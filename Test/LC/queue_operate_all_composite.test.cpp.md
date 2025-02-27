---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/SWAG.hpp
    title: Src/DataStructure/SWAG/SWAG.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/SWAG/SWAG.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n\n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\
    \nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    int Q;\n    std::cin\
    \ >> Q;\n    SlidingWindowAggregation<AffineMonoid<mint>> swag{};\n    using V\
    \ = typename decltype(swag)::V;\n    while (Q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int a, b;\n            std::cin >>\
    \ a >> b;\n            swag.push(V{a, b});\n        }\n        else if (t == 1)\
    \ {\n            swag.pop();\n        }\n        else if (t == 2) {\n        \
    \    int x;\n            std::cin >> x;\n            std::cout << (swag.empty()\
    \ ? V{} : swag.product())(x).val() << '\\n';\n        }\n        else {\n    \
    \        assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SWAG/SWAG.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2025-02-27 21:25:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/queue_operate_all_composite.test.cpp
- /verify/Test/LC/queue_operate_all_composite.test.cpp.html
title: Test/LC/queue_operate_all_composite.test.cpp
---
