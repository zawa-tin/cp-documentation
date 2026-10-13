---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Combinatorics/BinomialCoefficientPrefixSums.hpp
    title: "\u4E8C\u9805\u4FC2\u6570prefix sum $(\\sum_{i=0}^{k}\\binom{n}{i})$"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/Mo.hpp
    title: Src/Utility/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/tenka1-2014-final/submissions/80011789
    - https://atcoder.jp/contests/tenka1-2014-final/tasks/tenka1_2014_final_d
    - https://judge.yosupo.jp/problem/aplusb
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/tenka1-2014-final/tasks/tenka1_2014_final_d\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * \u5929\u4E0B\
    \u4E00\u30D7\u30ED\u30B0\u30E9\u30DE\u30FC\u30B3\u30F3\u30C6\u30B9\u30C82014\u672C\
    \u6226 D - \u9AD8\u6A4B\u541B\n * https://atcoder.jp/contests/tenka1-2014-final/submissions/80011789\n\
    \ */\n#include \"../../Src/Combinatorics/BinomialCoefficientPrefixSums.hpp\"\n\
    #include \"atcoder/modint\"\n#include <iostream>\n#include <utility>\n#include\
    \ <vector>\nusing mint=atcoder::modint1000000007;\nusing namespace std;\nint main()\
    \ {\n#ifdef ATCODER\n    int T;\n    cin >> T;\n    vector<pair<int,int>> NK(T);\n\
    \    for (auto& [n,k] : NK)\n        cin >> n >> k;\n    for (auto ans : zawa::BinomialCoefficientPrefixSums<mint>(NK))\n\
    \        cout << ans.val() << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n\
    \    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Combinatorics/BinomialCoefficientPrefixSums.hpp
  - Src/Utility/Mo.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/tenka1_2014_final_d.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 17:51:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/tenka1_2014_final_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/tenka1_2014_final_d.test.cpp
- /verify/Test/AtCoder/tenka1_2014_final_d.test.cpp.html
title: Test/AtCoder/tenka1_2014_final_d.test.cpp
---
