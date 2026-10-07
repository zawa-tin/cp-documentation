---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc429_f.test.cpp
    title: Test/AtCoder/abc429_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Ring/MinPlusSemiring.hpp\"\n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(T l,T r) noexcept {\n \
    \       return l + r;\n    }\n    static constexpr T inverse(T v) noexcept {\n\
    \        return -v;\n    }\n    template <class U>\n    static constexpr T power(T\
    \ v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n    }\n};\n\n\
    } // namespace zawa\n#line 4 \"Src/Algebra/Ring/MinPlusSemiring.hpp\"\n\n#include\
    \ <algorithm>\n#include <concepts>\n\nnamespace zawa {\n\nnamespace internal {\n\
    \ntemplate <std::totally_ordered T, T INF>\nstruct Min {\n\n    using Element\
    \ = T; \n\n    static Element identity() {\n        return INF;\n    }\n\n   \
    \ static Element operation(Element L,Element R) {\n        return std::min(L,R);\n\
    \    }\n    \n};\n\n} // namespace internal\n\ntemplate <std::totally_ordered\
    \ T,T INF>\nstruct MinPlusSemiring {\n\n    using Element = T;\n\n    using Addition\
    \ = internal::Min<T,INF>;\n\n    using Multiplication = AdditiveGroup<T>;\n\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Group/AdditiveGroup.hpp\"\n\n#include <algorithm>\n\
    #include <concepts>\n\nnamespace zawa {\n\nnamespace internal {\n\ntemplate <std::totally_ordered\
    \ T, T INF>\nstruct Min {\n\n    using Element = T; \n\n    static Element identity()\
    \ {\n        return INF;\n    }\n\n    static Element operation(Element L,Element\
    \ R) {\n        return std::min(L,R);\n    }\n    \n};\n\n} // namespace internal\n\
    \ntemplate <std::totally_ordered T,T INF>\nstruct MinPlusSemiring {\n\n    using\
    \ Element = T;\n\n    using Addition = internal::Min<T,INF>;\n\n    using Multiplication\
    \ = AdditiveGroup<T>;\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: false
  path: Src/Algebra/Ring/MinPlusSemiring.hpp
  requiredBy: []
  timestamp: '2026-10-07 23:31:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc429_f.test.cpp
documentation_of: Src/Algebra/Ring/MinPlusSemiring.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Ring/MinPlusSemiring.hpp
- /library/Src/Algebra/Ring/MinPlusSemiring.hpp.html
title: Src/Algebra/Ring/MinPlusSemiring.hpp
---
