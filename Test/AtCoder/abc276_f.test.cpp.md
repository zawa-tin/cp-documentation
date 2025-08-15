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
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
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
    - https://atcoder.jp/contests/abc276/submissions/67045295
    - https://atcoder.jp/contests/abc276/tasks/abc276_f
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_f\"\n\n\
    /*\n * AtCoder Beginner Contest 276 F - Double Chance\n * https://atcoder.jp/contests/abc276/submissions/67045295\n\
    \ */\n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n\n#include <iostream>\n\
    \nusing namespace zawa;\n#include \"atcoder/modint\"\nusing m32 = atcoder::modint998244353;\n\
    \nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    usize n; std::cin >> n;\n\n    const\
    \ usize sz{ 200200 };\n    FenwickTree<AdditiveGroup<m32>> ft1(sz), ft2(sz);\n\
    \n    m32 now{};\n    m32 ans{};\n    for (u32 k{1} ; k <= n ; k++) {\n      \
    \  int in;\n        std::cin >> in;\n        m32 a = m32::raw(in);\n        now\
    \ += (m32{2} * ft1.prefixProduct(a.val() + 1) + m32{1}) * a;\n        now += m32{2}\
    \ * ft2.product(a.val() + 1, sz);\n        ans = now / (m32{k} * m32{k});\n\n\
    \        std::cout << ans.val() << '\\n';\n\n        ft1.operation(a.val(), m32{1});\n\
    \        ft2.operation(a.val(), a);\n    }\n#else\n    std::cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc276_f.test.cpp
  requiredBy: []
  timestamp: '2025-08-15 19:19:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc276_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc276_f.test.cpp
- /verify/Test/AtCoder/abc276_f.test.cpp.html
title: Test/AtCoder/abc276_f.test.cpp
---
