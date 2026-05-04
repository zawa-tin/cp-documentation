---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/CartesianProductGroup.hpp
    title: Src/Algebra/Group/CartesianProductGroup.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
    title: Lazy Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
    title: Assignment Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2450.test.cpp
    title: Test/AOJ/2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_D.test.cpp
    title: Test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_F.test.cpp
    title: Test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_G.test.cpp
    title: Test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_I.test.cpp
    title: Test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc237_g.test.cpp
    title: Test/AtCoder/abc237_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc417_f.test.cpp
    title: Test/AtCoder/abc417_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abl_e.test.cpp
    title: Test/AtCoder/abl_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_set_range_composite.test.cpp
    title: Test/LC/range_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/PowerableConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T,class U>\nconcept\
    \ Powerable = requires {\n    typename T::Element;\n    { T::power(std::declval<typename\
    \ T::Element>(), std::declval<U>()) }\n        -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T,class U>\nconcept Powerable = requires {\n    typename\
    \ T::Element;\n    { T::power(std::declval<typename T::Element>(), std::declval<U>())\
    \ }\n        -> std::same_as<typename T::Element>;\n};\n\n} // namespace concepts\n\
    \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/PowerableConcept.hpp
  requiredBy:
  - Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
  - Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
  - Src/Algebra/Group/CartesianProductGroup.hpp
  timestamp: '2026-05-04 14:21:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/range_set_range_composite.test.cpp
  - Test/AOJ/2450.test.cpp
  - Test/AOJ/DSL_2_I.test.cpp
  - Test/AOJ/DSL_2_D.test.cpp
  - Test/AOJ/DSL_2_G.test.cpp
  - Test/AOJ/DSL_2_F.test.cpp
  - Test/AtCoder/abc237_g.test.cpp
  - Test/AtCoder/abc417_f.test.cpp
  - Test/AtCoder/abl_e.test.cpp
documentation_of: Src/Algebra/PowerableConcept.hpp
layout: document
redirect_from:
- /library/Src/Algebra/PowerableConcept.hpp
- /library/Src/Algebra/PowerableConcept.hpp.html
title: Src/Algebra/PowerableConcept.hpp
---
