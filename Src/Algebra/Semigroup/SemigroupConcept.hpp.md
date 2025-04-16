---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SWAG/FoldableQueue.hpp
    title: Foldable Queue
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/EnumerateStaticLengthProduct.hpp
    title: Src/Sequence/EnumerateStaticLengthProduct.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3548.test.cpp
    title: AOJ3548 String Puzzle
  - icon: ':heavy_check_mark:'
    path: Test/LC/queue_operate_all_composite.test.cpp
    title: Test/LC/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include\
    \ <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\n\
    concept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n\
    \    { T::operation(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Semigroup/SemigroupConcept.hpp
  requiredBy:
  - Src/Sequence/EnumerateStaticLengthProduct.hpp
  - Src/DataStructure/SWAG/FoldableQueue.hpp
  timestamp: '2025-04-16 16:40:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/3548.test.cpp
  - Test/LC/queue_operate_all_composite.test.cpp
documentation_of: Src/Algebra/Semigroup/SemigroupConcept.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Semigroup/SemigroupConcept.hpp
- /library/Src/Algebra/Semigroup/SemigroupConcept.hpp.html
title: Src/Algebra/Semigroup/SemigroupConcept.hpp
---
