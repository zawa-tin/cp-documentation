---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc333_g.test.cpp
    title: Test/AtCoder/abc333_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/rational_approximation.test.cpp
    title: Test/LC/rational_approximation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/RationalBinarySearch.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <utility>\n\nnamespace zawa {\n\ntemplate <class\
    \ F, std::integral T>\nrequires std::predicate<F, T, T>\nstd::pair<std::pair<T,\
    \ T>, std::pair<T, T>> RationalBinarySearch(F f, T n) {\n    assert(f(0, 1) and\
    \ !f(1, 0));\n    auto dfs = [&](auto dfs, bool cur, T& p, T& q, T pp, T pq) ->\
    \ void {\n        if (p + pp > n or q + pq > n) return;\n        if (f(p + pp,\
    \ q + pq) == cur) {\n            p += pp;\n            q += pq;\n            dfs(dfs,\
    \ cur, p, q, pp << 1, pq << 1);\n        }\n        if (p + pp <= n and q + pq\
    \ <= n and f(p + pp, q + pq) == cur) {\n            p += pp;\n            q +=\
    \ pq;\n        }\n    };\n    T pl = 0, ql = 1, pr = 1, qr = 0;\n    while (pl\
    \ + pr <= n and ql + qr <= n) {\n        dfs(dfs, true, pl, ql, pr, qr);\n   \
    \     dfs(dfs, false, pr, qr, pl, ql);\n    }\n    return std::pair{std::pair{pl,\
    \ ql}, std::pair{pr, qr}};\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <concepts>\n#include <utility>\n\
    \nnamespace zawa {\n\ntemplate <class F, std::integral T>\nrequires std::predicate<F,\
    \ T, T>\nstd::pair<std::pair<T, T>, std::pair<T, T>> RationalBinarySearch(F f,\
    \ T n) {\n    assert(f(0, 1) and !f(1, 0));\n    auto dfs = [&](auto dfs, bool\
    \ cur, T& p, T& q, T pp, T pq) -> void {\n        if (p + pp > n or q + pq > n)\
    \ return;\n        if (f(p + pp, q + pq) == cur) {\n            p += pp;\n   \
    \         q += pq;\n            dfs(dfs, cur, p, q, pp << 1, pq << 1);\n     \
    \   }\n        if (p + pp <= n and q + pq <= n and f(p + pp, q + pq) == cur) {\n\
    \            p += pp;\n            q += pq;\n        }\n    };\n    T pl = 0,\
    \ ql = 1, pr = 1, qr = 0;\n    while (pl + pr <= n and ql + qr <= n) {\n     \
    \   dfs(dfs, true, pl, ql, pr, qr);\n        dfs(dfs, false, pr, qr, pl, ql);\n\
    \    }\n    return std::pair{std::pair{pl, ql}, std::pair{pr, qr}};\n}\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Utility/RationalBinarySearch.hpp
  requiredBy: []
  timestamp: '2025-07-23 20:10:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/rational_approximation.test.cpp
  - Test/AtCoder/abc333_g.test.cpp
documentation_of: Src/Utility/RationalBinarySearch.hpp
layout: document
title: "\u6709\u7406\u6570\u3067\u4E8C\u5206\u63A2\u7D22"
---

## 概要

$N$ 以下の分母を持つ**非負の**有理数の集合上で二分探索を行い、 $f(\frac{a}{b})$ がTrueになる最大の $\frac{a}{b}$ と $f(\frac{a}{b})$ がFalseになる最小の $\frac{a}{b}$ を計算する。

$f$ は $f(\frac{0}{1}) = \text{T}, f(\frac{0}{1}(= \infty)) = \text{F}$ を満たす必要がある。
