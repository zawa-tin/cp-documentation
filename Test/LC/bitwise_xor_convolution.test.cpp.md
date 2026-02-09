---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/BitwiseXORConvolution.hpp
    title: Bitwise XOR Convolution
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../../Src/Sequence/BitwiseXORConvolution.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint = atcoder::modint998244353;\n\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    std::vector<mint> A(1 << N), B(1 << N);\n\
    \    for (int i = 0 ; i < std::ssize(A) ; i++) {\n        int v;\n        std::cin\
    \ >> v;\n        A[i] = mint::raw(v);\n    }\n    for (int i = 0 ; i < std::ssize(B)\
    \ ; i++) {\n        int v;\n        std::cin >> v;\n        B[i] = mint::raw(v);\n\
    \    }\n    auto ans = zawa::BitwiseXORConvolution(A, B);\n    for (int i = 0\
    \ ; i < std::ssize(ans) ; i++) std::cout << ans[i].val() << (i + 1 == std::ssize(ans)\
    \ ? '\\n' : ' ');\n}\n"
  dependsOn:
  - Src/Sequence/BitwiseXORConvolution.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/bitwise_xor_convolution.test.cpp
- /verify/Test/LC/bitwise_xor_convolution.test.cpp.html
title: Test/LC/bitwise_xor_convolution.test.cpp
---
