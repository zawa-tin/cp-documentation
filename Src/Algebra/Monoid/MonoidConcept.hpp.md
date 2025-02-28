---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
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
    path: Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
    title: Assignment Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
    title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/DualSparseTable.hpp
    title: Dual Sparse Table
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0478.test.cpp
    title: Test/AOJ/0478.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2559.test.cpp
    title: Test/AOJ/2559.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_A.test.cpp
    title: Test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_B.test.cpp
    title: Test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_D.test.cpp
    title: Test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_E.test.cpp
    title: Test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_F.test.cpp
    title: Test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/DSL_2_I.test.cpp
    title: Test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc237_g.test.cpp
    title: Test/AtCoder/abc237_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_f.test.cpp
    title: Test/AtCoder/abc276_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc287_g.test.cpp
    title: Test/AtCoder/abc287_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_h.test.cpp
    title: Test/AtCoder/abc292_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc331_f.test.cpp
    title: Test/AtCoder/abc331_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc332_f.test.cpp
    title: "ABC332-F Random Update Query (a <- ap + q\u306E\u51E6\u7406)"
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_e.test.cpp
    title: Test/AtCoder/abc340_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc384_g.test.cpp
    title: Test/AtCoder/abc384_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abl_e.test.cpp
    title: Test/AtCoder/abl_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc088_e.test.cpp
    title: Test/AtCoder/arc088_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC2-E.test.cpp
    title: Test/CF/EC2-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_range_sum.test.cpp
    title: Test/LC/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
    title: Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_range_composite.test.cpp
    title: Test/LC/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_point_get.test.cpp
    title: Test/LC/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_set_range_composite.test.cpp
    title: Test/LC/range_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_path_sum.test.cpp
    title: Test/LC/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_subtree_sum.test.cpp
    title: Test/LC/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/agc005_b.test.cpp
    title: Test/Manual/agc005_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3226.test.cpp
    title: Test/Manual/aoj3226.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Monoid\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n    { T::operation(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n} // namespace\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace Concept\
    \ {\n\ntemplate <class T>\nconcept Monoid = requires {\n    typename T::Element;\n\
    \    { T::identity() } -> std::same_as<typename T::Element>;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/MonoidConcept.hpp
  requiredBy:
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/DataStructure/SparseTable/DualSparseTable.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  - Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  - Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  - Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  timestamp: '2024-09-10 17:27:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/EC2-E.test.cpp
  - Test/AOJ/DSL_2_F.test.cpp
  - Test/AOJ/DSL_2_I.test.cpp
  - Test/AOJ/DSL_2_E.test.cpp
  - Test/AOJ/DSL_2_D.test.cpp
  - Test/AOJ/DSL_2_A.test.cpp
  - Test/AOJ/DSL_2_B.test.cpp
  - Test/AOJ/2559.test.cpp
  - Test/AOJ/0478.test.cpp
  - Test/Manual/aoj3226.test.cpp
  - Test/Manual/agc005_b.test.cpp
  - Test/LC/vertex_add_subtree_sum.test.cpp
  - Test/LC/point_add_rectangle_sum/OfflineFenwickTree2D.test.cpp
  - Test/LC/range_affine_point_get.test.cpp
  - Test/LC/point_add_range_sum.test.cpp
  - Test/LC/range_set_range_composite.test.cpp
  - Test/LC/vertex_add_path_sum.test.cpp
  - Test/LC/point_set_range_composite.test.cpp
  - Test/AtCoder/abc384_g.test.cpp
  - Test/AtCoder/abc237_g.test.cpp
  - Test/AtCoder/arc088_e.test.cpp
  - Test/AtCoder/abc292_h.test.cpp
  - Test/AtCoder/abl_e.test.cpp
  - Test/AtCoder/abc331_f.test.cpp
  - Test/AtCoder/abc332_f.test.cpp
  - Test/AtCoder/abc287_g.test.cpp
  - Test/AtCoder/abc276_f.test.cpp
  - Test/AtCoder/abc340_e.test.cpp
documentation_of: Src/Algebra/Monoid/MonoidConcept.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/MonoidConcept.hpp
- /library/Src/Algebra/Monoid/MonoidConcept.hpp.html
title: Src/Algebra/Monoid/MonoidConcept.hpp
---
