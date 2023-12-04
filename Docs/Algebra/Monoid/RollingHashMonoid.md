---
title: ロリハをセグ木にのせる時のモノイド
documentation_of: //Src/Algebra/Monoid/RollingHashMonoid.hpp
---

# 概要

`RollingHashMonoidData`: セグ木に乗っているデータ(ハッシュ)

- staticメンバ関数`randomValue(Value sigma)` で`sigma+1 ~ MOD - 1`のランダムな値を生成します
- staticメンバ変数`base`を必ず初期化してください (randomValueを使うのが一番無難な選択です)
- `generate(T v)` で単一要素からなるハッシュ値を生成します
- `operator==` `operator!=`が定義されています

`RollingHashMonoid`: セグ木上での演算
