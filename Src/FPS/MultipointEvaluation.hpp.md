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
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/fps_24_p.test.cpp
    title: Test/AtCoder/fps_24_p.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/multipoint_evaluation.test.cpp
    title: Test/LC/multipoint_evaluation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
  code: "#pragma once\n\n#include \"FPSNTTFriendly.hpp\"\n#include \"DivisionOfPolynomials.hpp\"\
    \n\n#include <bit>\n\nnamespace zawa {\n\ntemplate <usize MOD = 998244353>\nstd::vector<typename\
    \ FPSNTTFriendly<MOD>::V> MultipointEvaluation(const FPSNTTFriendly<MOD>& f,const\
    \ std::vector<typename FPSNTTFriendly<MOD>::V>& xs) {\n    using fps = FPSNTTFriendly<MOD>;\n\
    \    using mint = fps::V;\n    if (f.empty() or xs.empty())\n        return std::vector(xs.size(),mint{0});\n\
    \    const usize n = std::bit_ceil(xs.size());\n    std::vector<fps> prod(2*n,fps{std::vector<mint>{1}});\n\
    \    for (usize i = 0 ; i < xs.size() ; i++)\n        prod[n+i] = std::vector<mint>{-xs[i],1};\n\
    \    for (usize i = n ; --i ; )\n        prod[i] = prod[i<<1|0]*prod[i<<1|1];\n\
    \    std::vector<fps> rem(2*n);\n    rem[1] = DivisionOfPolynomials(f,prod[1]).second;\n\
    \    for (usize i = 1 ; i < n ; i++) {\n        rem[i<<1|0] = DivisionOfPolynomials(rem[i],prod[i<<1|0]).second;\n\
    \        rem[i<<1|1] = DivisionOfPolynomials(rem[i],prod[i<<1|1]).second;\n  \
    \  }\n    std::vector<mint> res(xs.size());\n    for (usize i = 0 ; i < xs.size()\
    \ ; i++)\n        res[i] = rem[n+i].empty() ? mint{0} : rem[n+i][0];\n    return\
    \ res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  isVerificationFile: false
  path: Src/FPS/MultipointEvaluation.hpp
  requiredBy: []
  timestamp: '2026-05-06 19:26:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/multipoint_evaluation.test.cpp
  - Test/AtCoder/fps_24_p.test.cpp
documentation_of: Src/FPS/MultipointEvaluation.hpp
layout: document
redirect_from:
- /library/Src/FPS/MultipointEvaluation.hpp
- /library/Src/FPS/MultipointEvaluation.hpp.html
title: Src/FPS/MultipointEvaluation.hpp
---
