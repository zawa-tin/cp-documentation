---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Circle.hpp
    title: Src/GeometryR2/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Distance/PointAndPoint.hpp
    title: Src/GeometryR2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Real.hpp
    title: Src/GeometryR2/Real.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A
  bundledCode: "#line 1 \"Test/AOJ/CGL_7_A/GeometryR2.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A\"\n\n#line\
    \ 2 \"Src/GeometryR2/Circle.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n\
    #include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    \nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 2 \"Src/GeometryR2/Real.hpp\"\n\n#line 4 \"Src/GeometryR2/Real.hpp\"\n\n\
    #include <cmath>\n#include <cassert>\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nusing Real = long double;\n\nnamespace internal {\n\nReal EPS{1e-12};\n\
    constexpr i32 negative{-1};\nconstexpr i32 zero{};\nconstexpr i32 positive{1};\n\
    \n} // namespace internal\n\nReal& Eps() {\n    return internal::EPS;\n}\n\ni32\
    \ Sign(Real value) {\n    if (value < -Eps()) return internal::negative;\n   \
    \ if (value > Eps()) return internal::positive;\n    return internal::zero;\n\
    }\n\nbool Zero(Real value) {\n    return Sign(value) == internal::zero;\n}\n\n\
    bool Positive(Real value) {\n    return Sign(value) == internal::positive;\n}\n\
    \nbool Negative(Real value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nbool Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nbool Smaller(Real\
    \ a, Real b) {\n    return Negative(a - b);\n}\n\nbool Bigger(Real a, Real b)\
    \ {\n    return Positive(a - b);\n}\n\nReal Square(Real value) {\n    return (Zero(value)\
    \ ? value : value * value);\n}\n\nReal Sqrt(Real value) {\n    assert(!Negative(value));\n\
    \    return (Zero(value) ? value : sqrtl(value));\n}\n\nReal Abs(Real value) {\n\
    \    return (Negative(value) ? -value : value);\n}\n\n} // namespace geometryR2\n\
    \ \n} // namespace zawa\n#line 2 \"Src/GeometryR2/Point.hpp\"\n\n#line 2 \"Src/GeometryR2/Angle.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\n\n#line 6 \"Src/GeometryR2/Angle.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nconstexpr Real PI{acosl(-1)};\n\
    constexpr Real TAU{static_cast<Real>(2) * PI};\n\nconstexpr Real ArcToRadian(Real\
    \ arc) {\n    return (arc * PI) / static_cast<Real>(180);\n}\n\nconstexpr Real\
    \ RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180)) / PI;\n\
    }\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Point.hpp\"\
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
    \   void normalize() {\n        assert((*this) != Point{});\n        (*this) /=\
    \ norm(); \n    }\n    Point normalized() const {\n        Point res{*this};\n\
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
    \ * rhs.y() - lhs.y() * rhs.x();\n    }\n    friend Real Argument(const Point&\
    \ lhs, const Point& rhs) {\n        return rhs.argument() - lhs.argument();\n\
    \    }\n    friend bool ArgComp(const Point& lhs, const Point& rhs) {\n      \
    \  return Smaller(lhs.argument(), rhs.argument());\n    }\n};\n\nusing Vector\
    \ = Point;\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryR2 {\n\nReal Distance(const Point& p0, const Point& p1) {\n\
    \    return Point{p1 - p0}.norm();\n}\n\nReal DistanceSquare(const Point& p0,\
    \ const Point& p1) {\n    return Point{p1 - p0}.normSquare();\n}\n\n} // namespace\
    \ geometryR2\n\n} // namespace zawa\n#line 7 \"Src/GeometryR2/Circle.hpp\"\n\n\
    #line 9 \"Src/GeometryR2/Circle.hpp\"\n#include <utility>\n\nnamespace zawa {\n\
    \nnamespace geometryR2 {\n\nclass Circle {\nprivate:\n    Point center_{};\n \
    \   Real radius_{};\npublic:\n    /* constructor */\n    Circle() = default;\n\
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
    \ rhs.radius());\n    }\n\n    /* friend function */\n    friend u32 NumberCommonTangent(const\
    \ Circle& c0, const Circle& c1) {\n        Real dist{DistanceSquare(c0.center(),\
    \ c1.center())};\n        Real down{Square(Abs(c0.radius() - c1.radius()))};\n\
    \        if (Smaller(dist, down)) return 0;\n        if (Equal(dist, down)) return\
    \ 1;\n        Real up{Square(c0.radius() + c1.radius())};\n        if (Smaller(dist,\
    \ up)) return 2;\n        if (Equal(dist, up)) return 3;\n        return 4;\n\
    \    }\n};\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 4 \"Test/AOJ/CGL_7_A/GeometryR2.test.cpp\"\
    \n\n#line 6 \"Test/AOJ/CGL_7_A/GeometryR2.test.cpp\"\n\nint main() {\n    using\
    \ namespace zawa::geometryR2;\n    Circle a, b;\n    std::cin >> a.center() >>\
    \ a.radius();\n    std::cin >> b.center() >> b.radius();\n    std::cout << NumberCommonTangent(a,\
    \ b) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A\"\
    \n\n#include \"../../../Src/GeometryR2/Circle.hpp\"\n\n#include <iostream>\n\n\
    int main() {\n    using namespace zawa::geometryR2;\n    Circle a, b;\n    std::cin\
    \ >> a.center() >> a.radius();\n    std::cin >> b.center() >> b.radius();\n  \
    \  std::cout << NumberCommonTangent(a, b) << '\\n';\n}\n"
  dependsOn:
  - Src/GeometryR2/Circle.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Distance/PointAndPoint.hpp
  isVerificationFile: true
  path: Test/AOJ/CGL_7_A/GeometryR2.test.cpp
  requiredBy: []
  timestamp: '2023-11-20 11:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/CGL_7_A/GeometryR2.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/CGL_7_A/GeometryR2.test.cpp
- /verify/Test/AOJ/CGL_7_A/GeometryR2.test.cpp.html
title: Test/AOJ/CGL_7_A/GeometryR2.test.cpp
---