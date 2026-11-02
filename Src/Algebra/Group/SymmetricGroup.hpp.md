---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/aalc001_l.test.cpp
    title: Test/AtCoder/aalc001_l.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc470_d.test.cpp
    title: Test/AtCoder/abc470_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Algebra/Group/SymmetricGroup.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Algebra/Group/SymmetricGroup.hpp\"\n\n#include\
    \ <array>\n#include <cassert>\n#include <concepts>\n#include <numeric>\n#include\
    \ <span>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <usize N = std::dynamic_extent,std::integral T = usize>\n\
    class SymmetricGroup {\npublic:\n\n    using Container = std::conditional_t<N==std::dynamic_extent,std::vector<T>,std::array<T,N>>;\n\
    \n    using Element = SymmetricGroup;\n\n    constexpr SymmetricGroup() requires\
    \ (N!=std::dynamic_extent) {\n        std::iota(m_perm.begin(),m_perm.end(),T{0});\n\
    \        std::iota(m_inv.begin(),m_inv.end(),T{0});\n    }\n\n    explicit SymmetricGroup(usize\
    \ n) requires (N==std::dynamic_extent) : m_perm(n), m_inv(n) {\n        std::iota(m_perm.begin(),m_perm.end(),T{0});\n\
    \        std::iota(m_inv.begin(),m_inv.end(),T{0});\n    }\n\n    explicit SymmetricGroup(std::array<T,N>\
    \ p) requires (N!=std::dynamic_extent) : m_perm{std::move(p)}, m_inv{} {\n   \
    \     for (usize i = 0 ; i < N ; i++)\n            m_inv[m_perm[i]]=i;\n    }\n\
    \n    explicit SymmetricGroup(std::vector<T> p) requires (N==std::dynamic_extent)\
    \ : m_perm{std::move(p)}, m_inv(m_perm.size()) {\n        for (usize i = 0 ; i\
    \ < size() ; i++)\n            m_inv[m_perm[i]]=i;\n    }\n\n    inline constexpr\
    \ usize size() const noexcept {\n        return m_perm.size();\n    }\n\n    inline\
    \ usize operator[](usize i) const noexcept {\n        assert(i<size());\n    \
    \    return m_perm[i];\n    }\n\n    inline T position(usize i) const noexcept\
    \ {\n        assert(i<size());\n        return m_inv[i];\n    }\n\n    void swap(usize\
    \ i,usize j) {\n        assert(i < size());\n        assert(j < size());\n   \
    \     std::swap(m_inv[m_perm[i]],m_inv[m_perm[j]]);\n        std::swap(m_perm[i],m_perm[j]);\n\
    \    }\n\n    void composite(const SymmetricGroup& sym) {\n        assert(size()==sym.size());\n\
    \        Container perm;\n        if constexpr (std::same_as<Container,std::vector<T>>)\n\
    \            perm.resize(size());\n        for (usize i = 0 ; i < size() ; i++)\
    \ {\n            perm[i]=sym[m_perm[i]];\n            m_inv[perm[i]]=i;\n    \
    \    }\n        m_perm=std::move(perm);\n    }\n\n    void invert() {\n      \
    \  std::swap(m_perm,m_inv);\n    }\n\n    static SymmetricGroup identity() {\n\
    \        return SymmetricGroup{};\n    }\n\n    static SymmetricGroup operation(SymmetricGroup\
    \ l,const SymmetricGroup& r) {\n        l.composite(r);\n        return l;\n \
    \   }\n\n    static SymmetricGroup inverse(SymmetricGroup sym) {\n        sym.invert();\n\
    \        return sym;\n    }\n\n    template <class U,usize M>\n    static std::array<U,M>\
    \ action(const SymmetricGroup& g,const std::array<U,M>& a) requires (N == std::dynamic_extent\
    \ or N <= M) {\n        assert(g.size() <= M);\n        std::array<U,M> res;\n\
    \        for (usize i = 0 ; i < g.size() ; i++)\n            res[g[i]]=a[i];\n\
    \        for (usize i = g.size() ; i < a.size() ; i++)\n            res[i]=a[i];\n\
    \        return res;\n    }\n\n    template <class U>\n    static std::vector<U>\
    \ action(const SymmetricGroup& g,const std::vector<U>& a) {\n        assert(g.size()<=a.size());\n\
    \        std::vector<U> res(a.size());\n        for (usize i = 0 ; i < g.size()\
    \ ; i++)\n            res[g[i]]=a[i];\n        for (usize i = g.size() ; i < a.size()\
    \ ; i++)\n            res[i]=a[i];\n        return res;\n    }\n\nprivate:\n\n\
    \    Container m_perm, m_inv;\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <array>\n\
    #include <cassert>\n#include <concepts>\n#include <numeric>\n#include <span>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <usize N = std::dynamic_extent,std::integral T = usize>\nclass\
    \ SymmetricGroup {\npublic:\n\n    using Container = std::conditional_t<N==std::dynamic_extent,std::vector<T>,std::array<T,N>>;\n\
    \n    using Element = SymmetricGroup;\n\n    constexpr SymmetricGroup() requires\
    \ (N!=std::dynamic_extent) {\n        std::iota(m_perm.begin(),m_perm.end(),T{0});\n\
    \        std::iota(m_inv.begin(),m_inv.end(),T{0});\n    }\n\n    explicit SymmetricGroup(usize\
    \ n) requires (N==std::dynamic_extent) : m_perm(n), m_inv(n) {\n        std::iota(m_perm.begin(),m_perm.end(),T{0});\n\
    \        std::iota(m_inv.begin(),m_inv.end(),T{0});\n    }\n\n    explicit SymmetricGroup(std::array<T,N>\
    \ p) requires (N!=std::dynamic_extent) : m_perm{std::move(p)}, m_inv{} {\n   \
    \     for (usize i = 0 ; i < N ; i++)\n            m_inv[m_perm[i]]=i;\n    }\n\
    \n    explicit SymmetricGroup(std::vector<T> p) requires (N==std::dynamic_extent)\
    \ : m_perm{std::move(p)}, m_inv(m_perm.size()) {\n        for (usize i = 0 ; i\
    \ < size() ; i++)\n            m_inv[m_perm[i]]=i;\n    }\n\n    inline constexpr\
    \ usize size() const noexcept {\n        return m_perm.size();\n    }\n\n    inline\
    \ usize operator[](usize i) const noexcept {\n        assert(i<size());\n    \
    \    return m_perm[i];\n    }\n\n    inline T position(usize i) const noexcept\
    \ {\n        assert(i<size());\n        return m_inv[i];\n    }\n\n    void swap(usize\
    \ i,usize j) {\n        assert(i < size());\n        assert(j < size());\n   \
    \     std::swap(m_inv[m_perm[i]],m_inv[m_perm[j]]);\n        std::swap(m_perm[i],m_perm[j]);\n\
    \    }\n\n    void composite(const SymmetricGroup& sym) {\n        assert(size()==sym.size());\n\
    \        Container perm;\n        if constexpr (std::same_as<Container,std::vector<T>>)\n\
    \            perm.resize(size());\n        for (usize i = 0 ; i < size() ; i++)\
    \ {\n            perm[i]=sym[m_perm[i]];\n            m_inv[perm[i]]=i;\n    \
    \    }\n        m_perm=std::move(perm);\n    }\n\n    void invert() {\n      \
    \  std::swap(m_perm,m_inv);\n    }\n\n    static SymmetricGroup identity() {\n\
    \        return SymmetricGroup{};\n    }\n\n    static SymmetricGroup operation(SymmetricGroup\
    \ l,const SymmetricGroup& r) {\n        l.composite(r);\n        return l;\n \
    \   }\n\n    static SymmetricGroup inverse(SymmetricGroup sym) {\n        sym.invert();\n\
    \        return sym;\n    }\n\n    template <class U,usize M>\n    static std::array<U,M>\
    \ action(const SymmetricGroup& g,const std::array<U,M>& a) requires (N == std::dynamic_extent\
    \ or N <= M) {\n        assert(g.size() <= M);\n        std::array<U,M> res;\n\
    \        for (usize i = 0 ; i < g.size() ; i++)\n            res[g[i]]=a[i];\n\
    \        for (usize i = g.size() ; i < a.size() ; i++)\n            res[i]=a[i];\n\
    \        return res;\n    }\n\n    template <class U>\n    static std::vector<U>\
    \ action(const SymmetricGroup& g,const std::vector<U>& a) {\n        assert(g.size()<=a.size());\n\
    \        std::vector<U> res(a.size());\n        for (usize i = 0 ; i < g.size()\
    \ ; i++)\n            res[g[i]]=a[i];\n        for (usize i = g.size() ; i < a.size()\
    \ ; i++)\n            res[i]=a[i];\n        return res;\n    }\n\nprivate:\n\n\
    \    Container m_perm, m_inv;\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Algebra/Group/SymmetricGroup.hpp
  requiredBy: []
  timestamp: '2026-11-02 13:53:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/aalc001_l.test.cpp
  - Test/AtCoder/abc470_d.test.cpp
