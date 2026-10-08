---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Ring/UsualRing.hpp
    title: Src/Algebra/Ring/UsualRing.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/LinearAlgebra/Matrix.hpp
    title: Src/LinearAlgebra/Matrix.hpp
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
    - https://codeforces.com/contest/1895/submission/393684305
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Algebra/Ring/UsualRing.hpp\"\n#include \"../../Src/LinearAlgebra/Matrix.hpp\"\
    \n#include \"atcoder/modint.hpp\"\n\n#include <iostream>\n\nusing namespace zawa;\n\
    using mint = atcoder::modint1000000007;\nusing M = Matrix<UsualRing<mint>>;\n\n\
    /*\n * ECR157-F Fancy Arrays\n * https://codeforces.com/contest/1895/submission/393684305\n\
    \ */\n\nmint solve() {\n    int n, x, k; std::cin >> n >> x >> k;\n    mint ans{};\n\
    \    if (x > 0) {\n        M A(x);\n        for (int i{} ; i < x ; i++) {\n  \
    \          for (int j{} ; j < x ; j++) {\n                if (std::abs(i - j)\
    \ <= k) {\n                    A[i][j] = mint::raw(1);\n                }\n  \
    \          }\n        }\n        A = A.pow(n - 1);\n        for (int i{} ; i <\
    \ x ; i++) {\n            for (int j{} ; j < x ; j++) {\n                ans +=\
    \ A[i][j];\n            }\n        }\n    }\n    ans = mint{x + k} * mint{2 *\
    \ k + 1}.pow(n - 1) - ans;\n    return ans;\n}\n\nint main() {\n#ifdef ONLINE_JUDGE\n\
    \    std::cin.tie(0);\n    std::cout.tie(0);\n    std::ios::sync_with_stdio(0);\n\
    \    int t; std::cin >> t;\n    while (t--) {\n        std::cout << solve().val()\
    \ << '\\n';\n    }\n#else\n    std::cout << \"Hello World\" << '\\n';\n#endif\n\
    }\n"
  dependsOn:
  - Src/Algebra/Ring/UsualRing.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/LinearAlgebra/Matrix.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/CF/ECR157-F.test.cpp
  requiredBy: []
  timestamp: '2026-10-08 17:25:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/CF/ECR157-F.test.cpp
layout: document
redirect_from:
- /verify/Test/CF/ECR157-F.test.cpp
- /verify/Test/CF/ECR157-F.test.cpp.html
title: Test/CF/ECR157-F.test.cpp
---
