---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/SqrtHeuristicArithmetic.hpp
    title: "Mod of Linear \u3092sqrt(M)\u500B\u306E\u7B49\u5DEE\u6570\u5217\u306B\u5206\
      \u5272\u3059\u308B"
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
    - https://atcoder.jp/contests/abc429/tasks/abc429_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc429/tasks/abc429_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Number/SqrtHeuristicArithmetic.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint = atcoder::modint;\n\n#include <iostream>\nusing namespace std;\n\
    mint f(long long a, long long b, long long x, long long n) {\n    mint res = 0,\
    \ pw = mint{x}.pow(a), sum = 1;\n    while (n) {\n        if (n & 1)\n       \
    \     res = res * pw + sum;\n        sum += sum * pw;\n        pw *= pw;\n   \
    \     n >>= 1;\n    }\n    return res * mint{x}.pow(b);\n}\nmint naive(long long\
    \ N, long long M, long long A, long long B, long long X, long long R) {\n    mint\
    \ res = 0;\n    for (long long i = 0 ; i < N ; i++) {\n        res += mint{X}.pow((A\
    \ * i + B) % M);\n    }\n    return res;\n}\nvoid solve() {\n    long long N,\
    \ M, A, B, X, R;\n    cin >> N >> M >> A >> B >> X >> R;\n    mint::set_mod(R);\n\
    \    long long g = gcd(A, M);\n    A /= g;\n    long long BB = B % g;\n    B /=\
    \ g;\n    M /= g;\n    mint ans = 0; \n    if (N >= M) {\n        mint kiyo =\
    \ f(g, 0, X, M);\n        ans += (N / M) * kiyo;\n        N %= M;\n    }\n   \
    \ for (const auto data : zawa::SqrtHeuristicArithmetic(A, B, M, N)) {\n      \
    \  if (X == 1)\n            ans += mint{data.n};\n        else {\n           \
    \ long long ar = data.a * g;\n            assert(ar != 0);\n            if (ar\
    \ > 0)\n                ans += f(ar, data(0)*g, X, data.n);\n            else\
    \ \n                ans += f(-ar, data(data.n - 1)*g, X, data.n);\n        }\n\
    \    }\n    ans *= mint{X}.pow(BB);\n    cout << ans.val() << '\\n';\n}\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int T;\n    cin >> T;\n    while (T--)\n        solve();\n#else\n    cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Number/SqrtHeuristicArithmetic.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc429_g.test.cpp
  requiredBy: []
  timestamp: '2025-10-27 16:11:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc429_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc429_g.test.cpp
- /verify/Test/AtCoder/abc429_g.test.cpp.html
title: Test/AtCoder/abc429_g.test.cpp
---
