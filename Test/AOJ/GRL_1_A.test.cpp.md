---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/Chmin.hpp
    title: Chmin
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Test/AOJ/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/Chmin.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T1, class T2>\nbool Chmin(T1& fr, const\
    \ T2& bk) {\n    return fr > bk and (fr = bk, true);\n}\n\n} // namespace zawa\n\
    #line 5 \"Test/AOJ/GRL_1_A.test.cpp\"\n\n#include <iostream>\n#include <vector>\n\
    #include <utility>\n#include <queue>\nusing namespace zawa;\n\nint main() {\n\
    \    usize N, M; std::cin >> N >> M;\n    u32 r; std::cin >> r;\n    std::vector<std::vector<std::pair<u32,\
    \ u32>>> G(N);\n    for (u32 _{} ; _ < M ; _++) {\n        u32 u, v, c; std::cin\
    \ >> u >> v >> c;\n        G[u].emplace_back(v, c);\n    }\n\n    const u64 inf{(1LL\
    \ << 60)};\n    std::vector<u64> dist(N, inf);\n    dist[r] = 0;\n    using qt\
    \ = std::pair<u64, u32>;\n    std::priority_queue<qt, std::vector<qt>, std::greater<qt>>\
    \ que;\n    que.emplace(0LL, r);\n    while (que.size()) {\n        auto [d, v]{\
    \ que.top() };\n        que.pop();\n        if (dist[v] < d) continue;\n     \
    \   for (auto [x, w] : G[v]) {\n            if (Chmin(dist[x], d + w)) {\n   \
    \             que.emplace(dist[x], x);\n            }\n        }\n    }\n\n  \
    \  for (auto d : dist) {\n        if (d == inf) std::cout << \"INF\" << std::endl;\n\
    \        else std::cout << d << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/Chmin.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include <queue>\n\
    using namespace zawa;\n\nint main() {\n    usize N, M; std::cin >> N >> M;\n \
    \   u32 r; std::cin >> r;\n    std::vector<std::vector<std::pair<u32, u32>>> G(N);\n\
    \    for (u32 _{} ; _ < M ; _++) {\n        u32 u, v, c; std::cin >> u >> v >>\
    \ c;\n        G[u].emplace_back(v, c);\n    }\n\n    const u64 inf{(1LL << 60)};\n\
    \    std::vector<u64> dist(N, inf);\n    dist[r] = 0;\n    using qt = std::pair<u64,\
    \ u32>;\n    std::priority_queue<qt, std::vector<qt>, std::greater<qt>> que;\n\
    \    que.emplace(0LL, r);\n    while (que.size()) {\n        auto [d, v]{ que.top()\
    \ };\n        que.pop();\n        if (dist[v] < d) continue;\n        for (auto\
    \ [x, w] : G[v]) {\n            if (Chmin(dist[x], d + w)) {\n               \
    \ que.emplace(dist[x], x);\n            }\n        }\n    }\n\n    for (auto d\
    \ : dist) {\n        if (d == inf) std::cout << \"INF\" << std::endl;\n      \
    \  else std::cout << d << std::endl;\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/Chmin.hpp
  isVerificationFile: true
  path: Test/AOJ/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-08-04 19:12:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/GRL_1_A.test.cpp
- /verify/Test/AOJ/GRL_1_A.test.cpp.html
title: Test/AOJ/GRL_1_A.test.cpp
---
