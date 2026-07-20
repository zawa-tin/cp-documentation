#pragma once

#include <cassert>
#include <cmath>
#include <concepts>
#include <utility>
#include <limits>

namespace zawa {

// floor(a^{1/k})
template <std::unsigned_integral T>
T KthRoot(T a,T k,bool floor=1) {
    assert(k >= 1);
    if (a <= 1 or k == 1)
        return a;
    if (k >= std::numeric_limits<T>::digits)
        return floor ? 1 : 2;
    auto pw = [&](T x) -> T {
        T res = 1, exp = k;
        while (exp) {
            if (exp & 1) {
                if (res > std::numeric_limits<T>::max() / x)
                    return 0;
                res *= x;
            }
            exp >>= 1;
            if (exp) {
                if (x > std::numeric_limits<T>::max() / x)
                    return 0;
                x *= x;
            }
        }
        return res;
    };
    T res = k == 2 ? sqrtl(a) : (k == 3 ? cbrtl(a) : powl(a,1.0l/(double)k));
    while (res >= 1) {
        T v = pw(res);
        if (v and v <= a)
            break;
        res--;
    }
    while (true) {
        T v = pw(res+1);
        if (v and v <= a)
            res++;
        else
            break;
    }
    if (!floor and pw(res) < a)
        res++;
    return res;
}

} // namespace zawa
