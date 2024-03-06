---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/117.test.cpp
    title: Test/yukicoder/117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/BinomalCoefficients.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/BinomalCoefficients.hpp\"\n\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\n#include <atcoder/internal_math>\n\
    #include <atcoder/modint>\n\nnamespace zawa {\n\ntemplate <u32 MOD>\nclass BinomalCoefficients\
    \ {\npublic:\n    using Value = atcoder::static_modint<MOD>;\n    static_assert(atcoder::internal::is_prime_constexpr(MOD));\n\
    private:\n    usize n_{};\n    std::vector<Value> F_{}, inv_{}, invF_{};\n   \
    \ constexpr bool need(usize n) const noexcept {\n        return n_ <= n;\n   \
    \ }\n    void expand(usize n) {\n        F_.reserve(n + 1);\n        inv_.reserve(n\
    \ + 1);\n        invF_.reserve(n + 1);\n        for (usize i{n_} ; i <= n ; i++)\
    \ {\n            F_.emplace_back(F_.back() * Value{i});\n            inv_.emplace_back(MOD\
    \ - inv_[MOD % i] * (MOD / i));\n            invF_.emplace_back(invF_.back() *\
    \ inv_.back());\n        }\n        n_ = n + 1;\n    }\npublic:\n    constexpr\
    \ usize size() const noexcept {\n        return n_;\n    }\n    BinomalCoefficients()\
    \ \n        : n_{2u}, F_{Value::raw(1), Value::raw(1)}, inv_{Value{}, Value::raw(1)},\
    \ \n        invF_{Value::raw(1), Value::raw(1)} {}\n    BinomalCoefficients(usize\
    \ n) \n        : n_{2u}, F_{Value::raw(1), Value::raw(1)}, inv_{Value{}, Value::raw(1)},\
    \ \n        invF_{Value::raw(1), Value::raw(1)} {\n        assert(n);\n      \
    \  if (need(n)) expand(n);\n    }\n    Value F(i32 n) {\n        if (need(std::abs(n)))\
    \ expand(static_cast<usize>(std::abs(n)));\n        return (n >= 0 ? F_[n] : invF_[-n]);\n\
    \    }\n    Value P(i32 p, i32 q) {\n        if (q > p) return Value{}; \n   \
    \     return F(p) * F(q - p);\n    }\n    Value C(i32 p, i32 q) {\n        if\
    \ (q > p) return Value{};\n        return P(p, q) * F(-q);\n    }\n    Value H(i32\
    \ p, i32 q) {\n        if (p == 0 and q == 0) return Value::raw(1);\n        return\
    \ C(p + q - 1, q);\n    }\n    Value B(const std::vector<i32>& b) {\n        Value\
    \ res{1};\n        i32 sum{};\n        for (i32 x : b) {\n            res *= F(-x);\n\
    \            sum += x;\n        }\n        res *= F(sum);\n        return res;\n\
    \    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <cmath>\n#include <vector>\n#include <atcoder/internal_math>\n#include\
    \ <atcoder/modint>\n\nnamespace zawa {\n\ntemplate <u32 MOD>\nclass BinomalCoefficients\
    \ {\npublic:\n    using Value = atcoder::static_modint<MOD>;\n    static_assert(atcoder::internal::is_prime_constexpr(MOD));\n\
    private:\n    usize n_{};\n    std::vector<Value> F_{}, inv_{}, invF_{};\n   \
    \ constexpr bool need(usize n) const noexcept {\n        return n_ <= n;\n   \
    \ }\n    void expand(usize n) {\n        F_.reserve(n + 1);\n        inv_.reserve(n\
    \ + 1);\n        invF_.reserve(n + 1);\n        for (usize i{n_} ; i <= n ; i++)\
    \ {\n            F_.emplace_back(F_.back() * Value{i});\n            inv_.emplace_back(MOD\
    \ - inv_[MOD % i] * (MOD / i));\n            invF_.emplace_back(invF_.back() *\
    \ inv_.back());\n        }\n        n_ = n + 1;\n    }\npublic:\n    constexpr\
    \ usize size() const noexcept {\n        return n_;\n    }\n    BinomalCoefficients()\
    \ \n        : n_{2u}, F_{Value::raw(1), Value::raw(1)}, inv_{Value{}, Value::raw(1)},\
    \ \n        invF_{Value::raw(1), Value::raw(1)} {}\n    BinomalCoefficients(usize\
    \ n) \n        : n_{2u}, F_{Value::raw(1), Value::raw(1)}, inv_{Value{}, Value::raw(1)},\
    \ \n        invF_{Value::raw(1), Value::raw(1)} {\n        assert(n);\n      \
    \  if (need(n)) expand(n);\n    }\n    Value F(i32 n) {\n        if (need(std::abs(n)))\
    \ expand(static_cast<usize>(std::abs(n)));\n        return (n >= 0 ? F_[n] : invF_[-n]);\n\
    \    }\n    Value P(i32 p, i32 q) {\n        if (q > p) return Value{}; \n   \
    \     return F(p) * F(q - p);\n    }\n    Value C(i32 p, i32 q) {\n        if\
    \ (q > p) return Value{};\n        return P(p, q) * F(-q);\n    }\n    Value H(i32\
    \ p, i32 q) {\n        if (p == 0 and q == 0) return Value::raw(1);\n        return\
    \ C(p + q - 1, q);\n    }\n    Value B(const std::vector<i32>& b) {\n        Value\
    \ res{1};\n        i32 sum{};\n        for (i32 x : b) {\n            res *= F(-x);\n\
    \            sum += x;\n        }\n        res *= F(sum);\n        return res;\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/BinomalCoefficients.hpp
  requiredBy: []
  timestamp: '2024-03-06 21:16:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/yukicoder/117.test.cpp
