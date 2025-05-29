---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactor.hpp
    title: Src/Number/PrimeFactor.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc170_d.test.cpp
    title: Test/AtCoder/abc170_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc177_e.test.cpp
    title: Test/AtCoder/abc177_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc185_e.test.cpp
    title: "ABC185-E Adjacent GCD (\u7D04\u6570\u30FB\u500D\u6570\u95A2\u4FC2\u306E\
      \u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF902-B.test.cpp
    title: Test/CF/CF902-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/LinearSieve.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/PrimeFactor.hpp\"\n\n#line 4 \"Src/Number/PrimeFactor.hpp\"\
    \n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass PrimeFactor\
    \ {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\");\n\
    private:\n    T factor_{};\n    u32 exponent_{};\n\npublic: \n    PrimeFactor()\
    \ = default;\n\n    PrimeFactor(T factor, u32 exponent) : factor_{factor}, exponent_{exponent}\
    \ {}\n\n    inline T factor() const noexcept {\n        return factor_;\n    }\n\
    \n    inline u32 exponent() const noexcept {\n        return exponent_;\n    }\n\
    \n    friend bool operator<(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs)\
    \ {\n        return lhs.factor() != rhs.factor() ?\n            lhs.factor() <\
    \ rhs.factor() :\n            lhs.exponent() < rhs.exponent();\n    }\n\n    friend\
    \ bool operator>(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs) {\n   \
    \     return lhs.factor() != rhs.factor() ?\n            lhs.factor() > rhs.factor()\
    \ :\n            lhs.exponent() > rhs.exponent();\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Src/Number/LinearSieve.hpp\"\n\n#include <concepts>\n#include\
    \ <vector>\n#include <utility>\n#include <cassert>\n\nnamespace zawa {\n\nclass\
    \ LinearSieve {\npublic:\n\n    using V = u32;\n    using F = PrimeFactor<V>;\n\
    \nprivate:\n\n    std::vector<V> primes_;\n    std::vector<V> lpf_;\n\npublic:\n\
    \n    explicit LinearSieve(V n) : primes_{}, lpf_(n + 1) {\n        for (V i{2}\
    \ ; i <= n ; i++) {\n            if (!lpf_[i]) {\n                lpf_[i] = i;\n\
    \                primes_.emplace_back(i);\n            }\n            for (V p\
    \ : primes_) {\n                if (static_cast<u64>(p) * i > n) break;\n    \
    \            lpf_[p * i] = p;\n            }\n        }\n    }\n\n    V size()\
    \ const noexcept {\n        return static_cast<V>(lpf_.size()) - 1;\n    }\n\n\
    \    bool isPrime(V x) const noexcept {\n        assert(x < lpf_.size());\n  \
    \      return lpf_[x] == x;\n    }\n\n    bool operator[](V x) const noexcept\
    \ {\n        assert(x < lpf_.size());\n        return lpf_[x] == x;\n    }\n\n\
    \    std::vector<V> primes() const {\n        return primes_;\n    }\n\n    //\
    \ @note: response array is not sorted.\n    template <std::integral T = V>\n \
    \   std::vector<T> divisor(V x) const {\n        assert(0u < x and x < lpf_.size());\n\
    \        std::vector<T> res(1, 1u);\n        while (x > 1) {\n            V factor{lpf_[x]};\n\
    \            u32 exponent{};\n            while (lpf_[x] == factor) {\n      \
    \          exponent++;\n                x /= lpf_[x];\n            }\n       \
    \     usize line{res.size()};\n            V now{1};\n            for (u32 i{}\
    \ ; i < exponent ; i++) {\n                now *= factor;\n                for\
    \ (usize j{} ; j < line ; j++) {\n                    res.emplace_back(static_cast<T>(res[j]\
    \ * now));\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n    std::vector<F> factorize(V x) const {\n        assert(0u < x and\
    \ x < lpf_.size());\n        std::vector<F> res;\n        while (x > 1) {\n  \
    \          V factor{lpf_[x]};\n            u32 exponent{};\n            while\
    \ (lpf_[x] == factor) {\n                exponent++;\n                x /= lpf_[x];\n\
    \            }\n            res.emplace_back(factor, exponent);\n        }\n \
    \       return res;\n    }\n\n    i32 mobius(V x) const {\n        assert(0u <\
    \ x and x < lpf_.size());\n        i32 res = 1;\n        while (x > 1u) {\n  \
    \          V factor = lpf_[x];\n            u32 exp = 0;\n            while (lpf_[x]\
    \ == factor) {\n                x /= factor;\n                exp++;\n       \
    \     }\n            if (exp >= 2u) return 0;\n            res *= -1;\n      \
    \  }\n        return res;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./PrimeFactor.hpp\"\
    \n\n#include <concepts>\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \nnamespace zawa {\n\nclass LinearSieve {\npublic:\n\n    using V = u32;\n   \
    \ using F = PrimeFactor<V>;\n\nprivate:\n\n    std::vector<V> primes_;\n    std::vector<V>\
    \ lpf_;\n\npublic:\n\n    explicit LinearSieve(V n) : primes_{}, lpf_(n + 1) {\n\
    \        for (V i{2} ; i <= n ; i++) {\n            if (!lpf_[i]) {\n        \
    \        lpf_[i] = i;\n                primes_.emplace_back(i);\n            }\n\
    \            for (V p : primes_) {\n                if (static_cast<u64>(p) *\
    \ i > n) break;\n                lpf_[p * i] = p;\n            }\n        }\n\
    \    }\n\n    V size() const noexcept {\n        return static_cast<V>(lpf_.size())\
    \ - 1;\n    }\n\n    bool isPrime(V x) const noexcept {\n        assert(x < lpf_.size());\n\
    \        return lpf_[x] == x;\n    }\n\n    bool operator[](V x) const noexcept\
    \ {\n        assert(x < lpf_.size());\n        return lpf_[x] == x;\n    }\n\n\
    \    std::vector<V> primes() const {\n        return primes_;\n    }\n\n    //\
    \ @note: response array is not sorted.\n    template <std::integral T = V>\n \
    \   std::vector<T> divisor(V x) const {\n        assert(0u < x and x < lpf_.size());\n\
    \        std::vector<T> res(1, 1u);\n        while (x > 1) {\n            V factor{lpf_[x]};\n\
    \            u32 exponent{};\n            while (lpf_[x] == factor) {\n      \
    \          exponent++;\n                x /= lpf_[x];\n            }\n       \
    \     usize line{res.size()};\n            V now{1};\n            for (u32 i{}\
    \ ; i < exponent ; i++) {\n                now *= factor;\n                for\
    \ (usize j{} ; j < line ; j++) {\n                    res.emplace_back(static_cast<T>(res[j]\
    \ * now));\n                }\n            }\n        }\n        return res;\n\
    \    }\n\n    std::vector<F> factorize(V x) const {\n        assert(0u < x and\
    \ x < lpf_.size());\n        std::vector<F> res;\n        while (x > 1) {\n  \
    \          V factor{lpf_[x]};\n            u32 exponent{};\n            while\
    \ (lpf_[x] == factor) {\n                exponent++;\n                x /= lpf_[x];\n\
    \            }\n            res.emplace_back(factor, exponent);\n        }\n \
    \       return res;\n    }\n\n    i32 mobius(V x) const {\n        assert(0u <\
    \ x and x < lpf_.size());\n        i32 res = 1;\n        while (x > 1u) {\n  \
    \          V factor = lpf_[x];\n            u32 exp = 0;\n            while (lpf_[x]\
    \ == factor) {\n                x /= factor;\n                exp++;\n       \
    \     }\n            if (exp >= 2u) return 0;\n            res *= -1;\n      \
    \  }\n        return res;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeFactor.hpp
  isVerificationFile: false
  path: Src/Number/LinearSieve.hpp
  requiredBy: []
  timestamp: '2025-05-29 15:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF902-B.test.cpp
  - Test/AtCoder/arc185_e.test.cpp
  - Test/AtCoder/abc177_e.test.cpp
  - Test/AtCoder/abc170_d.test.cpp
