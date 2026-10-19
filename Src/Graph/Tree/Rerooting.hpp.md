---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/1595.test.cpp
    title: Test/AOJ/1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc298_h.test.cpp
    title: Test/AtCoder/abc298_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc179_d.test.cpp
    title: Test/AtCoder/arc179_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/tree_path_composite_sum.test.cpp
    title: Test/LC/tree_path_composite_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/Rerooting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Rerooting.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T>\nconcept TreeDP = requires {\n    typename T::Tree;\n\
    \    typename T::Cluster;\n    typename T::Edge;\n    typename T::Vertex;\n  \
    \  { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::Tree>;\n    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::Cluster>;\n    { T::Merge(std::declval<typename\
    \ T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename\
    \ T::Cluster>;\n    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename\
    \ T::Vertex>()) } -> std::same_as<typename T::Tree>;\n};\n\n}\n\ntemplate <concepts::TreeDP\
    \ DP,std::integral T>\nclass Rerooting {\npublic:\n\n    using Tree = DP::Tree;\n\
    \n    using Cluster = DP::Cluster;\n\n    using Edge = DP::Edge;\n\n    using\
    \ Vertex = DP::Vertex;\n\n    Rerooting(usize n,std::vector<std::pair<T,T>> ed,std::vector<Vertex>\
    \ vs,std::vector<Edge> es) \n    : m_n{n}, m_edges{std::move(ed)}, m_alls(n),\
    \ m_sides(m_edges.size()) {\n        assert(m_edges.size()+1==n); \n        assert(m_edges.size()==es.size());\n\
    \        assert(n==vs.size());\n        if (n==1) {\n            m_alls[0]=DP::Convert(vs[0]);\n\
    \            return;\n        }\n        std::vector<std::vector<std::pair<T,u32>>>\
    \ g(n);\n        for (usize i = 0 ; auto [u,v] : m_edges) {\n            g[u].push_back({v,i});\n\
    \            g[v].push_back({u,i});\n            i++;\n        }\n        std::vector<Tree>\
    \ dp(n);\n        auto dfs1=[&](auto dfs,T v,T p) -> Tree {\n            if (std::ssize(g[v])==1\
    \ and g[v][0].first==p)\n                return dp[v]=DP::Convert(vs[v]);\n  \
    \          usize idx=g[v][0].first==p?1:0;\n            assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);\n\
    \            Cluster prod=DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]);\n\
    \            for (idx++ ; idx<g[v].size() ; idx++) \n                if (g[v][idx].first!=p)\
    \ {\n                    assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);\n\
    \                    prod=DP::Merge(prod,DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]));\n\
    \                }\n            return dp[v]=DP::AddVertex(std::move(prod),vs[v]);\n\
    \        };\n        dfs1(dfs1,0,static_cast<T>(0));\n        auto dfs2=[&](auto\
    \ dfs,T v,T p,Tree t) -> void {\n            const usize k=g[v].size();\n    \
    \        std::vector<Cluster> clusters(k);\n            for (usize i = 0 ; i <\
    \ k ; i++) {\n                if (g[v][i].first==p) {\n                    assignToSides(t,g[v][i].second,p);\n\
    \                    clusters[i]=DP::AddEdge(t,es[g[v][i].second]);\n        \
    \        }\n                else\n                    clusters[i]=DP::AddEdge(dp[g[v][i].first],es[g[v][i].second]);\n\
    \            }\n            if (k==1) {\n                m_alls[v]=DP::AddVertex(clusters[0],vs[v]);\n\
    \                if (g[v][0].first!=p) {\n                    assert(!v);\n  \
    \                  dfs(dfs,g[v][0].first,v,DP::Convert(vs[v]));\n            \
    \    }\n            }\n            else {\n                std::vector<Cluster>\
    \ pref=clusters,suf=clusters;\n                for (usize i = 1 ; i < k ; i++)\
    \ {\n                    pref[i]=DP::Merge(pref[i-1],clusters[i]);\n         \
    \           suf[k-i-1]=DP::Merge(clusters[k-i-1],suf[k-i]);\n                }\n\
    \                m_alls[v]=DP::AddVertex(pref[k-1],vs[v]);\n                for\
    \ (usize i = 0 ; i < g[v].size() ; i++) \n                    if (g[v][i].first!=p)\
    \ {\n                        Cluster pc=i?(i+1<g[v].size()?DP::Merge(pref[i-1],suf[i+1]):pref[k-2]):suf[1];\n\
    \                        dfs(dfs,g[v][i].first,v,DP::AddVertex(pc,vs[v]));\n \
    \                   }\n            }\n        };\n        dfs2(dfs2,0,static_cast<T>(0),Tree{});\n\
    \    }\n\n    inline usize size() const noexcept {\n        return m_n;\n    }\n\
    \n    const Tree& operator[](usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_alls[i];\n    }\n\n    const Tree& side(usize i,T v) const {\n\
    \        assert(i < m_sides.size()); \n        if (m_edges[i].first==v)\n    \
    \        return m_sides[i].first;\n        else if (m_edges[i].second==v)\n  \
    \          return m_sides[i].second;\n        assert(0);\n        return m_sides[i].first;\n\
    \    }\n\nprivate:\n\n    void assignToSides(Tree t,usize idx,T v) {\n       \
    \ if (m_edges[idx].first==v)\n            m_sides[idx].first=std::move(t);\n \
    \       else\n            m_sides[idx].second=std::move(t);\n    }\n\n    usize\
    \ m_n;\n\n    std::vector<std::pair<T,T>> m_edges;\n\n    std::vector<Tree> m_alls;\n\
    \n    std::vector<std::pair<Tree,Tree>> m_sides;\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T>\nconcept TreeDP = requires {\n    typename T::Tree;\n\
    \    typename T::Cluster;\n    typename T::Edge;\n    typename T::Vertex;\n  \
    \  { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::Tree>;\n    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::Cluster>;\n    { T::Merge(std::declval<typename\
    \ T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename\
    \ T::Cluster>;\n    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename\
    \ T::Vertex>()) } -> std::same_as<typename T::Tree>;\n};\n\n}\n\ntemplate <concepts::TreeDP\
    \ DP,std::integral T>\nclass Rerooting {\npublic:\n\n    using Tree = DP::Tree;\n\
    \n    using Cluster = DP::Cluster;\n\n    using Edge = DP::Edge;\n\n    using\
    \ Vertex = DP::Vertex;\n\n    Rerooting(usize n,std::vector<std::pair<T,T>> ed,std::vector<Vertex>\
    \ vs,std::vector<Edge> es) \n    : m_n{n}, m_edges{std::move(ed)}, m_alls(n),\
    \ m_sides(m_edges.size()) {\n        assert(m_edges.size()+1==n); \n        assert(m_edges.size()==es.size());\n\
    \        assert(n==vs.size());\n        if (n==1) {\n            m_alls[0]=DP::Convert(vs[0]);\n\
    \            return;\n        }\n        std::vector<std::vector<std::pair<T,u32>>>\
    \ g(n);\n        for (usize i = 0 ; auto [u,v] : m_edges) {\n            g[u].push_back({v,i});\n\
    \            g[v].push_back({u,i});\n            i++;\n        }\n        std::vector<Tree>\
    \ dp(n);\n        auto dfs1=[&](auto dfs,T v,T p) -> Tree {\n            if (std::ssize(g[v])==1\
    \ and g[v][0].first==p)\n                return dp[v]=DP::Convert(vs[v]);\n  \
    \          usize idx=g[v][0].first==p?1:0;\n            assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);\n\
    \            Cluster prod=DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]);\n\
    \            for (idx++ ; idx<g[v].size() ; idx++) \n                if (g[v][idx].first!=p)\
    \ {\n                    assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);\n\
    \                    prod=DP::Merge(prod,DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]));\n\
    \                }\n            return dp[v]=DP::AddVertex(std::move(prod),vs[v]);\n\
    \        };\n        dfs1(dfs1,0,static_cast<T>(0));\n        auto dfs2=[&](auto\
    \ dfs,T v,T p,Tree t) -> void {\n            const usize k=g[v].size();\n    \
    \        std::vector<Cluster> clusters(k);\n            for (usize i = 0 ; i <\
    \ k ; i++) {\n                if (g[v][i].first==p) {\n                    assignToSides(t,g[v][i].second,p);\n\
    \                    clusters[i]=DP::AddEdge(t,es[g[v][i].second]);\n        \
    \        }\n                else\n                    clusters[i]=DP::AddEdge(dp[g[v][i].first],es[g[v][i].second]);\n\
    \            }\n            if (k==1) {\n                m_alls[v]=DP::AddVertex(clusters[0],vs[v]);\n\
    \                if (g[v][0].first!=p) {\n                    assert(!v);\n  \
    \                  dfs(dfs,g[v][0].first,v,DP::Convert(vs[v]));\n            \
    \    }\n            }\n            else {\n                std::vector<Cluster>\
    \ pref=clusters,suf=clusters;\n                for (usize i = 1 ; i < k ; i++)\
    \ {\n                    pref[i]=DP::Merge(pref[i-1],clusters[i]);\n         \
    \           suf[k-i-1]=DP::Merge(clusters[k-i-1],suf[k-i]);\n                }\n\
    \                m_alls[v]=DP::AddVertex(pref[k-1],vs[v]);\n                for\
    \ (usize i = 0 ; i < g[v].size() ; i++) \n                    if (g[v][i].first!=p)\
    \ {\n                        Cluster pc=i?(i+1<g[v].size()?DP::Merge(pref[i-1],suf[i+1]):pref[k-2]):suf[1];\n\
    \                        dfs(dfs,g[v][i].first,v,DP::AddVertex(pc,vs[v]));\n \
    \                   }\n            }\n        };\n        dfs2(dfs2,0,static_cast<T>(0),Tree{});\n\
    \    }\n\n    inline usize size() const noexcept {\n        return m_n;\n    }\n\
    \n    const Tree& operator[](usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_alls[i];\n    }\n\n    const Tree& side(usize i,T v) const {\n\
    \        assert(i < m_sides.size()); \n        if (m_edges[i].first==v)\n    \
    \        return m_sides[i].first;\n        else if (m_edges[i].second==v)\n  \
    \          return m_sides[i].second;\n        assert(0);\n        return m_sides[i].first;\n\
    \    }\n\nprivate:\n\n    void assignToSides(Tree t,usize idx,T v) {\n       \
    \ if (m_edges[idx].first==v)\n            m_sides[idx].first=std::move(t);\n \
    \       else\n            m_sides[idx].second=std::move(t);\n    }\n\n    usize\
    \ m_n;\n\n    std::vector<std::pair<T,T>> m_edges;\n\n    std::vector<Tree> m_alls;\n\
    \n    std::vector<std::pair<Tree,Tree>> m_sides;\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2026-10-19 00:51:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/1595.test.cpp
  - Test/AtCoder/arc179_d.test.cpp
  - Test/AtCoder/abc298_h.test.cpp
  - Test/LC/tree_path_composite_sum.test.cpp
