---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/rectangle_sum.test.cpp
    title: Test/LC/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp\"\
    \n\n#include <algorithm>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    #include <type_traits>\n\nnamespace zawa {\n\n// P...\u5EA7\u6A19\u306E\u578B\n\
    // W...\u91CD\u307F\u306E\u578B\ntemplate <class T, class U>\nstd::vector<typename\
    \ T::W> StaticPointAddRectangleSum(std::vector<T> ps, std::vector<U> qs) {\n \
    \   using P = typename T::P;\n    using W = typename T::W;\n    static_assert(std::same_as<typename\
    \ T::P, typename U::P>, \"T::P and U::P must be same\");\n    usize n{ps.size()},\
    \ q{qs.size()};\n    std::vector<P> xs(n);\n    for (usize i{} ; i < n ; i++)\
    \ xs[i] = ps[i].x;\n    std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    std::sort(ps.begin(), ps.end(), [&](const auto& L,\
    \ const auto& R) -> bool {\n            return L.y < R.y;\n            });\n \
    \   using Q = std::pair<P, usize>;\n    std::vector<Q> query(2 * qs.size());\n\
    \    for (usize i{} ; i < qs.size() ; i++) {\n        qs[i].l = (P)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), qs[i].l));\n        qs[i].r = (P)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), qs[i].r));\n        query[i] = std::pair{qs[i].d,\
    \ i};\n        query[i + q] = std::pair{qs[i].u, i + q};\n    }\n    std::sort(query.begin(),\
    \ query.end());\n    std::vector<W> fen(xs.size() + 1), res(qs.size());\n    auto\
    \ pref{[&](i32 r) -> W {\n        W sum{};\n        for ( ; r ; r -= r & -r) sum\
    \ += fen[r];\n        return sum;\n    }};\n    for (usize i{}, j{} ; i < query.size()\
    \ ; i++) {\n        while (j < n and ps[j].y < query[i].first) {\n           \
    \ i32 x{(i32)std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(),\
    \ ps[j].x))}; \n            for ( x++ ; (usize)x < fen.size() ; x += x & -x) fen[x]\
    \ += ps[j].w;\n            j++;\n        }\n        usize idx{query[i].second};\n\
    \        if (idx < q) {\n            res[idx] += pref(qs[idx].l) - pref(qs[idx].r);\n\
    \        }\n        else {\n            idx -= q;\n            res[idx] += -pref(qs[idx].l)\
    \ + pref(qs[idx].r);\n        }\n    } \n    return res;\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <concepts>\n#include <utility>\n#include <vector>\n#include <type_traits>\n\
    \nnamespace zawa {\n\n// P...\u5EA7\u6A19\u306E\u578B\n// W...\u91CD\u307F\u306E\
    \u578B\ntemplate <class T, class U>\nstd::vector<typename T::W> StaticPointAddRectangleSum(std::vector<T>\
    \ ps, std::vector<U> qs) {\n    using P = typename T::P;\n    using W = typename\
    \ T::W;\n    static_assert(std::same_as<typename T::P, typename U::P>, \"T::P\
    \ and U::P must be same\");\n    usize n{ps.size()}, q{qs.size()};\n    std::vector<P>\
    \ xs(n);\n    for (usize i{} ; i < n ; i++) xs[i] = ps[i].x;\n    std::sort(xs.begin(),\
    \ xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n   \
    \ std::sort(ps.begin(), ps.end(), [&](const auto& L, const auto& R) -> bool {\n\
    \            return L.y < R.y;\n            });\n    using Q = std::pair<P, usize>;\n\
    \    std::vector<Q> query(2 * qs.size());\n    for (usize i{} ; i < qs.size()\
    \ ; i++) {\n        qs[i].l = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), qs[i].l));\n        qs[i].r = (P)std::distance(xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), qs[i].r));\n        query[i] = std::pair{qs[i].d, i};\n        query[i\
    \ + q] = std::pair{qs[i].u, i + q};\n    }\n    std::sort(query.begin(), query.end());\n\
    \    std::vector<W> fen(xs.size() + 1), res(qs.size());\n    auto pref{[&](i32\
    \ r) -> W {\n        W sum{};\n        for ( ; r ; r -= r & -r) sum += fen[r];\n\
    \        return sum;\n    }};\n    for (usize i{}, j{} ; i < query.size() ; i++)\
    \ {\n        while (j < n and ps[j].y < query[i].first) {\n            i32 x{(i32)std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), ps[j].x))}; \n            for ( x++ ;\
    \ (usize)x < fen.size() ; x += x & -x) fen[x] += ps[j].w;\n            j++;\n\
    \        }\n        usize idx{query[i].second};\n        if (idx < q) {\n    \
    \        res[idx] += pref(qs[idx].l) - pref(qs[idx].r);\n        }\n        else\
    \ {\n            idx -= q;\n            res[idx] += -pref(qs[idx].l) + pref(qs[idx].r);\n\
    \        }\n    } \n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2024-11-18 05:20:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/rectangle_sum.test.cpp
documentation_of: Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp
layout: document
title: Static Point Add Rectangle Sum
---

## 概要

以下のようなクエリを処理する

始めに $N$ 個の重み付きの点が与えられる。その次に $Q$ 個の矩形領域が与えられる。各矩形領域の中にある点の重みの総和を求めよ。

## ライブラリの使い方

```cpp
template <class T, class U>
std::vector<typename T::W> StaticPointAddRectangleSum(std::vector<T> ps, std::vector<U> qs) {
```

#### ps

重み付きの点の`std::vector`

`T`は基本的には以下をコピれば問題無いはず。

```cpp
struct Point {
    using P = int; // 座標の型、int, long long 
    using W = long long; // 重みの型、int, long long, mint
    P x, y;
    W w;
};
```

`P`は**符号付き整数**であることが期待される。

P型のメンバ変数`x, y`とW型のメンバ変数`w`が必要。

## qs

矩形領域の`std::vector`

基本的には以下をコピれば問題無い

```cpp
struct Rect {
    using P = int;
    int l, d, r, u;
};
```

`P`は座標の型、psの`P`と型が一致している必要がある。

メンバ変数`l`, `d`, `r`, `u`が必要。左下の点が $(l, d)$ 、右上の点が $(r, u)$ となるようにする。

## アルゴリズム

矩形クエリ $(l, d, r, u)$ は $(-\infty, -\infty, l, d), (-\infty, -\infty, r, d), (-\infty, -\infty, l, u), (-\infty, -\infty, r, u)$ の4つの矩形クエリの足し引きに帰着できる。

一方の軸について平面走査をすることにすると、一点更新・prefix和取得に帰着し、Fenwick Treeで処理できる。

- Fenwick Treeにのせる方の座標は座圧する。

時間計算量 $\Theta (N\log N + Q(\log Q + \log N))$ 、空間計算量 $\Theta (N + Q)$ でできる。

アルゴリズム・実装共に [ei1333の日記](https://ei1333.hateblo.jp/entry/2022/06/10/022355) を参考にした。
