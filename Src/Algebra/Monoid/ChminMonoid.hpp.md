---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/AuxiliaryTree.hpp
    title: "Auxiliary Tree (\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\
      \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\
      \u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc340_g.test.cpp
    title: Test/AtCoder/abc340_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc359_g.test.cpp
    title: ABC359-G Sum of Tree Distance
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF923-D.test.cpp
    title: Test/CF/CF923-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca/LowestCommonAncestor.test.cpp
    title: Test/LC/lca/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/typical90_ai.test.cpp
    title: Test/Manual/typical90_ai.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/My/Graph/Tree/LowestCommonAncestor.test.cpp
    title: Test/My/Graph/Tree/LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\n\n#include\
    \ <algorithm>\n#include <optional>\n\nnamespace zawa {\n\ntemplate <class T, class\
    \ U>\nclass ChminMonoidData {\nprivate:\n    std::optional<T> priority_{};\n \
    \   U value_{};\npublic:\n    ChminMonoidData() = default;\n    ChminMonoidData(const\
    \ U& value)\n        : priority_{std::nullopt}, value_{value} {}\n    ChminMonoidData(const\
    \ T& priority, const U& value)\n        : priority_{priority}, value_{value} {}\n\
    \n    constexpr bool infty() const noexcept {\n        return !priority_.has_value();\n\
    \    }\n    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator<(const ChminMonoidData& l, const ChminMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() < r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChminMonoid {\n    using Element = ChminMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    static Element operation(const Element& l, const Element& r) noexcept\
    \ {\n        return (r < l ? r : l);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <optional>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nclass\
    \ ChminMonoidData {\nprivate:\n    std::optional<T> priority_{};\n    U value_{};\n\
    public:\n    ChminMonoidData() = default;\n    ChminMonoidData(const U& value)\n\
    \        : priority_{std::nullopt}, value_{value} {}\n    ChminMonoidData(const\
    \ T& priority, const U& value)\n        : priority_{priority}, value_{value} {}\n\
    \n    constexpr bool infty() const noexcept {\n        return !priority_.has_value();\n\
    \    }\n    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator<(const ChminMonoidData& l, const ChminMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() < r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChminMonoid {\n    using Element = ChminMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    static Element operation(const Element& l, const Element& r) noexcept\
    \ {\n        return (r < l ? r : l);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/ChminMonoid.hpp
  requiredBy:
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Graph/Tree/AuxiliaryTree.hpp
  timestamp: '2025-12-23 16:17:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/Manual/typical90_ai.test.cpp
  - Test/AtCoder/abc359_g.test.cpp
  - Test/AtCoder/abc340_g.test.cpp
  - Test/LC/lca/LowestCommonAncestor.test.cpp
  - Test/My/Graph/Tree/LowestCommonAncestor.test.cpp
  - Test/CF/CF923-D.test.cpp
documentation_of: Src/Algebra/Monoid/ChminMonoid.hpp
layout: document
title: "chmin\u30E2\u30CE\u30A4\u30C9"
---

# 概要

タイブレークは $l$ 側を優先します。
