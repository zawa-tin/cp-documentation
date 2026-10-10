---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/EnumeratePowerSums.hpp
    title: "$(\\sum_{j=1}^{N} A_{j}^{i})$ \u3092 $i=0,1,\\dots,K$ \u306B\u3064\u3044\
      \u3066\u5217\u6319\u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialProducts.hpp
    title: "\u6B21\u6570\u306E\u7DCF\u548C\u304C\u6291\u3048\u3089\u308C\u3066\u3044\
      \u308B\u591A\u9805\u5F0F\u306E\u5217\u306E\u7DCF\u7A4D"
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
    - https://atcoder.jp/contests/fps-24/submissions/79892982
    - https://atcoder.jp/contests/fps-24/tasks/fps_24_q
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/fps-24/tasks/fps_24_q\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * FPS24\u984C\
    \ Q - \u30B5\u30A4\u30B3\u30ED\n * https://atcoder.jp/contests/fps-24/submissions/79892982\n\
    \ */\n#include \"../../Src/FPS/FPSNTTFriendly.hpp\"\n#include \"../../Src/FPS/EnumeratePowerSums.hpp\"\
    \n#include <iostream>\nusing namespace std;\nusing mint=atcoder::modint998244353;\n\
    using fps=zawa::FPSNTTFriendly<mint::mod()>;\nint main() {\n#ifdef ATCODER\n \
    \   int N,M,K;\n    cin >> N >> M >> K;\n    std::vector<mint> fac(K+1,1),ifac(K+1);\n\
    \    for (int i = 1 ; i <= K ; i++)\n        fac[i]=fac[i-1]*mint{i};\n    ifac[K]=fac[K].inv();\n\
    \    for (int i = K ; i >= 1 ; i--)\n        ifac[i-1]=ifac[i]*mint{i};\n    std::vector<mint>\
    \ A(N),B(M);\n    for (mint& a : A) {\n        int x;\n        cin >> x;\n   \
    \     a=mint::raw(x);\n    }\n    for (mint& a : B) {\n        int x;\n      \
    \  cin >> x;\n        a=mint::raw(x);\n    }\n    auto a=zawa::EnumeratePowerSums<fps>(A,K),b=zawa::EnumeratePowerSums<fps>(B,K);\n\
    \    for  (int i = 0 ; i <= K ; i++) {\n        a[i]*=ifac[i];\n        b[i]*=ifac[i];\n\
    \    }\n    auto c=(a*b).resized(K+1);\n    const mint inv=(mint{N}*mint{M}).inv();\n\
    \    for (int k = 1 ; k <= K ; k++)\n        cout << (c[k]*fac[k]*inv).val() <<\
    \ '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n\
    #endif\n}\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/EnumeratePowerSums.hpp
  - Src/FPS/PolynomialProducts.hpp
  isVerificationFile: true
  path: Test/AtCoder/fps24_q.test.cpp
  requiredBy: []
  timestamp: '2026-10-10 14:28:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/fps24_q.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/fps24_q.test.cpp
- /verify/Test/AtCoder/fps24_q.test.cpp.html
title: Test/AtCoder/fps24_q.test.cpp
---
