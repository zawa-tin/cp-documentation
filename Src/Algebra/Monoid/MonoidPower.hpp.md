---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/PowerableConcept.hpp
    title: Src/Algebra/PowerableConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  _extendedRequiredBy:
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
    path: Test/AtCoder/abc445_f.test.cpp
    title: Test/AtCoder/abc445_f.test.cpp
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
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MonoidPower.hpp\"\n\n#line 2 \"Src/Algebra/PowerableConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T,class U>\nconcept Powerable = requires {\n    typename T::Element;\n\
    \    { T::power(std::declval<typename T::Element>(), std::declval<U>()) }\n  \
    \      -> std::same_as<typename T::Element>;\n};\n\n} // namespace concepts\n\n\
    } // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#line 4 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/Algebra/Monoid/MonoidPower.hpp\"\
    \n\n#line 7 \"Src/Algebra/Monoid/MonoidPower.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <concepts::Monoid M,std::unsigned_integral U>\ntypename M::Element MonoidPower(const\
    \ typename M::Element& x,U exp) {\n    if constexpr (concepts::Powerable<M,U>)\
    \ \n        return M::power(x,exp);\n    else {\n        auto a = x;\n       \
    \ auto res = M::identity();\n        while (exp) {\n            if (exp & 1)\n\
    \                res = M::operation(res,a);\n            a = M::operation(a,a);\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../PowerableConcept.hpp\"\n#include \"./MonoidConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid M,std::unsigned_integral\
    \ U>\ntypename M::Element MonoidPower(const typename M::Element& x,U exp) {\n\
    \    if constexpr (concepts::Powerable<M,U>) \n        return M::power(x,exp);\n\
    \    else {\n        auto a = x;\n        auto res = M::identity();\n        while\
    \ (exp) {\n            if (exp & 1)\n                res = M::operation(res,a);\n\
    \            a = M::operation(a,a);\n            exp >>= 1;\n        }\n     \
    \   return res;\n    }\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/PowerableConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/MonoidPower.hpp
  requiredBy:
  - Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
  - Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
  timestamp: '2026-10-05 23:17:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_D.test.cpp
  - Test/AOJ/DSL_2_F.test.cpp
  - Test/AOJ/DSL_2_G.test.cpp
  - Test/AOJ/2450.test.cpp
  - Test/AOJ/DSL_2_I.test.cpp
  - Test/AtCoder/abc445_f.test.cpp
  - Test/AtCoder/abl_e.test.cpp
  - Test/AtCoder/abc237_g.test.cpp
  - Test/AtCoder/abc417_f.test.cpp
  - Test/LC/range_set_range_composite.test.cpp
documentation_of: Src/Algebra/Monoid/MonoidPower.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/MonoidPower.hpp
- /library/Src/Algebra/Monoid/MonoidPower.hpp.html
title: Src/Algebra/Monoid/MonoidPower.hpp
---
