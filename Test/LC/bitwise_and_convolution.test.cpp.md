---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/BitwiseAndConvolution.hpp
    title: Src/Sequence/BitwiseAndConvolution.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/SupersetTransform.hpp
    title: "Superset Zeta/Mobius Transform ( $\\emptyset$ \u306E\u65B9\u3078\u96C6\
      \u3081\u308B\u3084\u3064 )"
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"../../Src/Sequence/BitwiseAndConvolution.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint = atcoder::modint998244353;\n\n#include <iostream>\nusing namespace\
    \ std;\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (int\
    \ i = 0 ; i < (1 << N) ; i++) {\n        int v;\n        cin >> v;\n        a[i]\
    \ = v;\n    }\n    for (int i = 0 ; i < (1 << N) ; i++) {\n        int v;\n  \
    \      cin >> v;\n        b[i] = v;\n    }\n    auto ans = zawa::BitwiseAndConvolution(a,\
    \ b);\n    for (int i = 0 ; i < ssize(ans) ; i++)\n        cout << ans[i].val()\
    \ << (i + 1 == ssize(ans) ? '\\n' : ' ');\n}\n"
  dependsOn:
  - Src/Sequence/BitwiseAndConvolution.hpp
  - Src/Sequence/SupersetTransform.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-09-23 01:02:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/bitwise_and_convolution.test.cpp
- /verify/Test/LC/bitwise_and_convolution.test.cpp.html
title: Test/LC/bitwise_and_convolution.test.cpp
---
