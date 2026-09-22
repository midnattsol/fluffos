#ifndef FLUFFOS_CORE_ERRORS_H
#define FLUFFOS_CORE_ERRORS_H

#include <string>
struct svalue_t;
void make_error_value(svalue_t*, const std::string&, const std::string&, svalue_t*, svalue_t*);
void normalize_caught_error(svalue_t*, bool);
[[noreturn]] void raise_structured_error(const std::string&, const std::string&, const std::string&, size_t = 0);

#endif
