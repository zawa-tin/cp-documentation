---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Flow/BurnBury.hpp
    title: Src/Graph/Flow/BurnBury.hpp
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
    - https://atcoder.jp/contests/typical90/submissions/49664834
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/typical90_an.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line 2\
    \ \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n\
    #include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    \nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Graph/Flow/BurnBury.hpp\"\n\n#line 2 \"\
    Src/Utility/U32Pair.hpp\"\n\n#line 4 \"Src/Utility/U32Pair.hpp\"\n\n#include <functional>\n\
    #line 7 \"Src/Utility/U32Pair.hpp\"\n\nnamespace zawa {\n\nclass U32Pair {\nprivate:\n\
    \    static constexpr u32 SHIFT{32};\n    static constexpr u32 MASK{static_cast<u32>((1LL\
    \ << SHIFT) - 1)};\n    u64 value_{};\npublic:\n    constexpr U32Pair() {}\n \
    \   constexpr U32Pair(u32 first, u32 second) {\n        value_ = (static_cast<u64>(first)\
    \ << SHIFT) | second;\n    }\n    constexpr u32 first() const noexcept {\n   \
    \     return static_cast<u32>(value_ >> SHIFT);\n    }\n    constexpr u32 second()\
    \ const noexcept {\n        return static_cast<u32>(value_ & MASK);\n    }\n \
    \   constexpr u64 combined() const noexcept {\n        return value_;\n    }\n\
    \    constexpr U32Pair& operator=(const U32Pair& rhs) {\n        value_ = rhs.value_;\n\
    \        return *this;\n    }\n    friend constexpr bool operator==(const U32Pair&\
    \ lhs, const U32Pair& rhs) {\n        return lhs.value_ == rhs.value_;\n    }\n\
    \    friend constexpr bool operator!=(const U32Pair& lhs, const U32Pair& rhs)\
    \ {\n        return lhs.value_ != rhs.value_;\n    }\n    friend constexpr bool\
    \ operator<(const U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_\
    \ < rhs.value_;\n    }\n    friend constexpr bool operator<=(const U32Pair& lhs,\
    \ const U32Pair& rhs) {\n        return lhs.value_ <= rhs.value_;\n    }\n   \
    \ friend constexpr bool operator>(const U32Pair& lhs, const U32Pair& rhs) {\n\
    \        return lhs.value_ > rhs.value_;\n    }\n    friend constexpr bool operator>=(const\
    \ U32Pair& lhs, const U32Pair& rhs) {\n        return lhs.value_ >= rhs.value_;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const U32Pair& pair)\
    \ {\n        os << '(' << pair.first() << ',' << pair.second() << ')';\n     \
    \   return os;\n    }\n};\n\nstruct U32PairHash {\n    usize operator()(const\
    \ U32Pair& pair) const noexcept {\n        return std::hash<u64>{}(pair.combined());\n\
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Graph/Flow/Dinic.hpp\"\n\n#line\
    \ 5 \"Src/Graph/Flow/Dinic.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <limits>\n#include <type_traits>\n#include <vector>\n#include <queue>\n\
    \nnamespace zawa {\n\ntemplate <class Cap> \nclass Dinic {\nprivate:\n    static_assert(std::is_signed_v<Cap>,\
    \ \"Cap must be signed\");\n    usize n_{}, m_{};\n    static constexpr u32 invalid()\
    \ noexcept {\n        return std::numeric_limits<u32>::max();\n    }\npublic:\n\
    \    inline usize size() const noexcept {\n        return n_;\n    }\n    inline\
    \ usize edgeNumber() const noexcept {\n        return m_;\n    }\nprivate:\n \
    \   struct Edge {\n        u32 to{}, rev{};\n        Cap residual{};\n       \
    \ Edge() = default;\n        Edge(u32 to, u32 rev, const Cap& residual) \n   \
    \         : to{to}, rev{rev}, residual{residual} {}\n    };\n\n    std::vector<std::vector<Edge>>\
    \ g_;\n    std::vector<U32Pair> edges_;\n    std::vector<u32> label_, cur_;\n\n\
    \    bool dualStep(u32 s, u32 t) {\n        std::fill(label_.begin(), label_.end(),\
    \ invalid());\n        label_[s] = 0;\n        std::queue<u32> queue{ { s } };\n\
    \        while (queue.size()) {\n            u32 v{queue.front()};\n         \
    \   queue.pop();\n            for (const Edge& e : g_[v]) if (e.residual > 0)\
    \ {\n                if (label_[e.to] > label_[v] + 1) {\n                   \
    \ label_[e.to] = label_[v] + 1;\n                    if (e.to == t) return true;\n\
    \                    queue.emplace(e.to);\n                }\n            }\n\
    \        }\n        return false;\n    }\n\n    bool admissible(u32 v, const Edge&\
    \ e) const noexcept {\n        return e.residual > 0 and label_[v] + 1 == label_[e.to];\n\
    \    }\n\n    inline void flow(Edge& e, Cap f) {\n        e.residual -= f;\n \
    \       g_[e.to][e.rev].residual += f;\n    }\n\n    Cap dfs(u32 v, u32 t, Cap\
    \ up) {\n        if (v == t) return up;\n        Cap res{};\n        for (u32&\
    \ i{cur_[v]} ; i < g_[v].size() ; i++) {\n            if (!admissible(v, g_[v][i]))\
    \ continue;\n            Cap f{dfs(g_[v][i].to, t, std::min(g_[v][i].residual,\
    \ up - res))};\n            if (f == 0) continue;\n            flow(g_[v][i],\
    \ f);\n            res += f;\n            if (res == up) return res;\n       \
    \ }\n        return res;\n    }\n\n    Cap primalStep(u32 s, u32 t) {\n      \
    \  std::fill(cur_.begin(), cur_.end(), 0u);\n        cur_[t] = g_[t].size();\n\
    \        Cap res{};\n        while (true) {\n            Cap f{dfs(s, t, std::numeric_limits<Cap>::max())};\n\
    \            if (f == 0) break;\n            res += f;\n        }\n        return\
    \ res;\n    }\n\n    const Edge& edge(u32 i) const noexcept {\n        return\
    \ g_[edges_[i].first()][edges_[i].second()];\n    }\n    const Edge& reverse(u32\
    \ i) const noexcept {\n        const Edge& e{edge(i)};\n        return g_[e.to][e.rev];\n\
    \    }\n\npublic:\n    Dinic() = default;\n    Dinic(u32 n, u32 m = 0u) \n   \
    \     : n_{n}, m_{m}, g_(n), edges_{}, label_(n), cur_(n) {\n        g_.shrink_to_fit();\n\
    \        label_.shrink_to_fit();\n        cur_.shrink_to_fit();\n        edges_.reserve(m);\n\
    \    }\n\n    u32 addEdge(u32 u, u32 v, const Cap& cap) {\n        assert(u <\
    \ size());\n        assert(v < size());\n        u32 id{static_cast<u32>(g_[u].size())};\n\
    \        u32 revId{u == v ? id + 1 : static_cast<u32>(g_[v].size())};\n      \
    \  u32 res{static_cast<u32>(edges_.size())};\n        edges_.emplace_back(u, id);\n\
    \        g_[u].emplace_back(v, revId, cap);\n        g_[v].emplace_back(u, id,\
    \ Cap{});\n        m_++;\n        return res;\n    }\n\n    const Cap& flowed(u32\
    \ id) const noexcept {\n        assert(id < edgeNumber());\n        return reverse(id).residual;\n\
    \    }\n    const Cap& residual(u32 id) const noexcept {\n        assert(id <\
    \ edgeNumber());\n        return edge(id).residual;\n    }\n    const Cap& capacity(u32\
    \ id) const noexcept {\n        assert(id < edgeNumber());\n        return edge(id).residual\
    \ + reverse(id).residual;\n    }\n    const u32& from(u32 id) const noexcept {\n\
    \        assert(id < edgeNumber());\n        return edges_[id].first();\n    }\n\
    \    const u32& to(u32 id) const noexcept {\n        assert(id < edgeNumber());\n\
    \        return edge(id).to;\n    }\n\n    Cap flow(u32 s, u32 t) {\n        assert(s\
    \ < size());\n        assert(t < size()); \n        Cap res{};\n        while\
    \ (dualStep(s, t)) {\n            res += primalStep(s, t);\n        }\n      \
    \  return res;\n    }\n\n    std::vector<bool> cut(u32 s) {\n        std::vector<bool>\
    \ res(size());\n        res[s] = true;\n        std::queue<u32> queue{ { s } };\n\
    \        while (queue.size()) {\n            u32 v{queue.front()};\n         \
    \   queue.pop();\n            for (const auto& e : g_[v]) if (e.residual > 0 and\
    \ !res[e.to]) {\n                res[e.to] = true;\n                queue.emplace(e.to);\n\
    \            }\n        }\n        return res;\n    }    \n};\n\n} // namespace\
    \ zawa\n#line 6 \"Src/Graph/Flow/BurnBury.hpp\"\n\n#line 8 \"Src/Graph/Flow/BurnBury.hpp\"\
    \n#include <unordered_map>\n#line 10 \"Src/Graph/Flow/BurnBury.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class Cost>\nclass BurnBury {\nprivate:\n    usize n_{},\
    \ source_{}, sink_{}, graphsize_{};\n    Dinic<Cost> mf_{}; \n    Cost common_{};\n\
    \    std::unordered_map<U32Pair, Cost, U32PairHash> edge_{};\n    void addEdge(u32\
    \ u, u32 v, const Cost& cost) {\n        edge_[U32Pair{ u, v }] += cost;\n   \
    \ }\n    constexpr usize size() const noexcept {\n        return n_;\n    }\n\
    public:\n    BurnBury() = default;    \n    BurnBury(usize n) : n_{n}, source_{n},\
    \ sink_{n + 1}, graphsize_{n + 2} {\n        assert(n);\n    }\n    void constant(const\
    \ Cost& cost) {\n        common_ += cost;\n    }\n    void func1(u32 v, const\
    \ std::vector<Cost>& cost) {\n        assert(v < size());\n        assert(cost.size()\
    \ == (1u << 1));\n        if (cost[0] <= cost[1]) {\n            addEdge(source_,\
    \ v, cost[1] - cost[0]);\n            constant(cost[0]);\n        }\n        else\
    \ {\n            addEdge(v, sink_, cost[0] - cost[1]);\n            constant(cost[1]);\n\
    \        }\n    }\n    void func2(u32 u, u32 v, const std::vector<Cost>& cost)\
    \ {\n        assert(u < size());\n        assert(v < size());\n        assert(cost.size()\
    \ == (1u << 2));\n        constant(cost[0]);\n        func1(u, { Cost{0}, cost[2]\
    \ - cost[0] });\n        func1(v, { Cost{0}, cost[3] - cost[2] });\n        assert(cost[1]\
    \ + cost[2] - cost[0] - cost[3] >= 0);\n        addEdge(u, v, cost[1] + cost[2]\
    \ - cost[0] - cost[3]);\n    }\n    void func3(u32 u, u32 v, u32 w, const std::vector<Cost>&\
    \ cost) {\n        assert(u < size());\n        assert(v < size());\n        assert(w\
    \ < size());\n        assert(cost.size() == (1u << 3));\n        Cost p{cost[1]\
    \ + cost[3] + cost[5] + cost[6] - (cost[1] + cost[2] + cost[4] + cost[7])};\n\
    \        if (p >= 0) {\n            constant(cost[0]);\n            func1(u, Cost{0},\
    \ cost[5] - cost[1]);\n            func1(v, Cost{0}, cost[6] - cost[4]);\n   \
    \         func1(w, Cost{0}, cost[3] - cost[2]);\n            // 01\u4EE5\u5916\
    \u306F0\n            func2(u, v, { Cost{0}, cost[2] + cost[4] - cost[0] - cost[6],\
    \ Cost{0}, Cost{0} });\n            func2(v, w, { Cost{0}, cost[1] + cost[2] -\
    \ cost[0] - cost[3], Cost{0}, Cost{0} });\n            func2(w, u, { Cost{0},\
    \ cost[1] + cost[4] - cost[0] - cost[5], Cost{0}, Cost{0} });\n            //\
    \ 111\u3068\u3059\u308B\u3068-p\n            addEdge(u, graphsize_, p);\n    \
    \        addEdge(v, graphsize_, p);\n            addEdge(w, graphsize_, p);\n\
    \            addEdge(graphsize_, sink_, p);\n            constant(-p);\n     \
    \       graphsize_++;\n        }\n        else {\n            constant(cost[7]);\n\
    \            func1(u, { cost[2] - cost[6], Cost{0} });\n            func1(v, {\
    \ cost[1] - cost[3], Cost{0} });\n            func1(w, { cost[4] - cost[5], Cost{0}\
    \ });\n            // 10\u306E\u6642\n            func2(u, v, { Cost{0}, Cost{0},\
    \ cost[3] + cost[5] - cost[1] - cost[7], Cost{0} });\n            func2(v, w,\
    \ { Cost{0}, Cost{0}, cost[5] + cost[6] - cost[4] - cost[7], Cost{0} });\n   \
    \         func2(w, u, { Cost{0}, Cost{0}, cost[3] + cost[6] - cost[2] - cost[7],\
    \ Cost{0} });\n            // 000\n            addEdge(source_, graphsize_, -p);\n\
    \            addEdge(graphsize_, u, -p);\n            addEdge(graphsize_, v, -p);\n\
    \            addEdge(graphsize_, w, -p);\n            constant(p);\n         \
    \   graphsize_++;\n        }\n    }\n\n    [[nodiscard]] Cost build() {\n    \
    \    mf_ = Dinic<Cost>(graphsize_);\n        for (const auto& [uv, cost] : edge_)\
    \ {\n            mf_.addEdge(uv.first(), uv.second(), cost);\n        }\n    \
    \    Cost res{mf_.flow(source_, sink_)};\n        res += common_;\n        return\
    \ res;\n    }\n\n    [[nodiscard]] std::vector<u32> assign() {\n        auto tos{mf_.cut(source_)},\
    \ tot{mf_.cut(sink_)};\n        std::vector<u32> res(size());\n        for (u32\
    \ i{} ; i < size() ; i++) {\n            if (!tos[i] and !tot[i]) res[i] = 2;\n\
    \            else if (tos[i]) res[i] = 0;\n            else res[i] = 1;\n    \
    \    }\n        return res;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/Manual/typical90_an.test.cpp\"\
    \n\n#line 7 \"Test/Manual/typical90_an.test.cpp\"\n\n/*\n * \u7AF6\u30D7\u30ED\
    \u5178\u578B90\u554F-040 Get More Money\n * https://atcoder.jp/contests/typical90/submissions/49664834\n\
    \ */\n\nvoid solve() {\n    using namespace zawa;\n    SetFastIO();\n    int n;\
    \ std::cin >> n;\n    BurnBury<long long> solver(n);\n    long long w; std::cin\
    \ >> w;\n    for (int i{} ; i < n ; i++) {\n        long long a; std::cin >> a;\n\
    \        solver.func1(i, { 0LL, -(a - w) });\n    }\n    const long long INF{(long\
    \ long)1e12};\n    for (int i{} ; i < n ; i++) {\n        int k; std::cin >> k;\n\
    \        for (int _{} ; _ < k ; _++) {\n            int c; std::cin >> c;\n  \
    \          c--;\n            solver.func2(i, c, { 0LL, INF, 0LL, 0LL });\n   \
    \     }\n    }\n    long long ans{solver.build()};\n    ans *= -1;\n    std::cout\
    \ << ans << '\\n';\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n \
    \   std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Flow/BurnBury.hpp\"\
    \n\n#include <iostream>\n\n/*\n * \u7AF6\u30D7\u30ED\u5178\u578B90\u554F-040 Get\
    \ More Money\n * https://atcoder.jp/contests/typical90/submissions/49664834\n\
    \ */\n\nvoid solve() {\n    using namespace zawa;\n    SetFastIO();\n    int n;\
    \ std::cin >> n;\n    BurnBury<long long> solver(n);\n    long long w; std::cin\
    \ >> w;\n    for (int i{} ; i < n ; i++) {\n        long long a; std::cin >> a;\n\
    \        solver.func1(i, { 0LL, -(a - w) });\n    }\n    const long long INF{(long\
    \ long)1e12};\n    for (int i{} ; i < n ; i++) {\n        int k; std::cin >> k;\n\
    \        for (int _{} ; _ < k ; _++) {\n            int c; std::cin >> c;\n  \
    \          c--;\n            solver.func2(i, c, { 0LL, INF, 0LL, 0LL });\n   \
    \     }\n    }\n    long long ans{solver.build()};\n    ans *= -1;\n    std::cout\
    \ << ans << '\\n';\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n \
    \   std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Flow/BurnBury.hpp
  - Src/Utility/U32Pair.hpp
  - Src/Graph/Flow/Dinic.hpp
  isVerificationFile: true
  path: Test/Manual/typical90_an.test.cpp
  requiredBy: []
  timestamp: '2024-01-26 17:02:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/typical90_an.test.cpp
