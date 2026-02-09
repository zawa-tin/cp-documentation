---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Ring/UsualRing.hpp
    title: Src/Algebra/Ring/UsualRing.hpp
  - icon: ':heavy_check_mark:'
    path: Src/LinearAlgebra/Matrix.hpp
    title: Src/LinearAlgebra/Matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/LinearAlgebra/Matrix.hpp\"\
    \n#include \"../../Src/Algebra/Ring/UsualRing.hpp\"\n#include \"atcoder/modint\"\
    \n\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\nusing M = Matrix<UsualRing<mint>>;\n\
    \nint main() {\n    int N;\n    std::cin >> N;\n    M A(N, N);\n    for (int i{}\
    \ ; i < N ; i++) {\n        for (int j{} ; j < N ; j++) {\n            int a;\n\
    \            std::cin >> a;\n            A[i][j] = mint::raw(a);\n        }\n\
    \    }\n    std::cout << A.determinant().val() << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/LinearAlgebra/Matrix.hpp
  - Src/Algebra/Ring/UsualRing.hpp
  isVerificationFile: true
  path: Test/LC/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2026-01-01 21:17:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/matrix_det.test.cpp
- /verify/Test/LC/matrix_det.test.cpp.html
title: Test/LC/matrix_det.test.cpp
---
