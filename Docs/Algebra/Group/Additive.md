---
title: 加法群
documentation_of: //Src/Algebra/Group/AdditiveGroup.hpp
---

# 概要

本ライブラリの群を要求するデータ構造で加法を扱いたい時に使用します。

<br />

## 機能

実装の詳細は[本ライブラリでの群の実装について](https://zawa-tin.github.io/cp-documentation/Docs/Appendix/Group.html)を確認してください。

<br />

## 制約

テンプレート引数に入れる型、クラスが以下の条件を満たす必要があります。
- デフォルトコンストラクタが加法の単位元である。
- 加算の二項演算子`+`が定義されている。
- 単項否定演算子`-`の`operator`が定義されていて、加法の逆元を返すものになっている。
- 演算が群の条件を満たす。
