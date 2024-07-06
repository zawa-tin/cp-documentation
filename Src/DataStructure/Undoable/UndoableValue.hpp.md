---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc302_h.test.cpp
    title: Test/AtCoder/abc302_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Undoable/UndoableValue.hpp\"\n\n#include\
    \ <utility>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T>\nclass\
    \ UndoableValue {\npublic:\n\n    UndoableValue() = default;\n\n    UndoableValue(const\
    \ T& v) : v_{v} {}\n\n    UndoableValue(T&& v) : v_{std::move(v)} {}\n\n    void\
    \ assign(const T& v) {\n        save();\n        v_ = v;\n    }\n\n    void assign(T&&\
    \ v) {\n        save();\n        v_ = std::move(v);\n    }\n\n    const T& value()\
    \ const {\n        return v_;\n    }\n\n    void undo() {\n        assert(history_.size());\n\
    \        v_ = history_.back();\n        history_.pop_back();\n    }\n\nprivate:\n\
    \    T v_{};\n    std::vector<T> history_;\n\n    inline void save() {\n     \
    \   history_.emplace_back(v_);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\n\nnamespace zawa {\n\
    \ntemplate <class T>\nclass UndoableValue {\npublic:\n\n    UndoableValue() =\
    \ default;\n\n    UndoableValue(const T& v) : v_{v} {}\n\n    UndoableValue(T&&\
    \ v) : v_{std::move(v)} {}\n\n    void assign(const T& v) {\n        save();\n\
    \        v_ = v;\n    }\n\n    void assign(T&& v) {\n        save();\n       \
    \ v_ = std::move(v);\n    }\n\n    const T& value() const {\n        return v_;\n\
    \    }\n\n    void undo() {\n        assert(history_.size());\n        v_ = history_.back();\n\
    \        history_.pop_back();\n    }\n\nprivate:\n    T v_{};\n    std::vector<T>\
    \ history_;\n\n    inline void save() {\n        history_.emplace_back(v_);\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/DataStructure/Undoable/UndoableValue.hpp
  requiredBy: []
  timestamp: '2024-07-07 06:05:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc302_h.test.cpp
documentation_of: Src/DataStructure/Undoable/UndoableValue.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/Undoable/UndoableValue.hpp
- /library/Src/DataStructure/Undoable/UndoableValue.hpp.html
title: Src/DataStructure/Undoable/UndoableValue.hpp
---
