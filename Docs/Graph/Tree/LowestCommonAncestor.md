---
title: Lowest Common Ancestor
documentation_of: //Src/Graph/Tree/LowestCommonAncestor.hpp
---

## 概要

関数オブジェクトの様になっています。 `operator()(usize u, usize v)`で`u`と`v`のLCAが求まります。

なんと、前計算線形(実測あんまかわってないけど。がっくし)

- バケットサイズを固定してしまっているので $N$ が小さい かつ マルチテストケースみたいなときはちょっと遅いかも

## ライブラリの使い方

コンストラクタで `Tree` と根の頂点番号を与えること。頂点番号を指定しなかった場合は頂点 $0$ を根として構築する。
