---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
    title: Rectangle Sum of PointCloud
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
    - https://atcoder.jp/contests/abc136/submissions/65184629
    - https://atcoder.jp/contests/abc136/tasks/abc136_f
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc136/tasks/abc136_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 136 F - Enclosed Points\n * https://atcoder.jp/contests/abc136/submissions/65184629\n\
    \ */\n\n\n#include \"../../Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp\"\
    \n\n#include <vector>\n#include <iostream>\n\n#include \"atcoder/modint\"\nusing\
    \ mint = atcoder::modint998244353;\nstruct Point {\n    using P = int; // \u5EA7\
    \u6A19\u306E\u578B\u3001int, long long \n    using W = int; // \u91CD\u307F\u306E\
    \u578B\u3001int, long long, mint\n    P x, y;\n    W w;\n};\nstruct Rect {\n \
    \   using P = int;\n    int l, d, r, u;\n};\nint main() {\n#ifdef ATCODER\n  \
    \  std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    std::vector<Point> P(N);\n    std::vector<Rect>\
    \ Q(8 * N);\n    const int INF = (int)1e9 + 1;\n    for (int i = 0 ; i < N ; i++)\
    \ {\n        int x, y;\n        std::cin >> x >> y;\n        P[i] = {x, y, 1};\n\
    \        Q[8*i+0]={x+1,-INF, INF, INF};\n        Q[8*i+1]={-INF,y+1, INF, INF};\n\
    \        Q[8*i+2]={-INF,-INF, x, INF};\n        Q[8*i+3]={-INF,-INF, INF, y};\n\
    \        Q[8*i+4]={x+1,y+1, INF, INF};\n        Q[8*i+5]={-INF,y+1, x, INF};\n\
    \        Q[8*i+6]={-INF,-INF, x, y};\n        Q[8*i+7]={x+1,-INF, INF, y};\n \
    \   }\n    auto prod = zawa::RectangleSumOfPointCloud(P, Q);\n    std::vector<mint>\
    \ p2(N + 1, 1);\n    for (int i = 1 ; i <= N ; i++) p2[i] = p2[i - 1] * mint::raw(2);\n\
    \    mint ans = 0;     \n    for (int i = 0 ; i < N ; i++) {\n        mint val\
    \ = 0;\n        val += p2[prod[8*i+0]] - 1;\n        val += p2[prod[8*i+1]] -\
    \ 1;\n        val += p2[prod[8*i+2]] - 1;\n        val += p2[prod[8*i+3]] - 1;\n\
    \        val -= p2[prod[8*i+4]] - 1;\n        val -= p2[prod[8*i+5]] - 1;\n  \
    \      val -= p2[prod[8*i+6]] - 1;\n        val -= p2[prod[8*i+7]] - 1;\n    \
    \    ans += (p2[N - 1] - 1) - val;\n    }\n    ans += p2[N - 1] * mint::raw(N);\n\
    \    std::cout << ans.val() << '\\n';\n#else\n    std::cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc136_f.test.cpp
  requiredBy: []
  timestamp: '2025-04-25 15:47:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc136_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc136_f.test.cpp
- /verify/Test/AtCoder/abc136_f.test.cpp.html
title: Test/AtCoder/abc136_f.test.cpp
---
