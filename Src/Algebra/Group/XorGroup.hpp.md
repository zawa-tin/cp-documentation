---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc308_g.test.cpp
    title: Test/AtCoder/abc308_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF956-F.test.cpp
    title: Test/CF/CF956-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/XorGroup.hpp\"\n\nnamespace zawa {\n\n\
    template <class T>\nclass XorGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr Element identity() noexcept {\n        return Element{};\n    }\n\
    \    static constexpr Element operation(const Element& l, const Element& r) noexcept\
    \ {\n        return l ^ r;\n    }\n    static constexpr Element inverse(const\
    \ Element& v) noexcept {\n        return v;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nclass XorGroup {\n\
    public:\n    using Element = T;\n    static constexpr Element identity() noexcept\
    \ {\n        return Element{};\n    }\n    static constexpr Element operation(const\
    \ Element& l, const Element& r) noexcept {\n        return l ^ r;\n    }\n   \
    \ static constexpr Element inverse(const Element& v) noexcept {\n        return\
    \ v;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Group/XorGroup.hpp
  requiredBy: []
  timestamp: '2024-07-27 05:40:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF956-F.test.cpp
  - Test/AtCoder/abc308_g.test.cpp
documentation_of: Src/Algebra/Group/XorGroup.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Group/XorGroup.hpp
- /library/Src/Algebra/Group/XorGroup.hpp.html
title: Src/Algebra/Group/XorGroup.hpp
---