layout: document
title: "\u7AF6\u30D7\u30ED\u5178\u578B90\u554F-040 Get More Money"
---

燃やす埋める

$x_{i} =$ 家 $i$ に入る時 $1$ 、家 $i$ に入らない時 $0$ とする。

$x_{i}$ の割り当て方によって以下の様に利得が発生する。

- $x_{i} = 1$ ならば、 $W - A_{i}$ 円の得
- $x_{i} = 0$ かつ $x_{c_{ij}} = 1$ ならば、 $-\infty$ 円の得(このような割り当ての禁止)
- $x_{1}, x_{2}, \dots, x_{n}$ に $01$ を上手く割り当てて得られるお金の総和を最大化したい

最小カットに帰着したいので、全て $-1$ 倍することで最小化問題を考えることにする。

- $x_{i} = 1$ ならば、 $-(W - A_{i})$ 円の損
- $x_{i} = 0$ かつ $x_{c_{ij}} = 1$ ならば、 $\infty$ 円の損(このような割り当ての禁止)
- $x_{1}, x_{2}, \dots, x_{n}$ に $01$ を上手く割り当てて損失するお金の総和を最小化したい

二番目の条件が $2$ 変数関数になっているので、劣モジュラ性を持つかを確認する必要がある。

| $i \\ c_{ij}$ | 0 | 1 |
| ---- | ---- | ---- |
| 0 | 0 | $\infty$ |
| 1 | 0 | 0 |


$i\ \lt\ j, x_{i} = 0, x_{j} = 1$ の数を $\text{cnt}$ として $S = (x_{1}, x_{2}, \dots, x_{n})$ $T = (x_{1}', x_{2}', \dots, x_{n}')$

$S\cap T, S\cup T$ との $\text{cnt}$ の変化を考えると、 $\text{cnt}(S) + \text{cnt}(T) = \text{cnt}(S\cap T) + \text{cnt}(S\cup T)$ なので劣モジュラ性が成り立っている。