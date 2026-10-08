---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp
    title: "\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306B\u95A2\u3059\u308B\u30E1\
      \u30E2"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.tuna.camp/contests/73d937b6-89c4-4931-929c-f0b820567799/problems/master0918_matrix/statement
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://judge.tuna.camp/contests/73d937b6-89c4-4931-929c-f0b820567799/problems/master0918_matrix/statement\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp\"\
    \n#include <iostream>\n#include <vector>\nusing namespace std;\nint main() {\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n    // cin.tie(0);\n\
    \    // cout.tie(0);\n    // ios::sync_with_stdio(0);\n    // int N,M;\n    //\
    \ cin >> N >> M;\n    // vector<vector<int>> G(2*N);\n    // for (int i = 0 ;\
    \ i < M ; i++) {\n    //     int r,c,x;\n    //     cin >> r >> c >> x;\n    //\
    \     r--; c--;\n    //     G[r].push_back(N+c);\n    //     G[N+c].push_back(r);\n\
    \    // }\n    // vector<int> col(2*N,-1);\n    // int n=0;\n    // auto dfs=[&](auto\
    \ dfs,int v) -> void {\n    //     col[v]=n;\n    //     for (int x : G[v])\n\
    \    //         if (col[x] == -1)\n    //             dfs(dfs,x);\n    // }; \n\
    \    // for (int i = 0 ; i < 2*N ; i++)\n    //     if (col[i] == -1) {\n    //\
    \         dfs(dfs,i);\n    //         n++;\n    //     }\n    // using mint =\
    \ atcoder::modint998244353;\n    // auto stir=zawa::StirlingNumberSecondKindFixedN(n);\n\
    \    // mint ans=0,fac=1;\n    // for (int i=1 ; i<=n ; i++) {\n    //     fac*=mint::raw(i);\n\
    \    //     ans+=stir[i]*fac;\n    // }\n    // cout << ans.val() << '\\n';\n\
    }\n"
  dependsOn:
  - Src/Combinatorics/StirlingNumberSecondKindFixedN.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/TUNA/HUPC2025-K.test.cpp
  requiredBy: []
  timestamp: '2026-10-01 22:30:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/TUNA/HUPC2025-K.test.cpp
layout: document
redirect_from:
- /verify/Test/TUNA/HUPC2025-K.test.cpp
- /verify/Test/TUNA/HUPC2025-K.test.cpp.html
title: Test/TUNA/HUPC2025-K.test.cpp
---
