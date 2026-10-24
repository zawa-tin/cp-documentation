---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Differential.hpp
    title: SparseFPS::Differential
  - icon: ':heavy_check_mark:'
    path: Src/SparseFPS/Exp.hpp
    title: SparseFPS::Exp
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
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\
    \n#include \"../../Src/SparseFPS/Exp.hpp\"\n#include \"atcoder/modint\"\nusing\
    \ mint=atcoder::modint998244353;\n#include <iostream>\nusing namespace std;\n\
    using namespace zawa;\nusing fps=SparseFPS::Series<int,mint>;\nint main() {\n\
    \    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,K;\n\
    \    cin >> N >> K;\n    fps f(K);\n    for (auto& t : f) {\n        int i,a;\n\
    \        cin >> i >> a;\n        t={i,mint::raw(a)};\n    }\n    auto ans=Exp(move(f),N);\n\
    \    for (int i = 0 ; i < N ; i++)\n        cout << ans[i].val() << (i+1==N?'\\\
    n':' ');\n}\n"
  dependsOn:
  - Src/SparseFPS/Exp.hpp
  - Src/Template/TypeAlias.hpp
  - Src/SparseFPS/SparseFPS.hpp
  - Src/SparseFPS/Differential.hpp
  isVerificationFile: true
  path: Test/LC/exp_of_formal_power_series_sparse.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 18:04:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/exp_of_formal_power_series_sparse.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/exp_of_formal_power_series_sparse.test.cpp
- /verify/Test/LC/exp_of_formal_power_series_sparse.test.cpp.html
title: Test/LC/exp_of_formal_power_series_sparse.test.cpp
---
