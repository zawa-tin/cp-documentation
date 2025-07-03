---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/ConvexHull.hpp
    title: Src/GeometryZ2/ConvexHull.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp
    title: Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Distance/PointAndPoint.hpp
    title: Src/GeometryZ2/Distance/PointAndPoint.hpp
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
    path: Src/GeometryZ2/Zahlen.hpp
    title: Src/GeometryZ2/Zahlen.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/FloatingMarkerShift.hpp
    title: "\u6587\u5B57\u5217\u3067\u53D7\u3051\u53D6\u3063\u305F\u5C0F\u6570\u3092\
      10\u500D\u3057\u307E\u304F\u3063\u3066\u6574\u6570\u306B\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
  bundledCode: "#line 1 \"Test/AOJ/CGL_4_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#line 2 \"Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp\"\
    \n\n#line 2 \"Src/GeometryZ2/PointCloud.hpp\"\n\n#line 2 \"Src/GeometryZ2/Point.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\
    \n\n#line 4 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#include <cassert>\n\nnamespace zawa\
    \ {\n\nnamespace geometryZ2 {\n\nusing Zahlen = i64;\n\nnamespace internal {\n\
    \nconstexpr i32 positive{1};\nconstexpr i32 zero{0};\nconstexpr i32 negative{-1};\n\
    \n} // namespace internal\n\nconstexpr i32 Sign(Zahlen value) {\n    if (value\
    \ < 0) return internal::negative;\n    if (value > 0) return internal::positive;\n\
    \    return internal::zero;\n}\n\nconstexpr bool Positive(Zahlen value) {\n  \
    \  return Sign(value) == internal::positive;\n}\n\nconstexpr bool Zero(Zahlen\
    \ value) {\n    return Sign(value) == internal::zero;\n}\n\nconstexpr bool Negative(Zahlen\
    \ value) {\n    return Sign(value) == internal::negative;\n}\n\nconstexpr Zahlen\
    \ Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n}\n\nconstexpr\
    \ Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n} // namespace\
    \ geometryZ2\n\n} // namespace zawa\n#line 5 \"Src/GeometryZ2/Point.hpp\"\n\n\
    #include <algorithm>\n#include <iostream>\n#line 9 \"Src/GeometryZ2/Point.hpp\"\
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
    \ geometryZ2\n\n} // namespace zawa\n#line 4 \"Src/GeometryZ2/PointCloud.hpp\"\
    \n\n#line 6 \"Src/GeometryZ2/PointCloud.hpp\"\n#include <vector>\n\nnamespace\
    \ zawa {\n\nnamespace geometryZ2 {\n\nusing PointCloud = std::vector<Point>;\n\
    \nvoid ArgSort(PointCloud& p) {\n    std::sort(p.begin(), p.end(), Point::ArgComp);\n\
    }\n\n} // namespace geometryZ2 \n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/ConvexHull.hpp\"\
    \n\n#line 2 \"Src/GeometryZ2/Polygon.hpp\"\n\n#line 2 \"Src/GeometryZ2/Relation.hpp\"\
    \n\n#line 5 \"Src/GeometryZ2/Relation.hpp\"\n\nnamespace zawa {\n\nnamespace geometryZ2\
    \ {\n\nenum RELATION {\n    // p0 -> p1 -> p2\u306E\u9806\u3067\u76F4\u7DDA\u4E0A\
    \u306B\u4E26\u3093\u3067\u3044\u308B\n    ONLINE_FRONT        = -2,\n    // (p1\
    \ - p0) -> (p2 - p0)\u304C\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\
    \u308B\n    CLOCKWISE           = -1,\n    // p0 -> p2 -> p1\u306E\u9806\u3067\
    \u76F4\u7DDA\u4E0A\u306B\u4E26\u3093\u3067\u3044\u308B\n    ON_SEGMENT       \
    \   =  0,\n    // (p1 - p0) -> (p2 - p0)\u304C\u53CD\u6642\u8A08\u56DE\u308A\u306B\
    \u306A\u3063\u3066\u3044\u308B\n    COUNTER_CLOCKWISE   = +1,\n    // p2 -> p0\
    \ -> p1\u3001\u307E\u305F\u306Fp1 -> p0 -> p2\u306E\u9806\u3067\u76F4\u7DDA\u4E0A\
    \u306B\u4E26\u3093\u3067\u3044\u308B\n    ONLINE_BACK         = +2\n};\n\nRELATION\
    \ Relation(const Point& p0, const Point& p1, const Point& p2) {\n    Point a{p1\
    \ - p0}, b{p2 - p0};\n    if (Positive(Cross(a, b))) return COUNTER_CLOCKWISE;\n\
    \    if (Negative(Cross(a, b))) return CLOCKWISE;\n    if (Negative(Dot(a, b)))\
    \ return ONLINE_BACK;\n    if (a.normSquare() < b.normSquare()) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n\
    #line 6 \"Src/GeometryZ2/Polygon.hpp\"\n\n#line 9 \"Src/GeometryZ2/Polygon.hpp\"\
    \n#include <iterator>\n#include <type_traits>\n#line 12 \"Src/GeometryZ2/Polygon.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass Polygon {\nprivate:\n\
    \    std::vector<Point> data_;\npublic:\n    usize size() const {\n        return\
    \ data_.size(); \n    }\n\n    /* constructor */\n    Polygon() = default;\n \
    \   Polygon(const Polygon& polygon) : data_{polygon.data_} {}\n    Polygon(const\
    \ std::vector<Point>& data) : data_{data} {}\n    Polygon(usize n) : data_{n}\
    \ {\n        assert(n >= static_cast<usize>(3));\n    }\n\n    /* operator */\n\
    \    Polygon& operator=(const Polygon& polygon) {\n        data_ = polygon.data_;\n\
    \        return *this;\n    }\n    Point& operator[](usize i) {\n        assert(i\
    \ < size());\n        return data_[i];\n    }\n    const Point& operator[](usize\
    \ i) const {\n        assert(i < size());\n        return data_[i];\n    }\n \
    \   friend std::istream& operator>>(std::istream& is, Polygon& polygon) {\n  \
    \      for (size_t i{} ; i < polygon.size() ; i++) {\n            is >> polygon[i];\n\
    \        }\n        return is;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Polygon& polygon) {\n        for (usize i{} ; i < polygon.size() ;\
    \ i++) {\n            std::cout << polygon[i] << (i + 1 == polygon.size() ? \"\
    \" : \" \");\n        }\n        return os;\n    }\n\n    /* member function */\n\
    \    void reserve(usize n) {\n        data_.reserve(n);\n    }\n    void pushBack(const\
    \ Point& p) {\n        data_.push_back(p);\n    }\n    void emplaceBack(Zahlen\
    \ x, Zahlen y) {\n        data_.emplace_back(x, y);\n    }\n    template <class\
    \ RandomAccessIterator>\n    void insert(usize n, RandomAccessIterator first,\
    \ RandomAccessIterator last) {\n        assert(n <= size());\n        data_.insert(std::next(data_.begin(),\
    \ n), first, last);\n    }\n    void orderRotate(usize i) {\n        assert(i\
    \ < size());\n        std::rotate(data_.begin(), data_.begin() + i, data_.end());\n\
    \    }\n    template <class F>\n    void normalForm(const F& func) {\n       \
    \ auto index{std::distance(data_.begin(), std::min_element(data_.begin(), data_.end(),\
    \ func))};\n        orderRotate(index);\n    }\n    void normalForm() {\n    \
    \    auto index{std::distance(data_.begin(), std::min_element(data_.begin(), data_.end()))};\n\
    \        orderRotate(index);\n    }\n    template <class F>\n    Polygon normalFormed(const\
    \ F& func = [](const Point& a, const Point& b) -> bool { return a < b; }) const\
    \ {\n        Polygon res{*this};\n        res.normalForm(func);\n        return\
    \ res;\n    }\n    Polygon normalFormed() {\n        Polygon res{*this};\n   \
    \     res.normalForm();\n        return res;\n    }\n    bool isConvex() const\
    \ {\n        assert(size() >= static_cast<usize>(3));\n        for (usize i{}\
    \ ; i < size() ; i++) {\n            if (Relation(data_[i], data_[i+1==size()?0:i+1],\
    \ data_[i+2>=size()?i+2-size():i+2])\n                    == CLOCKWISE) {\n  \
    \              return false;\n            }\n        }\n        return true;\n\
    \    }\n    Zahlen areaTwice() const {\n        assert(size() >= static_cast<usize>(3));\n\
    \        Zahlen res{};\n        for (usize i{1} ; i < size() ; i++) {\n      \
    \      res += Cross(data_[i] - data_[0], data_[i+1==size()?0:i+1] - data_[0]);\n\
    \        }\n        return res;\n    }\n    Polygon subtriangle(usize i, usize\
    \ j, usize k) const {\n        assert(i < size());\n        assert(j < size());\n\
    \        assert(k < size());\n        return Polygon{std::vector<Point>{ data_[i],\
    \ data_[j], data_[k] }};\n    }\n};\n\n}\n\n} // namespace zawa\n#line 7 \"Src/GeometryZ2/ConvexHull.hpp\"\
    \n\n#line 13 \"Src/GeometryZ2/ConvexHull.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ geometryZ2 {\n\ntemplate <bool strictly>\nPolygon ConvexHull(const PointCloud&\
    \ p) {\n    PointCloud cp{p};\n    std::sort(cp.begin(), cp.end());\n    cp.erase(std::unique(cp.begin(),\
    \ cp.end()), cp.end());\n    if (cp.size() <= 2u) {\n        return Polygon{cp};\n\
    \    }\n    PointCloud lower;\n    lower.reserve(p.size());\n    for (auto it{cp.begin()}\
    \ ; it != cp.end() ; it++) {\n        lower.push_back(*it);\n        while (lower.size()\
    \ >= 3u) {\n            if (Relation(lower[lower.size() - 3], lower[lower.size()\
    \ - 2], lower[lower.size() - 1]) == COUNTER_CLOCKWISE) {\n                break;\n\
    \            }\n            if constexpr (!strictly) {\n                if (Relation(lower[lower.size()\
    \ - 3], lower[lower.size() - 2], lower[lower.size() - 1]) == ONLINE_FRONT) {\n\
    \                    break;\n                }\n            }\n            std::swap(lower[lower.size()\
    \ - 2], lower[lower.size() - 1]);\n            lower.pop_back();\n        }\n\
    \    }\n    PointCloud upper;\n    upper.reserve(p.size());\n    for (auto it{cp.rbegin()}\
    \ ; it != cp.rend() ; it++) {\n        upper.push_back(*it);\n        while (upper.size()\
    \ >= 3u) {\n            if (Relation(upper[upper.size() - 3], upper[upper.size()\
    \ - 2], upper[upper.size() - 1]) == COUNTER_CLOCKWISE) {\n                break;\n\
    \            }\n            if constexpr (!strictly) {\n                if (Relation(upper[upper.size()\
    \ - 3], upper[upper.size() - 2], upper[upper.size() - 1]) == ONLINE_FRONT) {\n\
    \                    break;\n                }\n            }\n            std::swap(upper[upper.size()\
    \ - 2], upper[upper.size() - 1]);\n            upper.pop_back();\n        }\n\
    \    }\n\n    Polygon res;\n    res.reserve(lower.size() + upper.size() - 2);\n\
    \    res.insert(res.size(), lower.begin(), lower.end());\n    res.insert(res.size(),\
    \ std::next(upper.begin()), std::prev(upper.end()));\n    return res;\n}\n\n}\
    \ // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Distance/PointAndPoint.hpp\"\
    \n\n#line 5 \"Src/GeometryZ2/Distance/PointAndPoint.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryZ2 {\n\nZahlen DistanceSquare(const Point& p0, const Point&\
    \ p1) {\n    return Vector{p1 - p0}.normSquare();\n}\n\n} // namespace geometryZ2\n\
    \n} // namespace zawa\n#line 6 \"Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp\"\
    \n\n#line 8 \"Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace geometryZ2 {\n\ntemplate <class T = usize>\nstd::pair<T,\
    \ T> FurthestPairOfPoints(const PointCloud& P) {\n    assert(std::ssize(P) >=\
    \ 2);\n    const auto ch = ConvexHull<true>(P);\n    if (std::ssize(ch) == 1)\
    \ { // \u5168\u90E8\u306E\u70B9\u304C\u540C\u3058\u6240\u306B\u3042\u308B -> \u4F55\
    \u3067\u3082\u826F\u3044\n        return {T{0}, T{1}};\n    }\n    usize mini\
    \ = 0, minj = 1;\n    Zahlen mind = DistanceSquare(ch[mini], ch[minj]);\n    if\
    \ (std::ssize(ch) > 2) {\n        usize idx = 0, jdx = 0;\n        for (usize\
    \ i = 1 ; i < ch.size() ; i++) {\n            if (ch[idx].x() > ch[i].x()) idx\
    \ = i;\n            if (ch[jdx].x() < ch[i].x()) jdx = i;\n        }\n       \
    \ const usize sidx = idx, sjdx = jdx;\n        while (idx != sjdx or jdx != sidx)\
    \ {\n            if (mind < DistanceSquare(ch[idx], ch[jdx])) {\n            \
    \    mind = DistanceSquare(ch[idx], ch[jdx]);\n                mini = idx;\n \
    \               minj = jdx;\n            }\n            if (Cross(ch[idx+1==ch.size()?0:idx+1]\
    \ - ch[idx], ch[jdx+1==ch.size()?0:jdx+1] - ch[jdx]) < 0) {\n                idx\
    \ = idx+1==ch.size()?0:idx+1;\n            }\n            else {\n           \
    \     jdx = jdx+1==ch.size()?0:jdx+1;\n            }\n        }\n    }\n    const\
    \ T n = static_cast<T>(P.size());\n    T i = n, j = n;\n    for (usize k = 0 ;\
    \ k < P.size() ; k++) {\n        if (i == n and P[k] == ch[mini]) i = k;\n   \
    \     if (j == n and P[k] == ch[minj]) j = k;\n    }\n    return {i, j};\n}\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/Utility/FloatingMarkerShift.hpp\"\
    \n\n#line 4 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#include <string>\n#line\
    \ 8 \"Src/Utility/FloatingMarkerShift.hpp\"\n\nnamespace zawa {\n\ni64 FloatingMarkerShift(const\
    \ std::string& S, u32 shift) {\n    static i64 lim10{std::numeric_limits<i64>::max()\
    \ / 10};\n    assert(not S.empty());\n    i64 res{};\n    u32 moved{};\n    bool\
    \ start{};\n    bool minus{S[0] == '-'};\n    for (u32 i{(u32)minus} ; i < S.size()\
    \ ; i++) {\n        if (S[i] == '.') {\n            start = true;\n        }\n\
    \        else {\n            if (start) moved++;\n            assert(res < lim10);\n\
    \            res = res * 10;\n            assert(res < std::numeric_limits<i64>::max()\
    \ - (S[i] - '0'));\n            res += S[i] - '0';\n        }\n    }\n    assert(moved\
    \ <= shift);\n    while (moved < shift) {\n        moved++;\n        assert(res\
    \ < lim10);\n        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return\
    \ res;\n}\n\n}// namespace zawa\n#line 6 \"Test/AOJ/CGL_4_B.test.cpp\"\nusing\
    \ namespace zawa;\nusing namespace geometryZ2;\n\n#line 10 \"Test/AOJ/CGL_4_B.test.cpp\"\
    \n#include <iomanip>\n#include <cmath>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int N;\n\
    \    std::cin >> N;\n    PointCloud P(N);\n    for (auto& p : P) {\n        std::string\
    \ x, y;\n        std::cin >> x >> y;\n        p = {FloatingMarkerShift(x, 6),\
    \ FloatingMarkerShift(y, 6)};\n    }\n    auto [i, j] = FurthestPairOfPoints<int>(P);\n\
    \    std::cout << std::fixed << std::setprecision(8) << sqrtl(DistanceSquare(P[i],\
    \ P[j])) / 1000000.0l << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#include \"../../Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp\"\
    \n#include \"../../Src/Utility/FloatingMarkerShift.hpp\"\nusing namespace zawa;\n\
    using namespace geometryZ2;\n\n#include <iostream>\n#include <iomanip>\n#include\
    \ <cmath>\n\nint main() {\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    PointCloud\
    \ P(N);\n    for (auto& p : P) {\n        std::string x, y;\n        std::cin\
    \ >> x >> y;\n        p = {FloatingMarkerShift(x, 6), FloatingMarkerShift(y, 6)};\n\
    \    }\n    auto [i, j] = FurthestPairOfPoints<int>(P);\n    std::cout << std::fixed\
    \ << std::setprecision(8) << sqrtl(DistanceSquare(P[i], P[j])) / 1000000.0l <<\
    \ '\\n';\n}\n"
  dependsOn:
  - Src/GeometryZ2/Distance/FurthestPairOfPoints.hpp
  - Src/GeometryZ2/PointCloud.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/ConvexHull.hpp
  - Src/GeometryZ2/Polygon.hpp
  - Src/GeometryZ2/Relation.hpp
  - Src/GeometryZ2/Distance/PointAndPoint.hpp
  - Src/Utility/FloatingMarkerShift.hpp
  isVerificationFile: true
  path: Test/AOJ/CGL_4_B.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 13:18:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/CGL_4_B.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/CGL_4_B.test.cpp
- /verify/Test/AOJ/CGL_4_B.test.cpp.html
title: Test/AOJ/CGL_4_B.test.cpp
---
