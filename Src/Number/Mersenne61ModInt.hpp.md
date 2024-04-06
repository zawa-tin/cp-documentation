---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/RollingHashMonoid.hpp
    title: "\u30ED\u30EA\u30CF\u3092\u30BB\u30B0\u6728\u306B\u306E\u305B\u308B\u6642\
      \u306E\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/RollingHash.hpp
    title: "\u30ED\u30EA\u30CF"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/ALDS1_14_B.test.cpp
    title: Test/AOJ/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc141_e.test.cpp
    title: Test/AtCoder/abc141_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc284_f.test.cpp
    title: Test/AtCoder/abc284_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc331_f.test.cpp
    title: Test/Manual/abc331_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"Src/Number/Mersenne61ModInt.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/Mersenne61ModInt.hpp\"\n\nnamespace\
    \ zawa {\n\n// @reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class Mersenne61ModInt {\npublic:\n    using Value = u64;\nprivate:\n    static\
    \ constexpr Value MOD{(1ull << 61) - 1}; // == MASK61\n    static constexpr Value\
    \ MASK30{(1ull << 30) - 1};\n    static constexpr Value MASK31{(1ull << 31) -\
    \ 1};\n    Value v_{};\npublic:\n    constexpr Mersenne61ModInt() {}\n\n    static\
    \ constexpr Value Mod() noexcept {\n        return MOD;\n    }\n    static constexpr\
    \ Value Modulo(const Value& v) noexcept {\n        Value res{(v >> 61) + (v &\
    \ MOD)};\n        res = (res >= MOD ? res - MOD : res);\n        return res;\n\
    \    }\n    static constexpr Value UnsafeMul(const Value& a, const Value& b) noexcept\
    \ {\n        Value fa{a >> 31}, fb{b >> 31};\n        Value ba{a & MASK31}, bb{b\
    \ & MASK31};\n        Value mid{fa * bb + fb * ba};\n        return Value{2}*fa*fb\
    \ + (mid >> 30) + ((mid & MASK30) << 31) + ba*bb;\n    }\n    static constexpr\
    \ Value Mul(const Value& a, const Value& b) noexcept {\n        return Modulo(UnsafeMul(a,\
    \ b));\n    }\n};\n\n};\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\nnamespace zawa\
    \ {\n\n// @reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\nclass\
    \ Mersenne61ModInt {\npublic:\n    using Value = u64;\nprivate:\n    static constexpr\
    \ Value MOD{(1ull << 61) - 1}; // == MASK61\n    static constexpr Value MASK30{(1ull\
    \ << 30) - 1};\n    static constexpr Value MASK31{(1ull << 31) - 1};\n    Value\
    \ v_{};\npublic:\n    constexpr Mersenne61ModInt() {}\n\n    static constexpr\
    \ Value Mod() noexcept {\n        return MOD;\n    }\n    static constexpr Value\
    \ Modulo(const Value& v) noexcept {\n        Value res{(v >> 61) + (v & MOD)};\n\
    \        res = (res >= MOD ? res - MOD : res);\n        return res;\n    }\n \
    \   static constexpr Value UnsafeMul(const Value& a, const Value& b) noexcept\
    \ {\n        Value fa{a >> 31}, fb{b >> 31};\n        Value ba{a & MASK31}, bb{b\
    \ & MASK31};\n        Value mid{fa * bb + fb * ba};\n        return Value{2}*fa*fb\
    \ + (mid >> 30) + ((mid & MASK30) << 31) + ba*bb;\n    }\n    static constexpr\
    \ Value Mul(const Value& a, const Value& b) noexcept {\n        return Modulo(UnsafeMul(a,\
    \ b));\n    }\n};\n\n};\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/Mersenne61ModInt.hpp
  requiredBy:
  - Src/Sequence/RollingHash.hpp
  - Src/Algebra/Monoid/RollingHashMonoid.hpp
  timestamp: '2023-12-04 20:18:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc284_f.test.cpp
  - Test/AtCoder/abc141_e.test.cpp
  - Test/Manual/abc331_f.test.cpp
  - Test/AOJ/ALDS1_14_B.test.cpp
documentation_of: Src/Number/Mersenne61ModInt.hpp
layout: document
redirect_from:
- /library/Src/Number/Mersenne61ModInt.hpp
- /library/Src/Number/Mersenne61ModInt.hpp.html
title: Src/Number/Mersenne61ModInt.hpp
---
