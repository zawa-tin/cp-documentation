---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/SuccessiveShortestPath.hpp
    title: "SuccessiveShortestPath (\u6700\u5C0F\u8CBB\u7528\u6D41\u3001\u6700\u77ED\
      \u8DEF\u53CD\u5FA9\u6CD5)"
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
    PROBLEM: https://atcoder.jp/contests/abc247/tasks/abc247_g
    links:
    - https://atcoder.jp/contests/abc247/tasks/abc247_g
  bundledCode: "#line 1 \"Test/AtCoder/abc247_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc247/tasks/abc247_g\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Flow/SuccessiveShortestPath.hpp\"\
    \n\n#line 2 \"Src/Utility/U32Pair.hpp\"\n\n#line 4 \"Src/Utility/U32Pair.hpp\"\
    \n\n#include <functional>\n#line 7 \"Src/Utility/U32Pair.hpp\"\n\nnamespace zawa\
    \ {\n\nclass U32Pair {\nprivate:\n    static constexpr u32 SHIFT{32};\n    static\
    \ constexpr u32 MASK{static_cast<u32>((1LL << SHIFT) - 1)};\n    u64 value_{};\n\
    public:\n    constexpr U32Pair() {}\n    constexpr U32Pair(u32 first, u32 second)\
    \ {\n        value_ = (static_cast<u64>(first) << SHIFT) | second;\n    }\n  \
    \  constexpr u32 first() const noexcept {\n        return static_cast<u32>(value_\
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
    \ 5 \"Src/Graph/Flow/SuccessiveShortestPath.hpp\"\n\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n#include <type_traits>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace zawa {\n\ntemplate <class Cap, class Cost>\nclass SuccessiveShortestPath\
    \ {\npublic:\n    static_assert(std::is_signed_v<Cost>, U\"Cost must be signed\"\
    );\n    static constexpr Cost invalid{(std::numeric_limits<Cost>::max() >> 1)\
    \ - 1};\n    static constexpr u32 reverseId(u32 i) noexcept {\n        return\
    \ i ^ 1;\n    }\n\n    struct Edge {\n        u32 from{}, to{};\n        Cap residual{};\n\
    \        Cost cost{};\n        Edge() = default;\n        Edge(u32 from, u32 to,\
    \ const Cap& cap, const Cost& cost)\n            : from{from}, to{to}, residual{cap},\
    \ cost{cost} {}\n    };\n\n    usize n_{}, m_{};\n    std::vector<Edge> edges_;\n\
    \    std::vector<std::vector<u32>> g_;\n    std::vector<Cost> dist_, potential_;\n\
    \    std::vector<U32Pair> prev_;\n    Cost mcf_{};\n\n    constexpr usize size()\
    \ const noexcept {\n        return n_;\n    }\n    constexpr usize edgeSize()\
    \ const noexcept {\n        return m_;\n    }\n    \n    SuccessiveShortestPath()\
    \ = default;\n    SuccessiveShortestPath(usize n, usize m = usize{}) \n      \
    \  : n_{n}, m_{}, edges_{}, g_(n), dist_(n), potential_(n), prev_(n), mcf_{} {\n\
    \        g_.shrink_to_fit();\n        dist_.shrink_to_fit();\n        potential_.shrink_to_fit();\n\
    \        prev_.shrink_to_fit();\n        edges_.reserve(2 * m);\n    }\n\n   \
    \ void emplace(u32 from, u32 to, const Cap& cap, const Cost& cost) {\n       \
    \ g_[from].emplace_back(m_);\n        edges_.emplace_back(from, to, cap, cost);\n\
    \        m_++;\n    }\n\n    u32 addEdge(u32 from, u32 to, const Cap& cap, const\
    \ Cost& cost) {\n        assert(from < size());\n        assert(to < size());\n\
    \        u32 res{static_cast<u32>(m_)};\n        emplace(from, to, cap, cost);\n\
    \        emplace(to, from, Cap{}, -cost);\n        return res;\n    }\n\n    inline\
    \ u32 from(u32 i) const noexcept {\n        return edges_[i].from;\n    }\n  \
    \  inline u32 to(u32 i) const noexcept {\n        return edges_[i].to;\n    }\n\
    \    inline const Cap& residual(u32 i) const noexcept {\n        return edges_[i].residual;\n\
    \    }\n    inline const Cost& cost(u32 i) const noexcept {\n        return edges_[i].cost;\n\
    \    }\n    inline const Cap& flowed(u32 i) const noexcept {\n        assert(i\
    \ < edgeSize());\n        return residual(i ^ 1);\n    }\n    inline const Cap&\
    \ capcacity(u32 i) const noexcept {\n        assert(i < edgeSize());\n       \
    \ return residual(i) + flowed(i);\n    }\n\n    inline Cost edgeCost(u32 i) const\
    \ noexcept {\n        return potential_[from(i)] + cost(i) - potential_[to(i)];\n\
    \    }\n    bool relax(u32 i) {\n        if (residual(i) > 0 and dist_[to(i)]\
    \ > dist_[from(i)] + edgeCost(i)) {\n            dist_[to(i)] = dist_[from(i)]\
    \ + edgeCost(i);\n            prev_[to(i)] = U32Pair{from(i), i};\n          \
    \  return true;\n        }\n        return false;\n    }\n\n    bool dijkstra(u32\
    \ s, u32 t) {\n        assert(s < size());\n        assert(t < size());\n    \
    \    std::fill(dist_.begin(), dist_.end(), invalid);\n        dist_[s] = Cost{};\n\
    \        using qt = std::pair<Cost, u32>;\n        std::priority_queue<qt, std::vector<qt>,\
    \ std::greater<qt>> que;\n        que.emplace(dist_[s], s);\n        while (que.size())\
    \ {\n            auto [d, v]{que.top()};\n            que.pop();\n           \
    \ if (dist_[v] < d) continue;\n            for (u32 i : g_[v]) {\n           \
    \     if (relax(i)) {\n                    que.emplace(dist_[to(i)], to(i));\n\
    \                }\n            }\n        }\n        return dist_[t] < invalid;\n\
    \    }\n\n    bool dagdp(u32 s, u32 t) {\n        assert(s < size());\n      \
    \  assert(t < size());\n        std::fill(dist_.begin(), dist_.end(), invalid);\n\
    \        dist_[s] = Cost{};\n        std::vector<u32> ord;\n        ord.reserve(size());\n\
    \        std::vector<bool> vis(size());\n        vis[s] = true;\n        ord.push_back(s);\n\
    \        for (u32 i{} ; i < ord.size() ; i++) {\n            u32 v{ord[i]};\n\
    \            for (auto e : g_[v]) {\n                if (!vis[to(e)]) {\n    \
    \                ord.push_back(to(e));\n                    vis[to(e)] = true;\n\
    \                }\n                relax(e);\n            }\n        }\n    \
    \    return dist_[t] < invalid;\n    }\n\n    bool bellmanford(u32 s, u32 t) {\n\
    \        assert(s < size());\n        assert(t < size());\n        std::fill(dist_.begin(),\
    \ dist_.end(), invalid);\n        dist_[s] = Cost{};\n        for (u32 i{} ; i\
    \ + 1 < size() ; i++) {\n            for (u32 j{} ; j < edgeSize() ; j++) {\n\
    \                relax(j);\n            }\n        }\n        return dist_[t]\
    \ < invalid;\n    }\n\n    void updatePotential() {\n        for (u32 v{} ; v\
    \ < size() ; v++) {\n            potential_[v] = potential_[v] + (dist_[v] ==\
    \ invalid ? Cost{} : dist_[v]);\n        }\n    }\n\n    Cap flush(u32 s, u32\
    \ t, Cap up = std::numeric_limits<Cap>::max()) {\n        for (u32 v{t} ; v !=\
    \ s ; v = prev_[v].first()) {\n            up = std::min(up, residual(prev_[v].second()));\n\
    \        }\n        for (u32 v{t} ; v != s ; v = prev_[v].first()) {\n       \
    \     edges_[prev_[v].second()].residual -= up;\n            edges_[prev_[v].second()\
    \ ^ 1].residual += up;\n        }\n        return up;\n    }\n\n    bool flow(u32\
    \ s, u32 t, Cap flow) {\n        assert(s < size());\n        assert(t < size());\n\
    \        while (flow > 0 and dijkstra(s, t)) {\n            updatePotential();\n\
    \            Cap water{flush(s, t, flow)};\n            mcf_ += potential_[t]\
    \ * water;\n            flow -= water;\n        }\n        return flow == 0;\n\
    \    }\n\n    Cap maxflow(u32 s, u32 t) {\n        assert(s < size());\n     \
    \   assert(t < size());\n        Cap flow{};\n        while (dijkstra(s, t)) {\n\
    \            updatePotential();\n            Cap water{flush(s, t)};\n       \
    \     mcf_ += potential_[t] * water;\n            flow += water;\n        }\n\
    \        return flow;\n    }\n\n    std::vector<Cost> slope(u32 s, u32 t) {\n\
    \        assert(s < size());\n        assert(t < size());\n        Cap flow{};\n\
    \        std::vector<Cost> res;\n        while (dijkstra(s, t)) {\n          \
    \  updatePotential();\n            Cap water{flush(s, t)};\n            for (u32\
    \ i{} ; i < water ; i++) {\n                res.emplace_back(mcf_);\n        \
    \        mcf_ += potential_[t];\n                flow++;\n            }\n    \
    \    }\n        res.emplace_back(mcf_);\n        return res;\n    }\n\n    struct\
    \ Line {\n        Cap dn{}, up{};\n        Cost slope{};\n        Line() = default;\n\
    \        Line(Cap dn, Cap up, Cost slope) : dn{dn}, up{up}, slope{slope} {}\n\
    \    };\n    std::vector<Line> slopeACL(u32 s, u32 t) {\n        assert(s < size());\n\
    \        assert(t < size()); \n        Cap flow{};\n        std::vector<Line>\
    \ res;\n        while (dijkstra(s, t)) {\n            updatePotential();\n   \
    \         Cap water{flush(s, t)};\n            mcf_ += potential_[t] * water;\n\
    \            res.emplace_back(flow, flow + water, potential_[t]);\n          \
    \  flow += water;\n        }\n        return res;\n    }\n\n    Cost minCost()\
    \ const noexcept {\n        return mcf_;\n    }\n};\n\n} // namespace zawa\n#line\
    \ 5 \"Test/AtCoder/abc247_g.test.cpp\"\n\nint main() {\n    using namespace zawa;\n\
    \    SetFastIO();\n    int n; std::cin >> n;\n    const int m{150};\n    SuccessiveShortestPath<int,\
    \ long long> mcf(2 * m + 2, 2 * m + n);\n    int source{2 * m}, sink{2 * m + 1};\n\
    \    const long long INF{(long long)1e9};\n    for (int i{} ; i < m ; i++) {\n\
    \        mcf.addEdge(source, i, 1, 0);\n        mcf.addEdge(m + i, sink, 1, 0);\n\
    \    }\n    for (int i{} ; i < n ; i++) {\n        int a, b, c; std::cin >> a\
    \ >> b >> c;\n        a--; b--;\n        c = INF - c;\n        mcf.addEdge(a,\
    \ m + b, 1, c);\n    }\n\n    auto info{mcf.slope(source, sink)};\n    int k{(int)info.size()\
    \ - 1};\n    std::cout << k << '\\n';\n    for (int i{1} ; i <= k ; i++) {\n \
    \       long long ans{INF * (long long)i - info[i]};\n        std::cout << ans\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc247/tasks/abc247_g\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Flow/SuccessiveShortestPath.hpp\"\
    \n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n    int n; std::cin\
    \ >> n;\n    const int m{150};\n    SuccessiveShortestPath<int, long long> mcf(2\
    \ * m + 2, 2 * m + n);\n    int source{2 * m}, sink{2 * m + 1};\n    const long\
    \ long INF{(long long)1e9};\n    for (int i{} ; i < m ; i++) {\n        mcf.addEdge(source,\
    \ i, 1, 0);\n        mcf.addEdge(m + i, sink, 1, 0);\n    }\n    for (int i{}\
    \ ; i < n ; i++) {\n        int a, b, c; std::cin >> a >> b >> c;\n        a--;\
    \ b--;\n        c = INF - c;\n        mcf.addEdge(a, m + b, 1, c);\n    }\n\n\
    \    auto info{mcf.slope(source, sink)};\n    int k{(int)info.size() - 1};\n \
    \   std::cout << k << '\\n';\n    for (int i{1} ; i <= k ; i++) {\n        long\
    \ long ans{INF * (long long)i - info[i]};\n        std::cout << ans << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Flow/SuccessiveShortestPath.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc247_g.test.cpp
  requiredBy: []
  timestamp: '2024-01-04 02:51:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc247_g.test.cpp
layout: document
title: ABC247-G Dream Team
---

最大重み二部マッチング問題に帰着するので、最小費用流で解ける。最大化問題を最小化問題に変換するためにコストを $-1$ 倍する。

この時に負のコストが出現する。この時の対処法をいくつか

1. 下駄を履かせる

使う辺の数が固定の時に有効。

2. ポテンシャルの初期値の計算にベルマンフォード法やDAG上のDPを適用する

特に、グラフがDAGの時は計算量が悪化していないことに注目

3. 流量固定時の変形

良くわかっていない。蟻本p205
