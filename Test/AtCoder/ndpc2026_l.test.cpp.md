---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/LinearSieve.hpp
    title: "\u7DDA\u5F62\u7BE9 (osa-k\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactor.hpp
    title: Src/Number/PrimeFactor.hpp
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
    - https://atcoder.jp/contests/ndpc/submissions/75550273
    - https://atcoder.jp/contests/ndpc/tasks/ndpc2026_l
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/ndpc/tasks/ndpc2026_l\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * Next DP Contest L - \u6700\u5C0F\u516C\u500D\u6570\n * https://atcoder.jp/contests/ndpc/submissions/75550273\n\
    \ */\n\n#include \"../../Src/Number/LinearSieve.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint = atcoder::modint998244353;\n\n#include <algorithm>\n#include <iostream>\n\
    #include <ranges>\n#include <vector>\nusing namespace std;\n\nint main() {\n#ifdef\
    \ ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n \
    \   int N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto& x : A)\n    \
    \    cin >> x;\n    zawa::LinearSieve siv(N);\n    vector<mint> table(N+1), inv(N+1);\n\
    \    for (int i = 1 ; i <= N ; i++)\n        inv[i] = mint::raw(i).inv();\n  \
    \  for (int d : siv.divisor<int>(A[0]))\n        table[d] = A[0];\n    for (int\
    \ i = 1 ; i < N ; i++) {\n        vector<int> ds = siv.divisor<int>(A[i]), ps\
    \ = siv.primeFactors<int>(A[i]);\n        ranges::sort(ds);\n        // mobius\n\
    \        for (int p : ps)\n            for (int d : ds)\n                if (A[i]\
    \ % (p*d) == 0)\n                    table[d] -= table[p*d];\n        mint ans\
    \ = 0;\n        for (int d : ds)\n            ans += inv[d] * table[d];\n    \
    \    ans *= mint::raw(A[i]);\n        cout << ans.val() << '\\n';\n        //\
    \ zeta\n        for (int p : ps)\n            for (int d : ds | views::reverse)\n\
    \                if (d % p == 0)\n                    table[d/p] += table[d];\n\
    \        for (int d : ds)\n            table[d] += mint::raw(A[i]) * ans;\n  \
    \  }\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Number/LinearSieve.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeFactor.hpp
  isVerificationFile: true
  path: Test/AtCoder/ndpc2026_l.test.cpp
  requiredBy: []
  timestamp: '2026-05-06 18:05:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/ndpc2026_l.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/ndpc2026_l.test.cpp
- /verify/Test/AtCoder/ndpc2026_l.test.cpp.html
title: Test/AtCoder/ndpc2026_l.test.cpp
---
