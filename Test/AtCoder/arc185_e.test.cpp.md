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
    - https://atcoder.jp/contests/arc185/submissions/66241326
    - https://atcoder.jp/contests/arc185/tasks/arc185_e
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc185/tasks/arc185_e\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Regular Contest 185 - E Adjacent GCD\n * https://atcoder.jp/contests/arc185/submissions/66241326\n\
    \ */\n\n#include \"../../Src/Number/LinearSieve.hpp\"\nusing namespace zawa;\n\
    #include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\n#include\
    \ <iostream>\n#include <vector>\n#include <numeric>\n\nconst int MAX = 100000;\n\
    int N, A[500050];\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cin\
    \ >> N;\n    for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n    LinearSieve\
    \ siv{MAX + 1};\n    std::vector<mint> x(MAX + 1), a(MAX + 1);\n    // \u91CD\u307F\
    \u306E\u5217Y\n    std::iota(x.begin(), x.end(), mint::raw(0));\n    // mobius\
    \ transform\u3067X\u3092\u5F97\u308B\n    for (int i = 1 ; i <= MAX ; i++) if\
    \ (siv.isPrime(i)) {\n        for (int j = MAX / i ; j >= 1 ; j--) x[i * j] -=\
    \ x[j];\n    }\n    std::vector<mint> p2(N, mint::raw(1));\n    for (int i = 1\
    \ ; i < N ; i++) p2[i] *= p2[i - 1] * mint::raw(2);\n    mint ans = 0;\n    for\
    \ (int i = 0 ; i < N ; i++, ans *= mint::raw(2)) {\n        for (int d : siv.divisor<int>(A[i]))\
    \ {\n            ans += x[d] * a[d];\n            a[d] += p2[i];\n        }\n\
    \        std::cout << ans.val() << '\\n';\n    }\n#else\n    std::cout << \"Hello\
    \ World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Number/LinearSieve.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeFactor.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc185_e.test.cpp
  requiredBy: []
  timestamp: '2025-05-29 15:37:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc185_e.test.cpp
layout: document
title: "ABC185-E Adjacent GCD (\u7D04\u6570\u30FB\u500D\u6570\u95A2\u4FC2\u306E\u9AD8\
  \u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
---

整数 $a, b$ に関して $a$ が $b$ の約数であることを $a\mid b$ と表記する。

## 約数関係のメビウス変換

$x_{i} = \sum_{j\mid i} y_{j}$ を満たす $x, y$ に対して、 $x$ から $y$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = MAX / p ; k >= 1 ; k--) x[p * k] -= x[k];
}
```

## 約数関係のゼータ変換

$x_{i} = \sum_{j\mid i} y_{j}$ を満たす $x, y$ に対して、 $y$ から $x$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = 1 ; p * k <= MAX ; k++) y[p * k] += y[k];
}
```

## 倍数関係のメビウス変換

$x_{i} = \sum_{i\mid j} y_{j}$ を満たす $x, y$ に対して、 $x$ から $y$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = 1 ; k * p <= MAX ; k++) x[k] -= x[p * k];
}
```

## 倍数関係のゼータ変換

$x_{i} = \sum_{i\mid j} y_{j}$ を満たす $x, y$ に対して、 $y$ から $x$ を $\Theta (N\log \log N)$ で得ることができる。

```cpp
for (int p = 1 ; p <= MAX ; p++) if (p is prime) {
    for (int k = 1 ; k * p <= MAX ; k++) y[k] += y[p * k];
}
```

## コンテスト中

どっちがどっちだが頭が壊れた -> $1$ の方に値が集まっているなら倍数関係、 $N$ の方に値が集まっているなら約数関係

包除原理とか考えると大体嵌る。多次元累積和をとっていると考えて向きを考えるとすっと変換の式が書けるはず。

ゼータ・メビウス変換をする上で、メビウス関数を陽に求める必要は無い。また、考察上でも変換するだけならメビウス関数は出てこない。

## 参考

- [ユーザー解説 ARC185-E](https://atcoder.jp/contests/arc185/editorial/11161)
