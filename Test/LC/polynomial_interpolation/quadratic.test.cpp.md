---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialInterpolation.hpp
    title: Src/FPS/PolynomialInterpolation.hpp
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
    - https://judge.yosupo.jp/problem/polynomial_interpolation
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/internal_math.hpp:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../../Src/FPS/PolynomialInterpolation.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint = atcoder::modint998244353;\n\n#include <iostream>\n#include <vector>\n\
    \nusing namespace zawa;\nusing namespace std;\n\nint main() {\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    // int N;\n    // cin >>\
    \ N;\n    // vector<mint> xs(N), ys(N);\n    // for (int i = 0 ; i < N ; i++)\
    \ {\n    //     int x;\n    //     cin >> x;\n    //     xs[i] = mint::raw(x);\n\
    \    // }\n    // for (int i = 0 ; i < N ; i++) {\n    //     int y;\n    // \
    \    cin >> y;\n    //     ys[i] = mint::raw(y);\n    // }\n    // auto ans =\
    \ PolynomialInterpolation(xs, ys);\n    // for (int i = 0 ; i < N ; i++)\n   \
    \ //     cout << ans[i].val() << (i + 1 == N ? '\\n' : ' ');\n    cout << \"Hello\
    \ World\\n\";\n}\n"
  dependsOn:
  - Src/FPS/PolynomialInterpolation.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/polynomial_interpolation/quadratic.test.cpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/polynomial_interpolation/quadratic.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/polynomial_interpolation/quadratic.test.cpp
- /verify/Test/LC/polynomial_interpolation/quadratic.test.cpp.html
title: Test/LC/polynomial_interpolation/quadratic.test.cpp
---
