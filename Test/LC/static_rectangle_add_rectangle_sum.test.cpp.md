---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
    title: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
    title: Rectangle Sum of Rectangles
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
    PROBLEM: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n#include \"../../Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp\"\
    \n#include \"atcoder/modint\"\nusing mint=atcoder::modint998244353;\n#include\
    \ <iostream>\nusing namespace std;\nstruct RectAdd {\n    using P=int;\n    using\
    \ W=mint;\n    int l,d,r,u;\n    mint w;\n};\nstruct Rect {\n    using P=int;\n\
    \    int l,d,r,u;\n};\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<RectAdd> rs(N);\n    for (auto&\
    \ r : rs) {\n        int w;\n        cin >> r.l >> r.d >> r.r >> r.u >> w;\n \
    \       r.w=mint::raw(w);\n    }\n    vector<Rect> qs(Q);\n    for (auto& r :\
    \ qs) \n        cin >> r.l >> r.d >> r.r >> r.u;\n    for (mint ans : zawa::RectangleSumOfRectangles(rs,qs))\n\
    \        cout << ans.val() << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
  isVerificationFile: true
  path: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-02 17:24:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/static_rectangle_add_rectangle_sum.test.cpp
- /verify/Test/LC/static_rectangle_add_rectangle_sum.test.cpp.html
title: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
---
