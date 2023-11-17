---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Relation.hpp
    title: Src/GeometryZ2/Relation.hpp
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
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C
  bundledCode: "#line 1 \"Test/AOJ/CGL_1_C/GeometryZ2.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C\"\n#define\
    \ ERROR 0.00000001\n\n#line 2 \"Src/GeometryZ2/Point.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#line 4 \"Src/GeometryZ2/Zahlen.hpp\"\
    \n\n#include <cassert>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nusing\
    \ Zahlen = i64;\n\nnamespace internal {\n\nconstexpr i32 positive{1};\nconstexpr\
    \ i32 zero{0};\nconstexpr i32 negative{-1};\n\n} // namespace internal\n\nconstexpr\
    \ i32 Sign(Zahlen value) {\n    if (value < 0) return internal::negative;\n  \
    \  if (value > 0) return internal::positive;\n    return internal::zero;\n}\n\n\
    constexpr bool Positive(Zahlen value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Zero(Zahlen value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool Negative(Zahlen value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr Zahlen Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n\
    }\n\n} // namespace geometryZ2\n\n} // namespace zawa\n#line 5 \"Src/GeometryZ2/Point.hpp\"\
    \n\n#include <iostream>\n#line 8 \"Src/GeometryZ2/Point.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace geometryZ2 {\n\nclass Point {\nprivate:\n    Zahlen x_{}, y_{};\n\
    \    static constexpr u32 origin{0};\n    static constexpr u32 firstQuadrant{1};\n\
    \    static constexpr u32 secondQuadrant{1};\n    static constexpr u32 thirdQuadrant{1};\n\
    \    static constexpr u32 forthQuadrant{1};\n\n    u32 area() const {\n      \
    \  if (x_ == 0 and y_ == 0) return origin;\n        if (x_ > 0 and y_ >= 0) return\
    \ firstQuadrant;\n        if (x_ <= 0 and y_ > 0) return secondQuadrant;\n   \
    \     if (x_ < 0 and y_ <= 0) return thirdQuadrant;\n        return forthQuadrant;\n\
    \    }\npublic:\n    /* constructor */\n    Point() = default;\n    Point(const\
    \ Point& p) : x_{p.x()}, y_{p.y()} {}\n    Point(Zahlen x, Zahlen y) : x_{x},\
    \ y_{y} {}\n\n    /* getter setter */\n    Zahlen& x() {\n        return x_;\n\
    \    }\n    const Zahlen& x() const {\n        return x_;\n    }\n    Zahlen&\
    \ y() {\n        return y_;\n    }\n    const Zahlen& y() const {\n        return\
    \ y_;\n    }\n\n    /* operator */\n    Point& operator=(const Point& p) {\n \
    \       x() = p.x();\n        y() = p.y();\n        return *this;\n    }\n   \
    \ Point& operator+=(const Point& p) {\n        x() += p.x();\n        y() += p.y();\n\
    \        return *this;\n    }\n    friend Point operator+(const Point& p0, const\
    \ Point& p1) {\n        return Point{p0} += p1;\n    }\n    Point& operator-=(const\
    \ Point& p) {\n        x() -= p.x();\n        y() -= p.y();\n        return *this;\n\
    \    }\n    friend Point operator-(const Point& p0, const Point& p1) {\n     \
    \   return Point{p0} -= p1;\n    }\n    Point& operator*=(Zahlen k) {\n      \
    \  x() *= k;\n        y() *= k;\n        return *this;\n    }\n    friend Point\
    \ operator*(const Point& p, Zahlen k) {\n        return Point{p} *= k;\n    }\n\
    \    friend Point operator*(Zahlen k, const Point& p) {\n        return Point{p}\
    \ *= k;\n    }\n    Point& operator/=(Zahlen k) {\n        assert(k);\n      \
    \  assert(x() % k == 0);\n        assert(y() % k == 0);\n        x() /= k;\n \
    \       y() /= k;\n        return *this;\n    }\n    friend Point operator/(const\
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
    \    Zahlen normSquare() const {\n        return x() * x() + y() * y();\n    }\n\
    \n    /* friend function */\n    friend Zahlen Dot(const Point& p0, const Point&\
    \ p1) {\n        return p0.x() * p1.x() + p0.y() * p1.y();\n    }\n    friend\
    \ Zahlen Cross(const Point& p0, const Point& p1) {\n        return p0.x() * p1.y()\
    \ - p0.y() * p1.x();\n    }\n    friend bool ArgComp(const Point& p0, const Point&\
    \ p1) {\n        if (p0.area() != p1.area()) return p0.area() < p1.area();\n \
    \       Zahlen cross{Cross(p0, p1)};\n        return (!Zero(cross) ? Positive(cross)\
    \ : p0.normSquare() < p1.normSquare());\n    }\n};\nusing Vector = Point;\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Relation.hpp\"\
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
    #line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 6 \"Src/Template/IOSetting.hpp\"\n#include <iomanip>\n\nnamespace zawa\
    \ {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 7 \"Test/AOJ/CGL_1_C/GeometryZ2.test.cpp\"\n\n\
    #line 9 \"Test/AOJ/CGL_1_C/GeometryZ2.test.cpp\"\n\nint main() {\n    using namespace\
    \ zawa;\n    using namespace geometryZ2;\n\n    SetFastIO();\n    Point p0, p1;\
    \ std::cin >> p0 >> p1;\n    int q; std::cin >> q;\n    for (int _{} ; _ < q ;\
    \ _++) {\n        Point p2; std::cin >> p2;\n        auto ans{Relation(p0, p1,\
    \ p2)};\n        if (ans == COUNTER_CLOCKWISE) std::cout << \"COUNTER_CLOCKWISE\\\
    n\";\n        else if (ans == CLOCKWISE) std::cout << \"CLOCKWISE\\n\";\n    \
    \    else if (ans == ONLINE_BACK) std::cout << \"ONLINE_BACK\\n\";\n        else\
    \ if (ans == ONLINE_FRONT) std::cout << \"ONLINE_FRONT\\n\";\n        else std::cout\
    \ << \"ON_SEGMENT\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C\"\
    \n#define ERROR 0.00000001\n\n#include \"../../../Src/GeometryZ2/Point.hpp\"\n\
    #include \"../../../Src/GeometryZ2/Relation.hpp\"\n#include \"../../../Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    using namespace zawa;\n    using\
    \ namespace geometryZ2;\n\n    SetFastIO();\n    Point p0, p1; std::cin >> p0\
    \ >> p1;\n    int q; std::cin >> q;\n    for (int _{} ; _ < q ; _++) {\n     \
    \   Point p2; std::cin >> p2;\n        auto ans{Relation(p0, p1, p2)};\n     \
    \   if (ans == COUNTER_CLOCKWISE) std::cout << \"COUNTER_CLOCKWISE\\n\";\n   \
    \     else if (ans == CLOCKWISE) std::cout << \"CLOCKWISE\\n\";\n        else\
    \ if (ans == ONLINE_BACK) std::cout << \"ONLINE_BACK\\n\";\n        else if (ans\
    \ == ONLINE_FRONT) std::cout << \"ONLINE_FRONT\\n\";\n        else std::cout <<\
    \ \"ON_SEGMENT\\n\";\n    }\n}\n"
  dependsOn:
  - Src/GeometryZ2/Point.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/Relation.hpp
  - Src/Template/IOSetting.hpp
  isVerificationFile: true
  path: Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
  requiredBy: []
  timestamp: '2023-11-17 15:09:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
layout: document
redirect_from:
- /verify/Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
- /verify/Test/AOJ/CGL_1_C/GeometryZ2.test.cpp.html
title: Test/AOJ/CGL_1_C/GeometryZ2.test.cpp
---
