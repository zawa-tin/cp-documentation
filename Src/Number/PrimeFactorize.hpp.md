---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/PrimeFactor.hpp
    title: Src/Number/PrimeFactor.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2706.test.cpp
    title: "AOJ2706 \u5E7E\u4F55\u554F\u984C\u3092\u89E3\u3053\u3046"
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc349_f.test.cpp
    title: ABC349-F Subsequence LCM
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/PrimeFactorize.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/PrimeFactor.hpp\"\n\n#line 4 \"Src/Number/PrimeFactor.hpp\"\
    \n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass PrimeFactor\
    \ {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\");\n\
    private:\n    T factor_{};\n    u32 exponent_{};\n\npublic: \n    PrimeFactor()\
    \ = default;\n\n    PrimeFactor(T factor, u32 exponent) : factor_{factor}, exponent_{exponent}\
    \ {}\n\n    inline T factor() const noexcept {\n        return factor_;\n    }\n\
    \n    inline u32 exponent() const noexcept {\n        return exponent_;\n    }\n\
    \n    friend bool operator<(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs)\
    \ {\n        return lhs.factor() != rhs.factor() ?\n            lhs.factor() <\
    \ rhs.factor() :\n            lhs.exponent() < rhs.exponent();\n    }\n\n    friend\
    \ bool operator>(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs) {\n   \
    \     return lhs.factor() != rhs.factor() ?\n            lhs.factor() > rhs.factor()\
    \ :\n            lhs.exponent() > rhs.exponent();\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Src/Number/PrimeFactorize.hpp\"\n\n#include <cassert>\n#line\
    \ 8 \"Src/Number/PrimeFactorize.hpp\"\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstd::vector<PrimeFactor<T>> PrimeFactorize(T\
    \ x) {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\"\
    );\n    assert(x > T{0});\n    std::vector<PrimeFactor<T>> res;\n    for (T f{2}\
    \ ; u64{f} * f <= x ; f++) {\n        u32 exp{};\n        while (x % f == 0) {\n\
    \            exp++;\n            x /= f;\n        }\n        if (exp) {\n    \
    \        res.emplace_back(f, exp);\n        }\n    }\n    if (x > T{1}) {\n  \
    \      res.emplace_back(x, u32{1});\n    }\n    return res;\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./PrimeFactor.hpp\"\
    \n\n#include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstd::vector<PrimeFactor<T>> PrimeFactorize(T\
    \ x) {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\"\
    );\n    assert(x > T{0});\n    std::vector<PrimeFactor<T>> res;\n    for (T f{2}\
    \ ; u64{f} * f <= x ; f++) {\n        u32 exp{};\n        while (x % f == 0) {\n\
    \            exp++;\n            x /= f;\n        }\n        if (exp) {\n    \
    \        res.emplace_back(f, exp);\n        }\n    }\n    if (x > T{1}) {\n  \
    \      res.emplace_back(x, u32{1});\n    }\n    return res;\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/PrimeFactor.hpp
  isVerificationFile: false
  path: Src/Number/PrimeFactorize.hpp
  requiredBy: []
  timestamp: '2024-06-30 19:07:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc349_f.test.cpp
  - Test/AOJ/2706.test.cpp
documentation_of: Src/Number/PrimeFactorize.hpp
layout: document
redirect_from:
- /library/Src/Number/PrimeFactorize.hpp
- /library/Src/Number/PrimeFactorize.hpp.html
title: Src/Number/PrimeFactorize.hpp
---
