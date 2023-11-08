---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Line.hpp
    title: Src/GeometryR2/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Real.hpp
    title: Src/GeometryR2/Real.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Reflection.hpp
    title: Src/GeometryR2/Reflection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_A.test.cpp
    title: Test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_B.test.cpp
    title: Test/AOJ/CGL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryR2/Projection.hpp\"\n\n#line 2 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Real.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nusing Real = long double;\nconstexpr Real EPS{1e-12};\n\nnamespace internal\
    \ {\n\nconstexpr int negative{-1};\nconstexpr int zero{};\nconstexpr int positive{1};\n\
    \n} // namespace internal\n\nconstexpr int Sign(Real value) {\n    if (value <\
    \ -EPS) return internal::negative;\n    if (value > EPS) return internal::positive;\n\
    \    return internal::zero;\n}\n\nconstexpr bool Zero(Real value) {\n    return\
    \ Sign(value) == internal::zero;\n}\n\nconstexpr bool Positive(Real value) {\n\
    \    return Sign(value) == internal::positive;\n}\n\nconstexpr bool Negative(Real\
    \ value) {\n    return Sign(value) == internal::negative;\n}\n\nconstexpr bool\
    \ Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nconstexpr bool Smaller(Real\
    \ a, Real b) {\n    return Negative(a - b);\n}\n\nconstexpr bool Bigger(Real a,\
    \ Real b) {\n    return Positive(a - b);\n}\n\n} // namespace geometryR2\n \n\
    } // namespace zawa\n#line 2 \"Src/GeometryR2/Angle.hpp\"\n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\
    \n\n#include <cmath>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nconstexpr\
    \ Real PI{acosl(-1)};\nconstexpr Real TAU{static_cast<Real>(2) * PI};\n\nconstexpr\
    \ Real ArcToRadian(Real arc) {\n    return (arc * PI) / static_cast<Real>(180);\n\
    }\n\nconstexpr Real RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180))\
    \ / PI;\n}\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 7 \"Src/GeometryR2/Point.hpp\"\n#include <iostream>\n#include <cassert>\n\
    \nnamespace zawa {\n\nnamespace geometryR2 {\n\nclass Point {\nprivate:\n    Real\
    \ x_{}, y_{};\npublic:\n    /* constructor */\n    Point() = default;\n    Point(Real\
    \ x, Real y) : x_{x}, y_{y} {}\n\n    /* getter, setter */\n    Real x() const\
    \ {\n        return x_;\n    }\n    Real& x() {\n        return x_;\n    }\n \
    \   Real y() const {\n        return y_;\n    }\n    Real& y() {\n        return\
    \ y_;\n    }\n\n    /* operator */\n    Point& operator+=(const Point& rhs) {\n\
    \        x_ += rhs.x();\n        y_ += rhs.y();\n        return *this;\n    }\n\
    \    friend Point operator+(const Point& lhs, const Point& rhs) {\n        return\
    \ Point{lhs} += rhs;\n    }\n    Point operator+() const {\n        return *this;\n\
    \    }\n    Point& operator-=(const Point& rhs) {\n        x_ -= rhs.x();\n  \
    \      y_ -= rhs.y();\n        return *this;\n    }\n    friend Point operator-(const\
    \ Point& lhs, const Point& rhs) {\n        return Point{lhs} -= rhs;\n    }\n\
    \    Point operator-() const {\n        return Point{} - *this;\n    }\n    Point&\
    \ operator*=(Real k) {\n        x_ *= k;\n        y_ *= k;\n        return *this;\n\
    \    }\n    friend Point operator*(Real k, const Point& p) {\n        return Point{p}\
    \ *= k;\n    }\n    friend Point operator*(const Point& p, Real k) {\n       \
    \ return Point{p} *= k;\n    }\n    Point& operator/=(Real k) {\n        assert(!Zero(k));\n\
    \        x_ /= k;\n        y_ /= k;\n        return *this;\n    }\n    friend\
    \ Point operator/(Real k, const Point& p) {\n        return Point{p} /= k;\n \
    \   }\n    friend Point operator/(const Point& p, Real k) {\n        return Point{p}\
    \ /= k;\n    }\n    friend bool operator==(const Point& lhs, const Point& rhs)\
    \ {\n        return Equal(lhs.x(), rhs.x()) and Equal(lhs.y(), rhs.y());\n   \
    \ }\n    friend bool operator!=(const Point& lhs, const Point& rhs) {\n      \
    \  return !Equal(lhs.x(), rhs.x()) or !Equal(lhs.y(), rhs.y());\n    }\n    friend\
    \ bool operator<(const Point& lhs, const Point& rhs) {\n        return Smaller(lhs.x(),\
    \ rhs.x()) or \n            (Equal(lhs.x(), rhs.x()) and Smaller(lhs.y(), rhs.y()));\n\
    \    }\n    friend bool operator<=(const Point& lhs, const Point& rhs) {\n   \
    \     return Smaller(lhs.x(), rhs.x()) or \n            (Equal(lhs.x(), rhs.x())\
    \ and (Smaller(lhs.y(), rhs.y()) or Equal(lhs.y(), rhs.y())));\n    }\n    friend\
    \ bool operator>(const Point& lhs, const Point& rhs) {\n        return Bigger(lhs.x(),\
    \ rhs.x()) or\n            (Equal(lhs.x(), rhs.x()) and Bigger(lhs.y(), rhs.y()));\n\
    \    }\n    friend bool operator>=(const Point& lhs, const Point& rhs) {\n   \
    \     return Bigger(lhs.x(), rhs.x()) or\n            (Equal(lhs.x(), rhs.x())\
    \ and (Bigger(lhs.y(), rhs.y()) or Equal(lhs.y(), rhs.y())));\n    }\n    friend\
    \ std::istream& operator>>(std::istream& is, Point& p) {\n        is >> p.x_ >>\
    \ p.y_;\n        return is;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& p) {\n        os << '(' << p.x_ << ',' << p.y_ << ')';\n  \
    \      return os;\n    }\n    \n    /* member function */\n    Real normSquare()\
    \ const {\n        return x_ * x_ + y_ * y_;\n    }\n    Real norm() const {\n\
    \        return sqrtl(normSquare());\n    }\n    void normalize() {\n        (*this)\
    \ /= norm(); \n    }\n    Point normalized() const {\n        Point res{*this};\n\
    \        res.normalize();\n        return res;\n    }\n    Point rotated(Real\
    \ radian) const {\n        return Point{\n            x_ * cosl(radian) - y_ *\
    \ sinl(radian),\n            x_ * sinl(radian) + y_ * cosl(radian)\n        };\n\
    \    }\n    void rotate(Real radian) {\n        *this = rotated(radian); \n  \
    \  }\n    Point rotatedByArc(Real arc) const {\n        return rotated(ArcToRadian(arc));\n\
    \    }\n    void rotateByArc(Real arc) {\n        *this = rotatedByArc(arc);\n\
    \    }\n    Real argument() const {\n        return (Negative(y_) ? TAU : static_cast<Real>(0))\
    \ + atan2l(y_, x_);\n    }\n    Real argumentByArc() const {\n        return RadianToArc(argument());\n\
    \    }\n\n    /* friend function */\n    friend Real Dot(const Point& lhs, const\
    \ Point& rhs) {\n        return lhs.x() * rhs.x() + lhs.y() * rhs.y();\n    }\n\
    \    friend Real Cross(const Point& lhs, const Point& rhs) {\n        return lhs.x()\
    \ * rhs.y() - lhs.y() * rhs.x();\n    }\n    friend Real DistanceSquare(const\
    \ Point& lhs, const Point& rhs) {\n        return Point{lhs - rhs}.normSquare();\n\
    \    }\n    friend Real Distance(const Point& lhs, const Point& rhs) {\n     \
    \   return Point{lhs - rhs}.norm();\n    }\n    friend Real Argument(const Point&\
    \ lhs, const Point& rhs) {\n        return rhs.argument() - lhs.argument();\n\
    \    }\n    friend bool ArgComp(const Point& lhs, const Point& rhs) {\n      \
    \  return Smaller(lhs.argument(), rhs.argument());\n    }\n};\n\nusing Vector\
    \ = Point;\n\n} // namespace geomeryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Line.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Line.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nclass Line {\nprivate:\n    Point p0_{}, p1_{};\npublic:\n    /* constructor\
    \ */\n    Line() = default;\n    Line(const Point& p0, const Point& p1) : p0_{p0},\
    \ p1_{p1} {}\n    // y = ax + b \n    Line(Real a, Real b) : p0_{static_cast<Real>(0),\
    \ b}, p1_{static_cast<Real>(1), a + b} {}\n\n    /* getter, setter */\n    const\
    \ Point& p0() const {\n        return p0_;\n    }\n    Point& p0() {\n       \
    \ return p0_;\n    }\n    const Point& p1() const {\n        return p1_;\n   \
    \ }\n    Point& p1() {\n        return p1_;\n    }\n\n    /* member function */\n\
    \    bool isValid() const {\n        return p0_ != p1_;\n    }\n};\n\n} // namespace\
    \ geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Projection.hpp\"\
    \n\n#line 7 \"Src/GeometryR2/Projection.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ geometryR2 {\n\nPoint Projection(const Point& point, const Line& line) {\n \
    \   assert(line.isValid());\n    Real coeff{Dot(line.p1() - line.p0(), point -\
    \ line.p0()) / Point{line.p1() - line.p0()}.normSquare()};\n    return coeff *\
    \ line.p1() + (static_cast<Real>(1) - coeff) * line.p0();\n}\n\n} // namespace\
    \ geometryR2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./Point.hpp\"\n#include \"./Line.hpp\"\n\n#include\
    \ <cassert>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nPoint Projection(const\
    \ Point& point, const Line& line) {\n    assert(line.isValid());\n    Real coeff{Dot(line.p1()\
    \ - line.p0(), point - line.p0()) / Point{line.p1() - line.p0()}.normSquare()};\n\
    \    return coeff * line.p1() + (static_cast<Real>(1) - coeff) * line.p0();\n\
    }\n\n} // namespace geometryR2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Line.hpp
  isVerificationFile: false
  path: Src/GeometryR2/Projection.hpp
  requiredBy:
  - Src/GeometryR2/Reflection.hpp
  timestamp: '2023-11-08 20:56:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/CGL_1_B.test.cpp
  - Test/AOJ/CGL_1_A.test.cpp
documentation_of: Src/GeometryR2/Projection.hpp
layout: document
redirect_from:
- /library/Src/GeometryR2/Projection.hpp
- /library/Src/GeometryR2/Projection.hpp.html
title: Src/GeometryR2/Projection.hpp
---