documentation_of: Src/Algebra/Group/SymmetricGroup.hpp
layout: document
title: "\u5BFE\u79F0\u7FA4"
---

## 概要

順列に関するUtilityライブラリです。

`concepts::Group`の要件を満たすように設計されています。しかし、内部で逆順列も一緒に管理しているため、データ構造に載せると若干オーバーヘッドがきついです。

## ライブラリの使い方

### テンプレート引数

```cpp
template <usize N = std::dynamic_extent,std::integral T = usize>
class SymmetricGroup
```

要素数が固定(コンパイル時定数にできる)ときは`N`にその定数を指定する。

そうでないときは`std::dynamic_extent`を指定する。

`T`は(要素数を $n$ として) $0$ 以上 $n$ 未満の整数を表現できる型ならなんでも良いが、基本デフォルトの`usize`で良いハズ。

典型的な運用では以下のどちらかでクラスを指定すれば十分です

```cpp
zawa::SymmetricGroup<3> sym;// (要素数のみを指定する)
zawa::SymmetricGroup sym(n);//(n要素で初期化)
```

以降実際の要素数を $n$ とします。

### コンストラクタ

```cpp
constexpr SymmetricGroup() requires (N!=std::dynamic_extent) (1)
explicit SymmetricGroup(usize n) requires (N==std::dynamic_extent) (2)
explicit SymmetricGroup(std::array<T,N> p) requires (N!=std::dynamic_extent) (3)
explicit SymmetricGroup(std::vector<T> p) requires (N==std::dynamic_extent) (4)
```

