---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
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
    path: Test/AtCoder/abc222_g.test.cpp
    title: Test/AtCoder/abc222_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc270_g.test.cpp
    title: Test/AtCoder/abc270_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/discrete_logarithm_mod.test.cpp
    title: Test/LC/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 6 \"Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 10 \"Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp\"\
    \n#include <cmath>\n#include <functional>\n#include <optional>\n#include <unordered_set>\n\
    \nnamespace zawa {\n\nnamespace discretelog_internal {\n\nusing namespace concepts;\n\
    \ntemplate <class X, class S>\nconcept Condition = Monoid<X> and Action<X, S>;\n\
    \ntemplate <class F, class S>\nconcept Hasher = std::is_invocable_r_v<usize, F,\
    \ S>;\n\ntemplate <class S>\nconcept STDHashable = requires (S s) {\n    { std::hash<S>{}(s)\
    \ } -> std::convertible_to<usize>;\n};\n\n} // namespace discretelog_internal\n\
    \ntemplate <class X, class S, class H>\nrequires discretelog_internal::Condition<X,\
    \ S> and discretelog_internal::Hasher<H, S>\nstd::optional<usize> MonoidDiscreteLogarithm(typename\
    \ X::Element x, S s, S t, usize N) {\n    assert(N);\n    if (s == t)\n      \
    \  return 0;\n    using XE = typename X::Element;\n    using Hashset = std::unordered_set<S,\
    \ H>;\n    const usize m = std::max<usize>(1, sqrtl(N));\n    Hashset T;\n   \
    \ T.reserve(m);\n    const XE xm = [&]() {\n        XE xi = X::identity();\n \
    \       for (usize i = 0 ; i < m ; i++)\n            T.insert(X::action(xi = X::operation(xi,\
    \ x), t));\n        return xi;\n    }();\n    XE prv = X::identity();\n    for\
    \ (usize k = 1, fail = 0 ; (k - 1) * m <= N and fail < 2 ; k++) {\n        XE\
    \ cur = X::operation(prv, xm);\n        const S val = X::action(cur, s);\n   \
    \     if (T.contains(val)) {\n            for (auto [i, xi] = std::pair<usize,\
    \ XE>(0, prv) ; i < m ; i++, xi = X::operation(xi, x)) {\n                if (X::action(xi,\
    \ s) == t) {\n                    const usize res = (k - 1) * m + i;\n       \
    \             return res < N ? std::optional<usize>{res} : std::nullopt;\n   \
    \             }\n            } \n            fail++;\n        }\n        prv =\
    \ std::move(cur);\n    }\n    return std::nullopt;\n}\n\ntemplate <class X, class\
    \ S>\nrequires discretelog_internal::Condition<X, S> and discretelog_internal::STDHashable<S>\n\
    std::optional<usize> MonoidDiscreteLogarithm(typename X::Element x, S s, S t,\
    \ usize N) {\n    return MonoidDiscreteLogarithm<X, S, std::hash<S>>(x, s, t,\
    \ N); \n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./MonoidConcept.hpp\"\n#include \"../Action/ActionConcept.hpp\"\
    \n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <concepts>\n#include <cmath>\n#include <functional>\n#include\
    \ <optional>\n#include <unordered_set>\n\nnamespace zawa {\n\nnamespace discretelog_internal\
    \ {\n\nusing namespace concepts;\n\ntemplate <class X, class S>\nconcept Condition\
    \ = Monoid<X> and Action<X, S>;\n\ntemplate <class F, class S>\nconcept Hasher\
    \ = std::is_invocable_r_v<usize, F, S>;\n\ntemplate <class S>\nconcept STDHashable\
    \ = requires (S s) {\n    { std::hash<S>{}(s) } -> std::convertible_to<usize>;\n\
    };\n\n} // namespace discretelog_internal\n\ntemplate <class X, class S, class\
    \ H>\nrequires discretelog_internal::Condition<X, S> and discretelog_internal::Hasher<H,\
    \ S>\nstd::optional<usize> MonoidDiscreteLogarithm(typename X::Element x, S s,\
    \ S t, usize N) {\n    assert(N);\n    if (s == t)\n        return 0;\n    using\
    \ XE = typename X::Element;\n    using Hashset = std::unordered_set<S, H>;\n \
    \   const usize m = std::max<usize>(1, sqrtl(N));\n    Hashset T;\n    T.reserve(m);\n\
    \    const XE xm = [&]() {\n        XE xi = X::identity();\n        for (usize\
    \ i = 0 ; i < m ; i++)\n            T.insert(X::action(xi = X::operation(xi, x),\
    \ t));\n        return xi;\n    }();\n    XE prv = X::identity();\n    for (usize\
    \ k = 1, fail = 0 ; (k - 1) * m <= N and fail < 2 ; k++) {\n        XE cur = X::operation(prv,\
    \ xm);\n        const S val = X::action(cur, s);\n        if (T.contains(val))\
    \ {\n            for (auto [i, xi] = std::pair<usize, XE>(0, prv) ; i < m ; i++,\
    \ xi = X::operation(xi, x)) {\n                if (X::action(xi, s) == t) {\n\
    \                    const usize res = (k - 1) * m + i;\n                    return\
    \ res < N ? std::optional<usize>{res} : std::nullopt;\n                }\n   \
    \         } \n            fail++;\n        }\n        prv = std::move(cur);\n\
    \    }\n    return std::nullopt;\n}\n\ntemplate <class X, class S>\nrequires discretelog_internal::Condition<X,\
    \ S> and discretelog_internal::STDHashable<S>\nstd::optional<usize> MonoidDiscreteLogarithm(typename\
    \ X::Element x, S s, S t, usize N) {\n    return MonoidDiscreteLogarithm<X, S,\
    \ std::hash<S>>(x, s, t, N); \n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp
  requiredBy: []
  timestamp: '2025-08-21 17:55:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/discrete_logarithm_mod.test.cpp
  - Test/AtCoder/abc222_g.test.cpp
  - Test/AtCoder/abc270_g.test.cpp
