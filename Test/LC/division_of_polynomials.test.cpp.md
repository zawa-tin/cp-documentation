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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/division_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n\n#include \"../../Src/FPS/DivisionOfPolynomials.hpp\"\nusing namespace zawa;\n\
    using fps = FPSNTTFriendly<998244353>;\n\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N, M;\n    cin >> N >> M;\n    fps f(N), g(M);\n    for (int i = 0 ;\
    \ i < N ; i++) {\n        int a;\n        cin >> a;\n        f[i] = a;\n    }\n\
    \    for (int i = 0 ; i < M ; i++) {\n        int a;\n        cin >> a;\n    \
    \    g[i] = a;\n    }\n    auto [q, r] = DivisionOfPolynomials(f, g);\n    cout\
    \ << q.size() << ' ' << r.size() << '\\n';\n    cout << q << '\\n';\n    cout\
    \ << r << '\\n';\n}\n"
  dependsOn:
  - Src/FPS/DivisionOfPolynomials.hpp
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/division_of_polynomials.test.cpp
  requiredBy: []
  timestamp: '2026-01-03 20:52:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/division_of_polynomials.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/division_of_polynomials.test.cpp
- /verify/Test/LC/division_of_polynomials.test.cpp.html
title: Test/LC/division_of_polynomials.test.cpp
---
