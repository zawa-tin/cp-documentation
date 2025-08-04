---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/2450.test.cpp
    title: Test/AOJ/2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3111.test.cpp
    title: Test/AOJ/3111.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/SubarraySumMaxMonoid.hpp\"\n\n#include\
    \ <algorithm>\n#include <concepts>\n#include <optional>\n\nnamespace zawa {\n\n\
    template <std::totally_ordered T>\nclass SubarraySumMax {\npublic:\n\n    SubarraySumMax()\
    \ = default;\n\n    explicit SubarraySumMax(T v) : m_ans{v}, m_sum{v}, m_pref{v},\
    \ m_suf{v}, m_entire{true} {}\n\n    SubarraySumMax(T ans, T sum, T pref, T suf,\
    \ bool entire) : m_ans{ans}, m_sum{sum}, m_pref{pref}, m_suf{suf}, m_entire{entire}\
    \ {}\n\n    inline T ans() const {\n        return m_ans;\n    }\n\n    inline\
    \ T sum() const {\n        return m_sum;\n    }\n\n    inline T pref() const {\n\
    \        return m_pref;\n    }\n\n    inline T suf() const {\n        return m_suf;\n\
    \    }\n\n    inline bool entire() const {\n        return m_entire;\n    }\n\n\
    \    static SubarraySumMax<T> merge(const SubarraySumMax<T>& lhs, const SubarraySumMax<T>&\
    \ rhs) {\n        T sum = lhs.sum() + rhs.sum();\n        T pref = std::max(lhs.pref(),\
    \ lhs.sum() + rhs.pref());\n        T suf = std::max(rhs.suf(), lhs.suf() + rhs.sum());\n\
    \        T ans = std::max({lhs.ans(), rhs.ans(), lhs.suf() + rhs.pref(), sum});\n\
    \        bool entire = (ans == sum);\n        return {ans, sum, pref, suf, entire};\n\
    \    }\n\nprivate:\n\n    T m_ans{}, m_sum{}, m_pref{}, m_suf{};\n\n    bool m_entire{};\n\
    };\n\ntemplate <std::totally_ordered T>\nstruct SubarraySumMaxMonoid {\n\n   \
    \ using Element = std::optional<SubarraySumMax<T>>;\n\n    static Element identity()\
    \ {\n        return std::nullopt;\n    }\n\n    static Element operation(const\
    \ Element& L, const Element& R) {\n        if (!L) return R;\n        if (!R)\
    \ return L;\n        return Element::value_type::merge(L.value(), R.value());\n\
    \    }\n\n    static Element convert(T v) {\n        return Element{v};\n    }\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <concepts>\n#include <optional>\n\
    \nnamespace zawa {\n\ntemplate <std::totally_ordered T>\nclass SubarraySumMax\
    \ {\npublic:\n\n    SubarraySumMax() = default;\n\n    explicit SubarraySumMax(T\
    \ v) : m_ans{v}, m_sum{v}, m_pref{v}, m_suf{v}, m_entire{true} {}\n\n    SubarraySumMax(T\
    \ ans, T sum, T pref, T suf, bool entire) : m_ans{ans}, m_sum{sum}, m_pref{pref},\
    \ m_suf{suf}, m_entire{entire} {}\n\n    inline T ans() const {\n        return\
    \ m_ans;\n    }\n\n    inline T sum() const {\n        return m_sum;\n    }\n\n\
    \    inline T pref() const {\n        return m_pref;\n    }\n\n    inline T suf()\
    \ const {\n        return m_suf;\n    }\n\n    inline bool entire() const {\n\
    \        return m_entire;\n    }\n\n    static SubarraySumMax<T> merge(const SubarraySumMax<T>&\
    \ lhs, const SubarraySumMax<T>& rhs) {\n        T sum = lhs.sum() + rhs.sum();\n\
    \        T pref = std::max(lhs.pref(), lhs.sum() + rhs.pref());\n        T suf\
    \ = std::max(rhs.suf(), lhs.suf() + rhs.sum());\n        T ans = std::max({lhs.ans(),\
    \ rhs.ans(), lhs.suf() + rhs.pref(), sum});\n        bool entire = (ans == sum);\n\
    \        return {ans, sum, pref, suf, entire};\n    }\n\nprivate:\n\n    T m_ans{},\
    \ m_sum{}, m_pref{}, m_suf{};\n\n    bool m_entire{};\n};\n\ntemplate <std::totally_ordered\
    \ T>\nstruct SubarraySumMaxMonoid {\n\n    using Element = std::optional<SubarraySumMax<T>>;\n\
    \n    static Element identity() {\n        return std::nullopt;\n    }\n\n   \
    \ static Element operation(const Element& L, const Element& R) {\n        if (!L)\
    \ return R;\n        if (!R) return L;\n        return Element::value_type::merge(L.value(),\
    \ R.value());\n    }\n\n    static Element convert(T v) {\n        return Element{v};\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/SubarraySumMaxMonoid.hpp
  requiredBy: []
  timestamp: '2025-08-04 20:15:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AOJ/3111.test.cpp
  - Test/AOJ/2450.test.cpp
documentation_of: Src/Algebra/Monoid/SubarraySumMaxMonoid.hpp
layout: document
title: "\u9023\u7D9A\u90E8\u5206\u5217\u306E\u7DCF\u548C\u306E\u6700\u5927\u3092\u7BA1\
  \u7406\u3059\u308B"
---

# 概要

**非空**な連続部分列であって総和が最大なものの総和を計算する

`std::optional`でデータを保持していて、空列に対応する値は`std::nullopt`である。

`SubarraySumMaxMonoid<T>::convert(T a)`というstaticメンバがあって、`T`型の値をこのモノイドの元に変換することができる。