documentation_of: Src/Number/BinomalCoefficients.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570(\u7D20\u6570mod)"
---

## 概要

素数 $P$ と $i = 0, 1, \dots, n$ について $i!$ と $x_{i}\times i!\equiv 1\pmod{P}$ なる $x_{i}$ を列挙する。

これによって素数 $P$ に対して $\binom{n}{r}$ 等が高速に求めることができる。

## ライブラリの使い方

#### テンプレート引数

```cpp
template <u32 MOD>
```

`MOD`が素数で無いと`static_assert`に引っかかる。

- `atcoder::internal::is_prime_constexpr`が内部で走る

#### 型

```cpp
using Value = atcoder::static_modint<MOD>;
```

#### コンストラクタ

```cpp
(1) BinomalCoefficients()
(2) BinomalCoefficients(usize n)
```

予め内部のコンテナをreserveしたい場合は(2)を使用する。 $n \gt 0$ を満たさない場合assertまたは`std::length_error`にひっかかる

<br />

#### F

```cpp
Value F(i32 n)
```

$n$ が非負ならば $n!$ を、 $n$ が負ならば $(-n)!$ の乗法逆元を返す。

<br />

#### P

```cpp
Value P(i32 p, i32 q)
```

$p$ 個の区別可能なボールから $q$ 個取り出し、それを一列に並べる通り数を返す。

<br />

#### C

```cpp
Value C(i32 p, i32 q)
```

$p$ 個の区別可能なボールから $q$ 個取り出す通り数を返す。すなわち $\binom{p}{q}$ を返す。

<br />

#### H

```cpp
Value H(i32 p, i32 q)
```

$p$ 種類のボールがそれぞれ無数にあるなかで、 $q$ 個取り出す通り数を返す。

いわゆる 「 $p - 1$ 個の仕切りと $q$ 個のボールの並べ方」である。

<br />

#### B

```cpp
Value B(const std::vector<i32>& b)
```

色 $0$ のボールが $b_0$ 個、色 $1$ のボールが $b_{1}$ 個.....

とあるなかで、それらすべてを一列に並べる通り数。ただし、同じ色のボールは区別がつかないとする。
