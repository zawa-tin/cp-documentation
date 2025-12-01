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
    #include <cassert>\n#include <concepts>\n#include <limits>\n\nnamespace zawa {\n\
    \nnamespace concepts {\n\ntemplate <class T>\nconcept TreeDP = requires {\n  \
    \  typename T::Tree;\n    typename T::Cluster;\n    typename T::Edge;\n    typename\
    \ T::Vertex;\n    { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::Tree>;\n    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::Cluster>;\n    { T::Merge(std::declval<typename\
    \ T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename\
    \ T::Cluster>;\n    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename\
    \ T::Vertex>()) } -> std::same_as<typename T::Tree>;\n};\n\n}\n\ntemplate <concepts::TreeDP\
    \ T>\nusing TreeDPGraph = std::vector<std::vector<std::pair<usize, typename T::Edge>>>;\n\
    \ntemplate <concepts::TreeDP T>\nstd::vector<typename T::Tree> TreeDP(const TreeDPGraph<T>&\
    \ g, const std::vector<typename T::Vertex>& vs, usize root) {\n    using Tree\
    \ = typename T::Tree;\n    using Cluster = typename T::Cluster;\n    // using\
    \ Edge = typename T::Edge;\n    // using Vertex = typename T::Vertex;\n    assert(g.size()\
    \ == vs.size());\n    const usize n = g.size();\n    std::vector<Tree> res(n);\n\
    \    auto rec = [&](auto rec, usize v, usize p) -> Tree {\n        if (ssize(g[v])\
    \ == 1 and g[v][0].first == p)\n            return res[v] = T::Convert(vs[v]);\n\
    \        usize idx = g[v][0].first == p ? 1 : 0;\n        assert(idx < g[v].size());\n\
    \        Cluster cluster = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);\n\
    \        idx++;\n        for ( ; idx < g[v].size() ; idx++) {\n            Cluster\
    \ cur = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);\n        \
    \    cluster = T::Merge(cluster, cur);\n        }\n        return res[v] = T::AddVertex(cluster,\
    \ vs[v]);\n    };\n    rec(rec, root, g.size());\n    return res;\n}\n\ntemplate\
    \ <concepts::TreeDP T>\nstd::vector<typename T::Tree> Rerooting(const TreeDPGraph<T>&\
    \ g, const std::vector<typename T::Vertex>& vs) {\n    using Tree = typename T::Tree;\n\
    \    using Cluster = typename T::Cluster;\n    // using Edge = typename T::Edge;\n\
    \    // using Vertex = typename T::Vertex;\n    assert(g.size() == vs.size());\n\
    \    const usize n = g.size();\n    if (n <= 2) {\n        std::vector<Tree> res(n);\n\
    \        for (usize i = 0 ; i < n ; i++)\n            res[i] = TreeDP<T>(g, vs,\
    \ i)[i];\n        return res;\n    }\n    std::vector<Cluster> dp(n);\n    auto\
    \ rec1 = [&](auto rec, usize v, usize p) -> Tree {\n        if (ssize(g[v]) ==\
    \ 1 and g[v][0].first == p)\n            return T::Convert(vs[v]);\n        usize\
    \ idx = g[v][0].first == p ? 1 : 0;\n        assert(idx < g[v].size());\n    \
    \    dp[v] = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);\n   \
    \     idx++;\n        for ( ; idx < g[v].size() ; idx++)\n            if (g[v][idx].first\
    \ != p) {\n                Cluster cur = T::AddEdge(rec(rec, g[v][idx].first,\
    \ v), g[v][idx].second);\n                dp[v] = T::Merge(dp[v], cur);\n    \
    \        }\n        return T::AddVertex(dp[v], vs[v]);\n    };\n    usize root\
    \ = 0;\n    while (root < g.size() and g[root].size() <= 1)\n        root++;\n\
    \    assert(root < g.size());\n    std::vector<Tree> res(n);\n    res[root] =\
    \ rec1(rec1, root, g.size());\n    auto rec2 = [&](auto rec, usize v, usize p,\
    \ Cluster pv) -> void {\n        if (ssize(g[v]) == 1) {\n            assert(g[v][0].first\
    \ == p);\n            res[v] = T::AddVertex(pv, vs[v]);\n            return;\n\
    \        }\n        assert(ssize(g[v]) >= 2);\n        std::vector<Cluster> pref(g[v].size()),\
    \ suf(g[v].size());\n        pref[0] = g[v][0].first == p ? pv : T::AddEdge(dp[g[v][0].first],\
    \ g[v][0].second);\n        for (usize i = 1 ; i < g[v].size() ; i++) {\n    \
    \        Cluster cur = g[v][i].first == p ? pv : T::AddEdge(dp[g[v][i].first],\
    \ g[v][i].second);\n            pref[i] = T::Merge(pref[i - 1], cur);\n      \
    \  }\n        suf[g[v].size() - 1] = g[v].back().first == p ? pv : T::AddEdge(dp[g[v].back().first],\
    \ g[v].back().second);\n        for (usize i = g[v].size() - 1 ; i-- ; ) {\n \
    \           Cluster cur = g[v][i].first == p ? pv : T::AddEdge(dp[g[v][i].first],\
    \ g[v][i].second);\n            suf[i] = T::Merge(cur, suf[i + 1]);\n        }\n\
    \        res[v] = T::AddVertex(pref.back(), vs[v]);\n        for (usize i = 0\
    \ ; i < g[v].size() ; i++)\n            if (g[v][i].first != p) {\n          \
    \      Cluster pc = i == 0 ? suf[1] : (i + 1 == g[v].size() ? pref[i - 1] : T::Merge(pref[i\
    \ - 1], suf[i + 1]));\n                rec(rec, g[v][i].first, v, T::AddEdge(T::AddVertex(pc,\
    \ vs[v]), g[v][i].second));\n            }\n    };\n    rec2(rec2, root, g.size(),\
    \ Cluster{});\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <concepts>\n#include <limits>\n\nnamespace zawa {\n\
    \nnamespace concepts {\n\ntemplate <class T>\nconcept TreeDP = requires {\n  \
    \  typename T::Tree;\n    typename T::Cluster;\n    typename T::Edge;\n    typename\
    \ T::Vertex;\n    { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::Tree>;\n    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::Cluster>;\n    { T::Merge(std::declval<typename\
    \ T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename\
    \ T::Cluster>;\n    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename\
    \ T::Vertex>()) } -> std::same_as<typename T::Tree>;\n};\n\n}\n\ntemplate <concepts::TreeDP\
    \ T>\nusing TreeDPGraph = std::vector<std::vector<std::pair<usize, typename T::Edge>>>;\n\
    \ntemplate <concepts::TreeDP T>\nstd::vector<typename T::Tree> TreeDP(const TreeDPGraph<T>&\
    \ g, const std::vector<typename T::Vertex>& vs, usize root) {\n    using Tree\
    \ = typename T::Tree;\n    using Cluster = typename T::Cluster;\n    // using\
    \ Edge = typename T::Edge;\n    // using Vertex = typename T::Vertex;\n    assert(g.size()\
    \ == vs.size());\n    const usize n = g.size();\n    std::vector<Tree> res(n);\n\
    \    auto rec = [&](auto rec, usize v, usize p) -> Tree {\n        if (ssize(g[v])\
    \ == 1 and g[v][0].first == p)\n            return res[v] = T::Convert(vs[v]);\n\
    \        usize idx = g[v][0].first == p ? 1 : 0;\n        assert(idx < g[v].size());\n\
    \        Cluster cluster = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);\n\
    \        idx++;\n        for ( ; idx < g[v].size() ; idx++) {\n            Cluster\
    \ cur = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);\n        \
    \    cluster = T::Merge(cluster, cur);\n        }\n        return res[v] = T::AddVertex(cluster,\
    \ vs[v]);\n    };\n    rec(rec, root, g.size());\n    return res;\n}\n\ntemplate\
    \ <concepts::TreeDP T>\nstd::vector<typename T::Tree> Rerooting(const TreeDPGraph<T>&\
    \ g, const std::vector<typename T::Vertex>& vs) {\n    using Tree = typename T::Tree;\n\
    \    using Cluster = typename T::Cluster;\n    // using Edge = typename T::Edge;\n\
    \    // using Vertex = typename T::Vertex;\n    assert(g.size() == vs.size());\n\
    \    const usize n = g.size();\n    if (n <= 2) {\n        std::vector<Tree> res(n);\n\
    \        for (usize i = 0 ; i < n ; i++)\n            res[i] = TreeDP<T>(g, vs,\
    \ i)[i];\n        return res;\n    }\n    std::vector<Cluster> dp(n);\n    auto\
    \ rec1 = [&](auto rec, usize v, usize p) -> Tree {\n        if (ssize(g[v]) ==\
    \ 1 and g[v][0].first == p)\n            return T::Convert(vs[v]);\n        usize\
    \ idx = g[v][0].first == p ? 1 : 0;\n        assert(idx < g[v].size());\n    \
    \    dp[v] = T::AddEdge(rec(rec, g[v][idx].first, v), g[v][idx].second);\n   \
    \     idx++;\n        for ( ; idx < g[v].size() ; idx++)\n            if (g[v][idx].first\
    \ != p) {\n                Cluster cur = T::AddEdge(rec(rec, g[v][idx].first,\
    \ v), g[v][idx].second);\n                dp[v] = T::Merge(dp[v], cur);\n    \
    \        }\n        return T::AddVertex(dp[v], vs[v]);\n    };\n    usize root\
    \ = 0;\n    while (root < g.size() and g[root].size() <= 1)\n        root++;\n\
    \    assert(root < g.size());\n    std::vector<Tree> res(n);\n    res[root] =\
    \ rec1(rec1, root, g.size());\n    auto rec2 = [&](auto rec, usize v, usize p,\
    \ Cluster pv) -> void {\n        if (ssize(g[v]) == 1) {\n            assert(g[v][0].first\
    \ == p);\n            res[v] = T::AddVertex(pv, vs[v]);\n            return;\n\
    \        }\n        assert(ssize(g[v]) >= 2);\n        std::vector<Cluster> pref(g[v].size()),\
    \ suf(g[v].size());\n        pref[0] = g[v][0].first == p ? pv : T::AddEdge(dp[g[v][0].first],\
    \ g[v][0].second);\n        for (usize i = 1 ; i < g[v].size() ; i++) {\n    \
    \        Cluster cur = g[v][i].first == p ? pv : T::AddEdge(dp[g[v][i].first],\
    \ g[v][i].second);\n            pref[i] = T::Merge(pref[i - 1], cur);\n      \
    \  }\n        suf[g[v].size() - 1] = g[v].back().first == p ? pv : T::AddEdge(dp[g[v].back().first],\
    \ g[v].back().second);\n        for (usize i = g[v].size() - 1 ; i-- ; ) {\n \
    \           Cluster cur = g[v][i].first == p ? pv : T::AddEdge(dp[g[v][i].first],\
    \ g[v][i].second);\n            suf[i] = T::Merge(cur, suf[i + 1]);\n        }\n\
    \        res[v] = T::AddVertex(pref.back(), vs[v]);\n        for (usize i = 0\
    \ ; i < g[v].size() ; i++)\n            if (g[v][i].first != p) {\n          \
    \      Cluster pc = i == 0 ? suf[1] : (i + 1 == g[v].size() ? pref[i - 1] : T::Merge(pref[i\
    \ - 1], suf[i + 1]));\n                rec(rec, g[v][i].first, v, T::AddEdge(T::AddVertex(pc,\
    \ vs[v]), g[v][i].second));\n            }\n    };\n    rec2(rec2, root, g.size(),\
    \ Cluster{});\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2025-12-01 12:59:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/1595.test.cpp
documentation_of: Src/Graph/Tree/Rerooting.hpp
layout: document
title: "\u6728DP/\u5168\u65B9\u4F4D\u6728DP"
---

## 概要

流石に木DPは自分で書いた方が早いので、用途は主に全方位木dpになると思う。
- 全方位木DPも自分で書いた方がマシかもしれないけど

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

[画像](./Tree.jpg)

木dpでは

```cpp
    for (int x : g[v])
        if (x != p)
            chs.push_back(rec(rec, x));
    dp[v] = prod(chs);
```

みたいにやると思うんですけど、それとこの雛形がどう関係しているのかというと

- Vertex: dpの計算に関する頂点の情報
- Edge: dpの計算に関する辺が持つ情報
- Cluster: prod(chs)のこと。ここでは木の根はvirtualなものと考える
- Tree: prod(chs)に頂点vの情報をマージして、根をvirtualで無いようにしたもの

みたいな感じ。

任意の木dpで全部を毎回使うわけではなくて、例えば最遠点を求める場合はVertexはdpの計算に何もかかわってこない。こういうときは適当にゴミをいれておけばいいと思います。SOLID のI(だっけ?)違反なライブラリだけど、使う側が頑張る形でいきましょう

## ライブラリの使い方

```cpp
template <concepts::TreeDP T>
using TreeDPGraph = std::vector<std::vector<std::pair<usize, typename T::Edge>>>;

template <concepts::TreeDP T>
std::vector<typename T::Tree> TreeDP(const TreeDPGraph<T>& g, const std::vector<typename T::Vertex>& vs, usize root) {
```

上の雛形にあるエイリアスとメンバが全部そろっていると`cocepts::TreeDP`の要求は満たされる。

`g`はいつもの隣接リストで、firstに行先の頂点番号、secondにその辺の情報Edgeを納めます。必ず $u\rightarrow v, v\rightarrow u$ 両方入れること。

`vs`は頂点の情報の列
