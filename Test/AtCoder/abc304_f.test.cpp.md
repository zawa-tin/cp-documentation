---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeSubsetTransform.hpp
    title: Src/Number/PrimeSubsetTransform.hpp
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
    - https://atcoder.jp/contests/abc304/submissions/69569939
    - https://atcoder.jp/contests/abc304/tasks/abc304_f
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc304/tasks/abc304_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 304 F - Shift Table\n * https://atcoder.jp/contests/abc304/submissions/69569939\n\
    \ */\n\n#include \"../../Src/Number/PrimeSubsetTransform.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint = atcoder::modint998244353;\n\n#include <algorithm>\n#include <vector>\n\
    #include <iostream>\n#include <string>\nusing namespace std;\nvoid solve() {\n\
    \    int N;\n    string S;\n    cin >> N >> S;\n    vector<mint> p2(N + 1, 1);\n\
    \    for (int i = 1 ; i <= N ; i++)\n        p2[i] = p2[i - 1] * mint::raw(2);\n\
    \    vector<mint> a(N + 1);\n    for (int m = 1 ; m <= N ; m++)\n        if (N\
    \ % m == 0) {\n            vector<bool> ng(m);\n            for (int i = 0 ; i\
    \ < N ; i++)\n                if (S[i] == '.')\n                    ng[i % m]\
    \ = 1;\n            a[m] = p2[ranges::count(ng, 0)];\n        }\n    zawa::PrimeSubsetMobiusTransform(a);\n\
    \    mint ans = 0;\n    for (int m = 1 ; m < N ; m++)\n        if (N % m == 0)\n\
    \            ans += a[m];\n    cout << ans.val() << '\\n';\n}\nint main() {\n\
    #ifdef ATCODER\n    solve();\n#else\n    cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  dependsOn:
  - Src/Number/PrimeSubsetTransform.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc304_f.test.cpp
  requiredBy: []
  timestamp: '2025-09-23 17:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc304_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc304_f.test.cpp
- /verify/Test/AtCoder/abc304_f.test.cpp.html
title: Test/AtCoder/abc304_f.test.cpp
---
