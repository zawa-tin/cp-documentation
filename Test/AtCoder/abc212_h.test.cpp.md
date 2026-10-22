---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/BitwiseXORConvolution.hpp
    title: Bitwise XOR Convolution
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
    - https://atcoder.jp/contests/abc212/submissions/80252043
    - https://atcoder.jp/contests/abc212/tasks/abc212_h
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc212/tasks/abc212_h\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 212 H - Counting\n * https://atcoder.jp/contests/abc212/submissions/80252043\n\
    \ */\n#include \"../../Src/Sequence/BitwiseXORConvolution.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint=atcoder::modint998244353;\n#include <iostream>\n#include <vector>\n\
    using namespace std;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    const int M=16;\n    int N,K;\n    cin >> N\
    \ >> K;\n    vector<mint> A(1<<M);\n    for (int i = 0 ; i < K ; i++) {\n    \
    \    int a;\n        cin >> a;\n        A[a]++;\n    }\n    zawa::FastWalshHadamardTransform(A);\n\
    \    for (int i = 0 ; i < (1<<M) ; i++) {\n        if (A[i]==mint::raw(1))\n \
    \           A[i]=N+1;\n        else\n            A[i]=(A[i].pow(N+1)-1)/(A[i]-1);\n\
    \    }\n    zawa::FastWalshHadamardTransform(A);\n    const mint inv=mint::raw(2).pow(M).inv();\n\
    \    mint ans=0;\n    for (int i = 1 ; i < (1<<M) ; i++) \n        ans+=A[i]*inv;\n\
    \    cout << ans.val() << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n  \
    \  cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/BitwiseXORConvolution.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc212_h.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 16:38:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc212_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc212_h.test.cpp
- /verify/Test/AtCoder/abc212_h.test.cpp.html
title: Test/AtCoder/abc212_h.test.cpp
---
