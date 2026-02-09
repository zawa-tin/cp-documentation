---
data:
  _extendedDependsOn:
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
    path: Test/LC/division_of_polynomials.test.cpp
    title: Test/LC/division_of_polynomials.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"FPSNTTFriendly.hpp\"\n\n#include <algorithm>\n\
    #include <ranges>\n#include <utility>\n\nnamespace zawa {\n\n// f = gq + r\n//\
    \ first... q\n// second... r\ntemplate <usize MOD = 998244353>\nstd::pair<FPSNTTFriendly<MOD>,\
    \ FPSNTTFriendly<MOD>> DivisionOfPolynomials(FPSNTTFriendly<MOD> f, FPSNTTFriendly<MOD>\
    \ g) {\n    while (g.size() and g.back() == 0)\n        g.pop_back();\n    while\
    \ (f.size() and f.back() == 0)\n        f.pop_back();\n    assert(g.size());\n\
    \    const usize n = f.size(), m = g.size();\n    if (n == 0 or n < m)\n     \
    \   return {FPSNTTFriendly<MOD>{}, f};\n    std::ranges::reverse(f);\n    std::ranges::reverse(g);\n\
    \    auto q = f * g.inv(n);\n    if (q.size() > n - m + 1)\n        q.resize(n\
    \ - m + 1);\n    std::ranges::reverse(f);\n    std::ranges::reverse(g);\n    std::ranges::reverse(q);\n\
    \    auto r = f - g * q;\n    while (r.size() and r.back() == 0)\n        r.pop_back();\n\
    \    return {q, r};\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/DivisionOfPolynomials.hpp
  requiredBy: []
  timestamp: '2026-01-03 20:52:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/division_of_polynomials.test.cpp
documentation_of: Src/FPS/DivisionOfPolynomials.hpp
layout: document
redirect_from:
- /library/Src/FPS/DivisionOfPolynomials.hpp
- /library/Src/FPS/DivisionOfPolynomials.hpp.html
title: Src/FPS/DivisionOfPolynomials.hpp
---
