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
    path: Src/DataStructure/SWAG/SWAGable.hpp
    title: Src/DataStructure/SWAG/SWAGable.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/EnumerateStaticLengthProduct.hpp
    title: Src/Sequence/EnumerateStaticLengthProduct.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AOJ/3548.test.cpp
    title: AOJ3548 String Puzzle
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/awc001_e.test.cpp
    title: Test/AtCoder/awc001_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/queue_operate_all_composite.test.cpp
    title: Test/LC/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SWAG/FoldableQueue.hpp\"\n\n#line 2 \"\
    Src/DataStructure/SWAG/SWAGable.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SWAG/SWAGable.hpp\"\
    \n\n#line 7 \"Src/DataStructure/SWAG/SWAGable.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept SWAGable = requires {\n    typename\
    \ T::Element;\n    typename T::Fold;\n    typename T::Fold::Element;\n    { T::convert(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Fold::Element>;\n    { T::pushBack(std::declval<typename\
    \ T::Fold::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Fold::Element>;\n    { T::pushFront(std::declval<typename T::Fold::Element>(),\
    \ std::declval<typename T::Element>()) } -> std::same_as<typename T::Fold::Element>;\n\
    };\n\n} // namespace concepts\n\ntemplate <concepts::Semigroup S>\nclass SemigroupSWAGable\
    \ {\npublic:\n    using Element = typename S::Element;\n    using Fold = S;\n\
    \    using F = Fold::Element;\n    static F convert(Element v) {\n        return\
    \ v;\n    }\n    static F pushBack(F f, Element v) {\n        return S::operation(f,\
    \ v);\n    }\n    static F pushFront(F f, Element v) {\n        return S::operation(v,\
    \ f);\n    }\n    static F operation(F l, F r) {\n        return S::operation(l,\
    \ r);\n    }\n};\n\ntemplate <concepts::Monoid S>\nclass MonoidSWAGable {\npublic:\n\
    \    using Element = typename S::Element;\n    using Fold = S;\n    using F =\
    \ Fold::Element;\n    static F convert(Element v) {\n        return v;\n    }\n\
    \    static F pushBack(F f, Element v) {\n        return S::operation(f, v);\n\
    \    }\n    static F pushFront(F f, Element v) {\n        return S::operation(v,\
    \ f);\n    }\n    static F identity() {\n        return S::identity();\n    }\n\
    \    static F operation(F l, F r) {\n        return S::operation(l, r);\n    }\n\
    };\n\n} // namespace zawa\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include\
    \ <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128 = __int128_t;\n\
    \nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\n} // namespace zawa\n\
    #line 7 \"Src/DataStructure/SWAG/FoldableQueue.hpp\"\n\n#include <cassert>\n#include\
    \ <optional>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::SWAGable\
    \ S>\nclass FoldableQueue {\npublic:\n\n    using V = typename S::Element;\n \
    \   using Fold = typename S::Fold;\n    using F = typename Fold::Element;\n\n\
    \    FoldableQueue() = default;\n\n    usize size() const noexcept {\n       \
    \ return m_front.size() + m_back.size();\n    }\n\n    bool empty() const noexcept\
    \ {\n        return size() == 0u;\n    }\n\n    void push(const V& v) {\n    \
    \    m_raw.push_back(v);\n        m_back.push_back(m_back.size() ? S::pushBack(m_back.back(),\
    \ v) : S::convert(v));\n    }\n\n    void pop() {\n        assert(size());\n \
    \       move();\n        m_front.pop_back();\n    }\n\n    std::pair<F, F> get()\
    \ const requires concepts::Identitiable<typename S::Fold> {\n        return {\n\
    \            m_front.empty() ? Fold::identity() : m_front.back(),\n          \
    \  m_back.empty() ? Fold::identity() : m_back.back()\n        };\n    }\n\n  \
    \  std::pair<std::optional<F>, std::optional<F>> get() const {\n        return\
    \ {\n            m_front.empty() ? std::nullopt : std::optional<F>{m_front.back()},\n\
    \            m_back.empty() ? std::nullopt : std::optional<F>{m_back.back()}\n\
    \        };\n    }\n\n    F product() const requires concepts::Monoid<typename\
    \ S::Fold> {\n        auto [f, b] = get();\n        return Fold::operation(f,\
    \ b);\n    }\n\n    F product() const requires concepts::Semigroup<typename S::Fold>\
    \ {\n        assert(m_front.size() or m_back.size());\n        if (m_front.empty())\
    \ return m_back.back();\n        if (m_back.empty()) return m_front.back();\n\
    \        return S::Fold::operation(m_front.back(), m_back.back());\n    }\n  \
    \  \nprivate:\n    std::vector<F> m_front{}, m_back{};\n    std::vector<V> m_raw{};\n\
    \n    void move() {\n        if (m_front.size()) return;\n        while (m_back.size())\
    \ {\n            m_back.pop_back();\n            V v{m_raw.back()};\n        \
    \    m_raw.pop_back();\n            m_front.push_back(m_front.size() ? S::pushFront(m_front.back(),\
    \ v) : S::convert(v));\n        }\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./SWAGable.hpp\"\n#include \"../../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"../../Algebra/Semigroup/SemigroupConcept.hpp\"\n#include \"../../Template/TypeAlias.hpp\"\
    \n\n#include <cassert>\n#include <optional>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <concepts::SWAGable S>\nclass FoldableQueue {\npublic:\n\n   \
    \ using V = typename S::Element;\n    using Fold = typename S::Fold;\n    using\
    \ F = typename Fold::Element;\n\n    FoldableQueue() = default;\n\n    usize size()\
    \ const noexcept {\n        return m_front.size() + m_back.size();\n    }\n\n\
    \    bool empty() const noexcept {\n        return size() == 0u;\n    }\n\n  \
    \  void push(const V& v) {\n        m_raw.push_back(v);\n        m_back.push_back(m_back.size()\
    \ ? S::pushBack(m_back.back(), v) : S::convert(v));\n    }\n\n    void pop() {\n\
    \        assert(size());\n        move();\n        m_front.pop_back();\n    }\n\
    \n    std::pair<F, F> get() const requires concepts::Identitiable<typename S::Fold>\
    \ {\n        return {\n            m_front.empty() ? Fold::identity() : m_front.back(),\n\
    \            m_back.empty() ? Fold::identity() : m_back.back()\n        };\n \
    \   }\n\n    std::pair<std::optional<F>, std::optional<F>> get() const {\n   \
    \     return {\n            m_front.empty() ? std::nullopt : std::optional<F>{m_front.back()},\n\
    \            m_back.empty() ? std::nullopt : std::optional<F>{m_back.back()}\n\
    \        };\n    }\n\n    F product() const requires concepts::Monoid<typename\
    \ S::Fold> {\n        auto [f, b] = get();\n        return Fold::operation(f,\
    \ b);\n    }\n\n    F product() const requires concepts::Semigroup<typename S::Fold>\
    \ {\n        assert(m_front.size() or m_back.size());\n        if (m_front.empty())\
    \ return m_back.back();\n        if (m_back.empty()) return m_front.back();\n\
    \        return S::Fold::operation(m_front.back(), m_back.back());\n    }\n  \
    \  \nprivate:\n    std::vector<F> m_front{}, m_back{};\n    std::vector<V> m_raw{};\n\
    \n    void move() {\n        if (m_front.size()) return;\n        while (m_back.size())\
    \ {\n            m_back.pop_back();\n            V v{m_raw.back()};\n        \
    \    m_raw.pop_back();\n            m_front.push_back(m_front.size() ? S::pushFront(m_front.back(),\
    \ v) : S::convert(v));\n        }\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/DataStructure/SWAG/SWAGable.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/SWAG/FoldableQueue.hpp
  requiredBy:
  - Src/Sequence/EnumerateStaticLengthProduct.hpp
  timestamp: '2026-02-09 20:31:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/awc001_e.test.cpp
  - Test/LC/queue_operate_all_composite.test.cpp
  - Test/AOJ/3548.test.cpp
