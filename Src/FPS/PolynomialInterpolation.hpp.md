---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc137_f.test.cpp
    title: Test/AtCoder/abc137_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/polynomial_interpolation/quadratic.test.cpp
    title: Test/LC/polynomial_interpolation/quadratic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/internal_math.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"atcoder/internal_math.hpp\"\
    \n\n#include <cassert>\n#include <concepts>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class mint>\nstd::vector<mint> PolynomialInterpolation(const\
    \ std::vector<mint>& xs, const std::vector<mint>& ys) {\n    assert(xs.size());\n\
    \    assert(xs.size() == ys.size());\n    assert(atcoder::internal::is_prime_constexpr(mint::mod()));\n\
    \    std::vector<mint> dp(1, 1); \n    for (mint x : xs) {\n        std::vector<mint>\
    \ next(dp.size() + 1);\n        for (usize i = 0 ; i < dp.size() ; i++) {\n  \
    \          next[i + 1] += dp[i];\n            next[i] += dp[i] * -x;\n       \
    \ }\n        dp = std::move(next);\n    }\n    std::vector<mint> ans(xs.size());\n\
    \    for (usize idx = 0 ; mint x : xs) {\n        // num -> modosu dp\n      \
    \  std::vector<mint> num(xs.size());  \n        if (x == mint{0}) {\n        \
    \    for (usize i = 0 ; i < num.size() ; i++)\n                num[i] = dp[i +\
    \ 1];\n        }\n        else {\n            const mint ix = mint{1} / x;\n \
    \           num[0] = -dp[0] * ix;\n            for (usize i = 1 ; i < num.size()\
    \ ; i++) \n                num[i] = (num[i - 1] - dp[i]) * ix;\n        }\n  \
    \      // den -> nene chang!\n        mint den = 1;\n        for (usize i = 0\
    \ ; i < xs.size() ; i++)\n            if (i != idx)\n                den *= x\
    \ - xs[i];\n        den = mint{1} / den;\n        for (usize i = 0 ; i < xs.size()\
    \ ; i++)\n            ans[i] += ys[idx] * num[i] * den;\n        idx++;\n    }\
    \ \n    return ans;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/PolynomialInterpolation.hpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc137_f.test.cpp
  - Test/LC/polynomial_interpolation/quadratic.test.cpp
documentation_of: Src/FPS/PolynomialInterpolation.hpp
layout: document
redirect_from:
- /library/Src/FPS/PolynomialInterpolation.hpp
- /library/Src/FPS/PolynomialInterpolation.hpp.html
title: Src/FPS/PolynomialInterpolation.hpp
---
