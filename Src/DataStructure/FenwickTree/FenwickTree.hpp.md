---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_B.test.cpp
    title: Test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_f.test.cpp
    title: Test/AtCoder/abc276_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_range_sum.test.cpp
    title: Test/LC/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc287_g.test.cpp
    title: Test/Manual/abc287_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n#include <functional>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <class Group>\nclass FenwickTree\
    \ {\nprivate:\n    using Value = typename Group::Element;\n\n    usize n_;\n \
    \   u32 bitWidth_;\n    std::vector<Value> a_, dat_;\n\n    constexpr i32 lsb(i32\
    \ x) const noexcept {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i]\
    \ + v\n    void addDat(i32 i, const Value& v) {\n        assert(0 <= i and i <\
    \ static_cast<i32>(n_));\n        for ( i++ ; i < static_cast<i32>(dat_.size())\
    \ ; i += lsb(i)) {\n            dat_[i] = Group::operation(dat_[i], v);\n    \
    \    }\n    }\n\n    // return a[0] + a[1] + .. + a[i - 1]\n    Value product(i32\
    \ i) const {\n        assert(0 <= i and i <= static_cast<i32>(n_));\n        Value\
    \ res{ Group::identity() };\n        for ( ; i > 0 ; i -= lsb(i)) {\n        \
    \    res = Group::operation(res, dat_[i]);\n        }\n        return res;\n \
    \   }\n\npublic:\n    FenwickTree() : n_{}, bitWidth_{}, a_{}, dat_{} {}\n\n \
    \   FenwickTree(usize n) : n_{ n }, bitWidth_{ std::__lg(static_cast<u32>(n))\
    \ + 1 }, a_(n), dat_(n + 1, Group::identity()) {\n        dat_.shrink_to_fit();\n\
    \    }\n\n    FenwickTree(const std::vector<Value>& a) : n_{ a.size() }, bitWidth_{\
    \ std::__lg(static_cast<u32>(a.size())) + 1 }, a_(a), dat_(a.size() + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();  \n        for (i32 i{} ; i < static_cast<i32>(n_)\
    \ ; i++) {\n            addDat(i, a[i]);\n        }\n    }\n\n    // return a[i]\n\
    \    const Value& get(usize i) const noexcept {\n        assert(i < n_);\n   \
    \     return a_[i];\n    }\n\n    // return a[i]\n    const Value& operator[](usize\
    \ i) const noexcept {\n        assert(i < n_);\n        return a_[i];\n    }\n\
    \n    usize size() const noexcept {\n        return n_;\n    }\n\n    // a[i]\
    \ <- a[i] + v\n    void operation(usize i, const Value& v) {\n        assert(i\
    \ < n_);\n        addDat(i, v);\n        a_[i] = Group::operation(a_[i], v);\n\
    \    }\n\n    // a[i] <- v\n    void set(usize i, const Value& v) {\n        assert(i\
    \ < n_);\n        addDat(i, Group::operation(Group::inverse(a_[i]), v));\n   \
    \     a_[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n    Value\
    \ prefixProduct(usize r) const {\n        assert(r <= n_);\n        return product(r);\n\
    \    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n    Value product(usize\
    \ l, usize r) const {\n        assert(l <= r and r <= n_);\n        return Group::operation(Group::inverse(product(l)),\
    \ product(r));\n    }\n\n    template <class Function>\n    u32 maxRight(usize\
    \ l, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(l < n_);\n        Value sum{ Group::inverse(product(l)) };\
    \ \n        u32 r{};\n        for (u32 bit{ bitWidth_ } ; bit ; ) {\n        \
    \    bit--;\n            u32 nxt{ r | (1u << bit) };\n            if (nxt < dat_.size()\
    \ and f(Group::operation(sum, dat_[nxt]))) {\n                sum = Group::operation(sum,\
    \ dat_[nxt]);\n                r = std::move(nxt);\n            }\n        }\n\
    \        assert(l <= r);\n        return r;\n    }\n\n    template <class Function>\n\
    \    u32 minLeft(usize r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(r <= n_);\n        Value sum{ product(r) };\n        u32 l{};\n\
    \        for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n         \
    \   u32 nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]),\
    \ sum))) {\n                sum = Group::operation(Group::inverse(dat_[nxt]),\
    \ sum);\n                l = std::move(nxt);\n            }\n        }\n     \
    \   assert(l <= r);\n        return l;\n    }\n\n    // debug print\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {\n      \
    \  for (u32 i{} ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i)\
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    };\n\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <ostream>\n#include <functional>\n#include <type_traits>\n\
    \nnamespace zawa {\n\ntemplate <class Group>\nclass FenwickTree {\nprivate:\n\
    \    using Value = typename Group::Element;\n\n    usize n_;\n    u32 bitWidth_;\n\
    \    std::vector<Value> a_, dat_;\n\n    constexpr i32 lsb(i32 x) const noexcept\
    \ {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i] + v\n    void addDat(i32\
    \ i, const Value& v) {\n        assert(0 <= i and i < static_cast<i32>(n_));\n\
    \        for ( i++ ; i < static_cast<i32>(dat_.size()) ; i += lsb(i)) {\n    \
    \        dat_[i] = Group::operation(dat_[i], v);\n        }\n    }\n\n    // return\
    \ a[0] + a[1] + .. + a[i - 1]\n    Value product(i32 i) const {\n        assert(0\
    \ <= i and i <= static_cast<i32>(n_));\n        Value res{ Group::identity() };\n\
    \        for ( ; i > 0 ; i -= lsb(i)) {\n            res = Group::operation(res,\
    \ dat_[i]);\n        }\n        return res;\n    }\n\npublic:\n    FenwickTree()\
    \ : n_{}, bitWidth_{}, a_{}, dat_{} {}\n\n    FenwickTree(usize n) : n_{ n },\
    \ bitWidth_{ std::__lg(static_cast<u32>(n)) + 1 }, a_(n), dat_(n + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n    }\n\n    FenwickTree(const std::vector<Value>&\
    \ a) : n_{ a.size() }, bitWidth_{ std::__lg(static_cast<u32>(a.size())) + 1 },\
    \ a_(a), dat_(a.size() + 1, Group::identity()) {\n        dat_.shrink_to_fit();\
    \  \n        for (i32 i{} ; i < static_cast<i32>(n_) ; i++) {\n            addDat(i,\
    \ a[i]);\n        }\n    }\n\n    // return a[i]\n    const Value& get(usize i)\
    \ const noexcept {\n        assert(i < n_);\n        return a_[i];\n    }\n\n\
    \    // return a[i]\n    const Value& operator[](usize i) const noexcept {\n \
    \       assert(i < n_);\n        return a_[i];\n    }\n\n    usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    // a[i] <- a[i] + v\n    void operation(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, v);\n     \
    \   a_[i] = Group::operation(a_[i], v);\n    }\n\n    // a[i] <- v\n    void set(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, Group::operation(Group::inverse(a_[i]),\
    \ v));\n        a_[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n\
    \    Value prefixProduct(usize r) const {\n        assert(r <= n_);\n        return\
    \ product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n    Value\
    \ product(usize l, usize r) const {\n        assert(l <= r and r <= n_);\n   \
    \     return Group::operation(Group::inverse(product(l)), product(r));\n    }\n\
    \n    template <class Function>\n    u32 maxRight(usize l, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>,\
    \ \"maxRight's argument f must be function bool(T)\");\n        assert(l < n_);\n\
    \        Value sum{ Group::inverse(product(l)) }; \n        u32 r{};\n       \
    \ for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n            u32 nxt{\
    \ r | (1u << bit) };\n            if (nxt < dat_.size() and f(Group::operation(sum,\
    \ dat_[nxt]))) {\n                sum = Group::operation(sum, dat_[nxt]);\n  \
    \              r = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return r;\n    }\n\n    template <class Function>\n    u32 minLeft(usize\
    \ r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(r <= n_);\n        Value sum{ product(r) };\n        u32 l{};\n\
    \        for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n         \
    \   u32 nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]),\
    \ sum))) {\n                sum = Group::operation(Group::inverse(dat_[nxt]),\
    \ sum);\n                l = std::move(nxt);\n            }\n        }\n     \
    \   assert(l <= r);\n        return l;\n    }\n\n    // debug print\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {\n      \
    \  for (u32 i{} ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i)\
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    };\n\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/FenwickTree/FenwickTree.hpp
  requiredBy: []
  timestamp: '2023-12-03 18:29:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_B.test.cpp
  - Test/AtCoder/abc276_f.test.cpp
  - Test/LC/vertex_add_path_sum.test.cpp
  - Test/LC/point_add_range_sum.test.cpp
  - Test/Manual/abc287_g.test.cpp
documentation_of: Src/DataStructure/FenwickTree/FenwickTree.hpp
layout: document
title: Fenwick Tree
---

## 概要

可換群 $G = (S, \circ)$ 上で列上の一点更新、区間積クエリに答えることができるデータ構造です。
- 以後、管理する列を $A$ とします。

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class Group>
```

群 $G$ を指定します。

詳細は、[本ライブラリにおける群の実装について](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Group.html) を確認してください。

以下、`Group::Element` を `Value` と訳します。

<br />

#### コンストラクタ

```cpp
(1) FenwickTree()
(2) FenwickTree(usize n)
(3) FenwickTree(const std::vector<Value>& a)
```

(1) $A$ を空列で初期化します

**計算量**: 定数時間

(2) $A$ を長さ $n$ で各要素が `Group::identity` である列で初期化します

**計算量**: $O(n)$

(3) $A$ を `a` で初期化します

**計算量**: `a`の長さを $n$ として $O(n\log n)$

<br />

#### get

```cpp
const Value& get(usize i) const noexcept
```

$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: 定数時間

<br/>

#### operator[]

```cpp
const Value& operator[](usize i) const noexcept
```
$A_i$ を返します。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: 定数時間

<br />

#### size

```cpp
usize size() const noexcept
```

$A$ の要素数を返します。

**計算量**: 定数時間

<br />

#### operation

```cpp
void operation(usize i, const Value& v)
```

$A_i$ を $A_i \circ v$ に置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br />

#### set

```cpp
void set(usize i, const Value& v)
```
$A_i$ を $v$ を置き換えます。

**制約**: $0\ \le\ i\ <\ n$

**計算量**: $O(\log n)$

<br />

#### prefixProduct

```cpp
Value prefixProduct(usize r) const;
```

$\displaystyle \prod_{i = 0}^{r - 1} A_{i}$ を求め、返します。

このメンバは`Group::inverse`を呼ばないので、`inverse`が定義されていない`Group`でも呼び出すことができます。

- 可換モノイドならok

<br />

#### product

```cpp
Value product(usize l, usize r) const
```

$\displaystyle \prod_{i = l}^{r - 1} A_i$ を求めます。

**制約**: $0\ \le\ l\ \le\ r\ \le\ n$

**計算量**: $O(\log n)$

<br />

#### maxRight

```cpp
template <class Function>
u32 maxRight(u32 l, const Function& f) const
```

ある$l$ 以上の整数 $m$ が存在して、 $l$ 以上 $m$ 未満の整数 $i$ について $\displaystyle f(\prod_{j = l}^{i} A_{j}) = \text{true}$ かつ $m$ 以上の整数 $i$ について $f(\displaystyle\prod_{j = l}^{i} A_{j}) = \text{false}$ であることを仮定します。

そのような状況で、 $m$ を発見して返します。

ただし、 $f(\displaystyle \prod_{i = l}^{n - 1} A_{i}) = \text{true}$ の時は $n$ を返します。

**制約**

- $0\ \le\ l\ <\ n$
- $f$ は`Value`から`bool`への写像
- 上記の仮定を満たす

**計算量**: $O(\log n)$

<br />

#### minLeft

```cpp
template <class Function>
u32 minLeft(u32 l, const Function& f) const
```

ある$r$ 以下の整数 $m$ が存在して、 $0$ 以上 $m$ 以下の整数 $i$ について $f(\displaystyle \prod_{j = i}^{r - 1} A_{j}) = \text{false}$ かつ $m + 1$ 以上 $r$ 以下の整数 $i$ について $f(\displaystyle \prod_{j = i}^{r - 1} A_{j}) = \text{true}$ であることを仮定します。

そのような状況で、 $m$ を発見して返します。

ただし、 $f(\displaystyle \prod_{i = 0}^{r - 1} A_{i}) = \text{true}$ の時は $0$ を返します。


**制約**

- $0\ \le\ r\ \le\ n$
- $f$ は`Value`から`bool`への写像
- 上記の仮定を満たす

**計算量**: $O(\log n)$

<br />

#### operator<<

```cpp
friend std::ostream& operator<<(std::ostream& os, const FenwickTree& ft)
```

$n + 1$ 要素空白区切りで出力します。 $i$ 要素目は $\displaystyle \prod_{j = 0}^{i} A_{j}$ を出力します。

<br />

#### update

2023/12/03: prefixProductメンバを作成

2023/12/03: 一部のメンバの引数の型`u32`を`usize`へ変更

2023/12/28: minLeftをverify
