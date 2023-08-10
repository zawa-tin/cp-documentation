---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Number/EnumerateQuotients.hpp
    title: "\u5546\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Number/EnumerateQuotients.hpp\"\
    \n\n#line 4 \"Src/Number/EnumerateQuotients.hpp\"\n\n#include <type_traits>\n\
    #include <vector>\n#include <utility>\n#include <cassert>\n\nnamespace zawa {\n\
    \ntemplate <class Value>\nclass EnumerateQuotients {\npublic:\n    class Data\
    \ {\n    private:\n        Value quotient_;\n        Value l_, r_;\n    public:\n\
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
    \ {\n            Value quotient{ n_ / l };\n            Value r{ n_ / quotient\
    \ + 1 };\n            seq_.emplace_back(quotient, l, r);\n            l = r;\n\
    \        } \n    }\n\n    constexpr void ceilBuild() noexcept {\n        Value\
    \ l{1U};\n        while (l < n_) {\n            Value quotient{ (n_ + l - 1) /\
    \ l };\n            Value r{ (n_ + quotient - 2) / (quotient - 1) };\n       \
    \     seq_.emplace_back(quotient, l, r);\n            l = r;\n        }\n    \
    \    seq_.emplace_back(1U, n_, n_ + 1);\n    }\n\npublic:\n    constexpr EnumerateQuotients()\
    \ : seq_{}, n_{} {\n        templateTypeAssert();\n    }\n\n    constexpr EnumerateQuotients(Value\
    \ n, bool floor = true) : seq_{}, n_{ n } {\n        templateTypeAssert();\n \
    \       floor ? floorBuild() : ceilBuild();\n    }\n\n    constexpr Value n()\
    \ const noexcept {\n        return n_;\n    }\n\n    constexpr Data operator[](u32\
    \ i) const noexcept {\n        return seq_[i];\n    }\n\n    constexpr Value quotient(u32\
    \ i) const noexcept {\n        assert(i < seq_.size()); \n        return seq_[i].quotient();\n\
    \    }\n\n    constexpr Value l(u32 i) const noexcept {\n        assert(i < seq_.size());\
    \ \n        return seq_[i].l();\n    }\n\n    constexpr Value r(u32 i) const noexcept\
    \ {\n        assert(i < seq_.size()); \n        return seq_[i].r();\n    }\n\n\
    \    constexpr std::pair<Value, Value> range(u32 i) const noexcept {\n       \
    \ assert(i < seq_.size());\n        return std::move(seq_[i].range());\n    }\n\
    \n    constexpr Value len(u32 i) const noexcept {\n        assert(i < seq_.size());\n\
    \        return seq_[i].len();\n    }\n\n    constexpr usize size() const noexcept\
    \ {\n        return seq_.size();\n    }\n\n    constexpr typename decltype(seq_)::const_iterator\
    \ begin() const noexcept {\n        return seq_.begin();\n    }\n\n    constexpr\
    \ typename decltype(seq_)::const_iterator end() const noexcept {\n        return\
    \ seq_.end();\n    }\n\n};\n\n} // namespace zawa\n#line 5 \"Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp\"\
    \n\n#line 7 \"Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp\"\n#include\
    \ <iostream>\n\nusing namespace zawa;\n\nint main() {\n    EnumerateQuotients\
    \ q(100u, false);\n    for (const auto& dat : q) {\n        std::cerr << '[' <<\
    \ dat.l() << ',' << dat.r() << \") : \" << dat.quotient() << std::endl;\n    \
    \    for (u32 i{dat.l()} ; i < dat.r() ; i++) {\n            assert(i * dat.quotient()\
    \ >= q.n());\n            assert(i * (dat.quotient() - 1) < q.n());\n        }\n\
    \    }\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../../../Src/Template/TypeAlias.hpp\"\n#include \"../../../../Src/Number/EnumerateQuotients.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n\nusing namespace zawa;\n\nint main()\
    \ {\n    EnumerateQuotients q(100u, false);\n    for (const auto& dat : q) {\n\
    \        std::cerr << '[' << dat.l() << ',' << dat.r() << \") : \" << dat.quotient()\
    \ << std::endl;\n        for (u32 i{dat.l()} ; i < dat.r() ; i++) {\n        \
    \    assert(i * dat.quotient() >= q.n());\n            assert(i * (dat.quotient()\
    \ - 1) < q.n());\n        }\n    }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/EnumerateQuotients.hpp
  isVerificationFile: true
  path: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 16:50:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
layout: document
redirect_from:
- /verify/Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
- /verify/Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp.html
title: Test/My/Number/EnumerateQuotients/ceilBuild.test.cpp
---
