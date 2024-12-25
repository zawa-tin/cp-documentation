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
    PROBLEM: https://judge.yosupo.jp/problem/incremental_scc
    links:
    - https://judge.yosupo.jp/problem/incremental_scc
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/scc.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/incremental_scc\"\n\n#include\
    \ \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Components/IncrementalSCC.hpp\"\
    \n#include \"../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp\" \n\
    #include \"atcoder/modint\"\n\n#include <iostream>\n#include <vector>\n\nusing\
    \ namespace zawa;\nusing mint = atcoder::modint998244353;\n\nint main() {\n  \
    \  SetFastIO();\n    int N, M;\n    std::cin >> N >> M;\n    std::vector<mint>\
    \ X(N);\n    for (auto& x : X) {\n        int v;\n        std::cin >> v;\n   \
    \     x = mint::raw(v);\n    }\n    IncrementalSCC g(N);\n    for (int _{} ; _\
    \ < M ; _++) {\n        int u, v;\n        std::cin >> u >> v;\n        g.addEdge(u,\
    \ v);\n    }\n    std::vector<std::vector<int>> event(M);\n    auto T{g.build()};\n\
    \    for (int i{} ; i < M ; i++) {\n        if (T[i] == T.invalid()) continue;\n\
    \        event[T[i]].push_back(i);\n    }\n    DisjointSetUnion dsu(N);\n    mint\
    \ ans{}; \n    for (int i{} ; i < M ; i++) {\n        for (auto j : event[i])\
    \ {\n            auto [u, v]{g.getEdge(j)};\n            u = dsu.leader(u);\n\
    \            v = dsu.leader(v);\n            if (u == v) continue;\n         \
    \   ans += X[u] * X[v];\n            mint next{X[u] + X[v]};\n            dsu.merge(u,\
    \ v);\n            X[dsu.leader(u)] = next;\n        }\n        std::cout << ans.val()\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Components/IncrementalSCC.hpp
  - Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp
  isVerificationFile: true
  path: Test/LC/incremental_scc.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 02:41:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/incremental_scc.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/incremental_scc.test.cpp
- /verify/Test/LC/incremental_scc.test.cpp.html
title: Test/LC/incremental_scc.test.cpp
---
