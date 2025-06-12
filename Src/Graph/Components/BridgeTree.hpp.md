---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ <concepts>\n#include <vector>\n#include <unordered_map>\n\nnamespace zawa {\n\
    \ntemplate <std::integral T>\nclass BridgeTree {\npublic:\n\n    using V = usize;\n\
    \n    BridgeTree() = default;\n\n    explicit BridgeTree(const std::vector<std::vector<T>>&\
    \ g) : m_id(g.size()) {\n        const usize n = g.size();\n        std::vector<usize>\
    \ low(n), ord(n);\n        std::vector<T> vs;\n        std::vector<std::pair<T,\
    \ T>> bridge;\n        usize time = 1, id = 0;\n        auto dfs = [&](auto dfs,\
    \ T v, T p) -> void {\n            low[v] = ord[v] = time++;\n            std::unordered_map<T,\
    \ usize> cnt;\n            for (T x : g[v]) cnt[x]++;\n            for (auto [x,\
    \ c] : cnt) if (x != p) {\n                if (ord[x]) {\n                   \
    \ low[v] = std::min(low[v], ord[x]);\n                }\n                else\
    \ {\n                    dfs(dfs, x, v);\n                    low[v] = std::min(low[v],\
    \ low[x]);\n                    if (c == 1u and ord[v] < low[x]) {\n         \
    \               std::vector<T> cur; \n                        while (vs.size()\
    \ and low[x] <= low[vs.back()]) {\n                            cur.push_back(vs.back());\n\
    \                            m_id[vs.back()] = m_comp.size();\n              \
    \              vs.pop_back();\n                        }\n                   \
    \     bridge.emplace_back(x, v);\n                        m_comp.push_back(std::move(cur));\n\
    \                    }\n                }\n            }\n            vs.push_back(v);\n\
    \        };\n        for (usize v = 0 ; v < n ; v++) if (!ord[v]) {\n        \
    \    dfs(dfs, v, static_cast<T>(-1));\n            if (vs.size()) {\n        \
    \        std::vector<T> cur;\n                while (vs.size()) {\n          \
    \          m_id[vs.back()] = m_comp.size();\n                    cur.push_back(vs.back());\n\
    \                    vs.pop_back();\n                }\n                m_comp.push_back(std::move(cur));\n\
    \            }\n        }\n        m_g.resize(m_comp.size());\n        for (auto\
    \ [u, v] : bridge) {\n            const V p = m_id[u], q = m_id[v];\n        \
    \    m_g[p].push_back(q);\n            m_g[q].push_back(p);\n        }\n    }\n\
    \n    inline usize size() const noexcept {\n        return m_g.size();\n    }\n\
    \n    const std::vector<V>& operator[](V v) const {\n        assert(v < size());\n\
    \        return m_g[v];\n    }\n\n    const std::vector<std::vector<T>>& components()\
    \ const {\n        return m_comp;\n    }\n\n    const std::vector<T>& component(V\
    \ v) const {\n        assert(v < size());\n        return m_comp[v];\n    }\n\n\
    private:\n\n    std::vector<V> m_id;\n\n    std::vector<std::vector<T>> m_comp;\n\
    \n    std::vector<std::vector<V>> m_g;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n#include <unordered_map>\n\nnamespace zawa {\n\ntemplate <std::integral\
    \ T>\nclass BridgeTree {\npublic:\n\n    using V = usize;\n\n    BridgeTree()\
    \ = default;\n\n    explicit BridgeTree(const std::vector<std::vector<T>>& g)\
    \ : m_id(g.size()) {\n        const usize n = g.size();\n        std::vector<usize>\
    \ low(n), ord(n);\n        std::vector<T> vs;\n        std::vector<std::pair<T,\
    \ T>> bridge;\n        usize time = 1, id = 0;\n        auto dfs = [&](auto dfs,\
    \ T v, T p) -> void {\n            low[v] = ord[v] = time++;\n            std::unordered_map<T,\
    \ usize> cnt;\n            for (T x : g[v]) cnt[x]++;\n            for (auto [x,\
    \ c] : cnt) if (x != p) {\n                if (ord[x]) {\n                   \
    \ low[v] = std::min(low[v], ord[x]);\n                }\n                else\
    \ {\n                    dfs(dfs, x, v);\n                    low[v] = std::min(low[v],\
    \ low[x]);\n                    if (c == 1u and ord[v] < low[x]) {\n         \
    \               std::vector<T> cur; \n                        while (vs.size()\
    \ and low[x] <= low[vs.back()]) {\n                            cur.push_back(vs.back());\n\
    \                            m_id[vs.back()] = m_comp.size();\n              \
    \              vs.pop_back();\n                        }\n                   \
    \     bridge.emplace_back(x, v);\n                        m_comp.push_back(std::move(cur));\n\
    \                    }\n                }\n            }\n            vs.push_back(v);\n\
    \        };\n        for (usize v = 0 ; v < n ; v++) if (!ord[v]) {\n        \
    \    dfs(dfs, v, static_cast<T>(-1));\n            if (vs.size()) {\n        \
    \        std::vector<T> cur;\n                while (vs.size()) {\n          \
    \          m_id[vs.back()] = m_comp.size();\n                    cur.push_back(vs.back());\n\
    \                    vs.pop_back();\n                }\n                m_comp.push_back(std::move(cur));\n\
    \            }\n        }\n        m_g.resize(m_comp.size());\n        for (auto\
    \ [u, v] : bridge) {\n            const V p = m_id[u], q = m_id[v];\n        \
    \    m_g[p].push_back(q);\n            m_g[q].push_back(p);\n        }\n    }\n\
    \n    inline usize size() const noexcept {\n        return m_g.size();\n    }\n\
    \n    const std::vector<V>& operator[](V v) const {\n        assert(v < size());\n\
    \        return m_g[v];\n    }\n\n    const std::vector<std::vector<T>>& components()\
    \ const {\n        return m_comp;\n    }\n\n    const std::vector<T>& component(V\
    \ v) const {\n        assert(v < size());\n        return m_comp[v];\n    }\n\n\
    private:\n\n    std::vector<V> m_id;\n\n    std::vector<std::vector<T>> m_comp;\n\
    \n    std::vector<std::vector<V>> m_g;\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Components/BridgeTree.hpp
  requiredBy: []
  timestamp: '2025-06-12 16:53:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/two_edge_connected_components.test.cpp
documentation_of: Src/Graph/Components/BridgeTree.hpp
layout: document
title: "Bridge tree (+ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3)"
---

## 概要

二辺連結成分をまとめて一頂点にし、グラフを縮約します。このグラフは木であり、各辺は元のグラフでは橋です。

## ライブラリ

### constructor

```cpp
BridgeTree() = default;
explicit BridgeTree(const std::vector<std::vector<T>>& g)
```

無向グラフの隣接リストを与える。`T`は`std::integral<T>`が`true`である必要がある。

### size

```cpp
inline usize size() const noexcept
```

縮約後の頂点数を返す

### operator[]

```
const std::vector<V>& operator[](V v) const;
```

縮約後の頂点 $v$ の隣接する頂点の列を返す。ここで、`V = usize`である。

### component

```
const std::vector<T>& component(V v) const
```

縮約後の頂点 $v$ に対応している元のグラフの頂点の列を返す。

### components

```
const std::vector<std::vector<T>>& components() const
```

`component`の列である。すなわち二重辺連結成分分解した列を返す。

## メモ

内部で`unordered_map`を使って多重辺を処理しているので、ちょっとオーバヘッドがやばそう？

LCでは133msで普通に良さそうだったけど。
