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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include \"../../Src/Graph/Tree/DynamicTreeDP.hpp\"\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\nusing namespace std;\nusing\
    \ namespace zawa;\nstruct Path {\n    mint ans;\n    Affine<mint> hev;\n    int\
    \ sz;\n};\nstruct Point {\n    mint ans;\n    int sz;\n};\nusing AM = AffineMonoid<mint>;\n\
    struct DP {\n    using Vertex = mint;\n    using Edge = Affine<mint>;\n    using\
    \ PathCluster = Path;\n    using PointCluster = Point;\n    static PathCluster\
    \ vertex(const Vertex& v) {\n        return {v, AM::identity(), 1};\n    }\n \
    \   static PathCluster addVertex(const PointCluster& p, const Vertex& v) {\n \
    \       return {p.ans + v, AM::identity(), p.sz + 1};\n    }\n    static PointCluster\
    \ addEdge(const PathCluster& p, const Edge& e) {\n        return {e.a() * p.ans\
    \ + e.b() * p.sz, p.sz};\n    }\n    static PointCluster rake(const PointCluster&\
    \ p, const PointCluster& q) {\n        return {p.ans + q.ans, p.sz + q.sz};\n\
    \    }\n    static PathCluster compress(const PathCluster& p, const Edge& e, const\
    \ PathCluster& q) {\n        auto hev = AM::operation(e, p.hev);\n        return\
    \ {p.ans + hev.a() * q.ans + hev.b() * q.sz, AM::operation(q.hev, hev), p.sz +\
    \ q.sz};\n    }\n};\n//#include <random>\n//mt19937 mt{random_device{}()};\n//mint\
    \ naive(DynamicTreeDPGraph g, vector<DP::Vertex> vs, vector<DP::Edge> es) {\n\
    //    auto rec = [&](auto rec, int v, int p) -> pair<mint, int> {\n//        int\
    \ sz = 1;\n//        mint ans = vs[v];\n//        for (auto [x, e] : g[v])\n//\
    \            if (x != p) {\n//                auto [a, b] = rec(rec, x, v);\n\
    //                ans += es[e].a() * a + es[e].b() * b;\n//                sz\
    \ += b;\n//            }\n//        return {ans, sz};\n//    };\n//    return\
    \ rec(rec, 0, -1).first;\n//}\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >> Q;\n    vector<DP::Vertex>\
    \ vs(N);\n    vector<DP::Edge> es(N - 1);\n    for (int i = 0 ; i < N ; i++) {\n\
    \        int a;\n        cin >> a;\n        vs[i] = a;\n    }\n    DynamicTreeDPGraph\
    \ g(N);\n    for (int i = 0 ; i < N - 1 ; i++) {\n        int u, v, b, c;\n  \
    \      cin >> u >> v >> b >> c;\n        g[u].push_back({v, i});\n        g[v].push_back({u,\
    \ i});\n        es[i] = Affine<mint>{b, c};\n    }\n    DynamicTreeDP<DP> dp(g,\
    \ 0, vs, es);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int w, x;\n            cin >> w >> x;\n            dp.assignVertex(w,\
    \ x);\n        }\n        else if (t == 1) {\n            int e, y, z;\n     \
    \       cin >> e >> y >> z;\n            dp.assignEdge(e, Affine<mint>{y, z});\n\
    \        }\n        else\n            assert(0);\n        cout << dp().ans.val()\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Graph/Tree/DynamicTreeDP.hpp
  - Src/Graph/Tree/StaticTopTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2025-12-03 17:47:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
