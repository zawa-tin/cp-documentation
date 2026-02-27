---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc350_c.test.cpp
    title: Test/AtCoder/abc350_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1015-C.test.cpp
    title: Test/CF/CF1015-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/PermutationSwapSort.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 10 \"Src/Sequence/PermutationSwapSort.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\n// Is A permutation of (0,1,...,|A|-1)\
    \ ?\ntemplate <std::integral T>\nbool IsPermutation(const std::vector<T>& A) {\n\
    \    std::vector<bool> app(A.size());\n    for (T v : A) {\n        if (v < 0\
    \ or v >= (T)A.size()) return false;\n        if (app[v]) return false;\n    \
    \    app[v] = true;\n    }\n    return true;\n}\n\n} // namespace internal\n\n\
    template <std::input_iterator It>\nstd::vector<std::pair<usize, usize>> PermutationSwapSort(It\
    \ first, It last) {\n    std::vector P(first, last);\n    assert(internal::IsPermutation(P));\n\
    \    std::vector<std::pair<usize, usize>> res;\n    for (usize i = 0 ; i < P.size()\
    \ ; i++) while ((usize)P[i] != i) {\n        res.push_back({i, P[i]});\n     \
    \   std::swap(P[i], P[P[i]]);\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <concepts>\n#include <iterator>\n\
    #include <utility>\n#include <vector>\n\n#include \"../Template/TypeAlias.hpp\"\
    \n\nnamespace zawa {\n\nnamespace internal {\n\n// Is A permutation of (0,1,...,|A|-1)\
    \ ?\ntemplate <std::integral T>\nbool IsPermutation(const std::vector<T>& A) {\n\
    \    std::vector<bool> app(A.size());\n    for (T v : A) {\n        if (v < 0\
    \ or v >= (T)A.size()) return false;\n        if (app[v]) return false;\n    \
    \    app[v] = true;\n    }\n    return true;\n}\n\n} // namespace internal\n\n\
    template <std::input_iterator It>\nstd::vector<std::pair<usize, usize>> PermutationSwapSort(It\
    \ first, It last) {\n    std::vector P(first, last);\n    assert(internal::IsPermutation(P));\n\
    \    std::vector<std::pair<usize, usize>> res;\n    for (usize i = 0 ; i < P.size()\
    \ ; i++) while ((usize)P[i] != i) {\n        res.push_back({i, P[i]});\n     \
    \   std::swap(P[i], P[P[i]]);\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/PermutationSwapSort.hpp
  requiredBy: []
  timestamp: '2025-04-06 19:32:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF1015-C.test.cpp
  - Test/AtCoder/abc350_c.test.cpp
documentation_of: Src/Sequence/PermutationSwapSort.hpp
layout: document
title: "Permutation\u3092 $N-1$ \u56DE\u4EE5\u4E0B\u306Eswap\u3067\u30BD\u30FC\u30C8\
  \u3059\u308B"
---

## 概要

$(0,1,2,\dots, N-1)$ の並び替え $P$ を入力に与えると、 $N-1$ 回以下の(隣接とは限らない)二点swapでソートします。

なお、実際にソートは行われず操作列が返ります。

## ライブラリの使い方

```cpp
template <std::input_iterator It>
std::vector<std::pair<usize, usize>> PermutationSwapSort(It first, It last)
```

**計算量:** $O(N)$
- 順列であるかのチェックや`std::vector`へのコピーが行われるため、若干オーバーヘッドがあります
