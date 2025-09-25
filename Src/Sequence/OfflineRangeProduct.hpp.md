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
    path: Test/AtCoder/abc223_h.test.cpp
    title: Test/AtCoder/abc223_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
    title: Test/LC/staticrmq/OfflineRangeProduct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Sequence/OfflineRangeProduct.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
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
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/Sequence/OfflineRangeProduct.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 10 \"Src/Sequence/OfflineRangeProduct.hpp\"\
    \n#include <numeric>\n#include <vector>\n\nnamespace zawa {\n\nnamespace offline_range_product_internal\
    \ {\n\ntemplate <class R>\nconcept Range = requires (R lr) {\n    { lr.l } ->\
    \ std::convertible_to<usize>;\n    { lr.r } -> std::convertible_to<usize>;\n};\n\
    \ntemplate <class M, class S, class R>\nconcept condition = concepts::Monoid<M>\
    \ and Range<R> and (std::same_as<typename M::Element, S> or concepts::Acted<M,\
    \ S>);\n\n} // namespace offline_range_product_internal\n\ntemplate <class M,\
    \ class S, class Range>\nrequires offline_range_product_internal::condition<M,\
    \ S, Range>\nstd::vector<typename M::Element> OfflineRangeProduct(const std::vector<S>&\
    \ as, const std::vector<Range>& qs) {\n    std::vector<typename M::Element> sum(as.size()\
    \ + 1), res(qs.size(), M::identity());\n    auto f = [&](usize m, const std::vector<usize>&\
    \ idx) -> void {\n        sum[m] = M::identity();\n        usize L = m, R = m;\n\
    \        for (usize i : idx) {\n            L = std::min<usize>(L, qs[i].l);\n\
    \            R = std::max<usize>(R, qs[i].r);\n        }\n        for (usize i\
    \ = m ; i-- > L ; ) {\n            if constexpr (std::same_as<typename M::Element,\
    \ S>)\n                sum[i] = M::operation(as[i], sum[i + 1]);\n           \
    \ else\n                sum[i] = M::acted(sum[i + 1], as[i]);\n        }\n   \
    \     for (usize i = m ; i < R ; i++) {\n            if constexpr (std::same_as<typename\
    \ M::Element, S>)\n                sum[i + 1] = M::operation(sum[i], as[i]);\n\
    \            else\n                sum[i + 1] = M::acted(sum[i], as[i]);\n   \
    \     }\n        for (usize i : idx)\n            res[i] = M::operation(sum[qs[i].l],\
    \ sum[qs[i].r]);\n    };\n    auto rec = [&](auto rec, usize L, usize R, std::vector<usize>\
    \ idx) -> void {\n        if (L >= R)\n            return;\n        if (L + 1\
    \ == R) {\n            f(L, idx);\n            return;\n        }\n        const\
    \ usize mid = (L + R) / 2;\n        std::vector<usize> toL, toR, cur;\n      \
    \  for (auto&& i : idx) {\n            assert(qs[i].l <= qs[i].r and static_cast<usize>(qs[i].r)\
    \ <= as.size());\n            if (static_cast<usize>(qs[i].r) <= mid)\n      \
    \          toL.push_back(std::move(i));\n            else if (mid <= static_cast<usize>(qs[i].l))\n\
    \                toR.push_back(std::move(i));\n            else\n            \
    \    cur.push_back(std::move(i));\n        }\n        if (cur.size())\n      \
    \      f(mid, cur);\n        if (toL.size())\n            rec(rec, L, mid, toL);\n\
    \        if (toR.size())\n            rec(rec, mid, R, toR);\n    };\n    std::vector<usize>\
    \ idx(qs.size());\n    std::iota(idx.begin(), idx.end(), 0);\n    rec(rec, 0,\
    \ as.size(), idx);\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"../Algebra/Monoid/MonoidConcept.hpp\"\
    \n#include \"../Algebra/Action/ActionConcept.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <concepts>\n#include <numeric>\n#include <vector>\n\nnamespace\
    \ zawa {\n\nnamespace offline_range_product_internal {\n\ntemplate <class R>\n\
    concept Range = requires (R lr) {\n    { lr.l } -> std::convertible_to<usize>;\n\
    \    { lr.r } -> std::convertible_to<usize>;\n};\n\ntemplate <class M, class S,\
    \ class R>\nconcept condition = concepts::Monoid<M> and Range<R> and (std::same_as<typename\
    \ M::Element, S> or concepts::Acted<M, S>);\n\n} // namespace offline_range_product_internal\n\
    \ntemplate <class M, class S, class Range>\nrequires offline_range_product_internal::condition<M,\
    \ S, Range>\nstd::vector<typename M::Element> OfflineRangeProduct(const std::vector<S>&\
    \ as, const std::vector<Range>& qs) {\n    std::vector<typename M::Element> sum(as.size()\
    \ + 1), res(qs.size(), M::identity());\n    auto f = [&](usize m, const std::vector<usize>&\
    \ idx) -> void {\n        sum[m] = M::identity();\n        usize L = m, R = m;\n\
    \        for (usize i : idx) {\n            L = std::min<usize>(L, qs[i].l);\n\
    \            R = std::max<usize>(R, qs[i].r);\n        }\n        for (usize i\
    \ = m ; i-- > L ; ) {\n            if constexpr (std::same_as<typename M::Element,\
    \ S>)\n                sum[i] = M::operation(as[i], sum[i + 1]);\n           \
    \ else\n                sum[i] = M::acted(sum[i + 1], as[i]);\n        }\n   \
    \     for (usize i = m ; i < R ; i++) {\n            if constexpr (std::same_as<typename\
    \ M::Element, S>)\n                sum[i + 1] = M::operation(sum[i], as[i]);\n\
    \            else\n                sum[i + 1] = M::acted(sum[i], as[i]);\n   \
    \     }\n        for (usize i : idx)\n            res[i] = M::operation(sum[qs[i].l],\
    \ sum[qs[i].r]);\n    };\n    auto rec = [&](auto rec, usize L, usize R, std::vector<usize>\
    \ idx) -> void {\n        if (L >= R)\n            return;\n        if (L + 1\
    \ == R) {\n            f(L, idx);\n            return;\n        }\n        const\
    \ usize mid = (L + R) / 2;\n        std::vector<usize> toL, toR, cur;\n      \
    \  for (auto&& i : idx) {\n            assert(qs[i].l <= qs[i].r and static_cast<usize>(qs[i].r)\
    \ <= as.size());\n            if (static_cast<usize>(qs[i].r) <= mid)\n      \
    \          toL.push_back(std::move(i));\n            else if (mid <= static_cast<usize>(qs[i].l))\n\
    \                toR.push_back(std::move(i));\n            else\n            \
    \    cur.push_back(std::move(i));\n        }\n        if (cur.size())\n      \
    \      f(mid, cur);\n        if (toL.size())\n            rec(rec, L, mid, toL);\n\
    \        if (toR.size())\n            rec(rec, mid, R, toR);\n    };\n    std::vector<usize>\
    \ idx(qs.size());\n    std::iota(idx.begin(), idx.end(), 0);\n    rec(rec, 0,\
    \ as.size(), idx);\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: false
  path: Src/Sequence/OfflineRangeProduct.hpp
  requiredBy: []
  timestamp: '2025-08-21 03:06:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc223_h.test.cpp
  - Test/LC/staticrmq/OfflineRangeProduct.test.cpp
