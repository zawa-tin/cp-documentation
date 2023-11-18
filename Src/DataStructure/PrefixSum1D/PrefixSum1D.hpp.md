---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
    title: "\u9759\u7684\u306A\u5217\u4E0A\u306E\u533A\u9593\u548C\u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc172_c.test.cpp
    title: ABC172-C Tsundoku
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc229_d.test.cpp
    title: ABC229-D Longest X
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/agc023_a.test.cpp
    title: AGC023-A Zero-Sum Ranges
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_sum.test.cpp
    title: Test/LC/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp\"\
    \n\n#include <cmath>\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    #include <type_traits>\n#include <functional>\n\nnamespace zawa {\n\ntemplate\
    \ <class Group>\nclass PrefixSum1D {\nprivate:\n    using T = typename Group::Element;\n\
    \    std::vector<T> dat_;\n\n    constexpr bool rangeCheck(u32 l, u32 r) const\
    \ {\n        return (l <= r and r < dat_.size());\n    }\n\npublic:\n    PrefixSum1D()\
    \ = default; \n    PrefixSum1D(const std::vector<T>& A) : dat_(A.size() + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n        for (u32 i = 0 ; i < A.size() ; i++)\
    \ {\n            dat_[i + 1] = Group::operation(dat_[i], A[i]);\n        }\n \
    \   }\n\n    inline T operator[](u32 i) const {\n        assert(i < dat_.size());\n\
    \        return dat_[i];\n    }\n\n    inline usize size() const {\n        return\
    \ dat_.size();\n    }\n\n    T product(u32 l, u32 r) const {\n        assert(rangeCheck(l,\
    \ r));\n        return Group::operation(Group::inverse(dat_[l]), dat_[r]);\n \
    \   }\n\n    u32 lowerBound(u32 l, u32 r, const T& v) const {\n        assert(rangeCheck(l,\
    \ r));\n        T value = Group::operation(v, dat_[l]);\n        return std::lower_bound(dat_.begin()\
    \ + l, dat_.begin() + r, value) - dat_.begin();\n    }\n\n    u32 upperBound(u32\
    \ l, u32 r, const T& v) const {\n        assert(rangeCheck(l, r));\n        T\
    \ value = Group::operation(v, dat_[l]);\n        return std::upper_bound(dat_.begin()\
    \ + l, dat_.begin() + r, value) - dat_.begin();\n    }\n\n    template <class\
    \ F>\n    u32 maxRight(u32 l, const F& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n        assert(l\
    \ < dat_.size());\n        assert(f(Group::identity()));\n        auto f_ = [&](const\
    \ T& v) -> bool {\n            return f(Group::operation(v, Group::inverse(dat_[l])));\n\
    \        };\n        return std::partition_point(dat_.begin() + l, dat_.end(),\
    \ f_) - dat_.begin();\n    }\n\n    template <class F>\n    u32 minLeft(u32 r,\
    \ const F& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n        assert(r\
    \ < dat_.size());\n        assert(f(Group::identity()));\n        auto f_ = [&](const\
    \ T& v) -> bool {\n            return f(Group::operation(Group::inverse(v), dat_[r]));\n\
    \        };\n        return dat_.rend() - std::partition_point(dat_.rbegin() +\
    \ (dat_.size() - r - 1), dat_.rend(), f_) - 1;\n    }\n\n    const auto begin()\
    \ const {\n        return dat_.begin();\n    }\n\n    const auto end() const {\n\
    \        return dat_.end();\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cmath>\n\
    #include <vector>\n#include <cassert>\n#include <algorithm>\n#include <type_traits>\n\
    #include <functional>\n\nnamespace zawa {\n\ntemplate <class Group>\nclass PrefixSum1D\
    \ {\nprivate:\n    using T = typename Group::Element;\n    std::vector<T> dat_;\n\
    \n    constexpr bool rangeCheck(u32 l, u32 r) const {\n        return (l <= r\
    \ and r < dat_.size());\n    }\n\npublic:\n    PrefixSum1D() = default; \n   \
    \ PrefixSum1D(const std::vector<T>& A) : dat_(A.size() + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n        for (u32 i = 0 ; i < A.size() ; i++)\
    \ {\n            dat_[i + 1] = Group::operation(dat_[i], A[i]);\n        }\n \
    \   }\n\n    inline T operator[](u32 i) const {\n        assert(i < dat_.size());\n\
    \        return dat_[i];\n    }\n\n    inline usize size() const {\n        return\
    \ dat_.size();\n    }\n\n    T product(u32 l, u32 r) const {\n        assert(rangeCheck(l,\
    \ r));\n        return Group::operation(Group::inverse(dat_[l]), dat_[r]);\n \
    \   }\n\n    u32 lowerBound(u32 l, u32 r, const T& v) const {\n        assert(rangeCheck(l,\
    \ r));\n        T value = Group::operation(v, dat_[l]);\n        return std::lower_bound(dat_.begin()\
    \ + l, dat_.begin() + r, value) - dat_.begin();\n    }\n\n    u32 upperBound(u32\
    \ l, u32 r, const T& v) const {\n        assert(rangeCheck(l, r));\n        T\
    \ value = Group::operation(v, dat_[l]);\n        return std::upper_bound(dat_.begin()\
    \ + l, dat_.begin() + r, value) - dat_.begin();\n    }\n\n    template <class\
    \ F>\n    u32 maxRight(u32 l, const F& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n        assert(l\
    \ < dat_.size());\n        assert(f(Group::identity()));\n        auto f_ = [&](const\
    \ T& v) -> bool {\n            return f(Group::operation(v, Group::inverse(dat_[l])));\n\
    \        };\n        return std::partition_point(dat_.begin() + l, dat_.end(),\
    \ f_) - dat_.begin();\n    }\n\n    template <class F>\n    u32 minLeft(u32 r,\
    \ const F& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n        assert(r\
    \ < dat_.size());\n        assert(f(Group::identity()));\n        auto f_ = [&](const\
    \ T& v) -> bool {\n            return f(Group::operation(Group::inverse(v), dat_[r]));\n\
    \        };\n        return dat_.rend() - std::partition_point(dat_.rbegin() +\
    \ (dat_.size() - r - 1), dat_.rend(), f_) - 1;\n    }\n\n    const auto begin()\
    \ const {\n        return dat_.begin();\n    }\n\n    const auto end() const {\n\
    \        return dat_.end();\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
  requiredBy:
  - Src/DataStructure/PrefixSum1D/StaticRangeSumSolver.hpp
  timestamp: '2023-07-22 13:55:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/static_range_sum.test.cpp
  - Test/AtCoder/abc229_d.test.cpp
  - Test/AtCoder/abc172_c.test.cpp
  - Test/AtCoder/agc023_a.test.cpp
