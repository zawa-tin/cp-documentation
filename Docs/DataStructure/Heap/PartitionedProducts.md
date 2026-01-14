---
title: 要素昇順 $K$ 個、降順 $N - K$ 個の総積を管理
documentation_of: //Src/DataStructure/Heap/PartitionedProducts.hpp
---

いわゆる「Priority Queue二つ持ってガチャガチャやるやつ」。海外だとSmartSetなんて呼ばれているやつかも

## ライブラリの使い方

内部で二つの削除可能Priority Queueを管理していて、昇順 $K$ 個を管理している方を`small`、他方を`big`と呼ぶことにする。

### テンプレート引数

```cpp
template <class S, class T, class Comp = std::less<T>>
requires concepts::SetOperator<S, T> and std::strict_weak_order<Comp, const T&, const T&>
class PartitionedProducts
```

`S`が総積の取り方を決める代数的構造。`T`が各要素を意味する。
- `S::Element`の単位元
- `S::Element`に`T`の要素を追加する
- `S::Element`に追加されていた`T`の要素を取り除く

のみっつが定義されていれば良い。例えばかけざんならば、

```
struct OP {
    using Element = long long;
    static Element identity() {
        return 1;
    }
    static void add(Element& a, int x) {
        a *= x;
    }
    static void remove(Element& a, int x) {
        assert(a % x == 0);
        return a / x;
    }
};
```
で良い。このように`S::Element`と`T`は必ずしも同じ要素である必要は無い。

### コンストラクタ

```cpp
(1) PartitionedProducts(Comp comp = {}) 
(2) PartitionedProducts(std::vector<T> a, Comp comp = {}) 
```

`comp`は指定しなければ`std::less<T>`になる。(`std::less<T>`以外のケースverifyしてないけど、ばぐってなければよいが...)

(2)において`a`は全部`small`側に入る。

**計算量:** (2)は $O(N)$

###  size(), empty()

```
inline usize size() const
inline usize smallSize() const
inline usize bigSize() const
inline bool empty() const
```

### insert

```cpp
template <class U>
requires std::same_as<std::remove_cvref_t<U>, T>
void insert(U&& v)
```

なにやらややこしいが、`T, const T&, T&&`以外で使用することは基本的に想定されていない

**計算量:** $O(\log N)$

### erase

```cpp
template <class U>
requires std::same_as<std::remove_cvref_t<U>, T>
void erase(U&& v)
```

なにやらややこしいが、`T, const T&, T&&`以外で使用することは基本的に想定されていない

**queに存在しない要素をeraseに呼んでもassertなどにはひっかからないが、後々のクエリでassert:Heap Underflowを発生させる。**

- これを咎めようとするとハッシュセットを別途持つ必要などがでてきて、諦めることにした。ユーザー側の責任とする。

**計算量:** $O(\log N)$


### adjust

```cpp
bool adjustSmall(usize K)
bool adjustBig(usize K)
```

それぞれ、`small`、`big`の個数が $K$ になるように調節し、trueを返す。`size() < K`のときは`false`を返し、何もしない。

### top

```cpp
const T& smallTop()
const T& bigTop()
```

呼び出す前に`smallSize(), bigSize()`を確認しておくと良い。

**計算量:** ならし $O(1)$

### prod

```cpp
const S::Element& smallProd() const;
const S::Element& bigProd() const
```

**計算量:** $O(1)$

### container

```cpp
std::pair<std::vector<T>, std::vector<T>> container() const
```

デバッグ目的。`first`にsmall, `second`にbigがある。
