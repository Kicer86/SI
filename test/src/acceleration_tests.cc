#include <catch.hpp>

#include <SI/acceleration.h>
#include <SI/time.h>

using namespace SI::literals;

/// @todo add decay to L, a and t&2

TEST_CASE("GIVEN velocity value WHEN divided by time value THEN result is "
          "an acceleration value") {

  constexpr SI::velocity_t<std::ratio<1>, int64_t> one_ms{1};
  constexpr auto acceleration = one_ms / 1_s;

  static_assert(
      std::is_same<decltype(acceleration),
                   const SI::acceleration_t<std::ratio<1>, int64_t>>::value);
}

TEST_CASE("GIVEN a length value WHEN divided by time squared THEN result is an "
          "acceleration value") {
  constexpr auto one_m = 1_m;
  constexpr auto one_square_s = 1_s * 1_s;
  constexpr auto acceleration = one_m / one_square_s;

  static_assert(
      std::is_same<decltype(acceleration),
                   const SI::acceleration_t<std::ratio<1>, int64_t>>::value);
}

TEST_CASE("GIVEN an acceleration value WHEN multiplied by time squared THEN "
          "result is a length value") {

  constexpr auto one_square_s = 1_s * 1_s;
  constexpr auto acceleration = 1_m / one_square_s;
  constexpr auto length = acceleration * one_square_s;
  constexpr auto length_commutative = one_square_s * acceleration;

  static_assert(
      std::is_same<decltype(length),
                   const SI::length_t<std::ratio<1>, int64_t>>::value);
  static_assert(
      std::is_same<decltype(length_commutative),
                   const SI::length_t<std::ratio<1>, int64_t>>::value);
}