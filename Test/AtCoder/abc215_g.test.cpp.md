---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialTaylorShift.hpp
    title: Polynomial Taylor Shift
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
    - https://atcoder.jp/contests/abc215/submissions/65595540
    - https://atcoder.jp/contests/abc215/tasks/abc215_g
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc215/tasks/abc215_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 215 G - Colorful Candies 2\n * https://atcoder.jp/contests/abc215/submissions/65595540\n\
    \ */\n\n#include \"../../Src/FPS/PolynomialTaylorShift.hpp\"\n\n#include \"atcoder/modint\"\
    \n#include \"atcoder/convolution\"\nusing mint = atcoder::modint998244353;\n\n\
    #include <iostream>\n#include <vector>\n#include <algorithm>\nint N, C[50050];\n\
    int main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n\n    std::cin >> N;\n    for (int i =\
    \ 0 ; i < N ; i++) std::cin >> C[i];\n    std::ranges::sort(C, C + N);\n    int\
    \ cnt = 0;\n    std::vector<mint> a(N + 1);\n    for (int i = 0, j = 0 ; i < N\
    \ ; i = j) {\n        while (j < N and C[i] == C[j]) j++;\n        a[N - (j -\
    \ i)]++;\n        cnt++;\n    }\n    auto b = zawa::PolynomialTaylorShift(a, 1,\
    \ atcoder::convolution<mint>);\n    std::vector<mint> fact(N + 1, 1), invfact(N\
    \ + 1);\n    for (int i = 1 ; i <= N ; i++) fact[i] = fact[i - 1] * mint::raw(i);\n\
    \    invfact[N] = fact[N].inv();\n    for (int i = N ; i >= 1 ; i--) invfact[i\
    \ - 1] = invfact[i] * mint::raw(i);\n    for (int k = 1 ; k <= N ; k++) {\n  \
    \      mint ans = mint{cnt} - b[k] * invfact[N] * fact[k] * fact[N - k];\n   \
    \     std::cout << ans.val() << '\\n';\n    }\n#else\n    std::cout << \"Hello\
    \ World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/FPS/PolynomialTaylorShift.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc215_g.test.cpp
  requiredBy: []
  timestamp: '2025-05-09 01:17:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc215_g.test.cpp
layout: document
title: ABC215-G Colorful Candies 2
---

$C$ は座圧されているものとし、 種類 $i (1 \le i \le N)$ のキャンディの個数が $n_{i}$ であるとする。

**期待値の線型性**より、 $K$ 個のキャンディを選択したとき、少なくとも $1$ 個以上の種類 $i$ のキャンディを取る確率を $i = 1, 2, \dots, N$ について計算できれば良い。

余事象を考えると、 $K$ に対して解は $\frac{1}{\binom{N}{K}}\sum_{i = 1}^{N}(\binom{N}{K}-\binom{N-n_{i}}{K})$ である。

$=N-\frac{1}{\binom{N}{K}}\sum_{i=1}^{N}\binom{N-n_{i}}{K}$

結局の所 $\sum_{i=1}^{N}\binom{N-n_{i}}{K}$ が全ての $K$ で計算できれば良い。

$f(x) = \sum_{i = 0}^{N} \sum_{j = 1}^{N}\binom{N-n_{j}}{i}x^{i}$ とすると...

$= \sum_{j = 1}^{N} \sum_{i = 0}^{N} \binom{N-n_{j}}{i}x^{i} = \sum_{j = 1}^{N} (1+x)^{N-n_{j}}$ (二項定理)

よって $g(x) = \sum_{j = 1}^{N} x^{N-n_{j}}$ をPolynomial Taylor Shiftすることで $f(x)$ の係数列が $O(N\log N)$ で計算できて、元の解も求まった。
