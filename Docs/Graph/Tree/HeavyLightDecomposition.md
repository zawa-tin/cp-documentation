---
title: Heavy Light Decomposition
documentation_of: //Src/Graph/Tree/HeavyLightDecomposition.hpp
---

## 概要

コンストラクタで`Tree`と根頂点を指定する。

`decomp(s, t)`や`operator()(s, t)`で $s-t$ パスを分解して`std::vector<std::pair<u32, u32>>`で返す。

- `min(idx[first], idx[second])...max(idx[first], idx[second])`にこのパスが列に並んでいる。

他にもLCA, Level Ancestor, Jump on Treeなどを整備している。
