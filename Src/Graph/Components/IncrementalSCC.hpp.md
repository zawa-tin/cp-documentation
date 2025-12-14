---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/ECR167-F.test.cpp
    title: Test/CF/ECR167-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/incremental_scc.test.cpp
    title: Test/LC/incremental_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/scc.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"atcoder/scc.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\nclass IncrementalSCCResponse {\npublic:\n    using TimeType\
    \ = u32;\n    static constexpr TimeType invalid() noexcept {\n        return INVALID;\n\
    \    }\n    IncrementalSCCResponse() = default;\n    IncrementalSCCResponse(const\
    \ std::vector<TimeType>& T) : time_{T} {\n        time_.shrink_to_fit();\n   \
    \ }\n    TimeType operator[](u32 i) const noexcept {\n        assert(i < time_.size());\n\
    \        return time_[i];\n    }\n    bool same(u32 i) const noexcept {\n    \
    \    return time_[i] != INVALID;\n    }\nprivate:\n    static constexpr TimeType\
    \ INVALID{static_cast<TimeType>(-1)};\n    std::vector<TimeType> time_;\n};\n\n\
    class IncrementalSCC {\nprivate:\n    using TimeType = IncrementalSCCResponse::TimeType;\n\
    \    using VType = u32;\n    using Edge = std::tuple<TimeType, VType, VType>;\n\
    \    static constexpr u32 INVALID{IncrementalSCCResponse::invalid()};\n\n    usize\
    \ n_;\n    std::vector<Edge> edges_;\npublic:\n    IncrementalSCC() = default;\n\
    \    IncrementalSCC(usize n) : n_{n}, edges_{} {}\n\n    inline u32 size() const\
    \ noexcept {\n        return n_;\n    }\n\n    constexpr u32 invalid() const noexcept\
    \ {\n        return INVALID;\n    }\n\n    u32 addEdge(VType u, VType v) {\n \
    \       assert(u < n_);\n        assert(v < n_);\n        TimeType t{static_cast<TimeType>(edges_.size())};\n\
    \        edges_.emplace_back(t, u, v);\n        return t;\n    }\n\n    std::pair<VType,\
    \ VType> getEdge(TimeType t) const {\n        assert(t < edges_.size());\n   \
    \     auto [_, u, v]{edges_[t]};\n        return std::pair<VType, VType>{ u, v\
    \ };\n    }\n\n    IncrementalSCCResponse build() const {\n        std::vector<VType>\
    \ id(size(), INVALID);\n        std::vector<TimeType> res(edges_.size(), INVALID);\n\
    \        auto rec{[&](auto rec, u32 L, u32 R, const std::vector<Edge>& E) -> void\
    \ {\n            if (E.empty() or L + 1 >= R) {\n                return;\n   \
    \         }\n            u32 n{};\n            for (auto [t, u, v] : E) {\n  \
    \              if (id[u] == INVALID) {\n                    id[u] = n++;\n   \
    \             }\n                if (id[v] == INVALID) {\n                   \
    \ id[v] = n++;\n                }\n            }\n            u32 mid{(L + R)\
    \ >> 1};\n            atcoder::scc_graph g(n);\n            for (auto [t, u, v]\
    \ : E) {\n                if (t < mid) {\n                    g.add_edge(id[u],\
    \ id[v]);\n                }\n            }\n            auto scc{g.scc()};\n\
    \            std::vector<u32> comp(n);\n            for (u32 i{} ; i < scc.size()\
    \ ; i++) {\n                for (auto v : scc[i]) {\n                    comp[v]\
    \ = i;\n                }\n            }\n            std::vector<Edge> EL, ER;\n\
    \            for (auto [t, u, v] : E) {\n                u = id[u];\n        \
    \        v = id[v];\n                if (t < mid and comp[u] == comp[v]) {\n \
    \                   res[t] = std::min(res[t], mid - 1);\n                    EL.emplace_back(t,\
    \ u, v);\n                }\n                else {\n                    ER.emplace_back(t,\
    \ comp[u], comp[v]);\n                }\n            }\n            for (auto\
    \ [_, u, v] : E) {\n                id[u] = id[v] = INVALID;\n            }\n\
    \            rec(rec, L, mid, EL);\n            rec(rec, mid, R, ER);\n      \
    \  }};\n        rec(rec, u32{}, edges_.size() + 1, edges_);\n        return IncrementalSCCResponse{res};\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Components/IncrementalSCC.hpp
  requiredBy: []
  timestamp: '2024-06-28 18:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/incremental_scc.test.cpp
  - Test/CF/ECR167-F.test.cpp
documentation_of: Src/Graph/Components/IncrementalSCC.hpp
layout: document
title: offline incremental SCC
---

## 概要

$M$ 要素からなる有向辺の列 $E = ((u_{1}, v_{1}), (u_{2}, v_{2}), \dots, (u_{M}, v_{M}))$ が与えられる。

$N$ 頂点 $0$ 辺のグラフ $G$ に対して $E$ の辺をこの順に追加していく。

$E$ の各辺 $(u_{i}, v_{i})$ についてその辺の両端点が強連結になる時間を計算する。

## 使い方

#### コンストラクタ

```cpp
(1) IncrementalSCC() = default;
(2) IncrementalSCC(usize n)
```

(2) $n$ 頂点 $0$ 辺のグラフを用意する。 $E = ()$ とする。

<br />

#### size

```cpp
inline u32 size() const noexcept
```

グラフの頂点数を返す。

<br />

#### addEdge

```cpp
u32 addEdge(VType u, VType v)
```

`VType = u32`

$E$ の末尾に $u$ から $v$ へ伸びる辺を追加する。この辺が何番目に追加された辺かを0-indexedで返す。

<br />

#### getEdge

```cpp
std::pair<VType, VType> getEdge(TimeType t) const
```

0-indexedで $t$ 番目に追加された辺を返す。firstからsecondへ向けて張られた辺である。

<br />

#### build

```cpp
IncrementalSCCResponse build() const
```

$E$ の各辺 $(u_{i}, v_{i})$ について、頂点 $u_{i}, v_{i}$ が強連結になる時間を計算する。

**計算量**: $O(|E|\log |E|)$

#### IncrementalSCCResponse

#### invalid

```cpp
static constexpr TimeType invalid() noexcept
```

最後まで強連結にならないことを示す特別な値を返す。


#### operator[]

```cpp
TimeType operator[](u32 i) const noexcept
```

$(u_{i}, v_{i})$ について頂点 $u_{i}, v_{i}$ が強連結になる時間を返す。

厳密には、 $E$ の $0$ 番目から $t$ 番目までの辺を追加すると $u_{i}, v_{i}$ が強連結になるような最小の $t$ を返す。

そのような $t$ が存在しなければ`invalid()`を返す。

**計算量**: $O(1)$

<br />

#### same

```cpp
bool same(u32 i) const noexcept
```

$(u_{i}, v_{i})$ が最終的に強連結になるかを返す。

<br />

## メモ

$(u_{i}, v_{i})$ が強連結になる時間を $T_{i}$ とする。

頂点 $u_{i}, v_{i}$ にコスト $T_{i}$ の無向辺を張ったグラフを考える。

このグラフ上で最小全域木を張る。 木上の $u-v$ パスに含まれるコスト最大の辺のコスト $T$ が頂点 $u, v$ が強連結になる時間と一致する。

## 参考

- [My own algorithm -- offline incremental strongly connected components in O(mlog(m))](https://codeforces.com/blog/entry/91608)

