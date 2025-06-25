---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
    title: Assignment Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
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
    - https://atcoder.jp/contests/abl/submissions/67038204
    - https://atcoder.jp/contests/abl/tasks/abl_e
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abl/tasks/abl_e\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp\"\
    \n#include \"atcoder/modint\"\n\n#include <iostream>\n#include <vector>\n\n/*\n\
    \ * ACL Beginner Contest - E Replace Digits\n * https://atcoder.jp/contests/abl/submissions/67038204\n\
    \ */\n\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\nint N,\
    \ Q;\nmint p10[2*200020];\nmint rep[10][2*200020];\n\nstruct M {\n    using Element\
    \ = std::pair<mint, int>;\n    static Element identity() {\n        return {mint{},\
    \ 0};\n    }\n    static Element operation(const Element& l, const Element& r)\
    \ {\n        return {p10[r.second]*l.first+r.first, l.second+r.second};\n    }\n\
    \    static Element power(Element v, u64 exp) {\n        return {rep[v.first.val()][exp],\
    \ (int)exp};\n    }\n};\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cin\
    \ >> N >> Q; \n    p10[0] = mint::raw(1);\n    for (int i = 1 ; i <= N ; i++)\
    \ p10[i] = p10[i - 1] * mint::raw(10);\n    for (int i = 0 ; i < 10 ; i++) {\n\
    \        // rep[i][0] = mint::raw(i);\n        for (int j = 1 ; j <= N ; j++)\
    \ rep[i][j] = rep[i][j - 1] * mint::raw(10) + mint::raw(i);\n    }\n    AssignmentSegmentTree<M>\
    \ seg(N);\n    seg.assign(0, N, {mint::raw(1), 1});\n    while (Q--) {\n     \
    \   int L, R, D;\n        std::cin >> L >> R >> D;\n        L--;\n        seg.assign(L,\
    \ R, {mint::raw(D), 1});\n        std::cout << seg.product(0, N).first.val() <<\
    \ '\\n';\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  isVerificationFile: true
  path: Test/AtCoder/abl_e.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 15:48:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abl_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abl_e.test.cpp
- /verify/Test/AtCoder/abl_e.test.cpp.html
title: Test/AtCoder/abl_e.test.cpp
---
