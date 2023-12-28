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
    PROBLEM: https://atcoder.jp/contests/abc193/tasks/abc193_f
    links:
    - https://atcoder.jp/contests/abc193/tasks/abc193_f
  bundledCode: "#line 1 \"Test/AtCoder/abc193_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc193/tasks/abc193_f\"\
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
    \ zawa\n#line 5 \"Test/AtCoder/abc193_f.test.cpp\"\n\nint main() {\n    using\
    \ namespace zawa;\n    SetFastIO();\n    int n; std::cin >> n;\n    std::vector<std::string>\
    \ S(n);\n    for (auto& s : S) std::cin >> s;\n    Dinic<int> mf(n * n + 2);\n\
    \    int source{n * n}, sink{n * n + 1};\n    constexpr int dx[4]{ 1, 0, -1, 0\
    \ };\n    constexpr int dy[4]{ 0, 1, 0, -1 };\n    auto in{[&](int x, int y) ->\
    \ bool {\n        return 0 <= x and x < n and 0 <= y and y < n;\n    }};\n   \
    \ auto f{[&](int x, int y) -> int {\n        return x * n + y;\n    }};\n    constexpr\
    \ int INF{10000};\n    int good{};\n    for (int x{} ; x < n ; x++) {\n      \
    \  for (int y{} ; y < n ; y++) {\n            for (int d{} ; d < 4 ; d++) {\n\
    \                int nx{x + dx[d]}, ny{y + dy[d]};\n                if (!in(nx,\
    \ ny)) continue;\n                mf.addEdge(f(x, y), f(nx, ny), 1);\n       \
    \         good++;\n            }\n            if ((x + y) & 1) {\n           \
    \     mf.addEdge(source, f(x, y), S[x][y] == 'B' ? INF : 0);\n               \
    \ mf.addEdge(f(x, y), sink, S[x][y] == 'W' ? INF : 0);\n            }\n      \
    \      else {\n                mf.addEdge(source, f(x, y), S[x][y] == 'W' ? INF\
    \ : 0);\n                mf.addEdge(f(x, y), sink, S[x][y] == 'B' ? INF : 0);\n\
    \            }\n        }\n    }\n    good /= 2;\n    int ans{good - mf.flow(source,\
    \ sink)};\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc193/tasks/abc193_f\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Flow/Dinic.hpp\"\
    \n\nint main() {\n    using namespace zawa;\n    SetFastIO();\n    int n; std::cin\
    \ >> n;\n    std::vector<std::string> S(n);\n    for (auto& s : S) std::cin >>\
    \ s;\n    Dinic<int> mf(n * n + 2);\n    int source{n * n}, sink{n * n + 1};\n\
    \    constexpr int dx[4]{ 1, 0, -1, 0 };\n    constexpr int dy[4]{ 0, 1, 0, -1\
    \ };\n    auto in{[&](int x, int y) -> bool {\n        return 0 <= x and x < n\
    \ and 0 <= y and y < n;\n    }};\n    auto f{[&](int x, int y) -> int {\n    \
    \    return x * n + y;\n    }};\n    constexpr int INF{10000};\n    int good{};\n\
    \    for (int x{} ; x < n ; x++) {\n        for (int y{} ; y < n ; y++) {\n  \
    \          for (int d{} ; d < 4 ; d++) {\n                int nx{x + dx[d]}, ny{y\
    \ + dy[d]};\n                if (!in(nx, ny)) continue;\n                mf.addEdge(f(x,\
    \ y), f(nx, ny), 1);\n                good++;\n            }\n            if ((x\
    \ + y) & 1) {\n                mf.addEdge(source, f(x, y), S[x][y] == 'B' ? INF\
    \ : 0);\n                mf.addEdge(f(x, y), sink, S[x][y] == 'W' ? INF : 0);\n\
    \            }\n            else {\n                mf.addEdge(source, f(x, y),\
    \ S[x][y] == 'W' ? INF : 0);\n                mf.addEdge(f(x, y), sink, S[x][y]\
    \ == 'B' ? INF : 0);\n            }\n        }\n    }\n    good /= 2;\n    int\
    \ ans{good - mf.flow(source, sink)};\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Flow/Dinic.hpp
  - Src/Utility/U32Pair.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc193_f.test.cpp
  requiredBy: []
  timestamp: '2023-12-28 22:17:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc193_f.test.cpp
layout: document
title: ABC193-F Zebraness
---

燃やす埋める。いくつかのポイントを残しておく

## しまうま度(得)の最大化 -> しまうまじゃない度(損)の最小化 と言い換える

理想のしまうまから最小カット容量(損としてあり得る最小)を引いてあげる。

理想のしまうまは明らかに市松模様に塗られた時である。(その時のしまうま度は $2\times N\times (N - 1)$ の様だ)

## ?で無いマスに対しても白に変更するか黒に変更するかを考慮する。

?であるマスに対しての割当では無く、全てのマスに対して白か黒かを割り当てる問題と考えた方が後々の思考コストが下がるようだ。

この場合、「白マスを黒マスに割り当てる」や「黒マスを白マスに割り当てる」は「やってはいけない」割当であり、そのような割当には $\infity$ の損とする
- 禁止を無限の損と言い換える良く見るやつ

## マスの変更自体に損は無い

「マス $(i, j)$ とマス $(i + 1, j)$ が同じ色の時、 1損する」みたいな2つの特定の割当によって発生するコストをsource -> マスやマス -> sinkの容量に記述してはいけない(頭が壊れる)

## グリッドグラフは市松で考える

ネットワークの構築を試みる。例として右左に隣り合う?のマスに対してどのように辺が張られるかを考える。
- source -(0)-> 左マス (左マスを白にすると0の損)
- 左マス -(0)-> sink (左マスを黒にすると0の損)
- source -(0)-> 右マス (右マスを白にすると0の損)
- 右マス -(0)-> sink (右マスを黒にすると0の損)

ここまでは良いが、「左のマスと右のマスが同じ色の時に1の損」が上手く記述できない。
- 例えば左マス -(1)-> 右マスとしてもこの辺を切らせることはできない。両方白or両方黒のカットがコスト0でできている

ここで、グリッドグラフの4近傍は二部グラフであることを思い出すと、市松の片方のsourceとsinkを反転させてあげれば良い
- source -(0)-> 左マス (左マスを白にすると0の損)
- 左マス -(0)-> sink (左マスを黒にすると0の損)
- source -(0)-> 右マス (右マスを**黒**にすると0の損)
- 右マス -(0)-> sink (右マスを**白**にすると0の損)
- 右マス -(1) -> 左マス (左マスを白、右マスを白にすると1の損)
- 左マス -(1)-> 右マス (左マスを黒、右マスを黒にすると1の損)
