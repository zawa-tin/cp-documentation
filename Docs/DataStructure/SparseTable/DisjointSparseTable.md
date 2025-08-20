---
title: Disjoint Sparse Table
documentation_of: //Src/DataStructure/SparseTable/DisjointSparseTable.hpp
---

```cpp
struct M {
    using Element = ;
    static Element identity() {

    }
    static Element operation(Element L, Element R) {

    }
    // コンストラクタの引数のvector<S>のSがElementと異なる場合必要
    // static Element acted(Element L, S e) {
    // }
};
```

## 参考

- [Disjoint Sparse Tableとセグ木に関するポエム](https://noshi91.hatenablog.com/entry/2018/05/08/183946)
- [分割統治による静的列の区間積クエリ](https://maspypy.com/%E5%88%86%E5%89%B2%E7%B5%B1%E6%B2%BB%E3%81%AB%E3%82%88%E3%82%8B%E9%9D%99%E7%9A%84%E5%88%97%E3%81%AE%E5%8C%BA%E9%96%93%E7%A9%8D%E3%82%AF%E3%82%A8%E3%83%AA)

## 変更履歴

2025/8/21:作用の考え方を取り入れた実装方針に変更。ドキュメントに参考を追加 
