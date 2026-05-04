---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_G.test.cpp
    title: Test/AOJ/DSL_2_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/CartesianProductGroup.hpp\"\n\n#line 2\
    \ \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/PowerableConcept.hpp\"\n\n#line 4\
    \ \"Src/Algebra/PowerableConcept.hpp\"\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T,class U>\nconcept Powerable = requires {\n    typename\
    \ T::Element;\n    { T::power(std::declval<typename T::Element>(), std::declval<U>())\
    \ }\n        -> std::same_as<typename T::Element>;\n};\n\n} // namespace concepts\n\
    \n} // namespace zawa\n#line 5 \"Src/Algebra/Group/CartesianProductGroup.hpp\"\
    \n\n#include <utility>\n\nnamespace zawa {\n\ntemplate <concepts::Group G>\nclass\
    \ CartesianProductGroup {\npublic:\n\n    using Element = std::pair<typename G::Element,typename\
    \ G::Element>;\n\n    static Element identity() {\n        return {G::identity(),G::identity()};\n\
    \    }\n\n    static Element operation(const Element& l,const Element& r) {\n\
    \        return {G::operation(l.first,r.first),G::operation(l.second,r.second)};\n\
    \    }\n\n    static Element inverse(const Element& v) {\n        return {G::inverse(v.first),G::inverse(v.second)};\n\
    \    }\n\n    template <class U>\n    static Element power(const Element& v,U\
    \ exp) requires concepts::Powerable<G,U> {\n        return {G::power(v.first,exp),G::power(v.second,exp)};\n\
    \    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./GroupConcept.hpp\"\n#include \"../PowerableConcept.hpp\"\
    \n\n#include <utility>\n\nnamespace zawa {\n\ntemplate <concepts::Group G>\nclass\
    \ CartesianProductGroup {\npublic:\n\n    using Element = std::pair<typename G::Element,typename\
    \ G::Element>;\n\n    static Element identity() {\n        return {G::identity(),G::identity()};\n\
    \    }\n\n    static Element operation(const Element& l,const Element& r) {\n\
    \        return {G::operation(l.first,r.first),G::operation(l.second,r.second)};\n\
    \    }\n\n    static Element inverse(const Element& v) {\n        return {G::inverse(v.first),G::inverse(v.second)};\n\
    \    }\n\n    template <class U>\n    static Element power(const Element& v,U\
    \ exp) requires concepts::Powerable<G,U> {\n        return {G::power(v.first,exp),G::power(v.second,exp)};\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/PowerableConcept.hpp
  isVerificationFile: false
  path: Src/Algebra/Group/CartesianProductGroup.hpp
  requiredBy:
  - Src/DataStructure/FenwickTree/LazyFenwickTree.hpp
  timestamp: '2026-05-04 14:21:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/DSL_2_G.test.cpp
documentation_of: Src/Algebra/Group/CartesianProductGroup.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Group/CartesianProductGroup.hpp
- /library/Src/Algebra/Group/CartesianProductGroup.hpp.html
title: Src/Algebra/Group/CartesianProductGroup.hpp
---
