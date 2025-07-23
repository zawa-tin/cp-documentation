---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc288_e.test.cpp
    title: ABC288-E Wish List
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_h.test.cpp
    title: Test/AtCoder/abc292_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MaxMonoid.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n#include <optional>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass MaxMonoid {\npublic:\n    using Element = std::optional<T>;\n    static\
    \ constexpr Element identity() noexcept {\n        return std::nullopt;\n    }\n\
    \    static constexpr Element operation(const Element& l, const Element& r) noexcept\
    \ {\n        if (l and r) {\n            return std::max(l, r);\n        }\n \
    \       else if (l) {\n            return l;\n        }\n        else if (r) {\n\
    \            return r;\n        }\n        else {\n            return std::nullopt;\n\
    \        }\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n#include <optional>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass MaxMonoid {\npublic:\n    using\
    \ Element = std::optional<T>;\n    static constexpr Element identity() noexcept\
    \ {\n        return std::nullopt;\n    }\n    static constexpr Element operation(const\
    \ Element& l, const Element& r) noexcept {\n        if (l and r) {\n         \
    \   return std::max(l, r);\n        }\n        else if (l) {\n            return\
    \ l;\n        }\n        else if (r) {\n            return r;\n        }\n   \
    \     else {\n            return std::nullopt;\n        }\n    }\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/MaxMonoid.hpp
  requiredBy: []
  timestamp: '2024-02-09 20:29:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc292_h.test.cpp
  - Test/AtCoder/abc288_e.test.cpp
documentation_of: Src/Algebra/Monoid/MaxMonoid.hpp
layout: document
title: "max\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
---

# 概要

`std::optional<T>`を利用して、 $-\infty$ を `std::nullopt`で表現している。

`std::optional<T>`の運用については [std::optional cpprefjp](https://cpprefjp.github.io/reference/optional/optional.html) 等も参考にすること。
