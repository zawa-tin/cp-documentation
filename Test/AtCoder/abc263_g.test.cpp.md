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
    PROBLEM: https://atcoder.jp/contests/abc263/tasks/abc263_g
    links:
    - https://atcoder.jp/contests/abc263/tasks/abc263_g
  bundledCode: "#line 1 \"Test/AtCoder/abc263_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc263/tasks/abc263_g\"\
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
    \ zawa\n#line 5 \"Test/AtCoder/abc263_g.test.cpp\"\n\n#line 8 \"Test/AtCoder/abc263_g.test.cpp\"\
    \n\nbool prime(int a) {\n    for (long long i{2} ; i * i <= (long long)a ; i++)\
    \ {\n        if (a % i == 0) return false;\n    }\n    return a != 1;\n}\n\nint\
    \ main() {\n    using namespace zawa;\n    SetFastIO();\n    \n    int n; std::cin\
    \ >> n;\n    std::vector<int> a(n), b(n);\n    for (int i{} ; i < n ; i++) {\n\
    \        std::cin >> a[i] >> b[i];\n    }\n    Dinic<long long> mf(2 * n + 2);\n\
    \    int source{2 * n}, sink{2 * n + 1};\n    const long long INF{(long long)1e13};\n\
    \    for (int i{} ; i < n ; i++) {\n        if (a[i] % 2 == 0) {\n           \
    \ mf.addEdge(source, i, b[i]);\n        }\n        else {\n            if (a[i]\
    \ == 1) continue;\n            mf.addEdge(i + n, sink, b[i]);\n        }\n   \
    \ }\n    for (int i{} ; i < n ; i++) {\n        if (a[i] % 2 == 1) continue;\n\
    \        for (int j{} ; j < n ; j++) {\n            if (a[j] % 2 == 0) continue;\n\
    \            if (a[j] == 1) continue;\n            if (!prime(a[i] + a[j])) continue;\n\
    \            mf.addEdge(i, n + j, INF);\n        }\n    }\n    long long ans{mf.flow(source,\
    \ sink)};\n    for (int i{} ; i < n ; i++) if (a[i] == 1) {\n        long long\
    \ cnt{b[i]};\n        int id{(int)mf.addEdge(n + i, sink, cnt)};\n        for\
    \ (int j{} ; j < n ; j++) if (a[j] % 2 == 0) {\n            if (!prime(a[i] +\
    \ a[j])) continue;\n            mf.addEdge(j, n + i, INF);\n        }\n      \
    \  ans += mf.flow(source, sink);\n        cnt -= mf.flowed(id);\n        ans +=\
    \ cnt >> 1;\n        break;\n    }\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc263/tasks/abc263_g\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Flow/Dinic.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nbool prime(int a) {\n    for (long\
    \ long i{2} ; i * i <= (long long)a ; i++) {\n        if (a % i == 0) return false;\n\
    \    }\n    return a != 1;\n}\n\nint main() {\n    using namespace zawa;\n   \
    \ SetFastIO();\n    \n    int n; std::cin >> n;\n    std::vector<int> a(n), b(n);\n\
    \    for (int i{} ; i < n ; i++) {\n        std::cin >> a[i] >> b[i];\n    }\n\
    \    Dinic<long long> mf(2 * n + 2);\n    int source{2 * n}, sink{2 * n + 1};\n\
    \    const long long INF{(long long)1e13};\n    for (int i{} ; i < n ; i++) {\n\
    \        if (a[i] % 2 == 0) {\n            mf.addEdge(source, i, b[i]);\n    \
    \    }\n        else {\n            if (a[i] == 1) continue;\n            mf.addEdge(i\
    \ + n, sink, b[i]);\n        }\n    }\n    for (int i{} ; i < n ; i++) {\n   \
    \     if (a[i] % 2 == 1) continue;\n        for (int j{} ; j < n ; j++) {\n  \
    \          if (a[j] % 2 == 0) continue;\n            if (a[j] == 1) continue;\n\
    \            if (!prime(a[i] + a[j])) continue;\n            mf.addEdge(i, n +\
    \ j, INF);\n        }\n    }\n    long long ans{mf.flow(source, sink)};\n    for\
    \ (int i{} ; i < n ; i++) if (a[i] == 1) {\n        long long cnt{b[i]};\n   \
    \     int id{(int)mf.addEdge(n + i, sink, cnt)};\n        for (int j{} ; j < n\
    \ ; j++) if (a[j] % 2 == 0) {\n            if (!prime(a[i] + a[j])) continue;\n\
    \            mf.addEdge(j, n + i, INF);\n        }\n        ans += mf.flow(source,\
    \ sink);\n        cnt -= mf.flowed(id);\n        ans += cnt >> 1;\n        break;\n\
    \    }\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Flow/Dinic.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc263_g.test.cpp
  requiredBy: []
  timestamp: '2023-12-29 17:56:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc263_g.test.cpp
layout: document
title: ABC263-G Erasing Prime Pairs
---

$2$ 以外の素数は奇数であり、２つの整数の和で表そうとすると必ず「奇数 + 偶数」の形になる。よって2を考慮しなければ二部グラフ上の最大マッチングに帰着する。

$2$ を考慮する。$2$ を２つの正整数の和で表す方法は「1 + 1」しかありえない。反対に $A_{i} = 1$ なる整数は同じ種類の整数とマッチできるので自由度が高い。

以下のようにする。

1. 1以外の整数を考慮した状態で最大フロー $f$ (及び最大フローから誘導される残余ネットワーク $G_{f}$ )を求める
2. $G_{f}$ に整数1を考慮した辺を追加し、もう一回最大フローを求める(1 -> 1という辺は追加しない。二部グラフで無くなってしまう)
3. 残った1の数がわかるので、1同士でマッチさせる。

例えば、 $\\{ 1, 1, 2, 4 \\}$ の時は $(1, 1)$ のペアを作るのをできるだけ後回しにして、1を別の整数とくっつけて上げる。一般の整数の集合でそのようにして損をすることはありえない

$1$ は自分同士でくっつくことができるので、 $\\{ 1, 1, 2, 5 \\}$ とかだと $(1, 2)$ より $(2, 5)$ を優先するべきだ。(これも一般の整数の集合で言える)

マッチングを最大化する際は、マッチングできる相手が少ないものから考慮していくとうまく貪欲法を構築・証明できることが多いようだ。

参考にしました: [最大マッチングを貪欲する問題の証明典型テク](https://snuke.hatenablog.com/entry/2019/01/04/004133)
