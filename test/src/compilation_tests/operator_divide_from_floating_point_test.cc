#include <SI/detail/unit.h>

void operator_divide_from_floating_point_test() {
  constexpr long double v1{1.0};
  constexpr SI::detail::unit_t<'X', 1, long double, std::kilo> v2{1};

  constexpr auto r = v1 / v2;
}