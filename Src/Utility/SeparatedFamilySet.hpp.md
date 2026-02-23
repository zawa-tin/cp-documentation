---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc429_e.test.cpp
    title: Test/AtCoder/abc429_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/UC/3-36-F.test.cpp
    title: Test/UC/3-36-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2024/05/31/012055
  bundledCode: "#line 2 \"Src/Utility/SeparatedFamilySet.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n#include <concepts>\n#include <ranges>\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 9 \"Src/Utility/SeparatedFamilySet.hpp\"\n\nnamespace\
    \ zawa {\n\n// https://noshi91.hatenablog.com/entry/2024/05/31/012055\n// each\
    \ (i, j) satisfy there are k such that res[k][i]=1,res[k][j]=0\nstd::vector<std::vector<bool>>\
    \ SeparatedFamilySet(usize U) {\n    const usize d = [&]() {\n        for (usize\
    \ i = 1 ; ; i++) {\n            usize max = 1;\n            for (usize j = 0 ;\
    \ j < (i / 2) ; j++) {\n                max *= i - j;\n                max /=\
    \ j + 1;\n            }\n            if (max >= U) return i;\n        }\n    \
    \    return U;\n    }();\n    std::vector res(d, std::vector<bool>(U));\n    std::vector<u8>\
    \ in(d);\n    std::fill(in.rbegin(), in.rbegin() + d / 2, true);\n    for (usize\
    \ idx = 0 ; idx < U ; idx++) {\n        for (usize i = 0 ; i < d ; i++) if (in[i])\
    \ {\n            res[i][idx] = true;\n        }\n        std::ranges::next_permutation(in);\n\
    \    }\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n#include <concepts>\n\
    #include <ranges>\n\n#include \"../Template/TypeAlias.hpp\"\n\nnamespace zawa\
    \ {\n\n// https://noshi91.hatenablog.com/entry/2024/05/31/012055\n// each (i,\
    \ j) satisfy there are k such that res[k][i]=1,res[k][j]=0\nstd::vector<std::vector<bool>>\
    \ SeparatedFamilySet(usize U) {\n    const usize d = [&]() {\n        for (usize\
    \ i = 1 ; ; i++) {\n            usize max = 1;\n            for (usize j = 0 ;\
    \ j < (i / 2) ; j++) {\n                max *= i - j;\n                max /=\
    \ j + 1;\n            }\n            if (max >= U) return i;\n        }\n    \
    \    return U;\n    }();\n    std::vector res(d, std::vector<bool>(U));\n    std::vector<u8>\
    \ in(d);\n    std::fill(in.rbegin(), in.rbegin() + d / 2, true);\n    for (usize\
    \ idx = 0 ; idx < U ; idx++) {\n        for (usize i = 0 ; i < d ; i++) if (in[i])\
    \ {\n            res[i][idx] = true;\n        }\n        std::ranges::next_permutation(in);\n\
    \    }\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Utility/SeparatedFamilySet.hpp
  requiredBy: []
  timestamp: '2025-10-26 19:01:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc429_e.test.cpp
  - Test/UC/3-36-F.test.cpp
documentation_of: Src/Utility/SeparatedFamilySet.hpp
layout: document
title: "2\u8981\u7D20\u306E\u5206\u96E2\u3092\u7DB2\u7F85\u3059\u308B\u30C6\u30AF\u30CB\
  \u30C3\u30AF"
---

$U = \{ 0, 1, 2, \dots, U - 1\}$ に対してある集合属 $S \subseteqq 2^{U}$ を計算する。 $S$ は以下の条件を満たす。

- 任意の $x, y\in U, x \ne y$ に対してある $s\in S$ が存在して $x\in s, y\notin s$ である。
- 条件を満たす $S$ は沢山あるが、そのなかで $\text{card}(S)$ が最小のものを一つ計算する。

計算量: $O(U\log U)$

- $\text{card}(S) \in \log_{2}U + O(\log \log U)$ らしい

## ライブラリの使い方

```
std::vector<std::vector<bool>> SeparatedFamilySet(usize U)
```

長さ $U$ の`std::vector<bool>`を $\text{card}(S)$ 個並べた`std::vector`を返す。

`res[i][j]` は $i$ 番目の集合に $j$ が属しているか。

## 参考

- [2要素の分離を網羅するテクニック](https://noshi91.hatenablog.com/entry/2024/05/31/012055)
