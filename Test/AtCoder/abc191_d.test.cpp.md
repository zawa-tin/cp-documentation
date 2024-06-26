---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Circle.hpp
    title: Src/GeometryZ2/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/CircleContainsPoint.hpp
    title: Src/GeometryZ2/Contain/CircleContainsPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Contain/State.hpp
    title: Src/GeometryZ2/Contain/State.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Distance/PointAndPoint.hpp
    title: Src/GeometryZ2/Distance/PointAndPoint.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Point.hpp
    title: Src/GeometryZ2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryZ2/Zahlen.hpp
    title: Src/GeometryZ2/Zahlen.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Number/IntegerDivision.hpp
    title: "\u6574\u6570\u540C\u58EB\u306E\u5207\u308A\u6368\u3066/\u5207\u308A\u4E0A\
      \u3052\u9664\u7B97"
  - icon: ':heavy_check_mark:'
    path: Src/Template/FloatingNumberAlias.hpp
    title: "\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\u306E\u30A8\u30A4\u30EA\u30A2\
      \u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/BinarySearch.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
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
    PROBLEM: https://atcoder.jp/contests/abc191/tasks/abc191_d
    links:
    - https://atcoder.jp/contests/abc191/tasks/abc191_d
  bundledCode: "#line 1 \"Test/AtCoder/abc191_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc191/tasks/abc191_d\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/FloatingNumberAlias.hpp\"\
    \n\nnamespace zawa {\n\nusing ld = long double;\n\n} // namespace zawa\n#line\
    \ 2 \"Src/Number/IntegerDivision.hpp\"\n\n#include <type_traits>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nconstexpr T DivFloor(T a, T b) {\n \
    \   static_assert(std::is_integral_v<T>, \"DivFloor argument must be Integer\"\
    );\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>) {\n      \
    \  return a / b;\n    }\n    else {\n        if (b < 0) {\n            a *= -1;\n\
    \            b *= -1;\n        }\n        return (a >= 0 ? a / b : (a - b + 1)\
    \ / b);\n    }\n}\n\ntemplate <class T>\nconstexpr T DivCeil(T a, T b) {\n   \
    \ static_assert(std::is_integral_v<T>, \"DivCeil argument must be Integer\");\n\
    \    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>) {\n        return\
    \ (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n            a *=\
    \ -1;\n            b *= -1;\n        }\n        return (a >= 0 ? (a + b - 1) /\
    \ b : a / b);\n    }\n}\n\n} // namespace zawa\n#line 2 \"Src/Utility/FloatingMarkerShift.hpp\"\
    \n\n#line 4 \"Src/Utility/FloatingMarkerShift.hpp\"\n\n#include <string>\n#line\
    \ 7 \"Src/Utility/FloatingMarkerShift.hpp\"\n#include <limits>\n\nnamespace zawa\
    \ {\n\ni64 FloatingMarkerShift(const std::string& S, u32 shift) {\n    static\
    \ i64 lim10{std::numeric_limits<i64>::max() / 10};\n    assert(not S.empty());\n\
    \    i64 res{};\n    u32 moved{};\n    bool start{};\n    bool minus{S[0] == '-'};\n\
    \    for (u32 i{(u32)minus} ; i < S.size() ; i++) {\n        if (S[i] == '.')\
    \ {\n            start = true;\n        }\n        else {\n            if (start)\
    \ moved++;\n            assert(res < lim10);\n            res = res * 10;\n  \
    \          assert(res < std::numeric_limits<i64>::max() - (S[i] - '0'));\n   \
    \         res += S[i] - '0';\n        }\n    }\n    assert(moved <= shift);\n\
    \    while (moved < shift) {\n        moved++;\n        assert(res < lim10);\n\
    \        res = res * 10;\n    }\n    if (minus) res *= -1;\n    return res;\n\
    }\n\n}// namespace zawa\n#line 2 \"Src/Utility/BinarySearch.hpp\"\n\n#line 4 \"\
    Src/Utility/BinarySearch.hpp\"\n\n#include <cmath>\n#include <functional>\n#line\
    \ 8 \"Src/Utility/BinarySearch.hpp\"\n#include <utility>\n\nnamespace zawa {\n\
    \nnamespace internal {\n\ntemplate <class T>\nT MidPoint(T a, T b) {\n    if (a\
    \ > b) std::swap(a, b);\n    return a + ((b - a) >> 1);\n}\n\ntemplate <class\
    \ T>\nT Abs(T a, T b) {\n    return (a >= b ? a - b : b - a);\n}\n\n} // namespace\
    \ zawa::internal\n\ntemplate <class T, class Function>\nT BinarySearch(T ok, T\
    \ ng, const Function& f) {\n    static_assert(std::is_integral_v<T>, \"T must\
    \ be integral type\");\n    static_assert(std::is_convertible_v<Function, std::function<bool(T)>>,\
    \ \"f must be function bool(T)\");\n    while (internal::Abs(ok, ng) > 1) {\n\
    \        T mid{ internal::MidPoint(ok, ng) };\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}\n\ntemplate <class T, class Function>\nT BinarySearch(T\
    \ ok, T ng, const Function& f, u32 upperLimit) {\n    static_assert(std::is_signed_v<T>,\
    \ \"T must be signed arithmetic type\");\n    static_assert(std::is_convertible_v<Function,\
    \ std::function<bool(T)>>, \"f must be function bool(T)\");\n    for (u32 _{}\
    \ ; _ < upperLimit ; _++) {\n        T mid{ (ok + ng) / (T)2 };\n        (f(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ok;\n}\n\n} // namespace zawa\n#line 2\
    \ \"Src/GeometryZ2/Circle.hpp\"\n\n#line 2 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#line\
    \ 4 \"Src/GeometryZ2/Zahlen.hpp\"\n\n#line 6 \"Src/GeometryZ2/Zahlen.hpp\"\n\n\
    namespace zawa {\n\nnamespace geometryZ2 {\n\nusing Zahlen = i64;\n\nnamespace\
    \ internal {\n\nconstexpr i32 positive{1};\nconstexpr i32 zero{0};\nconstexpr\
    \ i32 negative{-1};\n\n} // namespace internal\n\nconstexpr i32 Sign(Zahlen value)\
    \ {\n    if (value < 0) return internal::negative;\n    if (value > 0) return\
    \ internal::positive;\n    return internal::zero;\n}\n\nconstexpr bool Positive(Zahlen\
    \ value) {\n    return Sign(value) == internal::positive;\n}\n\nconstexpr bool\
    \ Zero(Zahlen value) {\n    return Sign(value) == internal::zero;\n}\n\nconstexpr\
    \ bool Negative(Zahlen value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr Zahlen Abs(Zahlen value) {\n    return (value > 0 ? value : -value);\n\
    }\n\nconstexpr Zahlen Square(Zahlen value) {\n    return value * value;\n}\n\n\
    } // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Point.hpp\"\
    \n\n#line 5 \"Src/GeometryZ2/Point.hpp\"\n\n#include <algorithm>\n#include <iostream>\n\
    #line 10 \"Src/GeometryZ2/Point.hpp\"\n\nnamespace zawa {\n\nnamespace geometryZ2\
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
    \    }\n    bool isNormSquareOver(Zahlen d) const {\n        assert(!Negative(d));\n\
    \        auto [mn, mx]{std::minmax({ Abs(x()), Abs(y()) })};\n        if (mx and\
    \ mx > d / mx) {\n            return true;\n        }\n        long long s1{Square(mn)},\
    \ s2{Square(mx)};\n        if (s1 > d - s2) {\n            return true;\n    \
    \    }\n        return false;\n    }\n    bool isNormSquareOverflow() const {\n\
    \        return isNormSquareOver(std::numeric_limits<Zahlen>::max());\n    }\n\
    \n    i32 area() const {\n        if (x_ == 0 and y_ == 0) return origin;\n  \
    \      if (x_ <= 0 and y_ < 0) return thirdQuadrant;\n        if (x_ > 0 and y_\
    \ <= 0) return forthQuadrant;\n        if (x_ >= 0 and y_ > 0) return firstQuadrant;\n\
    \        return secondQuadrant;\n    }\n\n    /* static member */\n    static\
    \ bool ArgComp(const Point& p0, const Point& p1) {\n        if (p0.area() != p1.area())\
    \ return p0.area() < p1.area();\n        Zahlen cross{Cross(p0, p1)};\n      \
    \  return (!Zero(cross) ? Positive(cross) : p0.normSquare() < p1.normSquare());\n\
    \    }\n\n    /* friend function */\n    friend Zahlen Dot(const Point& p0, const\
    \ Point& p1) {\n        return p0.x() * p1.x() + p0.y() * p1.y();\n    }\n   \
    \ friend Zahlen Cross(const Point& p0, const Point& p1) {\n        return p0.x()\
    \ * p1.y() - p0.y() * p1.x();\n    }\n};\nusing Vector = Point;\n\n} // namespace\
    \ geometryZ2\n\n} // namespace zawa\n#line 2 \"Src/GeometryZ2/Distance/PointAndPoint.hpp\"\
    \n\n#line 5 \"Src/GeometryZ2/Distance/PointAndPoint.hpp\"\n\nnamespace zawa {\n\
    \nnamespace geometryZ2 {\n\nZahlen DistanceSquare(const Point& p0, const Point&\
    \ p1) {\n    return Vector{p1 - p0}.normSquare();\n}\n\n} // namespace geometryZ2\n\
    \n} // namespace zawa\n#line 7 \"Src/GeometryZ2/Circle.hpp\"\n\n#line 9 \"Src/GeometryZ2/Circle.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nclass Circle {\nprivate:\n \
    \   Point center_{};\n    Zahlen radius_{};\npublic:\n    /* constructor */\n\
    \    Circle() = default;\n    Circle(const Point& center, const Zahlen radius)\
    \ : center_{center}, radius_{radius} {\n        assert(!Negative(radius_));\n\
    \    }\n\n    /* getter, setter */\n    Point& center() {\n        return center_;\n\
    \    }\n    const Point& center() const {\n        return center_;\n    }\n  \
    \  Zahlen& radius() {\n        return radius_;\n    }\n    const Zahlen& radius()\
    \ const {\n        return radius_;\n    }\n\n    /* operator */\n    Circle& operator=(const\
    \ Circle& c) {\n        radius_ = c.radius();\n        center_ = c.center();\n\
    \        return *this;\n    }\n    friend bool operator==(const Circle& c0, const\
    \ Circle& c1) {\n        return c0.radius() == c1.radius() and c0.center() ==\
    \ c1.center();\n    }\n    friend bool operator!=(const Circle& c0, const Circle&\
    \ c1) {\n        return c0.radius() != c1.radius() or c0.center() != c1.center();\n\
    \    }\n\n    /* member */\n    \n    Zahlen radiusSquare() const {\n        return\
    \ Square(radius_);\n    }\n\n    /* friend function */\n    friend u32 NumberCommonTangent(const\
    \ Circle& c0, const Circle& c1) {\n        Zahlen dist{DistanceSquare(c0.center(),\
    \ c1.center())};\n        Zahlen down{Square(Abs(c0.radius() - c1.radius()))};\n\
    \        if (dist < down) {\n            return 0;\n        }\n        if (dist\
    \ == down) {\n            return 1;\n        }\n        Zahlen up{Square(c0.radius()\
    \ + c1.radius())}; \n        if (dist < up) {\n            return 2;\n       \
    \ }\n        if (dist == up) {\n            return 3;\n        }\n        return\
    \ 4;\n    }\n};\n\n} // namespace geometryZ2\n\n} // namespace zawa\n#line 2 \"\
    Src/GeometryZ2/Contain/CircleContainsPoint.hpp\"\n\n#line 2 \"Src/GeometryZ2/Contain/State.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nenum ContainState {\n    INSIDE\
    \          = 0,\n    ONLINE          = 1,\n    OUTSIDE         = 2\n};\n\n} //\
    \ namespace geometryZ2\n\n} // namespace zawa\n#line 6 \"Src/GeometryZ2/Contain/CircleContainsPoint.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryZ2 {\n\nContainState CircleContainsPoint(const\
    \ Circle& c, const Point& p) {\n    Zahlen dist{DistanceSquare(c.center(), p)};\n\
    \    if (dist < c.radiusSquare()) {\n        return INSIDE;\n    }\n    else if\
    \ (dist == c.radiusSquare()) {\n        return ONLINE;\n    }\n    else {\n  \
    \      return OUTSIDE;\n    }\n}\n\n} // namespace geometryZ2\n\n} // namespace\
    \ zawa\n#line 10 \"Test/AtCoder/abc191_d.test.cpp\"\n\n#line 13 \"Test/AtCoder/abc191_d.test.cpp\"\
    \n\nusing namespace zawa;\nusing namespace geometryZ2;\n\ni64 parse() {\n    std::string\
    \ s; std::cin >> s;\n    return FloatingMarkerShift(s, 4);\n}\n\nconstexpr i64\
    \ mul{10000}, range{200100};\n\nint main() {\n    i64 X{parse()}, Y{parse()},\
    \ R{parse()}; \n    Circle c{Point{X, Y}, R};\n    u64 ans{};\n    \n    auto\
    \ contain{[&](Zahlen x, Zahlen y) -> bool {\n        return CircleContainsPoint(c,\
    \ Point{x, y}) != OUTSIDE;\n    }};\n\n    for (i64 x{-range * mul} ; x <= range\
    \ * mul ; x += mul) {\n        if (!contain(x, Y)) continue;\n        i64 u{BinarySearch(Y,\
    \ Y + R + 1, [&](i64 p) -> bool { return contain(x, p); })};\n        u = DivFloor(u,\
    \ mul);\n        i64 d{BinarySearch(Y, Y - R - 1, [&](i64 p) -> bool { return\
    \ contain(x, p); })};\n        d = DivCeil(d, mul);\n        ans += (u - d + 1);\n\
    \    }\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc191/tasks/abc191_d\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/FloatingNumberAlias.hpp\"\
    \n#include \"../../Src/Number/IntegerDivision.hpp\"\n#include \"../../Src/Utility/FloatingMarkerShift.hpp\"\
    \n#include \"../../Src/Utility/BinarySearch.hpp\"\n#include \"../../Src/GeometryZ2/Circle.hpp\"\
    \n#include \"../../Src/GeometryZ2/Contain/CircleContainsPoint.hpp\"\n\n#include\
    \ <iostream>\n#include <cmath>\n\nusing namespace zawa;\nusing namespace geometryZ2;\n\
    \ni64 parse() {\n    std::string s; std::cin >> s;\n    return FloatingMarkerShift(s,\
    \ 4);\n}\n\nconstexpr i64 mul{10000}, range{200100};\n\nint main() {\n    i64\
    \ X{parse()}, Y{parse()}, R{parse()}; \n    Circle c{Point{X, Y}, R};\n    u64\
    \ ans{};\n    \n    auto contain{[&](Zahlen x, Zahlen y) -> bool {\n        return\
    \ CircleContainsPoint(c, Point{x, y}) != OUTSIDE;\n    }};\n\n    for (i64 x{-range\
    \ * mul} ; x <= range * mul ; x += mul) {\n        if (!contain(x, Y)) continue;\n\
    \        i64 u{BinarySearch(Y, Y + R + 1, [&](i64 p) -> bool { return contain(x,\
    \ p); })};\n        u = DivFloor(u, mul);\n        i64 d{BinarySearch(Y, Y - R\
    \ - 1, [&](i64 p) -> bool { return contain(x, p); })};\n        d = DivCeil(d,\
    \ mul);\n        ans += (u - d + 1);\n    }\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/FloatingNumberAlias.hpp
  - Src/Number/IntegerDivision.hpp
  - Src/Utility/FloatingMarkerShift.hpp
  - Src/Utility/BinarySearch.hpp
  - Src/GeometryZ2/Circle.hpp
  - Src/GeometryZ2/Zahlen.hpp
  - Src/GeometryZ2/Point.hpp
  - Src/GeometryZ2/Distance/PointAndPoint.hpp
  - Src/GeometryZ2/Contain/CircleContainsPoint.hpp
  - Src/GeometryZ2/Contain/State.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc191_d.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 14:51:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc191_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc191_d.test.cpp
- /verify/Test/AtCoder/abc191_d.test.cpp.html
title: Test/AtCoder/abc191_d.test.cpp
---
