---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3168.test.cpp
    title: Test/AOJ/3168.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_6_A.test.cpp
    title: Test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/GRL_7_A.test.cpp
    title: Test/AOJ/GRL_7_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Flow/Dinic.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Flow/Dinic.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Cap>\nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>,\
    \ \"Cap must be signed\");\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    public:\n    static constexpr u32 invalid() noexcept {\n        return INVALID;\n\
    \    }\nprivate:\n    class ResidualGraph {\n    public:\n        struct Edge\
    \ {\n            u32 from{}, to{};\n            Cap cap{};\n            u32 rev{},\
    \ id{};\n            Edge() = default;\n            Edge(u32 from, u32 to, const\
    \ Cap& cap, u32 rev, u32 id)\n                : from{from}, to{to}, cap{cap},\
    \ rev{rev}, id{id} {}\n        }; \n    private:\n        usize n_{}, m_{};\n\
    \        std::vector<std::vector<Edge>> g_{};\n    public:\n        ResidualGraph()\
    \ = default;\n        ResidualGraph(usize n) : n_{n}, m_{}, g_(n) {\n        \
    \    g_.shrink_to_fit();\n        }\n\n        inline usize size() const noexcept\
    \ {\n            return n_;\n        }\n        inline usize edgeNumber() const\
    \ noexcept {\n            return m_;\n        }\n\n        std::vector<Edge>&\
    \ operator[](usize i) noexcept {\n            assert(i < size());\n          \
    \  return g_[i];\n        }\n        const std::vector<Edge>& operator[](usize\
    \ i) const noexcept {\n            assert(i < size());\n            return g_[i];\n\
    \        }\n\n        void addEdge(u32 from, u32 to, const Cap& cap, u32 id) {\n\
    \            u32 i{static_cast<u32>(g_[from].size())};\n            u32 j{static_cast<u32>(from\
    \ == to ? i + 1 : g_[to].size())};\n            g_[from].emplace_back(from, to,\
    \ cap, j, id);\n            g_[to].emplace_back(to, from, Cap{}, i, id);\n   \
    \         m_++;\n        }\n        void update(Edge& e, const Cap& flow) {\n\
    \            assert(e.cap >= flow);\n            e.cap -= flow;\n            g_[e.to][e.rev].cap\
    \ += flow;\n        }\n        u32 invalidEdgePointer(u32 v) const noexcept {\n\
    \            return g_[v].size();\n        }\n    };\n\n    ResidualGraph graph_;\n\
    \    std::vector<u32> label_;\n\npublic:\n    using Edge = typename ResidualGraph::Edge;\n\
    \    inline usize size() const noexcept {\n        return graph_.size();\n   \
    \ }\nprivate:\n\n    bool admissible(const Edge& e) {\n        return e.cap >\
    \ 0 and label_[e.from] + 1 == label_[e.to];\n    }\n\n    bool dualStep(u32 s,\
    \ u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n    \
    \    label_[s] = 0;\n        std::vector<u32> queue;\n        queue.reserve(size());\n\
    \        queue.emplace_back(s);\n        for (u32 topQ{} ; topQ < queue.size()\
    \ ; topQ++) {\n            u32 v{queue[topQ]};\n            for (const auto& e\
    \ : graph_[v]) if (e.cap > 0) {\n                if (label_[e.to] > label_[v]\
    \ + 1) {\n                    label_[e.to] = label_[v] + 1;\n                \
    \    queue.emplace_back(e.to);\n                }\n            }\n        }\n\
    \        return label_[t] < size();\n    }\n\n    using EdgePointer = std::pair<u32,\
    \ u32>;\n\n    bool findAdmissiblePath(u32 s, u32 t, std::vector<EdgePointer>&\
    \ path) {\n        std::vector<u32> currentEdge(size());\n        currentEdge[t]\
    \ = graph_.invalidEdgePointer(t);\n        u32 v{s};\n        while (true) {\n\
    \            while (currentEdge[v] != graph_.invalidEdgePointer(v)) {\n      \
    \          const Edge& now{graph_[v][currentEdge[v]]};\n                if (admissible(now))\
    \ {\n                    path.emplace_back(v, currentEdge[v]);\n             \
    \       v = now.to;\n                }\n                else {\n             \
    \       currentEdge[v]++;\n                }\n            }\n            if (v\
    \ == s) return false;\n            if (v == t) return true;\n            if (v\
    \ != t) {\n                v = path.back().first;\n                path.pop_back();\n\
    \                currentEdge[v]++;\n            }\n        }\n        assert(false);\n\
    \        return false;\n    }\n\n    Cap flow(const std::vector<EdgePointer>&\
    \ path) {\n        auto min{std::min_element(path.begin(), path.end(), [&](const\
    \ EdgePointer& l, const EdgePointer& r) -> bool {\n                return graph_[l.first][l.second].cap\
    \ < graph_[r.first][r.second].cap;\n            })};\n        Cap amount{graph_[min->first][min->second].cap};\n\
    \        assert(amount > 0);\n        for (const auto& [x, y] : path) {\n    \
    \        Edge& e{graph_[x][y]};\n            graph_.update(e, amount);\n     \
    \   }\n        return amount;\n    }\n\n    Cap primalStep(u32 s, u32 t) {\n \
    \       std::vector<EdgePointer> path;\n        Cap res{};\n        while (findAdmissiblePath(s,\
    \ t, path)) {\n            res += flow(path);\n            path.clear();\n   \
    \     }\n        return res;\n    }\n\npublic:\n\n    Dinic() = default;\n   \
    \ Dinic(usize n) : graph_{n}, label_(n) {\n        label_.shrink_to_fit();\n \
    \   }\n\n    void addEdge(u32 from, u32 to, const Cap& cap, u32 id = invalid())\
    \ {\n        assert(from < size());\n        assert(to < size());\n        graph_.addEdge(from,\
    \ to, cap, id);\n    }\n\n    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n\
    \        assert(t < size());\n        Cap res{};\n        while (dualStep(s, t))\
    \ {\n            res += primalStep(s, t);\n        }\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class Cap>\nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>,\
    \ \"Cap must be signed\");\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n\
    public:\n    static constexpr u32 invalid() noexcept {\n        return INVALID;\n\
    \    }\nprivate:\n    class ResidualGraph {\n    public:\n        struct Edge\
    \ {\n            u32 from{}, to{};\n            Cap cap{};\n            u32 rev{},\
    \ id{};\n            Edge() = default;\n            Edge(u32 from, u32 to, const\
    \ Cap& cap, u32 rev, u32 id)\n                : from{from}, to{to}, cap{cap},\
    \ rev{rev}, id{id} {}\n        }; \n    private:\n        usize n_{}, m_{};\n\
    \        std::vector<std::vector<Edge>> g_{};\n    public:\n        ResidualGraph()\
    \ = default;\n        ResidualGraph(usize n) : n_{n}, m_{}, g_(n) {\n        \
    \    g_.shrink_to_fit();\n        }\n\n        inline usize size() const noexcept\
    \ {\n            return n_;\n        }\n        inline usize edgeNumber() const\
    \ noexcept {\n            return m_;\n        }\n\n        std::vector<Edge>&\
    \ operator[](usize i) noexcept {\n            assert(i < size());\n          \
    \  return g_[i];\n        }\n        const std::vector<Edge>& operator[](usize\
    \ i) const noexcept {\n            assert(i < size());\n            return g_[i];\n\
    \        }\n\n        void addEdge(u32 from, u32 to, const Cap& cap, u32 id) {\n\
    \            u32 i{static_cast<u32>(g_[from].size())};\n            u32 j{static_cast<u32>(from\
    \ == to ? i + 1 : g_[to].size())};\n            g_[from].emplace_back(from, to,\
    \ cap, j, id);\n            g_[to].emplace_back(to, from, Cap{}, i, id);\n   \
    \         m_++;\n        }\n        void update(Edge& e, const Cap& flow) {\n\
    \            assert(e.cap >= flow);\n            e.cap -= flow;\n            g_[e.to][e.rev].cap\
    \ += flow;\n        }\n        u32 invalidEdgePointer(u32 v) const noexcept {\n\
    \            return g_[v].size();\n        }\n    };\n\n    ResidualGraph graph_;\n\
    \    std::vector<u32> label_;\n\npublic:\n    using Edge = typename ResidualGraph::Edge;\n\
    \    inline usize size() const noexcept {\n        return graph_.size();\n   \
    \ }\nprivate:\n\n    bool admissible(const Edge& e) {\n        return e.cap >\
    \ 0 and label_[e.from] + 1 == label_[e.to];\n    }\n\n    bool dualStep(u32 s,\
    \ u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n    \
    \    label_[s] = 0;\n        std::vector<u32> queue;\n        queue.reserve(size());\n\
    \        queue.emplace_back(s);\n        for (u32 topQ{} ; topQ < queue.size()\
    \ ; topQ++) {\n            u32 v{queue[topQ]};\n            for (const auto& e\
    \ : graph_[v]) if (e.cap > 0) {\n                if (label_[e.to] > label_[v]\
    \ + 1) {\n                    label_[e.to] = label_[v] + 1;\n                \
    \    queue.emplace_back(e.to);\n                }\n            }\n        }\n\
    \        return label_[t] < size();\n    }\n\n    using EdgePointer = std::pair<u32,\
    \ u32>;\n\n    bool findAdmissiblePath(u32 s, u32 t, std::vector<EdgePointer>&\
    \ path) {\n        std::vector<u32> currentEdge(size());\n        currentEdge[t]\
    \ = graph_.invalidEdgePointer(t);\n        u32 v{s};\n        while (true) {\n\
    \            while (currentEdge[v] != graph_.invalidEdgePointer(v)) {\n      \
    \          const Edge& now{graph_[v][currentEdge[v]]};\n                if (admissible(now))\
    \ {\n                    path.emplace_back(v, currentEdge[v]);\n             \
    \       v = now.to;\n                }\n                else {\n             \
    \       currentEdge[v]++;\n                }\n            }\n            if (v\
    \ == s) return false;\n            if (v == t) return true;\n            if (v\
    \ != t) {\n                v = path.back().first;\n                path.pop_back();\n\
    \                currentEdge[v]++;\n            }\n        }\n        assert(false);\n\
    \        return false;\n    }\n\n    Cap flow(const std::vector<EdgePointer>&\
    \ path) {\n        auto min{std::min_element(path.begin(), path.end(), [&](const\
    \ EdgePointer& l, const EdgePointer& r) -> bool {\n                return graph_[l.first][l.second].cap\
    \ < graph_[r.first][r.second].cap;\n            })};\n        Cap amount{graph_[min->first][min->second].cap};\n\
    \        assert(amount > 0);\n        for (const auto& [x, y] : path) {\n    \
    \        Edge& e{graph_[x][y]};\n            graph_.update(e, amount);\n     \
    \   }\n        return amount;\n    }\n\n    Cap primalStep(u32 s, u32 t) {\n \
    \       std::vector<EdgePointer> path;\n        Cap res{};\n        while (findAdmissiblePath(s,\
    \ t, path)) {\n            res += flow(path);\n            path.clear();\n   \
    \     }\n        return res;\n    }\n\npublic:\n\n    Dinic() = default;\n   \
    \ Dinic(usize n) : graph_{n}, label_(n) {\n        label_.shrink_to_fit();\n \
    \   }\n\n    void addEdge(u32 from, u32 to, const Cap& cap, u32 id = invalid())\
    \ {\n        assert(from < size());\n        assert(to < size());\n        graph_.addEdge(from,\
    \ to, cap, id);\n    }\n\n    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n\
    \        assert(t < size());\n        Cap res{};\n        while (dualStep(s, t))\
    \ {\n            res += primalStep(s, t);\n        }\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Flow/Dinic.hpp
  requiredBy: []
  timestamp: '2023-12-15 16:43:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/GRL_7_A.test.cpp
  - Test/AOJ/3168.test.cpp
  - Test/AOJ/GRL_6_A.test.cpp
documentation_of: Src/Graph/Flow/Dinic.hpp
layout: document
redirect_from:
- /library/Src/Graph/Flow/Dinic.hpp
- /library/Src/Graph/Flow/Dinic.hpp.html
title: Src/Graph/Flow/Dinic.hpp
---
