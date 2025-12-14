---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/GCDConvolution.hpp
    title: Src/Number/GCDConvolution.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeSupersetTransform.hpp
    title: Src/Number/PrimeSupersetTransform.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"../../Src/Number/GCDConvolution.hpp\"\n#include \"atcoder/modint\"\nusing\
    \ mint = atcoder::modint998244353;\n\n#include <iostream>\n#include <vector>\n\
    using namespace std;\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    vector<mint> a(N + 1), b(N + 1);\n    for (int\
    \ i = 1 ; i <= N ; i++) {\n        int v;\n        cin >> v;\n        a[i] = v;\n\
    \    }\n    for (int i = 1 ; i <= N ; i++) {\n        int v;\n        cin >> v;\n\
    \        b[i] = v;\n    }\n    auto ans = zawa::GCDConvolution(a, b);\n    for\
    \ (int i = 1 ; i < ssize(ans) ; i++)\n        cout << ans[i].val() << (i + 1 ==\
    \ ssize(ans) ? '\\n' : ' ');\n}\n"
  dependsOn:
  - Src/Number/GCDConvolution.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeSupersetTransform.hpp
  isVerificationFile: true
  path: Test/LC/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-09-23 17:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/gcd_convolution.test.cpp
- /verify/Test/LC/gcd_convolution.test.cpp.html
title: Test/LC/gcd_convolution.test.cpp
---