documentation_of: Src/Sequence/OfflineRangeProduct.hpp
layout: document
title: "\u9759\u7684\u5217\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u30AA\u30D5\u30E9\
  \u30A4\u30F3\u51E6\u7406\u3059\u308B"
---

## ライブラリの使い方

```cpp
template <class M, class S, class Range>
requires concepts::Monoid<M> and concepts::Acted<M, S> and offline_range_product_internal::Range<Range>
std::vector<typename M::Element> OfflineRangeProduct(const std::vector<S>& as, const std::vector<Range>& qs)
```

`M`はモノイドであり、 $S$ は`M::Element`に作用する。

`M::Element = S`の場合はそのまま`M`のみをテンプレート引数に渡せば良い。(actedを呼び出す所がoperationに置き換わる)

雛形

```cpp
struct M {
    using Element = ;
    static Element identity() {
    }
    static Element operation(Element L, Element R) {
    }
    static Element acted(Element E, S s) {
    }
};
```

`Range`は単に`l, r`という`usize`にキャストできるメンバがあれば良い。**半開区間**で与えること。

```cpp
struct query {
    usize l, r;
};
```

## 計算量

`acted`を $\Theta (N\log N)$ 回。`operation`を $\Theta (Q)$ 回。`identity`を $\Theta (N + Q)$ 回呼び出す。

## 参考

- [分割統治による静的列の区間積クエリ](https://maspypy.com/%E5%88%86%E5%89%B2%E7%B5%B1%E6%B2%BB%E3%81%AB%E3%82%88%E3%82%8B%E9%9D%99%E7%9A%84%E5%88%97%E3%81%AE%E5%8C%BA%E9%96%93%E7%A9%8D%E3%82%AF%E3%82%A8%E3%83%AA)

