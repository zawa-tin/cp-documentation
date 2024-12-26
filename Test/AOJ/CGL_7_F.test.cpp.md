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
    path: Src/GeometryR2/Contain/CircleContainsPoint.hpp
    title: Src/GeometryR2/Contain/CircleContainsPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Contain/State.hpp
    title: Src/GeometryR2/Contain/State.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Distance/PointAndPoint.hpp
    title: Src/GeometryR2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Line.hpp
    title: Src/GeometryR2/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Real.hpp
    title: Src/GeometryR2/Real.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Relation.hpp
    title: Src/GeometryR2/Relation.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Tangent/TangentToCircle.hpp
    title: Src/GeometryR2/Tangent/TangentToCircle.hpp
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
    ERROR: '0.00001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F
  bundledCode: "#line 1 \"Test/AOJ/CGL_7_F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F\"\
    \n#define ERROR 0.00001\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/GeometryR2/Point.hpp\"\n\n#line 2 \"Src/GeometryR2/Real.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Real.hpp\"\n\n#include <cmath>\n#include <cassert>\n\
    \nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing Real = long double;\n\n\
    namespace internal {\n\nReal EPS{1e-12};\nconstexpr i32 negative{-1};\nconstexpr\
    \ i32 zero{};\nconstexpr i32 positive{1};\n\n} // namespace internal\n\nReal&\
    \ Eps() {\n    return internal::EPS;\n}\n\ni32 Sign(Real value) {\n    if (value\
    \ < -Eps()) return internal::negative;\n    if (value > Eps()) return internal::positive;\n\
    \    return internal::zero;\n}\n\nbool Zero(Real value) {\n    return Sign(value)\
    \ == internal::zero;\n}\n\nbool Positive(Real value) {\n    return Sign(value)\
    \ == internal::positive;\n}\n\nbool Negative(Real value) {\n    return Sign(value)\
    \ == internal::negative;\n}\n\nbool Equal(Real a, Real b) {\n    return Zero(a\
    \ - b);\n}\n\nbool Smaller(Real a, Real b) {\n    return Negative(a - b);\n}\n\
    \nbool Bigger(Real a, Real b) {\n    return Positive(a - b);\n}\n\nReal Square(Real\
    \ value) {\n    return (Zero(value) ? value : value * value);\n}\n\nReal Sqrt(Real\
    \ value) {\n    assert(!Negative(value));\n    return (Zero(value) ? value : sqrtl(value));\n\
    }\n\nReal Abs(Real value) {\n    return (Negative(value) ? -value : value);\n\
    }\n\n} // namespace geometryR2\n \n} // namespace zawa\n#line 2 \"Src/GeometryR2/Angle.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\n\n#line 6 \"Src/GeometryR2/Angle.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nconstexpr Real PI{acosl(-1)};\n\
    constexpr Real TAU{static_cast<Real>(2) * PI};\n\nconstexpr Real ArcToRadian(Real\
    \ arc) {\n    return (arc * PI) / static_cast<Real>(180);\n}\n\nconstexpr Real\
    \ RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180)) / PI;\n\
    }\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 9 \"Src/GeometryR2/Point.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nclass Point {\nprivate:\n    Real x_{}, y_{};\npublic:\n    /* constructor\
    \ */\n    Point() = default;\n    Point(Real x, Real y) : x_{x}, y_{y} {}\n\n\
    \    /* getter, setter */\n    Real x() const {\n        return x_;\n    }\n \
    \   Real& x() {\n        return x_;\n    }\n    Real y() const {\n        return\
    \ y_;\n    }\n    Real& y() {\n        return y_;\n    }\n\n    /* operator */\n\
    \    Point& operator+=(const Point& rhs) {\n        x_ += rhs.x();\n        y_\
    \ += rhs.y();\n        return *this;\n    }\n    friend Point operator+(const\
    \ Point& lhs, const Point& rhs) {\n        return Point{lhs} += rhs;\n    }\n\
    \    Point operator+() const {\n        return *this;\n    }\n    Point& operator-=(const\
    \ Point& rhs) {\n        x_ -= rhs.x();\n        y_ -= rhs.y();\n        return\
    \ *this;\n    }\n    friend Point operator-(const Point& lhs, const Point& rhs)\
    \ {\n        return Point{lhs} -= rhs;\n    }\n    Point operator-() const {\n\
    \        return Point{} - *this;\n    }\n    Point& operator*=(Real k) {\n   \
    \     x_ *= k;\n        y_ *= k;\n        return *this;\n    }\n    friend Point\
    \ operator*(Real k, const Point& p) {\n        return Point{p} *= k;\n    }\n\
    \    friend Point operator*(const Point& p, Real k) {\n        return Point{p}\
    \ *= k;\n    }\n    Point& operator/=(Real k) {\n        assert(!Zero(k));\n \
    \       x_ /= k;\n        y_ /= k;\n        return *this;\n    }\n    friend Point\
    \ operator/(Real k, const Point& p) {\n        return Point{p} /= k;\n    }\n\
    \    friend Point operator/(const Point& p, Real k) {\n        return Point{p}\
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
    \ const {\n        return Square(x_) + Square(y_);\n    }\n    Real norm() const\
    \ {\n        return Sqrt(normSquare());\n    }\n    void normalize() {\n     \
    \   assert((*this) != Point{});\n        (*this) /= norm(); \n    }\n    Point\
    \ normalized() const {\n        Point res{*this};\n        res.normalize();\n\
    \        return res;\n    }\n    Point rotated(Real radian) const {\n        return\
    \ Point{\n            x_ * cosl(radian) - y_ * sinl(radian),\n            x_ *\
    \ sinl(radian) + y_ * cosl(radian)\n        };\n    }\n    void rotate(Real radian)\
    \ {\n        *this = rotated(radian); \n    }\n    Point rotatedByArc(Real arc)\
    \ const {\n        return rotated(ArcToRadian(arc));\n    }\n    void rotateByArc(Real\
    \ arc) {\n        *this = rotatedByArc(arc);\n    }\n    Real argument() const\
    \ {\n        return (Negative(y_) ? TAU : static_cast<Real>(0)) + atan2l(y_, x_);\n\
    \    }\n    Real argumentByArc() const {\n        return RadianToArc(argument());\n\
    \    }\n\n    /* friend function */\n    friend Real Dot(const Point& lhs, const\
    \ Point& rhs) {\n        return lhs.x() * rhs.x() + lhs.y() * rhs.y();\n    }\n\
    \    friend Real Cross(const Point& lhs, const Point& rhs) {\n        return lhs.x()\
    \ * rhs.y() - lhs.y() * rhs.x();\n    }\n    friend Real Argument(const Point&\
    \ lhs, const Point& rhs) {\n        return rhs.argument() - lhs.argument();\n\
    \    }\n    friend bool ArgComp(const Point& lhs, const Point& rhs) {\n      \
    \  return Smaller(lhs.argument(), rhs.argument());\n    }\n};\n\nusing Vector\
    \ = Point;\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Circle.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\n\n#line 4 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nReal Distance(const Point& p0,\
    \ const Point& p1) {\n    return Point{p1 - p0}.norm();\n}\n\nReal DistanceSquare(const\
    \ Point& p0, const Point& p1) {\n    return Point{p1 - p0}.normSquare();\n}\n\n\
    } // namespace geometryR2\n\n} // namespace zawa\n#line 7 \"Src/GeometryR2/Circle.hpp\"\
    \n\n#line 9 \"Src/GeometryR2/Circle.hpp\"\n#include <utility>\n\nnamespace zawa\
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
    \ rhs.radius());\n    }\n\n    /* friend function */\n    friend u32 NumberCommonTangent(const\
    \ Circle& c0, const Circle& c1) {\n        Real dist{DistanceSquare(c0.center(),\
    \ c1.center())};\n        Real down{Square(Abs(c0.radius() - c1.radius()))};\n\
    \        if (Smaller(dist, down)) return 0;\n        if (Equal(dist, down)) return\
    \ 1;\n        Real up{Square(c0.radius() + c1.radius())};\n        if (Smaller(dist,\
    \ up)) return 2;\n        if (Equal(dist, up)) return 3;\n        return 4;\n\
    \    }\n};\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Tangent/TangentToCircle.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Line.hpp\"\n\n#line 2 \"Src/GeometryR2/Relation.hpp\"\
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
    \ // namespace zawa\n#line 5 \"Src/GeometryR2/Line.hpp\"\n\n#line 7 \"Src/GeometryR2/Line.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nclass Line {\nprivate:\n   \
    \ Point p0_{}, p1_{};\npublic:\n    /* constructor */\n    Line() = default;\n\
    \    Line(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}\n    // y =\
    \ ax + b \n    Line(Real a, Real b) : p0_{static_cast<Real>(0), b}, p1_{static_cast<Real>(1),\
    \ a + b} {}\n\n    /* getter, setter */\n    const Point& p0() const {\n     \
    \   return p0_;\n    }\n    Point& p0() {\n        return p0_;\n    }\n    const\
    \ Point& p1() const {\n        return p1_;\n    }\n    Point& p1() {\n       \
    \ return p1_;\n    }\n\n    /* operator */\n    friend bool operator==(const Line&\
    \ l0, const Line& l1) {\n        return Zero(Cross(l0.p1() - l0.p0(), l1.p1()\
    \ - l1.p0())) and Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l0.p0()));\n    }\n\
    \    friend bool operator!=(const Line& l0, const Line& l1) {\n        return\
    \ !Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0())) or !Zero(Cross(l0.p1() -\
    \ l0.p0(), l1.p1() - l0.p0()));\n    }\n\n    /* member function */\n    bool\
    \ valid() const {\n        return p0_ != p1_;\n    }\n    Vector slope() const\
    \ {\n        assert(valid());\n        return Vector{p1() - p0()}.normalized();\n\
    \    }\n};\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Contain/CircleContainsPoint.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Contain/State.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ geometryR2 {\n\nenum ContainState {\n    INSIDE,\n    ONLINE,\n    OUTSIDE\n\
    };\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 8 \"Src/GeometryR2/Contain/CircleContainsPoint.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nContainState CircleContainsPoint(const\
    \ Circle& circle, const Point& p) {\n    Real dist{Distance(circle.center(), p)};\n\
    \    if (Smaller(dist, circle.radius())) {\n        return INSIDE;\n    }\n  \
    \  else if (Equal(dist, circle.radius())) {\n        return ONLINE;\n    }\n \
    \   else {\n        return OUTSIDE;\n    }\n}\n\n} // namespace geometryR2\n\n\
    } // namespace zawa\n#line 9 \"Src/GeometryR2/Tangent/TangentToCircle.hpp\"\n\n\
    #line 11 \"Src/GeometryR2/Tangent/TangentToCircle.hpp\"\n\nnamespace zawa {\n\n\
    namespace geometryR2 {\n\n// p0\u306B\u63A5\u70B9\u304C\u4EE3\u5165\u3055\u308C\
    \u307E\u3059\nstd::pair<Line, Line> TangentToCircle(const Circle& c, const Point&\
    \ p) {\n    ContainState state{CircleContainsPoint(c, p)};\n    assert(state !=\
    \ INSIDE);\n    if (state == ONLINE) {\n        Vector dir{Vector{p - c.center()}.rotatedByArc(90)};\n\
    \        return {Line{p, p + dir}, Line{p, p + dir}};\n    }\n    else {\n   \
    \     Vector dir{c.center() - p};\n        Real theta{asinl(c.radius() / dir.norm())};\n\
    \        Real len{Sqrt(dir.normSquare() - Square(c.radius()))};\n        dir.normalize();\n\
    \        return {Line{p + dir.rotated(theta) * len, p}, Line{p + dir.rotated(-theta)\
    \ * len, p}};\n    }\n}\n\n} // namespace geometryR2\n\n} // namespace zawa\n\
    #line 8 \"Test/AOJ/CGL_7_F.test.cpp\"\n\n#line 11 \"Test/AOJ/CGL_7_F.test.cpp\"\
    \n\nint main() {\n    using namespace zawa;\n    using namespace geometryR2;\n\
    \    SetPrecision(7);\n    Point p; std::cin >> p;\n    Circle c; std::cin >>\
    \ c.center() >> c.radius();\n    auto tangent{TangentToCircle(c, p)};\n    std::pair<Point,\
    \ Point> ans{tangent.first.p0(), tangent.second.p0()};\n    if (ans.first > ans.second)\
    \ std::swap(ans.first, ans.second);\n    std::cout << ans.first.x() << ' ' <<\
    \ ans.first.y() << '\\n';\n    std::cout << ans.second.x() << ' ' << ans.second.y()\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F\"\
    \n#define ERROR 0.00001\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include\
    \ \"../../Src/GeometryR2/Point.hpp\"\n#include \"../../Src/GeometryR2/Circle.hpp\"\
    \n#include \"../../Src/GeometryR2/Tangent/TangentToCircle.hpp\"\n\n#include <iostream>\n\
    #include <utility>\n\nint main() {\n    using namespace zawa;\n    using namespace\
    \ geometryR2;\n    SetPrecision(7);\n    Point p; std::cin >> p;\n    Circle c;\
    \ std::cin >> c.center() >> c.radius();\n    auto tangent{TangentToCircle(c, p)};\n\
    \    std::pair<Point, Point> ans{tangent.first.p0(), tangent.second.p0()};\n \
    \   if (ans.first > ans.second) std::swap(ans.first, ans.second);\n    std::cout\
    \ << ans.first.x() << ' ' << ans.first.y() << '\\n';\n    std::cout << ans.second.x()\
    \ << ' ' << ans.second.y() << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Circle.hpp
  - Src/GeometryR2/Distance/PointAndPoint.hpp
  - Src/GeometryR2/Tangent/TangentToCircle.hpp
  - Src/GeometryR2/Line.hpp
  - Src/GeometryR2/Relation.hpp
  - Src/GeometryR2/Contain/CircleContainsPoint.hpp
  - Src/GeometryR2/Contain/State.hpp
  isVerificationFile: true
  path: Test/AOJ/CGL_7_F.test.cpp
  requiredBy: []
  timestamp: '2023-11-22 13:46:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/CGL_7_F.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/CGL_7_F.test.cpp
- /verify/Test/AOJ/CGL_7_F.test.cpp.html
title: Test/AOJ/CGL_7_F.test.cpp
---