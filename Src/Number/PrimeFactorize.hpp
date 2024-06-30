#pragma once

#include "../Template/TypeAlias.hpp"
#include "./PrimeFactor.hpp"

#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

namespace zawa {

template <class T>
std::vector<PrimeFactor<T>> PrimeFactorize(T x) {
    static_assert(std::is_unsigned_v<T>, "T must be unsigned integer");
    assert(x > T{0});
    std::vector<PrimeFactor<T>> res;
    for (T f{2} ; u64{f} * f <= x ; f++) {
        u32 exp{};
        while (x % f == 0) {
            exp++;
            x /= f;
        }
        if (exp) {
            res.emplace_back(f, exp);
        }
    }
    if (x > T{1}) {
        res.emplace_back(x, u32{1});
    }
    return res;
}

} // namespace zawa
