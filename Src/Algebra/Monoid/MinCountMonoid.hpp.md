---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Utility/AreaOfUnionOfRectangles.hpp
    title: Src/Utility/AreaOfUnionOfRectangles.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc346_g.test.cpp
    title: Test/AtCoder/abc346_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/area_of_union_of_rectangles.test.cpp
    title: Test/LC/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MinCountMonoid.hpp\"\n\n#include <limits>\n\
    #include <utility>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nstruct\
    \ MinCountMonoid {\n    // min, count\u306E\u9806\n    using Element = std::pair<T,\
    \ U>;\n\n    static Element identity() noexcept {\n        return { std::numeric_limits<T>::max(),\
    \ U{} };\n    }\n\n    static Element operation(const Element& L, const Element&\
    \ R) {\n        if (L.first < R.first) return L;\n        else if (L.first > R.first)\
    \ return R;\n        else return Element{ L.first, L.second + R.second };\n  \
    \  }\n\n};\n\n} // namespace \n"
  code: "#pragma once\n\n#include <limits>\n#include <utility>\n\nnamespace zawa {\n\
    \ntemplate <class T, class U>\nstruct MinCountMonoid {\n    // min, count\u306E\
    \u9806\n    using Element = std::pair<T, U>;\n\n    static Element identity()\
    \ noexcept {\n        return { std::numeric_limits<T>::max(), U{} };\n    }\n\n\
    \    static Element operation(const Element& L, const Element& R) {\n        if\
    \ (L.first < R.first) return L;\n        else if (L.first > R.first) return R;\n\
    \        else return Element{ L.first, L.second + R.second };\n    }\n\n};\n\n\
    } // namespace \n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/MinCountMonoid.hpp
  requiredBy:
  - Src/Utility/AreaOfUnionOfRectangles.hpp
  timestamp: '2024-11-05 03:06:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc346_g.test.cpp
  - Test/LC/area_of_union_of_rectangles.test.cpp
documentation_of: Src/Algebra/Monoid/MinCountMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/MinCountMonoid.hpp
- /library/Src/Algebra/Monoid/MinCountMonoid.hpp.html
title: Src/Algebra/Monoid/MinCountMonoid.hpp
---
