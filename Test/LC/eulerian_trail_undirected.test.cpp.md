---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/EulerianTrail.hpp
    title: "Eulerian Trail (\u30AA\u30A4\u30E9\u30FC\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_undirected
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_undirected
  bundledCode: "#line 1 \"Test/LC/eulerian_trail_undirected.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\n\n#line 2 \"\
    Src/Graph/EulerianTrail.hpp\"\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <optional>\n#include <utility>\n#include <vector>\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 10 \"Src/Graph/EulerianTrail.hpp\"\n\nnamespace zawa\
    \ {\n\n// first: \u9802\u70B9\u5217, second: \u8FBA\u756A\u53F7\u5217\ntemplate\
    \ <class T>\nstd::optional<std::pair<std::vector<T>, std::vector<usize>>> EulerianTrail(usize\
    \ n, const std::vector<std::pair<T, T>>& edges, bool directed) {\n    std::vector<std::vector<std::pair<T,\
    \ usize>>> g(n);\n    for (usize i = 0 ; auto [u, v] : edges) {\n        assert(u\
    \ < n);\n        assert(v < n);\n        g[u].push_back({v, i});\n        if (!directed)\
    \ g[v].push_back({u, i});\n        i++;\n    }\n    std::vector<bool> used(edges.size());\n\
    \    std::vector<usize> cur(n), es;\n    std::vector<T> vs;\n    es.reserve(edges.size());\n\
    \    vs.reserve(edges.size() + 1);\n    auto dfs = [&](auto dfs, const T v) ->\
    \ void {\n        while (cur[v] < g[v].size()) {\n            auto [x, i] = g[v][cur[v]++];\n\
    \            if (!used[i]) {\n                used[i] = true;\n              \
    \  dfs(dfs, x);\n                es.push_back(i);\n                vs.push_back(v);\n\
    \            }\n        }\n    };\n    usize st = edges.size() ? edges[0].first\
    \ : 0, go = st;\n    if (directed) {\n        std::vector<usize> deg(n);\n   \
    \     for (auto [u, v] : edges) {\n            deg[u]++;\n            deg[v]--;\n\
    \        }\n        const usize p1 = 1, m1 = static_cast<usize>(-1);\n       \
    \ bool fnst = false, fngo = false;\n        for (usize i = 0 ; i < n ; i++) {\n\
    \            if (deg[i] == p1) {\n                if (fnst) return std::nullopt;\n\
    \                fnst = true;\n                st = i;\n            }\n      \
    \      else if (deg[i] == m1) {\n                if (fngo) return std::nullopt;\n\
    \                fngo = true;\n                go = i;\n            }\n      \
    \      else if (deg[i]) return std::nullopt;\n        }\n    }\n    else {\n \
    \       usize cntOdd = 0;\n        for (usize i = 0 ; i < n ; i++) if (g[i].size()\
    \ & 1) {\n            if (cntOdd++) go = i;\n            else st = i;\n      \
    \  }\n        if (cntOdd != 0 and cntOdd != 2) return std::nullopt;\n    }\n \
    \   if (n) {\n        dfs(dfs, st);\n        std::ranges::reverse(vs);\n     \
    \   vs.push_back(go);\n        std::ranges::reverse(es);\n    }\n    if (edges.size()\
    \ != es.size()) return std::nullopt;\n    return std::make_pair(vs, es);\n}\n\n\
    } // namespace zawa\n#line 4 \"Test/LC/eulerian_trail_undirected.test.cpp\"\n\
    using namespace zawa;\n\n#include <iostream>\n#line 9 \"Test/LC/eulerian_trail_undirected.test.cpp\"\
    \n\nvoid solve() {\n    int N, M;\n    std::cin >> N >> M;\n    std::vector<std::pair<int,\
    \ int>> E(M);\n    for (auto& [u, v] : E) std::cin >> u >> v;\n    auto ans =\
    \ EulerianTrail(N, E, false);\n    if (ans) {\n        std::cout << \"Yes\\n\"\
    ;\n        auto [vs, es] = std::move(*ans);\n        for (int i = 0 ; i < std::ssize(vs)\
    \ ; i++) std::cout << vs[i] << (i + 1 == std::ssize(vs) ? \"\" : \" \");\n   \
    \     std::cout << '\\n';\n        for (int i = 0 ; i < std::ssize(es) ; i++)\
    \ std::cout << es[i] << (i + 1 == std::ssize(es) ? \"\" : \" \");\n        std::cout\
    \ << '\\n';\n    }\n    else {\n        std::cout << \"No\\n\";\n    }\n}\n\n\
    int main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int T;\n    std::cin >> T;\n    while (T--) {\n        solve();\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_undirected\"\
    \n\n#include \"../../Src/Graph/EulerianTrail.hpp\"\nusing namespace zawa;\n\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\nvoid solve() {\n\
    \    int N, M;\n    std::cin >> N >> M;\n    std::vector<std::pair<int, int>>\
    \ E(M);\n    for (auto& [u, v] : E) std::cin >> u >> v;\n    auto ans = EulerianTrail(N,\
    \ E, false);\n    if (ans) {\n        std::cout << \"Yes\\n\";\n        auto [vs,\
    \ es] = std::move(*ans);\n        for (int i = 0 ; i < std::ssize(vs) ; i++) std::cout\
    \ << vs[i] << (i + 1 == std::ssize(vs) ? \"\" : \" \");\n        std::cout <<\
    \ '\\n';\n        for (int i = 0 ; i < std::ssize(es) ; i++) std::cout << es[i]\
    \ << (i + 1 == std::ssize(es) ? \"\" : \" \");\n        std::cout << '\\n';\n\
    \    }\n    else {\n        std::cout << \"No\\n\";\n    }\n}\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int T;\n    std::cin >> T;\n    while (T--) {\n        solve();\n    }\n\
    }\n"
  dependsOn:
  - Src/Graph/EulerianTrail.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/eulerian_trail_undirected.test.cpp
  requiredBy: []
  timestamp: '2025-05-27 19:35:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/eulerian_trail_undirected.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/eulerian_trail_undirected.test.cpp
- /verify/Test/LC/eulerian_trail_undirected.test.cpp.html
title: Test/LC/eulerian_trail_undirected.test.cpp
---
