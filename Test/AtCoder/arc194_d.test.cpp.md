---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/SubtreesHash.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u5404\u90E8\u5206\u6728\u3092\u30CF\u30C3\
      \u30B7\u30E5\u5024\u306B\u5909\u63DB\u3057\u305F\u5217"
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
    - https://atcoder.jp/contests/arc194/tasks/arc194_d
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc194/tasks/arc194_d\"\n\n\
    #include \"../../Src/Graph/Tree/SubtreesHash.hpp\"\nusing namespace zawa;\n#include\
    \ \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\n#include <iostream>\n\
    #include <vector>\nint N, SIZE = 1;\nstd::string S;\nstd::vector<int> g[5010];\n\
    mint F[5010], invF[5010];\nmint solve() {\n    std::cin >> N >> S;\n    std::vector<int>\
    \ stk;\n    stk.push_back(0);\n    for (char c : S) {\n        if (c == '(') {\n\
    \            g[stk.back()].push_back(SIZE);\n            stk.push_back(SIZE++);\n\
    \        }\n        else {\n            stk.pop_back();\n        }\n    }\n  \
    \  F[0] = 1;\n    for (int i = 1 ; i <= SIZE ; i++) F[i] = F[i - 1] * mint::raw(i);\n\
    \    invF[SIZE] = F[SIZE].inv();\n    for (int i = SIZE ; i >= 1 ; i--) invF[i\
    \ - 1] = invF[i] * mint::raw(i);\n    auto hash = SubtreesHasher{}(std::vector(g,\
    \ g + SIZE));\n    auto dfs = [&](auto dfs, int v, int p) -> mint {\n        std::vector<int>\
    \ ch;\n        ch.reserve(g[v].size());\n        mint res = 1;\n        for (int\
    \ x : g[v]) if (x != p) {\n            res *= dfs(dfs, x, v);\n            ch.push_back(hash[x]);\n\
    \        }\n        std::sort(ch.begin(), ch.end());\n        res *= F[ch.size()];\n\
    \        for (int i = 0, j = 0 ; i < (int)ch.size() ; i = j) {\n            while\
    \ (j < (int)ch.size() and ch[i] == ch[j]) j++;\n            res *= invF[j - i];\n\
    \        }\n        return res;\n    };\n    return dfs(dfs, 0, -1);\n}\n\nint\
    \ main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    std::cout << solve().val() << '\\\
    n';\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Graph/Tree/SubtreesHash.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc194_d.test.cpp
  requiredBy: []
  timestamp: '2025-04-09 18:50:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc194_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc194_d.test.cpp
- /verify/Test/AtCoder/arc194_d.test.cpp.html
title: Test/AtCoder/arc194_d.test.cpp
---