documentation_of: Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C(\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

モノイド $(X, \oplus)$ と集合 $S$ に対して関数 $f : X\times S\rightarrow S$ が定義されているとする。

$x \in S, s, t \in S$ に対して $f(x^{n}, s) = t$ を満たす最小の $n$ を計算する。それが入力で与えられる正整数 $N$ 以上である、または存在しないならば`std::nullopt`を返す。

## ライブラリの使い方

```cpp
template <class X, class S, class H>
std::optional<usize> MonoidDiscreteLogarithm(typename X::Element x, S s, S t, usize N)  (1)

template <class X, class S>
std::optional<usize> MonoidDiscreteLogarithm(X x, S s, S t, usize N) (2)
```

(1) `X`は`concepts::Monoid`を満たす必要がある。 `X`に対して`S action(X, S)`が定義されている必要がある。`H`は`S`の要素のハッシュを取る関数オブジェクトである必要がある。

$S$ に対して`std::hash`が定義されているならば(2)を用いることができる((2)は未verify...)

例えば、通常の離散対数問題( $x^{n} \equiv y\pmod{M}$ なる最小の $n$ を見つける)ときは以下のようにする。

```cpp
using S = mint;
struct X {
    using Element = mint;
    static Element identity() {
        return mint{1};
    }
    static Element operation(Element L, Element R) {
        return L * R;
    }
    static Element action(Element x, S s) {
        return x * s;
    }
};
struct Hasher {
    size_t operator()(const S& v) const {
        return v.val();
    }
};
int main() {
    auto ans = MonoidDiscreteLogarithm<M, mint, Hasher>(mint{x}, mint{1}, mint{y}, M);
}
```

## 計算量

- `X::identity()`を高々 $2$ 回呼び出す
- `X::operation()`を高々 $4\lfloor \sqrt{N}\rfloor + O(1)$ 回呼び出す
- `X::action()`を高々 $3\lfloor\sqrt{N}\rfloor + O(1)$ 回呼び出す
- `std::unordered<S>`に高々 $\lfloor\sqrt{N}\rfloor$ 要素挿入され、高々 $\lfloor\sqrt{N}\rfloor + O(1)$ 回検索を行う

## 参考

- [モノイド作用に関する離散対数問題](https://maspypy.com/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89%E4%BD%9C%E7%94%A8%E3%81%AB%E9%96%A2%E3%81%99%E3%82%8B%E9%9B%A2%E6%95%A3%E5%AF%BE%E6%95%B0%E5%95%8F%E9%A1%8C)

## 変更履歴

- 2025/08/21 作成
- 2026/01/03 ドキュメントの文言に誤りがあったため修正
