---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/Dinic.hpp
    title: "Dinic (\u6700\u5927\u6D41\u30FB\u6700\u5C0F\u30AB\u30C3\u30C8)"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/U32Pair.hpp
    title: Src/Utility/U32Pair.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc239/submissions/48601038
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc239_g.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Flow/Dinic.hpp\"\n\n#line 2 \"Src/Utility/U32Pair.hpp\"\
    \n\n#line 4 \"Src/Utility/U32Pair.hpp\"\n\n#include <functional>\n#line 7 \"Src/Utility/U32Pair.hpp\"\
    \n\nnamespace zawa {\n\nclass U32Pair {\nprivate:\n    static constexpr u32 SHIFT{32};\n\
    \    static constexpr u32 MASK{static_cast<u32>((1LL << SHIFT) - 1)};\n    u64\
    \ value_{};\npublic:\n    constexpr U32Pair() {}\n    constexpr U32Pair(u32 first,\
    \ u32 second) {\n        value_ = (static_cast<u64>(first) << SHIFT) | second;\n\
    \    }\n    constexpr u32 first() const noexcept {\n        return static_cast<u32>(value_\
    \ >> SHIFT);\n    }\n    constexpr u32 second() const noexcept {\n        return\
    \ static_cast<u32>(value_ & MASK);\n    }\n    constexpr u64 combined() const\
    \ noexcept {\n        return value_;\n    }\n    constexpr U32Pair& operator=(const\
    \ U32Pair& rhs) {\n        value_ = rhs.value_;\n        return *this;\n    }\n\
    \    friend constexpr bool operator==(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ == rhs.value_;\n    }\n    friend constexpr bool\
    \ operator!=(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ != rhs.value_;\n    }\n    friend constexpr bool operator<(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ < rhs.value_;\n    }\n    friend\
    \ constexpr bool operator<=(const U32Pair& lhs, const U32Pair& rhs) {\n      \
    \  return lhs.value_ <= rhs.value_;\n    }\n    friend constexpr bool operator>(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ > rhs.value_;\n\
    \    }\n    friend constexpr bool operator>=(const U32Pair& lhs, const U32Pair&\
    \ rhs) {\n        return lhs.value_ >= rhs.value_;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const U32Pair& pair) {\n        os << '(' << pair.first()\
    \ << ',' << pair.second() << ')';\n        return os;\n    }\n};\n\nstruct U32PairHash\
    \ {\n    usize operator()(const U32Pair& pair) const noexcept {\n        return\
    \ std::hash<u64>{}(pair.combined());\n    }\n};\n\n} // namespace zawa\n#line\
    \ 5 \"Src/Graph/Flow/Dinic.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #line 9 \"Src/Graph/Flow/Dinic.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #include <vector>\n#include <queue>\n\nnamespace zawa {\n\ntemplate <class Cap>\n\
    class Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>, \"Cap must be\
    \ signed\");\n    static constexpr u32 INVALID{static_cast<u32>(-1)};\n    using\
    \ EdgePointer = U32Pair;\npublic:\n    static constexpr u32 invalid() noexcept\
    \ {\n        return INVALID;\n    }\nprivate:\n    class ResidualGraph {\n   \
    \ public:\n        struct Edge {\n            u32 from{}, to{};\n            Cap\
    \ cap{};\n            u32 rev{};\n            Edge() = default;\n            Edge(u32\
    \ from, u32 to, const Cap& cap, u32 rev)\n                : from{from}, to{to},\
    \ cap{cap}, rev{rev} {}\n        }; \n    private:\n        usize n_{}, m_{};\n\
    \        std::vector<std::vector<Edge>> g_{};\n    public:\n        ResidualGraph()\
    \ = default;\n        ResidualGraph(usize n) : n_{n}, m_{}, g_(n) {\n        \
    \    g_.shrink_to_fit();\n        }\n\n        inline usize size() const noexcept\
    \ {\n            return n_;\n        }\n        inline usize edgeNumber() const\
    \ noexcept {\n            return m_;\n        }\n\n        std::vector<Edge>&\
    \ operator[](usize i) noexcept {\n            return g_[i];\n        }\n     \
    \   const std::vector<Edge>& operator[](usize i) const noexcept {\n          \
    \  return g_[i];\n        }\n        Edge& operator[](const EdgePointer& e) noexcept\
    \ {\n            return g_[e.first()][e.second()];\n        }\n        const Edge&\
    \ operator[](const EdgePointer& e) const noexcept {\n            return g_[e.first()][e.second()];\n\
    \        }\n\n        const Edge& reverseEdge(const EdgePointer& pos) const noexcept\
    \ {\n            const Edge& edge{g_[pos.first()][pos.second()]};\n          \
    \  return g_[edge.to][edge.rev];\n        }\n        \n        u32 addEdge(u32\
    \ from, u32 to, const Cap& cap) {\n            u32 i{static_cast<u32>(g_[from].size())};\n\
    \            u32 j{static_cast<u32>(from == to ? i + 1 : g_[to].size())};\n  \
    \          g_[from].emplace_back(from, to, cap, j);\n            g_[to].emplace_back(to,\
    \ from, Cap{}, i);\n            m_++;\n            return i;\n        }\n    \
    \    void update(Edge& e, const Cap& flow) {\n            assert(e.cap >= flow);\n\
    \            e.cap -= flow;\n            g_[e.to][e.rev].cap += flow;\n      \
    \  }\n    };\n\n    using Edge = typename ResidualGraph::Edge;\n\n    ResidualGraph\
    \ graph_;\n    std::vector<u32> label_;\n    std::vector<EdgePointer> edges_;\n\
    \    std::vector<u32> currentEdge_;\n\npublic:\n    inline usize size() const\
    \ noexcept {\n        return graph_.size();\n    }\n    inline usize edgeNumber()\
    \ const noexcept { \n        return graph_.edgeNumber();\n    }\nprivate:\n\n\
    \    inline bool admissible(const Edge& e) const noexcept {\n        return e.cap\
    \ > 0 and label_[e.from] + 1 == label_[e.to];\n    }\n\n    bool dualStep(u32\
    \ s, u32 t) {\n        std::fill(label_.begin(), label_.end(), invalid());\n \
    \       label_[s] = 0;\n        std::queue<u32> que{ { s } };\n        while (que.size())\
    \ {\n            u32 v{que.front()};\n            que.pop();\n            for\
    \ (const auto& edge : graph_[v]) if (edge.cap > 0) {\n                if (label_[edge.to]\
    \ > label_[v] + 1) {\n                    label_[edge.to] = label_[v] + 1;\n \
    \                   if (edge.to == t) return true;\n                    que.emplace(edge.to);\n\
    \                }\n            }\n        }\n        return label_[t] < size();\n\
    \    }\n\n    bool findAdmissiblePath(u32 s, u32 t, std::vector<EdgePointer>&\
    \ path) {\n        u32 v{path.empty() ? s : graph_[path.back()].to};\n       \
    \ while (true) {\n            while (currentEdge_[v] < graph_[v].size()) {\n \
    \               const Edge& now{graph_[v][currentEdge_[v]]};\n               \
    \ if (admissible(now)) {\n                    path.emplace_back(v, currentEdge_[v]);\n\
    \                    v = now.to;\n                }\n                else {\n\
    \                    currentEdge_[v]++;\n                }\n            }\n  \
    \          if (v == s) return false;\n            if (v == t) return true;\n \
    \           v = path.back().first();\n            path.pop_back();\n         \
    \   currentEdge_[v]++;\n        }\n        assert(false);\n        return false;\n\
    \    }\n\n    Cap flow(std::vector<EdgePointer>& path) {\n        Cap amount{graph_[*std::min_element(path.begin(),\
    \ path.end(), [&](const EdgePointer& l, const EdgePointer& r) -> bool {\n    \
    \            return graph_[l].cap < graph_[r].cap;\n            })].cap};\n  \
    \      assert(amount > 0);\n        usize becomeZero{invalid()};\n        for\
    \ (usize i{path.size()} ; i-- ; ) {\n            Edge& edge{graph_[path[i]]};\n\
    \            graph_.update(edge, amount);\n            if (edge.cap == 0) {\n\
    \                currentEdge_[edge.from]++;\n                becomeZero = i;\n\
    \            }\n        }\n        path.erase(path.begin() + becomeZero, path.end());\n\
    \        return amount;\n    }\n\n    Cap primalStep(u32 s, u32 t) {\n       \
    \ std::fill(currentEdge_.begin(), currentEdge_.end(), u32{});\n        currentEdge_[t]\
    \ = graph_[t].size();\n        std::vector<EdgePointer> path;\n        Cap res{};\n\
    \        while (findAdmissiblePath(s, t, path)) {\n            res += flow(path);\n\
    \        }\n        return res;\n    }\n\npublic:\n\n    Dinic() = default;\n\
    \    // @param m: \u8FBA\u6570\u3092\u3053\u3053\u306B\u5165\u308C\u308B\u3068\
    reserve\u3057\u3066\u304F\u308C\u308B\n    Dinic(usize n, usize m = usize{}) \n\
    \        : graph_{n}, label_(n), currentEdge_(n) {\n        label_.shrink_to_fit();\n\
    \        currentEdge_.shrink_to_fit();\n        edges_.reserve(m);\n    }\n\n\
    \    u32 addEdge(u32 from, u32 to, const Cap& cap) {\n        assert(from < size());\n\
    \        assert(to < size());\n        u32 res{static_cast<u32>(edges_.size())};\n\
    \        edges_.emplace_back(from, graph_.addEdge(from, to, cap));\n        return\
    \ res;\n    }\n\n    u32 from(u32 id) const noexcept {\n        assert(id < edgeNumber());\n\
    \        return graph_[edges_[id]].from;\n    }\n\n    u32 to(u32 id) const noexcept\
    \ {\n        assert(id < edgeNumber());\n        return graph_[edges_[id]].to;\n\
    \    }\n\n    Cap residual(u32 id) const noexcept {\n        assert(id < edgeNumber());\n\
    \        return graph_[edges_[id]].cap;\n    }\n\n    Cap flowed(u32 id) const\
    \ noexcept {\n        assert(id < edgeNumber());\n        return graph_.reverseEdge(edges_[id]).cap;\n\
    \    }\n\n    Cap originCap(u32 id) const noexcept {\n        assert(id < edgeNumber());\n\
    \        EdgePointer e{edges_[id]};\n        return graph_[e].cap + graph_.reverseEdge(edges_[id]).cap;\n\
    \    }\n\n    Cap flow(u32 s, u32 t) {\n        assert(s < size());\n        assert(t\
    \ < size());\n        Cap res{};\n        while (dualStep(s, t)) {\n         \
    \   res += primalStep(s, t);\n        }\n        return res;\n    }\n\n    std::vector<bool>\
    \ minCut(u32 s) const {\n        std::vector<bool> res(size());\n        std::queue<u32>\
    \ que{ { s } };\n        res[s] = true;\n        while (que.size()) {\n      \
    \      u32 v{que.front()};\n            que.pop();\n            for (const auto&\
    \ edge : graph_[v]) {\n                if (edge.cap > 0 and !res[edge.to]) {\n\
    \                    res[edge.to] = true;\n                    que.emplace(edge.to);\n\
    \                } \n            }\n        }\n        return res;\n    }\n};\n\
    \n} // namespace zawa\n#line 5 \"Test/Manual/abc239_g.test.cpp\"\n\n/*\n * ABC239-G\
    \ Builder Takahashi\n * https://atcoder.jp/contests/abc239/submissions/48601038\n\
    \ */\n\nvoid solve() {\n    using namespace zawa;\n    SetFastIO();\n    int n,\
    \ m; std::cin >> n >> m;\n    Dinic<long long> maxflow(2 * n);\n    const long\
    \ long INF{(long long)1e18};\n    for (int _{} ; _ < m ; _++) {\n        int a,\
    \ b; std::cin >> a >> b;\n        a--; b--;\n        maxflow.addEdge(n + a, b,\
    \ INF);\n        maxflow.addEdge(n + b, a, INF);\n    }\n    std::vector<u32>\
    \ id(n);\n    for (int i{} ; i < n ; i++) {\n        int c; std::cin >> c;\n \
    \       id[i] = maxflow.addEdge(i, i + n, c);\n        assert((int)id[i] == m\
    \ + m + i);\n    }\n    long long ans{maxflow.flow(n, n - 1)};\n    std::cout\
    \ << ans << '\\n';\n    auto cut{maxflow.minCut(n)};\n    // for (auto x : cut)\
    \ std::cerr << x << ' ';\n    // std::cerr << '\\n';\n    std::vector<int> recover;\n\
    \    for (int i{1} ; i < n - 1 ; i++) {\n        if (cut[i] and !cut[i + n]) recover.push_back(i);\n\
    \    }\n    std::cout << recover.size() << '\\n';\n    for (int i{} ; i < (int)recover.size()\
    \ ; i++) {\n        std::cout << recover[i] + 1 << (i + 1 == (int)recover.size()\
    \ ? '\\n' : ' ');\n    }\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n\
    \    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Flow/Dinic.hpp\"\
    \n\n/*\n * ABC239-G Builder Takahashi\n * https://atcoder.jp/contests/abc239/submissions/48601038\n\
    \ */\n\nvoid solve() {\n    using namespace zawa;\n    SetFastIO();\n    int n,\
    \ m; std::cin >> n >> m;\n    Dinic<long long> maxflow(2 * n);\n    const long\
    \ long INF{(long long)1e18};\n    for (int _{} ; _ < m ; _++) {\n        int a,\
    \ b; std::cin >> a >> b;\n        a--; b--;\n        maxflow.addEdge(n + a, b,\
    \ INF);\n        maxflow.addEdge(n + b, a, INF);\n    }\n    std::vector<u32>\
    \ id(n);\n    for (int i{} ; i < n ; i++) {\n        int c; std::cin >> c;\n \
    \       id[i] = maxflow.addEdge(i, i + n, c);\n        assert((int)id[i] == m\
    \ + m + i);\n    }\n    long long ans{maxflow.flow(n, n - 1)};\n    std::cout\
    \ << ans << '\\n';\n    auto cut{maxflow.minCut(n)};\n    // for (auto x : cut)\
    \ std::cerr << x << ' ';\n    // std::cerr << '\\n';\n    std::vector<int> recover;\n\
    \    for (int i{1} ; i < n - 1 ; i++) {\n        if (cut[i] and !cut[i + n]) recover.push_back(i);\n\
    \    }\n    std::cout << recover.size() << '\\n';\n    for (int i{} ; i < (int)recover.size()\
    \ ; i++) {\n        std::cout << recover[i] + 1 << (i + 1 == (int)recover.size()\
    \ ? '\\n' : ' ');\n    }\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n\
    \    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Flow/Dinic.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: true
  path: Test/Manual/abc239_g.test.cpp
  requiredBy: []
  timestamp: '2023-12-17 03:05:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc239_g.test.cpp
layout: document
title: ABC239-G Builder Takahashi
---

最大流最小カット定理より、ネットワーク $(V, E, s, t)$ の最大フロー $f$ から誘導される残余ネットワーク$G_{f}$ は $s-t$ の最小カットである。

今回の問題は最小カットを求める問題と一緒なので、最大フロー $f$ を求めた上でカットを復元できれば良い。

これは残余ネットワーク上で $s$ 側から正の残余容量を持つ辺のみをたどって到達できる頂点集合が最小カットの片側の集合である。
- BFSをすれば良い
