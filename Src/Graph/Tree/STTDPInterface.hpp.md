---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/DynamicTreeDP.hpp
    title: "1\u70B9\u66F4\u65B0\u4ED8\u304D\u6728DP(\u6839\u56FA\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/STTFold.hpp
    title: "Static Top Tree\u4E0A\u306EDP"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc269_h.test.cpp
    title: Test/AtCoder/abc269_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc351_g.test.cpp
    title: Test/AtCoder/abc351_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/ndpc2026_t.test.cpp
    title: Test/AtCoder/ndpc2026_t.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/STTDPInterface.hpp\"\n\n#include <concepts>\n\
    #include <utility>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class\
    \ T>\nconcept STTDPInterface = requires {\n    typename T::Vertex;\n    typename\
    \ T::Edge;\n    typename T::PathCluster;\n    typename T::PointCluster;\n    {\
    \ T::vertex(std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;\n\
    \    { T::addVertex(std::declval<typename T::PointCluster>(), std::declval<typename\
    \ T::Vertex>()) } -> std::same_as<typename T::PathCluster>;\n    { T::addEdge(std::declval<typename\
    \ T::PathCluster>(), std::declval<typename T::Edge>()) } -> std::same_as<typename\
    \ T::PointCluster>;\n    { T::rake(std::declval<typename T::PointCluster>(), std::declval<typename\
    \ T::PointCluster>()) } -> std::same_as<typename T::PointCluster>;\n    { T::compress(std::declval<typename\
    \ T::PathCluster>(), std::declval<typename T::Edge>(), std::declval<typename T::PathCluster>())\
    \ } -> std::same_as<typename T::PathCluster>;\n};\n\n} // namespace concepts\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n#include <utility>\n\nnamespace zawa\
    \ {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept STTDPInterface = requires\
    \ {\n    typename T::Vertex;\n    typename T::Edge;\n    typename T::PathCluster;\n\
    \    typename T::PointCluster;\n    { T::vertex(std::declval<typename T::Vertex>())\
    \ } -> std::same_as<typename T::PathCluster>;\n    { T::addVertex(std::declval<typename\
    \ T::PointCluster>(), std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::PathCluster>;\n    { T::addEdge(std::declval<typename T::PathCluster>(),\
    \ std::declval<typename T::Edge>()) } -> std::same_as<typename T::PointCluster>;\n\
    \    { T::rake(std::declval<typename T::PointCluster>(), std::declval<typename\
    \ T::PointCluster>()) } -> std::same_as<typename T::PointCluster>;\n    { T::compress(std::declval<typename\
    \ T::PathCluster>(), std::declval<typename T::Edge>(), std::declval<typename T::PathCluster>())\
    \ } -> std::same_as<typename T::PathCluster>;\n};\n\n} // namespace concepts\n\
    \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Graph/Tree/STTDPInterface.hpp
  requiredBy:
  - Src/Graph/Tree/STTFold.hpp
  - Src/Graph/Tree/DynamicTreeDP.hpp
  timestamp: '2026-10-26 15:58:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc269_h.test.cpp
  - Test/AtCoder/ndpc2026_t.test.cpp
  - Test/AtCoder/abc351_g.test.cpp
  - Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: Src/Graph/Tree/STTDPInterface.hpp
layout: document
title: "STT\u4E0A\u306Edp\u306E\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
---

## 雛形

```cpp
struct DP {
    using Vertex = ;
    using Edge = ;
    using PathCluster = ;
    using PointCluster = ;
    static PathCluster vertex(const Vertex&) {
    }
    static PathCluster addVertex(const PointCluster&, const Vertex&) {
    }
    static PointCluster addEdge(const PathCluster&, const Edge&) {
    }
    static PointCluster rake(const PointCluster&, const PointCluster&) {
    }
    static PathCluster compress(const PathCluster& p, const Edge& e, const PathCluster& c) {
    }
};
```

基本的に[ABC351-G 公式解説](https://atcoder.jp/contests/abc351/editorial/9868)の説明の通りに設計されている。

`compress`については、間の辺を陽に考慮するような設計に変更している。`Edge e`を挟んで祖先側の`PathCluster`が`p`、子孫側の`PathCluster`が`c`である。

## 更新履歴

- 2026/10/26: 作成(`DynamicTreeDP`から切り出した)
