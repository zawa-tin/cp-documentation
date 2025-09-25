---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc398_f.test.cpp
    title: Test/AtCoder/abc398_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/enumerate_palindromes.test.cpp
    title: Test/LC/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://snuke.hatenablog.com/entry/2014/12/02/235837
  bundledCode: "#line 2 \"Src/Sequence/Manacher.hpp\"\n\n#include <concepts>\n#include\
    \ <optional>\n#include <vector>\n#include <string>\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 9 \"Src/Sequence/Manacher.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace concepts {\n\ntemplate <class C, class T>\nconcept Container\
    \ = requires (C c, usize idx) {\n    { c[idx] } -> std::convertible_to<T>;\n};\n\
    \n} // namespace concepts\n\nnamespace internal {\n\n// ref: https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    template <std::equality_comparable T, std::integral RES>\nstd::vector<RES> Manacher(const\
    \ std::vector<std::optional<T>>& a) {\n    std::vector<RES> res(a.size());\n \
    \   for (usize i = 0, j = 0 ; i < a.size() ; ) {\n        // i + j\u306F\u3053\
    \u3053\u3067\u3057\u304B\u5897\u52A0\u305B\u305A\u3001i + j\u306F\u9AD8\u3005\
    |a|\u3057\u304B\u5897\u3048\u306A\u3044\n        // -> \u3053\u306E\u30EB\u30FC\
    \u30D7\u306F\u9AD8\u3005|a|\n        while (i >= j and i + j < a.size() and a[i\
    \ - j] == a[i + j]) j++;\n        res[i] = j;\n        usize k = 1;\n        //\
    \ i\u306F\u9AD8\u3005|a|\u307E\u3067\u3057\u304B\u5897\u3048\u306A\u3044->k\u3092\
    \u5897\u3084\u3057\u3066\u3044\u308B\u3053\u306E\u30EB\u30FC\u30D7\u306F\u4E01\
    \u5EA6|a|\n        for ( ; i >= k and k + res[i - k] < j ; k++) res[i + k] = res[i\
    \ - k];\n        i += k;\n        j -= k;\n    } \n    for (usize i = 0 ; i <\
    \ res.size() ; i++) {\n        if (i & 1) {\n            res[i] = res[i] & (res[i]\
    \ ^ 1);\n        }\n        else {\n            res[i] = (res[i] & 1 ? res[i]\
    \ : res[i] - 1);\n        }\n    }\n    return res;\n}\n\n} // namespace internal\n\
    \ntemplate <std::integral RES = usize, std::equality_comparable T = char, class\
    \ C = std::string>\nrequires concepts::Container<C, T>\nstd::vector<RES> Manacher(C\
    \ a) {\n    if (a.empty()) return {};\n    std::vector<std::optional<T>> seq(2\
    \ * a.size() - 1);\n    for (usize i = 0 ; i < a.size() ; i++) {\n        seq[2\
    \ * i] = std::optional{std::move(a[i])};\n    }\n    return internal::Manacher<T,\
    \ RES>(seq);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <concepts>\n#include <optional>\n#include <vector>\n\
    #include <string>\n\n#include \"../Template/TypeAlias.hpp\"\n\nnamespace zawa\
    \ {\n\nnamespace concepts {\n\ntemplate <class C, class T>\nconcept Container\
    \ = requires (C c, usize idx) {\n    { c[idx] } -> std::convertible_to<T>;\n};\n\
    \n} // namespace concepts\n\nnamespace internal {\n\n// ref: https://snuke.hatenablog.com/entry/2014/12/02/235837\n\
    template <std::equality_comparable T, std::integral RES>\nstd::vector<RES> Manacher(const\
    \ std::vector<std::optional<T>>& a) {\n    std::vector<RES> res(a.size());\n \
    \   for (usize i = 0, j = 0 ; i < a.size() ; ) {\n        // i + j\u306F\u3053\
    \u3053\u3067\u3057\u304B\u5897\u52A0\u305B\u305A\u3001i + j\u306F\u9AD8\u3005\
    |a|\u3057\u304B\u5897\u3048\u306A\u3044\n        // -> \u3053\u306E\u30EB\u30FC\
    \u30D7\u306F\u9AD8\u3005|a|\n        while (i >= j and i + j < a.size() and a[i\
    \ - j] == a[i + j]) j++;\n        res[i] = j;\n        usize k = 1;\n        //\
    \ i\u306F\u9AD8\u3005|a|\u307E\u3067\u3057\u304B\u5897\u3048\u306A\u3044->k\u3092\
    \u5897\u3084\u3057\u3066\u3044\u308B\u3053\u306E\u30EB\u30FC\u30D7\u306F\u4E01\
    \u5EA6|a|\n        for ( ; i >= k and k + res[i - k] < j ; k++) res[i + k] = res[i\
    \ - k];\n        i += k;\n        j -= k;\n    } \n    for (usize i = 0 ; i <\
    \ res.size() ; i++) {\n        if (i & 1) {\n            res[i] = res[i] & (res[i]\
    \ ^ 1);\n        }\n        else {\n            res[i] = (res[i] & 1 ? res[i]\
    \ : res[i] - 1);\n        }\n    }\n    return res;\n}\n\n} // namespace internal\n\
    \ntemplate <std::integral RES = usize, std::equality_comparable T = char, class\
    \ C = std::string>\nrequires concepts::Container<C, T>\nstd::vector<RES> Manacher(C\
    \ a) {\n    if (a.empty()) return {};\n    std::vector<std::optional<T>> seq(2\
    \ * a.size() - 1);\n    for (usize i = 0 ; i < a.size() ; i++) {\n        seq[2\
    \ * i] = std::optional{std::move(a[i])};\n    }\n    return internal::Manacher<T,\
    \ RES>(seq);\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Sequence/Manacher.hpp
  requiredBy: []
  timestamp: '2025-07-09 19:40:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc398_f.test.cpp
  - Test/LC/enumerate_palindromes.test.cpp
documentation_of: Src/Sequence/Manacher.hpp
layout: document
title: Manacher (Enumerate Palindromes)
---

## 概要

長さ $N$ の列 $A$ に対して以下の要件を満たす $2N - 1$ 要素の列 $(D_1, D_2, \dots, D_{2N - 1})$ を返す。

- $i$ が奇数ならば、 $D_i$ は $A$ の $\frac{i + 1}{2}$ 番目の要素を中心とする極大な回文の要素数
- $i$ が偶数ならば、 $D_i$ は $A$ の $\frac{i}{2}$ 番目の要素と $\frac{i}{2}+1$ 番目の要素の間を中心とする極大な回文の要素数

## ライブラリの使い方

```cpp
template <std::integral RES = usize, std::equality_comparable T = char, class C = std::string>
requires concepts::Container<C, T>
```

`RES`は返り値の型`usize`や`int`など。
