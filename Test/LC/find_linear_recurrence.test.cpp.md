---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/FindLinearRecurrence.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u3092\u767A\u898B\u3059\u308B(Berlekamp-Massey)"
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
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include \"../../Src/Sequence/FindLinearRecurrence.hpp\"\n#include \"atcoder/modint\"\
    \nusing mint=atcoder::modint998244353;\n#include <iostream>\n#include <vector>\n\
    using namespace std;\nint main() {\n    int N;\n    cin >> N;\n    vector<mint>\
    \ A(N);\n    for (int i = 0 ; i < N ; i++) {\n        int a;\n        cin >> a;\n\
    \        A[i]=mint::raw(a);\n    }\n    auto ans=zawa::FindLinearRecurrence(A);\n\
    \    cout << ans.size() << '\\n';\n    for (int i = 0 ; i < ssize(ans) ; i++)\n\
    \        cout << ans[i].val() << (i+1==ssize(ans)?'\\n':' ');\n}\n"
  dependsOn:
  - Src/Sequence/FindLinearRecurrence.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2026-10-03 17:18:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/find_linear_recurrence.test.cpp
- /verify/Test/LC/find_linear_recurrence.test.cpp.html
title: Test/LC/find_linear_recurrence.test.cpp
---
