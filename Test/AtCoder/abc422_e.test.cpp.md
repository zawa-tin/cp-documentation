---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/LineContainsPoint.hpp
    title: Src/GeometryZ2/Contain/LineContainsPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/State.hpp
    title: Src/GeometryZ2/Contain/State.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Line.hpp
    title: Src/GeometryZ2/Line.hpp
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
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc422/tasks/abc422_e
    - https://atcoder.jp/contests/jsc2025advance-final/submissions/69185007
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc422_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc422/tasks/abc422_e\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 422 E - Colinear\n * https://atcoder.jp/contests/jsc2025advance-final/submissions/69185007\n\
    \ */\n\n#line 2 \"Src/GeometryZ2/Contain/LineContainsPoint.hpp\"\n\n#line 2 \"\
    Src/GeometryZ2/Contain/State.hpp\"\n\nnamespace zawa {\n\nnamespace geometryZ2\
    \ {\n\nenum ContainState {\n    INSIDE          = 0,\n    ONLINE          = 1,\n\
    \    OUTSIDE         = 2\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n\
    #line 2 \"Src/GeometryZ2/Line.hpp\"\n\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/GeometryZ2/Zahlen.hpp\"\
    \n\n#include <cassert>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nusing\
    \ Zahlen = i64;\n\nnamespace internal {\n\nconstexpr i32 positive{1};\nconstexpr\
    \ i32 zero{0};\nconstexpr i32 negative{-1};\n\n} // namespace internal\n\nconstexpr\
    \ i32 Sign(Zahlen value) {\n    if (value < 0) return internal::negative;\n  \
    \  if (value > 0) return internal::positive;\n    return internal::zero;\n}\n\n\
    constexpr bool Positive(Zahlen value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Zero(Zahlen value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool Negative(Zahlen value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr Zahlen Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n\
    }\n\nconstexpr Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Point.hpp\"\
    \n\n#line 5 \"Src/GeometryZ2/Point.hpp\"\n\n#include <algorithm>\n#include <iostream>\n\
    #line 9 \"Src/GeometryZ2/Point.hpp\"\n#include <limits>\n\nnamespace zawa {\n\n\
    namespace geometryZ2 {\n\nclass Point {\nprivate:\n    Zahlen x_{}, y_{};\n  \
    \  static constexpr i32 origin{0};\n    static constexpr i32 firstQuadrant{1};\n\
    \    static constexpr i32 secondQuadrant{2};\n    static constexpr i32 thirdQuadrant{-2};\n\
    \    static constexpr i32 forthQuadrant{-1};\npublic:\n    /* constructor */\n\
    \    Point() = default;\n    Point(const Point& p) : x_{p.x()}, y_{p.y()} {}\n\
    \    Point(Zahlen x, Zahlen y) : x_{x}, y_{y} {}\n\n    /* getter setter */\n\
    \    Zahlen& x() {\n        return x_;\n    }\n    const Zahlen& x() const {\n\
    \        return x_;\n    }\n    Zahlen& y() {\n        return y_;\n    }\n   \
    \ const Zahlen& y() const {\n        return y_;\n    }\n\n    /* operator */\n\
    \    Point& operator=(const Point& p) {\n        x() = p.x();\n        y() = p.y();\n\
    \        return *this;\n    }\n    Point& operator+=(const Point& p) {\n     \
    \   x() += p.x();\n        y() += p.y();\n        return *this;\n    }\n    friend\
    \ Point operator+(const Point& p0, const Point& p1) {\n        return Point{p0}\
    \ += p1;\n    }\n    Point& operator-=(const Point& p) {\n        x() -= p.x();\n\
    \        y() -= p.y();\n        return *this;\n    }\n    friend Point operator-(const\
    \ Point& p0, const Point& p1) {\n        return Point{p0} -= p1;\n    }\n    Point&\
    \ operator*=(Zahlen k) {\n        x() *= k;\n        y() *= k;\n        return\
    \ *this;\n    }\n    friend Point operator*(const Point& p, Zahlen k) {\n    \
    \    return Point{p} *= k;\n    }\n    friend Point operator*(Zahlen k, const\
    \ Point& p) {\n        return Point{p} *= k;\n    }\n    Point& operator/=(Zahlen\
    \ k) {\n        assert(k);\n        assert(x() % k == 0);\n        assert(y()\
    \ % k == 0);\n        x() /= k;\n        y() /= k;\n        return *this;\n  \
    \  }\n    friend Point operator/(const Point& p, Zahlen k) {\n        return Point{p}\
    \ /= k;\n    }\n    friend bool operator==(const Point& p0, const Point& p1) {\n\
    \        return p0.x() == p1.x() and p0.y() == p1.y();\n    }\n    friend bool\
    \ operator!=(const Point& p0, const Point& p1) {\n        return p0.x() != p1.x()\
    \ or p0.y() != p1.y();\n    }\n    friend bool operator<(const Point& p0, const\
    \ Point& p1) {\n        if (p0.x() != p1.x()) return p0.x() < p1.x();\n      \
    \  else return p0.y() < p1.y();\n    }\n    friend bool operator<=(const Point&\
    \ p0, const Point& p1) {\n        return (p0 < p1) or (p0 == p1);\n    }\n   \
    \ friend bool operator>(const Point& p0, const Point& p1) {\n        if (p0.x()\
    \ != p1.x()) return p0.x() > p1.x();\n        else return p0.y() > p1.y();\n \
    \   }\n    friend bool operator>=(const Point& p0, const Point& p1) {\n      \
    \  return (p0 > p1) or (p0 == p1);\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, Point& p) {\n        is >> p.x() >> p.y();\n        return is;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Point& p) {\n   \
    \     os << '(' << p.x() << ',' << p.y() << ')';\n        return os;\n    }\n\n\
    \    /* member function */\n    Zahlen normSquare() const {\n        return Square(x())\
    \ + Square(y());\n    }\n    bool isNormSquareOver(Zahlen d) const {\n       \
    \ assert(!Negative(d));\n        auto [mn, mx]{std::minmax({ Abs(x()), Abs(y())\
    \ })};\n        if (mx and mx > d / mx) {\n            return true;\n        }\n\
    \        long long s1{Square(mn)}, s2{Square(mx)};\n        if (s1 > d - s2) {\n\
    \            return true;\n        }\n        return false;\n    }\n    bool isNormSquareOverflow()\
    \ const {\n        return isNormSquareOver(std::numeric_limits<Zahlen>::max());\n\
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
    #line 6 \"Src/GeometryZ2/Line.hpp\"\n\n#line 8 \"Src/GeometryZ2/Line.hpp\"\n#include\
    \ <tuple>\n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass Line {\nprivate:\n\
    \    Point p0_{}, p1_{};\n\npublic:\n    /* constructor */\n    Line() = default;\n\
    \    Line(const Point& p0, const Point& p1) : p0_{p0}, p1_{p1} {}\n    // y =\
    \ ax + b\n    Line(const Zahlen& a, const Zahlen& b) : p0_{Zahlen{}, b}, p1_{a,\
    \ a + b} {}\n    Line(const Line& l) : p0_{l.p0()}, p1_{l.p1()} {}\n\n    /* getter,\
    \ setter */\n    const Point& p0() const {\n        return p0_;\n    }\n    Point&\
    \ p0() {\n        return p0_;\n    }\n    const Point& p1() const {\n        return\
    \ p1_;\n    }\n    Point& p1() {\n        return p1_;\n    }\n\n    /* operator\
    \ */\n    friend bool operator==(const Line& l0, const Line& l1) {\n        return\
    \ Zero(Cross(l0.p1() - l0.p0(), l1.p1() - l1.p0())) \n            and Zero(Cross(l1.p0()\
    \ - l0.p0(), l0.p1() - l0.p0()));\n    }\n    friend bool operator!=(const Line&\
    \ l0, const Line& l1) {\n        return !(l0 == l1);\n    }\n    friend bool operator<(const\
    \ Line& l0, const Line& l1) {\n        if (Zero(Cross(l0.p1() - l0.p0(), l1.p1()\
    \ - l1.p0()))) {\n            return Relation(l0.p0(), l0.p1(), l1.p0()) == COUNTER_CLOCKWISE;\n\
    \        }\n        else {\n            return Point::ArgComp(l0.positiveDir(),\
    \ l1.positiveDir());\n        }\n    }\n    friend bool operator<=(const Line&\
    \ l0, const Line& l1) {\n        return (l0 == l1) or (l0 < l1);\n    }\n    friend\
    \ bool operator>(const Line& l0, const Line& l1) {\n        if (Zero(Cross(l0.p1()\
    \ - l0.p0(), l1.p1() - l1.p0()))) {\n            return Relation(l0.p0(), l0.p1(),\
    \ l1.p0()) == CLOCKWISE;\n        }\n        else {\n            return Point::ArgComp(l0.positiveDir(),\
    \ l1.positiveDir());\n        }\n    }\n    friend bool operator>=(const Line&\
    \ l0, const Line& l1) {\n        return (l0 == l1) or (l0 > l1);\n    }\n\n  \
    \  /* member function */\n    bool valid() const {\n        return p0_ != p1_;\n\
    \    }\n    Vector positiveDir() const {\n        Vector res{p1_ - p0_};\n   \
    \     if (Negative(res.x())) {\n            res.x() *= -1;\n            res.y()\
    \ *= -1;\n        }\n        return res;\n    }\n    std::tuple<Zahlen, Zahlen,\
    \ Zahlen> normalForm() const {\n        Zahlen a = p0_.y() - p1_.y();\n      \
    \  Zahlen b = p1_.x() - p0_.x();\n        Zahlen c = -a * p0_.x() - b * p0_.y();\n\
    \        return {a, b, c};\n    }\n};\n\n} // namespace geometryZ2\n\n} // namespace\
    \ zawa\n\n#line 6 \"Src/GeometryZ2/Contain/LineContainsPoint.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace geometryZ2 {\n\nContainState LineContainsPoint(const Line&\
    \ l, const Point& p) {\n    return Cross(p - l.p0(), l.p1() - l.p0()) == 0 ? ONLINE\
    \ : OUTSIDE;\n}\n\n} // namespace geometryZ2\n\n} // namespace zawa\n#line 10\
    \ \"Test/AtCoder/abc422_e.test.cpp\"\nusing namespace zawa::geometryZ2;\nusing\
    \ namespace std;\n\n#line 14 \"Test/AtCoder/abc422_e.test.cpp\"\n#include <random>\n\
    \nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N;\n    cin >> N;\n    vector<Point> P(N);\n    for (auto& p : P)\n \
    \       cin >> p;\n    mt19937 mt{random_device{}()};\n    for (int _ = 0 ; _\
    \ < 100 ; _++) {\n        int p = 0, q = 0;\n        while (p == q) {\n      \
    \      p = mt() % N;\n            q = mt() % N;\n        }\n        Line l{P[p],\
    \ P[q]};\n        int cnt = 0;\n        for (const Point& v : P)\n           \
    \ cnt += LineContainsPoint(l, v) == ONLINE;\n        if (2 * cnt > N) {\n    \
    \        auto [a, b, c] = l.normalForm();\n            cout << \"Yes\\n\" << a\
    \ << ' ' << b << ' ' << c << '\\n';\n            return 0;\n        }\n    }\n\
    \    cout << \"No\\n\";\n#else\n    cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc422/tasks/abc422_e\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 422 E - Colinear\n * https://atcoder.jp/contests/jsc2025advance-final/submissions/69185007\n\
    \ */\n\n#include \"../../Src/GeometryZ2/Contain/LineContainsPoint.hpp\"\nusing\
    \ namespace zawa::geometryZ2;\nusing namespace std;\n\n#include <iostream>\n#include\
    \ <random>\n\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N;\n    cin >> N;\n    vector<Point> P(N);\n\
    \    for (auto& p : P)\n        cin >> p;\n    mt19937 mt{random_device{}()};\n\
    \    for (int _ = 0 ; _ < 100 ; _++) {\n        int p = 0, q = 0;\n        while\
    \ (p == q) {\n            p = mt() % N;\n            q = mt() % N;\n        }\n\
    \        Line l{P[p], P[q]};\n        int cnt = 0;\n        for (const Point&\
    \ v : P)\n            cnt += LineContainsPoint(l, v) == ONLINE;\n        if (2\
    \ * cnt > N) {\n            auto [a, b, c] = l.normalForm();\n            cout\
    \ << \"Yes\\n\" << a << ' ' << b << ' ' << c << '\\n';\n            return 0;\n\
    \        }\n    }\n    cout << \"No\\n\";\n#else\n    cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  dependsOn:
  - Src/GeometryZ2/Contain/LineContainsPoint.hpp
  - Src/GeometryZ2/Contain/State.hpp
  - Src/GeometryZ2/Line.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/Template/TypeAlias.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/GeometryZ2/Relation.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc422_e.test.cpp
  requiredBy: []
  timestamp: '2025-09-09 19:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc422_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc422_e.test.cpp
- /verify/Test/AtCoder/abc422_e.test.cpp.html
title: Test/AtCoder/abc422_e.test.cpp
---
