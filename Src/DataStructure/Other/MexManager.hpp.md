---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc330_e.test.cpp
    title: Test/AtCoder/abc330_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Other/MexManager.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <limits>\n#include <utility>\n#include <set>\n\n\
    namespace zawa {\n\ntemplate <std::signed_integral T>\nclass MexManager {\npublic:\n\
    \n    static constexpr T MAX = std::numeric_limits<T>::max();\n\n    static constexpr\
    \ T MIN = T{-1};\n\n    MexManager() {\n        m_rg.insert({MIN, MIN});\n   \
    \     m_rg.insert({MAX, MAX});\n    }\n\n    void insert(T v) {\n        assert(MIN\
    \ + 1 <= v and v <= MAX - 1);\n        if (!m_set.contains(v)) {\n           \
    \ const T r = [&]() {\n                auto it = m_rg.lower_bound({v + 1, MIN});\n\
    \                if (it->first == v + 1) {\n                    int res = it->second;\n\
    \                    m_rg.erase(it);\n                    return res;\n      \
    \          }\n                else\n                    return v;\n          \
    \  }();\n            const T l = [&]() {\n                auto it = prev(m_rg.lower_bound({v,\
    \ MIN}));\n                if (it->second + 1 == v) {\n                    int\
    \ res = it->first;\n                    m_rg.erase(it);\n                    return\
    \ res;\n                }\n                else\n                    return v;\n\
    \            }();\n            m_rg.insert({l, r});\n        }\n        m_set.insert(v);\n\
    \    }\n\n    void erase(T v) {\n        if (!m_set.contains(v))\n           \
    \ return;\n        m_set.erase(m_set.find(v));\n        if (m_set.contains(v))\n\
    \            return;\n        auto it = prev(m_rg.lower_bound({v + 1, MIN}));\n\
    \        const auto [l, r] = *it;\n        assert(l <= v and v <= r);\n      \
    \  it = m_rg.erase(it);\n        if (l < v) m_rg.insert({l, v - 1});\n       \
    \ if (v < r) m_rg.insert({v + 1, r});\n    }\n\n    T operator()() const {\n \
    \       return m_rg.begin()->second + 1;\n    }\n\nprivate:\n\n    std::set<std::pair<T,\
    \ T>> m_rg;\n\n    std::multiset<T> m_set;\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cassert>\n#include <concepts>\n#include <limits>\n\
    #include <utility>\n#include <set>\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T>\nclass MexManager {\npublic:\n\n    static constexpr T MAX = std::numeric_limits<T>::max();\n\
    \n    static constexpr T MIN = T{-1};\n\n    MexManager() {\n        m_rg.insert({MIN,\
    \ MIN});\n        m_rg.insert({MAX, MAX});\n    }\n\n    void insert(T v) {\n\
    \        assert(MIN + 1 <= v and v <= MAX - 1);\n        if (!m_set.contains(v))\
    \ {\n            const T r = [&]() {\n                auto it = m_rg.lower_bound({v\
    \ + 1, MIN});\n                if (it->first == v + 1) {\n                   \
    \ int res = it->second;\n                    m_rg.erase(it);\n               \
    \     return res;\n                }\n                else\n                 \
    \   return v;\n            }();\n            const T l = [&]() {\n           \
    \     auto it = prev(m_rg.lower_bound({v, MIN}));\n                if (it->second\
    \ + 1 == v) {\n                    int res = it->first;\n                    m_rg.erase(it);\n\
    \                    return res;\n                }\n                else\n  \
    \                  return v;\n            }();\n            m_rg.insert({l, r});\n\
    \        }\n        m_set.insert(v);\n    }\n\n    void erase(T v) {\n       \
    \ if (!m_set.contains(v))\n            return;\n        m_set.erase(m_set.find(v));\n\
    \        if (m_set.contains(v))\n            return;\n        auto it = prev(m_rg.lower_bound({v\
    \ + 1, MIN}));\n        const auto [l, r] = *it;\n        assert(l <= v and v\
    \ <= r);\n        it = m_rg.erase(it);\n        if (l < v) m_rg.insert({l, v -\
    \ 1});\n        if (v < r) m_rg.insert({v + 1, r});\n    }\n\n    T operator()()\
    \ const {\n        return m_rg.begin()->second + 1;\n    }\n\nprivate:\n\n   \
    \ std::set<std::pair<T, T>> m_rg;\n\n    std::multiset<T> m_set;\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/DataStructure/Other/MexManager.hpp
  requiredBy: []
  timestamp: '2025-08-15 21:25:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc330_e.test.cpp
documentation_of: Src/DataStructure/Other/MexManager.hpp
layout: document
title: "\u8981\u7D20\u8FFD\u52A0\u30FB\u524A\u9664\u30FBmex\u8A08\u7B97"
---

## 概要

**多重集合** $S$ に対して、要素の追加、削除、全体のmexの計算が高速に行えるデータ構造

$0$ 以上`numeric_limits<T>::max() - 1`以下の値を扱うことができる。実装の都合上`T`は符号付き整数である必要がある。

結構雑に書いたため遅いみたい。mexが要素数以下であることを利用した枝刈りとか入れたらもっと早くなると思う。
