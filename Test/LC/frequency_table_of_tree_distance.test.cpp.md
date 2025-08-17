---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Centroid.hpp
    title: "\u6728\u306E\u91CD\u5FC3"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.6/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Graph/Tree/Centroid.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\nusing namespace\
    \ zawa;\n\n#include \"atcoder/convolution\"\n\nint main() {\n    SetFastIO();\n\
    \    int N;\n    std::cin >> N;\n    std::vector<std::vector<int>> T(N);\n   \
    \ for (int i{} ; i < N - 1 ; i++) {\n        int a, b;\n        std::cin >> a\
    \ >> b;\n        T[a].push_back(b);\n        T[b].push_back(a);\n    }\n    Centroid\
    \ C(std::move(T));\n    std::vector<int> dep(N);\n    auto calc_dep{[&](auto dfs,\
    \ int v, int p, int d) -> void {\n        dep[v] = d;\n        for (auto x : C[v])\
    \ if ((int)x != p and !C.isRemoved(x)) {\n            dfs(dfs, x, v, d + 1);\n\
    \        }\n    }};\n    std::vector<long long> ans(N);\n    auto dfs{[&](auto\
    \ dfs, int v) -> void {\n        v = C.rooting(v);\n        calc_dep(calc_dep,\
    \ v, -1, 0);\n        C.remove(v);\n        std::vector<std::vector<int>> subtree;\n\
    \        for (auto x : C.adjlist(v)) {\n            subtree.push_back(C.component(x));\n\
    \        }\n        std::vector<long long> sq_sum, sum_sq;\n        for (const\
    \ auto& comp : subtree) {\n            int max_d{};\n            for (auto x :\
    \ comp) max_d = std::max(max_d, dep[x]);\n            std::vector<long long> cur(max_d\
    \ + 1);\n            for (auto x : comp) {\n                ans[dep[x]]++; //\
    \ v\u3092\u7AEF\u70B9\u3068\u3057\u305F\u30D1\u30B9\u306E\u5BC4\u4E0E\n      \
    \          cur[dep[x]]++;\n            }\n            while (sum_sq.size() < cur.size())\
    \ sum_sq.push_back(0LL);\n            for (int i{} ; i < (int)cur.size() ; i++)\
    \ {\n                sum_sq[i] += cur[i];\n            }\n            cur = atcoder::convolution_ll(cur,\
    \ cur);\n            while (sq_sum.size() < cur.size()) sq_sum.push_back(0LL);\n\
    \            for (int i{} ; i < (int)cur.size() ; i++) {\n                sq_sum[i]\
    \ += cur[i];\n            }\n        }\n        sum_sq = atcoder::convolution_ll(sum_sq,\
    \ sum_sq);\n        for (int i{} ; i < (int)sum_sq.size() ; i++) {\n         \
    \   ans[i] += sum_sq[i] >> 1;\n        }\n        for (int i{} ; i < (int)sq_sum.size()\
    \ ; i++) {\n            ans[i] -= sq_sum[i] >> 1;\n        }\n        for (auto\
    \ x : C.adjlist(v)) {\n            dfs(dfs, x);\n        }\n    }};\n    dfs(dfs,\
    \ 0);\n    for (int i{1} ; i < N ; i++) {\n        std::cout << ans[i] << (i +\
    \ 1 == N ? '\\n' : ' ');\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/Centroid.hpp
  isVerificationFile: true
  path: Test/LC/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2024-12-06 16:40:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/frequency_table_of_tree_distance.test.cpp
- /verify/Test/LC/frequency_table_of_tree_distance.test.cpp.html
title: Test/LC/frequency_table_of_tree_distance.test.cpp
---
