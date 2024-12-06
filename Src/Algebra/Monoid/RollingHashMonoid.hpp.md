---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/Mersenne61ModInt.hpp
    title: Src/Number/Mersenne61ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/0478.test.cpp
    title: Test/AOJ/0478.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc331_f.test.cpp
    title: Test/AtCoder/abc331_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3548.test.cpp
    title: AOJ3548 String Puzzle
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Number/Mersenne61ModInt.hpp\"\
    \n\n#line 4 \"Src/Number/Mersenne61ModInt.hpp\"\n\nnamespace zawa {\n\n// @reference:\
    \ https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\nclass Mersenne61ModInt\
    \ {\npublic:\n    using Value = u64;\nprivate:\n    static constexpr Value MOD{(1ull\
    \ << 61) - 1}; // == MASK61\n    static constexpr Value MASK30{(1ull << 30) -\
    \ 1};\n    static constexpr Value MASK31{(1ull << 31) - 1};\n    Value v_{};\n\
    public:\n    constexpr Mersenne61ModInt() {}\n\n    static constexpr Value Mod()\
    \ noexcept {\n        return MOD;\n    }\n    static constexpr Value Modulo(const\
    \ Value& v) noexcept {\n        Value res{(v >> 61) + (v & MOD)};\n        res\
    \ = (res >= MOD ? res - MOD : res);\n        return res;\n    }\n    static constexpr\
    \ Value UnsafeMul(const Value& a, const Value& b) noexcept {\n        Value fa{a\
    \ >> 31}, fb{b >> 31};\n        Value ba{a & MASK31}, bb{b & MASK31};\n      \
    \  Value mid{fa * bb + fb * ba};\n        return Value{2}*fa*fb + (mid >> 30)\
    \ + ((mid & MASK30) << 31) + ba*bb;\n    }\n    static constexpr Value Mul(const\
    \ Value& a, const Value& b) noexcept {\n        return Modulo(UnsafeMul(a, b));\n\
    \    }\n};\n\n};\n#line 5 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\n#include\
    \ <random>\n#include <type_traits>\n\nnamespace zawa {\n\nstruct RollingHashMonoidData\
    \ {\n    using Value = Mersenne61ModInt::Value;\n    using Size = usize;\n   \
    \ static Value base;\n    Value hash{}, pow{1};\n    usize len{};\n\n    constexpr\
    \ RollingHashMonoidData() = default;\n    constexpr RollingHashMonoidData(Value\
    \ h, Value p, usize l) : hash{h}, pow{p}, len{l} {}\n    template <class T>\n\
    \    constexpr RollingHashMonoidData(const T& v) \n        : hash{static_cast<Value>(v)},\
    \ pow{base}, len{1} {}\n    // RollingHashMonoidData(const RollingHashMonoidData&\
    \ data)\n    //     : hash{data.hash}, pow{data.pow}, len{data.len} {}\n    \n\
    \    static Value randomValue(const Value& sigma) {\n        return std::mt19937{std::random_device{}()}()\
    \ % (Mersenne61ModInt::Mod() - sigma) + sigma + 1;\n    }\n\n    friend constexpr\
    \ bool operator==(const RollingHashMonoidData& lhs, const RollingHashMonoidData&\
    \ rhs) {\n        return lhs.hash == rhs.hash and lhs.len == rhs.len;\n    }\n\
    \    friend constexpr bool operator!=(const RollingHashMonoidData& lhs, const\
    \ RollingHashMonoidData& rhs) {\n        return lhs.hash != rhs.hash or lhs.len\
    \ != rhs.len;\n    }\n};\n\nstruct RollingHashMonoid {\n    using Modulo = Mersenne61ModInt;\n\
    \    using Element = RollingHashMonoidData;\n    static constexpr Element identity()\
    \ noexcept {\n        return Element{};\n    }\n    static constexpr Element operation(const\
    \ Element& lhs, const Element& rhs) noexcept {\n        return Element{\n    \
    \        Modulo::Modulo(Modulo::UnsafeMul(lhs.hash, rhs.pow) + rhs.hash),\n  \
    \          Modulo::Mul(lhs.pow, rhs.pow),\n            lhs.len + rhs.len\n   \
    \     };\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Number/Mersenne61ModInt.hpp\"\
    \n\n#include <random>\n#include <type_traits>\n\nnamespace zawa {\n\nstruct RollingHashMonoidData\
    \ {\n    using Value = Mersenne61ModInt::Value;\n    using Size = usize;\n   \
    \ static Value base;\n    Value hash{}, pow{1};\n    usize len{};\n\n    constexpr\
    \ RollingHashMonoidData() = default;\n    constexpr RollingHashMonoidData(Value\
    \ h, Value p, usize l) : hash{h}, pow{p}, len{l} {}\n    template <class T>\n\
    \    constexpr RollingHashMonoidData(const T& v) \n        : hash{static_cast<Value>(v)},\
    \ pow{base}, len{1} {}\n    // RollingHashMonoidData(const RollingHashMonoidData&\
    \ data)\n    //     : hash{data.hash}, pow{data.pow}, len{data.len} {}\n    \n\
    \    static Value randomValue(const Value& sigma) {\n        return std::mt19937{std::random_device{}()}()\
    \ % (Mersenne61ModInt::Mod() - sigma) + sigma + 1;\n    }\n\n    friend constexpr\
    \ bool operator==(const RollingHashMonoidData& lhs, const RollingHashMonoidData&\
    \ rhs) {\n        return lhs.hash == rhs.hash and lhs.len == rhs.len;\n    }\n\
    \    friend constexpr bool operator!=(const RollingHashMonoidData& lhs, const\
    \ RollingHashMonoidData& rhs) {\n        return lhs.hash != rhs.hash or lhs.len\
    \ != rhs.len;\n    }\n};\n\nstruct RollingHashMonoid {\n    using Modulo = Mersenne61ModInt;\n\
    \    using Element = RollingHashMonoidData;\n    static constexpr Element identity()\
    \ noexcept {\n        return Element{};\n    }\n    static constexpr Element operation(const\
    \ Element& lhs, const Element& rhs) noexcept {\n        return Element{\n    \
    \        Modulo::Modulo(Modulo::UnsafeMul(lhs.hash, rhs.pow) + rhs.hash),\n  \
    \          Modulo::Mul(lhs.pow, rhs.pow),\n            lhs.len + rhs.len\n   \
    \     };\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/Mersenne61ModInt.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/RollingHashMonoid.hpp
  requiredBy: []
  timestamp: '2024-12-06 16:40:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/0478.test.cpp
  - Test/Manual/aoj3548.test.cpp
  - Test/AtCoder/abc331_f.test.cpp
documentation_of: Src/Algebra/Monoid/RollingHashMonoid.hpp
layout: document
title: "\u30ED\u30EA\u30CF\u3092\u30BB\u30B0\u6728\u306B\u306E\u305B\u308B\u6642\u306E\
  \u30E2\u30CE\u30A4\u30C9"
---

# 概要

`RollingHashMonoidData`: セグ木に乗っているデータ

- staticメンバ関数`randomValue(Value sigma)` で`sigma+1 ~ MOD - 1`のランダムな値を生成します
- staticメンバ変数`base`を必ず初期化してください (RollingHashMonoidData::randomValueを使うのが一番無難な選択です)
- `operator==` `operator!=`が定義されています

`RollingHashMonoid`: 結合とかの関数が定義されている。
