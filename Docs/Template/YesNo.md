---
title: YesかNoを出力する
documentation_of: //Src/Template/YesNo.hpp
---

## 概要

真理値を受け取り、その真偽によって予め設定した文字列を出力します。


## ライブラリの使い方

#### YesNo

```cpp
void YesNo(bool answer)
```

`answer`が`true`なら`yes`に設定された文字列を、`false`なら`no`に設定された文字列を出力します。

<br />

#### SetYes

```cpp
void SetYes(const std::string& yes)
```

`yes`の文字列を設定します。

<br />

#### SetNo

```cpp
void SetNo(const std::string& no)
```

`no`の文字列を設定します。

<br />

#### SetAtCoderYesNo

```cpp
void SetAtCoderYesNo()
```

`yes`を`Yes`に、`no`を`No`に設定します。

<br />

#### SetCodeforcesYesNo

```cpp
void SetCodeforcesYesNo()
```

`yes`を`YES`に、`no`を`NO`に設定します。
