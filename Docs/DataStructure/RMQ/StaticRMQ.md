---
title: Static RMQ
documentation_of: //Src/DataStructure/RMQ/StaticRMQ.hpp
---

Disjoint Sparse Tableとは異なり凝った抽象化はしておらず、モノイドを要求する仕様になっている。

クエリ毎に最大 $15$ 回も`operation`を呼び出すため、`operation`が早い場合でないとスパテより早くなることが期待できない。

Library CheckerではDisjoint Sparse Tableより30msほど有利を取っている。

## 更新履歴

- 2026/05/24: 作成
