---
title: 静的列の区間クエリをオフライン処理する
documentation_of: //Src/Sequence/OfflineRangeProduct.hpp
---

## ライブラリの使い方

```cpp
template <class M, class S, class Range>
requires concepts::Monoid<M> and concepts::Acted<M, S> and offline_range_product_internal::Range<Range>
std::vector<typename M::Element> OfflineRangeProduct(const std::vector<S>& as, const std::vector<Range>& qs)
```

`M`はモノイドであり、 $S$ は`M::Element`に作用する。

`M::Element = S`の場合はMonoidAction.hppの`AddSelfAction<M>`とすれば作用の関数がその`operation`で自動的に定義される(非可換のときは十分に注意すること)

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

`acted`を $\Theta (N\log N)$ 回。`operation, identity`をそれぞれ $O\Theta (Q)$ 回呼び出す。

## 参考

- [分割統治による静的列の区間積クエリ](https://maspypy.com/%E5%88%86%E5%89%B2%E7%B5%B1%E6%B2%BB%E3%81%AB%E3%82%88%E3%82%8B%E9%9D%99%E7%9A%84%E5%88%97%E3%81%AE%E5%8C%BA%E9%96%93%E7%A9%8D%E3%82%AF%E3%82%A8%E3%83%AA)

