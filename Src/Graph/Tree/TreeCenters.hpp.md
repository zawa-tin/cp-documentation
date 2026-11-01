---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc221_f.test.cpp
    title: Test/AtCoder/abc221_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc482_e.test.cpp
    title: Test/AtCoder/abc482_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1045-D.test.cpp
    title: Test/CF/CF1045-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/tree_diameter.test.cpp
    title: Test/LC/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/TreeCenters.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/TreeCenters.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral\
    \ T,class U>\nclass TreeCenters {\npublic:\n\n    explicit TreeCenters(std::vector<std::vector<std::pair<T,U>>>\
    \ g) \n        : m_g{std::move(g)},m_path{},m_root{} {\n        assert(size()\
    \ and \"TreeCenters: empty graph is not a tree\");\n        auto d0=bfs(0).first;\n\
    \        const T p=std::ranges::max_element(d0)-d0.begin();\n        auto [dp,prev]=bfs(p);\n\
    \        const T q=std::ranges::max_element(dp)-dp.begin();\n        auto dq=bfs(q).first;\n\
    \        for (i32 v = static_cast<i32>(q) ; ; v = prev[v]) {\n            m_path.push_back(v);\n\
    \            if (static_cast<T>(v)==p)\n                break;\n        }\n  \
    \      const auto [u,v]=[&]() -> std::pair<T,T> {\n            for (usize i =\
    \ 0 ; i < m_path.size() ; i++)\n                if (dq[m_path[i]]==dp[m_path[i]])\n\
    \                    return {m_path[i],m_path[i]};\n            for (usize i =\
    \ 0 ; i + 1 < m_path.size() ; i++) {\n                T u=m_path[i],v=m_path[i+1];\n\
    \                if (dq[u]<dp[u] and dq[v]>dp[v])\n                    return\
    \ {u,v};\n            }\n            // std::unreachable();\n            assert(0);\n\
    \            return {0,0};\n        }();\n        if (u==v)\n            m_root=v;\n\
    \        else {\n            U w=0;\n            for (auto it=m_g[u].begin() ;\
    \ it != m_g[u].end() ; it++)\n                if (it->first==v) {\n          \
    \          w=it->second;\n                    it=m_g[u].erase(it);\n         \
    \           break;\n                }\n            for (auto it=m_g[v].begin()\
    \ ; it != m_g[v].end() ; it++)\n                if (it->first==u) {\n        \
    \            it=m_g[v].erase(it);\n                    break;\n              \
    \  }\n            assert(w>0);\n            std::vector<std::pair<T,U>> adj;\n\
    \            adj.push_back({u,w/2});\n            adj.push_back({v,w/2+w%2});\n\
    \            dp.push_back(dp[v]+w/2+w%2);\n            dq.push_back(dq[u]+w/2);\n\
    \            m_root=size();\n            m_g.push_back(std::move(adj));\n    \
    \    }\n        m_farthest.resize(size());\n        for (usize i = 0 ; i < size()\
    \ ; i++)\n            m_farthest[i]=dp[i]<dq[i]?std::pair{q,dq[i]}:std::pair{p,dp[i]};\n\
    \        m_par.resize(size(),-1);\n        dfs(m_root,-1);\n    }\n\n    explicit\
    \ TreeCenters(std::vector<std::vector<T>> g) : TreeCenters(convert(std::move(g)))\
    \ {}\n\n    inline usize size() const noexcept {\n        return m_g.size();\n\
    \    }\n\n    inline const std::vector<T>& diameterPath() const {\n        return\
    \ m_path;\n    }\n\n    U diameterLength() const {\n        return m_farthest[m_path[0]].second;\n\
    \    }\n\n    inline T root() const noexcept {\n        return m_root;\n    }\n\
    \n    inline const std::vector<std::pair<T,U>>& operator[](usize v) const noexcept\
    \ {\n        assert(v<size());\n        return m_g[v];\n    }\n\n    inline i32\
    \ parent(usize v) const noexcept {\n        assert(v<size());\n        return\
    \ m_par[v];\n    }\n    \n    inline const std::pair<T,U>& farthest(usize v) const\
    \ noexcept {\n        assert(v<size());\n        return m_farthest[v];\n    }\n\
    \nprivate:\n\n    std::pair<std::vector<U>,std::vector<i32>> bfs(T s) const {\n\
    \        std::vector<T> que{s};\n        std::vector<U> dist(size(),static_cast<U>(-1));\n\
    \        dist[s]=0;\n        std::vector<i32> prev(size(),-1);\n        for (usize\
    \ t = 0 ; t < que.size() ; t++) {\n            const T v=que[t];\n           \
    \ for (auto [x,w] : m_g[v]) {\n                assert(w > 0 and \"TreeCenters:\
    \ edge weight must be positive\");\n                if (dist[x]==-1) {\n     \
    \               dist[x]=dist[v]+w;\n                    prev[x]=v;\n         \
    \           que.push_back(x);\n                }\n            }\n        }\n \
    \       return {std::move(dist),std::move(prev)};\n    }\n\n    void dfs(T v,T\
    \ p) {\n        m_par[v]=p;\n        for (auto it=m_g[v].begin() ; it!=m_g[v].end()\
    \ ; ) {\n            if (it->first==p)\n                it=m_g[v].erase(it);\n\
    \            else {\n                dfs(it->first,v);\n                it++;\n\
    \            }\n        }\n    }\n\n    static std::vector<std::vector<std::pair<T,U>>>\
    \ convert(std::vector<std::vector<T>> g) {\n        std::vector<std::vector<std::pair<T,U>>>\
    \ res(g.size());\n        for (usize i = 0 ; i < g.size() ; i++)\n           \
    \ for (T x : g[i])\n                res[i].push_back({x,U{1}});\n        return\
    \ res;\n    }\n\n    std::vector<std::vector<std::pair<T,U>>> m_g;\n\n    std::vector<T>\
    \ m_path;\n\n    T m_root;\n\n    std::vector<i32> m_par;\n\n    std::vector<std::pair<T,U>>\
    \ m_farthest;\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral T,class U>\n\
    class TreeCenters {\npublic:\n\n    explicit TreeCenters(std::vector<std::vector<std::pair<T,U>>>\
    \ g) \n        : m_g{std::move(g)},m_path{},m_root{} {\n        assert(size()\
    \ and \"TreeCenters: empty graph is not a tree\");\n        auto d0=bfs(0).first;\n\
    \        const T p=std::ranges::max_element(d0)-d0.begin();\n        auto [dp,prev]=bfs(p);\n\
    \        const T q=std::ranges::max_element(dp)-dp.begin();\n        auto dq=bfs(q).first;\n\
    \        for (i32 v = static_cast<i32>(q) ; ; v = prev[v]) {\n            m_path.push_back(v);\n\
    \            if (static_cast<T>(v)==p)\n                break;\n        }\n  \
    \      const auto [u,v]=[&]() -> std::pair<T,T> {\n            for (usize i =\
    \ 0 ; i < m_path.size() ; i++)\n                if (dq[m_path[i]]==dp[m_path[i]])\n\
    \                    return {m_path[i],m_path[i]};\n            for (usize i =\
    \ 0 ; i + 1 < m_path.size() ; i++) {\n                T u=m_path[i],v=m_path[i+1];\n\
    \                if (dq[u]<dp[u] and dq[v]>dp[v])\n                    return\
    \ {u,v};\n            }\n            // std::unreachable();\n            assert(0);\n\
    \            return {0,0};\n        }();\n        if (u==v)\n            m_root=v;\n\
    \        else {\n            U w=0;\n            for (auto it=m_g[u].begin() ;\
    \ it != m_g[u].end() ; it++)\n                if (it->first==v) {\n          \
    \          w=it->second;\n                    it=m_g[u].erase(it);\n         \
    \           break;\n                }\n            for (auto it=m_g[v].begin()\
    \ ; it != m_g[v].end() ; it++)\n                if (it->first==u) {\n        \
    \            it=m_g[v].erase(it);\n                    break;\n              \
    \  }\n            assert(w>0);\n            std::vector<std::pair<T,U>> adj;\n\
    \            adj.push_back({u,w/2});\n            adj.push_back({v,w/2+w%2});\n\
    \            dp.push_back(dp[v]+w/2+w%2);\n            dq.push_back(dq[u]+w/2);\n\
    \            m_root=size();\n            m_g.push_back(std::move(adj));\n    \
    \    }\n        m_farthest.resize(size());\n        for (usize i = 0 ; i < size()\
    \ ; i++)\n            m_farthest[i]=dp[i]<dq[i]?std::pair{q,dq[i]}:std::pair{p,dp[i]};\n\
    \        m_par.resize(size(),-1);\n        dfs(m_root,-1);\n    }\n\n    explicit\
    \ TreeCenters(std::vector<std::vector<T>> g) : TreeCenters(convert(std::move(g)))\
    \ {}\n\n    inline usize size() const noexcept {\n        return m_g.size();\n\
    \    }\n\n    inline const std::vector<T>& diameterPath() const {\n        return\
    \ m_path;\n    }\n\n    U diameterLength() const {\n        return m_farthest[m_path[0]].second;\n\
    \    }\n\n    inline T root() const noexcept {\n        return m_root;\n    }\n\
    \n    inline const std::vector<std::pair<T,U>>& operator[](usize v) const noexcept\
    \ {\n        assert(v<size());\n        return m_g[v];\n    }\n\n    inline i32\
    \ parent(usize v) const noexcept {\n        assert(v<size());\n        return\
    \ m_par[v];\n    }\n    \n    inline const std::pair<T,U>& farthest(usize v) const\
    \ noexcept {\n        assert(v<size());\n        return m_farthest[v];\n    }\n\
    \nprivate:\n\n    std::pair<std::vector<U>,std::vector<i32>> bfs(T s) const {\n\
    \        std::vector<T> que{s};\n        std::vector<U> dist(size(),static_cast<U>(-1));\n\
    \        dist[s]=0;\n        std::vector<i32> prev(size(),-1);\n        for (usize\
    \ t = 0 ; t < que.size() ; t++) {\n            const T v=que[t];\n           \
    \ for (auto [x,w] : m_g[v]) {\n                assert(w > 0 and \"TreeCenters:\
    \ edge weight must be positive\");\n                if (dist[x]==-1) {\n     \
    \               dist[x]=dist[v]+w;\n                    prev[x]=v;\n         \
    \           que.push_back(x);\n                }\n            }\n        }\n \
    \       return {std::move(dist),std::move(prev)};\n    }\n\n    void dfs(T v,T\
    \ p) {\n        m_par[v]=p;\n        for (auto it=m_g[v].begin() ; it!=m_g[v].end()\
    \ ; ) {\n            if (it->first==p)\n                it=m_g[v].erase(it);\n\
    \            else {\n                dfs(it->first,v);\n                it++;\n\
    \            }\n        }\n    }\n\n    static std::vector<std::vector<std::pair<T,U>>>\
    \ convert(std::vector<std::vector<T>> g) {\n        std::vector<std::vector<std::pair<T,U>>>\
    \ res(g.size());\n        for (usize i = 0 ; i < g.size() ; i++)\n           \
    \ for (T x : g[i])\n                res[i].push_back({x,U{1}});\n        return\
    \ res;\n    }\n\n    std::vector<std::vector<std::pair<T,U>>> m_g;\n\n    std::vector<T>\
    \ m_path;\n\n    T m_root;\n\n    std::vector<i32> m_par;\n\n    std::vector<std::pair<T,U>>\
    \ m_farthest;\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/TreeCenters.hpp
  requiredBy: []
  timestamp: '2026-11-01 20:19:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF1045-D.test.cpp
  - Test/LC/tree_diameter.test.cpp
  - Test/AtCoder/abc482_e.test.cpp
  - Test/AtCoder/abc221_f.test.cpp
documentation_of: Src/Graph/Tree/TreeCenters.hpp
layout: document
title: "\u6728\u306E\u76F4\u5F84\u306B\u307E\u3064\u308F\u308BUtility\u30AF\u30E9\u30B9"
---

## 概要

与えられた木を木の中心を根とした根付き木に変換する。

中心が辺の上にあるときは、辺を分割して仮想頂点を置き、仮想頂点を根とする。

## ライブラリの使い方

### テンプレート引数

```
template <std::integral T,class U>
class TreeCenters
```

`T`は頂点番号の型。`int`、`u32`、`usize`のいずれかであることが推奨される。

`U`は辺重みの型。整数であることが必要。直径の長さが`U`で表現できる(オーバーフローしない)ことが重要である。

### コンストラクタ

```
explicit TreeCenters(std::vector<std::vector<std::pair<T,U>>> g)  (1)
explicit TreeCenters(std::vector<std::vector<T>> g) (2)
```

(1)は辺に重みがある場合、いつもの隣接リストの形式で与える。

**重要な制約として、各辺の重みは正である必要がある。特に、辺の重みとして $0$ も許容されず、assertにひっかかる点に注意**

(2)は辺に重みが無い場合に用いることができる。全ての辺の重みが $1$ であると仮定してアルゴリズムを実行する。

それぞれについて与えられた木に対して以下の手続きを行う

- 直径を一つ求める
- 直径から中心を求める
- 中心が辺上にあるときは、仮想頂点 $N$ を追加して、もとの辺を消し、仮想頂点と接続する。このときの仮想頂点とつながる辺の重みはそれぞれ元の辺の重みを $w$ として $\lfloor\frac{w}{2}\rfloor$ 及び $\lceil\frac{w}{2}\rceil$ である。よって辺上に中心がある場合は、厳密に中心を取っているわけではない。
- 中心を根とした根付き木に変換する。特に、子孫から親方向への辺は削除され、有向木として管理される
- 各頂点の親頂点が計算される
- 各頂点について最遠点とその距離が計算される

**計算量**: $O(N)$

### メンバ

```
inline usize size() const noexcept
inline const std::vector<T>& diameterPath() const
U diameterLength() const
inline T root() const noexcept
inline const std::vector<std::pair<T,U>>& operator[](usize v) const noexcept
inline i32 parent(usize v) const noexcept
inline const std::pair<T,U>& farthest(usize v) const noexcept
```

- `size()` は根付き木の頂点数。木の中心が頂点にあるときは $N$ 、そうでないときは $N+1$ に一致する。  $O(1)$
- `diameterPath()` は発見した直径の頂点列を返す。中心が辺の場合の仮想頂点は含まない。
- `diameterLength()` は直径の長さ (辺重みの総和) を返す。 $O(1)$
- `root()` は変換後の根頂点の番号を返す。特に、仮想頂点が根のときは $N$ が返ることになる。 $O(1)$　
- `operator[](v)` は根付き木における $v$ の直接の子のリスト。コンストラクタ(1)の引数と同様に`pair{子,辺重み}`で返す。
- `parent(v)` は $v$ の親頂点。 $v$ が根のときは `-1` が返される。 $O(1)$
- `farthest(v)` は $v$ の最遠点の一つが `first` に、最遠点までの距離が `second` に返される。なお、`first`に入る最遠点は`diameterPath().front(),diameterPath().back()`のいずれか一方である。 $O(1)$


## 更新履歴

- 2026/11/01: 作成
