---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/arc197/submissions/65531577
    - https://atcoder.jp/contests/arc197/tasks/arc197_d
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc197/tasks/arc197_d\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Regular Contest 197 (Div. 2) D - Ancestor Relation\n * https://atcoder.jp/contests/arc197/submissions/65531577\n\
    \ */\n\n#include \"../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n#include \"atcoder/modint\"\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\n\
    \n#include <iostream>\n#include <ranges>\nint N, A[400][400];\nmint solve(std::vector<int>\
    \ a) {\n    if (a.empty()) return 1;\n    std::vector<bool> all(N);\n    for (int\
    \ v : a) {\n        all[v] = true;\n        for (int x : a) if (A[v][x] == 0)\
    \ all[v] = false;\n    }\n    if (a[0] == 0 and !all[0]) return 0;\n    int cnt\
    \ = std::ranges::count(all, true);\n    if (cnt == 0) return 0;\n    if (a[0]\
    \ == 0) cnt--;\n    DisjointSetUnion dsu(N);\n    for (int v : a) if (!all[v])\
    \ for (int x : a) if (!all[x]) {\n        if (A[v][x]) dsu.merge(v, x);\n    }\n\
    \    auto gs = dsu.enumerate<int>();\n    mint res = 1;\n    for (int i = 1 ;\
    \ i <= cnt ; i++) res *= mint::raw(i);\n    std::vector<bool> next(N);\n    for\
    \ (int v : a) if (!all[v]) next[v] = true;\n    for (const std::vector<int>& g\
    \ : gs) if (next[g[0]]) {\n        res *= solve(g);\n    }\n    return res;\n\
    }\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int T;\n    std::cin >> T;\n    while\
    \ (T--) {\n        std::cin >> N;\n        for (int i = 0 ; i < N ; i++) {\n \
    \           for (int j = 0 ; j < N ; j++) std::cin >> A[i][j];\n        }\n  \
    \      std::vector<int> a(N);\n        std::iota(a.begin(), a.end(), 0);\n   \
    \     std::cout << solve(a).val() << '\\n';\n    }\n#else\n    std::cout << \"\
    Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc197_d.test.cpp
  requiredBy: []
  timestamp: '2025-05-05 21:42:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc197_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc197_d.test.cpp
- /verify/Test/AtCoder/arc197_d.test.cpp.html
title: Test/AtCoder/arc197_d.test.cpp
---
