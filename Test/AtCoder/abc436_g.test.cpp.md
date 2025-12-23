---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/BostanMori.hpp
    title: "$[x^{N}]\\frac{P(x)}{Q(x)}$ \u306E\u9AD8\u901F\u8A08\u7B97 (Bostan-Mori\
      \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPSNTTFriendly.hpp
    title: Src/FPS/FPSNTTFriendly.hpp
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
    - https://atcoder.jp/contests/abc436/submissions/71935256
    - https://atcoder.jp/contests/abc436/tasks/abc436_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc436/tasks/abc436_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 436 G - Linear Inequation\n * https://atcoder.jp/contests/abc436/submissions/71935256\n\
    \ */\n\n#include \"../../Src/FPS/BostanMori.hpp\"\nusing namespace zawa;\nusing\
    \ mint = atcoder::modint998244353;\nusing fps = FPSNTTFriendly<mint::mod()>;\n\
    \n#include <iostream>\nusing namespace std;\n\nint main() {\n#ifdef ATCODER\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N;\n\
    \    long long M;\n    cin >> N >> M;\n    fps Q{1, -1};\n    while (N--) {\n\
    \        int a;\n        cin >> a;\n        fps f(a + 1);\n        f[0] = 1;\n\
    \        f[a] = -1;\n        Q *= f;\n    }\n    cout << BostanMori(M, fps{1},\
    \ Q).val() << '\\n';\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/FPS/BostanMori.hpp
  - Src/FPS/FPSNTTFriendly.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc436_g.test.cpp
  requiredBy: []
  timestamp: '2025-12-23 20:35:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc436_g.test.cpp
layout: document
title: ABC436-G Linear Inequation
---

$A_{N + 1} = 1$ を追加することで、 $\sum_{i}A_ix_i = M$ を満たす $x$ を数えることに帰着する。 要は[貯金箱の焦り](https://yukicoder.me/problems/no/137)をすれば良い。

- 貯金箱の焦りdpとか、桁上がりを考慮する桁dpと言われていたり、自分で呼んでいたりするもの。

このdpのテクニックの肝は「$x$ を何個でも選べる」を「 $x, 2x, 4x, 8x, \dots$ をそれぞれコスト $1, 2, 4, 8, \dots, $ かかるとして高々 $1$ 個とる」という話に置き換えるところだと思っている。

実は、あまり賢いことをしなくても $[x^{M}]1/\prod_{i}(1-x^{A_{i}})$ なのでBostan-Moriをして終わり。
