---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc238_c.test.cpp
    title: Test/AtCoder/abc238_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc247_f.test.cpp
    title: Test/AtCoder/abc247_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc276_f.test.cpp
    title: Test/AtCoder/abc276_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc307_e.test.cpp
    title: Test/AtCoder/abc307_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_range_composite.test.cpp
    title: Test/LC/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_point_get.test.cpp
    title: Test/LC/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/range_affine_range_sum.test.cpp
    title: Test/LC/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/ModInt.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/ModInt.hpp\"\n\n#include <type_traits>\n\
    #include <iostream>\n#include <utility>\n#include <cassert>\n\nnamespace zawa\
    \ {\n\ntemplate <class T, T mod>\nclass StaticModInt {\nprivate:\n    using mint\
    \ = StaticModInt;\n\n    T v_{};\n\n    static constexpr void templateTypeAssert()\
    \ {\n        static_assert(std::is_integral_v<T>, \"ModInt template argument must\
    \ be integral\");\n        static_assert(mod > 0, \"mod must be positive\");\n\
    \    }\n\n    i64 extendGCD(i64 a, i64 b, i64& x, i64& y) const {\n       i64\
    \ d{a};\n       if (b) {\n           d = extendGCD(b, a % b, y, x);\n        \
    \   y -= (a / b) * x;\n       }\n       else {\n           x = 1;\n          \
    \ y = 0;\n       }\n       return d;\n    }\n\npublic:\n\n    constexpr StaticModInt()\
    \ {\n        templateTypeAssert();\n    }\n    template <class ArgType>\n    constexpr\
    \ StaticModInt(ArgType v) : v_{ static_cast<T>(((v % mod) + mod) % mod) } {\n\
    \        templateTypeAssert();\n        static_assert(std::is_integral_v<ArgType>,\
    \ \"ModInt constructor Argument Must Be Integral\");\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& value) {\n        is >> value.v_;\n     \
    \   return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ mint& value) {\n        os << value.v_;\n        return os;\n    }\n\n    T\
    \ v() const {\n        return v_;\n    }\n\n    bool operator==(const mint& rhs)\
    \ const {\n        return v_ == rhs.v_;\n    }\n\n    mint operator+() const {\n\
    \        return *this;\n    }\n    mint& operator+=(const mint& rhs) {\n     \
    \   v_ = (v_ < mod - rhs.v_ ? v_ + rhs.v_ : v_ + rhs.v_ - mod);\n        return\
    \ *this;\n    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n\
    \        return mint{lhs} += rhs;\n    }\n    mint& operator++() {\n        v_\
    \ = (v_ + 1 == mod ? 0 : v_ + 1);\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint res{*this};\n        ++*this;\n        return res;\n    }\n\n\
    \    mint operator-() const {\n        return mod - v_;\n    }\n    mint& operator-=(const\
    \ mint& rhs) {\n        v_ = (v_ >= rhs.v_ ? v_ - rhs.v_ : v_ + (mod - rhs.v_));\n\
    \        return *this;\n    }\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) {\n        return mint{lhs} -= rhs;\n    }\n    mint& operator--()\
    \ {\n        v_ = (v_ ? v_ - 1 : mod - 1);\n        return *this;\n    }\n   \
    \ mint operator--(int) {\n        mint res{*this};\n        --*this;\n       \
    \ return res;\n    }\n\n    mint& operator*=(const mint& rhs) {\n        u64 mult{\
    \ static_cast<u64>(v_) * static_cast<u64>(rhs.v_) };\n        v_ = static_cast<T>(mult\
    \ % mod);\n        return *this;\n    }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) {\n        return mint{lhs} *= rhs;\n    }\n\n    mint\
    \ inverse() const {\n        i64 res{}, hoge{};\n        assert(extendGCD(static_cast<i64>(v_),\
    \ static_cast<i64>(mod), res, hoge) == 1);\n        return mint{res};\n    }\n\
    \    mint& operator/=(const mint& rhs) {\n        return *this *= rhs.inverse();\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint{lhs} /= rhs;\n    }\n\n    mint pow(u64 k) const {\n        mint\
    \ res{1}, base{k};\n        while (k) {\n            if (k & 1) res *= base;\n\
    \            base *= base; \n            k >>= 1;\n        }\n        return res;\n\
    \    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <type_traits>\n\
    #include <iostream>\n#include <utility>\n#include <cassert>\n\nnamespace zawa\
    \ {\n\ntemplate <class T, T mod>\nclass StaticModInt {\nprivate:\n    using mint\
    \ = StaticModInt;\n\n    T v_{};\n\n    static constexpr void templateTypeAssert()\
    \ {\n        static_assert(std::is_integral_v<T>, \"ModInt template argument must\
    \ be integral\");\n        static_assert(mod > 0, \"mod must be positive\");\n\
    \    }\n\n    i64 extendGCD(i64 a, i64 b, i64& x, i64& y) const {\n       i64\
    \ d{a};\n       if (b) {\n           d = extendGCD(b, a % b, y, x);\n        \
    \   y -= (a / b) * x;\n       }\n       else {\n           x = 1;\n          \
    \ y = 0;\n       }\n       return d;\n    }\n\npublic:\n\n    constexpr StaticModInt()\
    \ {\n        templateTypeAssert();\n    }\n    template <class ArgType>\n    constexpr\
    \ StaticModInt(ArgType v) : v_{ static_cast<T>(((v % mod) + mod) % mod) } {\n\
    \        templateTypeAssert();\n        static_assert(std::is_integral_v<ArgType>,\
    \ \"ModInt constructor Argument Must Be Integral\");\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& value) {\n        is >> value.v_;\n     \
    \   return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ mint& value) {\n        os << value.v_;\n        return os;\n    }\n\n    T\
    \ v() const {\n        return v_;\n    }\n\n    bool operator==(const mint& rhs)\
    \ const {\n        return v_ == rhs.v_;\n    }\n\n    mint operator+() const {\n\
    \        return *this;\n    }\n    mint& operator+=(const mint& rhs) {\n     \
    \   v_ = (v_ < mod - rhs.v_ ? v_ + rhs.v_ : v_ + rhs.v_ - mod);\n        return\
    \ *this;\n    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n\
    \        return mint{lhs} += rhs;\n    }\n    mint& operator++() {\n        v_\
    \ = (v_ + 1 == mod ? 0 : v_ + 1);\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint res{*this};\n        ++*this;\n        return res;\n    }\n\n\
    \    mint operator-() const {\n        return mod - v_;\n    }\n    mint& operator-=(const\
    \ mint& rhs) {\n        v_ = (v_ >= rhs.v_ ? v_ - rhs.v_ : v_ + (mod - rhs.v_));\n\
    \        return *this;\n    }\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) {\n        return mint{lhs} -= rhs;\n    }\n    mint& operator--()\
    \ {\n        v_ = (v_ ? v_ - 1 : mod - 1);\n        return *this;\n    }\n   \
    \ mint operator--(int) {\n        mint res{*this};\n        --*this;\n       \
    \ return res;\n    }\n\n    mint& operator*=(const mint& rhs) {\n        u64 mult{\
    \ static_cast<u64>(v_) * static_cast<u64>(rhs.v_) };\n        v_ = static_cast<T>(mult\
    \ % mod);\n        return *this;\n    }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) {\n        return mint{lhs} *= rhs;\n    }\n\n    mint\
    \ inverse() const {\n        i64 res{}, hoge{};\n        assert(extendGCD(static_cast<i64>(v_),\
    \ static_cast<i64>(mod), res, hoge) == 1);\n        return mint{res};\n    }\n\
    \    mint& operator/=(const mint& rhs) {\n        return *this *= rhs.inverse();\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint{lhs} /= rhs;\n    }\n\n    mint pow(u64 k) const {\n        mint\
    \ res{1}, base{k};\n        while (k) {\n            if (k & 1) res *= base;\n\
    \            base *= base; \n            k >>= 1;\n        }\n        return res;\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/ModInt.hpp
  requiredBy: []
  timestamp: '2023-09-28 07:12:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/range_affine_point_get.test.cpp
  - Test/LC/point_set_range_composite.test.cpp
  - Test/LC/range_affine_range_sum.test.cpp
  - Test/AtCoder/abc247_f.test.cpp
  - Test/AtCoder/abc276_f.test.cpp
  - Test/AtCoder/abc307_e.test.cpp
  - Test/AtCoder/abc238_c.test.cpp
documentation_of: Src/Number/ModInt.hpp
layout: document
redirect_from:
- /library/Src/Number/ModInt.hpp
- /library/Src/Number/ModInt.hpp.html
title: Src/Number/ModInt.hpp
---
