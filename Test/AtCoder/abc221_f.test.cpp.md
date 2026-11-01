---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/TreeCenters.hpp
    title: "\u6728\u306E\u76F4\u5F84\u306B\u307E\u3064\u308F\u308BUtility\u30AF\u30E9\
      \u30B9"
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
    - https://atcoder.jp/contests/abc221/submissions/80544216
    - https://atcoder.jp/contests/abc221/tasks/abc221_f
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc221/tasks/abc221_f\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 221 F - Diameter set\n * https://atcoder.jp/contests/abc221/submissions/80544216\n\
    \ */\n#include \"../../Src/Graph/Tree/TreeCenters.hpp\"\n#include \"atcoder/modint\"\
    \n#include <iostream>\n#include <ranges>\n#include <vector>\nusing namespace std;\n\
    using mint=atcoder::modint998244353;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n \
    \   vector<vector<int>> G(N);\n    for (int i = 0 ; i < N - 1 ; i++) {\n     \
    \   int u,v;\n        cin >> u >> v;\n        u--; v--;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n    zawa::TreeCenters<int,int> cent{move(G)};\n\
    \    auto dfs=[&](auto dfs,int v)->int {\n        int res=0;\n        res+=cent.farthest(v).second==cent.diameterLength();\n\
    \        for (int x : cent[v]|views::keys)\n            res+=dfs(dfs,x);\n   \
    \     return res;\n    };\n    vector<mint> dp(3);\n    dp[0]=1;\n    for (int\
    \ v : cent[cent.root()]|views::keys) {\n        int cnt=dfs(dfs,v);\n        dp[2]+=(dp[2]+dp[1])*cnt;\
    \ \n        dp[1]+=dp[0]*cnt;\n    }\n    cout << dp[2].val() << '\\n';\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/TreeCenters.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc221_f.test.cpp
  requiredBy: []
  timestamp: '2026-11-01 20:19:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc221_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc221_f.test.cpp
- /verify/Test/AtCoder/abc221_f.test.cpp.html
title: Test/AtCoder/abc221_f.test.cpp
---
