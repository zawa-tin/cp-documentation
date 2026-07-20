---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/kth_root_integer.test.cpp
    title: Test/LC/kth_root_integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/KthRoot.hpp\"\n\n#include <cassert>\n#include\
    \ <cmath>\n#include <concepts>\n#include <utility>\n#include <limits>\n\nnamespace\
    \ zawa {\n\n// floor(a^{1/k})\ntemplate <std::unsigned_integral T>\nT KthRoot(T\
    \ a,T k,bool floor=1) {\n    assert(k >= 1);\n    if (a <= 1 or k == 1)\n    \
    \    return a;\n    if (k >= std::numeric_limits<T>::digits)\n        return floor\
    \ ? 1 : 2;\n    auto pw = [&](T x) -> T {\n        T res = 1, exp = k;\n     \
    \   while (exp) {\n            if (exp & 1) {\n                if (res > std::numeric_limits<T>::max()\
    \ / x)\n                    return 0;\n                res *= x;\n           \
    \ }\n            exp >>= 1;\n            if (exp) {\n                if (x > std::numeric_limits<T>::max()\
    \ / x)\n                    return 0;\n                x *= x;\n            }\n\
    \        }\n        return res;\n    };\n    T res = k == 2 ? sqrtl(a) : (k ==\
    \ 3 ? cbrtl(a) : powl(a,1.0l/(double)k));\n    while (res >= 1) {\n        T v\
    \ = pw(res);\n        if (v and v <= a)\n            break;\n        res--;\n\
    \    }\n    while (true) {\n        T v = pw(res+1);\n        if (v and v <= a)\n\
    \            res++;\n        else\n            break;\n    }\n    if (!floor and\
    \ pw(res) < a)\n        res++;\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cmath>\n#include <concepts>\n\
    #include <utility>\n#include <limits>\n\nnamespace zawa {\n\n// floor(a^{1/k})\n\
    template <std::unsigned_integral T>\nT KthRoot(T a,T k,bool floor=1) {\n    assert(k\
    \ >= 1);\n    if (a <= 1 or k == 1)\n        return a;\n    if (k >= std::numeric_limits<T>::digits)\n\
    \        return floor ? 1 : 2;\n    auto pw = [&](T x) -> T {\n        T res =\
    \ 1, exp = k;\n        while (exp) {\n            if (exp & 1) {\n           \
    \     if (res > std::numeric_limits<T>::max() / x)\n                    return\
    \ 0;\n                res *= x;\n            }\n            exp >>= 1;\n     \
    \       if (exp) {\n                if (x > std::numeric_limits<T>::max() / x)\n\
    \                    return 0;\n                x *= x;\n            }\n     \
    \   }\n        return res;\n    };\n    T res = k == 2 ? sqrtl(a) : (k == 3 ?\
    \ cbrtl(a) : powl(a,1.0l/(double)k));\n    while (res >= 1) {\n        T v = pw(res);\n\
    \        if (v and v <= a)\n            break;\n        res--;\n    }\n    while\
    \ (true) {\n        T v = pw(res+1);\n        if (v and v <= a)\n            res++;\n\
    \        else\n            break;\n    }\n    if (!floor and pw(res) < a)\n  \
    \      res++;\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Number/KthRoot.hpp
  requiredBy: []
  timestamp: '2026-07-20 19:53:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/kth_root_integer.test.cpp
documentation_of: Src/Number/KthRoot.hpp
layout: document
title: "$K$ \u4E57\u6839\u3092\u6574\u6570\u306B\u5207\u308A\u6368\u3066\u30FB\u5207\
  \u308A\u4E0A\u3052"
---

非負整数 $a,k$ に対して $\lfloor a^{\frac{1}{k}}\rfloor$ や $\lceil a^{\frac{1}{k}}\rceil$ を計算する。

- **ceilの方はverifyしていない**

制約: $a, k$ の型は**std::unsigned_integral**がtrueに派生する必要がある。 $k > 0$ が必要である。

標準関数で近い値を求めた後適当に足し引きするという実装方針を取っている(自分がいつもやっているやつ)

## 更新履歴

- 2026/07/20: 作成
