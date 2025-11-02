---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc430_g.test.cpp
    title: Test/AtCoder/abc430_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Other/RangeAssigner.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <utility>\n#include\
    \ <map>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral Z, class\
    \ T>\nclass RangeAssigner {\npublic:\n\n    RangeAssigner() = default;\n\n   \
    \ RangeAssigner(Z n, T init)\n        : m_min{0}, m_max{n} {\n        m_mp[0]\
    \ = {n, init};\n    }\n\n    RangeAssigner(Z min, Z max, T init) \n        : m_min{min},\
    \ m_max{max} {\n        assert(min <= max);\n        m_mp[m_min] = {max, init};\n\
    \    }\n\n    std::vector<std::tuple<Z, Z, T>> operator()(Z l, Z r) const {\n\
    \        assert(m_min <= l and l <= r and r <= m_max);\n        std::vector<std::tuple<Z,\
    \ Z, T>> res;\n        for (auto it = prev(m_mp.upper_bound(l)) ; it != m_mp.end()\
    \ and it->first < r ; it++)\n            res.emplace_back(std::max(it->first,\
    \ l), std::min(it->second.first, r), it->second.second);\n        return res;\n\
    \    }\n\n    std::vector<std::tuple<Z, Z, T>> assign(Z l, Z r, T v) {\n     \
    \   assert(m_min <= l and l <= r and r <= m_max);\n        std::vector<std::tuple<Z,\
    \ Z, T>> res;\n        {\n            auto it = prev(m_mp.upper_bound(l));\n \
    \           const Z L = it->first, R = it->second.first;\n            const T\
    \ V = it->second.second;\n            it->second.first = L;\n            m_mp.erase(it);\n\
    \            if (L < l)\n                m_mp[L] = {l, V};\n            res.emplace_back(l,\
    \ std::min(r, R), V);\n            if (r < R)\n                m_mp[r] = {R, V};\n\
    \            if (r <= R) {\n                m_mp[l] = {r, v};\n              \
    \  return res;\n            }\n        }\n        auto it = m_mp.upper_bound(l);\n\
    \        for ( ; it != m_mp.end() and it->second.first <= r ; it = m_mp.erase(it))\n\
    \            res.emplace_back(it->first, it->second.first, it->second.second);\n\
    \        if (it != m_mp.end() and r < it->second.first) {\n            const Z\
    \ L = it->first, R = it->second.first;\n            const T V = it->second.second;\n\
    \            it = m_mp.erase(it);\n            res.emplace_back(L, r, V);\n  \
    \          m_mp[r] = {R, V};\n        }\n        m_mp[l] = {r, v};\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::map<Z, std::pair<Z, T>> m_mp;\n\n    Z m_min,\
    \ m_max;\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <concepts>\n\
    #include <utility>\n#include <map>\n#include <vector>\n\nnamespace zawa {\n\n\
    template <std::integral Z, class T>\nclass RangeAssigner {\npublic:\n\n    RangeAssigner()\
    \ = default;\n\n    RangeAssigner(Z n, T init)\n        : m_min{0}, m_max{n} {\n\
    \        m_mp[0] = {n, init};\n    }\n\n    RangeAssigner(Z min, Z max, T init)\
    \ \n        : m_min{min}, m_max{max} {\n        assert(min <= max);\n        m_mp[m_min]\
    \ = {max, init};\n    }\n\n    std::vector<std::tuple<Z, Z, T>> operator()(Z l,\
    \ Z r) const {\n        assert(m_min <= l and l <= r and r <= m_max);\n      \
    \  std::vector<std::tuple<Z, Z, T>> res;\n        for (auto it = prev(m_mp.upper_bound(l))\
    \ ; it != m_mp.end() and it->first < r ; it++)\n            res.emplace_back(std::max(it->first,\
    \ l), std::min(it->second.first, r), it->second.second);\n        return res;\n\
    \    }\n\n    std::vector<std::tuple<Z, Z, T>> assign(Z l, Z r, T v) {\n     \
    \   assert(m_min <= l and l <= r and r <= m_max);\n        std::vector<std::tuple<Z,\
    \ Z, T>> res;\n        {\n            auto it = prev(m_mp.upper_bound(l));\n \
    \           const Z L = it->first, R = it->second.first;\n            const T\
    \ V = it->second.second;\n            it->second.first = L;\n            m_mp.erase(it);\n\
    \            if (L < l)\n                m_mp[L] = {l, V};\n            res.emplace_back(l,\
    \ std::min(r, R), V);\n            if (r < R)\n                m_mp[r] = {R, V};\n\
    \            if (r <= R) {\n                m_mp[l] = {r, v};\n              \
    \  return res;\n            }\n        }\n        auto it = m_mp.upper_bound(l);\n\
    \        for ( ; it != m_mp.end() and it->second.first <= r ; it = m_mp.erase(it))\n\
    \            res.emplace_back(it->first, it->second.first, it->second.second);\n\
    \        if (it != m_mp.end() and r < it->second.first) {\n            const Z\
    \ L = it->first, R = it->second.first;\n            const T V = it->second.second;\n\
    \            it = m_mp.erase(it);\n            res.emplace_back(L, r, V);\n  \
    \          m_mp[r] = {R, V};\n        }\n        m_mp[l] = {r, v};\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::map<Z, std::pair<Z, T>> m_mp;\n\n    Z m_min,\
    \ m_max;\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/DataStructure/Other/RangeAssigner.hpp
  requiredBy: []
  timestamp: '2025-11-02 16:57:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc430_g.test.cpp
documentation_of: Src/DataStructure/Other/RangeAssigner.hpp
layout: document
title: "\u540C\u4E00\u8981\u7D20\u304B\u3089\u306A\u308B\u6975\u5927\u306A\u533A\u9593\
  \u3092\u7BA1\u7406\u3059\u308B"
---

## 概要

区間set
