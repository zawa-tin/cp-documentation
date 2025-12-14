---
data:
  _extendedDependsOn:
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
    - https://atcoder.jp/contests/abc269/submissions/71411446
    - https://atcoder.jp/contests/abc269/tasks/abc269_h
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc269/tasks/abc269_h\"\n\n\
    /*\n * AtCoder Beginner Contest 269 Ex - Antichain\n * https://atcoder.jp/contests/abc269/submissions/71411446\n\
    \ */\n\n#include \"../../Src/Graph/Tree/DynamicTreeDP.hpp\"\n#include \"atcoder/modint\"\
    \n#include \"atcoder/convolution\"\nusing mint = atcoder::modint998244353;\n#include\
    \ <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\nusing namespace zawa;\nvector<mint> operator+(vector<mint> a,\
    \ vector<mint> b) {\n    a.resize(max(a.size(), b.size()));\n    for (int i =\
    \ 0 ; i < ssize(b) ; i++)\n        a[i] += b[i];\n    return a;\n}\nstruct DP\
    \ {\n    using Vertex = struct {};\n    using Edge = struct {};\n    // first...\
    \ must use root(heavy path), second... must not use root\n    using PathCluster\
    \ = pair<vector<mint>, vector<mint>>;\n    using PointCluster = vector<mint>;\n\
    \    static PathCluster vertex(Vertex) {\n        return {vector<mint>{0, 1},\
    \ vector<mint>{1, 0}};\n    }\n    static PathCluster addVertex(PointCluster p,\
    \ Vertex) {\n        return {vector<mint>{0, 1}, p};\n    }\n    static PointCluster\
    \ addEdge(PathCluster p, Edge) {\n        return p.first + p.second;\n    }\n\
    \    static PointCluster rake(PointCluster p, PointCluster q) {\n        return\
    \ atcoder::convolution(p, q);\n    }\n    static PathCluster compress(PathCluster\
    \ p, Edge, PathCluster q) {\n        return {p.first + atcoder::convolution(p.second,\
    \ q.first), atcoder::convolution(p.second, q.second)};\n    }\n};\nostream& operator<<(ostream&\
    \ os, vector<mint> v) {\n    for (auto x : v)\n        os << x.val() << ' ';\n\
    \    return os; \n}\nstruct Printer {\n    void operator()(int i, string name,\
    \ int par, DP::PathCluster path) {\n        cout << i << ' ' << name << ' ' <<\
    \ par << \" -> \" << path.first << '|' << path.second << endl;\n    }\n    void\
    \ operator()(int i, string name, int par, DP::PointCluster point) {\n        cout\
    \ << i << ' ' << name << ' ' << par << \" -> \" << point << endl;\n    }\n};\n\
    int main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    DynamicTreeDPGraph g(N);\n    for (int i = 1 ;\
    \ i < N ; i++) {\n        int p;\n        cin >> p;\n        g[--p].push_back({i,\
    \ i - 1});\n    }\n    DynamicTreeDP<DP> dp(g, 0, vector<DP::Vertex>(N), vector<DP::Edge>(N\
    \ - 1));\n    //dp.visit(Printer{});\n    auto [p, q] = dp();\n    auto ans =\
    \ p + q;\n    while (ssize(ans) <= N)\n        ans.push_back(0);\n    for (int\
    \ i = 1 ; i <= N ; i++)\n        cout << ans[i].val() << '\\n';\n#else\n    cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/DynamicTreeDP.hpp
  - Src/Graph/Tree/StaticTopTree.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc269_h.test.cpp
  requiredBy: []
  timestamp: '2025-12-03 17:47:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc269_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc269_h.test.cpp
- /verify/Test/AtCoder/abc269_h.test.cpp.html
title: Test/AtCoder/abc269_h.test.cpp
---
