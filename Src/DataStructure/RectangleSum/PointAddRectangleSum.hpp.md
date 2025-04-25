---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
    title: Rectangle Sum of PointCloud
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/PointAddRectangleSum.test.cpp
    title: Test/LC/point_add_rectangle_sum/PointAddRectangleSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp\"\
    \n\n#line 2 \"Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp\"\n\n\
    #line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp\"\
    \n\n#include <algorithm>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    #include <type_traits>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Point = requires (T p) {\n    typename T::P;\n    typename\
    \ T::W;\n    { p.x } -> std::same_as<typename T::P&>;\n    { p.y } -> std::same_as<typename\
    \ T::P&>;\n    { p.w } -> std::same_as<typename T::W&>;\n};\n\ntemplate <class\
    \ T>\nconcept Rectangle = requires (T r) {\n    typename T::P;\n    { r.l } ->\
    \ std::same_as<typename T::P&>;\n    { r.d } -> std::same_as<typename T::P&>;\n\
    \    { r.r } -> std::same_as<typename T::P&>;\n    { r.u } -> std::same_as<typename\
    \ T::P&>;\n};\n\ntemplate <class T, class U>\nconcept RSOPCQuery = Point<T> and\
    \ Rectangle<U> and std::same_as<typename T::P, typename U::P>;\n\n} // namespace\
    \ concepts\n\ntemplate <class T, class U>\nstd::vector<typename T::W> RectangleSumOfPointCloud(std::vector<T>\
    \ ps, std::vector<U> qs) requires concepts::RSOPCQuery<T, U> {\n    using P =\
    \ typename T::P;\n    using W = typename T::W;\n    usize n{ps.size()}, q{qs.size()};\n\
    \    std::vector<P> xs(n);\n    for (usize i{} ; i < n ; i++) xs[i] = ps[i].x;\n\
    \    std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()),\
    \ xs.end());\n    std::sort(ps.begin(), ps.end(), [&](const auto& L, const auto&\
    \ R) -> bool {\n            return L.y < R.y;\n            });\n    using Q =\
    \ std::pair<P, usize>;\n    std::vector<Q> query(qs.size() << 1);\n    for (usize\
    \ i{} ; i < qs.size() ; i++) {\n        qs[i].l = (P)std::distance(xs.begin(),\
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
    \ zawa\n#line 5 \"Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp\"\n\n\
    #include <cassert>\n#line 9 \"Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T, class U>\nrequires concepts::RSOPCQuery<T,\
    \ U>\nclass PointAddRectangleSum {\npublic:\n    using P = typename T::P;\n  \
    \  using W = typename T::W;\n\n    usize add(const T& P) {\n        usize res{m_ps.size()};\n\
    \        m_pos.emplace_back(false, res);\n        m_ps.push_back(P);\n       \
    \ return res;\n    }\n\n    usize add(T&& P) {\n        usize res{m_ps.size()};\n\
    \        m_pos.emplace_back(false, res);\n        m_ps.push_back(std::move(P));\n\
    \        return res;\n    }\n\n    usize product(const U& Q) {\n        usize\
    \ res{m_qs.size()};\n        m_pos.emplace_back(true, res);\n        m_qs.push_back(Q);\n\
    \        return res;\n    }\n\n    usize product(U&& Q) {\n        usize res{m_qs.size()};\n\
    \        m_pos.emplace_back(true, res);\n        m_qs.push_back(std::move(Q));\n\
    \        return res;\n    }\n\n    std::vector<W> execute() const {\n        std::vector<W>\
    \ res(m_qs.size());\n\n        auto rec{[&](auto rec, usize l, usize r) -> void\
    \ {\n            assert(l <= r);\n            if (l + 1 >= r) return;\n      \
    \      if (r - l > THRESHOLD) {\n                usize m{(l + r) >> 1};\n    \
    \            rec(rec, l, m);\n                rec(rec, m, r);\n              \
    \  std::vector<usize> p, q;\n                for (usize i{l} ; i < m ; i++) if\
    \ (!m_pos[i].first) {\n                    p.push_back(m_pos[i].second);\n   \
    \             }\n                for (usize i{m} ; i < r ; i++) if (m_pos[i].first)\
    \ {\n                    q.push_back(m_pos[i].second);\n                }\n  \
    \              if (p.empty() or q.empty()) return;\n                std::vector<W>\
    \ kiyo{RectangleSumOfPointCloud<T, U>(\n                        std::vector<T>(m_ps.begin()\
    \ + p.front(), m_ps.begin() + p.back() + 1),\n                        std::vector<U>(m_qs.begin()\
    \ + q.front(), m_qs.begin() + q.back() + 1)\n                        )};\n   \
    \             for (usize i{} ; i < q.size() ; i++) {\n                    res[q[i]]\
    \ += kiyo[i];\n                }\n            }\n            else {\n        \
    \        for (usize i{l} ; i < r ; i++) if (m_pos[i].first) {\n              \
    \      const U& u{m_qs[m_pos[i].second]};\n                    for (usize j{l}\
    \ ; j < i ; j++) if (!m_pos[j].first) {\n                        const T& t{m_ps[m_pos[j].second]};\n\
    \                        if (u.l <= t.x and t.x < u.r and u.d <= t.y and t.y <\
    \ u.u) {\n                            res[m_pos[i].second] += t.w;\n         \
    \               }\n                    }\n                }\n            }\n \
    \       }};\n\n        rec(rec, usize{0}, m_pos.size());\n        return res;\n\
    \    }\n\nprivate:\n\n    static constexpr usize THRESHOLD{200};\n\n    std::vector<T>\
    \ m_ps;\n    std::vector<U> m_qs;\n    std::vector<std::pair<bool, usize>> m_pos;\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./RectangleSumOfPointCloud.hpp\"\n#include \"\
    ../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nrequires concepts::RSOPCQuery<T,\
    \ U>\nclass PointAddRectangleSum {\npublic:\n    using P = typename T::P;\n  \
    \  using W = typename T::W;\n\n    usize add(const T& P) {\n        usize res{m_ps.size()};\n\
    \        m_pos.emplace_back(false, res);\n        m_ps.push_back(P);\n       \
    \ return res;\n    }\n\n    usize add(T&& P) {\n        usize res{m_ps.size()};\n\
    \        m_pos.emplace_back(false, res);\n        m_ps.push_back(std::move(P));\n\
    \        return res;\n    }\n\n    usize product(const U& Q) {\n        usize\
    \ res{m_qs.size()};\n        m_pos.emplace_back(true, res);\n        m_qs.push_back(Q);\n\
    \        return res;\n    }\n\n    usize product(U&& Q) {\n        usize res{m_qs.size()};\n\
    \        m_pos.emplace_back(true, res);\n        m_qs.push_back(std::move(Q));\n\
    \        return res;\n    }\n\n    std::vector<W> execute() const {\n        std::vector<W>\
    \ res(m_qs.size());\n\n        auto rec{[&](auto rec, usize l, usize r) -> void\
    \ {\n            assert(l <= r);\n            if (l + 1 >= r) return;\n      \
    \      if (r - l > THRESHOLD) {\n                usize m{(l + r) >> 1};\n    \
    \            rec(rec, l, m);\n                rec(rec, m, r);\n              \
    \  std::vector<usize> p, q;\n                for (usize i{l} ; i < m ; i++) if\
    \ (!m_pos[i].first) {\n                    p.push_back(m_pos[i].second);\n   \
    \             }\n                for (usize i{m} ; i < r ; i++) if (m_pos[i].first)\
    \ {\n                    q.push_back(m_pos[i].second);\n                }\n  \
    \              if (p.empty() or q.empty()) return;\n                std::vector<W>\
    \ kiyo{RectangleSumOfPointCloud<T, U>(\n                        std::vector<T>(m_ps.begin()\
    \ + p.front(), m_ps.begin() + p.back() + 1),\n                        std::vector<U>(m_qs.begin()\
    \ + q.front(), m_qs.begin() + q.back() + 1)\n                        )};\n   \
    \             for (usize i{} ; i < q.size() ; i++) {\n                    res[q[i]]\
    \ += kiyo[i];\n                }\n            }\n            else {\n        \
    \        for (usize i{l} ; i < r ; i++) if (m_pos[i].first) {\n              \
    \      const U& u{m_qs[m_pos[i].second]};\n                    for (usize j{l}\
    \ ; j < i ; j++) if (!m_pos[j].first) {\n                        const T& t{m_ps[m_pos[j].second]};\n\
    \                        if (u.l <= t.x and t.x < u.r and u.d <= t.y and t.y <\
    \ u.u) {\n                            res[m_pos[i].second] += t.w;\n         \
    \               }\n                    }\n                }\n            }\n \
    \       }};\n\n        rec(rec, usize{0}, m_pos.size());\n        return res;\n\
    \    }\n\nprivate:\n\n    static constexpr usize THRESHOLD{200};\n\n    std::vector<T>\
    \ m_ps;\n    std::vector<U> m_qs;\n    std::vector<std::pair<bool, usize>> m_pos;\n\
    };\n\n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2025-04-25 15:47:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/point_add_rectangle_sum/PointAddRectangleSum.test.cpp
documentation_of: Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp
layout: document
title: Point Add Rectangle Sum
---

## 概要

以下のようなクエリを処理する

1. 二次元平面上に重み付きの点を追加する
2. 矩形領域が与えられる。矩形領域の中にある点の重みの総和を求める

ただし、オフライン処理である。すなわち全てのクエリは処理前に与えられている必要がある。

## ライブラリの使い方

```cpp
template <class T, class U>
requires concepts::RSOPCQuery
PointAddRectangleSum()
```

#### T

点の型

`T`は基本的には以下をコピれば問題無いはず。

- `P`が点の座標の型で、`W`が重みの型を表す

```cpp
struct Point {
    using P = int; 
    using W = long long;
    P x, y;
    W w;
};
```

`P`は**符号付き整数**であることが期待される。

P型のメンバ変数`x, y`とW型のメンバ変数`w`が必要。

## U

矩形領域型

基本的には以下をコピれば問題無い。`P`が座標の型を表す。

```cpp
// [l, r)x[d, u)
struct Rect {
    using P = int;
    int l, d, r, u;
};
```

`P`は座標の型、psの`P`と型が一致している必要がある。

メンバ変数`l`, `d`, `r`, `u`が必要。左下の点が $(l, d)$ 、右上の点が $(r, u)$ となるようにする。

## アルゴリズム

クエリ分割統治する。 $l$ 番目から $r - 1$ 番目のクエリを処理することを考える。 $m = \lfloor \frac{l+r}{2}\rfloor$ とする。

分割統治を考えているわけだから、結局の所 $m$ 番目から $r - 1$ 番目のクエリに含まれる求値に対する $l$ 番目から $m - 1$ 番目のクエリに含まれる点の寄与を計算できれば良い。

これは[Static Point Add Rectangle Sum](https://zawa-tin.github.io/cp-documentation/Src/DataStructure/RectangleSum/StaticPointAddRectangleSum.hpp)そのものである。

Static verはlog1つでできて、各クエリは高々 $\Theta (\log Q)$ 計算されるので、log2つ。

実装上は $r - l$ がある程度小さかったら再帰を打ち切って愚直を回している。この工夫でほんのちょっと早くなった。

アルゴリズム・実装共に [ei1333の日記](https://ei1333.hateblo.jp/entry/2022/06/10/022355) を参考にした。
