---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
    title: Fenwick Tree 2D (Offline Query)
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
    title: Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Set/OfflineOrderedSet.hpp
    title: Src/DataStructure/Set/OfflineOrderedSet.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/RangeKthSmallest.hpp
    title: Range Kth Smallest
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc213_c.test.cpp
    title: Test/AtCoder/abc213_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc287_g.test.cpp
    title: Test/AtCoder/abc287_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc384_g.test.cpp
    title: Test/AtCoder/abc384_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc389_f.test.cpp
    title: Test/AtCoder/abc389_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/tdpc_target.test.cpp
    title: Test/AtCoder/tdpc_target.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1026-E.test.cpp
    title: Test/CF/CF1026-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/ordered_set/OfflineOrderedSet.test.cpp
    title: Test/LC/ordered_set/OfflineOrderedSet.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_kth_smallest.test.cpp
    title: Test/LC/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_range_frequency.test.cpp
    title: Test/LC/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence\
    \ {\npublic:\n\n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\
    \n    CompressedSequence() = default;\n\n    template <class InputIterator>\n\
    \    CompressedSequence(InputIterator first, InputIterator last) : comped_(first,\
    \ last), f_{} {\n        std::sort(comped_.begin(), comped_.end());\n        comped_.erase(std::unique(comped_.begin(),\
    \ comped_.end()), comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n\n    inline\
    \ std::vector<T> comped() const noexcept {\n        return comped_;\n    }\n\n\
    private:\n\n    std::vector<T> comped_;\n\n    std::vector<u32> f_;\n\n};\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <limits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence {\npublic:\n\
    \n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\n   \
    \ CompressedSequence() = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n\n    inline\
    \ std::vector<T> comped() const noexcept {\n        return comped_;\n    }\n\n\
    private:\n\n    std::vector<T> comped_;\n\n    std::vector<u32> f_;\n\n};\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/CompressedSequence.hpp
  requiredBy:
  - Src/DataStructure/Set/OfflineOrderedSet.hpp
  - Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp
  - Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
  - Src/Sequence/RangeKthSmallest.hpp
  timestamp: '2025-03-04 23:23:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF1026-E.test.cpp
  - Test/AtCoder/tdpc_target.test.cpp
  - Test/AtCoder/abc384_g.test.cpp
  - Test/AtCoder/abc287_g.test.cpp
  - Test/AtCoder/abc389_f.test.cpp
  - Test/AtCoder/abc213_c.test.cpp
  - Test/LC/ordered_set/OfflineOrderedSet.test.cpp
  - Test/LC/range_kth_smallest.test.cpp
  - Test/LC/static_range_frequency.test.cpp
  - Test/LC/point_add_rectangle_sum/OfflineSegmentTree2D.test.cpp
  - Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
documentation_of: Src/Sequence/CompressedSequence.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

## 概要

長さ $N$ の列 $A$ を座標圧縮して、これを管理します。 $A$ の要素の種類数を $M$ 、すなわち $\mid \\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}\mid = M$ とします。

<br />

## 使い方

#### テンプレート引数T

圧縮する対象の $A$ は`std::vector<T>`である必要があります。

**制約:** `operator<` と `operator==`が定義されている型・クラスであること(無いとコンパイルエラーになります)

<br />

#### コンストラクタ
```
(1) CompressedSequence() = default;
(2) CompressedSequence(const std::vector<T>& A)
(3) CompressedSequence(InputIterator first, InputIterator last)
```

(1) デフォルトコンストラクタ

(2) 引数に与えた $A$ で座標圧縮した列を構築します。

(3) イテレータfirst, last間で構築します。

**計算量:** $O(N\log N)$

<br />

#### size
```cpp
inline usize size() const noexcept
```
$M$ を返します。

**計算量:** 定数時間


<br />

#### operator[]
```cpp
u32 operator[](const T& v) const
```

集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ 上で`v`で`lower_bound`します。

`lower_bound - begin()`を返します。

**計算量:** $O(\log N)$

<br />

#### upper_bound

```cpp
u32 upper_bound(const T& v) const
```

集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ 上で`v`で`upper_bound`します。

`upper_bound - begin()`を返します。

**計算量:** $O(\log N)$

#### at

```cpp
u32 at(const T& v) const
```

operator[]と一緒ですが、 $v$ が $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ に存在しない場合assertに引っかかる

<br />

#### contains

```cpp
bool contains(const T& v) const
```

$v$ が含まれるか判定します。

**計算量:** $O(\log N)$

<br />

#### find

```cpp
u32 find(const T& v) const
```

$v$ が含まれるなら`(*self)[v]`を、そうでないなら`CompressedSequence<T>::NotFound`を返します。

`CompressedSequence<T>::NotFound`は`std::numeric_limits<u32>::max()`と同じ値です。

**計算量:** $O(\log N)$

<br />


#### map
```cpp
inline u32 map(u32 i) const noexcept
```

引数で与えた非負整数$i$ に対して、 $A_i$ の座標圧縮後の値を返します。

**制約:** $i\ <\ N$

**計算量:** 定数時間

<br />

#### inverse

```cpp
inline T inverse(u32 i) const noexcept
```
集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ で $i$ 番目に小さい要素を返します。

**制約**: $0\ \le\ i\ <\ \text{size()}$

**計算量**: 定数時間

<br />


#### comped

```cpp
inline std::vector<T> comped() const noexcept
```

集合 $\\{\ x \mid \exists i_{1\le i\le N}\ x = A_i\ \\}$ に属する値を小さい順に入れたvectorを返します。

**計算量**: 集合サイズ

## アルゴリズム、そもそも座標圧縮とは

長さ $N$ の整数列 $B$ は、次の条件を満たす時に「 $A$ を座標圧縮した列」であると(私を含む多くの競プロerが)呼びます。
- $B$ の各要素が $0$ 以上 $M$ 未満の整数である[^1]。
- $A_i = A_j$ を満たす時、またその時に限り $B_i = B_j$ である。
- $A_i < A_j$ を満たす時、またその時に限り $B_i < B_j$ である。

このような $B$ は $A$ に対して一意に定まることが知られています。

例1: $(3, 2, 15, 3, 13, 15)$ を座標圧縮した列は $(1, 0, 3, 1, 2, 3)$ です。

例2: $(0, 0, 0)$ を座標圧縮した列は $(0, 0, 0)$ です。

例3: トランプの役の列 $(\text{A}, \text{Q}, \text{4}, \text{2})$ を大小関係を「大富豪で強い方が大きい」と定めて座標圧縮した列は $(2, 1, 0, 3)$ です。

<br />

座標圧縮した列の構築のオーソドックスなやり方として、以下の $2$ つのやり方が有名です。
- 本質は $1$ も $2$ も同じです。

1. ソートして重複要素を取り除いた列を用意して、その列上で二分探索することで自身より小さい値の種類数を得る。

2. 連想配列に $A$ を押し込んで、小さい順に番号を振る。

本ライブラリでは $1$ のやり方を採用しています。

<br />

[^1]: $1$ 以上 $M$ 以下とする人もいると思います。0-indexedか1-indexedかの違いだけです。
