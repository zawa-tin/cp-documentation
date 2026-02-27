---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp
    title: Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc165_f.test.cpp
    title: Test/AtCoder/abc165_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc302_h.test.cpp
    title: Test/AtCoder/abc302_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Undoable/UndoableVector.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/Undoable/UndoableVector.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass UndoableVector {\npublic:\n    using Iterator\
    \ = typename std::vector<T>::const_iterator;\n\n    UndoableVector() = default;\n\
    \n    UndoableVector(usize n) : vec_(n) {}\n\n    UndoableVector(usize n, const\
    \ T& v) : vec_(n, v) {}\n\n    UndoableVector(const std::vector<T>& vec) : vec_{vec}\
    \ {}\n\n    UndoableVector(std::vector<T>&& vec) : vec_{std::move(vec)} {}\n \
    \   \n    inline usize size() const {\n        return vec_.size();\n    }\n\n\
    \    Iterator begin() const {\n        return vec_.begin();\n    }\n\n    Iterator\
    \ end() const {\n        return vec_.end();\n    }\n\n    void assign(usize i,\
    \ const T& v) {\n        assert(i < size());\n        save(i);\n        vec_[i]\
    \ = v;\n    }\n\n    T operator[](usize i) const {\n        assert(i < size());\n\
    \        return vec_[i];\n    }\n\n    void undo() {\n        assert(history_.size());\n\
    \        auto [i, v]{history_.back()};\n        vec_[i] = v;\n        history_.pop_back();\n\
    \    }\n\nprivate:\n    std::vector<T> vec_; \n    std::vector<std::pair<usize,\
    \ T>> history_;\n\n    void save(usize i) {\n        history_.emplace_back(i,\
    \ vec_[i]);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\n\
    class UndoableVector {\npublic:\n    using Iterator = typename std::vector<T>::const_iterator;\n\
    \n    UndoableVector() = default;\n\n    UndoableVector(usize n) : vec_(n) {}\n\
    \n    UndoableVector(usize n, const T& v) : vec_(n, v) {}\n\n    UndoableVector(const\
    \ std::vector<T>& vec) : vec_{vec} {}\n\n    UndoableVector(std::vector<T>&& vec)\
    \ : vec_{std::move(vec)} {}\n    \n    inline usize size() const {\n        return\
    \ vec_.size();\n    }\n\n    Iterator begin() const {\n        return vec_.begin();\n\
    \    }\n\n    Iterator end() const {\n        return vec_.end();\n    }\n\n  \
    \  void assign(usize i, const T& v) {\n        assert(i < size());\n        save(i);\n\
    \        vec_[i] = v;\n    }\n\n    T operator[](usize i) const {\n        assert(i\
    \ < size());\n        return vec_[i];\n    }\n\n    void undo() {\n        assert(history_.size());\n\
    \        auto [i, v]{history_.back()};\n        vec_[i] = v;\n        history_.pop_back();\n\
    \    }\n\nprivate:\n    std::vector<T> vec_; \n    std::vector<std::pair<usize,\
    \ T>> history_;\n\n    void save(usize i) {\n        history_.emplace_back(i,\
    \ vec_[i]);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/Undoable/UndoableVector.hpp
  requiredBy:
  - Src/DataStructure/DisjointSetUnion/UndoableDisjointSetUnion.hpp
  timestamp: '2024-07-07 06:05:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc165_f.test.cpp
  - Test/AtCoder/abc302_h.test.cpp
documentation_of: Src/DataStructure/Undoable/UndoableVector.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/Undoable/UndoableVector.hpp
- /library/Src/DataStructure/Undoable/UndoableVector.hpp.html
title: Src/DataStructure/Undoable/UndoableVector.hpp
---
