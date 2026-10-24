---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Differential.hpp
    title: SparseFPS::Differential
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/PowerProduct.hpp
    title: "\u758E\u306AFPS $f,g$ \u306E $f^ng^m$ \u306E\u4FC2\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/SparseFPS.hpp
    title: "\u975E\u96F6\u306E\u4FC2\u6570\u306E\u500B\u6570\u304C\u5341\u5206\u5C11\
      \u306A\u3044FPS"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc276/submissions/80353697
    - https://atcoder.jp/contests/abc276/tasks/abc276_g
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_g\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n/*\n * AtCoder Beginner\
    \ Contest 276 G - Count Sequence\n * https://atcoder.jp/contests/abc276/submissions/80353697\n\
    \ */\n#include \"../../Src/SparseFPS/PowerProduct.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint=atcoder::modint998244353;\n#include <iostream>\nusing namespace zawa;\n\
    using namespace std;\nusing fps=SparseFPS::Series<int,mint>;\nint main() {\n#ifdef\
    \ ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n \
    \   int N,M;\n    cin >> N >> M;\n    fps num,den;\n    num.emplace_back(1,1);\n\
    \    num.emplace_back(2,1);\n    den.emplace_back(0,1);\n    den.emplace_back(3,-1);\n\
    \    auto f=SparseFPS::PowProduct(num,den,N-1,-(N-1),M+1);\n    for (int i = 0\
    \ ; i < 2 ; i++)\n        for (int j = 1 ; j <= M ; j++)\n            f[j]+=f[j-1];\n\
    \    cout << f[M].val() << '\\n';\n#else\n    int a,b;\n    cin >> a >> b;\n \
    \   cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/SparseFPS/PowerProduct.hpp
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  - Src/SparseFPS/Differential.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc276_g.test.cpp
  requiredBy: []
  timestamp: '2026-10-25 00:16:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc276_g.test.cpp
layout: document
title: ABC276-G Count Sequences
---

- 初項 $a_1$ の決め方は $\frac{1}{1-x}$
- $i=2,3,\dots,N$ について、 $a_{i}-a_{i-1}$ の決め方は $\frac{1}{1-x}-\frac{1}{1-x^3}$

よって求めたいものは

$$
\sum_{m=0}^{M}[x^m]\frac{1}{1-x}(\frac{1}{1-x}-\frac{1}{1-x^3})^{N-1} = [x^M]\frac{1}{(1-x)^2}(\frac{1}{1-x}-\frac{1}{1-x^3})^{N-1}
$$

であり、整理すると

$$
[x^M] \frac{1}{(1-x)^2}(\frac{x+x^2}{1-x^3})^{N-1}
$$

となるため、 $(x+x^2)^{N-1}(1-x^3)^{-(N-1)}$ の $0$ 次から $M$ 次までの係数を列挙したあと、二回累積和をとればよい。

さらに上手く整理すると二項定理のみで解けるが、このまま疎なFPSのライブラリを使って解いても、計算量 $O(N+M)$ を達成する。