documentation_of: Src/Number/LinearSieve.hpp
layout: document
title: "\u7DDA\u5F62\u7BE9 (osa-k\u7D20\u56E0\u6570\u5206\u89E3)"
---

## 概要

ある正整数 $n$ 以下の任意の正整数 $x$ について、適切な前計算の後

- 素数判定
- 素因数分解
- 約数列挙

を提供することができます。いずれも試し割りのアルゴリズムより高速です。

## ライブラリの使い方

#### コンストラクタ

```cpp
LinearSieve(u32 n)
```

$n$ を設定します。

**制約**: $n$ は正整数である

**計算量**: $O(n)$

<br />

#### size

```cpp
usize size() const noexcept
```

コンストラクタで設定した $n$ を返します。

<br />

#### isPrime

```cpp
bool isPrime(u32 x) const noexcept
```

$x$ が素数か判定します。

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $O(1)$

<br />

#### operator[]

```cpp
bool operator[](u32 x) const noexcept
```

$x$ が素数か判定します。

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $O(1)$

<br />

#### divisor

```cpp
template <std::integral T = u32>
std::vector<T> divisor(u32 x) const
```

$x$ の約数を列挙する。**ソートされていないことに注意**

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $x$ の約数の個数に比例する

<br />

#### factorize

std::vector<PrimeFactor> factorize(u32 x) const

$x$ を素因数分解したものを返す。

`PrimeFactor`とは以下のような構造のclassである。

```cpp
class PrimeFactor {
public:
    u32 factor(); // 素因数を返す O(1)
    u32 exponent(); // 指数を返す O(1)
};
```

**制約**: $x$ は $n$ 以下の正整数である

**計算量**: $O(\log x)$

<br />

## 参考

- [線形篩](https://37zigen.com/linear-sieve/)
