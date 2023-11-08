---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Real.hpp
    title: Src/GeometryR2/Real.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_7_E.test.cpp
    title: Test/AOJ/CGL_7_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryR2/Circle.hpp\"\n\n#line 2 \"Src/GeometryR2/Real.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing Real = long double;\n\
    constexpr Real EPS{1e-12};\n\nnamespace internal {\n\nconstexpr int negative{-1};\n\
    constexpr int zero{};\nconstexpr int positive{1};\n\n} // namespace internal\n\
    \nconstexpr int Sign(Real value) {\n    if (value < -EPS) return internal::negative;\n\
    \    if (value > EPS) return internal::positive;\n    return internal::zero;\n\
    }\n\nconstexpr bool Zero(Real value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool Positive(Real value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Negative(Real value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr bool Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nconstexpr\
    \ bool Smaller(Real a, Real b) {\n    return Negative(a - b);\n}\n\nconstexpr\
    \ bool Bigger(Real a, Real b) {\n    return Positive(a - b);\n}\n\n} // namespace\
    \ geometryR2\n \n} // namespace zawa\n#line 2 \"Src/GeometryR2/Point.hpp\"\n\n\
    #line 2 \"Src/GeometryR2/Angle.hpp\"\n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\n\
    \n#include <cmath>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nconstexpr\
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
    \ = Point;\n\n} // namespace geomeryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Circle.hpp\"\
    \n\n#line 7 \"Src/GeometryR2/Circle.hpp\"\n#include <utility>\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nclass Circle {\nprivate:\n    Point center_{};\n\
    \    Real radius_{};\npublic:\n    /* constructor */\n    Circle() = default;\n\
    \    Circle(const Point& center, Real radius) : center_{center}, radius_{radius}\
    \ {\n        assert(!Negative(radius));\n    }\n    Circle(Real x, Real y, Real\
    \ r) : center_{x, y}, radius_{r} {\n        assert(!Negative(r));\n    }\n\n \
    \   /* getter setter */\n    const Point& center() const {\n        return center_;\n\
    \    }\n    Point& center() {\n        return center_;\n    }\n    Real radius()\
    \ const {\n        return radius_;\n    }\n    Real& radius() {\n        return\
    \ radius_;\n    }\n\n    /* operator */\n    friend bool operator==(const Circle&\
    \ lhs, const Circle& rhs) {\n        return lhs.center() == rhs.center() and Equal(lhs.radius(),\
    \ rhs.radius());\n    }\n    friend bool operator!=(const Circle& lhs, const Circle&\
    \ rhs) {\n        return lhs.center() != rhs.center() or !Equal(lhs.radius(),\
    \ rhs.radius());\n    }\n\n    /* friend function */\n    friend bool Intersect(const\
    \ Circle& lhs, const Circle& rhs) {\n        Real centerDist{DistanceSquare(lhs.center(),\
    \ rhs.center())};\n        Real down{std::abs(lhs.radius() - rhs.radius())};\n\
    \        down = down * down;\n        if (Smaller(centerDist, down)) return false;\n\
    \        Real up{lhs.radius() + rhs.radius()};\n        up = up * up;\n      \
    \  if (Bigger(centerDist, up)) return false;\n        return true;\n    }\n  \
    \  friend std::pair<Point, Point> CrossPoint(const Circle& lhs, const Circle&\
    \ rhs) {\n        assert(lhs.center() != rhs.center());\n        assert(Intersect(lhs,\
    \ rhs));\n        assert(!Zero(lhs.radius()) or !Zero(rhs.radius()));\n      \
    \  if (Zero(lhs.radius())) return {lhs.center(), lhs.center()};\n        if (Zero(rhs.radius()))\
    \ return {rhs.center(), rhs.center()};\n        Real d{Distance(lhs.center(),\
    \ rhs.center())};\n        Real cosine{(lhs.radius()*lhs.radius() + d*d - rhs.radius()*rhs.radius())\n\
    \            / (static_cast<Real>(2)*lhs.radius()*d)};\n        Real rc{lhs.radius()*cosine};\n\
    \        Real rs{sqrtl(lhs.radius()*lhs.radius() - rc*rc)};\n        Vector lr{Vector{rhs.center()\
    \ - lhs.center()}.normalized()};\n        Vector h{lhs.center() + lr*rc};\n  \
    \      std::pair<Point, Point> res;\n        res.first = h + lr.rotatedByArc(90)\
    \ * rs;\n        res.second = h + lr.rotatedByArc(-90) * rs;\n        return res;\n\
    \    }\n};\n\n} // namespace geometryR2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./Real.hpp\"\n#include \"./Point.hpp\"\n\n#include\
    \ <cassert>\n#include <utility>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\
    \nclass Circle {\nprivate:\n    Point center_{};\n    Real radius_{};\npublic:\n\
    \    /* constructor */\n    Circle() = default;\n    Circle(const Point& center,\
    \ Real radius) : center_{center}, radius_{radius} {\n        assert(!Negative(radius));\n\
    \    }\n    Circle(Real x, Real y, Real r) : center_{x, y}, radius_{r} {\n   \
    \     assert(!Negative(r));\n    }\n\n    /* getter setter */\n    const Point&\
    \ center() const {\n        return center_;\n    }\n    Point& center() {\n  \
    \      return center_;\n    }\n    Real radius() const {\n        return radius_;\n\
    \    }\n    Real& radius() {\n        return radius_;\n    }\n\n    /* operator\
    \ */\n    friend bool operator==(const Circle& lhs, const Circle& rhs) {\n   \
    \     return lhs.center() == rhs.center() and Equal(lhs.radius(), rhs.radius());\n\
    \    }\n    friend bool operator!=(const Circle& lhs, const Circle& rhs) {\n \
    \       return lhs.center() != rhs.center() or !Equal(lhs.radius(), rhs.radius());\n\
    \    }\n\n    /* friend function */\n    friend bool Intersect(const Circle& lhs,\
    \ const Circle& rhs) {\n        Real centerDist{DistanceSquare(lhs.center(), rhs.center())};\n\
    \        Real down{std::abs(lhs.radius() - rhs.radius())};\n        down = down\
    \ * down;\n        if (Smaller(centerDist, down)) return false;\n        Real\
    \ up{lhs.radius() + rhs.radius()};\n        up = up * up;\n        if (Bigger(centerDist,\
    \ up)) return false;\n        return true;\n    }\n    friend std::pair<Point,\
    \ Point> CrossPoint(const Circle& lhs, const Circle& rhs) {\n        assert(lhs.center()\
    \ != rhs.center());\n        assert(Intersect(lhs, rhs));\n        assert(!Zero(lhs.radius())\
    \ or !Zero(rhs.radius()));\n        if (Zero(lhs.radius())) return {lhs.center(),\
    \ lhs.center()};\n        if (Zero(rhs.radius())) return {rhs.center(), rhs.center()};\n\
    \        Real d{Distance(lhs.center(), rhs.center())};\n        Real cosine{(lhs.radius()*lhs.radius()\
    \ + d*d - rhs.radius()*rhs.radius())\n            / (static_cast<Real>(2)*lhs.radius()*d)};\n\
    \        Real rc{lhs.radius()*cosine};\n        Real rs{sqrtl(lhs.radius()*lhs.radius()\
    \ - rc*rc)};\n        Vector lr{Vector{rhs.center() - lhs.center()}.normalized()};\n\
    \        Vector h{lhs.center() + lr*rc};\n        std::pair<Point, Point> res;\n\
    \        res.first = h + lr.rotatedByArc(90) * rs;\n        res.second = h + lr.rotatedByArc(-90)\
    \ * rs;\n        return res;\n    }\n};\n\n} // namespace geometryR2\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Angle.hpp
  isVerificationFile: false
  path: Src/GeometryR2/Circle.hpp
  requiredBy: []
  timestamp: '2023-11-08 20:56:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/CGL_7_E.test.cpp
documentation_of: Src/GeometryR2/Circle.hpp
layout: document
redirect_from:
- /library/Src/GeometryR2/Circle.hpp
- /library/Src/GeometryR2/Circle.hpp.html
title: Src/GeometryR2/Circle.hpp
---
