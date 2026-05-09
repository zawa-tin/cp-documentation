---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
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
    - https://atcoder.jp/contests/abc457/submissions/75681374
    - https://atcoder.jp/contests/abc457/tasks/abc457_f
    - https://judge.yosupo.jp/problem/aplusb
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
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc457/tasks/abc457_f\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * AtCoder Beginner\
    \ Contest 457 F - Second Gap\n * https://atcoder.jp/contests/abc457/submissions/75681374\n\
    \ */\n\n#include \"../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\
    using namespace zawa;\n\n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\
    \n#include <iostream>\n#include <vector>\n#include <optional>\nusing namespace\
    \ std;\nstruct M {\n    using Element = pair<optional<mint>,mint>;\n    static\
    \ Element identity() {\n        return {nullopt,1};\n    }\n    static Element\
    \ operation(Element L, Element R) {\n        if (R.first)\n            return\
    \ R;\n        L.second *= R.second;\n        return L;\n    }\n    static mint\
    \ action(Element o,mint x) {\n        if (o.first)\n            return o.first.value()\
    \ * o.second;\n        else\n            return x * o.second;\n    }\n};\nint\
    \ main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    vector<int> D(N-1);\n    for (auto& x : D)\n \
    \       cin >> x;\n    DualSegmentTree<M,mint> dp(N);\n    dp.assign(N-2,mint::raw(1));\n\
    \    dp.assign(N-1,mint::raw(1));\n    int cnt = 2;\n    int pr = D[N-2];\n  \
    \  for (int i = N - 3 ; i >= 0 ; i--) {\n        mint val = dp[i+D[i]];\n    \
    \    if (pr == D[i])\n            dp.operation(i+1,N,{nullopt,cnt-1});\n     \
    \   else\n            dp.operation(i+1,N,{0,1});\n        dp.assign(i,val);\n\
    \        mint x = val + dp[i+D[i]];\n        dp.assign(i+D[i],x);\n        pr\
    \ = D[i];\n        cnt++;\n    }\n    mint ans = 0;\n    for (auto i : dp.container())\n\
    \        ans += i;\n    cout << ans.val() << '\\n';\n#else\n    int a,b;\n   \
    \ cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc457_f.test.cpp
  requiredBy: []
  timestamp: '2026-05-10 03:36:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc457_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc457_f.test.cpp
- /verify/Test/AtCoder/abc457_f.test.cpp.html
title: Test/AtCoder/abc457_f.test.cpp
---
