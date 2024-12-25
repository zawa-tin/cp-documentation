---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Circle.hpp
    title: Src/GeometryZ2/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/CircleContainsPoint.hpp
    title: Src/GeometryZ2/Contain/CircleContainsPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp
    title: Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/ConvexHull.hpp
    title: Src/GeometryZ2/ConvexHull.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Distance/PointAndPoint.hpp
    title: Src/GeometryZ2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Intersect/PolygonAndPolygon.hpp
    title: Src/GeometryZ2/Intersect/PolygonAndPolygon.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Intersect/SegmentAndSegment.hpp
    title: Src/GeometryZ2/Intersect/SegmentAndSegment.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Line.hpp
    title: Src/GeometryZ2/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Parallel/SegmentAndSegment.hpp
    title: Src/GeometryZ2/Parallel/SegmentAndSegment.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/PointCloud.hpp
    title: Src/GeometryZ2/PointCloud.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Polygon.hpp
    title: Src/GeometryZ2/Polygon.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Relation.hpp
    title: Src/GeometryZ2/Relation.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Segment.hpp
    title: Src/GeometryZ2/Segment.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0388.test.cpp
    title: Test/AOJ/0388.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0445.test.cpp
    title: Test/AOJ/0445.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/1298.test.cpp
    title: Test/AOJ/1298.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/1379.test.cpp
    title: Test/AOJ/1379.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2609.test.cpp
    title: Test/AOJ/2609.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
    title: Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_3_A.test.cpp
    title: Test/AOJ/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_3_A/GeometryZ2.test.cpp
    title: Test/AOJ/CGL_3_A/GeometryZ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_3_B/GeometryZ2.test.cpp
    title: Test/AOJ/CGL_3_B/GeometryZ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_4_A.test.cpp
    title: Test/AOJ/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_7_A/GeometryZ2.test.cpp
    title: Test/AOJ/CGL_7_A/GeometryZ2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc139_f.test.cpp
    title: Test/AtCoder/abc139_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc191_d.test.cpp
    title: Test/AtCoder/abc191_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc225_e.test.cpp
    title: Test/AtCoder/abc225_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc250_f.test.cpp
    title: Test/AtCoder/abc250_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc266_c.test.cpp
    title: Test/AtCoder/abc266_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc296_g.test.cpp
    title: Test/AtCoder/abc296_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/sort_by_argument.test.cpp
    title: Test/LC/sort_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/static_convex_hull.test.cpp
    title: Test/LC/static_convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#include <cassert>\n\
    \nnamespace zawa {\n\nnamespace geometryZ2 {\n\nusing Zahlen = i64;\n\nnamespace\
    \ internal {\n\nconstexpr i32 positive{1};\nconstexpr i32 zero{0};\nconstexpr\
    \ i32 negative{-1};\n\n} // namespace internal\n\nconstexpr i32 Sign(Zahlen value)\
    \ {\n    if (value < 0) return internal::negative;\n    if (value > 0) return\
    \ internal::positive;\n    return internal::zero;\n}\n\nconstexpr bool Positive(Zahlen\
    \ value) {\n    return Sign(value) == internal::positive;\n}\n\nconstexpr bool\
    \ Zero(Zahlen value) {\n    return Sign(value) == internal::zero;\n}\n\nconstexpr\
    \ bool Negative(Zahlen value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr Zahlen Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n\
    }\n\nconstexpr Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    \nnamespace zawa {\n\nnamespace geometryZ2 {\n\nusing Zahlen = i64;\n\nnamespace\
    \ internal {\n\nconstexpr i32 positive{1};\nconstexpr i32 zero{0};\nconstexpr\
    \ i32 negative{-1};\n\n} // namespace internal\n\nconstexpr i32 Sign(Zahlen value)\
    \ {\n    if (value < 0) return internal::negative;\n    if (value > 0) return\
    \ internal::positive;\n    return internal::zero;\n}\n\nconstexpr bool Positive(Zahlen\
    \ value) {\n    return Sign(value) == internal::positive;\n}\n\nconstexpr bool\
    \ Zero(Zahlen value) {\n    return Sign(value) == internal::zero;\n}\n\nconstexpr\
    \ bool Negative(Zahlen value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr Zahlen Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n\
    }\n\nconstexpr Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/GeometryZ2/Zahlen.hpp
  requiredBy:
  - Src/GeometryZ2/Line.hpp
  - Src/GeometryZ2/ConvexHull.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/GeometryZ2/Distance/PointAndPoint.hpp
  - Src/GeometryZ2/Parallel/SegmentAndSegment.hpp
  - Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp
  - Src/GeometryZ2/Contain/CircleContainsPoint.hpp
  - Src/GeometryZ2/Circle.hpp
  - Src/GeometryZ2/Segment.hpp
  - Src/GeometryZ2/Relation.hpp
  - Src/GeometryZ2/Polygon.hpp
  - Src/GeometryZ2/Intersect/SegmentAndSegment.hpp
  - Src/GeometryZ2/Intersect/PolygonAndPolygon.hpp
  - Src/GeometryZ2/PointCloud.hpp
  timestamp: '2023-11-18 23:42:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/0445.test.cpp
  - Test/AOJ/CGL_3_B/GeometryZ2.test.cpp
  - Test/AOJ/1379.test.cpp
  - Test/AOJ/CGL_4_A.test.cpp
  - Test/AOJ/0388.test.cpp
  - Test/AOJ/CGL_3_A.test.cpp
  - Test/AOJ/1298.test.cpp
  - Test/AOJ/CGL_7_A/GeometryZ2.test.cpp
  - Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
  - Test/AOJ/CGL_3_A/GeometryZ2.test.cpp
  - Test/AOJ/2609.test.cpp
  - Test/LC/sort_by_argument.test.cpp
  - Test/LC/static_convex_hull.test.cpp
  - Test/AtCoder/abc250_f.test.cpp
  - Test/AtCoder/abc139_f.test.cpp
  - Test/AtCoder/abc296_g.test.cpp
  - Test/AtCoder/abc266_c.test.cpp
  - Test/AtCoder/abc191_d.test.cpp
  - Test/AtCoder/abc225_e.test.cpp
documentation_of: Src/GeometryZ2/Zahlen.hpp
layout: document
redirect_from:
- /library/Src/GeometryZ2/Zahlen.hpp
- /library/Src/GeometryZ2/Zahlen.hpp.html
title: Src/GeometryZ2/Zahlen.hpp
---