documentation_of: Src/Graph/Tree/Rerooting.hpp
layout: document
title: "\u6728DP/\u5168\u65B9\u4F4D\u6728DP"
---

## 概要

全方位木dp。 [ABC351-G 公式解説](https://atcoder.jp/contests/abc351/editorial/9868) の内容を参考に抽象化されたもの。

## テンプレートの雛形

```cpp
struct DP {
    using Tree = ;
    using Cluster = ;
    using Edge = ;
    using Vertex = ;
    static Tree Convert(Vertex) {
    }
    static Cluster AddEdge(Tree,Edge) {
    }
    static Cluster Merge(Cluster,Cluster) {
    }
    static Tree AddVertex(Cluster,Vertex) {
    }
};
```

![image](https://github.com/zawa-tin/cp-documentation/blob/main/Docs/Graph/Tree/Tree.jpg?raw=true)

上記の各staticメンバが木dpとどう対応しているのかというと...

```cpp
if (v is leaf)
    return Convert(v);
Cluster prod=Cluster::identity();
for (auto [x,e] : G[v])
    if (x != p)
        prod=Merge(prod,AddEdge(dp[x],e));
return AddVertex(prod,v);
```

といった塩梅である。なお、説明のために`Cluster::identity()`を用いたが、本ライブラリでは要求されない。

`DP`に対する詳細な要求は以下の通りである

- `Merge`は結合律を要求する。現在は辺のリストを順番に走査することで得られる隣接リストの前から順番にマージしていく設計となっている
- `Tree`及び`Cluster`にはデフォルト構築・コピー構築・コピー代入ができることが必要である。なお、デフォルト構築は単位元を返す必要はない。


## ライブラリの使い方

コンストラクタで全方位木DPが実行される。

```cpp
template <concepts::TreeDP DP,std::integral T>
Rerooting(usize n,std::vector<std::pair<T,T>> ed,std::vector<Vertex> vs,std::vector<Edge> es)
```

`DP`及び`T`は`Rerooting`のテンプレート引数である。

- `DP`は上記の雛形を適切に埋めたクラスであればよい。
- `T`は頂点番号の型。基本的に`int`、`unsigned`、`usize`のいずれかであることが推奨される。

$n$ は頂点数。 $n$ が $0$ のときはassertにひっかかる

`ed`は辺のリスト。頂点番号が $0,1,\dots,n-1$ であることを仮定している。辺数が $n-1$ でないときはassertにひっかかる。当然だが、`ed`は木の辺集合であることを要求する。

`vs`は頂点の情報を格納した要素数 $n$ の`vector`であり、`vs[v]`は頂点 $v$ の情報である必要がある。

`es`は辺の情報を格納した要素数 $n-1$ の`vector`であり、`es[i]` は`ed[i]`の情報である必要がある。

```
inline usize size() const noexcept
```

頂点数 $n$ を`usize`で返す。

```
const Tree& operator[](usize i) const noexcept
```

で頂点 $i$ を根としてfoldしたときの`Tree`を得ることができる。

```
const Tree& side(usize i,T v) const
```

で $i$ 番目の辺でぶったぎって得られる二つの木に関して、頂点 $v$ 側の木の $v$ を根としたfoldを`Tree`として返す。なお、 $i$ 番目の辺の端点の一方が $v$ である必要がある。そうでない場合はassertにひっかかる。

## 計算量

`DP`の各種演算、コピーが $O(1)$ であると仮定すると、構築 $O(n)$ 、取得 $O(1)$ 、空間 $O(n)$ メモリとなっている。

## 更新履歴

- 2025/12/01: 作成
- 2026/10/19: 木DPは使わないため削除。`Rerooting`をクラスにし、`side`メンバを追加した。
