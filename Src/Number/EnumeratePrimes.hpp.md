---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/ECR178-D.test.cpp
    title: Test/CF/ECR178-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/enumerate_primes.test.cpp
    title: Test/LC/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Number/EnumeratePrimes.test.cpp
    title: Test/My/Number/EnumeratePrimes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/EnumeratePrimes.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/EnumeratePrimes.hpp\"\n\n#include\
    \ <concepts>\n#include <vector>\n#include <bit>\n\nnamespace zawa {\n\ntemplate\
    \ <std::integral T>\nstd::vector<T> EnumeratePrimes(usize N) {\n    static constexpr\
    \ u32 p[]{2,3,5,7,11,13,17,19,23,29,31};\n    u32 w = 1;\n    usize m = 0;\n \
    \   for ( ; m < std::size(p) and static_cast<u64>(w) * w < N ; w *= p[m++]) ;\n\
    \    std::vector<u32> R = [&]() {\n        std::vector<bool> siv(w, true);\n \
    \       for (usize i = 0 ; i < m ; i++) {\n            for (u32 j = p[i] ; j <\
    \ w ; j += p[i]) siv[j] = false;\n        }\n        std::vector<u32> res{1};\n\
    \        for (u32 i = 2 ; i < w ; i++) if (siv[i]) res.push_back(i);\n       \
    \ return res;\n    }();\n    std::vector<T> res;\n    res.reserve(N / (std::bit_width(N)\
    \ + 1));\n    std::vector<u32> S;\n    S.reserve(N / 5u);\n    for (u32 kw = 0\
    \ ; kw <= N ; kw += w) {\n        for (u32 r = 0 ; r < R.size() and kw + R[r]\
    \ <= N ; r++) {\n            S.push_back(kw + R[r]);\n        }\n    }\n    for\
    \ (usize i = 0 ; i < m ; i++) res.push_back(static_cast<T>(p[i]));\n    std::vector<bool>\
    \ siv(N + 1, true);\n    for (usize i = 1 ; i < S.size() ; i++) if (siv[S[i]])\
    \ {\n        res.push_back(static_cast<T>(S[i])); \n        for (u32 j = i ; j\
    \ < S.size() ; j++) {\n            u64 p = static_cast<u64>(S[i]) * S[j];\n  \
    \          if (p > N) break;\n            siv[p] = false;\n        }\n    }\n\
    \    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <concepts>\n\
    #include <vector>\n#include <bit>\n\nnamespace zawa {\n\ntemplate <std::integral\
    \ T>\nstd::vector<T> EnumeratePrimes(usize N) {\n    static constexpr u32 p[]{2,3,5,7,11,13,17,19,23,29,31};\n\
    \    u32 w = 1;\n    usize m = 0;\n    for ( ; m < std::size(p) and static_cast<u64>(w)\
    \ * w < N ; w *= p[m++]) ;\n    std::vector<u32> R = [&]() {\n        std::vector<bool>\
    \ siv(w, true);\n        for (usize i = 0 ; i < m ; i++) {\n            for (u32\
    \ j = p[i] ; j < w ; j += p[i]) siv[j] = false;\n        }\n        std::vector<u32>\
    \ res{1};\n        for (u32 i = 2 ; i < w ; i++) if (siv[i]) res.push_back(i);\n\
    \        return res;\n    }();\n    std::vector<T> res;\n    res.reserve(N / (std::bit_width(N)\
    \ + 1));\n    std::vector<u32> S;\n    S.reserve(N / 5u);\n    for (u32 kw = 0\
    \ ; kw <= N ; kw += w) {\n        for (u32 r = 0 ; r < R.size() and kw + R[r]\
    \ <= N ; r++) {\n            S.push_back(kw + R[r]);\n        }\n    }\n    for\
    \ (usize i = 0 ; i < m ; i++) res.push_back(static_cast<T>(p[i]));\n    std::vector<bool>\
    \ siv(N + 1, true);\n    for (usize i = 1 ; i < S.size() ; i++) if (siv[S[i]])\
    \ {\n        res.push_back(static_cast<T>(S[i])); \n        for (u32 j = i ; j\
    \ < S.size() ; j++) {\n            u64 p = static_cast<u64>(S[i]) * S[j];\n  \
    \          if (p > N) break;\n            siv[p] = false;\n        }\n    }\n\
    \    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/EnumeratePrimes.hpp
  requiredBy: []
  timestamp: '2025-05-09 20:26:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/enumerate_primes.test.cpp
  - Test/CF/ECR178-D.test.cpp
  - Test/My/Number/EnumeratePrimes.test.cpp
documentation_of: Src/Number/EnumeratePrimes.hpp
layout: document
title: Enumerate Primes
---

## 概要

Wheel Sieveを実装しようとして、失敗してできた残骸。自分のエラトステネスの篩より $5$ 倍くらい早いので取り敢えず実戦には耐えそう。

## ライブラリの使い方

```cpp
template <std::integral T>
std::vector<T> EnumeratePrimes(usize N)
```

$N$ 以下の素数を`T`型のvectorに昇順に並べて返す。

## 参考

- [素数列挙: Wheel Sieve](https://37zigen.com/wheel-sieve/)
- メモリの削減及びlpfに注目した高速化が説明されているが、今の所読解に失敗しており、本ライブラリでは実装されていない。
