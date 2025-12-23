---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF923-D.test.cpp
    title: Test/CF/CF923-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/ChmaxMonoid.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/ChmaxMonoid.hpp\"\n\n#include\
    \ <algorithm>\n#include <optional>\n\nnamespace zawa {\n\ntemplate <class T, class\
    \ U>\nclass ChmaxMonoidData {\nprivate:\n    std::optional<T> priority_{};\n \
    \   U value_{};\npublic:\n    ChmaxMonoidData() = default;\n    ChmaxMonoidData(const\
    \ U& value)\n        : priority_{std::nullopt}, value_{value} {}\n    ChmaxMonoidData(const\
    \ T& priority, const U& value)\n        : priority_{priority}, value_{value} {}\n\
    \n    constexpr bool infty() const noexcept {\n        return !priority_.has_value();\n\
    \    }\n    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator>(const ChmaxMonoidData& l, const ChmaxMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() > r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChmaxMonoid {\n    using Element = ChmaxMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    static Element operation(const Element& l, const Element& r) noexcept\
    \ {\n        return (r > l ? r : l);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <optional>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nclass\
    \ ChmaxMonoidData {\nprivate:\n    std::optional<T> priority_{};\n    U value_{};\n\
    public:\n    ChmaxMonoidData() = default;\n    ChmaxMonoidData(const U& value)\n\
    \        : priority_{std::nullopt}, value_{value} {}\n    ChmaxMonoidData(const\
    \ T& priority, const U& value)\n        : priority_{priority}, value_{value} {}\n\
    \n    constexpr bool infty() const noexcept {\n        return !priority_.has_value();\n\
    \    }\n    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator>(const ChmaxMonoidData& l, const ChmaxMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() > r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChmaxMonoid {\n    using Element = ChmaxMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    static Element operation(const Element& l, const Element& r) noexcept\
    \ {\n        return (r > l ? r : l);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/ChmaxMonoid.hpp
  requiredBy: []
  timestamp: '2025-12-23 16:17:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF923-D.test.cpp
documentation_of: Src/Algebra/Monoid/ChmaxMonoid.hpp
layout: document
title: "chmax\u30E2\u30CE\u30A4\u30C9"
---

# 概要

タイブレークは $l$ 側を優先します。
