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
    path: Src/FPS/PolynomialProducts.hpp
    title: "\u6B21\u6570\u306E\u7DCF\u548C\u304C\u6291\u3048\u3089\u308C\u3066\u3044\
      \u308B\u591A\u9805\u5F0F\u306E\u5217\u306E\u7DCF\u7A4D"
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
    - https://atcoder.jp/contests/abc385/submissions/72424554
    - https://atcoder.jp/contests/abc385/tasks/abc385_g
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc385/tasks/abc385_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 385 G - Counting Buildings\n * https://atcoder.jp/contests/abc385/submissions/72424554\n\
    \ */\n\n#include \"../../Src/FPS/PolynomialProducts.hpp\"\n#include \"../../Src/FPS/FPSNTTFriendly.hpp\"\
    \nusing namespace zawa;\n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\
    using fps = FPSNTTFriendly<mint::mod()>;\n\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n#ifdef ATCODER\n    int N, K;\n    cin >>\
    \ N >> K;\n    vector<fps> dp(N);\n    dp[0] = {0, 1, 0};\n    for (int i = 1\
    \ ; i < N ; i++) {\n        dp[i].resize(3);\n        dp[i][0] = dp[i][2] = 1;\n\
    \        dp[i][1] = i - 1;\n    }\n    auto pd = PolynomialProducts(dp);\n   \
    \ cout << pd[N + K].val() << '\\n';\n#else\n    cout << \"Hello World\\n\";\n\
    #endif\n}\n"
  dependsOn:
  - Src/FPS/PolynomialProducts.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/FPSNTTFriendly.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc385_g.test.cpp
  requiredBy: []
  timestamp: '2026-01-12 19:02:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc385_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc385_g.test.cpp
- /verify/Test/AtCoder/abc385_g.test.cpp.html
title: Test/AtCoder/abc385_g.test.cpp
---
