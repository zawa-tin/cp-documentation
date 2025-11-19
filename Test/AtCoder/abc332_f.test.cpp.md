---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
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
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
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
    - https://atcoder.jp/contests/abc332/submissions/71071551
    - https://atcoder.jp/contests/abc332/tasks/abc332_f
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc332/tasks/abc332_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n#include\
    \ \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n\n/*\n * AtCoder Beginner Contest\
    \ 332 F - Random Update Query\n * https://atcoder.jp/contests/abc332/submissions/71071551\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\nusing namespace zawa;\n#include\
    \ \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\nvoid solve() {\n\
    \    int N, M;\n    std::cin >> N >> M;\n    std::vector<Affine<mint>> init(N);\n\
    \    for (int i = 0 ; i < N ; i++) {\n        int A;\n        std::cin >> A;\n\
    \        init[i] = Affine{mint{}, mint{A}};\n    }\n    DualSegmentTree<AffineMonoid<mint>>\
    \ seg{init};\n    while (M--) {\n        int L, R, X;\n        std::cin >> L >>\
    \ R >> X;\n        L--;\n        mint inv = mint::raw(R - L).inv();\n        seg.operation(L,\
    \ R, Affine{mint::raw(R-L-1)*inv, mint::raw(X)*inv});\n    }\n    for (int i =\
    \ 0 ; i < N ; i++) std::cout << seg[i].b().val() << (i + 1 == N ? '\\n' : ' ');\n\
    }\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    solve();\n#else\n    std::cout <<\
    \ \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc332_f.test.cpp
  requiredBy: []
  timestamp: '2025-11-20 00:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc332_f.test.cpp
layout: document
title: "ABC332-F Random Update Query (a <- ap + q\u306E\u51E6\u7406)"
---

簡単な考察を踏むと、以下の様な処理ができれば良いことがわかる。

- 長さ $N$ のmintの列 $A$ がある
- $M$ 個のクエリが与えられる
- 各クエリでは、mint $p, q$ が与えられるので、 $A_{i} (l\le i\lt r)$ について $A_{i} \leftarrow A_{i}\times p+q$ せよ

双対セグ木にAffineMonoidを載せると、これが楽に処理できる。

- $i$ 番目の要素を $0x + A_{i}$ で初期化する
- 区間に $px + q$ をoperationする
- 答えは定数項に入っている。はじめ $0x + A_{i}$ で初期化しているため、一次の係数は $0$ になっている。
