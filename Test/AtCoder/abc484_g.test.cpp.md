---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/PowersetConstruction.hpp
    title: "Powerset Construction (NFA\u3092DFA\u306B\u5909\u63DB\u3059\u308B)"
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
    - https://atcoder.jp/contests/abc484/submissions/80932848
    - https://atcoder.jp/contests/abc484/tasks/abc484_g
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint.hpp:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc484/tasks/abc484_g\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 484 G - Wildcard Construction\n * https://atcoder.jp/contests/abc484/submissions/80932848\n\
    \ */\n#include \"../../Src/Sequence/PowersetConstruction.hpp\"\nusing namespace\
    \ zawa;\n#include \"atcoder/modint.hpp\"\nusing mint=atcoder::modint998244353;\n\
    #include <iostream>\n#include <string>\n#include <vector>\nusing namespace std;\n\
    int main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    string S,X,Y;\n    cin >> S >> X >> Y;\n    const int g1=ssize(X)+ssize(Y),g2=g1+1;\n\
    \    PowersetConstruction<int,int> nfa(ssize(X)+ssize(Y)+2,2,g1,vector<int>{g1,g2});\n\
    \    auto addEdge=[&](int from,int to,char c){\n        if (c!='1')\n        \
    \    nfa.addTransition(from,to,0);\n        if (c!='0')\n            nfa.addTransition(from,to,1);\n\
    \    };\n    addEdge(g1,0,X[0]);\n    for (int i = 1 ; i < ssize(X) ; i++)\n \
    \       addEdge(i-1,i,X[i]);\n    nfa.addEpsilonTransition(ssize(X)-1,g1);\n \
    \   addEdge(g1,ssize(X),Y[0]);\n    for (int i = 1 ; i < ssize(Y) ; i++)\n   \
    \     addEdge(ssize(X)+i-1,ssize(X)+i,Y[i]);\n    nfa.addEpsilonTransition(ssize(X)+ssize(Y)-1,g2);\
    \ \n    addEdge(g2,0,X[0]);\n    auto [g,ok]=nfa.build();\n    std::vector<mint>\
    \ dp(g.size());\n    dp[0]=1;\n    for (char c : S) {\n        std::vector<mint>\
    \ nxt(g.size());\n        for (int i = 0 ; i < ssize(g) ; i++) {\n           \
    \ if (c!='1' and g[i][0]!=ssize(g))\n                nxt[g[i][0]]+=dp[i];\n  \
    \          if (c!='0' and g[i][1]!=ssize(g))\n                nxt[g[i][1]]+=dp[i];\n\
    \        }\n        dp=move(nxt);\n    }\n    mint ans=0;\n    for (int i = 0\
    \ ; i < ssize(g) ; i++)\n        if (ok[i])\n            ans+=dp[i];\n    cout\
    \ << ans.val() << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n    cout <<\
    \ a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/PowersetConstruction.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc484_g.test.cpp
  requiredBy: []
  timestamp: '2026-11-19 16:34:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc484_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc484_g.test.cpp
- /verify/Test/AtCoder/abc484_g.test.cpp.html
title: Test/AtCoder/abc484_g.test.cpp
---
