#include <SI/detail/unit.h>

void operator_divide_from_integral_test() {
  constexpr int64_t v1{1};
  constexpr SI::detail::unit_t<'X', 1, int64_t, std::kilo> v2{1};

  constexpr auto r = v1 / v2;
}