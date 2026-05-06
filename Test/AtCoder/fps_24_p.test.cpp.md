---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/DivisionOfPolynomials.hpp
    title: Src/FPS/DivisionOfPolynomials.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/MultipointEvaluation.hpp
    title: Src/FPS/MultipointEvaluation.hpp
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
    - https://atcoder.jp/contests/fps-24/submissions/75551782
    - https://atcoder.jp/contests/fps-24/tasks/fps_24_p
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/fps-24/tasks/fps_24_p\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * FPS24\u984C\
    \ P - \u30DC\u30FC\u30EB\n * https://atcoder.jp/contests/fps-24/submissions/75551782\n\
    \ */\n\n#include \"../../Src/FPS/FPSNTTFriendly.hpp\"\n#include \"../../Src/FPS/MultipointEvaluation.hpp\"\
    \nusing mint = atcoder::modint998244353;\nusing fps = zawa::FPSNTTFriendly<mint::mod()>;\n\
    \n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N,M,K;\n    cin >> N >> M >> K;\n    std::vector<mint>\
    \ F(N+1,1),invF(N+1);\n    for (int i = 1 ; i <= N ; i++)\n        F[i] = F[i-1]*mint::raw(i);\n\
    \    invF[N] = F[N].inv();\n    for (int i = N ; i >= 1 ; i--)\n        invF[i-1]\
    \ = invF[i]*mint::raw(i);\n    fps f(N+1);\n    for (int k = 0 ; k <= std::min(N,K)\
    \ ; k++)\n        f[N-k] = F[N]*invF[k]*invF[N-k];\n    std::vector<mint> x(M);\n\
    \    iota(x.begin(),x.end(),mint{1});\n    auto ans = zawa::MultipointEvaluation(f,x);\n\
    \    for (int i = 0 ; i < M ; i++)\n        cout << ans[i].val() << '\\n';\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/MultipointEvaluation.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  isVerificationFile: true
  path: Test/AtCoder/fps_24_p.test.cpp
  requiredBy: []
  timestamp: '2026-05-06 19:26:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/fps_24_p.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/fps_24_p.test.cpp
- /verify/Test/AtCoder/fps_24_p.test.cpp.html
title: Test/AtCoder/fps_24_p.test.cpp
---
