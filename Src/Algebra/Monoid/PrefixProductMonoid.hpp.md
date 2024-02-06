---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc292_h.test.cpp
    title: Test/AtCoder/abc292_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/PrefixProductMonoid.hpp\"\n\n#include\
    \ <type_traits>\n\nnamespace zawa {\n\ntemplate <class Value>\nclass PrefixProductMonoidData\
    \ {\n    Value product_{}, prefix_{};\npublic:\n    PrefixProductMonoidData()\
    \ = default;\n    PrefixProductMonoidData(const Value& product, const Value& prefix)\n\
    \        : product_{product}, prefix_{prefix} {}\n\n    inline const Value& product()\
    \ const noexcept {\n        return product_;\n    }\n    inline const Value& prefix()\
    \ const noexcept {\n        return prefix_;\n    }\n};\n\ntemplate <class O, class\
    \ F>\nclass PrefixProductMonoid {\n    static_assert(std::is_same_v<typename O::Element,\
    \ typename F::Element>);\npublic:\n    using Element = PrefixProductMonoidData<typename\
    \ O::Element>;\n    static Element identity() noexcept {\n        return PrefixProductMonoidData{O::identity(),\
    \ F::identity()};\n    }\n    static Element operation(const Element& l, const\
    \ Element& r) noexcept {\n        return PrefixProductMonoidData{\n          \
    \  O::operation(l.product(), r.product()),\n            F::operation(l.prefix(),\
    \ O::operation(l.product(), r.prefix()))\n        };\n    }\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class\
    \ Value>\nclass PrefixProductMonoidData {\n    Value product_{}, prefix_{};\n\
    public:\n    PrefixProductMonoidData() = default;\n    PrefixProductMonoidData(const\
    \ Value& product, const Value& prefix)\n        : product_{product}, prefix_{prefix}\
    \ {}\n\n    inline const Value& product() const noexcept {\n        return product_;\n\
    \    }\n    inline const Value& prefix() const noexcept {\n        return prefix_;\n\
    \    }\n};\n\ntemplate <class O, class F>\nclass PrefixProductMonoid {\n    static_assert(std::is_same_v<typename\
    \ O::Element, typename F::Element>);\npublic:\n    using Element = PrefixProductMonoidData<typename\
    \ O::Element>;\n    static Element identity() noexcept {\n        return PrefixProductMonoidData{O::identity(),\
    \ F::identity()};\n    }\n    static Element operation(const Element& l, const\
    \ Element& r) noexcept {\n        return PrefixProductMonoidData{\n          \
    \  O::operation(l.product(), r.product()),\n            F::operation(l.prefix(),\
    \ O::operation(l.product(), r.prefix()))\n        };\n    }\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: Src/Algebra/Monoid/PrefixProductMonoid.hpp
  requiredBy: []
  timestamp: '2024-02-06 13:31:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc292_h.test.cpp
documentation_of: Src/Algebra/Monoid/PrefixProductMonoid.hpp
layout: document
title: "\u533A\u9593Prefix\u7DCF\u7A4D\u30E2\u30CE\u30A4\u30C9"
---

# 概要

セグ木とかのモノイドで抽象化できるデータ構造に乗るやつ。

列 $A$ 上の区間 $[l, r)$ に対して

$g_{l, r}(A) = g(A_{l}, f(A_{l}, A_{l + 1}), f(A_{l}, A_{l + 1}, A_{l + 2}), \dots, f(A_{l}, A_{l + 1}, \dots, A_{r}))$ を管理する。

例えば $\max(A_{1}, A_{1} + A_{2}, \dots, A_{1} + A_{2} + \dots, A_{N})$ とか...

え？これ遅延伝搬いらないんすね。うお〜〜〜〜。

# 使い方

```cpp
template <class Value>
class PrefixProductMonoidData(const Value& product, const Value& prefix)

template <class O, class F>
class PrefixProductMonoid
```

`PrefixProductMonoidData`は`product`, `prefix`のゲッタだけ提供する。
- `product`は $f(A_{l}, A_{l + 1}, \dots, A_{r})$
- `prefix` は $g_{l, r}(A)$

`PrefixProductMonoid`は`Element, identity(), operation()`を提供するクラス。

テンプレート引数について、`O` は $f$ 、 `F`は $g$ のモノイドを与える必要がある。

# 参考

- [ABC292-H Editional](https://atcoder.jp/contests/abc292/editorial/5887)
