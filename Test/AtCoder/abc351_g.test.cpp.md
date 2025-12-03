---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/DynamicTreeDP.hpp
    title: "Static Top Tree + \u6728DP"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/StaticTopTree.hpp
    title: Src/Graph/Tree/StaticTopTree.hpp
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
    - https://atcoder.jp/contests/abc351/submissions/71410674
    - https://atcoder.jp/contests/abc351/tasks/abc351_g
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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc351/tasks/abc351_g\"\n\n\
    /*\n * AtCoder Beginner Contest 351 G - Hash on Tree\n * https://atcoder.jp/contests/abc351/submissions/71410674\n\
    \ */\n\n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\
    #include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n#include \"../../Src/Graph/Tree/DynamicTreeDP.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\nusing namespace zawa;\nusing AM\
    \ = AffineMonoid<mint>;\nstruct Void {};\nstruct Path {\n    mint ans, boundA;\n\
    \    Affine<mint> ab;\n};\nusing Point = mint;\nstruct DP {\n    using Vertex\
    \ = mint;\n    using Edge = Void;\n    using PathCluster = Path;\n    using PointCluster\
    \ = Point;\n    static PathCluster vertex(const Vertex& v) {\n        return {v,\
    \ v, Affine<mint>{1, 0}};\n    }\n    static PathCluster addVertex(const PointCluster&\
    \ p, const Vertex& v) {\n        return {v, v, Affine<mint>{p, 0}};\n    }\n \
    \   static PointCluster addEdge(const PathCluster& p, const Edge&) {\n       \
    \ return p.ans;\n    }\n    static PointCluster rake(const PointCluster& p, const\
    \ PointCluster& q) {\n        return p * q;\n    }\n    static PathCluster compress(const\
    \ PathCluster& p, const Edge&, const PathCluster& q) {\n        return {p.ans\
    \ + p.ab(q.ans), p.boundA, AM::operation(q.ab, p.ab)};\n    }\n};\n//struct Printer\
    \ {\n//    void operator()(int i, string type, int par, Path p) const {\n//  \
    \      std::cout << i << \" -> \" << type << ' ' << par << '|' << p.ans.val()\
    \ << ',' << p.boundA.val() << ',' << p.ab.a().val() << ',' << p.ab.b().val() <<\
    \ endl;\n//    }\n//    void operator()(int i, string type, int par, Point p)\
    \ const {\n//        std::cout << i << \" -> \" << type << ' ' << par << '|' <<\
    \ p.val() << endl;\n//    }\n//};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >>\
    \ Q;\n    DynamicTreeDPGraph g(N);\n    for (int i = 1 ; i < N ; i++) {\n    \
    \    int p;\n        cin >> p;\n        g[--p].push_back({i, i - 1});\n    }\n\
    \    vector<DP::Vertex> A(N);\n    for (int i = 0 ; i < N ; i++) {\n        int\
    \ a;\n        cin >> a;\n        A[i] = a;\n    }\n    DynamicTreeDP<DP> dp(g,\
    \ 0, A, vector<DP::Edge>(N - 1));\n    //dp.visit(Printer{});\n    while (Q--)\
    \ {\n        int v, x;\n        cin >> v >> x;\n        dp.assignVertex(--v, mint{x});\n\
    \        cout << dp().ans.val() << '\\n';\n    }\n#else\n    cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Monoid/AffineMonoid.hpp
  - Src/Graph/Tree/DynamicTreeDP.hpp
  - Src/Graph/Tree/StaticTopTree.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc351_g.test.cpp
  requiredBy: []
  timestamp: '2025-12-03 17:47:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc351_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc351_g.test.cpp
- /verify/Test/AtCoder/abc351_g.test.cpp.html
title: Test/AtCoder/abc351_g.test.cpp
---
