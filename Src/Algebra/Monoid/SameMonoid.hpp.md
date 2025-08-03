---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/EC162-D.test.cpp
    title: Test/CF/EC162-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/Manual/aoj3326.test.cpp
    title: Test/Manual/aoj3326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/SameMonoid.hpp\"\n\n#include <optional>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass SameMonoidData {\nprivate:\n \
    \   std::optional<T> element_{};\n    bool same_{true};\npublic:\n\n    static\
    \ std::optional<T> merge(const std::optional<T>& l, const std::optional<T>& r)\
    \ noexcept {\n        if (l and r) return (l.value() == r.value() ? l : std::nullopt);\n\
    \        if (l) return l;\n        if (r) return r;\n        return std::nullopt;\n\
    \    }\n\n    SameMonoidData() = default;\n    SameMonoidData(const T& element)\
    \ \n        : element_{element}, same_{true} {}\n    SameMonoidData(const std::optional<T>&\
    \ element, bool same)\n        : element_{element}, same_{same} {}\n\n    bool\
    \ empty() const noexcept {\n        return same_ and !element_.has_value();\n\
    \    }\n    bool same() const noexcept {\n        return same_;\n    }\n    std::optional<T>\
    \ element() const noexcept {\n        return element_;\n    }\n    T value() const\
    \ noexcept {\n        return element_.value();\n    }\n};\n\ntemplate <class T>\n\
    struct SameMonoid {\npublic:\n    using Element = SameMonoidData<T>;\n    static\
    \ Element identity() noexcept {\n        return Element{}; \n    }\n    static\
    \ Element operation(const Element& l, const Element& r) {\n        if (l.empty()\
    \ and r.empty()) return identity();\n        if (l.empty()) return r;\n      \
    \  if (r.empty()) return l;\n        std::optional<T> element{Element::merge(l.element(),\
    \ r.element())};\n        return Element{element, l.same() and r.same() and element.has_value()};\n\
    \    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <optional>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass SameMonoidData {\nprivate:\n    std::optional<T> element_{};\n   \
    \ bool same_{true};\npublic:\n\n    static std::optional<T> merge(const std::optional<T>&\
    \ l, const std::optional<T>& r) noexcept {\n        if (l and r) return (l.value()\
    \ == r.value() ? l : std::nullopt);\n        if (l) return l;\n        if (r)\
    \ return r;\n        return std::nullopt;\n    }\n\n    SameMonoidData() = default;\n\
    \    SameMonoidData(const T& element) \n        : element_{element}, same_{true}\
    \ {}\n    SameMonoidData(const std::optional<T>& element, bool same)\n       \
    \ : element_{element}, same_{same} {}\n\n    bool empty() const noexcept {\n \
    \       return same_ and !element_.has_value();\n    }\n    bool same() const\
    \ noexcept {\n        return same_;\n    }\n    std::optional<T> element() const\
    \ noexcept {\n        return element_;\n    }\n    T value() const noexcept {\n\
    \        return element_.value();\n    }\n};\n\ntemplate <class T>\nstruct SameMonoid\
    \ {\npublic:\n    using Element = SameMonoidData<T>;\n    static Element identity()\
    \ noexcept {\n        return Element{}; \n    }\n    static Element operation(const\
    \ Element& l, const Element& r) {\n        if (l.empty() and r.empty()) return\
    \ identity();\n        if (l.empty()) return r;\n        if (r.empty()) return\
    \ l;\n        std::optional<T> element{Element::merge(l.element(), r.element())};\n\
    \        return Element{element, l.same() and r.same() and element.has_value()};\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/SameMonoid.hpp
  requiredBy: []
  timestamp: '2024-02-25 01:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/EC162-D.test.cpp
  - Test/Manual/aoj3326.test.cpp
documentation_of: Src/Algebra/Monoid/SameMonoid.hpp
layout: document
title: "\u5358\u4E00\u8981\u7D20\u304B\u3089\u306A\u308B\u591A\u91CD\u96C6\u5408\u304B\
  \u5224\u5B9A\u3059\u308B\u30E2\u30CE\u30A4\u30C9"
---

# 概要

しばしば「指定された集合 $S$ に属する要素が全て同じ値か $o(|S|)$ で判定せよ」といった問題が要求されることがある。
- 数列 $A$ の区間 $[l, r)$ に属する要素が... 等

こういったクエリをデータ構造に載せたい時用。

`std::optional<T>`の運用については [std::optional cpprefjp](https://cpprefjp.github.io/reference/optional/optional.html) 等も参考にすること。

## 使い方

#### コンストラクタ

```cpp
(1) SameMonoidData<T>() = default;
(2) SameMonoidData<T>(const T& element)
(3) SameMonoidData<T>(const std::optional<T>& element, bool same)
```

(1) 空集合の時
(2) 単一要素`element`からなる集合の時
(3) ユーザー側からの使用は特に想定していない。protectedとかにすればよかったかも。

<br />

#### empty

```cpp
bool SameMonoidData<T>::empty() const noexcept
```

持っている集合が空集合の時`true`

<br />

#### same

```cpp
bool SameMonoidData<T>::same() const noexcept
```

持っている集合が空または単一要素からなる多重集合の時`true`

<br />

#### element

```cpp
std::optional<T> SameMonoidData<T>::element() const noexcept
```

集合の代表元を返す。集合が空だったり単一要素から構成されていない場合は`std::nullopt`が返る。

<br />

#### value

```cpp
T SameMonoidData<T>::value() const noexcept
```

集合の代表元を返す。集合が空だったり単一要素から構成されていない場合は**実行時エラー**になる。

<br />
