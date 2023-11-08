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
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
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
    ERROR: '0.000001'
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_b
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_b
  bundledCode: "#line 1 \"Test/AtCoder/abc259_b.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_b\"\
    \n#define ERROR 0.000001\n\n#line 2 \"Src/GeometryR2/Point.hpp\"\n\n#line 2 \"\
    Src/GeometryR2/Real.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing\
    \ Real = long double;\nconstexpr Real EPS{1e-12};\n\nnamespace internal {\n\n\
    constexpr int negative{-1};\nconstexpr int zero{};\nconstexpr int positive{1};\n\
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
    \ = Point;\n\n} // namespace geomeryR2\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 6 \"Src/Template/IOSetting.hpp\"\n#include <iomanip>\n\nnamespace zawa\
    \ {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 6 \"Test/AtCoder/abc259_b.test.cpp\"\n\n#line\
    \ 8 \"Test/AtCoder/abc259_b.test.cpp\"\n\nint main() {\n    using namespace zawa;\n\
    \    using namespace geometryR2;\n    Point p; std::cin >> p;\n    int d; std::cin\
    \ >> d;\n    p.rotateByArc(d);\n    SetPrecision(10);\n    std::cout << p.x()\
    \ << ' ' << p.y() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc259/tasks/abc259_b\"\n#define\
    \ ERROR 0.000001\n\n#include \"../../Src/GeometryR2/Point.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    using namespace zawa;\n    using\
    \ namespace geometryR2;\n    Point p; std::cin >> p;\n    int d; std::cin >> d;\n\
    \    p.rotateByArc(d);\n    SetPrecision(10);\n    std::cout << p.x() << ' ' <<\
    \ p.y() << '\\n';\n}\n"
  dependsOn:
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc259_b.test.cpp
  requiredBy: []
  timestamp: '2023-11-08 20:56:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc259_b.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc259_b.test.cpp
- /verify/Test/AtCoder/abc259_b.test.cpp.html
title: Test/AtCoder/abc259_b.test.cpp
---
