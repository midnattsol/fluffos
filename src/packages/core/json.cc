#include "base/package_api.h"
#include "packages/core/errors.h"

#include <nlohmann/json.hpp>
#include <cmath>
#include <charconv>
#include <limits>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
constexpr int max_json_depth = 64;

struct Value {
  svalue_t value = const0;
  Value() = default;
  Value(const Value&) = delete;
  Value& operator=(const Value&) = delete;
  ~Value() { free_svalue(&value, "json temporary"); }
};

void validate_text(const std::string& value) {
  if (value.find('\0') != std::string::npos)
    throw std::runtime_error("JSON strings containing NUL cannot be represented in LPC");
  if (value.size() > static_cast<size_t>(CONFIG_INT(__MAX_STRING_LENGTH__)))
    throw std::runtime_error("JSON string exceeds maximum string length");
}

void from_json(const json& source, svalue_t* output, int depth) {
  if (depth > max_json_depth) throw std::runtime_error("JSON nesting exceeds 64 levels");
  if (source.is_null()) {
    *output = svalue_t{T_NULL, 0, {0}};
  } else if (source.is_boolean()) {
    *output = svalue_t{T_BOOLEAN, 0, {source.get<bool>() ? 1 : 0}};
  } else if (source.is_number_unsigned()) {
    auto number = source.get<uint64_t>();
    if (number > static_cast<uint64_t>(std::numeric_limits<LPC_INT>::max()))
      throw std::runtime_error("JSON integer exceeds LPC integer range");
    *output = svalue_t{T_NUMBER, 0, {static_cast<LPC_INT>(number)}};
  } else if (source.is_number_integer()) {
    *output = svalue_t{T_NUMBER, 0, {source.get<LPC_INT>()}};
  } else if (source.is_number_float()) {
    output->type = T_REAL;
    output->subtype = 0;
    output->u.real = source.get<LPC_FLOAT>();
    if (!std::isfinite(output->u.real)) throw std::runtime_error("JSON number must be finite");
  } else if (source.is_string()) {
    const auto& text = source.get_ref<const std::string&>();
    validate_text(text);
    output->u.string = string_copy(text.c_str(), "json_decode");
    output->type = T_STRING;
    output->subtype = STRING_MALLOC;
  } else if (source.is_array()) {
    if (source.size() > static_cast<size_t>(CONFIG_INT(__MAX_ARRAY_SIZE__)))
      throw std::runtime_error("JSON array exceeds maximum array size");
    output->u.arr = allocate_array(source.size());
    output->type = T_ARRAY;
    output->subtype = 0;
    for (size_t index = 0; index < source.size(); ++index)
      from_json(source[index], &output->u.arr->item[index], depth + 1);
  } else if (source.is_object()) {
    if (source.size() > static_cast<size_t>(CONFIG_INT(__MAX_MAPPING_SIZE__)))
      throw std::runtime_error("JSON object exceeds maximum mapping size");
    output->u.map = allocate_mapping(source.size());
    output->type = T_MAPPING;
    output->subtype = 0;
    for (const auto& [key, item] : source.items()) {
      validate_text(key);
      Value key_value;
      key_value.value.u.string = make_shared_string(key.c_str());
      key_value.value.type = T_STRING;
      key_value.value.subtype = STRING_SHARED;
      svalue_t* slot = find_for_insert(output->u.map, &key_value.value, 1);
      from_json(item, slot, depth + 1);
    }
  }
}

json to_json(const svalue_t* value, std::set<const void*>& active, int depth, size_t& budget) {
  if (!budget--) throw std::runtime_error("JSON output exceeds node budget");
  if (depth > max_json_depth) throw std::runtime_error("JSON nesting exceeds 64 levels");
  switch (value->type) {
    case T_NULL: return nullptr;
    case T_BOOLEAN: return value->u.number != 0;
    case T_NUMBER:
      if (value->subtype == T_UNDEFINED) throw std::runtime_error("Undefined is not JSON null");
      return value->u.number;
    case T_REAL:
      if (!std::isfinite(value->u.real)) throw std::runtime_error("JSON number must be finite");
      return value->u.real;
    case T_STRING: {
      const std::string text(value->u.string, SVALUE_STRLEN(value));
      validate_text(text);
      return text;
    }
    case T_ARRAY:
    case T_MAPPING: break;
    default: throw std::runtime_error("Value type cannot be encoded as JSON");
  }
  const void* identity = value->u.refed;
  if (!active.insert(identity).second) throw std::runtime_error("JSON cannot represent a reference cycle");
  json result;
  if (value->type == T_ARRAY) {
    result = json::array();
    for (int index = 0; index < value->u.arr->size; ++index)
      result.push_back(to_json(&value->u.arr->item[index], active, depth + 1, budget));
  } else {
    result = json::object();
    for (unsigned int bucket = 0; bucket <= value->u.map->table_size; ++bucket)
      for (mapping_node_t* node = value->u.map->table[bucket]; node; node = node->next) {
        if (node->values[0].type != T_STRING) throw std::runtime_error("JSON object keys must be strings");
        result[std::string(node->values[0].u.string, SVALUE_STRLEN(&node->values[0]))] =
            to_json(&node->values[1], active, depth + 1, budget);
      }
  }
  active.erase(identity);
  return result;
}

