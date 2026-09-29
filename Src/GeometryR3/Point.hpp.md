---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR3/Plane.hpp
    title: Src/GeometryR3/Plane.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR3/Segment.hpp
    title: Src/GeometryR3/Segment.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR3/Sphere.hpp
    title: Src/GeometryR3/Sphere.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2641.test.cpp
    title: Test/AOJ/2641.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/UC/3-37-M.test.cpp
    title: Test/UC/3-37-M.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://manabitimes.jp/math/2649
  bundledCode: "#line 2 \"Src/GeometryR3/Point.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <cmath>\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n\
    #include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32\
    \ = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing\
    \ u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 11 \"Src/GeometryR3/Point.hpp\"\n\nnamespace zawa {\n\nnamespace geometryR3\
    \ {\n\ntemplate <std::floating_point T>\nclass Point {\npublic:\n\n    Point()\
    \ = default;\n\n    Point(T x, T y, T z) : m_p{x, y, z} {}\n\n    explicit Point(const\
    \ std::array<T, 3>& p) : m_p{p} {}\n\n    explicit Point(std::array<T, 3>&& p)\
    \ : m_p{std::move(p)} {}\n\n    const T& x() const {\n        return m_p[0];\n\
    \    }\n\n    T& x() {\n        return m_p[0];\n    }\n\n    const T& y() const\
    \ {\n        return m_p[1];\n    }\n\n    T& y() {\n        return m_p[1];\n \
    \   }\n\n    const T& z() const {\n        return m_p[2];\n    }\n\n    T& z()\
    \ {\n        return m_p[2];\n    }\n\n    const T& operator[](usize i) const {\n\
    \        assert(i < 3);\n        return m_p[i];\n    }\n\n    T& operator[](usize\
    \ i) {\n        assert(i < 3);\n        return m_p[i];\n    }\n\n    Point<T>&\
    \ operator+=(const Point<T>& p) {\n        m_p[0] += p[0];\n        m_p[1] +=\
    \ p[1];\n        m_p[2] += p[2];\n        return *this;\n    }\n\n    Point<T>&\
    \ operator-=(const Point<T>& p) {\n        m_p[0] -= p[0];\n        m_p[1] -=\
    \ p[1];\n        m_p[2] -= p[2];\n        return *this;\n    }\n\n    Point<T>&\
    \ operator*=(T k) {\n        m_p[0] *= k;\n        m_p[1] *= k;\n        m_p[2]\
    \ *= k;\n        return *this;\n    }\n\n    Point<T>& operator/=(T k) {\n   \
    \     m_p[0] /= k;\n        m_p[1] /= k;\n        m_p[2] /= k;\n        return\
    \ *this;\n    }\n\n    T normSquare() const {\n        return m_p[0]*m_p[0] +\
    \ m_p[1]*m_p[1] + m_p[2]*m_p[2];\n    }\n\n    T norm() const {\n        return\
    \ sqrtl(normSquare());\n    }\n\n    Point<T> normalized() const {\n        return\
    \ Point<T>{*this} /= norm();\n    }\n\n    // \u30ED\u30C9\u30EA\u30B2\u30B9\u306E\
    \u56DE\u8EE2\u516C\u5F0F https://manabitimes.jp/math/2649\n    Point<T> rotated(const\
    \ Point<T>& axis, T theta) const {\n        const T cosT = cosl(theta), sinT =\
    \ sinl(theta);\n        const Point<T> cp{*this};\n        return cosT * cp +\
    \ (1 - cosT) * DotProduct(axis, cp) * axis + sinT * CrossProduct(axis, cp);\n\
    \    }\n\nprivate:\n\n    std::array<T, 3> m_p{T{0}, T{0}, T{0}};\n\n};\n\ntemplate\
    \ <std::floating_point T>\nPoint<T> operator+(const Point<T>& lhs, const Point<T>&\
    \ rhs) {\n    return Point<T>{lhs} += rhs;\n}\n\ntemplate <std::floating_point\
    \ T>\nPoint<T> operator-(const Point<T>& lhs, const Point<T>& rhs) {\n    return\
    \ Point<T>{lhs} -= rhs;\n}\n\ntemplate <std::floating_point T>\nPoint<T> operator*(const\
    \ T k, const Point<T>& p) {\n    return Point<T>{p} *= k;\n}\n\ntemplate <std::floating_point\
    \ T>\nstd::ostream& operator<<(std::ostream& os, const Point<T>& p) {\n    os\
    \ << '(' << p[0] << ',' << p[1] << ',' << p[2] << ')';\n    return os;\n}\n\n\
    template <std::floating_point T>\nstd::istream& operator>>(std::istream& is, Point<T>&\
    \ p) {\n    is >> p[0] >> p[1] >> p[2];\n    return is;\n}\n\ntemplate <std::floating_point\
    \ T>\nT DistanceSquare(const Point<T>& lhs, const Point<T>& rhs) {\n    return\
    \ Point{lhs - rhs}.normSquare();\n}\n\ntemplate <std::floating_point T>\nT Distance(const\
    \ Point<T>& lhs, const Point<T>& rhs) {\n    return sqrtl(DistanceSquare(lhs,\
    \ rhs));\n}\n\ntemplate <std::floating_point T>\nT DotProduct(const Point<T>&\
    \ lhs, const Point<T>& rhs) {\n    return lhs[0]*rhs[0] + lhs[1]*rhs[1] + lhs[2]*rhs[2];\n\
    }\n\ntemplate <std::floating_point T>\nPoint<T> CrossProduct(const Point<T>& lhs,\
    \ const Point<T>& rhs) {\n    return {\n        lhs[1]*rhs[2]-lhs[2]*rhs[1],\n\
    \        lhs[2]*rhs[0]-lhs[0]*rhs[2],\n        lhs[0]*rhs[1]-lhs[1]*rhs[0],\n\
    \    };\n}\n\ntemplate <std::floating_point T>\nusing Vector = Point<T>;\n\n}\
    \ // namespace geometryR3\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <cmath>\n\
    #include <concepts>\n#include <iostream>\n#include <utility>\n\n#include \"../Template/TypeAlias.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR3 {\n\ntemplate <std::floating_point\
    \ T>\nclass Point {\npublic:\n\n    Point() = default;\n\n    Point(T x, T y,\
    \ T z) : m_p{x, y, z} {}\n\n    explicit Point(const std::array<T, 3>& p) : m_p{p}\
    \ {}\n\n    explicit Point(std::array<T, 3>&& p) : m_p{std::move(p)} {}\n\n  \
    \  const T& x() const {\n        return m_p[0];\n    }\n\n    T& x() {\n     \
    \   return m_p[0];\n    }\n\n    const T& y() const {\n        return m_p[1];\n\
    \    }\n\n    T& y() {\n        return m_p[1];\n    }\n\n    const T& z() const\
    \ {\n        return m_p[2];\n    }\n\n    T& z() {\n        return m_p[2];\n \
    \   }\n\n    const T& operator[](usize i) const {\n        assert(i < 3);\n  \
    \      return m_p[i];\n    }\n\n    T& operator[](usize i) {\n        assert(i\
    \ < 3);\n        return m_p[i];\n    }\n\n    Point<T>& operator+=(const Point<T>&\
    \ p) {\n        m_p[0] += p[0];\n        m_p[1] += p[1];\n        m_p[2] += p[2];\n\
    \        return *this;\n    }\n\n    Point<T>& operator-=(const Point<T>& p) {\n\
    \        m_p[0] -= p[0];\n        m_p[1] -= p[1];\n        m_p[2] -= p[2];\n \
    \       return *this;\n    }\n\n    Point<T>& operator*=(T k) {\n        m_p[0]\
    \ *= k;\n        m_p[1] *= k;\n        m_p[2] *= k;\n        return *this;\n \
    \   }\n\n    Point<T>& operator/=(T k) {\n        m_p[0] /= k;\n        m_p[1]\
    \ /= k;\n        m_p[2] /= k;\n        return *this;\n    }\n\n    T normSquare()\
    \ const {\n        return m_p[0]*m_p[0] + m_p[1]*m_p[1] + m_p[2]*m_p[2];\n   \
    \ }\n\n    T norm() const {\n        return sqrtl(normSquare());\n    }\n\n  \
    \  Point<T> normalized() const {\n        return Point<T>{*this} /= norm();\n\
    \    }\n\n    // \u30ED\u30C9\u30EA\u30B2\u30B9\u306E\u56DE\u8EE2\u516C\u5F0F\
    \ https://manabitimes.jp/math/2649\n    Point<T> rotated(const Point<T>& axis,\
    \ T theta) const {\n        const T cosT = cosl(theta), sinT = sinl(theta);\n\
    \        const Point<T> cp{*this};\n        return cosT * cp + (1 - cosT) * DotProduct(axis,\
    \ cp) * axis + sinT * CrossProduct(axis, cp);\n    }\n\nprivate:\n\n    std::array<T,\
    \ 3> m_p{T{0}, T{0}, T{0}};\n\n};\n\ntemplate <std::floating_point T>\nPoint<T>\
    \ operator+(const Point<T>& lhs, const Point<T>& rhs) {\n    return Point<T>{lhs}\
    \ += rhs;\n}\n\ntemplate <std::floating_point T>\nPoint<T> operator-(const Point<T>&\
    \ lhs, const Point<T>& rhs) {\n    return Point<T>{lhs} -= rhs;\n}\n\ntemplate\
    \ <std::floating_point T>\nPoint<T> operator*(const T k, const Point<T>& p) {\n\
    \    return Point<T>{p} *= k;\n}\n\ntemplate <std::floating_point T>\nstd::ostream&\
    \ operator<<(std::ostream& os, const Point<T>& p) {\n    os << '(' << p[0] <<\
    \ ',' << p[1] << ',' << p[2] << ')';\n    return os;\n}\n\ntemplate <std::floating_point\
    \ T>\nstd::istream& operator>>(std::istream& is, Point<T>& p) {\n    is >> p[0]\
    \ >> p[1] >> p[2];\n    return is;\n}\n\ntemplate <std::floating_point T>\nT DistanceSquare(const\
    \ Point<T>& lhs, const Point<T>& rhs) {\n    return Point{lhs - rhs}.normSquare();\n\
    }\n\ntemplate <std::floating_point T>\nT Distance(const Point<T>& lhs, const Point<T>&\
    \ rhs) {\n    return sqrtl(DistanceSquare(lhs, rhs));\n}\n\ntemplate <std::floating_point\
    \ T>\nT DotProduct(const Point<T>& lhs, const Point<T>& rhs) {\n    return lhs[0]*rhs[0]\
    \ + lhs[1]*rhs[1] + lhs[2]*rhs[2];\n}\n\ntemplate <std::floating_point T>\nPoint<T>\
    \ CrossProduct(const Point<T>& lhs, const Point<T>& rhs) {\n    return {\n   \
    \     lhs[1]*rhs[2]-lhs[2]*rhs[1],\n        lhs[2]*rhs[0]-lhs[0]*rhs[2],\n   \
    \     lhs[0]*rhs[1]-lhs[1]*rhs[0],\n    };\n}\n\ntemplate <std::floating_point\
    \ T>\nusing Vector = Point<T>;\n\n} // namespace geometryR3\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/GeometryR3/Point.hpp
  requiredBy:
  - Src/GeometryR3/Segment.hpp
  - Src/GeometryR3/Sphere.hpp
  - Src/GeometryR3/Plane.hpp
  timestamp: '2025-05-21 20:07:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/2641.test.cpp
  - Test/UC/3-37-M.test.cpp
documentation_of: Src/GeometryR3/Point.hpp
layout: document
redirect_from:
- /library/Src/GeometryR3/Point.hpp
- /library/Src/GeometryR3/Point.hpp.html
title: Src/GeometryR3/Point.hpp
---
