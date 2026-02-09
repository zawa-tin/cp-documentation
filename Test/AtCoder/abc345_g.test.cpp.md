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
    path: Src/FPS/PowerProjection.hpp
    title: FPS Power Projection
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
    - https://atcoder.jp/contests/abc345/submissions/72422855
    - https://atcoder.jp/contests/abc345/tasks/abc345_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc345/tasks/abc345_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 345 G - Sugoroku 5\n * https://atcoder.jp/contests/abc345/submissions/72422855\n\
    \ */\n\n#include \"../../Src/FPS/FPSNTTFriendly.hpp\"\n#include \"../../Src/FPS/PowerProjection.hpp\"\
    \nusing namespace zawa;\n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\
    using fps = FPSNTTFriendly<mint::mod()>;\n\n#include <iostream>\nusing namespace\
    \ std;\n\nint main() {\n#ifdef ATCODER\n    int N, K;\n    cin >> N >> K;\n  \
    \  fps dice(K + 1, mint::raw(K).inv()), ngs(N, 1);\n    dice[0] = 0;\n    auto\
    \ pws = PowerProjection(N + 1, ngs, dice);\n    for (int i = 0 ; i <= N ; i++)\n\
    \        pws[i] = 1 - pws[i];\n    for (int i = N ; i >= 1 ; i--)\n        pws[i]\
    \ -= pws[i - 1];\n    for (int i = 1 ; i <= N ; i++)\n        cout << pws[i].val()\
    \ << '\\n';\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/PowerProjection.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc345_g.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 17:25:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc345_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc345_g.test.cpp
- /verify/Test/AtCoder/abc345_g.test.cpp.html
title: Test/AtCoder/abc345_g.test.cpp
---
