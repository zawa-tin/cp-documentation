---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Real.hpp
    title: Src/GeometryR2/Real.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Line.hpp
    title: Src/GeometryR2/Line.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Point.hpp
    title: Src/GeometryR2/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Src/GeometryR2/Projection.hpp
    title: Src/GeometryR2/Projection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/CGL_1_A.test.cpp
    title: Test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc259_b.test.cpp
    title: Test/AtCoder/abc259_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/GeometryR2/Angle.hpp\"\n\n#line 2 \"Src/GeometryR2/Real.hpp\"\
    \n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nusing Real = long double;\n\
    constexpr Real EPS{1e-12};\n\nnamespace internal {\n\nconstexpr int negative{-1};\n\
    constexpr int zero{};\nconstexpr int positive{1};\n\n} // namespace internal\n\
    \nconstexpr int Sign(Real value) {\n    if (value < -EPS) return internal::negative;\n\
    \    if (value > EPS) return internal::positive;\n    return internal::zero;\n\
    }\n\nconstexpr bool IsZero(Real value) {\n    return Sign(value) == internal::zero;\n\
    }\n\nconstexpr bool IsPositive(Real value) {\n    return Sign(value) == internal::positive;\n\
    }\n\nconstexpr bool IsNegative(Real value) {\n    return Sign(value) == internal::negative;\n\
    }\n\nconstexpr bool Equal(Real a, Real b) {\n    return IsZero(a - b);\n}\n\n\
    constexpr bool Smaller(Real a, Real b) {\n    return IsNegative(a - b);\n}\n\n\
    constexpr bool Bigger(Real a, Real b) {\n    return IsPositive(a - b);\n}\n\n\
    } // namespace geometryR2\n \n} // namespace zawa\n#line 4 \"Src/GeometryR2/Angle.hpp\"\
    \n\n#include <cmath>\n\nnamespace zawa {\n\nnamespace geometryR2 {\n\nconstexpr\
    \ Real PI{acosl(-1)};\nconstexpr Real TAU{static_cast<Real>(2) * PI};\n\nconstexpr\
    \ Real ArcToRadian(Real arc) {\n    return (arc * PI) / static_cast<Real>(180);\n\
    }\n\nconstexpr Real RadianToArc(Real radian) {\n    return (radian * static_cast<Real>(180))\
    \ / PI;\n}\n\n} // namespace geometryR2\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./Real.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ zawa {\n\nnamespace geometryR2 {\n\nconstexpr Real PI{acosl(-1)};\nconstexpr\
    \ Real TAU{static_cast<Real>(2) * PI};\n\nconstexpr Real ArcToRadian(Real arc)\
    \ {\n    return (arc * PI) / static_cast<Real>(180);\n}\n\nconstexpr Real RadianToArc(Real\
    \ radian) {\n    return (radian * static_cast<Real>(180)) / PI;\n}\n\n} // namespace\
    \ geometryR2\n\n} // namespace zawa\n"
  dependsOn:
  - Src/GeometryR2/Real.hpp
  isVerificationFile: false
  path: Src/GeometryR2/Angle.hpp
  requiredBy:
  - Src/GeometryR2/Point.hpp
  - Src/GeometryR2/Line.hpp
  - Src/GeometryR2/Projection.hpp
  timestamp: '2023-11-08 17:47:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc259_b.test.cpp
  - Test/AOJ/CGL_1_A.test.cpp
documentation_of: Src/GeometryR2/Angle.hpp
layout: document
redirect_from:
- /library/Src/GeometryR2/Angle.hpp
- /library/Src/GeometryR2/Angle.hpp.html
title: Src/GeometryR2/Angle.hpp
---
