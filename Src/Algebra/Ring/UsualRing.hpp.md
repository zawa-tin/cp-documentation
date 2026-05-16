---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/ECR157-F.test.cpp
    title: Test/CF/ECR157-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/matrix_det.test.cpp
    title: Test/LC/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3369.test.cpp
    title: "AOJ3369 Namori Counting (\u884C\u5217\u6728\u5B9A\u7406)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Ring/UsualRing.hpp\"\n\n#include <type_traits>\n\
    \nnamespace zawa {\n\nnamespace internal {\n\ntemplate <class T>\nstruct Addition\
    \ {\n    using Element = T;\n    static Element identity() {\n        return static_cast<Element>(0);\n\
    \    }\n    static Element operation(const Element& lhs, const Element& rhs) {\n\
    \        return lhs + rhs;\n    }\n    static Element inverse(const Element& v)\
    \ {\n        return -v;\n    }\n};\n\ntemplate <class T>\nstruct Multiplication\
    \ {\n    using Element = T;\n    static Element identity() {\n        return static_cast<Element>(1);\n\
    \    }\n    static Element operation(const Element& lhs, const Element& rhs) {\n\
    \        return lhs * rhs;\n    }\n    static Element inverse(const Element& value)\
    \ {\n        return identity() / value;\n    }\n};\n\n} // namespace internal\n\
    \ntemplate <class T>\nstruct UsualRing {\n    using Element = T;\n    using Addition\
    \ = typename internal::Addition<T>;\n    using Multiplication = typename internal::Multiplication<T>;\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <type_traits>\n\nnamespace zawa {\n\nnamespace internal\
    \ {\n\ntemplate <class T>\nstruct Addition {\n    using Element = T;\n    static\
    \ Element identity() {\n        return static_cast<Element>(0);\n    }\n    static\
    \ Element operation(const Element& lhs, const Element& rhs) {\n        return\
    \ lhs + rhs;\n    }\n    static Element inverse(const Element& v) {\n        return\
    \ -v;\n    }\n};\n\ntemplate <class T>\nstruct Multiplication {\n    using Element\
    \ = T;\n    static Element identity() {\n        return static_cast<Element>(1);\n\
    \    }\n    static Element operation(const Element& lhs, const Element& rhs) {\n\
    \        return lhs * rhs;\n    }\n    static Element inverse(const Element& value)\
    \ {\n        return identity() / value;\n    }\n};\n\n} // namespace internal\n\
    \ntemplate <class T>\nstruct UsualRing {\n    using Element = T;\n    using Addition\
    \ = typename internal::Addition<T>;\n    using Multiplication = typename internal::Multiplication<T>;\n\
    };\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Ring/UsualRing.hpp
  requiredBy: []
  timestamp: '2024-06-25 21:03:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/aoj3369.test.cpp
  - Test/LC/matrix_det.test.cpp
  - Test/CF/ECR157-F.test.cpp
documentation_of: Src/Algebra/Ring/UsualRing.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Ring/UsualRing.hpp
- /library/Src/Algebra/Ring/UsualRing.hpp.html
title: Src/Algebra/Ring/UsualRing.hpp
---
