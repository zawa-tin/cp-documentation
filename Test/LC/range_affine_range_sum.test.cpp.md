---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AdditionMonoid.hpp
    title: Src/Algebra/Monoid/AdditionMonoid.hpp
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
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
    title: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"atcoder/modint\"\n\nusing mint = atcoder::modint998244353;\nstd::pair<mint,\
    \ mint> operator+(const std::pair<mint, mint>& a, const std::pair<mint, mint>&\
    \ b) {\n    return {a.first+b.first,a.second+b.second};\n}\n\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/AdditionMonoid.hpp\"\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <cassert>\n#include <utility>\n\
    \nusing namespace zawa;\n\nstruct S {\n    using ValueMonoid = AdditionMonoid<std::pair<mint,\
    \ mint>>;\n    using OperatorMonoid = AffineMonoid<mint>;\n    static std::pair<mint,\
    \ mint> mapping(const std::pair<mint, mint>& v, const Affine<mint>& o) {\n   \
    \     return { o.a() * v.first + o.b() * v.second, v.second };\n    }\n};\n\n\n\
    int main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q; \n    std::cin >> n >> q;\n    std::vector<std::pair<mint, mint>>\
    \ a(n);\n    for (auto& x : a) {\n        int v;\n        std::cin >> v;\n   \
    \     x = {v, 1};\n    }\n    LazySegmentTree<S> seg(a);\n    while (q--) {\n\
    \        int t, l, r; \n        std::cin >> t >> l >> r;\n        if (t == 0)\
    \ {\n            int b, c; \n            std::cin >> b >> c;\n            seg.operation(l,\
    \ r, Affine{ mint{b}, mint{c} });\n        }\n        else if (t == 1) {\n   \
    \         std::cout << seg.product(l, r).first.val() << '\\n';\n        }\n  \
    \      else {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-11-20 00:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/range_affine_range_sum.test.cpp
- /verify/Test/LC/range_affine_range_sum.test.cpp.html
title: Test/LC/range_affine_range_sum.test.cpp
---
