---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialTaylorShift.hpp
    title: Polynomial Taylor Shift
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
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \n\n#include \"../../Src/FPS/PolynomialTaylorShift.hpp\"\n\n#include \"atcoder/modint\"\
    \n#include \"atcoder/convolution\"\nusing mint = atcoder::modint998244353;\n\n\
    #include <iostream>\n#include <vector>\n\nint main() {\n    std::cin.tie(nullptr);\
    \    \n    std::cout.tie(nullptr);    \n    std::ios::sync_with_stdio(false);\n\
    \    int N, c;\n    std::cin >> N >> c;\n    std::vector<mint> A(N);\n    for\
    \ (int i = 0 ; i < N ; i++) {\n        int a;\n        std::cin >> a;\n      \
    \  A[i] = mint::raw(a);\n    }\n    auto B = zawa::PolynomialTaylorShift(A, c,\
    \ atcoder::convolution<mint>);\n    for (int i = 0 ; i < N ; i++) std::cout <<\
    \ B[i].val() << (i + 1 == N ? '\\n' : ' ');\n}\n"
  dependsOn:
  - Src/FPS/PolynomialTaylorShift.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/polynomial_taylor_shift.test.cpp
  requiredBy: []
  timestamp: '2025-05-09 01:17:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/polynomial_taylor_shift.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/polynomial_taylor_shift.test.cpp
- /verify/Test/LC/polynomial_taylor_shift.test.cpp.html
title: Test/LC/polynomial_taylor_shift.test.cpp
---
