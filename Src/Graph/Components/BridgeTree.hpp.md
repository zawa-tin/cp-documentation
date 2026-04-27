---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc039_d.test.cpp
    title: Test/AtCoder/arc039_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1043-F.test.cpp
    title: CF1043(Div. 3)-F Rada and the Chamomile Valley
  - icon: ':heavy_check_mark:'
    path: Test/LC/two_edge_connected_components.test.cpp
    title: Test/LC/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Components/BridgeTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Components/BridgeTree.hpp\"\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <ranges>\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <std::integral T>\nclass BridgeTreeBuilder {\n\n    class\
    \ BridgeTree {\n    public:\n\n        BridgeTree(const std::vector<std::vector<std::pair<T,usize>>>&\
    \ g,const std::vector<std::pair<T,T>>& edge) \n            : m_isBridge(edge.size()),\
    \ m_id(g.size()), m_comps{}, m_g{} {\n            const usize n = g.size();\n\
    \            const usize m = edge.size();\n            std::vector<u32> low(n),ord(n);\n\
    \            std::vector<T> remain;\n            u32 time = 1;\n            auto\
    \ dfs = [&](auto dfs,usize v,usize pe) -> void {\n                ord[v] = low[v]\
    \ = time++;\n                for (auto [x,id] : g[v])\n                    if\
    \ (pe != id) {\n                        if (ord[x]) {\n                      \
    \      low[v] = std::min(low[v],ord[x]);\n                        }\n        \
    \                else {\n                            dfs(dfs,x,id);\n        \
    \                    low[v] = std::min(low[v],low[x]);\n                     \
    \       if (ord[v] < low[x]) {\n                                m_isBridge[id]\
    \ = 1;\n                                std::vector<T> cur;\n                \
    \                const T id = static_cast<T>(m_comps.size());\n              \
    \                  while (remain.size() and ord[v] < low[remain.back()]) {\n \
    \                                   cur.push_back(remain.back());\n          \
    \                          m_id[remain.back()] = id;\n                       \
    \             remain.pop_back();\n                                }\n        \
    \                        m_comps.push_back(std::move(cur));\n                \
    \            }\n                        }\n                    }\n           \
    \     remain.push_back(v);\n            };\n            for (usize i = 0 ; i <\
    \ n ; i++)\n                if (!ord[i]) {\n                    remain.clear();\n\
    \                    dfs(dfs,i,edge.size());\n                    for (T j : remain)\n\
    \                        m_id[j] = static_cast<T>(m_comps.size());\n         \
    \           m_comps.push_back(remain);\n                }\n            m_g.resize(m_comps.size());\n\
    \            for (usize i = 0 ; i < m ; i++) \n                if (m_isBridge[i])\
    \ {\n                    auto [u,v] = edge[i];\n                    m_g[m_id[u]].push_back({m_id[v],i});\n\
    \                    m_g[m_id[v]].push_back({m_id[u],i});\n                }\n\
    \        }\n\n        inline usize size() const {\n            return m_g.size();\n\
    \        }\n\n        T id(T v) const {\n            assert(static_cast<usize>(v)\
    \ < m_id.size());\n            return m_id[v];\n        }\n\n        bool isBridge(usize\
    \ i) const {\n            assert(i < m_isBridge.size());\n            return m_isBridge[i];\n\
    \        }\n\n        const std::vector<T>& component(T i) const {\n         \
    \   assert(static_cast<usize>(i) < size());\n            return m_comps[i];\n\
    \        }\n\n        const std::vector<std::vector<T>>& components() const {\n\
    \            return m_comps;\n        }\n\n        const std::vector<std::pair<T,usize>>&\
    \ operator[](T i) const {\n            assert(static_cast<usize>(i) < size());\n\
    \            return m_g[i];\n        }\n\n    private:\n        \n        std::vector<bool>\
    \ m_isBridge;\n\n        std::vector<T> m_id;\n        \n        std::vector<std::vector<T>>\
    \ m_comps;\n\n        std::vector<std::vector<std::pair<T,usize>>> m_g;\n    };\n\
    \npublic:\n\n    BridgeTreeBuilder() = default;\n\n    explicit BridgeTreeBuilder(usize\
    \ n) : m_n{n}, m_g(n) {}\n\n    inline usize size() const {\n        return m_n;\n\
    \    }\n\n    inline usize edgeSize() const {\n        return m_edge.size();\n\
    \    }\n\n    usize addEdge(T u,T v) {\n        assert(static_cast<usize>(u) <\
    \ size());\n        assert(static_cast<usize>(v) < size());\n        usize res\
    \ = m_edge.size();\n        m_g[u].push_back({v,res});\n        m_g[v].push_back({u,res});\n\
    \        m_edge.push_back({u,v});\n        return res;\n    }\n\n    std::pair<T,T>\
    \ getEdge(usize i) const {\n        assert(i < m_edge.size());\n        return\
    \ m_edge[i];\n    }\n\n    BridgeTree build() const {\n        return BridgeTree{m_g,m_edge};\n\
    \    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<std::vector<std::pair<T,usize>>>\
    \ m_g;\n\n    std::vector<std::pair<T,T>> m_edge;\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <ranges>\n#include <vector>\n\nnamespace zawa {\n\
    \ntemplate <std::integral T>\nclass BridgeTreeBuilder {\n\n    class BridgeTree\
    \ {\n    public:\n\n        BridgeTree(const std::vector<std::vector<std::pair<T,usize>>>&\
    \ g,const std::vector<std::pair<T,T>>& edge) \n            : m_isBridge(edge.size()),\
    \ m_id(g.size()), m_comps{}, m_g{} {\n            const usize n = g.size();\n\
    \            const usize m = edge.size();\n            std::vector<u32> low(n),ord(n);\n\
    \            std::vector<T> remain;\n            u32 time = 1;\n            auto\
    \ dfs = [&](auto dfs,usize v,usize pe) -> void {\n                ord[v] = low[v]\
    \ = time++;\n                for (auto [x,id] : g[v])\n                    if\
    \ (pe != id) {\n                        if (ord[x]) {\n                      \
    \      low[v] = std::min(low[v],ord[x]);\n                        }\n        \
    \                else {\n                            dfs(dfs,x,id);\n        \
    \                    low[v] = std::min(low[v],low[x]);\n                     \
    \       if (ord[v] < low[x]) {\n                                m_isBridge[id]\
    \ = 1;\n                                std::vector<T> cur;\n                \
    \                const T id = static_cast<T>(m_comps.size());\n              \
    \                  while (remain.size() and ord[v] < low[remain.back()]) {\n \
    \                                   cur.push_back(remain.back());\n          \
    \                          m_id[remain.back()] = id;\n                       \
    \             remain.pop_back();\n                                }\n        \
    \                        m_comps.push_back(std::move(cur));\n                \
    \            }\n                        }\n                    }\n           \
    \     remain.push_back(v);\n            };\n            for (usize i = 0 ; i <\
    \ n ; i++)\n                if (!ord[i]) {\n                    remain.clear();\n\
    \                    dfs(dfs,i,edge.size());\n                    for (T j : remain)\n\
    \                        m_id[j] = static_cast<T>(m_comps.size());\n         \
    \           m_comps.push_back(remain);\n                }\n            m_g.resize(m_comps.size());\n\
    \            for (usize i = 0 ; i < m ; i++) \n                if (m_isBridge[i])\
    \ {\n                    auto [u,v] = edge[i];\n                    m_g[m_id[u]].push_back({m_id[v],i});\n\
    \                    m_g[m_id[v]].push_back({m_id[u],i});\n                }\n\
    \        }\n\n        inline usize size() const {\n            return m_g.size();\n\
    \        }\n\n        T id(T v) const {\n            assert(static_cast<usize>(v)\
    \ < m_id.size());\n            return m_id[v];\n        }\n\n        bool isBridge(usize\
    \ i) const {\n            assert(i < m_isBridge.size());\n            return m_isBridge[i];\n\
    \        }\n\n        const std::vector<T>& component(T i) const {\n         \
    \   assert(static_cast<usize>(i) < size());\n            return m_comps[i];\n\
    \        }\n\n        const std::vector<std::vector<T>>& components() const {\n\
    \            return m_comps;\n        }\n\n        const std::vector<std::pair<T,usize>>&\
    \ operator[](T i) const {\n            assert(static_cast<usize>(i) < size());\n\
    \            return m_g[i];\n        }\n\n    private:\n        \n        std::vector<bool>\
    \ m_isBridge;\n\n        std::vector<T> m_id;\n        \n        std::vector<std::vector<T>>\
    \ m_comps;\n\n        std::vector<std::vector<std::pair<T,usize>>> m_g;\n    };\n\
    \npublic:\n\n    BridgeTreeBuilder() = default;\n\n    explicit BridgeTreeBuilder(usize\
    \ n) : m_n{n}, m_g(n) {}\n\n    inline usize size() const {\n        return m_n;\n\
    \    }\n\n    inline usize edgeSize() const {\n        return m_edge.size();\n\
    \    }\n\n    usize addEdge(T u,T v) {\n        assert(static_cast<usize>(u) <\
    \ size());\n        assert(static_cast<usize>(v) < size());\n        usize res\
    \ = m_edge.size();\n        m_g[u].push_back({v,res});\n        m_g[v].push_back({u,res});\n\
    \        m_edge.push_back({u,v});\n        return res;\n    }\n\n    std::pair<T,T>\
    \ getEdge(usize i) const {\n        assert(i < m_edge.size());\n        return\
    \ m_edge[i];\n    }\n\n    BridgeTree build() const {\n        return BridgeTree{m_g,m_edge};\n\
    \    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<std::vector<std::pair<T,usize>>>\
    \ m_g;\n\n    std::vector<std::pair<T,T>> m_edge;\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Components/BridgeTree.hpp
  requiredBy: []
  timestamp: '2026-04-27 14:04:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF1043-F.test.cpp
  - Test/LC/two_edge_connected_components.test.cpp
  - Test/AtCoder/arc039_d.test.cpp
documentation_of: Src/Graph/Components/BridgeTree.hpp
layout: document
title: "Bridge tree (+ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3)"
---

## 概要

二辺連結成分をまとめて一頂点にし、グラフを縮約します。このグラフは木であり、各辺は元のグラフでは橋です。

```cpp
explicit BridgeTreeBuilder<T>(usize n);
```

で $n$ 頂点 $0$ 辺のグラフ (頂点のindexの型が`T`) を作って

```cpp
usize BridgeTreeBuilder<T>::addEdge(T u,T v)
```

で辺を追加して

```cpp
BridgeTreeBuilder<T>::BridgeTree BridgeTreeBuilder<T>::build()
```

でBridge Treeを返す

## 更新履歴

2026/04/20: 書き直した。

2026/04/27: クラス名を変更、`getEdge`を追加。CF1043-Fでverify
