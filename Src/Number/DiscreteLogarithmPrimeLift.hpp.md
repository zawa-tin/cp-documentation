---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/My/Number/DiscreteLogarithmPrimeLifet.test.cpp
    title: Test/My/Number/DiscreteLogarithmPrimeLifet.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/UC/4-9-A.test.cpp
    title: Test/UC/4-9-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/DiscreteLogarithmPrimeLift.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Number/DiscreteLogarithmPrimeLift.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <numeric>\n#include <optional>\n\
    \nnamespace zawa {\n\nnamespace internal {\n\nu64 PowMod(u64 a, u64 p, u64 m)\
    \ {\n    a %= m;\n    u64 res = 1, base = a;\n    while (p) {\n        if (p &\
    \ 1)\n            res = __uint128_t{res} * base % m;\n        base = __uint128_t{base}\
    \ * base % m;\n        p >>= 1;\n    }\n    return res;\n}\n\n// sabori \\Theta(p)\n\
    std::optional<u64> DiscreteLogarithmSinglePrime(u64 a, u64 b, u64 p) {\n    a\
    \ %= p;\n    b %= p;\n    u64 cur = 1;\n    for (u64 i = 0 ; i < p ; i++, cur\
    \ = (cur * a) % p) \n        if (cur == b)\n            return i;\n    return\
    \ std::nullopt;\n}\n\nstd::optional<u64> DiscreteLogarithmBinaryLift(u64 a, u64\
    \ b, u64 k) {\n    assert(k <= 64);\n    const u64 m = u64{1} << k; \n    auto\
    \ modM = [&](__uint128_t v) {\n        return k == 64 ? static_cast<u64>(v) :\
    \ v % m;\n    };\n    if (!(a & 1)) {\n        u64 res = 1;\n        for (u64\
    \ i = 0 ; i <= k ; i++, res = modM(__uint128_t{res} * a))\n            if (res\
    \ == b)\n                return i;\n        return std::nullopt;\n    }\n    u64\
    \ r = 0, md = 1;\n    __uint128_t h = __uint128_t{a} * a - 1;\n    while (r <\
    \ k and !(h & 1)) {\n        r++;\n        h >>= 1;\n        md <<= 1;\n    }\n\
    \    if (r == k and k == 64) {\n        if (b == 1)\n            return 0;\n \
    \       else if (a == b)\n            return 1;\n        else\n            return\
    \ std::nullopt;\n    }\n    u64 x = 0;\n    if (b % md == 1)\n        x = 0;\n\
    \    else if (b % md == a % md)\n        x = 1;\n    else\n        return std::nullopt;\n\
    \    if (r == k)\n        return x;\n    u64 ax = (x ? a : u64{1});\n    for (u64\
    \ i = 1, ai = modM(__uint128_t{a} * a) ; ax != b ; i++, ai = modM(__uint128_t{ai}\
    \ * ai)) {\n        md <<= 1;\n        if ((md ? ax % md : ax) != (md ? b % md\
    \ : b)) {\n            x |= u64{1} << i;\n            ax = modM(__uint128_t{ax}\
    \ * ai);\n        }\n    }\n    return x;\n}\n    \n} // namespace internal\n\n\
    std::optional<u64> DiscreteLogarithmPrimeLift(u64 a, u64 b, u64 p, u64 k) {\n\
    \    // assert(p is prime)\n    // assert(p^k <= 2^{64})\n    const u64 m = [&]()\
    \ {\n        u64 res = 1, base = p;\n        for (u64 i = k ; i ; i >>= 1, base\
    \ *= base)\n            if (i & 1)\n                res *= base;\n        return\
    \ res;\n    }();\n    if (m) {\n        a %= m;\n        b %= m;\n    }\n    if\
    \ (p == 2)\n        return internal::DiscreteLogarithmBinaryLift(a, b, k);\n \
    \   assert(m);\n    if (a % p == 0) {\n        u64 cur = 1;\n        for (u64\
    \ i = 0 ; i <= k ; i++) {\n            if (cur == b)\n                return i;\n\
    \            cur = __uint128_t{cur} * a % m;\n        }\n        return std::nullopt;\n\
    \    }\n    auto z = internal::DiscreteLogarithmSinglePrime(a, b, p);\n    if\
    \ (!z.has_value())\n        return std::nullopt;\n    u64 r = 0, md = 1;\n   \
    \ __uint128_t h = internal::PowMod(a, p - 1, m) - 1;\n    while (r < k and h %\
    \ p == 0) {\n        r++;\n        h /= p;\n        md *= p;\n    }\n    u64 ax\
    \ = internal::PowMod(a, z.value(), m);\n    if (ax % md != b % md)\n        return\
    \ std::nullopt;\n    if (r == k)\n        return z;\n    u64 y = 0; \n    const\
    \ u64 rev = internal::PowMod((b % p) * (h % p) % p, p - 2, p);\n    u64 up = internal::PowMod(a,\
    \ p - 1, m);\n    u64 u = 1;\n    while (ax != b) {\n        u64 df = ((__uint128_t{b}\
    \ + m - ax) % m + m) % m;\n        assert(df % md == 0);\n        u64 d = ((df/md)\
    \ * rev) % p;\n        y += u * d;\n        ax = __uint128_t{ax} * internal::PowMod(up,\
    \ d, m) % m;\n        md *= p;\n        u *= p;\n        up = internal::PowMod(up,\
    \ p, m);\n    }\n    return (p - 1) * y + z.value();\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <optional>\n\nnamespace zawa\
    \ {\n\nnamespace internal {\n\nu64 PowMod(u64 a, u64 p, u64 m) {\n    a %= m;\n\
    \    u64 res = 1, base = a;\n    while (p) {\n        if (p & 1)\n           \
    \ res = __uint128_t{res} * base % m;\n        base = __uint128_t{base} * base\
    \ % m;\n        p >>= 1;\n    }\n    return res;\n}\n\n// sabori \\Theta(p)\n\
    std::optional<u64> DiscreteLogarithmSinglePrime(u64 a, u64 b, u64 p) {\n    a\
    \ %= p;\n    b %= p;\n    u64 cur = 1;\n    for (u64 i = 0 ; i < p ; i++, cur\
    \ = (cur * a) % p) \n        if (cur == b)\n            return i;\n    return\
    \ std::nullopt;\n}\n\nstd::optional<u64> DiscreteLogarithmBinaryLift(u64 a, u64\
    \ b, u64 k) {\n    assert(k <= 64);\n    const u64 m = u64{1} << k; \n    auto\
    \ modM = [&](__uint128_t v) {\n        return k == 64 ? static_cast<u64>(v) :\
    \ v % m;\n    };\n    if (!(a & 1)) {\n        u64 res = 1;\n        for (u64\
    \ i = 0 ; i <= k ; i++, res = modM(__uint128_t{res} * a))\n            if (res\
    \ == b)\n                return i;\n        return std::nullopt;\n    }\n    u64\
    \ r = 0, md = 1;\n    __uint128_t h = __uint128_t{a} * a - 1;\n    while (r <\
    \ k and !(h & 1)) {\n        r++;\n        h >>= 1;\n        md <<= 1;\n    }\n\
    \    if (r == k and k == 64) {\n        if (b == 1)\n            return 0;\n \
    \       else if (a == b)\n            return 1;\n        else\n            return\
    \ std::nullopt;\n    }\n    u64 x = 0;\n    if (b % md == 1)\n        x = 0;\n\
    \    else if (b % md == a % md)\n        x = 1;\n    else\n        return std::nullopt;\n\
    \    if (r == k)\n        return x;\n    u64 ax = (x ? a : u64{1});\n    for (u64\
    \ i = 1, ai = modM(__uint128_t{a} * a) ; ax != b ; i++, ai = modM(__uint128_t{ai}\
    \ * ai)) {\n        md <<= 1;\n        if ((md ? ax % md : ax) != (md ? b % md\
    \ : b)) {\n            x |= u64{1} << i;\n            ax = modM(__uint128_t{ax}\
    \ * ai);\n        }\n    }\n    return x;\n}\n    \n} // namespace internal\n\n\
    std::optional<u64> DiscreteLogarithmPrimeLift(u64 a, u64 b, u64 p, u64 k) {\n\
    \    // assert(p is prime)\n    // assert(p^k <= 2^{64})\n    const u64 m = [&]()\
    \ {\n        u64 res = 1, base = p;\n        for (u64 i = k ; i ; i >>= 1, base\
    \ *= base)\n            if (i & 1)\n                res *= base;\n        return\
    \ res;\n    }();\n    if (m) {\n        a %= m;\n        b %= m;\n    }\n    if\
    \ (p == 2)\n        return internal::DiscreteLogarithmBinaryLift(a, b, k);\n \
    \   assert(m);\n    if (a % p == 0) {\n        u64 cur = 1;\n        for (u64\
    \ i = 0 ; i <= k ; i++) {\n            if (cur == b)\n                return i;\n\
    \            cur = __uint128_t{cur} * a % m;\n        }\n        return std::nullopt;\n\
    \    }\n    auto z = internal::DiscreteLogarithmSinglePrime(a, b, p);\n    if\
    \ (!z.has_value())\n        return std::nullopt;\n    u64 r = 0, md = 1;\n   \
    \ __uint128_t h = internal::PowMod(a, p - 1, m) - 1;\n    while (r < k and h %\
    \ p == 0) {\n        r++;\n        h /= p;\n        md *= p;\n    }\n    u64 ax\
    \ = internal::PowMod(a, z.value(), m);\n    if (ax % md != b % md)\n        return\
    \ std::nullopt;\n    if (r == k)\n        return z;\n    u64 y = 0; \n    const\
    \ u64 rev = internal::PowMod((b % p) * (h % p) % p, p - 2, p);\n    u64 up = internal::PowMod(a,\
    \ p - 1, m);\n    u64 u = 1;\n    while (ax != b) {\n        u64 df = ((__uint128_t{b}\
    \ + m - ax) % m + m) % m;\n        assert(df % md == 0);\n        u64 d = ((df/md)\
    \ * rev) % p;\n        y += u * d;\n        ax = __uint128_t{ax} * internal::PowMod(up,\
    \ d, m) % m;\n        md *= p;\n        u *= p;\n        up = internal::PowMod(up,\
    \ p, m);\n    }\n    return (p - 1) * y + z.value();\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/DiscreteLogarithmPrimeLift.hpp
  requiredBy: []
  timestamp: '2026-02-02 16:16:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/UC/4-9-A.test.cpp
  - Test/My/Number/DiscreteLogarithmPrimeLifet.test.cpp
documentation_of: Src/Number/DiscreteLogarithmPrimeLift.hpp
layout: document
title: "$p^k$\u306B\u5BFE\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C"
---

## 概要

$a^{x}\equiv b\pmod{p^k}$ を満たす $x$ を一つ発見するか、存在しないことを報告する。

発見した場合は最小値を返す。
- 本当に最小値を返しているかは未verify

$p$は素数であり、ある程度小さい必要がある。

## ライブラリの使い方

```cpp
std::optional<u64> DiscreteLogarithmPrimeLift(u64 a, u64 b, u64 p, u64 k)
```

$p$ が素数、 $p^k$ が $2^{64}$ 以下である必要がある。

**計算量:** $O(p + k\log p)$

さぼっているだけで、ちゃんと実装すると $O(\sqrt{p} + k)$ になるはず。

## 参考

- [Efficient Lifting of Discrete Logarithms Modulo Prime Powers](https://arxiv.org/pdf/2505.07434)
- [上記論文の読解メモ(自分用: 非公開)](https://scrapbox.io/zawatin/Efficient_Lifting_of_Discrete_Logarithms_Modulo_Prime_Powers)