documentation_of: Src/DataStructure/PrefixSum1D/PrefixSum1D.hpp
layout: document
title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 概要

群 $(S, \oplus)$ の上で列 $A$ 上のクエリ $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を処理することができます。ただし、 $A$ に値の変更があってはなりません。

<br />

## ライブラリの使い方

#### テンプレート引数Group

[本ライブラリにおける群の実装について](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Group.html) をご確認ください。

以下、テンプレート引数の`Group::Element`を`T`と略します。

<br />

#### コンストラクタ
```
(1) PrefixSum1D = default
(2) PrefixSum1D(const std::vector<T>& A)
```
(1) デフォルトコンストラクタ

(2) $A$ によって累積和 $S$ を構築します。処理する列 $A$ を`std::vector<T>`として引数に入れてください。以降、 $A$ の長さを $N$ とします。

**計算量:** $O(N)$

<br />

#### operator[]
```
inline T operator[](u32 i) const
```
$S_i$ を返します。(0-indexedです)

**制約:** $i\ \le\ N$

**計算量:** 定数時間

<br />

#### size
```
inline usize size() const
```
$S$ の長さを返します。すなわち $N + 1$ です。

**計算量:** 定数時間

<br />

#### product
```
T product(u32 l, u32 r) const
```

$\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を返します。(0-indexedです)

**制約:** $l\ \le\ r\ \le\ N$

**計算量:** 定数時間

<br />

#### lowerBound
```
u32 lowerBound(u32 l, u32 r, const T& v)
```

$\displaystyle \sum_{i = l}^{r - 1} A_i\ \ge\ v$ となる最左の $r$ を返します。

