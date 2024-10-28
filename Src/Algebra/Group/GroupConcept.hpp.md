---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
    title: Fenwick Tree 2D (Offline Query)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_B.test.cpp
    title: Test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_f.test.cpp
    title: Test/AtCoder/abc276_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC2-E.test.cpp
    title: Test/CF/EC2-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_range_sum.test.cpp
    title: Test/LC/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum.test.cpp
    title: Test/LC/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_subtree_sum.test.cpp
    title: Test/LC/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc287_g.test.cpp
    title: Test/Manual/abc287_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate\
    \ <class T>\nconcept Monoid = requires {\n    typename T::Element;\n    { T::identity()\
    \ } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Monoid/MonoidConcept.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Inversible = requires\
    \ {\n    typename T::Element;\n    { T::inverse(std::declval<typename T::Element>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class T>\nconcept Group\
    \ = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: false
  path: Src/Algebra/Group/GroupConcept.hpp
  requiredBy:
  - Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  timestamp: '2024-09-10 17:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_B.test.cpp
  - Test/CF/EC2-E.test.cpp
  - Test/Manual/abc287_g.test.cpp
  - Test/AtCoder/abc276_f.test.cpp
  - Test/LC/point_add_range_sum.test.cpp
  - Test/LC/point_add_rectangle_sum.test.cpp
  - Test/LC/vertex_add_path_sum.test.cpp
  - Test/LC/vertex_add_subtree_sum.test.cpp
documentation_of: Src/Algebra/Group/GroupConcept.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Group/GroupConcept.hpp
- /library/Src/Algebra/Group/GroupConcept.hpp.html
title: Src/Algebra/Group/GroupConcept.hpp
---
