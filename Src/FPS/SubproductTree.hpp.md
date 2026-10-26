---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/FPS.hpp
    title: Src/FPS/FPS.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/FPS/MultipointEvaluation.hpp
    title: "\u591A\u70B9\u8A55\u4FA1(Multipoint Evaluation)"
  - icon: ':heavy_check_mark:'
    path: Src/FPS/PolynomialInterpolationFast.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593 $O(N\\log^2N)$"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/fps_24_p.test.cpp
    title: Test/AtCoder/fps_24_p.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/multipoint_evaluation.test.cpp
    title: Test/LC/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/polynomial_interpolation/fast.test.cpp
    title: Test/LC/polynomial_interpolation/fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/FPS/SubproductTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/FPS/FPS.hpp\"\n\n#line 4 \"Src/FPS/FPS.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class FPS>\nconcept IndexedFPS = requires(FPS f, usize i) {\n    typename FPS::value_type;\n\
    \    { f.size() } -> std::convertible_to<usize>;\n    { f[i] } -> std::convertible_to<typename\
    \ FPS::value_type>;\n    f.reserve(0);\n    f.push_back(f[i]);\n};\n\ntemplate\
    \ <class FPS, class Conv>\nconcept Convolution = \n    std::regular_invocable<Conv,\
    \ const FPS&, const FPS&> &&\n    std::same_as<std::invoke_result_t<Conv, const\
    \ FPS&, const FPS&>, FPS>;\n\n} // namespace concepts\n\nstruct FPSMult {\n  \
    \  template <class FPS>\n    requires requires(const FPS& a, const FPS& b) {\n\
    \        { a * b } -> std::same_as<FPS>;\n    }\n    FPS operator()(const FPS&\
    \ a, const FPS& b) const {\n        return a * b;\n    }\n};\n\nstruct NaiveConvolution\
    \ {\n    template <class FPS>\n    FPS operator()(const FPS& a, const FPS& b)\
    \ const {\n        if (a.empty())\n            return b;\n        if (b.empty())\n\
    \            return a;\n        FPS res(a.size() + b.size() - 1);\n        for\
    \ (usize i = 0 ; i < a.size() ; i++)\n            for (usize j = 0 ; j < b.size()\
    \ ; j++)\n                res[i + j] += a[i] * b[j];\n        return res;\n  \
    \  }\n};\n\n} // namespace zawa\n#line 5 \"Src/FPS/SubproductTree.hpp\"\n\n#include\
    \ <cassert>\n#include <bit>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <concepts::IndexedFPS FPS, class Conv = FPSMult>\nrequires\
    \ concepts::Convolution<FPS, Conv>\nclass SubproductTree {\npublic:\n\n    SubproductTree(std::vector<FPS>\
    \ fs,Conv convolution = {})\n        : m_n{fs.size()}, m_sz{std::bit_ceil(m_n)},\
    \ m_tree(m_sz<<1,FPS{1}) {\n        for (usize i = 0 ; i < m_n ; i++)\n      \
    \      m_tree[m_sz+i]=std::move(fs[i]);\n        for (usize i = m_sz ; --i ; )\
    \ \n            m_tree[i]=convolution(m_tree[i<<1|0],m_tree[i<<1|1]);\n    }\n\
    \n    const FPS& root() const noexcept {\n        return m_tree[1];\n    }\n\n\
    \    const FPS& operator[](usize i) const noexcept {\n        assert(i and i <\
    \ m_tree.size());\n        return m_tree[i];\n    }\n\n    const FPS& leaf(usize\
    \ i) const noexcept {\n        assert(i < size());\n        return m_tree[m_sz+i];\n\
    \    }\n\n    inline usize size() const noexcept {\n        return m_n;\n    }\n\
    \n    inline usize innerSize() const noexcept {\n        return m_sz;\n    }\n\
    \nprivate:\n\n    usize m_n, m_sz;\n\n    std::vector<FPS> m_tree;\n\n};\n\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n#include \"./FPS.hpp\"\
    \n\n#include <cassert>\n#include <bit>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <concepts::IndexedFPS FPS, class Conv = FPSMult>\n\
    requires concepts::Convolution<FPS, Conv>\nclass SubproductTree {\npublic:\n\n\
    \    SubproductTree(std::vector<FPS> fs,Conv convolution = {})\n        : m_n{fs.size()},\
    \ m_sz{std::bit_ceil(m_n)}, m_tree(m_sz<<1,FPS{1}) {\n        for (usize i = 0\
    \ ; i < m_n ; i++)\n            m_tree[m_sz+i]=std::move(fs[i]);\n        for\
    \ (usize i = m_sz ; --i ; ) \n            m_tree[i]=convolution(m_tree[i<<1|0],m_tree[i<<1|1]);\n\
    \    }\n\n    const FPS& root() const noexcept {\n        return m_tree[1];\n\
    \    }\n\n    const FPS& operator[](usize i) const noexcept {\n        assert(i\
    \ and i < m_tree.size());\n        return m_tree[i];\n    }\n\n    const FPS&\
    \ leaf(usize i) const noexcept {\n        assert(i < size());\n        return\
    \ m_tree[m_sz+i];\n    }\n\n    inline usize size() const noexcept {\n       \
    \ return m_n;\n    }\n\n    inline usize innerSize() const noexcept {\n      \
    \  return m_sz;\n    }\n\nprivate:\n\n    usize m_n, m_sz;\n\n    std::vector<FPS>\
    \ m_tree;\n\n};\n\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/FPS/FPS.hpp
  isVerificationFile: false
  path: Src/FPS/SubproductTree.hpp
  requiredBy:
  - Src/FPS/PolynomialInterpolationFast.hpp
  - Src/FPS/MultipointEvaluation.hpp
  timestamp: '2026-10-26 13:52:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/fps_24_p.test.cpp
  - Test/LC/multipoint_evaluation.test.cpp
  - Test/LC/polynomial_interpolation/fast.test.cpp
