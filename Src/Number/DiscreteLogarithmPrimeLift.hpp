#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <optional>

namespace zawa {

namespace internal {

u64 PowMod(u64 a, u64 p, u64 m) {
    a %= m;
    u64 res = 1, base = a;
    while (p) {
        if (p & 1)
            res = __uint128_t{res} * base % m;
        base = __uint128_t{base} * base % m;
        p >>= 1;
    }
    return res;
}

// sabori \Theta(p)
std::optional<u64> DiscreteLogarithmSinglePrime(u64 a, u64 b, u64 p) {
    a %= p;
    b %= p;
    u64 cur = 1;
    for (u64 i = 0 ; i < p ; i++, cur = (cur * a) % p) 
        if (cur == b)
            return i;
    return std::nullopt;
}

std::optional<u64> DiscreteLogarithmBinaryLift(u64 a, u64 b, u64 k) {
    assert(k <= 64);
    const u64 m = u64{1} << k; 
    auto modM = [&](__uint128_t v) {
        return k == 64 ? static_cast<u64>(v) : v % m;
    };
    if (!(a & 1)) {
        u64 res = 1;
        for (u64 i = 0 ; i <= k ; i++, res = modM(__uint128_t{res} * a))
            if (res == b)
                return i;
        return std::nullopt;
    }
    u64 r = 0, md = 1;
    __uint128_t h = __uint128_t{a} * a - 1;
    while (r < k and !(h & 1)) {
        r++;
        h >>= 1;
        md <<= 1;
    }
    if (r == k and k == 64) {
        if (b == 1)
            return 0;
        else if (a == b)
            return 1;
        else
            return std::nullopt;
    }
    u64 x = 0;
    if (b % md == 1)
        x = 0;
    else if (b % md == a % md)
        x = 1;
    else
        return std::nullopt;
    if (r == k)
        return x;
    u64 ax = (x ? a : u64{1});
    for (u64 i = 1, ai = modM(__uint128_t{a} * a) ; ax != b ; i++, ai = modM(__uint128_t{ai} * ai)) {
        md <<= 1;
        if ((md ? ax % md : ax) != (md ? b % md : b)) {
            x |= u64{1} << i;
            ax = modM(__uint128_t{ax} * ai);
        }
    }
    return x;
}
    
} // namespace internal

std::optional<u64> DiscreteLogarithmPrimeLift(u64 a, u64 b, u64 p, u64 k) {
    // assert(p is prime)
    // assert(p^k <= 2^{64})
    const u64 m = [&]() {
        u64 res = 1, base = p;
        for (u64 i = k ; i ; i >>= 1, base *= base)
            if (i & 1)
                res *= base;
        return res;
    }();
    if (m) {
        a %= m;
        b %= m;
    }
    if (p == 2)
        return internal::DiscreteLogarithmBinaryLift(a, b, k);
    assert(m);
    if (a % p == 0) {
        u64 cur = 1;
        for (u64 i = 0 ; i <= k ; i++) {
            if (cur == b)
                return i;
            cur = __uint128_t{cur} * a % m;
        }
        return std::nullopt;
    }
    auto z = internal::DiscreteLogarithmSinglePrime(a, b, p);
    if (!z.has_value())
        return std::nullopt;
    u64 r = 0, md = 1;
    __uint128_t h = internal::PowMod(a, p - 1, m) - 1;
    while (r < k and h % p == 0) {
        r++;
        h /= p;
        md *= p;
    }
    u64 ax = internal::PowMod(a, z.value(), m);
    if (ax % md != b % md)
        return std::nullopt;
    if (r == k)
        return z;
    u64 y = 0; 
    const u64 rev = internal::PowMod((b % p) * (h % p) % p, p - 2, p);
    u64 up = internal::PowMod(a, p - 1, m);
    u64 u = 1;
    while (ax != b) {
        u64 df = ((__uint128_t{b} + m - ax) % m + m) % m;
        assert(df % md == 0);
        u64 d = ((df/md) * rev) % p;
        y += u * d;
        ax = __uint128_t{ax} * internal::PowMod(up, d, m) % m;
        md *= p;
        u *= p;
        up = internal::PowMod(up, p, m);
    }
    return (p - 1) * y + z.value();
}

} // namespace zawa
