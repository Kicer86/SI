# implementation details of SI

All units provided by SI are derived from the template `SI::detail::unit_t`. All units have a base typedef i.e. `force_t` and further derived typedefs for each ratio i.e. `micro_newton_t`

example:
```cpp
template <typename _Type, class _Ratio = std::ratio<1>>
using force_t = detail::unit_t<'F', 1, _Type, _Ratio>;

template <typename _Type> using micro_newton_t = force_t<_Type, std::micro>;
```

The implementation of most of the functionality is done purely in the classes of the `detail` namespace. 

## Anatomy of the `unit_t` class

The `unit_t` template class is the base class for all units in SI. IT also allows to provide for own units. 
A unit consists of a `_Symbol` which is a single letter representing the dimension symbol for the physical unit. This letter has to be **unique** for each unit, even if you want to provide aditional units yourself. 
As most units can be multiplied and divided by themselves the `_Exponent` of the unit itself is also stored.For most units this does make limited sense in practice, but it  allows for easy creation of units such as square meters etc. **If two units of the same exponent are divided by each other, the resulting type is a scalar of the defined internal type.**
The `_Type` template parameter denotes an internal integral or floating point type. Units constructed with the supplied literals are either `int64_t`or `long double`. 
The last template parameter denotes the `_Ratio` of the unit, which is an instantiation of [`std::ratio`](https://en.cppreference.com/w/cpp/numeric/ratio/ratio) This means that all units have the same resolution 

```cpp
template <char _Symbol, char _Exponent, typename _Type,
          typename _Ratio = std::ratio<1>>
struct unit_t
```




