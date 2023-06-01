# 本ライブラリの群の実装について

本ライブラリのいくつかのデータ構造では、一般の群で内部の演算が抽象化されているものがあります。そのようなデータ構造は`Src/Algebra/Group/*.hpp`内のクラスや、それらと同様の実装をしたクラスをテンプレート引数で渡すことで利用することができます。

<br />

### そもそも群とは

[参考: Wikipedia](https://ja.wikipedia.org/wiki/%E7%BE%A4_(%E6%95%B0%E5%AD%A6))

集合 $S$ と $S$ 上の二項演算 $f:\ S\times S\to S$ の組 (S, f)$ は以下の条件を満たす時群といいます。
- 結合則 $(\forall a, b, c\in S)[f(a, f(b, c)) = f(f(a, b), c)]$ を満たす
- ある要素 $e\in S$ が存在して、 $(\forall a\in S)[f(a, e) = f(e, a) = a]$ を満たす (このような $e$ を $S$ の単位元と呼ぶ)
- $S$ の全ての要素について逆元が存在する。すなわち $(\forall a\in S)(\exists b\in S)[f(a, b) = f(b, a) = e]$ を満たす。

<br />

## 本ライブラリでの実装

どのクラスも、基本的には以下のような枠組みで実装されています。

```cpp
template <class T>
class Group {
    using valueType = T;
    static constexpr T identity() noexcept {
    
    }
    static constexpr T operation(const T& l, const T& r) noexcept {
        
    }
    static constexpr T inverse(const T& v) noexcept {
    }
};
```

<br />

**template引数 T**

上の説明でいう、 $S$ です。例えば $32$ bitで収まる範囲で足し算をしたい時は `int`型や`zawa::i32 (= std::int32_t)`型を引数に入れることになります。

<br />

**identity**

上の説明でいう、単位元を返すメソッドです。引数をとらず、 `T`型の値を返り値とするメソッドである必要があります。

<br />

**operation**

上の説明でいう、二項演算です。 必ず `T`型の変数 $2$ つを引数にとり、 `T`型の値を返り値とするメソッドである必要があります。

`noexcept`は無くても大丈夫です

<br />

**inverse**

上の説明でいう、逆元を返すメソッドです。必ず `T`型の変数 $1$ つを引数にとり、 `T` 型の値を帰り値とするメソッドである必要があります。

<br />

## 参考

- [代数的構造を乗せるデータ構造の設計について](https://noshi91.hatenablog.com/entry/2020/04/22/212649)
   - 本ライブラリのデータ構造はこちらのブログの E の実装を参考に設計されています。
