---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidAction.hpp
    title: Src/Algebra/Monoid/MonoidAction.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/AhoCorasick.hpp
    title: Aho-Corasick
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
    - https://atcoder.jp/contests/abc419/submissions/68657508
    - https://atcoder.jp/contests/abc419/tasks/abc419_f
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc419/tasks/abc419_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 419 F - All Included\n * https://atcoder.jp/contests/abc419/submissions/68657508\n\
    \ */\n\n#include \"../../Src/Sequence/AhoCorasick.hpp\"\n#include \"../../Src/Algebra/Monoid/MonoidAction.hpp\"\
    \n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n#include\
    \ <string>\n\nusing namespace zawa;\nusing namespace std;\nstruct Monoid {\n \
    \   using Element = int;\n    static Element identity() {\n        return 0;\n\
    \    }\n    static Element operation(Element a, Element b) {\n        return a\
    \ | b;\n    }\n};\nusing M = AddSelfAction<Monoid>;\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N, L;\n\
    \    cin >> N >> L;\n    AhoCorasick<string> aho;\n    vector<int> idx(N);\n \
    \   for (int i = 0 ; i < N ; i++) {\n        string s;\n        cin >> s;\n  \
    \      aho.insert(s);\n        idx[i] = 1 << i;\n    }\n    auto [trie, msk] =\
    \ aho.build<M>(idx);\n    vector dp(1 << N, vector<mint>(trie.size()));\n    dp[0][decltype(trie)::Root()]\
    \ = 1;\n    while (L--) {\n        vector nxt(1 << N, vector<mint>(trie.size()));\
    \ \n        for (int b = 0 ; b < (1 << N) ; b++)\n            for (int i = 0 ;\
    \ i < ssize(trie) ; i++)\n                if (dp[b][i] != mint{}) \n         \
    \           for (char c = 'a' ; c <= 'z' ; c++) {\n                        int\
    \ nd = trie.trace(i, c);\n                        nxt[b | msk[nd]][nd] += dp[b][i];\n\
    \                    }\n        dp = move(nxt);\n    }\n    mint ans = accumulate(dp[(1\
    \ << N) - 1].begin(), dp[(1 << N) - 1].end(), mint{});\n    cout << ans.val()\
    \ << '\\n';\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/AhoCorasick.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Algebra/Monoid/MonoidAction.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc419_f.test.cpp
  requiredBy: []
  timestamp: '2025-08-20 19:47:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc419_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc419_f.test.cpp
- /verify/Test/AtCoder/abc419_f.test.cpp.html
title: Test/AtCoder/abc419_f.test.cpp
---
