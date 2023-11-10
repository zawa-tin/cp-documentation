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
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Relation.hpp
    title: Src/GeometryR2/Relation.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_2_B.test.cpp
    title: Test/AOJ/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_2_C.test.cpp
    title: Test/AOJ/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_2_D.test.cpp
    title: Test/AOJ/CGL_2_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryR2/Segment.hpp\"\n\n#line 2 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Real.hpp\"\n\n#include <cmath>\n#include <cassert>\n\
    \nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing Real = long double;\nconstexpr\
    \ Real EPS{1e-12};\n\nnamespace internal {\n\nconstexpr int negative{-1};\nconstexpr\
    \ int zero{};\nconstexpr int positive{1};\n\n} // namespace internal\n\nconstexpr\
    \ int Sign(Real value) {\n    if (value < -EPS) return internal::negative;\n \
    \   if (value > EPS) return internal::positive;\n    return internal::zero;\n\
    }\n\nconstexpr bool Zero(Real value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool Positive(Real value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Negative(Real value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr bool Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nconstexpr\
    \ bool Smaller(Real a, Real b) {\n    return Negative(a - b);\n}\n\nconstexpr\
    \ bool Bigger(Real a, Real b) {\n    return Positive(a - b);\n}\n\nconstexpr Real\
    \ Square(Real value) {\n    return value * value;\n}\n\nconstexpr Real Sqrt(Real\
    \ value) {\n    assert(!Negative(value));\n    return (Zero(value) ? value : sqrtl(value));\n\
    }\n\nconstexpr Real Abs(Real value) {\n    return (Negative(value) ? -value :\
    \ value);\n}\n\n} // namespace geometryR2\n \n} // namespace zawa\n#line 2 \"\
    Src/GeometryR2/Angle.hpp\"\n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\n\n#line 6\
    \ \"Src/GeometryR2/Angle.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\
    \nconstexpr Real PI{acosl(-1)};\nconstexpr Real TAU{static_cast<Real>(2) * PI};\n\
    \nconstexpr Real ArcToRadian(Real arc) {\n    return (arc * PI) / static_cast<Real>(180);\n\
    }\n\nconstexpr Real RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180))\
    \ / PI;\n}\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 7 \"Src/GeometryR2/Point.hpp\"\n#include <iostream>\n#line 9 \"Src/GeometryR2/Point.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nclass Point {\nprivate:\n  \
    \  Real x_{}, y_{};\npublic:\n    /* constructor */\n    Point() = default;\n\
    \    Point(Real x, Real y) : x_{x}, y_{y} {}\n\n    /* getter, setter */\n   \
    \ Real x() const {\n        return x_;\n    }\n    Real& x() {\n        return\
    \ x_;\n    }\n    Real y() const {\n        return y_;\n    }\n    Real& y() {\n\
    \        return y_;\n    }\n\n    /* operator */\n    Point& operator+=(const\
    \ Point& rhs) {\n        x_ += rhs.x();\n        y_ += rhs.y();\n        return\
    \ *this;\n    }\n    friend Point operator+(const Point& lhs, const Point& rhs)\
    \ {\n        return Point{lhs} += rhs;\n    }\n    Point operator+() const {\n\
    \        return *this;\n    }\n    Point& operator-=(const Point& rhs) {\n   \
    \     x_ -= rhs.x();\n        y_ -= rhs.y();\n        return *this;\n    }\n \
    \   friend Point operator-(const Point& lhs, const Point& rhs) {\n        return\
    \ Point{lhs} -= rhs;\n    }\n    Point operator-() const {\n        return Point{}\
    \ - *this;\n    }\n    Point& operator*=(Real k) {\n        x_ *= k;\n       \
    \ y_ *= k;\n        return *this;\n    }\n    friend Point operator*(Real k, const\
    \ Point& p) {\n        return Point{p} *= k;\n    }\n    friend Point operator*(const\
    \ Point& p, Real k) {\n        return Point{p} *= k;\n    }\n    Point& operator/=(Real\
    \ k) {\n        assert(!Zero(k));\n        x_ /= k;\n        y_ /= k;\n      \
    \  return *this;\n    }\n    friend Point operator/(Real k, const Point& p) {\n\
    \        return Point{p} /= k;\n    }\n    friend Point operator/(const Point&\
    \ p, Real k) {\n        return Point{p} /= k;\n    }\n    friend bool operator==(const\
    \ Point& lhs, const Point& rhs) {\n        return Equal(lhs.x(), rhs.x()) and\
    \ Equal(lhs.y(), rhs.y());\n    }\n    friend bool operator!=(const Point& lhs,\
    \ const Point& rhs) {\n        return !Equal(lhs.x(), rhs.x()) or !Equal(lhs.y(),\
    \ rhs.y());\n    }\n    friend bool operator<(const Point& lhs, const Point& rhs)\
    \ {\n        return Smaller(lhs.x(), rhs.x()) or \n            (Equal(lhs.x(),\
    \ rhs.x()) and Smaller(lhs.y(), rhs.y()));\n    }\n    friend bool operator<=(const\
    \ Point& lhs, const Point& rhs) {\n        return Smaller(lhs.x(), rhs.x()) or\
    \ \n            (Equal(lhs.x(), rhs.x()) and (Smaller(lhs.y(), rhs.y()) or Equal(lhs.y(),\
    \ rhs.y())));\n    }\n    friend bool operator>(const Point& lhs, const Point&\
    \ rhs) {\n        return Bigger(lhs.x(), rhs.x()) or\n            (Equal(lhs.x(),\
    \ rhs.x()) and Bigger(lhs.y(), rhs.y()));\n    }\n    friend bool operator>=(const\
    \ Point& lhs, const Point& rhs) {\n        return Bigger(lhs.x(), rhs.x()) or\n\
    \            (Equal(lhs.x(), rhs.x()) and (Bigger(lhs.y(), rhs.y()) or Equal(lhs.y(),\
    \ rhs.y())));\n    }\n    friend std::istream& operator>>(std::istream& is, Point&\
    \ p) {\n        is >> p.x_ >> p.y_;\n        return is;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Point& p) {\n        os << '(' << p.x_ <<\
    \ ',' << p.y_ << ')';\n        return os;\n    }\n    \n    /* member function\
    \ */\n    Real normSquare() const {\n        return Square(x_) + Square(y_);\n\
    \    }\n    Real norm() const {\n        return Sqrt(normSquare());\n    }\n \
    \   void normalize() {\n        (*this) /= norm(); \n    }\n    Point normalized()\
    \ const {\n        Point res{*this};\n        res.normalize();\n        return\
    \ res;\n    }\n    Point rotated(Real radian) const {\n        return Point{\n\
    \            x_ * cosl(radian) - y_ * sinl(radian),\n            x_ * sinl(radian)\
    \ + y_ * cosl(radian)\n        };\n    }\n    void rotate(Real radian) {\n   \
    \     *this = rotated(radian); \n    }\n    Point rotatedByArc(Real arc) const\
    \ {\n        return rotated(ArcToRadian(arc));\n    }\n    void rotateByArc(Real\
    \ arc) {\n        *this = rotatedByArc(arc);\n    }\n    Real argument() const\
    \ {\n        return (Negative(y_) ? TAU : static_cast<Real>(0)) + atan2l(y_, x_);\n\
    \    }\n    Real argumentByArc() const {\n        return RadianToArc(argument());\n\
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
    \ = Point;\n\n} // namespace geomeryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Relation.hpp\"\
    \n\n#line 5 \"Src/GeometryR2/Relation.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nenum RELATION {\n    // p0 -> p1 -> p2\u306E\u9806\u3067\u76F4\u7DDA\u4E0A\
    \u306B\u4E26\u3093\u3067\u3044\u308B\n    ONLINE_FRONT = -2,\n    // (p1 - p0)\
    \ -> (p2 - p0)\u304C\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\
    \n    CLOCKWISE,\n    // p0 -> p2 -> p1\u306E\u9806\u3067\u76F4\u7DDA\u4E0A\u306B\
    \u4E26\u3093\u3067\u3044\u308B\n    ON_SEGMENT,\n    // (p1 - p0) -> (p2 - p0)\u304C\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\n    COUNTER_CLOCKWISE,\n\
    \    // p2 -> p0 -> p1\u3001\u307E\u305F\u306Fp1 -> p0 -> p2\u306E\u9806\u3067\
    \u76F4\u7DDA\u4E0A\u306B\u4E26\u3093\u3067\u3044\u308B\n    ONLINE_BACK\n};\n\n\
    RELATION Relation(const Point& p0, const Point& p1, const Point& p2) {\n    Point\
    \ a{p1 - p0}, b{p2 - p0};\n    if (Positive(Cross(a, b))) return COUNTER_CLOCKWISE;\n\
    \    if (Negative(Cross(a, b))) return CLOCKWISE;\n    if (Negative(Dot(a, b)))\
    \ return ONLINE_BACK;\n    if (Smaller(a.normSquare(), b.normSquare())) return\
    \ ONLINE_FRONT;\n    return ON_SEGMENT;\n};\n\n} // namespace geometryR2\n\n}\
    \ // namespace zawa\n#line 5 \"Src/GeometryR2/Segment.hpp\"\n\n#include <algorithm>\n\
    \nnamespace zawa {\n\nnamespace geometryR2 {\n\nclass Segment {\nprivate:\n  \
    \  Point p0_{}, p1_{};\npublic:\n    /* constructor */\n    Segment() = default;\n\
    \    Segment(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}\n    Segment(Real\
    \ x0, Real y0, Real x1, Real y1) : p0_{x0, y0}, p1_{x1, y1} {}\n\n    /* getter\
    \ setter */\n    const Point& p0() const {\n        return p0_;\n    }\n    Point&\
    \ p0() {\n        return p0_;\n    }\n    const Point& p1() const {\n        return\
    \ p1_;\n    }\n    Point& p1() {\n        return p1_;\n    }\n\n    /* member\
    \ function */\n    bool valid() const {\n        return p0_ != p1_;\n    }\n \
    \   bool straddle(const Segment& s) const {\n        return Relation(p0_, p1_,\
    \ s.p0()) * Relation(p0_, p1_, s.p1()) <= 0;\n    }\n    Real length() const {\n\
    \        return Vector{p1_ - p0_}.norm();\n    }\n    Real distance(const Point&\
    \ p) const {\n        assert(valid());\n        if (Negative(Dot(p1_ - p0_, p\
    \ - p0_))) return Vector{p - p0_}.norm();\n        if (Negative(Dot(p0_ - p1_,\
    \ p - p1_))) return Vector{p - p1_}.norm();\n        return Abs(Cross(p1_ - p0_,\
    \ p - p0_) / length());\n    }\n    bool on(const Point& p) const {\n        assert(valid());\n\
    \        return Zero(distance(p));\n    }\n\n    /* friend function */\n    friend\
    \ bool Parallel(const Segment& s0, const Segment& s1) {\n        assert(s0.valid());\n\
    \        assert(s1.valid());\n        return Zero(Cross(s0.p1() - s0.p0(), s1.p1()\
    \ - s1.p0()));\n    }\n    friend bool Intersect(const Segment& s0, const Segment&\
    \ s1) {\n        return s0.straddle(s1) and s1.straddle(s0); \n    }\n    friend\
    \ bool Orthgonal(const Segment& s0, const Segment& s1) {\n        assert(s0.valid());\n\
    \        assert(s1.valid());\n        return Intersect(s0, s1) and Zero(Dot(s0.p1()\
    \ - s0.p0(), s1.p1() - s1.p0()));\n    }\n    friend Real Distance(const Segment&\
    \ s0, const Segment& s1) {\n        if (Intersect(s0, s1)) return static_cast<Real>(0);\n\
    \        return std::min({\n                s0.distance(s1.p0()),\n          \
    \      s0.distance(s1.p1()),\n                s1.distance(s0.p0()),\n        \
    \        s1.distance(s0.p1())\n                });\n    }\n    friend Point CrossPoint(const\
    \ Segment& s0, const Segment& s1) {\n        assert(s0.valid());\n        assert(s1.valid());\n\
    \        assert(Intersect(s0, s1));\n        if (Parallel(s0, s1)) {\n       \
    \     if (s0.p0() == s1.p0()) {\n                if (Relation(s0.p0(), s0.p1(),\
    \ s1.p1()) == ONLINE_BACK) {\n                    return s0.p0();\n          \
    \      }\n                else {\n                    assert(false);\n       \
    \         }\n            }\n            else if (s0.p0() == s1.p1()) {\n     \
    \           if (Relation(s0.p0(), s0.p1(), s1.p0()) == ONLINE_BACK) {\n      \
    \              return s0.p0();\n                }\n                else {\n  \
    \                  assert(false);\n                }\n            }\n        \
    \    else if (s0.p1() == s1.p0()) {\n                if (Relation(s0.p1(), s0.p0(),\
    \ s1.p1()) == ONLINE_BACK) {\n                    return s0.p1();\n          \
    \      }\n                else {\n                    assert(false);\n       \
    \         }\n            }\n            else if (s0.p1() == s1.p1()) {\n     \
    \           if (Relation(s0.p1(), s0.p0(), s1.p0()) == ONLINE_BACK) {\n      \
    \              return s0.p1();\n                }\n                else {\n  \
    \                  assert(false);\n                }\n            }\n        \
    \    else {\n                assert(false);\n            }\n        }\n      \
    \  else {\n            Vector base{s0.p1() - s0.p0()};\n            Real baseNorm{base.norm()};\n\
    \            Real r1{Abs(Cross(base, s1.p0() - s0.p0())) / baseNorm};\n      \
    \      Real r2{Abs(Cross(base, s1.p1() - s0.p0())) / baseNorm};\n            return\
    \ s1.p0() + (s1.p1() - s1.p0()) * (r1 / (r1 + r2));\n        }\n    }\n};\n\n\
    } // namespace geometryR2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./Point.hpp\"\n#include \"./Relation.hpp\"\n\n\
    #include <algorithm>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nclass Segment\
    \ {\nprivate:\n    Point p0_{}, p1_{};\npublic:\n    /* constructor */\n    Segment()\
    \ = default;\n    Segment(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1}\
    \ {}\n    Segment(Real x0, Real y0, Real x1, Real y1) : p0_{x0, y0}, p1_{x1, y1}\
    \ {}\n\n    /* getter setter */\n    const Point& p0() const {\n        return\
    \ p0_;\n    }\n    Point& p0() {\n        return p0_;\n    }\n    const Point&\
    \ p1() const {\n        return p1_;\n    }\n    Point& p1() {\n        return\
    \ p1_;\n    }\n\n    /* member function */\n    bool valid() const {\n       \
    \ return p0_ != p1_;\n    }\n    bool straddle(const Segment& s) const {\n   \
    \     return Relation(p0_, p1_, s.p0()) * Relation(p0_, p1_, s.p1()) <= 0;\n \
    \   }\n    Real length() const {\n        return Vector{p1_ - p0_}.norm();\n \
    \   }\n    Real distance(const Point& p) const {\n        assert(valid());\n \
    \       if (Negative(Dot(p1_ - p0_, p - p0_))) return Vector{p - p0_}.norm();\n\
    \        if (Negative(Dot(p0_ - p1_, p - p1_))) return Vector{p - p1_}.norm();\n\
    \        return Abs(Cross(p1_ - p0_, p - p0_) / length());\n    }\n    bool on(const\
    \ Point& p) const {\n        assert(valid());\n        return Zero(distance(p));\n\
    \    }\n\n    /* friend function */\n    friend bool Parallel(const Segment& s0,\
    \ const Segment& s1) {\n        assert(s0.valid());\n        assert(s1.valid());\n\
    \        return Zero(Cross(s0.p1() - s0.p0(), s1.p1() - s1.p0()));\n    }\n  \
    \  friend bool Intersect(const Segment& s0, const Segment& s1) {\n        return\
    \ s0.straddle(s1) and s1.straddle(s0); \n    }\n    friend bool Orthgonal(const\
    \ Segment& s0, const Segment& s1) {\n        assert(s0.valid());\n        assert(s1.valid());\n\
    \        return Intersect(s0, s1) and Zero(Dot(s0.p1() - s0.p0(), s1.p1() - s1.p0()));\n\
    \    }\n    friend Real Distance(const Segment& s0, const Segment& s1) {\n   \
    \     if (Intersect(s0, s1)) return static_cast<Real>(0);\n        return std::min({\n\
    \                s0.distance(s1.p0()),\n                s0.distance(s1.p1()),\n\
    \                s1.distance(s0.p0()),\n                s1.distance(s0.p1())\n\
    \                });\n    }\n    friend Point CrossPoint(const Segment& s0, const\
    \ Segment& s1) {\n        assert(s0.valid());\n        assert(s1.valid());\n \
    \       assert(Intersect(s0, s1));\n        if (Parallel(s0, s1)) {\n        \
    \    if (s0.p0() == s1.p0()) {\n                if (Relation(s0.p0(), s0.p1(),\
    \ s1.p1()) == ONLINE_BACK) {\n                    return s0.p0();\n          \
    \      }\n                else {\n                    assert(false);\n       \
    \         }\n            }\n            else if (s0.p0() == s1.p1()) {\n     \
    \           if (Relation(s0.p0(), s0.p1(), s1.p0()) == ONLINE_BACK) {\n      \
    \              return s0.p0();\n                }\n                else {\n  \
    \                  assert(false);\n                }\n            }\n        \
    \    else if (s0.p1() == s1.p0()) {\n                if (Relation(s0.p1(), s0.p0(),\
    \ s1.p1()) == ONLINE_BACK) {\n                    return s0.p1();\n          \
    \      }\n                else {\n                    assert(false);\n       \
    \         }\n            }\n            else if (s0.p1() == s1.p1()) {\n     \
    \           if (Relation(s0.p1(), s0.p0(), s1.p0()) == ONLINE_BACK) {\n      \
    \              return s0.p1();\n                }\n                else {\n  \
    \                  assert(false);\n                }\n            }\n        \
    \    else {\n                assert(false);\n            }\n        }\n      \
    \  else {\n            Vector base{s0.p1() - s0.p0()};\n            Real baseNorm{base.norm()};\n\
    \            Real r1{Abs(Cross(base, s1.p0() - s0.p0())) / baseNorm};\n      \
    \      Real r2{Abs(Cross(base, s1.p1() - s0.p0())) / baseNorm};\n            return\
    \ s1.p0() + (s1.p1() - s1.p0()) * (r1 / (r1 + r2));\n        }\n    }\n};\n\n\
    } // namespace geometryR2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Relation.hpp
  isVerificationFile: false
  path: Src/GeometryR2/Segment.hpp
  requiredBy: []
  timestamp: '2023-11-10 17:17:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/CGL_2_B.test.cpp
  - Test/AOJ/CGL_2_C.test.cpp
  - Test/AOJ/CGL_2_D.test.cpp
documentation_of: Src/GeometryR2/Segment.hpp
layout: document
redirect_from:
- /library/Src/GeometryR2/Segment.hpp
- /library/Src/GeometryR2/Segment.hpp.html
title: Src/GeometryR2/Segment.hpp
---
