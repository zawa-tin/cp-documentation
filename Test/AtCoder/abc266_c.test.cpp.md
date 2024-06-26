---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc266/tasks/abc266_c
    links:
    - https://atcoder.jp/contests/abc266/tasks/abc266_c
  bundledCode: "#line 1 \"Test/AtCoder/abc266_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_c\"\
    \n\n#line 2 \"Src/GeometryZ2/Polygon.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Point.hpp\"\n\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\
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
    \ geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Relation.hpp\"\n\
    \n#line 5 \"Src/GeometryZ2/Relation.hpp\"\n\nnamespace zawa {\n\nnamespace geometryZ2\
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
    \n#include <iterator>\n#include <type_traits>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nnamespace geometryZ2 {\n\nclass Polygon {\nprivate:\n    std::vector<Point>\
    \ data_;\npublic:\n    usize size() const {\n        return data_.size(); \n \
    \   }\n\n    /* constructor */\n    Polygon() = default;\n    Polygon(const Polygon&\
    \ polygon) : data_{polygon.data_} {}\n    Polygon(const std::vector<Point>& data)\
    \ : data_{data} {}\n    Polygon(usize n) : data_{n} {\n        assert(n >= static_cast<usize>(3));\n\
    \    }\n\n    /* operator */\n    Polygon& operator=(const Polygon& polygon) {\n\
    \        data_ = polygon.data_;\n        return *this;\n    }\n    Point& operator[](usize\
    \ i) {\n        assert(i < size());\n        return data_[i];\n    }\n    const\
    \ Point& operator[](usize i) const {\n        assert(i < size());\n        return\
    \ data_[i];\n    }\n    friend std::istream& operator>>(std::istream& is, Polygon&\
    \ polygon) {\n        for (size_t i{} ; i < polygon.size() ; i++) {\n        \
    \    is >> polygon[i];\n        }\n        return is;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Polygon& polygon) {\n        for (usize i{}\
    \ ; i < polygon.size() ; i++) {\n            std::cout << polygon[i] << (i + 1\
    \ == polygon.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    \    /* member function */\n    void reserve(usize n) {\n        data_.reserve(n);\n\
    \    }\n    void pushBack(const Point& p) {\n        data_.push_back(p);\n   \
    \ }\n    void emplaceBack(Zahlen x, Zahlen y) {\n        data_.emplace_back(x,\
    \ y);\n    }\n    template <class RandomAccessIterator>\n    void insert(usize\
    \ n, RandomAccessIterator first, RandomAccessIterator last) {\n        assert(n\
    \ <= size());\n        data_.insert(std::next(data_.begin(), n), first, last);\n\
    \    }\n    void orderRotate(usize i) {\n        assert(i < size());\n       \
    \ std::rotate(data_.begin(), data_.begin() + i, data_.end());\n    }\n    template\
    \ <class F>\n    void normalForm(const F& func) {\n        auto index{std::distance(data_.begin(),\
    \ std::min_element(data_.begin(), data_.end(), func))};\n        orderRotate(index);\n\
    \    }\n    void normalForm() {\n        auto index{std::distance(data_.begin(),\
    \ std::min_element(data_.begin(), data_.end()))};\n        orderRotate(index);\n\
    \    }\n    template <class F>\n    Polygon normalFormed(const F& func = [](const\
    \ Point& a, const Point& b) -> bool { return a < b; }) const {\n        Polygon\
    \ res{*this};\n        res.normalForm(func);\n        return res;\n    }\n   \
    \ Polygon normalFormed() {\n        Polygon res{*this};\n        res.normalForm();\n\
    \        return res;\n    }\n    bool isConvex() const {\n        assert(size()\
    \ >= static_cast<usize>(3));\n        for (usize i{} ; i < size() ; i++) {\n \
    \           if (Relation(data_[i], data_[i+1==size()?0:i+1], data_[i+2>=size()?i+2-size():i+2])\n\
    \                    == CLOCKWISE) {\n                return false;\n        \
    \    }\n        }\n        return true;\n    }\n    Zahlen areaTwice() const {\n\
    \        assert(size() >= static_cast<usize>(3));\n        Zahlen res{};\n   \
    \     for (usize i{1} ; i < size() ; i++) {\n            res += Cross(data_[i]\
    \ - data_[0], data_[i+1==size()?0:i+1] - data_[0]);\n        }\n        return\
    \ res;\n    }\n    Polygon subtriangle(usize i, usize j, usize k) const {\n  \
    \      assert(i < size());\n        assert(j < size());\n        assert(k < size());\n\
    \        return Polygon{std::vector<Point>{ data_[i], data_[j], data_[k] }};\n\
    \    }\n};\n\n}\n\n} // namespace zawa\n#line 4 \"Test/AtCoder/abc266_c.test.cpp\"\
    \n\n#line 6 \"Test/AtCoder/abc266_c.test.cpp\"\n\nint main() {\n    using namespace\
    \ zawa::geometryZ2;\n    Polygon p(4);\n    std::cin >> p;\n    std::cout << (p.isConvex()\
    \ ? \"Yes\\n\" : \"No\\n\");\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_c\"\n\n\
    #include \"../../Src/GeometryZ2/Polygon.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    using namespace zawa::geometryZ2;\n    Polygon p(4);\n    std::cin >>\
    \ p;\n    std::cout << (p.isConvex() ? \"Yes\\n\" : \"No\\n\");\n}\n"
  dependsOn:
  - Src/GeometryZ2/Polygon.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/Relation.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc266_c.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 14:51:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc266_c.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc266_c.test.cpp
- /verify/Test/AtCoder/abc266_c.test.cpp.html
title: Test/AtCoder/abc266_c.test.cpp
---
