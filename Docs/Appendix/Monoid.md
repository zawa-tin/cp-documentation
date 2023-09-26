# 本ライブラリのモノイドの実装について

本ライブラリのいくつかのデータ構造では、一般のモノイドで内部の演算が抽象化されているものがあります。そのようなデータ構造は`Src/Algebra/Monoid/*.hpp`内のクラスや、それらと同様の実装をしたクラスをテンプレート引数で渡すことで利用することができます。

<br />

### そもそもモノイドとは

[参考: Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)

- 単位元が存在する
- 結合律が成り立つ
- 可換である必要は無い

<br />

## 本ライブラリでの実装

どのクラスも、基本的には以下のような枠組みで実装されています。

```cpp
template <class T>
class Monoid {
public:
    using Element = T;
    static constexpr T identity() noexcept {
    
    }
    static constexpr T operation(const T& l, const T& r) noexcept {
        
    }
};
```

<br />

**template引数 T**

上の説明でいう、 $S$ です。例えば $32$ bitで収まる範囲で足し算をしたい時は `int`型や`zawa::i32 (= std::int32_t)`型を引数に入れることになります。

<br />

**using Element = T**

データ構造等で群の型にアクセスする時に使います。必ず用意してください。

<br />

**identity**

上の説明でいう、単位元を返すメンバです。引数をとらず、 `T`型の値を返り値とするメソッドである必要があります。

<br />

**operation**

上の説明でいう、二項演算です。 必ず `T`型の変数 $2$ つを引数にとり、 `T`型の値を返り値とするメソッドである必要があります。

- 可換で無い時、`l, r`の順番に気をつけてください
- `noexcept`は無くても大丈夫です

<br />

## 参考

- [代数的構造を乗せるデータ構造の設計について](https://noshi91.hatenablog.com/entry/2020/04/22/212649)
   - 本ライブラリのデータ構造はこちらのブログの E の実装を参考に設計しています。
