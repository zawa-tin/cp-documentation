---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Zahlen.hpp
    title: Src/GeometryZ2/Zahlen.hpp
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
  bundledCode: "#line 2 \"Src/GeometryZ2/Point.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#line 4 \"Src/GeometryZ2/Zahlen.hpp\"\
    \n\n#include <cassert>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nusing\
    \ Zahlen = i64;\n\nnamespace internal {\n\nconstexpr i32 positive{1};\nconstexpr\
    \ i32 zero{0};\nconstexpr i32 negative{-1};\n\n} // namespace internal\n\nconstexpr\
    \ i32 Sign(Zahlen value) {\n    if (value < 0) return internal::negative;\n  \
    \  if (value > 0) return internal::positive;\n    return internal::zero;\n}\n\n\
    constexpr bool Positive(Zahlen value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Zero(Zahlen value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool Negative(Zahlen value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr Zahlen Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n\
    }\n\nconstexpr Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n#line 5 \"Src/GeometryZ2/Point.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#line 9 \"Src/GeometryZ2/Point.hpp\"\
    \n#include <limits>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass Point\
    \ {\nprivate:\n    Zahlen x_{}, y_{};\n    static constexpr i32 origin{0};\n \
    \   static constexpr i32 firstQuadrant{1};\n    static constexpr i32 secondQuadrant{2};\n\
    \    static constexpr i32 thirdQuadrant{-2};\n    static constexpr i32 forthQuadrant{-1};\n\
    public:\n    /* constructor */\n    Point() = default;\n    Point(const Point&\
    \ p) : x_{p.x()}, y_{p.y()} {}\n    Point(Zahlen x, Zahlen y) : x_{x}, y_{y} {}\n\
    \n    /* getter setter */\n    Zahlen& x() {\n        return x_;\n    }\n    const\
    \ Zahlen& x() const {\n        return x_;\n    }\n    Zahlen& y() {\n        return\
    \ y_;\n    }\n    const Zahlen& y() const {\n        return y_;\n    }\n\n   \
    \ /* operator */\n    Point& operator=(const Point& p) {\n        x() = p.x();\n\
    \        y() = p.y();\n        return *this;\n    }\n    Point& operator+=(const\
    \ Point& p) {\n        x() += p.x();\n        y() += p.y();\n        return *this;\n\
    \    }\n    friend Point operator+(const Point& p0, const Point& p1) {\n     \
    \   return Point{p0} += p1;\n    }\n    Point& operator-=(const Point& p) {\n\
    \        x() -= p.x();\n        y() -= p.y();\n        return *this;\n    }\n\
    \    friend Point operator-(const Point& p0, const Point& p1) {\n        return\
    \ Point{p0} -= p1;\n    }\n    Point& operator*=(Zahlen k) {\n        x() *= k;\n\
    \        y() *= k;\n        return *this;\n    }\n    friend Point operator*(const\
    \ Point& p, Zahlen k) {\n        return Point{p} *= k;\n    }\n    friend Point\
    \ operator*(Zahlen k, const Point& p) {\n        return Point{p} *= k;\n    }\n\
    \    Point& operator/=(Zahlen k) {\n        assert(k);\n        assert(x() % k\
    \ == 0);\n        assert(y() % k == 0);\n        x() /= k;\n        y() /= k;\n\
    \        return *this;\n    }\n    friend Point operator/(const Point& p, Zahlen\
    \ k) {\n        return Point{p} /= k;\n    }\n    friend bool operator==(const\
    \ Point& p0, const Point& p1) {\n        return p0.x() == p1.x() and p0.y() ==\
    \ p1.y();\n    }\n    friend bool operator!=(const Point& p0, const Point& p1)\
    \ {\n        return p0.x() != p1.x() or p0.y() != p1.y();\n    }\n    friend bool\
    \ operator<(const Point& p0, const Point& p1) {\n        if (p0.x() != p1.x())\
    \ return p0.x() < p1.x();\n        else return p0.y() < p1.y();\n    }\n    friend\
    \ bool operator<=(const Point& p0, const Point& p1) {\n        return (p0 < p1)\
    \ or (p0 == p1);\n    }\n    friend bool operator>(const Point& p0, const Point&\
    \ p1) {\n        if (p0.x() != p1.x()) return p0.x() > p1.x();\n        else return\
    \ p0.y() > p1.y();\n    }\n    friend bool operator>=(const Point& p0, const Point&\
    \ p1) {\n        return (p0 > p1) or (p0 == p1);\n    }\n    friend std::istream&\
    \ operator>>(std::istream& is, Point& p) {\n        is >> p.x() >> p.y();\n  \
    \      return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Point& p) {\n        os << '(' << p.x() << ',' << p.y() << ')';\n    \
    \    return os;\n    }\n\n    /* member function */\n    Zahlen normSquare() const\
    \ {\n        return Square(x()) + Square(y());\n    }\n    bool isNormSquareOver(Zahlen\
    \ d) const {\n        assert(!Negative(d));\n        auto [mn, mx]{std::minmax({\
    \ Abs(x()), Abs(y()) })};\n        if (mx and mx > d / mx) {\n            return\
    \ true;\n        }\n        long long s1{Square(mn)}, s2{Square(mx)};\n      \
    \  if (s1 > d - s2) {\n            return true;\n        }\n        return false;\n\
    \    }\n    bool isNormSquareOverflow() const {\n        return isNormSquareOver(std::numeric_limits<Zahlen>::max());\n\
    \    }\n\n    i32 area() const {\n        if (x_ == 0 and y_ == 0) return origin;\n\
    \        if (x_ <= 0 and y_ < 0) return thirdQuadrant;\n        if (x_ > 0 and\
    \ y_ <= 0) return forthQuadrant;\n        if (x_ >= 0 and y_ > 0) return firstQuadrant;\n\
    \        return secondQuadrant;\n    }\n\n    /* static member */\n    static\
    \ bool ArgComp(const Point& p0, const Point& p1) {\n        if (p0.area() != p1.area())\
    \ return p0.area() < p1.area();\n        Zahlen cross{Cross(p0, p1)};\n      \
    \  return (!Zero(cross) ? Positive(cross) : p0.normSquare() < p1.normSquare());\n\
    \    }\n\n    /* friend function */\n    friend Zahlen Dot(const Point& p0, const\
    \ Point& p1) {\n        return p0.x() * p1.x() + p0.y() * p1.y();\n    }\n   \
    \ friend Zahlen Cross(const Point& p0, const Point& p1) {\n        return p0.x()\
    \ * p1.y() - p0.y() * p1.x();\n    }\n};\nusing Vector = Point;\n\n} // namespace\
    \ geometryZ2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./Zahlen.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <cassert>\n#include <limits>\n\
    \nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass Point {\nprivate:\n    Zahlen\
    \ x_{}, y_{};\n    static constexpr i32 origin{0};\n    static constexpr i32 firstQuadrant{1};\n\
    \    static constexpr i32 secondQuadrant{2};\n    static constexpr i32 thirdQuadrant{-2};\n\
    \    static constexpr i32 forthQuadrant{-1};\npublic:\n    /* constructor */\n\
    \    Point() = default;\n    Point(const Point& p) : x_{p.x()}, y_{p.y()} {}\n\
    \    Point(Zahlen x, Zahlen y) : x_{x}, y_{y} {}\n\n    /* getter setter */\n\
    \    Zahlen& x() {\n        return x_;\n    }\n    const Zahlen& x() const {\n\
    \        return x_;\n    }\n    Zahlen& y() {\n        return y_;\n    }\n   \
    \ const Zahlen& y() const {\n        return y_;\n    }\n\n    /* operator */\n\
    \    Point& operator=(const Point& p) {\n        x() = p.x();\n        y() = p.y();\n\
    \        return *this;\n    }\n    Point& operator+=(const Point& p) {\n     \
    \   x() += p.x();\n        y() += p.y();\n        return *this;\n    }\n    friend\
    \ Point operator+(const Point& p0, const Point& p1) {\n        return Point{p0}\
    \ += p1;\n    }\n    Point& operator-=(const Point& p) {\n        x() -= p.x();\n\
    \        y() -= p.y();\n        return *this;\n    }\n    friend Point operator-(const\
    \ Point& p0, const Point& p1) {\n        return Point{p0} -= p1;\n    }\n    Point&\
    \ operator*=(Zahlen k) {\n        x() *= k;\n        y() *= k;\n        return\
    \ *this;\n    }\n    friend Point operator*(const Point& p, Zahlen k) {\n    \
    \    return Point{p} *= k;\n    }\n    friend Point operator*(Zahlen k, const\
    \ Point& p) {\n        return Point{p} *= k;\n    }\n    Point& operator/=(Zahlen\
    \ k) {\n        assert(k);\n        assert(x() % k == 0);\n        assert(y()\
    \ % k == 0);\n        x() /= k;\n        y() /= k;\n        return *this;\n  \
    \  }\n    friend Point operator/(const Point& p, Zahlen k) {\n        return Point{p}\
    \ /= k;\n    }\n    friend bool operator==(const Point& p0, const Point& p1) {\n\
    \        return p0.x() == p1.x() and p0.y() == p1.y();\n    }\n    friend bool\
    \ operator!=(const Point& p0, const Point& p1) {\n        return p0.x() != p1.x()\
    \ or p0.y() != p1.y();\n    }\n    friend bool operator<(const Point& p0, const\
    \ Point& p1) {\n        if (p0.x() != p1.x()) return p0.x() < p1.x();\n      \
    \  else return p0.y() < p1.y();\n    }\n    friend bool operator<=(const Point&\
    \ p0, const Point& p1) {\n        return (p0 < p1) or (p0 == p1);\n    }\n   \
    \ friend bool operator>(const Point& p0, const Point& p1) {\n        if (p0.x()\
    \ != p1.x()) return p0.x() > p1.x();\n        else return p0.y() > p1.y();\n \
    \   }\n    friend bool operator>=(const Point& p0, const Point& p1) {\n      \
    \  return (p0 > p1) or (p0 == p1);\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, Point& p) {\n        is >> p.x() >> p.y();\n        return is;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Point& p) {\n   \
    \     os << '(' << p.x() << ',' << p.y() << ')';\n        return os;\n    }\n\n\
    \    /* member function */\n    Zahlen normSquare() const {\n        return Square(x())\
    \ + Square(y());\n    }\n    bool isNormSquareOver(Zahlen d) const {\n       \
    \ assert(!Negative(d));\n        auto [mn, mx]{std::minmax({ Abs(x()), Abs(y())\
    \ })};\n        if (mx and mx > d / mx) {\n            return true;\n        }\n\
    \        long long s1{Square(mn)}, s2{Square(mx)};\n        if (s1 > d - s2) {\n\
    \            return true;\n        }\n        return false;\n    }\n    bool isNormSquareOverflow()\
    \ const {\n        return isNormSquareOver(std::numeric_limits<Zahlen>::max());\n\
    \    }\n\n    i32 area() const {\n        if (x_ == 0 and y_ == 0) return origin;\n\
    \        if (x_ <= 0 and y_ < 0) return thirdQuadrant;\n        if (x_ > 0 and\
    \ y_ <= 0) return forthQuadrant;\n        if (x_ >= 0 and y_ > 0) return firstQuadrant;\n\
    \        return secondQuadrant;\n    }\n\n    /* static member */\n    static\
    \ bool ArgComp(const Point& p0, const Point& p1) {\n        if (p0.area() != p1.area())\
    \ return p0.area() < p1.area();\n        Zahlen cross{Cross(p0, p1)};\n      \
    \  return (!Zero(cross) ? Positive(cross) : p0.normSquare() < p1.normSquare());\n\
    \    }\n\n    /* friend function */\n    friend Zahlen Dot(const Point& p0, const\
    \ Point& p1) {\n        return p0.x() * p1.x() + p0.y() * p1.y();\n    }\n   \
    \ friend Zahlen Cross(const Point& p0, const Point& p1) {\n        return p0.x()\
    \ * p1.y() - p0.y() * p1.x();\n    }\n};\nusing Vector = Point;\n\n} // namespace\
    \ geometryZ2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Zahlen.hpp
  isVerificationFile: false
  path: Src/GeometryZ2/Point.hpp
  requiredBy:
  - Src/GeometryZ2/Polygon.hpp
  - Src/GeometryZ2/Segment.hpp
  - Src/GeometryZ2/Line.hpp
  - Src/GeometryZ2/Contain/CircleContainsPoint.hpp
  - Src/GeometryZ2/Contain/ConvexPolygonContainsPoint.hpp
  - Src/GeometryZ2/Relation.hpp
  - Src/GeometryZ2/Distance/PointAndPoint.hpp
  - Src/GeometryZ2/PointCloud.hpp
  - Src/GeometryZ2/Intersect/SegmentAndSegment.hpp
  - Src/GeometryZ2/Intersect/PolygonAndPolygon.hpp
  - Src/GeometryZ2/Parallel/SegmentAndSegment.hpp
  - Src/GeometryZ2/Circle.hpp
  - Src/GeometryZ2/ConvexHull.hpp
  timestamp: '2024-06-26 14:51:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/0388.test.cpp
  - Test/AOJ/1379.test.cpp
  - Test/AOJ/0445.test.cpp
  - Test/AOJ/CGL_3_A.test.cpp
  - Test/AOJ/CGL_3_A/GeometryZ2.test.cpp
  - Test/AOJ/1298.test.cpp
  - Test/AOJ/CGL_7_A/GeometryZ2.test.cpp
  - Test/AOJ/2609.test.cpp
  - Test/AOJ/CGL_4_A.test.cpp
  - Test/AOJ/CGL_3_B/GeometryZ2.test.cpp
  - Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
  - Test/AtCoder/abc225_e.test.cpp
  - Test/AtCoder/abc139_f.test.cpp
  - Test/AtCoder/abc250_f.test.cpp
  - Test/AtCoder/abc296_g.test.cpp
  - Test/AtCoder/abc266_c.test.cpp
  - Test/AtCoder/abc191_d.test.cpp
  - Test/LC/static_convex_hull.test.cpp
  - Test/LC/sort_by_argument.test.cpp
documentation_of: Src/GeometryZ2/Point.hpp
layout: document
redirect_from:
- /library/Src/GeometryZ2/Point.hpp
- /library/Src/GeometryZ2/Point.hpp.html
title: Src/GeometryZ2/Point.hpp
---