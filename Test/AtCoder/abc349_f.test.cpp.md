---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactor.hpp
    title: Src/Number/PrimeFactor.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactorize.hpp
    title: Src/Number/PrimeFactorize.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc349/tasks/abc349_f
    links:
    - https://atcoder.jp/contests/abc349/tasks/abc349_f
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc349/tasks/abc349_f\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/Number/PrimeFactorize.hpp\"\
    \n#include \"atcoder/modint\"\n\n#include <iostream>\n#include <map>\n\nusing\
    \ namespace zawa;\nusing mint = atcoder::modint998244353;\n\nint main() {\n  \
    \  SetFastIO(); \n\n    int N;\n    long long M;\n    std::cin >> N >> M;\n  \
    \  std::map<long long, int> map;\n    int NN{};\n    for (int i{} ; i < N ; i++)\
    \ {\n        long long A;\n        std::cin >> A;\n        if (M % A == 0) {\n\
    \            map[A]++;\n        }\n        else {\n            NN++;\n       \
    \ }\n    }\n    N -= NN;\n    if (M == 1) {\n        std::cout << mint{mint::raw(2).pow(N)\
    \ - 1}.val() << '\\n';\n        return 0;\n    }\n    std::vector A(map.begin(),\
    \ map.end());\n    auto F{PrimeFactorize((unsigned long long)M)};\n    std::vector<int>\
    \ B(A.size());\n    for (int i{} ; i < (int)F.size() ; i++) {\n        long long\
    \ mult{1};\n        for (int j{} ; j < (int)F[i].exponent() ; j++) {\n       \
    \     mult *= F[i].factor();\n        }\n        for (int j{} ; j < (int)A.size()\
    \ ; j++) {\n            if (A[j].first % mult == 0) {\n                B[j] |=\
    \ (1 << i);\n            }\n        }\n    }\n    std::vector<mint> P2(N + 1,\
    \ mint::raw(1));\n    for (int i{} ; i < N ; i++) {\n        P2[i + 1] = P2[i]\
    \ * mint::raw(2);\n    }\n    mint ans{P2[N] - 1};\n    for (int bit{1} ; bit\
    \ < (1 << (int)F.size()) ; bit++) {\n        int num{};\n        for (int i{}\
    \ ; i < (int)A.size() ; i++) {\n            if (B[i] & bit) {\n              \
    \  continue;\n            }\n            num += A[i].second;\n        }\n    \
    \    ans -= (__builtin_popcount(bit) % 2 ? +1 : -1) * (P2[num] - 1);\n    }\n\
    \    std::cout << ans.val() << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeFactorize.hpp
  - Src/Number/PrimeFactor.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc349_f.test.cpp
  requiredBy: []
  timestamp: '2024-06-30 19:07:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc349_f.test.cpp
layout: document
title: ABC349-F Subsequence LCM
---

$M$ で割り切れないような要素を部分列に含めると必ず部分列の最小公倍数は $M$ で無くなる。以後 $A$ のすべての要素が $M$ で割り切れることを仮定する。

$M$ を素因数分解して、 $M = \prod p_{i}^{e_{i}}$ という表示を得たとする。 この $(p_{i}, e_{i})$ を順に並べた列を $F$ とする。

$A$ のすべての要素が $M$ で割り切れるとして、 $A$ のある部分列の最小公倍数が $M$ とならない必要十分条件は以下の通りである。

ある $F$ の要素 $(p_{i}, e_{i})$ が存在して、部分列のすべての要素が $p_{i}^{e_{i}}$ で割り切れない。

このことから包除原理を適用して数え上げることができる。 $F$ のすべての部分列 $F'$ について $\prod_{i\in F'} p_{i}^{e_{i}}$ で割り切れないように $A$ から部分列を取る通り数を数えれば良い。

$M\le 10^{16}$ ゆえ、 $\mid F \mid \le 13$ である。 $A$ のすべての要素は $M$ で割り切れるという仮定から $A$ の要素の種類数は $43008$ 以下である。

- [参考: 高度合成数](https://algo-method.com/descriptions/92)
