---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/EnumerateQuotients.hpp
    title: "\u5546\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: Src/Number/IntegerDivision.hpp
    title: "\u6574\u6570\u540C\u58EB\u306E\u5207\u308A\u6368\u3066/\u5207\u308A\u4E0A\
      \u3052\u9664\u7B97"
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':question:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"Test/LC/enumerate_quotients.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Number/EnumerateQuotients.hpp\"\n\n#line 2 \"Src/Number/IntegerDivision.hpp\"\
    \n\n#include <type_traits>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nconstexpr T DivFloor(T a, T b) {\n    static_assert(std::is_integral_v<T>,\
    \ \"DivFloor argument must be Integer\");\n    assert(b != T{});\n    if constexpr\
    \ (std::is_unsigned_v<T>) {\n        return a / b;\n    }\n    else {\n      \
    \  if (b < 0) {\n            a *= -1;\n            b *= -1;\n        }\n     \
    \   return (a >= 0 ? a / b : (a - b + 1) / b);\n    }\n}\n\ntemplate <class T>\n\
    constexpr T DivCeil(T a, T b) {\n    static_assert(std::is_integral_v<T>, \"DivCeil\
    \ argument must be Integer\");\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>)\
    \ {\n        return (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n\
    \            a *= -1;\n            b *= -1;\n        }\n        return (a >= 0\
    \ ? (a + b - 1) / b : a / b);\n    }\n}\n\n} // namespace zawa\n#line 5 \"Src/Number/EnumerateQuotients.hpp\"\
    \n\n#line 7 \"Src/Number/EnumerateQuotients.hpp\"\n#include <vector>\n#include\
    \ <utility>\n#line 10 \"Src/Number/EnumerateQuotients.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class Value>\nclass EnumerateQuotients {\npublic:\n    class\
    \ Data {\n    private:\n        Value quotient_;\n        Value l_, r_;\n    public:\n\
    \        Data() = default;\n        constexpr Data(Value quotient, Value l, Value\
    \ r) : quotient_{ quotient }, l_{ l }, r_{ r } {\n            assert(l < r);\n\
    \        }\n        \n        constexpr Value quotient() const noexcept {\n  \
    \          return quotient_;\n        }\n\n        constexpr Value l() const noexcept\
    \ {\n            return l_;\n        }\n\n        constexpr Value r() const noexcept\
    \ {\n            return r_;\n        }\n\n        constexpr std::pair<Value, Value>\
    \ range() const noexcept {\n            return std::pair{ l_, r_ };\n        }\n\
    \n        constexpr Value len() const noexcept {\n            return r_ - l_;\n\
    \        }\n    };\n\nprivate:\n    std::vector<Data> seq_;\n    Value n_;\n\n\
    \    constexpr void templateTypeAssert() const noexcept {\n        static_assert(std::is_integral_v<Value>,\
    \ \"Template argument must be unsigned integer type.\");\n        static_assert(std::is_unsigned_v<Value>,\
    \ \"Template argument must be unsigned integer type.\");\n    }\n\n    constexpr\
    \ void floorBuild() noexcept {\n        Value l{1U};\n        while (l <= n_)\
    \ {\n            Value quotient{ DivFloor(n_, l) };\n            Value r{ DivFloor(n_,\
    \ quotient) + 1 };\n            seq_.emplace_back(quotient, l, r);\n         \
    \   l = r;\n        } \n    }\n\n    constexpr void ceilBuild() noexcept {\n \
    \       Value l{1U};\n        while (l < n_) {\n            Value quotient{ DivCeil(n_,\
    \ l) };\n            Value r{ DivCeil(n_, quotient - 1) };\n            seq_.emplace_back(quotient,\
    \ l, r);\n            l = r;\n        }\n        if (n_) {\n            seq_.emplace_back(1U,\
    \ n_, n_ + 1);\n        }\n    }\n\npublic:\n    constexpr EnumerateQuotients()\
    \ : seq_{}, n_{} {\n        templateTypeAssert();\n    }\n\n    constexpr EnumerateQuotients(Value\
    \ n, bool floor = true) : seq_{}, n_{ n } {\n        templateTypeAssert();\n \
    \       floor ? floorBuild() : ceilBuild();\n        seq_.shrink_to_fit();\n \
    \   }\n\n    constexpr Value n() const noexcept {\n        return n_;\n    }\n\
    \n    constexpr Data operator[](u32 i) const noexcept {\n        return seq_[i];\n\
    \    }\n\n    constexpr Value quotient(u32 i) const noexcept {\n        assert(i\
    \ < seq_.size()); \n        return seq_[i].quotient();\n    }\n\n    constexpr\
    \ Value l(u32 i) const noexcept {\n        assert(i < seq_.size()); \n       \
    \ return seq_[i].l();\n    }\n\n    constexpr Value r(u32 i) const noexcept {\n\
    \        assert(i < seq_.size()); \n        return seq_[i].r();\n    }\n\n   \
    \ constexpr std::pair<Value, Value> range(u32 i) const noexcept {\n        assert(i\
    \ < seq_.size());\n        return std::move(seq_[i].range());\n    }\n\n    constexpr\
    \ Value len(u32 i) const noexcept {\n        assert(i < seq_.size());\n      \
    \  return seq_[i].len();\n    }\n\n    constexpr usize size() const noexcept {\n\
    \        return seq_.size();\n    }\n\n    constexpr typename decltype(seq_)::const_iterator\
    \ begin() const noexcept {\n        return seq_.begin();\n    }\n\n    constexpr\
    \ typename decltype(seq_)::const_iterator end() const noexcept {\n        return\
    \ seq_.end();\n    }\n\n};\n\n} // namespace zawa\n#line 6 \"Test/LC/enumerate_quotients.test.cpp\"\
    \n\n#line 8 \"Test/LC/enumerate_quotients.test.cpp\"\n\nusing namespace zawa;\n\
    \nint main() {\n    SetFastIO(); \n    u64 N; std::cin >> N;\n    EnumerateQuotients\
    \ eq(N);\n    std::cout << eq.size() << std::endl;\n    for (i32 i{(i32)eq.size()\
    \ - 1} ; i >= 0 ; i--) {\n        std::cout << eq[i].quotient() << (i ? ' ' :\
    \ '\\n');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../Src/Number/EnumerateQuotients.hpp\"\n\n#include <iostream>\n\
    \nusing namespace zawa;\n\nint main() {\n    SetFastIO(); \n    u64 N; std::cin\
    \ >> N;\n    EnumerateQuotients eq(N);\n    std::cout << eq.size() << std::endl;\n\
    \    for (i32 i{(i32)eq.size() - 1} ; i >= 0 ; i--) {\n        std::cout << eq[i].quotient()\
    \ << (i ? ' ' : '\\n');\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/Number/EnumerateQuotients.hpp
  - Src/Number/IntegerDivision.hpp
  isVerificationFile: true
  path: Test/LC/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2023-08-14 01:40:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/enumerate_quotients.test.cpp
- /verify/Test/LC/enumerate_quotients.test.cpp.html
title: Test/LC/enumerate_quotients.test.cpp
---
