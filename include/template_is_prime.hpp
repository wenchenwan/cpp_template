
#include <iostream>

template <unsigned p, unsigned d>
struct is_prime {
    static constexpr bool value = (p % d != 0) && is_prime<p, d - 1>::value;
};

template <unsigned p>
struct is_prime<p, 2> {
    static constexpr bool value = (p % 2 != 0);
};

template <unsigned p>
struct is_prime<p, 1> {
    static constexpr bool value = true;
};

template <unsigned p>
struct is_prime<p, 0> {
    static constexpr bool value = false;
};

template <unsigned p>
struct template_is_prime {
    static constexpr bool value = is_prime<p, p / 2>::value;
};
