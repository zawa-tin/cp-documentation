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
    path: Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C(\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../../Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp\"\n#include\
    \ \"atcoder/modint\"\n\n#include <iostream>\nusing mint = atcoder::modint;\nusing\
    \ namespace std;\nusing namespace zawa;\n\nstruct M {\n    using Element = mint;\n\
    \    static Element identity() {\n        return mint{1};\n    }\n    static Element\
    \ operation(Element L, Element R) {\n        return L * R;\n    }\n    static\
    \ Element action(Element a, Element b) {\n        return a * b;\n    }\n};\n\n\
    struct Hasher {\n    size_t operator()(const mint& v) const {\n        return\
    \ v.val();\n    }\n};\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n   \
    \ ios::sync_with_stdio(0);\n    int T;\n    cin >> T;\n    while (T--) {\n   \
    \     int x, y, m;\n        cin >> x >> y >> m;\n        mint::set_mod(m);\n \
    \       auto ans = MonoidDiscreteLogarithm<M, mint, Hasher>(mint{x}, mint{1},\
    \ mint{y}, m);\n        if (ans)\n            cout << ans.value() << '\\n';\n\
    \        else\n            cout << -1 << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/LC/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2025-08-21 17:55:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/discrete_logarithm_mod.test.cpp
- /verify/Test/LC/discrete_logarithm_mod.test.cpp.html
title: Test/LC/discrete_logarithm_mod.test.cpp
---
