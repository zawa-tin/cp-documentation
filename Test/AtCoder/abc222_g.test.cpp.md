---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc222/submissions/68673469
    - https://atcoder.jp/contests/abc222/tasks/abc222_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.12/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc222/tasks/abc222_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 222 G - 222\n * https://atcoder.jp/contests/abc222/submissions/68673469\n\
    \ */\n\n#include \"../../Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp\"\n#include\
    \ \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\n#include \"atcoder/modint\"\n\
    \n#include <iostream>\n#include <utility>\nusing namespace std;\nusing namespace\
    \ zawa;\nusing mint = atcoder::modint;\nstruct X : public AffineMonoid<mint> {\n\
    \    using super = AffineMonoid<mint>;\n    static mint action(super::Element\
    \ f, mint x) {\n        return f(x);\n    }\n};\nstruct Hasher {\n    size_t operator()(const\
    \ mint& v) const {\n        return v.val();\n    }\n};\nlong long P;\nlong long\
    \ solve() {\n    mint::set_mod(P);\n    auto ans = MonoidDiscreteLogarithm<X,\
    \ mint, Hasher>(Affine<mint>{10, 2}, mint{2}, mint{0}, P);\n    if (ans)\n   \
    \     return ans.value() + 1;\n    else\n        return -1;\n}\nint main() {\n\
    #ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int T;\n    cin >> T;\n    while (T--) {\n        cin >> P;\n        cout\
    \ << solve() << '\\n';\n    }\n#else\n    cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc222_g.test.cpp
  requiredBy: []
  timestamp: '2025-11-20 00:22:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc222_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc222_g.test.cpp
- /verify/Test/AtCoder/abc222_g.test.cpp.html
title: Test/AtCoder/abc222_g.test.cpp
---
