---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Rerooting.hpp
    title: "\u6728DP/\u5168\u65B9\u4F4D\u6728DP"
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#include \"../../Src/Graph/Tree/Rerooting.hpp\"\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n#include \"atcoder/modint\"\n#include <iostream>\n#include <utility>\n#include\
    \ <vector>\nusing namespace std;\nusing namespace zawa;\nusing mint=atcoder::modint998244353;\n\
    struct DP {\n    using Tree = pair<mint,int>;\n    using Cluster = pair<mint,int>;\n\
    \    using Edge = Affine<mint>;\n    using Vertex = mint;\n    static Tree Convert(Vertex\
    \ a) {\n        return {a,1};\n    }\n    static Cluster AddEdge(Tree t,Edge f)\
    \ {\n        return {f.a()*t.first+f.b()*t.second,t.second};\n    }\n    static\
    \ Cluster Merge(Cluster l,Cluster r) {\n        return {l.first+r.first,l.second+r.second};\n\
    \    }\n    static Tree AddVertex(Cluster c,Vertex a) {\n        return {c.first+a,c.second+1};\n\
    \    }\n};\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    vector<mint> A(N);\n    for (int i = 0 ; i < N\
    \ ; i++) {\n        int a;\n        cin >> a;\n        A[i]=mint::raw(a);\n  \
    \  }\n    vector<pair<int,int>> E(N-1);\n    vector<Affine<mint>> af(N-1);\n \
    \   for (int i = 0 ; auto& [u,v] : E) {\n        int b,c;\n        cin >> u >>\
    \ v >> b >> c;\n        af[i]=Affine<mint>{mint::raw(b),mint::raw(c)};\n     \
    \   i++;\n    }\n    Rerooting<DP,int> dp(N,E,A,af);\n    for (int i = 0 ; i <\
    \ N ; i++)\n        cout << dp[i].first.val() << (i+1==N?'\\n':' ');\n}\n"
  dependsOn:
  - Src/Graph/Tree/Rerooting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 15:41:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/tree_path_composite_sum.test.cpp
- /verify/Test/LC/tree_path_composite_sum.test.cpp.html
title: Test/LC/tree_path_composite_sum.test.cpp
---
