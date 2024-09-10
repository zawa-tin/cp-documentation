---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Components/IncrementalSCC.hpp
    title: offline incremental SCC
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    - https://codeforces.com/contest/1989/submission/269109756
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/scc.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * Educational Codeforces Round 167 - F Simultaneous Coloring\n * https://codeforces.com/contest/1989/submission/269109756\n\
    \ */\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\"\
    \n#include \"../../Src/Graph/Components/IncrementalSCC.hpp\"\n\nusing namespace\
    \ zawa;\n\nvoid solve() {\n    SetFastIO();\n    int N, M, Q;\n    std::cin >>\
    \ N >> M >> Q;\n    IncrementalSCC g(N + M);\n    for (int i{} ; i < Q ; i++)\
    \ {\n        int x, y;\n        std::cin >> x >> y;\n        x--;\n        y =\
    \ y - 1 + N;\n        char c;\n        std::cin >> c;\n        if (c == 'R') {\n\
    \            g.addEdge(y, x);\n        }\n        else if (c == 'B') {\n     \
    \       g.addEdge(x, y);\n        }\n    }\n    std::vector<std::vector<std::pair<u32,\
    \ u32>>> event(Q);\n    auto T{g.build()};\n    for (int i{} ; i < Q ; i++) {\n\
    \        if (T.same(i)) {\n            event[T[i]].emplace_back(g.getEdge(i));\n\
    \        }\n    }\n    DisjointSetUnion dsu(N + M);\n    long long cur{};\n  \
    \  auto cost{[&](u32 s) -> long long {\n        return s == 1u ? 0 : (long long)s\
    \ * s;\n    }};\n    for (int i{} ; i < Q ; i++) {\n        for (auto [u, v] :\
    \ event[i]) {\n            if (dsu.same(u, v)) {\n                continue;\n\
    \            }\n            cur -= cost(dsu.size(u));\n            cur -= cost(dsu.size(v));\n\
    \            dsu.merge(u, v);\n            cur += cost(dsu.size(u));\n       \
    \ }\n        std::cout << cur << '\\n';\n    }\n}\n\nint main() {\n#ifdef ONLINE_JUDGE\n\
    \    solve();\n#else\n    std::cout << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  - Src/Graph/Components/IncrementalSCC.hpp
  isVerificationFile: true
  path: Test/CF/ECR167-F.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 02:41:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/CF/ECR167-F.test.cpp
layout: document
redirect_from:
- /verify/Test/CF/ECR167-F.test.cpp
- /verify/Test/CF/ECR167-F.test.cpp.html
title: Test/CF/ECR167-F.test.cpp
---
