---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
    title: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Utility/AreaOfUnionOfRectangles.hpp
    title: Src/Utility/AreaOfUnionOfRectangles.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc256_h.test.cpp
    title: Test/AtCoder/abc256_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc322_f.test.cpp
    title: ABC322-F Vacation Query
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc346_g.test.cpp
    title: Test/AtCoder/abc346_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc371_f.test.cpp
    title: Test/AtCoder/abc371_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/practice2_l.test.cpp
    title: Test/AtCoder/practice2_l.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF895-E.test.cpp
    title: Test/CF/CF895-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/area_of_union_of_rectangles.test.cpp
    title: Test/LC/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_range_sum.test.cpp
    title: Test/LC/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\n\
    \n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept MonoidWithAction\
    \ = requires {\n    requires Monoid<typename T::ValueMonoid>;\n    requires Monoid<typename\
    \ T::OperatorMonoid>;\n    { T::mapping(\n            std::declval<typename T::ValueMonoid::Element>(),\n\
    \            std::declval<typename T::OperatorMonoid::Element>()\n           \
    \ ) } -> std::same_as<typename T::ValueMonoid::Element>; \n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept MonoidWithAction\
    \ = requires {\n    requires Monoid<typename T::ValueMonoid>;\n    requires Monoid<typename\
    \ T::OperatorMonoid>;\n    { T::mapping(\n            std::declval<typename T::ValueMonoid::Element>(),\n\
    \            std::declval<typename T::OperatorMonoid::Element>()\n           \
    \ ) } -> std::same_as<typename T::ValueMonoid::Element>; \n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  requiredBy:
  - Src/Utility/AreaOfUnionOfRectangles.hpp
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
  timestamp: '2025-06-25 16:48:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF895-E.test.cpp
  - Test/LC/range_affine_range_sum.test.cpp
  - Test/LC/area_of_union_of_rectangles.test.cpp
  - Test/AtCoder/abc346_g.test.cpp
  - Test/AtCoder/abc371_f.test.cpp
  - Test/AtCoder/abc256_h.test.cpp
  - Test/AtCoder/abc322_f.test.cpp
  - Test/AtCoder/practice2_l.test.cpp
documentation_of: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
- /library/Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp.html
title: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
---
