---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/EnumerateStaticLengthProduct.hpp
    title: Src/Sequence/EnumerateStaticLengthProduct.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/queue_operate_all_composite.test.cpp
    title: Test/LC/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3548.test.cpp
    title: AOJ3548 String Puzzle
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SWAG/SWAG.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/SWAG/SWAG.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class S>\nclass\
    \ SlidingWindowAggregation {\npublic:\n    using V = typename S::Element;\n\n\
    \    SlidingWindowAggregation() = default;\n\n    usize size() const noexcept\
    \ {\n        return front_.size() + back_.size();\n    }\n\n    bool empty() const\
    \ noexcept {\n        return size() == 0u;\n    }\n\n    void push(const V& v)\
    \ {\n        raw_.push_back(v);\n        back_.push_back(back_.size() ? S::operation(back_.back(),\
    \ v) : v);\n    }\n\n    void pop() {\n        assert(size());\n        move();\n\
    \        front_.pop_back();\n    }\n\n    V product() {\n        assert(size());\n\
    \        if (front_.empty()) return back_.back();\n        if (back_.empty())\
    \ return front_.back();\n        return S::operation(front_.back(), back_.back());\n\
    \    }\n    \nprivate:\n    std::vector<V> front_{}, back_{};\n    std::vector<V>\
    \ raw_{};\n\n    void move() {\n        if (front_.empty()) {\n            while\
    \ (back_.size()) {\n                back_.pop_back();\n                V v{raw_.back()};\n\
    \                raw_.pop_back();\n                front_.push_back(front_.size()\
    \ ? S::operation(v, front_.back()) : v);\n            }\n        }\n    }\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <class S>\nclass SlidingWindowAggregation\
    \ {\npublic:\n    using V = typename S::Element;\n\n    SlidingWindowAggregation()\
    \ = default;\n\n    usize size() const noexcept {\n        return front_.size()\
    \ + back_.size();\n    }\n\n    bool empty() const noexcept {\n        return\
    \ size() == 0u;\n    }\n\n    void push(const V& v) {\n        raw_.push_back(v);\n\
    \        back_.push_back(back_.size() ? S::operation(back_.back(), v) : v);\n\
    \    }\n\n    void pop() {\n        assert(size());\n        move();\n       \
    \ front_.pop_back();\n    }\n\n    V product() {\n        assert(size());\n  \
    \      if (front_.empty()) return back_.back();\n        if (back_.empty()) return\
    \ front_.back();\n        return S::operation(front_.back(), back_.back());\n\
    \    }\n    \nprivate:\n    std::vector<V> front_{}, back_{};\n    std::vector<V>\
    \ raw_{};\n\n    void move() {\n        if (front_.empty()) {\n            while\
    \ (back_.size()) {\n                back_.pop_back();\n                V v{raw_.back()};\n\
    \                raw_.pop_back();\n                front_.push_back(front_.size()\
    \ ? S::operation(v, front_.back()) : v);\n            }\n        }\n    }\n};\n\
    \n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/SWAG/SWAG.hpp
  requiredBy:
  - Src/Sequence/EnumerateStaticLengthProduct.hpp
  timestamp: '2024-07-15 23:06:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/queue_operate_all_composite.test.cpp
  - Test/Manual/aoj3548.test.cpp
documentation_of: Src/DataStructure/SWAG/SWAG.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/SWAG/SWAG.hpp
- /library/Src/DataStructure/SWAG/SWAG.hpp.html
title: Src/DataStructure/SWAG/SWAG.hpp
---