(1),(2)どちらも恒等置換で初期化します。特に、(2)ではテンプレート引数で指定しなかった要素数をコンストラクタに与えます。

(3),(4)は順列 $p$ からクラスを作成します。 $p$ が順列でないときの動作は保証しません。

### メンバ

```cpp
inline constexpr usize size() const noexcept
inline usize operator[](usize i) const noexcept
inline T position(usize i) const noexcept
void swap(usize i,usize j)
void composite(const SymmetricGroup& sym) 
void invert()
```

- `size()`は要素数を取得する。 $O(1)$
- `operator[](i)`は順列の $i$ 番目の要素を取得する。 $O(1)$
- `position(i)`は逆順列の $i$ 番目の要素を取得する。 $O(1)$
- `swap(i,j)`は現在の順列の位置 $i,j$ をswapする。 $O(1)$
- `composite(sym)`は現在の順列を `sym` でpermuteする。 $O(n)$
- `invert()`は逆順列に取り換える。 
    - `N`が`std::dynamic_extent`のとき、 $O(1)$
    - そうでないとき、 $O(n)$

### Groupに関するstaticメンバ

```cpp
static SymmetricGroup identity()
static SymmetricGroup operation(SymmetricGroup l,const SymmetricGroup& r)
static SymmetricGroup inverse(SymmetricGroup sym)
```

他の`Group`と同じような意味で設計されている。特に、データ構造ライブラリに載せるときに使うので、これらを使用するときは`N`が`std::dynamic_extent`でないことが想定されている。

- `identity()`は恒等置換を返す
- `operation(l,r)`は $l\rightarrow r$ の順で置換を施して得られる順列を返す。
- `inverse()`は逆順列を返す。

### action

```
template <class U,usize M>
static std::array<U,M> action(const SymmetricGroup& g,const std::array<U,M>& a) requires (N == std::dynamic_extent or N <= M) 

template <class U>
static std::vector<U> action(const SymmetricGroup& g,const std::vector<U>& a) 
```

列`a`を`g`でpermuteして返す。`a`の要素数 $M$ は`g`の要素数 $N$ 以上である必要があり、特に $M\gt N$ のときは、前 $N$ 要素をpermuteし、残りの $M-N$ 要素はそのままの順番で返す。

## 更新履歴

- 2026/11/02: 作成