documentation_of: Src/FPS/SubproductTree.hpp
layout: document
title: Subproduct Tree
---

## 概要

$n$ 個の多項式 $f_0,f_1,\dots,f_{n-1}$ が与えられたとき、セグ木上に区間の総積を保持する。

## ライブラリの使い方

### クラステンプレート

```
template <concepts::IndexedFPS FPS, class Conv = FPSMult>
requires concepts::Convolution<FPS, Conv>
class SubproductTree
```

`PolynomialProducts`や`KthTerm`などと同じ形式である。

### コンストラクタ

```
SubproductTree(std::vector<FPS> fs,Conv convolution = {})
```

`fs` が多項式の列 $f$ に対応する。典型的には `FPS` は `FPSNTTFriendly<MOD>` が選ばれるが、このときは`convolution`には何も指定しなくてよい。

効率的な`convolution`の実装が無い場合は`NaiveConvolution`を与えると良い。

**内部で`fs`のサイズが $2$ 冪になるように多項式 $1$ を末尾に挿入した後**、セグ木上にSubproduct Treeを構築する。

### メンバ

```cpp
const FPS& root() const noexcept

const FPS& operator[](usize i) const noexcept

const FPS& leaf(usize i) const noexcept

inline usize size() const noexcept

inline usize innerSize() const noexcept
```

`root()`は $\prod_{i} f_{i}$ を返す。

`operator[](i)`は セグ木の $i$ 番目の添え字に対応するノードを返す。`LazySegmentTree`と同じ添え字管理になっており、特に1-indexedである点には注意が必要かもしれない。

`leaf(i)` は $f_{i}$ を返す。

`size()` は元々の $f$ の要素数であり、 `innerSize()`はセグ木の葉の数である。つまり、セグ木のノード数は合計して `2*innerSize()-1` である。

## 計算量

`convolution`が $O(n)$ 回実行される。

基本的に`PolynomialProducts`と同様の計算量となる。次のような典型的な状況では $O(n\log^2 n)$ となる。

- `convolution`に`atcoder::convolution`を利用する。`FPS`の型が`FPSNTTFriendly<MOD>`である
- $f$ の全ての次数が $1$ である。より典型的には $x-a_i$ という形をしている

## 更新履歴

- 2026/10/26: 作成
