---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/CrossPoint/LineAndLine.hpp
    title: Src/GeometryR2/CrossPoint/LineAndLine.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/CrossPoint/LineAndSegment.hpp
    title: Src/GeometryR2/CrossPoint/LineAndSegment.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Distance/PointAndPoint.hpp
    title: Src/GeometryR2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Intersect/LineAndLine.hpp
    title: Src/GeometryR2/Intersect/LineAndLine.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Line.hpp
    title: Src/GeometryR2/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Polygon.hpp
    title: Src/GeometryR2/Polygon.hpp
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
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_4_C.test.cpp
    title: Test/AOJ/CGL_4_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryR2/ConvexPolygonCut.hpp\"\n\n#line 2 \"Src/GeometryR2/Polygon.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/Real.hpp\"\
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
    }\n\n} // namespace geometryR2\n \n} // namespace zawa\n#line 2 \"Src/GeometryR2/Point.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Angle.hpp\"\n\n#line 4 \"Src/GeometryR2/Angle.hpp\"\
    \n\n#line 6 \"Src/GeometryR2/Angle.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nconstexpr Real PI{acosl(-1)};\nconstexpr Real TAU{static_cast<Real>(2)\
    \ * PI};\n\nconstexpr Real ArcToRadian(Real arc) {\n    return (arc * PI) / static_cast<Real>(180);\n\
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
    \ // namespace zawa\n#line 7 \"Src/GeometryR2/Polygon.hpp\"\n\n#include <algorithm>\n\
    #line 10 \"Src/GeometryR2/Polygon.hpp\"\n#include <concepts>\n#include <vector>\n\
    \nnamespace zawa {\n\nnamespace geometryR2 {\n\nclass Polygon {\nprivate:\n  \
    \  std::vector<Point> data_;\npublic:\n    /* member */\n    usize size() const\
    \ {\n        return data_.size();\n    }\n\n    /* constructor */\n    Polygon()\
    \ = default;\n    explicit Polygon(const std::vector<Point>& data) : data_{data}\
    \ {}\n    explicit Polygon(usize n) : data_(n) {}\n\n    /* operator[] */\n  \
    \  Point& operator[](usize i) {\n        assert(i < size());\n        return data_[i];\n\
    \    }\n    const Point& operator[](usize i) const {\n        assert(i < size());\n\
    \        return data_[i];\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, Polygon& polygon) {\n        for (size_t i{} ; i < polygon.size() ; i++)\
    \ {\n            is >> polygon[i];\n        }\n        return is;\n    }\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon) {\n\
    \        for (usize i{} ; i < polygon.size() ; i++) {\n            std::cout <<\
    \ polygon[i] << (i + 1 == polygon.size() ? \"\" : \" \");\n        }\n       \
    \ return os;\n    }\n\n    /* member function */\n    void orderRotate(usize i)\
    \ {\n        assert(i < size());\n        std::rotate(data_.begin(), data_.begin()\
    \ + i, data_.end());\n    }\n    void normalForm() {\n        auto index{std::distance(data_.begin(),\
    \ std::min_element(data_.begin(), data_.end()))};\n        orderRotate(index);\n\
    \    }\n    Polygon normalFormed() const {\n        Polygon res{*this};\n    \
    \    res.normalForm();\n        return res;\n    }\n    bool isConvex() const\
    \ {\n        assert(size() >= static_cast<usize>(3));\n        for (usize i{}\
    \ ; i < size() ; i++) {\n            if (Relation(data_[i], data_[i+1==size()?0:i+1],\
    \ data_[i+2>=size()?i+2-size():i+2])\n                    == CLOCKWISE) {\n  \
    \              return false;\n            }\n        }\n        return true;\n\
    \    }\n    Real area() const {\n        if (std::ssize(data_) <= 2) return 0;\n\
    \        Real res{};\n        for (usize i{1} ; i < size() ; i++) {\n        \
    \    res += Cross(data_[i] - data_[0], data_[i+1==size()?0:i+1] - data_[0]);\n\
    \        }\n        return res / static_cast<Real>(2);\n    }\n    void pushBack(const\
    \ Point& p) {\n        data_.push_back(p);\n    }\n    void emplaceBack(Real x,\
    \ Real y) {\n        data_.emplace_back(x, y);\n    }\n    void reserve(usize\
    \ n) {\n        data_.reserve(n);\n    }\n    template <std::input_iterator RandomAccessIterator>\n\
    \    void insert(usize n, RandomAccessIterator first, RandomAccessIterator last)\
    \ {\n        assert(n <= size());\n        data_.insert(std::next(data_.begin(),\
    \ n), first, last);\n    }\n};\n\n} // namespace geometryR2\n\n} // namespace\
    \ zawa\n\n#line 2 \"Src/GeometryR2/Line.hpp\"\n\n#line 5 \"Src/GeometryR2/Line.hpp\"\
    \n\n#line 7 \"Src/GeometryR2/Line.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nclass Line {\nprivate:\n    Point p0_{}, p1_{};\npublic:\n    /* constructor\
    \ */\n    Line() = default;\n    Line(const Point& p0, const Point& p1) : p0_{p0},\
    \ p1_{p1} {}\n    // y = ax + b \n    Line(Real a, Real b) : p0_{static_cast<Real>(0),\
    \ b}, p1_{static_cast<Real>(1), a + b} {}\n\n    /* getter, setter */\n    const\
    \ Point& p0() const {\n        return p0_;\n    }\n    Point& p0() {\n       \
    \ return p0_;\n    }\n    const Point& p1() const {\n        return p1_;\n   \
    \ }\n    Point& p1() {\n        return p1_;\n    }\n\n    /* operator */\n   \
    \ friend bool operator==(const Line& l0, const Line& l1) {\n        return Zero(Cross(l0.p1()\
    \ - l0.p0(), l1.p1() - l1.p0())) and Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l0.p0()));\n\
    \    }\n    friend bool operator!=(const Line& l0, const Line& l1) {\n       \
    \ return !Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0())) or !Zero(Cross(l0.p1()\
    \ - l0.p0(), l1.p1() - l0.p0()));\n    }\n\n    /* member function */\n    bool\
    \ valid() const {\n        return p0_ != p1_;\n    }\n    Vector slope() const\
    \ {\n        assert(valid());\n        return Vector{p1() - p0()}.normalized();\n\
    \    }\n};\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/CrossPoint/LineAndSegment.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Segment.hpp\"\n\n#line 2 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\
    \n\n#line 4 \"Src/GeometryR2/Distance/PointAndPoint.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryR2 {\n\nReal Distance(const Point& p0, const Point& p1) {\n\
    \    return Point{p1 - p0}.norm();\n}\n\nReal DistanceSquare(const Point& p0,\
    \ const Point& p1) {\n    return Point{p1 - p0}.normSquare();\n}\n\n} // namespace\
    \ geometryR2\n\n} // namespace zawa\n#line 6 \"Src/GeometryR2/Segment.hpp\"\n\n\
    #line 9 \"Src/GeometryR2/Segment.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR2\
    \ {\n\nclass Segment {\nprivate:\n    Point p0_{}, p1_{};\npublic:\n    /* constructor\
    \ */\n    Segment() = default;\n    Segment(const Point& p0, const Point& p1)\
    \ : p0_{p0}, p1_{p1} {}\n    Segment(Real x0, Real y0, Real x1, Real y1) : p0_{x0,\
    \ y0}, p1_{x1, y1} {}\n\n    /* getter setter */\n    const Point& p0() const\
    \ {\n        return p0_;\n    }\n    Point& p0() {\n        return p0_;\n    }\n\
    \    const Point& p1() const {\n        return p1_;\n    }\n    Point& p1() {\n\
    \        return p1_;\n    }\n\n    /* member function */\n    bool valid() const\
    \ {\n        return p0_ != p1_;\n    }\n    bool straddle(const Segment& s) const\
    \ {\n        return Relation(p0_, p1_, s.p0()) * Relation(p0_, p1_, s.p1()) <=\
    \ 0;\n    }\n    Real length() const {\n        assert(valid());\n        return\
    \ Distance(p0_, p1_);\n    }\n    Point midpoint() const {\n        assert(valid());\n\
    \        return p0_ + Vector{p1_ - p0_} / static_cast<Real>(2);\n    }\n};\n\n\
    } // namespace geometryR2\n\n} // namespace zawa\n#line 2 \"Src/GeometryR2/CrossPoint/LineAndLine.hpp\"\
    \n\n#line 2 \"Src/GeometryR2/Intersect/LineAndLine.hpp\"\n\n#line 4 \"Src/GeometryR2/Intersect/LineAndLine.hpp\"\
    \n\n#line 6 \"Src/GeometryR2/Intersect/LineAndLine.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryR2 {\n\nbool Intersect(const Line& l0, const Line& l1) {\n\
    \    assert(l0.valid());\n    assert(l1.valid());\n    if (!Zero(Cross(l0.p1()\
    \ - l0.p0(), l1.p1() - l1.p0()))) {\n        return true;\n    }\n    else if\
    \ (!Zero(Cross(l0.p1() - l0.p0(), l1.p0() - l0.p0()))) {\n        return false;\n\
    \    }\n    else {\n        return true;\n    }\n}\n\n} // namespace geometryR2\n\
    \n} // namespace \n#line 6 \"Src/GeometryR2/CrossPoint/LineAndLine.hpp\"\n\n#line\
    \ 8 \"Src/GeometryR2/CrossPoint/LineAndLine.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ geometryR2 {\n\nPoint CrossPoint(const Line& l0, const Line& l1) {\n    assert(l0.valid());\n\
    \    assert(l1.valid());\n    assert(Intersect(l0, l1));\n    assert(l0 != l1);\n\
    \    return l0.p0() + (l0.p1() - l0.p0()) * \n        (Cross(l1.p0() - l0.p0(),\
    \ l1.p1() - l1.p0()) / Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0()));\n}\n\n} //\
    \ namespace geometryR2\n\n} // namespace zawa\n#line 6 \"Src/GeometryR2/CrossPoint/LineAndSegment.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nPoint CrossPoint(const Line&\
    \ l, const Segment& s) {\n    assert(l.valid());\n    assert(s.valid());\n   \
    \ const i32 sl = Sign(Cross(l.p1() - l.p0(), s.p0() - l.p0()));\n    const i32\
    \ sr = Sign(Cross(l.p1() - l.p0(), s.p1() - l.p0()));\n    assert(sl * sr <= 0);\n\
    \    assert(sl != 0 or sr != 0);\n    return CrossPoint(l, Line{s.p0(), s.p1()});\n\
    }\n\n} // namespace geometryR2\n\n} // namespace zawa\n#line 6 \"Src/GeometryR2/ConvexPolygonCut.hpp\"\
    \n\n#include <utility>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nstd::pair<Polygon,\
    \ Polygon> ConvexPolygonCut(const Polygon& p, const Line& l) {\n    assert(p.isConvex());\n\
    \    assert(l.valid());\n    std::vector<i32> signs(p.size());\n    for (usize\
    \ i = 0 ; i < p.size() ; i++) signs[i] = Sign(Cross(l.p1() - l.p0(), l.p1() -\
    \ p[i]));\n    Polygon left, right;\n    for (usize i = 0 ; i < p.size() ; i++)\
    \ {\n        usize j = i + 1 == p.size() ? 0u : i + 1;\n        if (signs[i] >=\
    \ 0) right.pushBack(p[i]);\n        if (signs[i] <= 0) left.pushBack(p[i]);\n\
    \        if (signs[i] * signs[j] < 0) {\n            const Point& cp = CrossPoint(l,\
    \ Segment{p[i], p[j]});\n            right.pushBack(cp);\n            left.pushBack(cp);\n\
    \        }\n    }\n    return {left, right};\n}\n\n} // namespace geometryR2\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./Polygon.hpp\"\n#include \"./Line.hpp\"\n#include\
    \ \"./CrossPoint/LineAndSegment.hpp\"\n\n#include <utility>\n\nnamespace zawa\
    \ {\n\nnamespace geometryR2 {\n\nstd::pair<Polygon, Polygon> ConvexPolygonCut(const\
    \ Polygon& p, const Line& l) {\n    assert(p.isConvex());\n    assert(l.valid());\n\
    \    std::vector<i32> signs(p.size());\n    for (usize i = 0 ; i < p.size() ;\
    \ i++) signs[i] = Sign(Cross(l.p1() - l.p0(), l.p1() - p[i]));\n    Polygon left,\
    \ right;\n    for (usize i = 0 ; i < p.size() ; i++) {\n        usize j = i +\
    \ 1 == p.size() ? 0u : i + 1;\n        if (signs[i] >= 0) right.pushBack(p[i]);\n\
    \        if (signs[i] <= 0) left.pushBack(p[i]);\n        if (signs[i] * signs[j]\
    \ < 0) {\n            const Point& cp = CrossPoint(l, Segment{p[i], p[j]});\n\
    \            right.pushBack(cp);\n            left.pushBack(cp);\n        }\n\
    \    }\n    return {left, right};\n}\n\n} // namespace geometryR2\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/GeometryR2/Polygon.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryR2/Real.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Relation.hpp
  - Src/GeometryR2/Line.hpp
  - Src/GeometryR2/CrossPoint/LineAndSegment.hpp
  - Src/GeometryR2/Segment.hpp
  - Src/GeometryR2/Distance/PointAndPoint.hpp
  - Src/GeometryR2/CrossPoint/LineAndLine.hpp
  - Src/GeometryR2/Intersect/LineAndLine.hpp
  isVerificationFile: false
  path: Src/GeometryR2/ConvexPolygonCut.hpp
  requiredBy: []
  timestamp: '2025-07-03 17:15:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/CGL_4_C.test.cpp
documentation_of: Src/GeometryR2/ConvexPolygonCut.hpp
layout: document
redirect_from:
- /library/Src/GeometryR2/ConvexPolygonCut.hpp
- /library/Src/GeometryR2/ConvexPolygonCut.hpp.html
title: Src/GeometryR2/ConvexPolygonCut.hpp
---
