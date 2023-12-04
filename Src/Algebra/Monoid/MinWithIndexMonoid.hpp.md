---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca.test.cpp
    title: Test/LC/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MinWithIndexMonoid.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/MinWithIndexMonoid.hpp\"\
    \n\n#include <limits>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass MinWithIndexMonoidData {\nprivate:\n    // CHECK!! LIMIT\n    T value_{std::numeric_limits<T>::max()};\n\
    \    usize index_{}; \npublic:\n    constexpr MinWithIndexMonoidData() {}\n  \
    \  constexpr MinWithIndexMonoidData(const T& value, usize index) : value_{value},\
    \ index_{index} {}\n\n    constexpr const T& value() const noexcept {\n      \
    \  return value_;\n    } \n    T& value() noexcept {\n        return value_;\n\
    \    }\n    constexpr const usize& index() const noexcept {\n        return index_;\n\
    \    }\n    usize& index() noexcept {\n        return index_;\n    }\n};\n\ntemplate\
    \ <class T>\nstruct MinWithIndexMonoid {\n    using Element = MinWithIndexMonoidData<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return Element{};\n\
    \    }\n    // CHECK!!! tie break\n    static constexpr Element operation(const\
    \ Element& lhs, const Element& rhs) noexcept {\n        return (rhs.value() <\
    \ lhs.value() ? rhs : lhs);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <limits>\n\
    #include <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass MinWithIndexMonoidData\
    \ {\nprivate:\n    // CHECK!! LIMIT\n    T value_{std::numeric_limits<T>::max()};\n\
    \    usize index_{}; \npublic:\n    constexpr MinWithIndexMonoidData() {}\n  \
    \  constexpr MinWithIndexMonoidData(const T& value, usize index) : value_{value},\
    \ index_{index} {}\n\n    constexpr const T& value() const noexcept {\n      \
    \  return value_;\n    } \n    T& value() noexcept {\n        return value_;\n\
    \    }\n    constexpr const usize& index() const noexcept {\n        return index_;\n\
    \    }\n    usize& index() noexcept {\n        return index_;\n    }\n};\n\ntemplate\
    \ <class T>\nstruct MinWithIndexMonoid {\n    using Element = MinWithIndexMonoidData<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return Element{};\n\
    \    }\n    // CHECK!!! tie break\n    static constexpr Element operation(const\
    \ Element& lhs, const Element& rhs) noexcept {\n        return (rhs.value() <\
    \ lhs.value() ? rhs : lhs);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/MinWithIndexMonoid.hpp
  requiredBy:
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  timestamp: '2023-12-05 01:06:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/lca.test.cpp
documentation_of: Src/Algebra/Monoid/MinWithIndexMonoid.hpp
layout: document
redirect_from:
- /library/Src/Algebra/Monoid/MinWithIndexMonoid.hpp
- /library/Src/Algebra/Monoid/MinWithIndexMonoid.hpp.html
title: Src/Algebra/Monoid/MinWithIndexMonoid.hpp
---
