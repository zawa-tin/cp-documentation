---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/FoldableQueue.hpp
    title: Foldable Queue
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/SWAG/FoldableQueue.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n\n#include \"atcoder/modint\"\nusing mint = atcoder::modint998244353;\n\
    \nusing namespace zawa;\n\nint main() {\n    SetFastIO();\n    int Q;\n    std::cin\
    \ >> Q;\n    FoldableQueue<AffineMonoid<mint>> que{};\n    using V = typename\
    \ AffineMonoid<mint>::Element;\n    while (Q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int a, b;\n            std::cin >>\
    \ a >> b;\n            que.push(V{a, b});\n        }\n        else if (t == 1)\
    \ {\n            que.pop();\n        }\n        else if (t == 2) {\n         \
    \   int x;\n            std::cin >> x;\n            std::cout << (que.empty()\
    \ ? V{} : que.product())(x).val() << '\\n';\n        }\n        else {\n     \
    \       assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SWAG/FoldableQueue.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2025-04-16 16:40:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/queue_operate_all_composite.test.cpp
- /verify/Test/LC/queue_operate_all_composite.test.cpp.html
title: Test/LC/queue_operate_all_composite.test.cpp
---
