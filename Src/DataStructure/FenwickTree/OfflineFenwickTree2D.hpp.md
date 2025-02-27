---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate\
    \ <class T>\nconcept Monoid = requires {\n    typename T::Element;\n    { T::identity()\
    \ } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n#include <functional>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <Concept::Group Group>\n\
    class FenwickTree {\nprivate:\n    using Value = typename Group::Element;\n\n\
    \    usize n_;\n    u32 bitWidth_;\n    std::vector<Value> a_, dat_;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n    \n    //\
    \ a[i] <- a[i] + v\n    void addDat(i32 i, const Value& v) {\n        assert(0\
    \ <= i and i < static_cast<i32>(n_));\n        for ( i++ ; i < static_cast<i32>(dat_.size())\
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
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\
    };\n\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\
    \n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 6 \"Src/Sequence/CompressedSequence.hpp\"\
    \n#include <algorithm>\n#line 8 \"Src/Sequence/CompressedSequence.hpp\"\n#include\
    \ <iterator>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass\
    \ CompressedSequence {\nprivate:\n    std::vector<T> comped_;\n    std::vector<u32>\
    \ f_;\n    \npublic:\n\n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\
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
    \        assert(i < size());\n        return comped_[i];\n    }\n};\n\n} // namespace\
    \ zawa\n#line 6 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\n\n\
    #include <utility>\n#line 9 \"Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp\"\
    \n#include <tuple>\n\nnamespace zawa {\n\ntemplate <class T, class G>\nclass OfflineFenwickTree2D\
    \ {\npublic:\n    using V = typename G::Element;\n\n    OfflineFenwickTree2D()\
    \ = default;\n\n    u32 operation(T x, T y, const V& v) {\n        u32 res{(u32)idx_.size()};\n\
    \        idx_.emplace_back(false, op_.size());\n        op_.emplace_back(x, y,\
    \ v);\n        return res;\n    }\n\n    u32 product(T lx, T ly, T rx, T ry) {\n\
    \        u32 res{(u32)idx_.size()};\n        idx_.emplace_back(true, prod_.size());\n\
    \        prod_.emplace_back(lx, ly, rx, ry);\n        return res;\n    }\n\n \
    \   inline usize size() const noexcept {\n        return idx_.size();\n    }\n\
    \n    std::vector<std::pair<V, u32>> execute() const {\n        std::vector<T>\
    \ appX;\n        appX.reserve(op_.size());\n        for (u32 i{} ; i < op_.size()\
    \ ; i++) {\n            appX.push_back(std::get<0>(op_[i]));\n        }\n    \
    \    CompressedSequence<T> compX{appX};\n        std::vector<std::vector<T>> appY(compX.size()\
    \ + 1);\n        for (u32 i{} ; i < op_.size() ; i++) {\n            T x{std::get<0>(op_[i])},\
    \ y{std::get<1>(op_[i])};\n            for (u32 j{compX[x] + 1} ; j < appY.size()\
    \ ; j += lsb(j)) {\n                appY[j].push_back(y);\n            }\n   \
    \     }\n        std::vector<CompressedSequence<T>> compY(compX.size() + 1);\n\
    \        for (u32 i{1} ; i < compY.size() ; i++) {\n            compY[i] = CompressedSequence{appY[i]};\n\
    \        }\n        std::vector<FenwickTree<G>> fen(compX.size() + 1); \n    \
    \    for (u32 i{1} ; i < fen.size() ; i++) {\n            fen[i] = FenwickTree<G>(compY[i].size()\
    \ + 1);\n        }\n        std::vector<std::pair<V, u32>> res(prod_.size());\n\
    \n        auto prefix{[&](T x, T y) -> V {\n            V res{G::identity()};\n\
    \            for (u32 i{compX[x]} ; i ; i -= lsb(i)) {\n                res =\
    \ G::operation(res, fen[i].prefixProduct(compY[i][y]));\n            }\n     \
    \       return res;\n        }};\n\n        for (u32 i{} ; i < size() ; i++) {\n\
    \            if (idx_[i].first) { // product\n                auto [lx, ly, rx,\
    \ ry]{prod_[idx_[i].second]};\n                V prod{G::identity()}; \n     \
    \           prod = G::operation(prod, prefix(rx, ry));\n                prod =\
    \ G::operation(prod, G::inverse(prefix(lx, ry)));\n                prod = G::operation(prod,\
    \ G::inverse(prefix(rx, ly)));\n                prod = G::operation(prod, prefix(lx,\
    \ ly));\n                res[idx_[i].second] = std::pair{ prod, i }; \n      \
    \      }\n            else { // operation\n                auto [x, y, v]{op_[idx_[i].second]};\n\
    \                for (u32 j{compX[x] + 1} ; j < fen.size() ; j += lsb(j)) {\n\
    \                    fen[j].operation(compY[j][y], v);\n                }\n  \
    \          }\n        }\n        return res;\n    }\n\nprivate:\n    std::vector<std::tuple<T,\
    \ T, T>> op_;\n    std::vector<std::tuple<T, T, T, T>> prod_;\n    std::vector<std::pair<bool,\
    \ u32>> idx_;\n\n    constexpr i32 lsb(i32 v) const noexcept {\n        return\
    \ v & -v;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"./FenwickTree.hpp\"\
    \n#include \"../../Sequence/CompressedSequence.hpp\"\n\n#include <utility>\n#include\
    \ <vector>\n#include <tuple>\n\nnamespace zawa {\n\ntemplate <class T, class G>\n\
    class OfflineFenwickTree2D {\npublic:\n    using V = typename G::Element;\n\n\
    \    OfflineFenwickTree2D() = default;\n\n    u32 operation(T x, T y, const V&\
    \ v) {\n        u32 res{(u32)idx_.size()};\n        idx_.emplace_back(false, op_.size());\n\
    \        op_.emplace_back(x, y, v);\n        return res;\n    }\n\n    u32 product(T\
    \ lx, T ly, T rx, T ry) {\n        u32 res{(u32)idx_.size()};\n        idx_.emplace_back(true,\
    \ prod_.size());\n        prod_.emplace_back(lx, ly, rx, ry);\n        return\
    \ res;\n    }\n\n    inline usize size() const noexcept {\n        return idx_.size();\n\
    \    }\n\n    std::vector<std::pair<V, u32>> execute() const {\n        std::vector<T>\
    \ appX;\n        appX.reserve(op_.size());\n        for (u32 i{} ; i < op_.size()\
    \ ; i++) {\n            appX.push_back(std::get<0>(op_[i]));\n        }\n    \
    \    CompressedSequence<T> compX{appX};\n        std::vector<std::vector<T>> appY(compX.size()\
    \ + 1);\n        for (u32 i{} ; i < op_.size() ; i++) {\n            T x{std::get<0>(op_[i])},\
    \ y{std::get<1>(op_[i])};\n            for (u32 j{compX[x] + 1} ; j < appY.size()\
    \ ; j += lsb(j)) {\n                appY[j].push_back(y);\n            }\n   \
    \     }\n        std::vector<CompressedSequence<T>> compY(compX.size() + 1);\n\
    \        for (u32 i{1} ; i < compY.size() ; i++) {\n            compY[i] = CompressedSequence{appY[i]};\n\
    \        }\n        std::vector<FenwickTree<G>> fen(compX.size() + 1); \n    \
    \    for (u32 i{1} ; i < fen.size() ; i++) {\n            fen[i] = FenwickTree<G>(compY[i].size()\
    \ + 1);\n        }\n        std::vector<std::pair<V, u32>> res(prod_.size());\n\
    \n        auto prefix{[&](T x, T y) -> V {\n            V res{G::identity()};\n\
    \            for (u32 i{compX[x]} ; i ; i -= lsb(i)) {\n                res =\
    \ G::operation(res, fen[i].prefixProduct(compY[i][y]));\n            }\n     \
    \       return res;\n        }};\n\n        for (u32 i{} ; i < size() ; i++) {\n\
    \            if (idx_[i].first) { // product\n                auto [lx, ly, rx,\
    \ ry]{prod_[idx_[i].second]};\n                V prod{G::identity()}; \n     \
    \           prod = G::operation(prod, prefix(rx, ry));\n                prod =\
    \ G::operation(prod, G::inverse(prefix(lx, ry)));\n                prod = G::operation(prod,\
    \ G::inverse(prefix(rx, ly)));\n                prod = G::operation(prod, prefix(lx,\
    \ ly));\n                res[idx_[i].second] = std::pair{ prod, i }; \n      \
    \      }\n            else { // operation\n                auto [x, y, v]{op_[idx_[i].second]};\n\
    \                for (u32 j{compX[x] + 1} ; j < fen.size() ; j += lsb(j)) {\n\
    \                    fen[j].operation(compY[j][y], v);\n                }\n  \
    \          }\n        }\n        return res;\n    }\n\nprivate:\n    std::vector<std::tuple<T,\
    \ T, T>> op_;\n    std::vector<std::tuple<T, T, T, T>> prod_;\n    std::vector<std::pair<bool,\
    \ u32>> idx_;\n\n    constexpr i32 lsb(i32 v) const noexcept {\n        return\
    \ v & -v;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: false
  path: Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
  requiredBy: []
  timestamp: '2025-02-27 21:44:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
documentation_of: Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
layout: document
title: Fenwick Tree 2D (Offline Query)
---

## 概要

二次元FenwickTree!!

## ライブラリの使い方

#### テンプレート引数

```cpp
template <class T, class G>
```

`T`: 座標の型

`G`: データ構造に乗せる代数的構造

#### operation

```cpp
u32 operation(T x, T y, const V& v)
```

$(x, y)$ に $v$ を加算する。これが何番目のクエリかを返す。

<br />

#### product

```cpp
u32 product(T lx, T ly, T rx, T ry)
```

$\sum_{x = lx}^{rx - 1} \sum_{y = ly}^{ry - 1} A_{x, y}$ を計算する。

一度も`operation`で呼ばれていない場所からは`G::identity()`が加算される。

これが何番目のクエリかを返す。

<br />

#### execute

```cpp
std::vector<std::pair<V, u32>> execute() const
```

`operation`と`product`で登録されたクエリを登録された順に処理する。

`product`の解が登録された順番に保管された列を返す。

- first: 解
- second: それが何番目に呼び出されたクエリか？
