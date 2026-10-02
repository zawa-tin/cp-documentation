---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp
    title: Point Add Rectangle Sum
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
    title: Rectangle Sum of PointCloud
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
    title: Rectangle Sum of Rectangles
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc136_f.test.cpp
    title: Test/AtCoder/abc136_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc477_f.test.cpp
    title: Test/AtCoder/abc477_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_add_rectangle_sum/PointAddRectangleSum.test.cpp
    title: Test/LC/point_add_rectangle_sum/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/rectangle_sum/rectangle_sum.test.cpp
    title: Test/LC/rectangle_sum/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
    title: Test/LC/static_rectangle_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp\"\
    \n\n#include <concepts>\n#include <type_traits>\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept Point = requires (T p) {\n    typename\
    \ T::P;\n    typename T::W;\n    { p.x } -> std::same_as<typename T::P&>;\n  \
    \  { p.y } -> std::same_as<typename T::P&>;\n    { p.w } -> std::same_as<typename\
    \ T::W&>;\n};\n\ntemplate <class T>\nconcept RectangleAdd = requires (T r) {\n\
    \    typename T::P;\n    typename T::W;\n    { r.l } -> std::same_as<typename\
    \ T::P&>;\n    { r.d } -> std::same_as<typename T::P&>;\n    { r.r } -> std::same_as<typename\
    \ T::P&>;\n    { r.u } -> std::same_as<typename T::P&>;\n    { r.w } -> std::same_as<typename\
    \ T::W&>;\n};\n\ntemplate <class T>\nconcept Rectangle = requires (T r) {\n  \
    \  typename T::P;\n    { r.l } -> std::same_as<typename T::P&>;\n    { r.d } ->\
    \ std::same_as<typename T::P&>;\n    { r.r } -> std::same_as<typename T::P&>;\n\
    \    { r.u } -> std::same_as<typename T::P&>;\n};\n\n} // namespace concepts\n\
    \n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n#include <type_traits>\n\nnamespace\
    \ zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Point = requires\
    \ (T p) {\n    typename T::P;\n    typename T::W;\n    { p.x } -> std::same_as<typename\
    \ T::P&>;\n    { p.y } -> std::same_as<typename T::P&>;\n    { p.w } -> std::same_as<typename\
    \ T::W&>;\n};\n\ntemplate <class T>\nconcept RectangleAdd = requires (T r) {\n\
    \    typename T::P;\n    typename T::W;\n    { r.l } -> std::same_as<typename\
    \ T::P&>;\n    { r.d } -> std::same_as<typename T::P&>;\n    { r.r } -> std::same_as<typename\
    \ T::P&>;\n    { r.u } -> std::same_as<typename T::P&>;\n    { r.w } -> std::same_as<typename\
    \ T::W&>;\n};\n\ntemplate <class T>\nconcept Rectangle = requires (T r) {\n  \
    \  typename T::P;\n    { r.l } -> std::same_as<typename T::P&>;\n    { r.d } ->\
    \ std::same_as<typename T::P&>;\n    { r.r } -> std::same_as<typename T::P&>;\n\
    \    { r.u } -> std::same_as<typename T::P&>;\n};\n\n} // namespace concepts\n\
    \n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
  requiredBy:
  - Src/DataStructure/RectangleSum/RectangleSumOfPointCloud.hpp
  - Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp
  - Src/DataStructure/RectangleSum/PointAddRectangleSum.hpp
  timestamp: '2026-10-02 17:24:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc477_f.test.cpp
  - Test/AtCoder/abc136_f.test.cpp
  - Test/LC/rectangle_sum/rectangle_sum.test.cpp
  - Test/LC/point_add_rectangle_sum/PointAddRectangleSum.test.cpp
  - Test/LC/static_rectangle_add_rectangle_sum.test.cpp
documentation_of: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
- /library/Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp.html
title: Src/DataStructure/RectangleSum/RectangleSumConcepts.hpp
---
