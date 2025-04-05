---
title: Misere Nim
documentation_of: //Src/Utility/MisereNim.hpp
---

## 概要

Misere Nimの勝敗を判定します

Misere Nimとは、「最後の一個をとったら負け」石取りゲームのこと。

$2$ 個以上の石からなる石山が存在すると通常のNimに帰着し、そうでない場合は自明

## 使い方

```cpp
enum class GameWinner {
    First,
    Second
}
```

返り値

```cpp
template <std::input_iterator It>
GameWinner MisereNim(It first, It last)
```

標準ライブラリと同じノリでイテレータを入れる
