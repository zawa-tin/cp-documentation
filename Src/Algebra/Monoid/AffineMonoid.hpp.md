---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc332_f.test.cpp
    title: "ABC332-F Random Update Query (a <- ap + q\u306E\u51E6\u7406)"
  - icon: ':heavy_check_mark:'
    path: Test/LC/deque_operate_all_composite.test.cpp
    title: Test/LC/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_range_composite.test.cpp
    title: Test/LC/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_range_composite_large_array.test.cpp
    title: Test/LC/point_set_range_composite_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/queue_operate_all_composite.test.cpp
    title: Test/LC/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_point_get.test.cpp
    title: Test/LC/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_range_sum.test.cpp
    title: Test/LC/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_set_range_composite.test.cpp
    title: Test/LC/range_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/AffineMonoid.hpp\"\n\n#include <ostream>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass Affine {\nprivate:\n    T a_{1},\
    \ b_{};\npublic:\n    constexpr Affine() {}\n    constexpr Affine(const T& a,\
    \ const T& b) : a_{a}, b_{b} {}\n    T a() const noexcept {\n        return a_;\n\
    \    }\n    T b() const noexcept {\n        return b_;\n    }\n    constexpr T\
    \ mapping(const T& x) const {\n        return a_ * x + b_;\n    }\n    constexpr\
    \ T operator()(const T& x) const {\n        return a_ * x + b_;\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Affine& affine) {\n       \
    \ os << '(' << affine.a_ << ',' << affine.b_ << ')';\n        return os;\n   \
    \ }\n    friend bool operator==(const Affine& lhs, const Affine& rhs) {\n    \
    \    return lhs.a_ == rhs.a_ and lhs.b_ == rhs.b_;\n    }\n};\n\ntemplate <class\
    \ T>\nstruct AffineMonoid {\n    using Element = Affine<T>;\n    static constexpr\
    \ Element identity() noexcept {\n        return Element{};\n    }\n    // f_r(f_l(x)):\
    \ a_r(a_lx+b_l)+b_r\n    static constexpr Element operation(const Element& l,\
    \ const Element& r) noexcept {\n        return Element{ l.a() * r.a(), l.b() *\
    \ r.a() + r.b() };\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <ostream>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass Affine {\nprivate:\n    T a_{1}, b_{};\npublic:\n    constexpr Affine()\
    \ {}\n    constexpr Affine(const T& a, const T& b) : a_{a}, b_{b} {}\n    T a()\
    \ const noexcept {\n        return a_;\n    }\n    T b() const noexcept {\n  \
    \      return b_;\n    }\n    constexpr T mapping(const T& x) const {\n      \
    \  return a_ * x + b_;\n    }\n    constexpr T operator()(const T& x) const {\n\
    \        return a_ * x + b_;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Affine& affine) {\n        os << '(' << affine.a_ << ',' << affine.b_\
    \ << ')';\n        return os;\n    }\n    friend bool operator==(const Affine&\
    \ lhs, const Affine& rhs) {\n        return lhs.a_ == rhs.a_ and lhs.b_ == rhs.b_;\n\
    \    }\n};\n\ntemplate <class T>\nstruct AffineMonoid {\n    using Element = Affine<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return Element{};\n\
    \    }\n    // f_r(f_l(x)): a_r(a_lx+b_l)+b_r\n    static constexpr Element operation(const\
    \ Element& l, const Element& r) noexcept {\n        return Element{ l.a() * r.a(),\
    \ l.b() * r.a() + r.b() };\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/AffineMonoid.hpp
  requiredBy: []
  timestamp: '2025-02-27 21:25:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc332_f.test.cpp
  - Test/LC/point_set_range_composite.test.cpp
  - Test/LC/range_affine_range_sum.test.cpp
  - Test/LC/range_affine_point_get.test.cpp
  - Test/LC/deque_operate_all_composite.test.cpp
  - Test/LC/range_set_range_composite.test.cpp
  - Test/LC/queue_operate_all_composite.test.cpp
  - Test/LC/point_set_range_composite_large_array.test.cpp
documentation_of: Src/Algebra/Monoid/AffineMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/AffineMonoid.hpp
- /library/Src/Algebra/Monoid/AffineMonoid.hpp.html
title: Src/Algebra/Monoid/AffineMonoid.hpp
---
