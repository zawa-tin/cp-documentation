---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Angle.hpp
    title: Src/GeometryR2/Angle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Circle.hpp
    title: Src/GeometryR2/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Line.hpp
    title: Src/GeometryR2/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Projection.hpp
    title: Src/GeometryR2/Projection.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Reflection.hpp
    title: Src/GeometryR2/Reflection.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Relation.hpp
    title: Src/GeometryR2/Relation.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Segment.hpp
    title: Src/GeometryR2/Segment.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_A.test.cpp
    title: Test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_B.test.cpp
    title: Test/AOJ/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_C.test.cpp
    title: Test/AOJ/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_2_A.test.cpp
    title: Test/AOJ/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_2_B.test.cpp
    title: Test/AOJ/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_2_D.test.cpp
    title: Test/AOJ/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_7_A.test.cpp
    title: Test/AOJ/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_7_E.test.cpp
    title: Test/AOJ/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc259_b.test.cpp
    title: Test/AtCoder/abc259_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryR2/Real.hpp\"\n\n#include <cmath>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing Real = long\
    \ double;\nconstexpr Real EPS{1e-12};\n\nnamespace internal {\n\nconstexpr int\
    \ negative{-1};\nconstexpr int zero{};\nconstexpr int positive{1};\n\n} // namespace\
    \ internal\n\nconstexpr int Sign(Real value) {\n    if (value < -EPS) return internal::negative;\n\
    \    if (value > EPS) return internal::positive;\n    return internal::zero;\n\
    }\n\nconstexpr bool Zero(Real value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool Positive(Real value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Negative(Real value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr bool Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nconstexpr\
    \ bool Smaller(Real a, Real b) {\n    return Negative(a - b);\n}\n\nconstexpr\
    \ bool Bigger(Real a, Real b) {\n    return Positive(a - b);\n}\n\nconstexpr Real\
    \ Square(Real value) {\n    return value * value;\n}\n\nconstexpr Real Sqrt(Real\
    \ value) {\n    assert(!Negative(value));\n    return (Zero(value) ? value : sqrtl(value));\n\
    }\n\nconstexpr Real Abs(Real value) {\n    return (Negative(value) ? -value :\
    \ value);\n}\n\n} // namespace geometryR2\n \n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cmath>\n#include <cassert>\n\nnamespace zawa {\n\
    \nnamespace geometryR2 {\n\nusing Real = long double;\nconstexpr Real EPS{1e-12};\n\
    \nnamespace internal {\n\nconstexpr int negative{-1};\nconstexpr int zero{};\n\
    constexpr int positive{1};\n\n} // namespace internal\n\nconstexpr int Sign(Real\
    \ value) {\n    if (value < -EPS) return internal::negative;\n    if (value >\
    \ EPS) return internal::positive;\n    return internal::zero;\n}\n\nconstexpr\
    \ bool Zero(Real value) {\n    return Sign(value) == internal::zero;\n}\n\nconstexpr\
    \ bool Positive(Real value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool Negative(Real value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr bool Equal(Real a, Real b) {\n    return Zero(a - b);\n}\n\nconstexpr\
    \ bool Smaller(Real a, Real b) {\n    return Negative(a - b);\n}\n\nconstexpr\
    \ bool Bigger(Real a, Real b) {\n    return Positive(a - b);\n}\n\nconstexpr Real\
    \ Square(Real value) {\n    return value * value;\n}\n\nconstexpr Real Sqrt(Real\
    \ value) {\n    assert(!Negative(value));\n    return (Zero(value) ? value : sqrtl(value));\n\
    }\n\nconstexpr Real Abs(Real value) {\n    return (Negative(value) ? -value :\
    \ value);\n}\n\n} // namespace geometryR2\n \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/GeometryR2/Real.hpp
  requiredBy:
  - Src/GeometryR2/Angle.hpp
  - Src/GeometryR2/Relation.hpp
  - Src/GeometryR2/Segment.hpp
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Reflection.hpp
  - Src/GeometryR2/Line.hpp
  - Src/GeometryR2/Circle.hpp
  - Src/GeometryR2/Projection.hpp
  timestamp: '2023-11-09 10:05:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc259_b.test.cpp
  - Test/AOJ/CGL_2_A.test.cpp
  - Test/AOJ/CGL_7_E.test.cpp
  - Test/AOJ/CGL_2_B.test.cpp
  - Test/AOJ/CGL_7_A.test.cpp
  - Test/AOJ/CGL_1_B.test.cpp
  - Test/AOJ/CGL_1_C.test.cpp
  - Test/AOJ/CGL_1_A.test.cpp
  - Test/AOJ/CGL_2_D.test.cpp
documentation_of: Src/GeometryR2/Real.hpp
layout: document
redirect_from:
- /library/Src/GeometryR2/Real.hpp
- /library/Src/GeometryR2/Real.hpp.html
title: Src/GeometryR2/Real.hpp
---