documentation_of: Src/DataStructure/SWAG/FoldableQueue.hpp
layout: document
title: Foldable Queue
---

## 概要

**半群**の積が取れるQueue

- モノイドじゃなくて半群だから、単位元がいらない！すごい？

参考の名称に従い、SWAGでは無く「Foldable Queue」という呼び名を使用しているが、ライブラリの総積を取得するメンバの名前は`product()`

雛形
```cpp
struct S {
    using Fold = struct {
        using Element = ;
        /*
        static Element identity() {
        }
        static Element operation(Element, Element) {
        }
        */
    };
    using Element = std::pair<int, int>;
    using F = typename Fold::Element;
    static F convert(Element v) {
    }
    static F pushBack(F dp, Element v) {
    }
    static F pushFront(F dp, Element v) {
    }
};
```

または、`concepts::Semigroup, concepts::Monoid`を満たすクラスを`SWAGable`に変換するラッパー`SemigroupSWAGable<S>`, `MonoidSWAGable<S>`が提供されている。

意味合いを説明する。SWAGは以下の条件を満たす集合の二つ組 $(S, F)$ を要求する。前者が実装における`Element`、後者が`Fold`である

- $s\in S$ を $f\in F$ に変換する関数 $f: S\rightarrow F$ が定義されている (convert)
- 関数 $g: (F, S) \rightarrow F$ が定義されている (pushBack)
- 関数 $h: (S, F) \rightarrow F$ が定義されている (pushFront)

dequeに挿入する各要素は $S$ の元であり、積を取った値が $F$ の元になる。

- 一要素からなる $s\in S$ の総積を取るために $f$ が必要
- SWAGに値を追加したときの総積の更新に $g, h$ が必要

ここで、 $F$ 上の二項演算演算(operation)が結合律を満たすとき盆栽から直接`product()`を取得できるようになる。

更に、 $F$ とその二項演算がモノイドを成すとき、空列からproduct()を取得できるようになる。

## 参考

- [https://motsu-xe.hatenablog.com/entry/2021/05/13/224016](https://motsu-xe.hatenablog.com/entry/2021/05/13/224016)
- [https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1](https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1)
