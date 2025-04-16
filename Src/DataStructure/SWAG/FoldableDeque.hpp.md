---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/deque_operate_all_composite.test.cpp
    title: Test/LC/deque_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SWAG/FoldableDeque.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 2\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 4 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Monoid\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n    { T::operation(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n} // namespace\n\
    \n} // namespace zawa\n#line 6 \"Src/DataStructure/SWAG/FoldableDeque.hpp\"\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::Semigroup\
    \ S>\nclass FoldableDeque {\npublic:\n\n    using V = typename S::Element;\n\n\
    \    FoldableDeque() = default;\n\n    inline usize size() const {\n        return\
    \ m_front.size() + m_back.size();\n    }\n\n    inline bool empty() const {\n\
    \        return m_front.empty() and m_back.empty();\n    }\n\n    void pushBack(const\
    \ V& v) {\n        m_back.push_back({\n                m_back.empty() ? v : S::operation(m_back.back().first,\
    \ v),\n                v\n                });\n    }\n\n    void pushFront(const\
    \ V& v) {\n        m_front.push_back({\n                m_front.empty() ? v :\
    \ S::operation(v, m_front.back().first),\n                v\n                });\n\
    \    }\n\n    V product() const {\n        if (empty()) {\n            if constexpr\
    \ (Concept::Monoid<S>) {\n                return S::identity();\n            }\n\
    \            else {\n                assert(!\"try to calculate product on empty\
    \ deque! You must need identity for S\");\n            }\n        }\n        else\
    \ {\n            if (m_front.empty()) return m_back.back().first;\n          \
    \  if (m_back.empty()) return m_front.back().first;\n            return S::operation(m_front.back().first,\
    \ m_back.back().first);\n        }\n    }\n\n    V popFront() {\n        assert(size());\n\
    \        if (m_front.empty()) moveBtoF();\n        V res = std::move(m_front.back().second);\n\
    \        m_front.pop_back();\n        return res;\n    }\n\n    V popBack() {\n\
    \        assert(size());\n        if (m_back.empty()) moveFtoB();\n        V res\
    \ = std::move(m_back.back().second);\n        m_back.pop_back();\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::vector<std::pair<V, V>> m_front, m_back;\n\
    \n    void moveFtoB() {\n        usize sz = m_front.size() / 2;\n        std::vector<V>\
    \ tmp(sz); \n        for (usize i = 0 ; i < sz ; i++) {\n            tmp[i] =\
    \ m_front.back().second;\n            m_front.pop_back();\n        }\n       \
    \ while (m_front.size()) {\n            pushBack(m_front.back().second);\n   \
    \         m_front.pop_back();\n        }\n        for (usize i = tmp.size() ;\
    \ i-- ; ) {\n            pushFront(tmp[i]);\n        }\n    }\n\n    void moveBtoF()\
    \ {\n        usize sz = m_back.size() / 2;\n        std::vector<V> tmp(sz); \n\
    \        for (usize i = 0 ; i < sz ; i++) {\n            tmp[i] = m_back.back().second;\n\
    \            m_back.pop_back();\n        }\n        while (m_back.size()) {\n\
    \            pushFront(m_back.back().second);\n            m_back.pop_back();\n\
    \        }\n        for (usize i = tmp.size() ; i-- ; ) {\n            pushBack(tmp[i]);\n\
    \        }\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::Semigroup S>\nclass\
    \ FoldableDeque {\npublic:\n\n    using V = typename S::Element;\n\n    FoldableDeque()\
    \ = default;\n\n    inline usize size() const {\n        return m_front.size()\
    \ + m_back.size();\n    }\n\n    inline bool empty() const {\n        return m_front.empty()\
    \ and m_back.empty();\n    }\n\n    void pushBack(const V& v) {\n        m_back.push_back({\n\
    \                m_back.empty() ? v : S::operation(m_back.back().first, v),\n\
    \                v\n                });\n    }\n\n    void pushFront(const V&\
    \ v) {\n        m_front.push_back({\n                m_front.empty() ? v : S::operation(v,\
    \ m_front.back().first),\n                v\n                });\n    }\n\n  \
    \  V product() const {\n        if (empty()) {\n            if constexpr (Concept::Monoid<S>)\
    \ {\n                return S::identity();\n            }\n            else {\n\
    \                assert(!\"try to calculate product on empty deque! You must need\
    \ identity for S\");\n            }\n        }\n        else {\n            if\
    \ (m_front.empty()) return m_back.back().first;\n            if (m_back.empty())\
    \ return m_front.back().first;\n            return S::operation(m_front.back().first,\
    \ m_back.back().first);\n        }\n    }\n\n    V popFront() {\n        assert(size());\n\
    \        if (m_front.empty()) moveBtoF();\n        V res = std::move(m_front.back().second);\n\
    \        m_front.pop_back();\n        return res;\n    }\n\n    V popBack() {\n\
    \        assert(size());\n        if (m_back.empty()) moveFtoB();\n        V res\
    \ = std::move(m_back.back().second);\n        m_back.pop_back();\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::vector<std::pair<V, V>> m_front, m_back;\n\
    \n    void moveFtoB() {\n        usize sz = m_front.size() / 2;\n        std::vector<V>\
    \ tmp(sz); \n        for (usize i = 0 ; i < sz ; i++) {\n            tmp[i] =\
    \ m_front.back().second;\n            m_front.pop_back();\n        }\n       \
    \ while (m_front.size()) {\n            pushBack(m_front.back().second);\n   \
    \         m_front.pop_back();\n        }\n        for (usize i = tmp.size() ;\
    \ i-- ; ) {\n            pushFront(tmp[i]);\n        }\n    }\n\n    void moveBtoF()\
    \ {\n        usize sz = m_back.size() / 2;\n        std::vector<V> tmp(sz); \n\
    \        for (usize i = 0 ; i < sz ; i++) {\n            tmp[i] = m_back.back().second;\n\
    \            m_back.pop_back();\n        }\n        while (m_back.size()) {\n\
    \            pushFront(m_back.back().second);\n            m_back.pop_back();\n\
    \        }\n        for (usize i = tmp.size() ; i-- ; ) {\n            pushBack(tmp[i]);\n\
    \        }\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: false
  path: Src/DataStructure/SWAG/FoldableDeque.hpp
  requiredBy: []
  timestamp: '2025-04-16 17:26:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/deque_operate_all_composite.test.cpp
documentation_of: Src/DataStructure/SWAG/FoldableDeque.hpp
layout: document
title: Foldable Deque
---

## 概要

**半群**の積が取れるDeque

- モノイドじゃなくて半群だから、単位元がいらない！すごい？
- 空のdequeに対して`product()`を呼ぶ際は`S::identity()`を要求する(無いときは実行時エラー)

雛形
```cpp
struct S {
    using Element = ;
    static Element operation(Element, Element) {
    }
    /*
    static Element identity() {
    }
    */
};
```

## 参考

- [https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1](https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1)
