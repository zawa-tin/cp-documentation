---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/frequency_table_of_tree_distance.test.cpp
    title: Test/LC/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/abc291_h.test.cpp
    title: Test/Manual/abc291_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/yahoo_procon2018_final_c.test.cpp
    title: Test/Manual/yahoo_procon2018_final_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/Centroid.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Centroid.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class V>\n\
    class Centroid {\npublic:\n\n    Centroid() = default;\n\n    Centroid(const std::vector<std::vector<V>>&\
    \ T) : T_{T}, size_(T_.size(), usize{1}) {}\n    Centroid(std::vector<std::vector<V>>&&\
    \ T) : T_{std::move(T)}, size_(T_.size(), usize{1}) {}\n\n    inline usize size()\
    \ const noexcept {\n        return T_.size();\n    }\n\n    inline usize size(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return size_[v];\n\
    \    }\n\n    bool isRemoved(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return size_[v] == 0u;\n    }\n\n    void remove(V v) noexcept {\n  \
    \      assert(v < (V)size());\n        size_[v] = 0u;\n    }\n\n    const std::vector<V>&\
    \ operator[](V v) const noexcept {\n        assert(v < (V)size());\n        return\
    \ T_[v];\n    }\n\n    // @response: centroid of component which v belongs\n \
    \   V rooting(V v) {\n        assert(v < (V)size());\n        assert(!isRemoved(v));\n\
    \        usize all{dfsSize(v, INVALID)};\n        V par{INVALID};\n        bool\
    \ fn{false};\n        while (!fn) {\n            fn = true;\n            for (V\
    \ x : T_[v]) {\n                if (x == par or isRemoved(x) or usize{2} * size_[x]\
    \ <= all) {\n                    continue;\n                }\n              \
    \  fn = false;\n                par = v;\n                v = x;\n           \
    \     break;\n            }\n        }\n        return v;\n    }\n\n    std::vector<V>\
    \ component(V v) const {\n        assert(v < (V)size());\n        assert(!isRemoved(v));\n\
    \        std::vector<V> res;\n        dfsComponent(v, INVALID, res);\n       \
    \ return res;\n    }\n\n    std::vector<V> adjlist(V v) const {\n        assert(v\
    \ < (V)size());\n        std::vector<V> res;\n        res.reserve(T_[v].size());\n\
    \        for (auto x : T_[v]) if (!isRemoved(x)) {\n            res.emplace_back(x);\n\
    \        }\n        return res;\n    }\n\nprivate:\n    static constexpr V INVALID{static_cast<V>(-1)};\n\
    \    std::vector<std::vector<V>> T_{};\n    std::vector<usize> size_{};\n\n  \
    \  usize dfsSize(V v, V par) {\n        size_[v] = 1u;\n        for (V x : T_[v])\
    \ if (x != par and !isRemoved(x)) {\n            size_[v] += dfsSize(x, v);\n\
    \        }\n        return size_[v];\n    }\n\n    void dfsComponent(V v, V par,\
    \ std::vector<V>& comp) const {\n        comp.emplace_back(v);\n        for (V\
    \ x : T_[v]) if (x != par and !isRemoved(x)) {\n            dfsComponent(x, v,\
    \ comp);\n        }\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class V>\n\
    class Centroid {\npublic:\n\n    Centroid() = default;\n\n    Centroid(const std::vector<std::vector<V>>&\
    \ T) : T_{T}, size_(T_.size(), usize{1}) {}\n    Centroid(std::vector<std::vector<V>>&&\
    \ T) : T_{std::move(T)}, size_(T_.size(), usize{1}) {}\n\n    inline usize size()\
    \ const noexcept {\n        return T_.size();\n    }\n\n    inline usize size(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return size_[v];\n\
    \    }\n\n    bool isRemoved(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return size_[v] == 0u;\n    }\n\n    void remove(V v) noexcept {\n  \
    \      assert(v < (V)size());\n        size_[v] = 0u;\n    }\n\n    const std::vector<V>&\
    \ operator[](V v) const noexcept {\n        assert(v < (V)size());\n        return\
    \ T_[v];\n    }\n\n    // @response: centroid of component which v belongs\n \
    \   V rooting(V v) {\n        assert(v < (V)size());\n        assert(!isRemoved(v));\n\
    \        usize all{dfsSize(v, INVALID)};\n        V par{INVALID};\n        bool\
    \ fn{false};\n        while (!fn) {\n            fn = true;\n            for (V\
    \ x : T_[v]) {\n                if (x == par or isRemoved(x) or usize{2} * size_[x]\
    \ <= all) {\n                    continue;\n                }\n              \
    \  fn = false;\n                par = v;\n                v = x;\n           \
    \     break;\n            }\n        }\n        return v;\n    }\n\n    std::vector<V>\
    \ component(V v) const {\n        assert(v < (V)size());\n        assert(!isRemoved(v));\n\
    \        std::vector<V> res;\n        dfsComponent(v, INVALID, res);\n       \
    \ return res;\n    }\n\n    std::vector<V> adjlist(V v) const {\n        assert(v\
    \ < (V)size());\n        std::vector<V> res;\n        res.reserve(T_[v].size());\n\
    \        for (auto x : T_[v]) if (!isRemoved(x)) {\n            res.emplace_back(x);\n\
    \        }\n        return res;\n    }\n\nprivate:\n    static constexpr V INVALID{static_cast<V>(-1)};\n\
    \    std::vector<std::vector<V>> T_{};\n    std::vector<usize> size_{};\n\n  \
    \  usize dfsSize(V v, V par) {\n        size_[v] = 1u;\n        for (V x : T_[v])\
    \ if (x != par and !isRemoved(x)) {\n            size_[v] += dfsSize(x, v);\n\
    \        }\n        return size_[v];\n    }\n\n    void dfsComponent(V v, V par,\
    \ std::vector<V>& comp) const {\n        comp.emplace_back(v);\n        for (V\
    \ x : T_[v]) if (x != par and !isRemoved(x)) {\n            dfsComponent(x, v,\
    \ comp);\n        }\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/Centroid.hpp
  requiredBy: []
  timestamp: '2024-12-06 16:40:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/frequency_table_of_tree_distance.test.cpp
  - Test/Manual/abc291_h.test.cpp
  - Test/Manual/yahoo_procon2018_final_c.test.cpp
documentation_of: Src/Graph/Tree/Centroid.hpp
layout: document
title: "\u6728\u306E\u91CD\u5FC3"
---

## 概要

森に対して

- 指定された頂点を含む連結成分の重心を求める
- 頂点を削除する

といったことができます。

## ライブラリの使い方
