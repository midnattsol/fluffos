#include "base/package_api.h"

#include "packages/core/errors.h"
#include <set>
#include <string>

namespace {
struct OwnedValue {
  svalue_t value = const0;
  ~OwnedValue() { free_svalue(&value, "error temporary"); }
};

// `budget` counts values copied, not distinct ones: shared subtrees are copied
// once per reference, so a few nested arrays can describe 2^n values and no LPC
// instruction runs to trip the eval limit while they are copied.
void snapshot(const svalue_t* source, svalue_t* target, std::set<const void*>& active, int depth,
              size_t& budget) {
  if (depth > 64) error("Error context nesting exceeds 64 levels.\n");
  const size_t cost = source->type == T_BUFFER ? 1 + source->u.buf->size / sizeof(svalue_t) : 1;
  if (cost > budget) error("Error context is too large.\n");
  budget -= cost;
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
        snapshot(&node->values[1], slot, active, depth + 1, budget);
      }
  } else {
    target->u.arr = source->type == T_CLASS ? allocate_class_by_size(source->u.arr->size) :
                                            allocate_array(source->u.arr->size);
    target->type = source->type;
    target->subtype = 0;
    for (int index = 0; index < source->u.arr->size; ++index)
      snapshot(&source->u.arr->item[index], &target->u.arr->item[index], active, depth + 1, budget);
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
  size_t budget = CONFIG_INT(__MAX_ARRAY_SIZE__);
  if (context) snapshot(context, &copied.value, active, 0, budget);
  else { copied.value.u.map = allocate_mapping(0); copied.value.type = T_MAPPING; }
  set_field(result->u.map, "context", &copied.value);
  svalue_t nil{T_NULL, 0, {0}};
  set_field(result->u.map, "cause", cause && cause->type == T_ERROR ? cause : &nil);

  // Arguments and locals are not retained: they may include credentials and
  // cycles.
  OwnedValue trace;
  trace.value.u.arr = get_svalue_frame_trace();
  // Like get_svalue_trace(), this returns a reference-zero array.
  trace.value.u.arr->ref++;
  trace.value.type = T_ARRAY;
  set_field(result->u.map, "trace", &trace.value);
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
  // A stored context is already a tree that passed make_error()'s budget, so
  // this copy is linear in it and must not fail on a valid error.
  size_t budget = SIZE_MAX;
  snapshot(&source, &result.value, active, 0, budget);
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
