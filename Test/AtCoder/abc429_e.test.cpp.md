---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/SeparatedFamilySet.hpp
    title: "2\u8981\u7D20\u306E\u5206\u96E2\u3092\u7DB2\u7F85\u3059\u308B\u30C6\u30AF\
      \u30CB\u30C3\u30AF"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc429/tasks/abc429_e
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc429_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc429/tasks/abc429_e\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#line 2 \"Src/Utility/SeparatedFamilySet.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n#include <concepts>\n#include <ranges>\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 9 \"Src/Utility/SeparatedFamilySet.hpp\"\n\nnamespace\
    \ zawa {\n\n// https://noshi91.hatenablog.com/entry/2024/05/31/012055\n// \u5411\
    \u304D\u306E\u3064\u3044\u305F\u5206\u5272\nstd::vector<std::vector<bool>> SeparatedFamilySet(usize\
    \ U) {\n    const usize d = [&]() {\n        for (usize i = 1 ; ; i++) {\n   \
    \         usize max = 1;\n            for (usize j = 0 ; j < (i / 2) ; j++) {\n\
    \                max *= i - j;\n                max /= j + 1;\n            }\n\
    \            if (max >= U) return i;\n        }\n        return U;\n    }();\n\
    \    std::vector res(d, std::vector<bool>(U));\n    std::vector<u8> in(d);\n \
    \   std::fill(in.rbegin(), in.rbegin() + d / 2, true);\n    for (usize idx = 0\
    \ ; idx < U ; idx++) {\n        for (usize i = 0 ; i < d ; i++) if (in[i]) {\n\
    \            res[i][idx] = true;\n        }\n        std::ranges::next_permutation(in);\n\
    \    }\n    return res;\n}\n\n} // namespace zawa\n#line 4 \"Test/AtCoder/abc429_e.test.cpp\"\
    \n#include <iostream>\n#line 7 \"Test/AtCoder/abc429_e.test.cpp\"\n#include <string>\n\
    using namespace std;\nvoid solve() {\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ g(N);\n    for (int i = 0 ; i < M ; i++) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        a--; b--;\n        g[a].push_back(b);\n        g[b].push_back(a);\n\
    \    }\n    string S;\n    cin >> S;\n    vector<int> safe, danger;\n    for (int\
    \ i = 0 ; i < N ; i++) {\n        if (S[i] == 'S')\n            safe.push_back(i);\n\
    \        else\n            danger.push_back(i);\n    }\n    const int INF = (int)1e9;\n\
    \    auto bfs = [&](const vector<bool>& use) -> vector<int> {\n        vector<int>\
    \ dist(N, INF), que;\n        for (int i = 0 ; i < ssize(safe) ; i++)\n      \
    \      if (use[i]) {\n                dist[safe[i]] = 0;\n                que.push_back(safe[i]);\n\
    \            }\n        for (int t = 0 ; t < ssize(que) ; t++) {\n           \
    \ const int v = que[t];\n            for (int x : g[v])\n                if (dist[x]\
    \ == INF) {\n                    dist[x] = dist[v] + 1;\n                    que.push_back(x);\n\
    \                }\n        }\n        return dist;\n    };\n    vector<int> ans(N,\
    \ INF);\n    for (vector<bool> sep : zawa::SeparatedFamilySet(safe.size())) {\n\
    \        vector<int> da = bfs(sep);\n        for (int i = 0 ; i < ssize(sep) ;\
    \ i++)\n            sep[i] = !sep[i];\n        vector<int> db = bfs(sep);\n  \
    \      for (int i : danger)\n            ans[i] = min(ans[i], da[i] + db[i]);\n\
    \    }\n    for (int i : danger)\n        cout << ans[i] << '\\n';\n}\nint main()\
    \ {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n#ifdef ATCODER\n\
    \    solve();\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc429/tasks/abc429_e\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#include \"../../Src/Utility/SeparatedFamilySet.hpp\"\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <string>\nusing namespace std;\n\
    void solve() {\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> g(N);\n\
    \    for (int i = 0 ; i < M ; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        a--; b--;\n        g[a].push_back(b);\n        g[b].push_back(a);\n \
    \   }\n    string S;\n    cin >> S;\n    vector<int> safe, danger;\n    for (int\
    \ i = 0 ; i < N ; i++) {\n        if (S[i] == 'S')\n            safe.push_back(i);\n\
    \        else\n            danger.push_back(i);\n    }\n    const int INF = (int)1e9;\n\
    \    auto bfs = [&](const vector<bool>& use) -> vector<int> {\n        vector<int>\
    \ dist(N, INF), que;\n        for (int i = 0 ; i < ssize(safe) ; i++)\n      \
    \      if (use[i]) {\n                dist[safe[i]] = 0;\n                que.push_back(safe[i]);\n\
    \            }\n        for (int t = 0 ; t < ssize(que) ; t++) {\n           \
    \ const int v = que[t];\n            for (int x : g[v])\n                if (dist[x]\
    \ == INF) {\n                    dist[x] = dist[v] + 1;\n                    que.push_back(x);\n\
    \                }\n        }\n        return dist;\n    };\n    vector<int> ans(N,\
    \ INF);\n    for (vector<bool> sep : zawa::SeparatedFamilySet(safe.size())) {\n\
    \        vector<int> da = bfs(sep);\n        for (int i = 0 ; i < ssize(sep) ;\
    \ i++)\n            sep[i] = !sep[i];\n        vector<int> db = bfs(sep);\n  \
    \      for (int i : danger)\n            ans[i] = min(ans[i], da[i] + db[i]);\n\
    \    }\n    for (int i : danger)\n        cout << ans[i] << '\\n';\n}\nint main()\
    \ {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n#ifdef ATCODER\n\
    \    solve();\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Utility/SeparatedFamilySet.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc429_e.test.cpp
  requiredBy: []
  timestamp: '2025-10-26 18:56:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc429_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc429_e.test.cpp
- /verify/Test/AtCoder/abc429_e.test.cpp.html
title: Test/AtCoder/abc429_e.test.cpp
---
