---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/PointCloud.hpp
    title: Src/GeometryZ2/PointCloud.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Zahlen.hpp
    title: Src/GeometryZ2/Zahlen.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc225/tasks/abc225_e
    links:
    - https://atcoder.jp/contests/abc225/tasks/abc225_e
  bundledCode: "#line 1 \"Test/AtCoder/abc225_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc225/tasks/abc225_e\"\
    \n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Point.hpp\"\n\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\
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
    #line 8 \"Src/GeometryZ2/Point.hpp\"\n\nnamespace zawa {\n\nnamespace geometryZ2\
    \ {\n\nclass Point {\nprivate:\n    Zahlen x_{}, y_{};\n    static constexpr i32\
    \ origin{0};\n    static constexpr i32 firstQuadrant{1};\n    static constexpr\
    \ i32 secondQuadrant{2};\n    static constexpr i32 thirdQuadrant{-2};\n    static\
    \ constexpr i32 forthQuadrant{-1};\npublic:\n    /* constructor */\n    Point()\
    \ = default;\n    Point(const Point& p) : x_{p.x()}, y_{p.y()} {}\n    Point(Zahlen\
    \ x, Zahlen y) : x_{x}, y_{y} {}\n\n    /* getter setter */\n    Zahlen& x() {\n\
    \        return x_;\n    }\n    const Zahlen& x() const {\n        return x_;\n\
    \    }\n    Zahlen& y() {\n        return y_;\n    }\n    const Zahlen& y() const\
    \ {\n        return y_;\n    }\n\n    /* operator */\n    Point& operator=(const\
    \ Point& p) {\n        x() = p.x();\n        y() = p.y();\n        return *this;\n\
    \    }\n    Point& operator+=(const Point& p) {\n        x() += p.x();\n     \
    \   y() += p.y();\n        return *this;\n    }\n    friend Point operator+(const\
    \ Point& p0, const Point& p1) {\n        return Point{p0} += p1;\n    }\n    Point&\
    \ operator-=(const Point& p) {\n        x() -= p.x();\n        y() -= p.y();\n\
    \        return *this;\n    }\n    friend Point operator-(const Point& p0, const\
    \ Point& p1) {\n        return Point{p0} -= p1;\n    }\n    Point& operator*=(Zahlen\
    \ k) {\n        x() *= k;\n        y() *= k;\n        return *this;\n    }\n \
    \   friend Point operator*(const Point& p, Zahlen k) {\n        return Point{p}\
    \ *= k;\n    }\n    friend Point operator*(Zahlen k, const Point& p) {\n     \
    \   return Point{p} *= k;\n    }\n    Point& operator/=(Zahlen k) {\n        assert(k);\n\
    \        assert(x() % k == 0);\n        assert(y() % k == 0);\n        x() /=\
    \ k;\n        y() /= k;\n        return *this;\n    }\n    friend Point operator/(const\
    \ Point& p, Zahlen k) {\n        return Point{p} /= k;\n    }\n    friend bool\
    \ operator==(const Point& p0, const Point& p1) {\n        return p0.x() == p1.x()\
    \ and p0.y() == p1.y();\n    }\n    friend bool operator!=(const Point& p0, const\
    \ Point& p1) {\n        return p0.x() != p1.x() or p0.y() != p1.y();\n    }\n\
    \    friend bool operator<(const Point& p0, const Point& p1) {\n        if (p0.x()\
    \ != p1.x()) return p0.x() < p1.x();\n        else return p0.y() < p1.y();\n \
    \   }\n    friend bool operator<=(const Point& p0, const Point& p1) {\n      \
    \  return (p0 < p1) or (p0 == p1);\n    }\n    friend bool operator>(const Point&\
    \ p0, const Point& p1) {\n        if (p0.x() != p1.x()) return p0.x() > p1.x();\n\
    \        else return p0.y() > p1.y();\n    }\n    friend bool operator>=(const\
    \ Point& p0, const Point& p1) {\n        return (p0 > p1) or (p0 == p1);\n   \
    \ }\n    friend std::istream& operator>>(std::istream& is, Point& p) {\n     \
    \   is >> p.x() >> p.y();\n        return is;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Point& p) {\n        os << '(' << p.x() <<\
    \ ',' << p.y() << ')';\n        return os;\n    }\n\n    /* member function */\n\
    \    Zahlen normSquare() const {\n        return Square(x()) + Square(y());\n\
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
    \ geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/PointCloud.hpp\"\
    \n\n#line 4 \"Src/GeometryZ2/PointCloud.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nusing PointCloud =\
    \ std::vector<Point>;\n\nvoid ArgSort(PointCloud& p) {\n    std::sort(p.begin(),\
    \ p.end(), Point::ArgComp);\n}\n\n} // namespace geometryZ2 \n\n} // namespace\
    \ zawa\n#line 6 \"Test/AtCoder/abc225_e.test.cpp\"\n\nint main() {\n    using\
    \ namespace zawa;\n    using namespace geometryZ2;\n    SetFastIO();\n    int\
    \ n; std::cin >> n;\n    PointCloud p(n);\n    for (auto& v : p) std::cin >> v;\n\
    \    for (auto& v : p) v.x()--;\n    ArgSort(p);\n    int ans{1};\n    Point now{p[0]};\n\
    \    for (int i{1} ; i < n ; i++) {\n        Point tar{p[i] + Point{1, -1}};\n\
    \        if (Cross(now, tar) >= 0) {\n            ans++;\n            now = p[i];\n\
    \        }\n    }\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc225/tasks/abc225_e\"\n\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/GeometryZ2/Point.hpp\"\
    \n#include \"../../Src/GeometryZ2/PointCloud.hpp\"\n\nint main() {\n    using\
    \ namespace zawa;\n    using namespace geometryZ2;\n    SetFastIO();\n    int\
    \ n; std::cin >> n;\n    PointCloud p(n);\n    for (auto& v : p) std::cin >> v;\n\
    \    for (auto& v : p) v.x()--;\n    ArgSort(p);\n    int ans{1};\n    Point now{p[0]};\n\
    \    for (int i{1} ; i < n ; i++) {\n        Point tar{p[i] + Point{1, -1}};\n\
    \        if (Cross(now, tar) >= 0) {\n            ans++;\n            now = p[i];\n\
    \        }\n    }\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/PointCloud.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc225_e.test.cpp
  requiredBy: []
  timestamp: '2023-12-02 16:32:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc225_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc225_e.test.cpp
- /verify/Test/AtCoder/abc225_e.test.cpp.html
title: Test/AtCoder/abc225_e.test.cpp
---
