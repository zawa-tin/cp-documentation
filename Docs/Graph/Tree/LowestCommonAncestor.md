---
title: Lowest Common Ancestor
documentation_of: //Src/Graph/Tree/LowestCommonAncestor.hpp
---

## 概要

関数オブジェクトの様になっています。 `operator()(usize u, usize v)`で`u`と`v`のLCAが求まります。

## ライブラリの使い方

コンストラクタで `Tree` と根の頂点番号を与えること。頂点番号を指定しなかった場合は頂点 $0$ を根として構築する。
