#include "base/package_api.h"
#include "packages/core/errors.h"

#include <nlohmann/json.hpp>
#include <cmath>
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

// Builds the LPC value directly from the parser's events, so a decode allocates
// neither a json tree nor per-object key sets. Everything built so far is owned
// here: a limit (thrown as a C++ exception) or an error() from an allocation
// unwinds through the destructor and frees it.
class SvalueBuilder : public nlohmann::json_sax<json> {
 public:
  SvalueBuilder() = default;
  SvalueBuilder(const SvalueBuilder&) = delete;
  SvalueBuilder& operator=(const SvalueBuilder&) = delete;
  ~SvalueBuilder() override {
    for (auto& frame : frames_) {
      for (auto& item : frame.items) free_svalue(&item, "json builder");
      free_svalue(&frame.key, "json builder");
      if (frame.map) free_mapping(frame.map);
    }
    free_svalue(&root_, "json builder");
  }

  bool null() override { return emit(svalue_t{T_NULL, 0, {0}}); }
  bool boolean(bool value) override { return emit(svalue_t{T_BOOLEAN, 0, {value ? 1 : 0}}); }
  bool number_integer(number_integer_t value) override {
    return emit(svalue_t{T_NUMBER, 0, {static_cast<LPC_INT>(value)}});
  }
  bool number_unsigned(number_unsigned_t value) override {
    if (value > static_cast<uint64_t>(std::numeric_limits<LPC_INT>::max()))
      throw std::runtime_error("JSON integer exceeds LPC integer range");
    return emit(svalue_t{T_NUMBER, 0, {static_cast<LPC_INT>(value)}});
  }
  bool number_float(number_float_t value, const string_t& token) override {
    // The parser falls back to double for an integer token too big for 64 bits.
    if (token.find_first_of(".eE") == string_t::npos)
      throw std::runtime_error("JSON integer exceeds LPC integer range");
    if (!std::isfinite(value)) throw std::runtime_error("JSON number must be finite");
    svalue_t real;
    real.type = T_REAL;
    real.subtype = 0;
    real.u.real = value;
    return emit(real);
  }
  bool string(string_t& value) override {
    validate_text(value);
    svalue_t text;
    text.u.string = string_copy(value.c_str(), "json_decode");
    text.type = T_STRING;
    text.subtype = STRING_MALLOC;
    return emit(text);
  }
  bool binary(binary_t&) override { throw std::runtime_error("JSON binary values are unsupported"); }

  bool start_object(std::size_t) override {
    enter();
    frames_.back().map = allocate_mapping(0);
    return true;
  }
  bool key(string_t& value) override {
    validate_text(value);
    Frame& frame = frames_.back();
    frame.key.u.string = make_shared_string(value.c_str());
    frame.key.type = T_STRING;
    frame.key.subtype = STRING_SHARED;
    if (find_in_mapping(frame.map, frame.key) != &const0u)
      throw std::runtime_error("Duplicate JSON object key: " + value);
    return true;
  }
  bool end_object() override {
    svalue_t finished;
    finished.u.map = frames_.back().map;
    finished.type = T_MAPPING;
    finished.subtype = 0;
    frames_.back().map = nullptr;
    frames_.pop_back();
    return emit(finished);
  }
  bool start_array(std::size_t) override {
    enter();
    return true;
  }
  bool end_array() override {
    auto& items = frames_.back().items;
    array_t* array = allocate_empty_array(static_cast<int>(items.size()));
    if (!items.empty()) memcpy(array->item, items.data(), items.size() * sizeof(svalue_t));
    items.clear();  // moved into the array
    frames_.pop_back();
    svalue_t finished;
    finished.u.arr = array;
    finished.type = T_ARRAY;
    finished.subtype = 0;
    return emit(finished);
  }
  bool parse_error(std::size_t position, const std::string&,
                   const nlohmann::detail::exception& exception) override {
    failure_ = exception.what();
    if (dynamic_cast<const json::parse_error*>(&exception)) {
      syntax_error_ = true;
      failure_offset_ = position;
    }
    return false;
  }

  [[nodiscard]] svalue_t* root() { return &root_; }
  [[nodiscard]] const std::string& failure() const { return failure_; }
  [[nodiscard]] bool syntax_error() const { return syntax_error_; }
  [[nodiscard]] size_t failure_offset() const { return failure_offset_; }

 private:
  struct Frame {
    std::vector<svalue_t> items;  // array elements so far
    mapping_t* map = nullptr;     // object so far; null for an array
    svalue_t key = const0;        // object key waiting for its value
  };

  void enter() {
    if (frames_.size() > max_json_depth) throw std::runtime_error("JSON nesting exceeds 64 levels");
    frames_.emplace_back();
  }

  // Takes ownership of value.
  bool emit(svalue_t value) {
    if (frames_.empty()) {
      root_ = value;
      return true;
    }
    Frame& frame = frames_.back();
    if (!frame.map) {
      if (frame.items.size() >= static_cast<size_t>(CONFIG_INT(__MAX_ARRAY_SIZE__))) {
        free_svalue(&value, "json builder");
        throw std::runtime_error("JSON array exceeds maximum array size");
      }
      frame.items.push_back(value);
      return true;
    }
    if (MAP_COUNT(frame.map) >= static_cast<unsigned>(CONFIG_INT(__MAX_MAPPING_SIZE__))) {
      free_svalue(&value, "json builder");
      throw std::runtime_error("JSON object exceeds maximum mapping size");
    }
    *find_for_insert(frame.map, &frame.key, 1) = value;
    free_svalue(&frame.key, "json builder");
    frame.key = const0;
    return true;
  }

  std::vector<Frame> frames_;
  svalue_t root_ = const0;
  std::string failure_;
  bool syntax_error_ = false;
  size_t failure_offset_ = 0;
};

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
  const char* data;
  size_t size;
  if (sp->type == T_STRING) {
    data = sp->u.string;
    size = SVALUE_STRLEN(sp);
  } else {
    data = reinterpret_cast<const char*>(sp->u.buf->item);
    size = sp->u.buf->size;
  }

  std::string failure;
  std::string failure_code = "json.invalid_data";
  size_t offset = 0;
  {
    SvalueBuilder builder;
    try {
      if (size > static_cast<size_t>(CONFIG_INT(__MAX_STRING_LENGTH__)))
        throw std::runtime_error("JSON input exceeds maximum string length");
      if (size && memchr(data, '\0', size))
        throw std::runtime_error("JSON input contains an embedded NUL byte");
      if (json::sax_parse(data, data + size, &builder)) {
        if (object_only && builder.root()->type != T_MAPPING)
          throw std::runtime_error("JSON root must be an object");
        pop_stack();
        push_svalue(builder.root());
        return;
      }
      failure = builder.failure();
      if (builder.syntax_error()) {
        failure_code = "json.syntax";
        offset = builder.failure_offset();
      }
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
