---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SparseSegmentTree.hpp
    title: "\u5358\u4F4D\u5143\u3067\u7121\u3044\u8981\u7D20\u304C\u758E\u306A\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/SparseSegmentTree.hpp\"\
    \n#include \"atcoder/modint\"\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\n\
    \n#include <cassert>\n#include <iostream>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    std::cin >> N >> Q;\n    using M = AffineMonoid<mint>;\n    using V\
    \ = M::Element;\n    SparseSegmentTree<M> seg(N, Q);\n    while (Q--) {\n    \
    \    int t;\n        std::cin >> t;\n        if (t == 0) {\n            int p,\
    \ c, d;\n            std::cin >> p >> c >> d;\n            seg.assign(p, V{mint{c},\
    \ mint{d}});\n        }\n        else if (t == 1) {\n            int l, r, x;\n\
    \            std::cin >> l >> r >> x;\n            std::cout << seg.product(l,\
    \ r)(x).val() << '\\n';\n        }\n        else assert(false);\n    }\n}\n"
  dependsOn:
  - Src/Algebra/Monoid/AffineMonoid.hpp
  - Src/DataStructure/SegmentTree/SparseSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/LC/point_set_range_composite_large_array.test.cpp
  requiredBy: []
  timestamp: '2025-06-24 16:35:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/point_set_range_composite_large_array.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/point_set_range_composite_large_array.test.cpp
- /verify/Test/LC/point_set_range_composite_large_array.test.cpp.html
title: Test/LC/point_set_range_composite_large_array.test.cpp
---
