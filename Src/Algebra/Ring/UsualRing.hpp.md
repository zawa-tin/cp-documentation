---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3369.test.cpp
    title: Test/AOJ/3369.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/aalc001_o.test.cpp
    title: "\u30BB\u30B0\u6728\u30B3\u30F3 O - \u6700\u5C0F\u5024 (\u5C65\u6B74\u548C\
      \u306E\u30C6\u30AF\u30CB\u30C3\u30AF)"
  - icon: ':heavy_check_mark:'
    path: Test/CF/ECR157-F.test.cpp
    title: Test/CF/ECR157-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/matrix_det.test.cpp
    title: Test/LC/matrix_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Ring/UsualRing.hpp\"\n\n#include <type_traits>\n\
    \n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(T l,T r) noexcept {\n        return l + r;\n    }\n    static constexpr\
    \ T inverse(T v) noexcept {\n        return -v;\n    }\n    template <class U>\n\
    \    static constexpr T power(T v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n\
    \    }\n};\n\n} // namespace zawa\n#line 6 \"Src/Algebra/Ring/UsualRing.hpp\"\n\
    \nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class T>\nstruct Multiplication\
    \ {\n\n    using Element = T;\n\n    static constexpr Element identity() {\n \
    \       return static_cast<Element>(1);\n    }\n\n    static constexpr Element\
    \ operation(const Element& lhs, const Element& rhs) {\n        return lhs * rhs;\n\
    \    }\n\n    static constexpr Element inverse(const Element& value) {\n     \
    \   return identity() / value;\n    }\n};\n\n} // namespace internal\n\ntemplate\
    \ <class T>\nstruct UsualRing {\n\n    using Element = T;\n\n    using Addition\
    \ = AdditiveGroup<T>;\n\n    using Multiplication = typename internal::Multiplication<T>;\n\
    \n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <type_traits>\n\n#include \"../Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class T>\nstruct Multiplication\
    \ {\n\n    using Element = T;\n\n    static constexpr Element identity() {\n \
    \       return static_cast<Element>(1);\n    }\n\n    static constexpr Element\
    \ operation(const Element& lhs, const Element& rhs) {\n        return lhs * rhs;\n\
    \    }\n\n    static constexpr Element inverse(const Element& value) {\n     \
    \   return identity() / value;\n    }\n};\n\n} // namespace internal\n\ntemplate\
    \ <class T>\nstruct UsualRing {\n\n    using Element = T;\n\n    using Addition\
    \ = AdditiveGroup<T>;\n\n    using Multiplication = typename internal::Multiplication<T>;\n\
    \n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: false
  path: Src/Algebra/Ring/UsualRing.hpp
  requiredBy: []
  timestamp: '2026-10-08 17:25:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/ECR157-F.test.cpp
  - Test/AOJ/3369.test.cpp
  - Test/AtCoder/aalc001_o.test.cpp
  - Test/LC/matrix_det.test.cpp
documentation_of: Src/Algebra/Ring/UsualRing.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Ring/UsualRing.hpp
- /library/Src/Algebra/Ring/UsualRing.hpp.html
title: Src/Algebra/Ring/UsualRing.hpp
---
