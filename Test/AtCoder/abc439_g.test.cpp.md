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
    path: Src/FPS/RationalSum.hpp
    title: "\u6B21\u6570\u306E\u7DCF\u548C\u304C\u6291\u3048\u3089\u308C\u3066\u3044\
      \u308B\u6709\u7406\u5F0F\u306E\u7DCF\u548C"
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
    - https://atcoder.jp/contests/abc439/submissions/72425293
    - https://atcoder.jp/contests/abc439/tasks/abc439_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc439/tasks/abc439_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 439 G - Sugoroku 6\n * https://atcoder.jp/contests/abc439/submissions/72425293\n\
    \ */\n\n#include \"../../Src/FPS/PowerProjection.hpp\"\n#include \"../../Src/FPS/RationalSum.hpp\"\
    \n#include \"../../Src/FPS/FPSNTTFriendly.hpp\"\nusing namespace zawa;\n#include\
    \ \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\nusing fps = FPSNTTFriendly<mint::mod()>;\n\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N, M,\
    \ L;\n    cin >> N >> M >> L;\n    const mint inv = mint::raw(M).inv();\n    fps\
    \ dice(N + 1);\n    for (int i = 0 ; i < M ; i++) {\n        int a;\n        cin\
    \ >> a;\n        dice[a] = inv;\n    }\n    fps q{PowerProjection(N + 1, fps(N,\
    \ 1), dice)};\n    fps p(N + 1);\n    for (int i = 0 ; i <= N ; i++)\n       \
    \ p[i] = 1 - q[i];\n    for (int i = N ; i >= 1 ; i--)\n        p[i] -= p[i -\
    \ 1];\n    vector<fps> num, den;\n    for (int j = 1 ; j <= N ; j++) {\n     \
    \   if (q[j - 1] == mint{})\n            break;\n        num.push_back({p[j] *\
    \ q[j - 1].pow(L - 1)});\n        den.push_back({1, -q[j] * q[j - 1].inv()});\n\
    \    }\n    auto [a, b] = RationalSum(num, den);\n    auto ans = a * b.inv(L);\n\
    \    for (int i = 0 ; i < L ; i++)\n        cout << ans[i].val() << '\\n';\n#else\n\
    \    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/FPS/PowerProjection.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/RationalSum.hpp
  - Src/FPS/FPSNTTFriendly.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc439_g.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 19:55:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc439_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc439_g.test.cpp
- /verify/Test/AtCoder/abc439_g.test.cpp.html
title: Test/AtCoder/abc439_g.test.cpp
---
