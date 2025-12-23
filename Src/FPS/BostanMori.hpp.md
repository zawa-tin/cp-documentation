---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/KthTerm.hpp
    title: "$[x^{N}]\\frac{P(x)}{Q(x)}$ \u306E\u9AD8\u901F\u8A08\u7B97 (Bostan-Mori\
      \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/3044.test.cpp
    title: Test/yukicoder/3044.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"FPSNTTFriendly.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <usize MOD = 998244353>\ntypename FPSNTTFriendly<MOD>::V BostanMori(usize N,\
    \ FPSNTTFriendly<MOD> P, FPSNTTFriendly<MOD> Q) {\n    assert(P.size());\n   \
    \ assert(Q.size() and Q[0] != 0); \n    auto takeParity = [&](const FPSNTTFriendly<MOD>&\
    \ f, usize p) {\n        FPSNTTFriendly<MOD> res;\n        res.reserve(f.size()\
    \ / 2);\n        for (usize i = p ; i < f.size() ; i += 2)\n            res.push_back(f[i]);\n\
    \        return res;\n    };\n    while (N) {\n        FPSNTTFriendly<MOD> Qm(Q.size());\n\
    \        for (usize i = 0 ; i < Q.size() ; i++)\n            Qm[i] = i % 2 ? -Q[i]\
    \ : Q[i];\n        P = takeParity(P * Qm, N % 2);\n        Q = takeParity(Q *\
    \ Qm, 0);\n        N >>= 1;\n    }\n    return P[0] / Q[0];\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/FPS/BostanMori.hpp
  requiredBy:
  - Src/FPS/KthTerm.hpp
  timestamp: '2025-12-23 20:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  - Test/yukicoder/3044.test.cpp
documentation_of: Src/FPS/BostanMori.hpp
layout: document
redirect_from:
- /library/Src/FPS/BostanMori.hpp
- /library/Src/FPS/BostanMori.hpp.html
title: Src/FPS/BostanMori.hpp
---
