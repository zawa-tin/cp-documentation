---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0478.test.cpp
    title: Test/AOJ/0478.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2450.test.cpp
    title: Test/AOJ/2450.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/ReverseOrder.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/ReverseOrder.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nstruct ReverseOrder {\n\
    \n    using Element = M::Element;\n    \n    static Element identity() {\n   \
    \     return M::identity();\n    }\n\n    static Element operation(const Element&\
    \ L, const Element& R) {\n        return M::operation(R, L);\n    }\n\n};\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"./MonoidConcept.hpp\"\n\nnamespace zawa {\n\n\
    template <concepts::Monoid M>\nstruct ReverseOrder {\n\n    using Element = M::Element;\n\
    \    \n    static Element identity() {\n        return M::identity();\n    }\n\
    \n    static Element operation(const Element& L, const Element& R) {\n       \
    \ return M::operation(R, L);\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/ReverseOrder.hpp
  requiredBy: []
  timestamp: '2025-08-04 20:48:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2450.test.cpp
  - Test/AOJ/0478.test.cpp
documentation_of: Src/Algebra/Monoid/ReverseOrder.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/ReverseOrder.hpp
- /library/Src/Algebra/Monoid/ReverseOrder.hpp.html
title: Src/Algebra/Monoid/ReverseOrder.hpp
---
