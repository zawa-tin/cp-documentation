---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ChminMonoid.hpp
    title: Src/Algebra/Monoid/ChminMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree (\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
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
    PROBLEM: https://atcoder.jp/contests/abc340/tasks/abc340_g
    links:
    - https://atcoder.jp/contests/abc340/tasks/abc340_g
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc340/tasks/abc340_g\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Graph/Tree/AuxiliaryTree.hpp\"\
    \n#include \"atcoder/modint\"\n\n#include <array>\n#include <algorithm>\n#include\
    \ <iostream>\n#include <set>\n\nusing namespace zawa;\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n    int N;\n    std::cin >> N;\n    std::vector<std::vector<int>>\
    \ A(N);\n    std::vector<int> col(N);\n    for (int i{} ; i < N ; i++) {\n   \
    \     std::cin >> col[i];\n        col[i]--;\n        A[col[i]].push_back(i);\n\
    \    }\n    std::vector<std::vector<int>> g(N);\n    for (int i{} ; i < N - 1\
    \ ; i++) {\n        int u, v;\n        std::cin >> u >> v;\n        u--; v--;\n\
    \        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n    AuxiliaryTree\
    \ AT{g};\n    mint ans{};\n    for (int c{} ; c < N ; c++) {\n        if (A[c].empty())\
    \ {\n            continue;\n        }\n        int r{(int)AT.construct(A[c])};\n\
    \        auto dfs{[&](auto dfs, int v, int p) -> mint {\n            std::array<mint,\
    \ 3> dp{ mint{1}, mint{0}, mint{0} };\n            for (auto x : AT[v]) {\n  \
    \              if ((int)x == p) continue;\n                std::array<mint, 3>\
    \ next{ dp };\n                mint chval{dfs(dfs, x, v)};\n                for\
    \ (int i{} ; i < 3 ; i++) {\n                    next[std::min(2, i + 1)] += dp[i]\
    \ * chval;\n                }\n                dp = next;\n            }\n   \
    \         ans += dp[2];\n            if (col[v] == c) {\n                dp[1]++;\n\
    \                ans += dp[1];\n            }\n            return dp[1] + dp[2];\n\
    \        }};\n        dfs(dfs, r, -1);\n    }\n    std::cout << ans.val() << '\\\
    n';\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/AuxiliaryTree.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Algebra/Monoid/ChminMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc340_g.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:29:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc340_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc340_g.test.cpp
- /verify/Test/AtCoder/abc340_g.test.cpp.html
title: Test/AtCoder/abc340_g.test.cpp
---
