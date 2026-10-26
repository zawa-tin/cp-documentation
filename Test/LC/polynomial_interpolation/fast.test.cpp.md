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
    title: "\u591A\u70B9\u8A55\u4FA1(Multipoint Evaluation)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialInterpolationFast.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593 $O(N\\log^2N)$"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialProducts.hpp
    title: "\u6B21\u6570\u306E\u7DCF\u548C\u304C\u6291\u3048\u3089\u308C\u3066\u3044\
      \u308B\u591A\u9805\u5F0F\u306E\u5217\u306E\u7DCF\u7A4D"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/SubproductTree.hpp
    title: Subproduct Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_interpolation
    links:
    - https://judge.yosupo.jp/problem/polynomial_interpolation
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n#include \"../../../Src/FPS/FPSNTTFriendly.hpp\"\n#include \"../../../Src/FPS/PolynomialInterpolationFast.hpp\"\
    \n#include \"atcoder/modint\"\nusing mint=atcoder::modint998244353;\nusing fps=zawa::FPSNTTFriendly<mint::mod()>;\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\nint main() {\n \
    \   cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N;\n\
    \    cin >> N;\n    vector<mint> xs(N),ys(N);\n    for (mint& a : xs) {\n    \
    \    int v;\n        cin >> v;\n        a=mint::raw(v);\n    }\n    for (mint&\
    \ a : ys) {\n        int v;\n        cin >> v;\n        a=mint::raw(v);\n    }\n\
    \    cout << zawa::PolynomialInterpolationFast(move(xs),move(ys)) << '\\n';\n\
    }\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/PolynomialInterpolationFast.hpp
  - Src/FPS/MultipointEvaluation.hpp
  - Src/FPS/SubproductTree.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  - Src/FPS/PolynomialProducts.hpp
  isVerificationFile: true
  path: Test/LC/polynomial_interpolation/fast.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 13:52:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/polynomial_interpolation/fast.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/polynomial_interpolation/fast.test.cpp
- /verify/Test/LC/polynomial_interpolation/fast.test.cpp.html
title: Test/LC/polynomial_interpolation/fast.test.cpp
---
