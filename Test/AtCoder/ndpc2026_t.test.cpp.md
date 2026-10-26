---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/DivisionOfPolynomials.hpp
    title: Src/FPS/DivisionOfPolynomials.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
  - icon: ':heavy_check_mark:'
    path: Src/FPS/MultipointEvaluation.hpp
    title: "\u591A\u70B9\u8A55\u4FA1(Multipoint Evaluation)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/SubproductTree.hpp
    title: Subproduct Tree
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/STTDPInterface.hpp
    title: "STT\u4E0A\u306Edp\u306E\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/STTFold.hpp
    title: "Static Top Tree\u4E0A\u306EDP"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/ndpc/submissions/80403501
    - https://atcoder.jp/contests/ndpc/tasks/ndpc2026_t
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/ndpc/tasks/ndpc2026_t\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * Next DP Contest\
    \ T - \u72EC\u7ACB\u96C6\u5408 (Subtask)\n * https://atcoder.jp/contests/ndpc/submissions/80403501\n\
    \ */\n#include \"../../Src/FPS/FPSNTTFriendly.hpp\"\n#include \"../../Src/FPS/MultipointEvaluation.hpp\"\
    \n#include \"../../Src/Graph/Tree/STTFold.hpp\"\n#include \"atcoder/modint\"\n\
    using mint=atcoder::modint998244353;\n#include <vector>\n#include <array>\n#include\
    \ <iostream>\nusing namespace std;\nusing namespace zawa;\nusing fps=FPSNTTFriendly<mint::mod()>;\n\
    struct DP {\n    using Vertex = struct {};\n    using Edge = struct {};\n    //\
    \ 1..ue,2..sita\n    using PathCluster = array<fps,4>;\n    using PointCluster\
    \ = array<fps,2>;\n    static PathCluster vertex(const Vertex&) {\n        fps\
    \ notuse{1};\n        fps use{0,1};\n        fps ban;\n        return {notuse,ban,ban,use};\n\
    \    }\n    static PathCluster addVertex(PointCluster f, const Vertex&) {\n  \
    \      fps notuse=f[0]+f[1];\n        fps use=f[0]*fps{0,1};\n        fps ban;\n\
    \        return {notuse,ban,ban,use};\n    }\n    static PointCluster addEdge(PathCluster\
    \ fs, const Edge&) {\n        return {fs[0]+fs[2],fs[1]+fs[3]};\n    }\n    static\
    \ PointCluster rake(PointCluster l, PointCluster r) {\n        return {l[0]*r[0],l[0]*r[1]+l[1]*r[0]+l[1]*r[1]};\n\
    \    }\n    static PathCluster compress(PathCluster p, Edge, const PathCluster\
    \ c) {\n        array<fps,4> res;\n        res.fill(fps{});\n        for (int\
    \ i = 0 ; i < 4 ; i++)\n            for (int j = 0 ; j < 4 ; j++) {\n        \
    \        if ((i&2) and (j&1))\n                    continue;\n               \
    \ int idx=0;\n                if (i&1)\n                    idx|=1;\n        \
    \        if (j&2)\n                    idx|=2;\n                res[idx]+=p[i]*c[j];\n\
    \            }\n        return res;\n    }\n};\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n\
    \    cin >> N >> Q;\n    STTGraph g(N);\n    for (int i = 0 ; i < N-1 ; i++) {\n\
    \        int u,v;\n        cin >> u >> v;\n        u--; v--;\n        g[u].push_back({v,i});\n\
    \        g[v].push_back({u,i});\n    }\n    auto fold=STTFold<DP>(move(g),0,vector<DP::Vertex>(N),vector<DP::Edge>(N-1));\n\
    \    fps f=fold[1]+fold[3];\n    vector<mint> x(Q);\n    for (int i = 0 ; i <\
    \ Q ; i++) {\n        int v,q;\n        cin >> v >> q;\n        if (v != 1)\n\
    \            exit(0);\n        x[i]=mint::raw(q);\n    }\n    for (mint ans :\
    \ MultipointEvaluation(f,x))\n        cout << ans.val() << '\\n';\n#else\n   \
    \ int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/FPS/FPS.hpp
  - Src/Template/TypeAlias.hpp
  - Src/FPS/MultipointEvaluation.hpp
  - Src/FPS/SubproductTree.hpp
  - Src/FPS/DivisionOfPolynomials.hpp
  - Src/Graph/Tree/STTFold.hpp
  - Src/Graph/Tree/StaticTopTree.hpp
  - Src/Graph/Tree/STTDPInterface.hpp
  isVerificationFile: true
  path: Test/AtCoder/ndpc2026_t.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 15:58:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/ndpc2026_t.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/ndpc2026_t.test.cpp
- /verify/Test/AtCoder/ndpc2026_t.test.cpp.html
title: Test/AtCoder/ndpc2026_t.test.cpp
---
