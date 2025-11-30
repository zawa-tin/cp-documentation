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
    path: Src/DataStructure/FenwickTree/DualFenwickTree.hpp
    title: Dual Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
    title: Fenwick Tree 2D (Offline Query)
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Other/PriorityProductSet.hpp
    title: "\u6607\u9806 $K$ \u500B\u306E\u548C\u3092\u53D6\u308C\u308Bpriority_queue"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/Imos2D.hpp
    title: Src/DataStructure/PrefixSum/Imos2D.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
    title: Src/DataStructure/PrefixSum/PrefixSum2D.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Set/FenwickSet.hpp
    title: Src/DataStructure/Set/FenwickSet.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Set/OfflineOrderedSet.hpp
    title: Src/DataStructure/Set/OfflineOrderedSet.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_B.test.cpp
    title: Test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_E.test.cpp
    title: Test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_f.test.cpp
    title: Test/AtCoder/abc276_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc287_g.test.cpp
    title: Test/AtCoder/abc287_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_e.test.cpp
    title: Test/AtCoder/abc340_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc384_g.test.cpp
    title: Test/AtCoder/abc384_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc389_f.test.cpp
    title: Test/AtCoder/abc389_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc434_d.test.cpp
    title: Test/AtCoder/abc434_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc088_e.test.cpp
    title: Test/AtCoder/arc088_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc196_a.test.cpp
    title: Test/AtCoder/arc196_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC2-E.test.cpp
    title: Test/CF/EC2-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/ordered_set/OfflineOrderedSet.test.cpp
    title: Test/LC/ordered_set/OfflineOrderedSet.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_range_sum.test.cpp
    title: Test/LC/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_subtree_sum.test.cpp
    title: Test/LC/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/UC/4-2-K.test.cpp
    title: Test/UC/4-2-K.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/yukicoder/649.test.cpp
    title: Test/yukicoder/649.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
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
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Monoid/MonoidConcept.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible = requires\
    \ {\n    typename T::Element;\n    { T::inverse(std::declval<typename T::Element>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class T>\nconcept Group\
    \ = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: false
  path: Src/Algebra/Group/GroupConcept.hpp
  requiredBy:
  - Src/DataStructure/Set/FenwickSet.hpp
  - Src/DataStructure/Set/OfflineOrderedSet.hpp
  - Src/DataStructure/PrefixSum/Imos2D.hpp
  - Src/DataStructure/PrefixSum/PrefixSum2D.hpp
  - Src/DataStructure/Other/PriorityProductSet.hpp
  - Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  - Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  timestamp: '2025-04-17 19:44:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/arc196_a.test.cpp
  - Test/AtCoder/abc389_f.test.cpp
  - Test/AtCoder/abc287_g.test.cpp
  - Test/AtCoder/abc434_d.test.cpp
  - Test/AtCoder/abc340_e.test.cpp
  - Test/AtCoder/abc276_f.test.cpp
  - Test/AtCoder/abc384_g.test.cpp
  - Test/AtCoder/arc088_e.test.cpp
  - Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  - Test/LC/ordered_set/OfflineOrderedSet.test.cpp
  - Test/LC/point_add_range_sum.test.cpp
  - Test/LC/vertex_add_path_sum.test.cpp
  - Test/LC/vertex_add_subtree_sum.test.cpp
  - Test/UC/4-2-K.test.cpp
  - Test/AOJ/DSL_2_E.test.cpp
  - Test/AOJ/DSL_2_B.test.cpp
  - Test/CF/EC2-E.test.cpp
  - Test/yukicoder/649.test.cpp
documentation_of: Src/Algebra/Group/GroupConcept.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Group/GroupConcept.hpp
- /library/Src/Algebra/Group/GroupConcept.hpp.html
title: Src/Algebra/Group/GroupConcept.hpp
---