**制約:** $l\ \le\ r\ \le\ N$

**計算量:** $O(r - l)$

<br />

#### upperBound
```
u32 upperBound(u32 l, u32 r, const T& v)
```

$\displaystyle \sum_{i = l}^{r - 1} A_i\ > v$ となる最左の $r$ を返します。

**制約:** $l\ \le\ r\ \le\ N$

**計算量:** $O(r - l)$

<br />

#### maxRight
```cpp
u32 maxRight<F>(u32 l, const F& f) const
```
$S \to \\{ \text{true}, \text{false} \\}$ でありかつ単調性を持つ関数 $f$ に対して、 $\displaystyle f(\sum_{i = l}^{r - 1} A_i) = \text{false}$ を満たす最左の $r$ を返します。

`f`は関数オブジェクトを入れる必要があります。(ラムダ式とか`std::function<bool(T)>`とかを引数に入れることができる)

**制約:** 
- `F`は`T`型の値をひとつ引数に取り、`bool`値を返り値とする関数オブジェクトであること
- $e =$ `Group::identity()`として $f(e) = \text{true}$ を満たすこと
- $f$ に副作用が無いこと、あったとしても同じ値を引数に入れたのなら常に同じ結果を返すこと
- $l\ \le\ N$

<br />

#### minLeft

**未テストでかつ実装に自信が無いです。**

```cpp
u32 minLeft<F>(u32 r, const F& f) const
```
$S \to \\{ \text{true}, \text{false} \\}$ でありかつ単調性を持つ関数 $f$ に対して、 $\displaystyle f(\sum_{i = l}^{r - 1} A_i) = \text{false}$ を満たす最右の $l$ を返します。

`f`は関数オブジェクトを入れる必要があります。(ラムダ式とか`std::function<bool(T)>`とかを引数に入れることができる)

**制約:** 
- `F`は`T`型の値をひとつ引数に取り、`bool`値を返り値とする関数オブジェクトであること
- $e =$ `Group::identity()`として $f(e) = \text{true}$ を満たすこと
- $f$ に副作用が無いこと、あったとしても同じ値を引数に入れたのなら常に同じ結果を返すこと
- $l\ \le\ N$

<br />

#### begin

```cpp
const auto begin() const
```

内部のコンテナの先頭要素の`const_iterator`を返します。

**計算量**: 定数時間

<br />

#### end

```cpp
const auto end() const
```

内部のコンテナの末尾の次の要素の`const_iterator`を返します。

**計算量**: 定数時間

<br />

## アルゴリズム

簡単のため、 $S = \mathbb{Z}$ 、 $\oplus = +$ で考えます。(群の条件を満たすなら他の $(S, \oplus)$ でも勿論なりたちます)

数列 $A$ に対して、 $\displaystyle S_i = A_0 + A_1 + \dots + A_{i - 1} = \sum_{j = 0}^{i - 1} A_{j}$ が成り立つ $S$ を $A$ の累積和(prefix sum、cumulative sum)と呼びます。

例えば、 $A = (1, 3, -2, 4, 3)$ ならば、 $S = (0, 1, 4, 2, 6, 9)$ です。

$\displaystyle \sum_{i = l}^{r - 1} A_i = \sum_{i = 0}^{r - 1} A_i - \sum_{i = 0}^{l - 1} A_i = S_{r} - S_{l}$ が成り立つので、愚直より高速に $\displaystyle \sum_{i = l}^{r - 1} A_i$ を求めることが可能です。

上の例で一つ区間和の例をとると、 $A_1 + A_2 + A_3 = 3 - 2 + 4 = 5, S_{4} - S_{1} = 6 - 1 = 5$ で確かに一致していることがわかります。他の例でも成り立つと思います。

累積和は頭が壊れるので嫌ですね。出るなと念を送りながらコンテストに出ていますが、当然のように毎回出てくるので辛いです。

<br />

## メモ

可換でない群で累積和を構築する時は注意が必要です。例えば、可換で無い群上で列のSuffix Sumが欲しい時にこのライブラリを貼ると死にます。(`product(l, r)`の値が異なります)
- そもそもそのような実装に注意を払うべきであるような場合は、ライブラリを使うべきでは無いのかも?
