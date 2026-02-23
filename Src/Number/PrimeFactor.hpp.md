---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Number/LinearSieve.hpp
    title: "\u7DDA\u5F62\u7BE9 (osa-k\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactorize.hpp
    title: Src/Number/PrimeFactorize.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2706.test.cpp
    title: "AOJ2706 \u5E7E\u4F55\u554F\u984C\u3092\u89E3\u3053\u3046"
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc170_d.test.cpp
    title: Test/AtCoder/abc170_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc177_e.test.cpp
    title: Test/AtCoder/abc177_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc349_f.test.cpp
    title: ABC349-F Subsequence LCM
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc185_e.test.cpp
    title: "ABC185-E Adjacent GCD (\u7D04\u6570\u30FB\u500D\u6570\u95A2\u4FC2\u306E\
      \u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1070-F.test.cpp
    title: Test/CF/CF1070-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF902-B.test.cpp
    title: Test/CF/CF902-B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/PrimeFactor.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/PrimeFactor.hpp\"\n\n#include <type_traits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass PrimeFactor {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"T must be unsigned integer\");\nprivate:\n    T factor_{};\n    u32 exponent_{};\n\
    \npublic: \n    PrimeFactor() = default;\n\n    PrimeFactor(T factor, u32 exponent)\
    \ : factor_{factor}, exponent_{exponent} {}\n\n    inline T factor() const noexcept\
    \ {\n        return factor_;\n    }\n\n    inline u32 exponent() const noexcept\
    \ {\n        return exponent_;\n    }\n\n    friend bool operator<(const PrimeFactor<T>&\
    \ lhs, const PrimeFactor<T>& rhs) {\n        return lhs.factor() != rhs.factor()\
    \ ?\n            lhs.factor() < rhs.factor() :\n            lhs.exponent() < rhs.exponent();\n\
    \    }\n\n    friend bool operator>(const PrimeFactor<T>& lhs, const PrimeFactor<T>&\
    \ rhs) {\n        return lhs.factor() != rhs.factor() ?\n            lhs.factor()\
    \ > rhs.factor() :\n            lhs.exponent() > rhs.exponent();\n    }\n};\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <type_traits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass PrimeFactor {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"T must be unsigned integer\");\nprivate:\n    T factor_{};\n    u32 exponent_{};\n\
    \npublic: \n    PrimeFactor() = default;\n\n    PrimeFactor(T factor, u32 exponent)\
    \ : factor_{factor}, exponent_{exponent} {}\n\n    inline T factor() const noexcept\
    \ {\n        return factor_;\n    }\n\n    inline u32 exponent() const noexcept\
    \ {\n        return exponent_;\n    }\n\n    friend bool operator<(const PrimeFactor<T>&\
    \ lhs, const PrimeFactor<T>& rhs) {\n        return lhs.factor() != rhs.factor()\
    \ ?\n            lhs.factor() < rhs.factor() :\n            lhs.exponent() < rhs.exponent();\n\
    \    }\n\n    friend bool operator>(const PrimeFactor<T>& lhs, const PrimeFactor<T>&\
    \ rhs) {\n        return lhs.factor() != rhs.factor() ?\n            lhs.factor()\
    \ > rhs.factor() :\n            lhs.exponent() > rhs.exponent();\n    }\n};\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/PrimeFactor.hpp
  requiredBy:
  - Src/Number/LinearSieve.hpp
  - Src/Number/PrimeFactorize.hpp
  timestamp: '2024-06-30 19:07:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc349_f.test.cpp
  - Test/AtCoder/abc170_d.test.cpp
  - Test/AtCoder/abc177_e.test.cpp
  - Test/AtCoder/arc185_e.test.cpp
  - Test/AOJ/2706.test.cpp
  - Test/CF/CF902-B.test.cpp
  - Test/CF/CF1070-F.test.cpp
documentation_of: Src/Number/PrimeFactor.hpp
layout: document
redirect_from:
- /library/Src/Number/PrimeFactor.hpp
- /library/Src/Number/PrimeFactor.hpp.html
title: Src/Number/PrimeFactor.hpp
---
