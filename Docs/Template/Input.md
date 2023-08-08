---
title: 標準入力
documentation_of: //Src/Template/Input.hpp
---

## 概要

標準入力を扱います。

## ライブラリの使い方

```cpp
void input(T& value)
```

```cpp
void input(Head& head, Tail&... tail)
```

標準入力から受け取った値を順に引数の変数に保管します。
- `std::array`、`std::vector`、`std::pair`の標準入力にも対応しています。
