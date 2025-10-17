---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/KthTerm.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306EK\u9805\u76EE\u3092\u8A08\u7B97\u3059\
      \u308B"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include \"../../Src/FPS/KthTerm.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"./atcoder/convolution\"\n\nusing mint = atcoder::modint998244353;\n\
    \nusing namespace zawa;\n\nint main() {\n    SetFastIO(); \n    int d;\n    long\
    \ long k;\n    std::cin >> d >> k;\n    std::vector<mint> a(d), c(d);\n    for\
    \ (auto& v : a) {\n        int i;\n        std::cin >> i;\n        v = i;\n  \
    \  }\n    for (auto& v : c) {\n        int i;\n        std::cin >> i;\n      \
    \  v = i;\n    }\n    std::cout << KthTerm(k, a, c, [](const auto& L, const auto&\
    \ R) { return atcoder::convolution(L, R); }).val();\n}\n"
  dependsOn:
  - Src/FPS/KthTerm.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  isVerificationFile: true
  path: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: Test/LC/kth_term_of_linearly_recurrent_sequence.test.cpp
---
