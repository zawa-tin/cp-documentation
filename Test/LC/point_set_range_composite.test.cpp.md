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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n\n#include \"atcoder/modint\"\
    \n\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\nusing Monoid\
    \ = AffineMonoid<mint>;\n\n#include <iostream>\n#include <vector>\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q; std::cin >> n >> q;\n    std::vector<Affine<mint>> init(n);\n \
    \   for (int i{} ; i < n ; i++) {\n        u64 a, b; std::cin >> a >> b;\n   \
    \     init[i] = Affine<mint>{ a, b };\n    }\n    SegmentTree<Monoid> seg(init);\n\
    \    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if\
    \ (t == 0) {\n            int p, c, d; std::cin >> p >> c >> d;\n            seg.assign(p,\
    \ { c, d });\n        }\n        else if (t == 1) {\n            int l, r, x;\
    \ std::cin >> l >> r >> x;\n            std::cout << seg.product(l, r)(x).val()\
    \ << '\\n';\n        }\n        else {\n            assert(false);\n        }\n\
    \    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/point_set_range_composite.test.cpp
- /verify/Test/LC/point_set_range_composite.test.cpp.html
title: Test/LC/point_set_range_composite.test.cpp
---
