#include "base/package_api.h"

#include "packages/core/errors.h"
#include <set>
#include <string>

namespace {
struct OwnedValue {
  svalue_t value = const0;
  ~OwnedValue() { free_svalue(&value, "error temporary"); }
};

void snapshot(const svalue_t* source, svalue_t* target, std::set<const void*>& active, int depth) {
  if (depth > 64) error("Error context nesting exceeds 64 levels.\n");
  if (source->type == T_BUFFER) {
    target->u.buf = allocate_buffer(source->u.buf->size);
    target->type = T_BUFFER;
    target->subtype = 0;
    memcpy(target->u.buf->item, source->u.buf->item, source->u.buf->size);
    return;
  }
  if (source->type != T_ARRAY && source->type != T_CLASS && source->type != T_MAPPING) {
    assign_svalue(target, const_cast<svalue_t*>(source));
    return;
  }
  const void* identity = source->u.refed;
  if (!active.insert(identity).second) error("Error context cannot contain a reference cycle.\n");
  if (source->type == T_MAPPING) {
    target->u.map = allocate_mapping(MAP_COUNT(source->u.map));
    target->type = T_MAPPING;
    target->subtype = 0;
    for (unsigned int bucket = 0; bucket <= source->u.map->table_size; ++bucket)
      for (mapping_node_t* node = source->u.map->table[bucket]; node; node = node->next) {
        if (node->values[0].type & (T_ARRAY | T_CLASS | T_MAPPING | T_BUFFER))
          error("Error context mapping keys cannot be mutable containers.\n");
        svalue_t* slot = find_for_insert(target->u.map, &node->values[0], 1);
        snapshot(&node->values[1], slot, active, depth + 1);
      }
  } else {
    target->u.arr = source->type == T_CLASS ? allocate_class_by_size(source->u.arr->size) :
                                            allocate_array(source->u.arr->size);
    target->type = source->type;
    target->subtype = 0;
    for (int index = 0; index < source->u.arr->size; ++index)
      snapshot(&source->u.arr->item[index], &target->u.arr->item[index], active, depth + 1);
  }
  active.erase(identity);
}

void set_field(mapping_t* record, const char* name, svalue_t* value) {
  OwnedValue key;
  key.value.type = T_STRING;
  key.value.subtype = STRING_SHARED;
  key.value.u.string = make_shared_string(name);
  assign_svalue(find_for_insert(record, &key.value, 1), value);
}
}  // namespace

void make_error_value(svalue_t* result, const std::string& code, const std::string& message,
                      svalue_t* context, svalue_t* cause) {
  if (code.empty()) error("Error code cannot be empty.\n");
  if (cause && cause->type != T_ERROR && !IS_ZERO(cause)) error("Error cause must be an error.\n");
  result->u.map = allocate_mapping(5);
  result->type = T_ERROR;
  result->subtype = 0;
  add_mapping_string(result->u.map, "code", code.c_str());
  add_mapping_string(result->u.map, "message", message.c_str());
  OwnedValue copied;
  std::set<const void*> active;
  if (context) snapshot(context, &copied.value, active, 0);
  else { copied.value.u.map = allocate_mapping(0); copied.value.type = T_MAPPING; }
  set_field(result->u.map, "context", &copied.value);
  svalue_t nil{T_NULL, 0, {0}};
  set_field(result->u.map, "cause", cause && cause->type == T_ERROR ? cause : &nil);

  OwnedValue trace;
  trace.value.u.arr = get_svalue_trace();
  // get_svalue_trace returns a reference-zero array (like its existing
  // push_refed_array callers, this owner must acquire its own reference).
  trace.value.u.arr->ref++;
  trace.value.type = T_ARRAY;
  OwnedValue public_trace;
  int frame_count = 0;
  for (int index = 0; index < trace.value.u.arr->size; ++index)
    if (trace.value.u.arr->item[index].type == T_MAPPING) ++frame_count;
  public_trace.value.u.arr = allocate_array(frame_count);
  public_trace.value.type = T_ARRAY;
  int output_index = 0;
  // Do not retain arguments/locals: they may include credentials and cycles.
  for (int index = 0; index < trace.value.u.arr->size; ++index) {
    svalue_t* frame = &trace.value.u.arr->item[index];
    if (frame->type != T_MAPPING) continue;
    OwnedValue filtered;
    filtered.value.u.map = allocate_mapping(4);
    filtered.value.type = T_MAPPING;
    for (const char* field : {"file", "program", "function", "line"}) {
      svalue_t* value = find_string_in_mapping(frame->u.map, field);
      if (value != &const0u) set_field(filtered.value.u.map, field, value);
    }
    assign_svalue(&public_trace.value.u.arr->item[output_index++], &filtered.value);
  }
  set_field(result->u.map, "trace", &public_trace.value);
}

void f_make_error() {
  const int count = st_num_arg;
  svalue_t* arguments = sp - count + 1;
  const std::string code(arguments[0].u.string);
  const std::string message(arguments[1].u.string);
  OwnedValue result;
  make_error_value(&result.value, code, message, count >= 3 ? &arguments[2] : nullptr,
                    count >= 4 ? &arguments[3] : nullptr);
  pop_n_elems(count);
  push_svalue(&result.value);
}

void f_errorp() {
  const bool result = sp->type == T_ERROR;
  pop_stack();
  push_number(result);
}

void normalize_caught_error(svalue_t* value, bool caught) {
  if (!caught) {
    free_svalue(value, "modern catch success");
    *value = svalue_t{T_NULL, 0, {0}};
    return;
  }
  if (value->type == T_ERROR) return;
  const std::string message = value->type == T_STRING ? std::string(value->u.string) :
      std::string("Thrown value of type ") + type_name(value->type);
  OwnedValue context;
  context.value.u.map = allocate_mapping(2);
  context.value.type = T_MAPPING;
  add_mapping_string(context.value.u.map, "thrown_type", type_name(value->type));
  if (value->type & (T_NUMBER | T_REAL | T_STRING | T_BOOLEAN | T_NULL))
    set_field(context.value.u.map, "value", value);
  OwnedValue result;
  make_error_value(&result.value, "runtime.error", message, &context.value, nullptr);
  assign_svalue(value, &result.value);
}

void f_error_info() {
  if (sp->type != T_ERROR) error("error_info expects an error value.\n");
  svalue_t source = *sp;
  source.type = T_MAPPING;
  OwnedValue result;
  std::set<const void*> active;
  snapshot(&source, &result.value, active, 0);
  pop_stack();
  push_svalue(&result.value);
}

[[noreturn]] void raise_structured_error(const std::string& code, const std::string& message,
                                         svalue_t* context) {
  OwnedValue result;
  make_error_value(&result.value, code, message, context, nullptr);
  assign_svalue(&catch_value, &result.value);
  throw_error();
}

[[noreturn]] void raise_structured_error(const std::string& code, const std::string& message,
                                         const std::string& path, size_t offset) {
  OwnedValue context;
  context.value.u.map = allocate_mapping(1);
  context.value.type = T_MAPPING;
  add_mapping_string(context.value.u.map, "path", path.c_str());
  if (offset) add_mapping_pair(context.value.u.map, "byte", offset);
  raise_structured_error(code, message, &context.value);
}
