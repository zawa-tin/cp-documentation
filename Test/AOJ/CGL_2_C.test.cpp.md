---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp
    title: Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Distance/PointAndPoint.hpp
    title: Src/GeometryR2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Intersect/SegmentAndSegment.hpp
    title: Src/GeometryR2/Intersect/SegmentAndSegment.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Parallel/SegmentAndSegment.hpp
    title: Src/GeometryR2/Parallel/SegmentAndSegment.hpp
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
    path: Src/GeometryR2/Segment.hpp
    title: Src/GeometryR2/Segment.hpp
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
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
  bundledCode: "#line 1 \"Test/AOJ/CGL_2_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C\"\
    \n#define ERROR 0.00000001\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/GeometryR2/Segment.hpp\"\n\n#line 2 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Real.hpp\"\n\n#line 4 \"Src/GeometryR2/Real.hpp\"\
    \n\n#include <cmath>\n#include <cassert>\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nusing Real = long double;\nconstexpr Real EPS{1e-12};\n\nnamespace internal\
    \ {\n\nconstexpr i32 negative{-1};\nconstexpr i32 zero{};\nconstexpr i32 positive{1};\n\
    \n} // namespace internal\n\nconstexpr i32 Sign(Real value) {\n    if (value <\
    \ -EPS) return internal::negative;\n    if (value > EPS) return internal::positive;\n\
    \    return internal::zero;\n}\n\nconstexpr bool Zero(Real value) {\n    return\
    \ Sign(value) == internal::zero;\n}\n\nconstexpr bool Positive(Real value) {\n\
    \    return Sign(value) == internal::positive;\n}\n\nconstexpr bool Negative(Real\
    \ value) {\n    return Sign(value) == internal::negative;\n}\n\nconstexpr bool\
    \ Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nconstexpr bool Smaller(Real\
    \ a, Real b) {\n    return Negative(a - b);\n}\n\nconstexpr bool Bigger(Real a,\
    \ Real b) {\n    return Positive(a - b);\n}\n\nconstexpr Real Square(Real value)\
    \ {\n    return (Zero(value) ? value : value * value);\n}\n\nconstexpr Real Sqrt(Real\
    \ value) {\n    assert(!Negative(value));\n    return (Zero(value) ? value : sqrtl(value));\n\
    }\n\nconstexpr Real Abs(Real value) {\n    return (Negative(value) ? -value :\
    \ value);\n}\n\n} // namespace geometryR2\n \n} // namespace zawa\n#line 2 \"\
    Src/GeometryR2/Angle.hpp\"\n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\n\n#line 6\
    \ \"Src/GeometryR2/Angle.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\
    \nconstexpr Real PI{acosl(-1)};\nconstexpr Real TAU{static_cast<Real>(2) * PI};\n\
    \nconstexpr Real ArcToRadian(Real arc) {\n    return (arc * PI) / static_cast<Real>(180);\n\
    }\n\nconstexpr Real RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180))\
    \ / PI;\n}\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 5 \"Src/GeometryR2/Point.hpp\"\
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
    \ = Point;\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Relation.hpp\"\
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
    \ // namespace zawa\n#line 2 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\n\n\
    #line 4 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\n\nnamespace zawa {\n\n\
    namespace geometryR2 {\n\nReal Distance(const Point& p0, const Point& p1) {\n\
    \    return Point{p1 - p0}.norm();\n}\n\nReal DistanceSquare(const Point& p0,\
    \ const Point& p1) {\n    return Point{p1 - p0}.normSquare();\n}\n\n} // namespace\
    \ geometryR2\n\n} // namespace zawa\n#line 6 \"Src/GeometryR2/Segment.hpp\"\n\n\
    #include <algorithm>\n#line 9 \"Src/GeometryR2/Segment.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nclass Segment {\nprivate:\n    Point p0_{}, p1_{};\n\
    public:\n    /* constructor */\n    Segment() = default;\n    Segment(const Point&\
    \ p0, const Point& p1) : p0_{p0}, p1_{p1} {}\n    Segment(Real x0, Real y0, Real\
    \ x1, Real y1) : p0_{x0, y0}, p1_{x1, y1} {}\n\n    /* getter setter */\n    const\
    \ Point& p0() const {\n        return p0_;\n    }\n    Point& p0() {\n       \
    \ return p0_;\n    }\n    const Point& p1() const {\n        return p1_;\n   \
    \ }\n    Point& p1() {\n        return p1_;\n    }\n\n    /* member function */\n\
    \    bool valid() const {\n        return p0_ != p1_;\n    }\n    bool straddle(const\
    \ Segment& s) const {\n        return Relation(p0_, p1_, s.p0()) * Relation(p0_,\
    \ p1_, s.p1()) <= 0;\n    }\n    Real length() const {\n        assert(valid());\n\
    \        return Distance(p0_, p1_);\n    }\n};\n\n} // namespace geometryR2\n\n\
    } // namespace zawa\n#line 2 \"Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Parallel/SegmentAndSegment.hpp\"\n\n#line 4 \"Src/GeometryR2/Parallel/SegmentAndSegment.hpp\"\
    \n\n#line 6 \"Src/GeometryR2/Parallel/SegmentAndSegment.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nbool Parallel(const Segment& s0, const Segment&\
    \ s1) {\n    assert(s0.valid());\n    assert(s1.valid());\n    return Zero(Cross(s0.p1()\
    \ - s0.p0(), s1.p1() - s1.p0()));\n}\n\n} // namespace geometryR2\n\n} // namespace\
    \ zawa\n#line 2 \"Src/GeometryR2/Intersect/SegmentAndSegment.hpp\"\n\n#line 4\
    \ \"Src/GeometryR2/Intersect/SegmentAndSegment.hpp\"\n\n#line 6 \"Src/GeometryR2/Intersect/SegmentAndSegment.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nbool Intersect(const Segment&\
    \ s0, const Segment& s1) {\n    assert(s0.valid());\n    assert(s1.valid());\n\
    \    return s0.straddle(s1) and s1.straddle(s0);\n}\n\n} // namespace geometryR2\n\
    \n} // namespace zawa\n#line 7 \"Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp\"\
    \n\n#line 9 \"Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nPoint CrossPoint(const Segment& s0, const Segment&\
    \ s1) {\n    assert(s0.valid());\n    assert(s1.valid());\n    assert(Intersect(s0,\
    \ s1));\n    if (Parallel(s0, s1)) {\n        if (s0.p0() == s1.p0()) {\n    \
    \        if (Relation(s0.p0(), s0.p1(), s1.p1()) == ONLINE_BACK) {\n         \
    \       return s0.p0();\n            }\n            else {\n                assert(false);\n\
    \            }\n        }\n        else if (s0.p0() == s1.p1()) {\n          \
    \  if (Relation(s0.p0(), s0.p1(), s1.p0()) == ONLINE_BACK) {\n               \
    \ return s0.p0();\n            }\n            else {\n                assert(false);\n\
    \            }\n        }\n        else if (s0.p1() == s1.p0()) {\n          \
    \  if (Relation(s0.p1(), s0.p0(), s1.p1()) == ONLINE_BACK) {\n               \
    \ return s0.p1();\n            }\n            else {\n                assert(false);\n\
    \            }\n        }\n        else if (s0.p1() == s1.p1()) {\n          \
    \  if (Relation(s0.p1(), s0.p0(), s1.p0()) == ONLINE_BACK) {\n               \
    \ return s0.p1();\n            }\n            else {\n                assert(false);\n\
    \            }\n        }\n        else {\n            assert(false);\n      \
    \  }\n    }\n    else {\n        Vector base{s0.p1() - s0.p0()};\n        Real\
    \ baseNorm{base.norm()};\n        Real r1{Abs(Cross(base, s1.p0() - s0.p0()))\
    \ / baseNorm};\n        Real r2{Abs(Cross(base, s1.p1() - s0.p0())) / baseNorm};\n\
    \        return s1.p0() + (s1.p1() - s1.p0()) * (r1 / (r1 + r2));\n    }\n}\n\n\
    } // namespace geometryR2\n\n} // namespace zawa\n#line 7 \"Test/AOJ/CGL_2_C.test.cpp\"\
    \n\n#line 9 \"Test/AOJ/CGL_2_C.test.cpp\"\n\nint main() {\n    using namespace\
    \ zawa;\n    using namespace geometryR2;\n    SetFastIO();\n    SetPrecision(10);\n\
    \    int q; std::cin >> q;\n    for (int _{} ; _ < q ; _++) {\n        Segment\
    \ s0, s1;\n        std::cin >> s0.p0() >> s0.p1() >> s1.p0() >> s1.p1();\n   \
    \     Point ans{CrossPoint(s0, s1)};\n        std::cout << ans.x() << ' ' << ans.y()\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C\"\
    \n#define ERROR 0.00000001\n\n#include \"../../Src/Template/IOSetting.hpp\"\n\
    #include \"../../Src/GeometryR2/Segment.hpp\"\n#include \"../../Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    using namespace zawa;\n    using\
    \ namespace geometryR2;\n    SetFastIO();\n    SetPrecision(10);\n    int q; std::cin\
    \ >> q;\n    for (int _{} ; _ < q ; _++) {\n        Segment s0, s1;\n        std::cin\
    \ >> s0.p0() >> s0.p1() >> s1.p0() >> s1.p1();\n        Point ans{CrossPoint(s0,\
    \ s1)};\n        std::cout << ans.x() << ' ' << ans.y() << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryR2/Segment.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Relation.hpp
  - Src/GeometryR2/Distance/PointAndPoint.hpp
  - Src/GeometryR2/CrossPoint/SegmentAndSegment.hpp
  - Src/GeometryR2/Parallel/SegmentAndSegment.hpp
  - Src/GeometryR2/Intersect/SegmentAndSegment.hpp
  isVerificationFile: true
  path: Test/AOJ/CGL_2_C.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 09:08:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/CGL_2_C.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/CGL_2_C.test.cpp
- /verify/Test/AOJ/CGL_2_C.test.cpp.html
title: Test/AOJ/CGL_2_C.test.cpp
---