void decode(bool object_only) {
  std::string failure;
  std::string failure_code = "json.invalid_data";
  size_t offset = 0;
  {
    Value result;
    try {
      std::string source;
      if (sp->type == T_STRING) source.assign(sp->u.string, SVALUE_STRLEN(sp));
      else source.assign(reinterpret_cast<const char*>(sp->u.buf->item), sp->u.buf->size);
      if (source.size() > static_cast<size_t>(CONFIG_INT(__MAX_STRING_LENGTH__)))
        throw std::runtime_error("JSON input exceeds maximum string length");
      if (source.find('\0') != std::string::npos)
        throw std::runtime_error("JSON input contains an embedded NUL byte");
      // nlohmann falls back to double for integer tokens beyond uint64. Reject
      // those tokens before parsing rather than silently losing precision.
      bool quoted = false;
      for (size_t index = 0; index < source.size(); ++index) {
        const char ch = source[index];
        if (quoted) {
          if (ch == '\\') ++index;
          else if (ch == '"') quoted = false;
          continue;
        }
        if (ch == '"') { quoted = true; continue; }
        if (ch != '-' && (ch < '0' || ch > '9')) continue;
        size_t end = index;
        bool integer = true;
        while (end < source.size() &&
               ((source[end] >= '0' && source[end] <= '9') || source[end] == '-' ||
                source[end] == '+' || source[end] == '.' || source[end] == 'e' || source[end] == 'E')) {
          if (source[end] == '.' || source[end] == 'e' || source[end] == 'E') integer = false;
          ++end;
        }
        if (integer) {
          LPC_INT number;
          const auto parsed = std::from_chars(source.data() + index, source.data() + end, number);
          if (parsed.ec == std::errc::result_out_of_range)
            throw std::runtime_error("JSON integer exceeds LPC integer range");
        }
        index = end - 1;
      }
      std::vector<std::set<std::string>> object_keys;
      auto callback = [&](int depth, json::parse_event_t event, json& parsed) {
        if (depth > max_json_depth) throw std::runtime_error("JSON nesting exceeds 64 levels");
        if (event == json::parse_event_t::object_start) object_keys.emplace_back();
        if (event == json::parse_event_t::object_end) object_keys.pop_back();
        if (event == json::parse_event_t::key && !object_keys.back().insert(parsed.get<std::string>()).second)
          throw std::runtime_error("Duplicate JSON object key: " + parsed.get<std::string>());
        return true;
      };
      json document = json::parse(source, callback);
      if (object_only && !document.is_object()) throw std::runtime_error("JSON root must be an object");
      from_json(document, &result.value, 0);
      pop_stack();
      push_svalue(&result.value);
      return;
    } catch (const json::parse_error& exception) {
      failure_code = "json.syntax";
      failure = exception.what();
      offset = exception.byte;
    } catch (const std::exception& exception) {
      failure = exception.what();
    }
  }
  raise_structured_error(failure_code, failure, "", offset);
}
}  // namespace

void f_json_decode() { decode(false); }
void f_json_decode_object() { decode(true); }

void f_json_encode() {
  std::string failure;
  try {
    std::set<const void*> active;
    size_t budget = CONFIG_INT(__MAX_STRING_LENGTH__);
    const std::string encoded = to_json(sp, active, 0, budget).dump();
    if (encoded.size() > static_cast<size_t>(CONFIG_INT(__MAX_STRING_LENGTH__)))
      throw std::runtime_error("Encoded JSON exceeds maximum string length");
    pop_stack();
    copy_and_push_string(encoded.c_str());
    return;
  } catch (const std::exception& exception) {
    failure = exception.what();
  }
  raise_structured_error("json.encode", failure, "");
}

void f_booleanp() {
  const bool matches = sp->type == T_BOOLEAN;
  pop_stack();
  push_number(matches);
}

void f_json_nullp() {
  const bool matches = sp->type == T_NULL;
  pop_stack();
  push_number(matches);
}
