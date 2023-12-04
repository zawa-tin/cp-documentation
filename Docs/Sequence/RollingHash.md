---
title: ロリハ
documentation_of: //Src/Sequence/RollingHash.hpp
---

## 概要

`RollingHashFactory`のコンストラクタで、ハッシュ化したい列の取りうる最大長と $\mid \sigma \mid$ をこの順に与えてください。

`RollingHashFactory::create(hogeee)`でロリハ(区間ハッシュが取れるやつ)を作成します。

- `prefix`
- `range`
- `lcp` (こいつ未テスト)
- 型は`auto`で受け取るのが一番楽。真面目に書くなら`RollingHashFactory::RollingHash`

`RollingHashFactory::hash(hogee)`で単に引数の列のハッシュ値を返します。

- 型は`auto`で受け取るのが一番楽。真面目に書くなら`RollingHashFactory::Hash`

ハッシュは`{ hash(), len() }`の構造体となっています。

`RollingHashFactory::concate`でハッシュ値の連結を行うことができます。

ドキュメントを書く気力がないんじゃ

## 参考

- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://twitter.com/0x3b800001/status/1612589603973914624?s=46

## update
