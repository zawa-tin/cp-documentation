---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/CF/CF1070-F.test.cpp
    title: Test/CF/CF1070-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Utility/GreyCode.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Utility/GreyCode.hpp\"\n\n#include <bit>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nenum class GreyCodeOp\
    \ {\n    Add,\n    Remove,\n    Access\n};\n\nstd::vector<std::pair<GreyCodeOp,\
    \ usize>> GreyCode(usize n) {\n    std::vector<std::pair<GreyCodeOp, usize>> res;\n\
    \    res.reserve(1 << (n + 1));\n    usize cur = 0;\n    res.emplace_back(GreyCodeOp::Access,\
    \ cur);\n    for (usize i = 1 ; i < (1 << n) ; i++) {\n        usize nxt = i ^\
    \ (i >> 1);\n        usize k = std::countr_zero<unsigned>(cur ^ nxt);\n      \
    \  if (cur & (1 << k))\n            res.emplace_back(GreyCodeOp::Remove, k);\n\
    \        else\n            res.emplace_back(GreyCodeOp::Add, k);\n        res.emplace_back(GreyCodeOp::Access,\
    \ nxt);\n        cur = nxt;\n    }\n    return res;\n}\n\nnamespace concepts {\n\
    \ntemplate <class T>\nconcept SubsetProd = requires {\n    typename T::Element;\n\
    \    { T::identity() } -> std::same_as<typename T::Element>;\n    { T::add(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n    { T::remove(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n\n} // namespace\
    \ concepts\n\ntemplate <concepts::SubsetProd T>\nstd::vector<typename T::Element>\
    \ EnumerateSubsetProduct(std::vector<typename T::Element> A) {\n    std::vector<typename\
    \ T::Element> res(1 << A.size());\n    typename T::Element cur = T::identity();\n\
    \    for (auto [type, idx] : GreyCode(A.size())) {\n        switch (type) {\n\
    \        case GreyCodeOp::Add:\n            cur = T::add(cur, A[idx]);\n     \
    \       break;\n        case GreyCodeOp::Remove:\n            cur = T::remove(cur,\
    \ A[idx]);\n            break;\n        case GreyCodeOp::Access:\n           \
    \ res[idx] = cur;\n            break;\n        }\n    }\n    return res;\n}\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <bit>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\nenum class GreyCodeOp\
    \ {\n    Add,\n    Remove,\n    Access\n};\n\nstd::vector<std::pair<GreyCodeOp,\
    \ usize>> GreyCode(usize n) {\n    std::vector<std::pair<GreyCodeOp, usize>> res;\n\
    \    res.reserve(1 << (n + 1));\n    usize cur = 0;\n    res.emplace_back(GreyCodeOp::Access,\
    \ cur);\n    for (usize i = 1 ; i < (1 << n) ; i++) {\n        usize nxt = i ^\
    \ (i >> 1);\n        usize k = std::countr_zero<unsigned>(cur ^ nxt);\n      \
    \  if (cur & (1 << k))\n            res.emplace_back(GreyCodeOp::Remove, k);\n\
    \        else\n            res.emplace_back(GreyCodeOp::Add, k);\n        res.emplace_back(GreyCodeOp::Access,\
    \ nxt);\n        cur = nxt;\n    }\n    return res;\n}\n\nnamespace concepts {\n\
    \ntemplate <class T>\nconcept SubsetProd = requires {\n    typename T::Element;\n\
    \    { T::identity() } -> std::same_as<typename T::Element>;\n    { T::add(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n    { T::remove(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n\n} // namespace\
    \ concepts\n\ntemplate <concepts::SubsetProd T>\nstd::vector<typename T::Element>\
    \ EnumerateSubsetProduct(std::vector<typename T::Element> A) {\n    std::vector<typename\
    \ T::Element> res(1 << A.size());\n    typename T::Element cur = T::identity();\n\
    \    for (auto [type, idx] : GreyCode(A.size())) {\n        switch (type) {\n\
    \        case GreyCodeOp::Add:\n            cur = T::add(cur, A[idx]);\n     \
    \       break;\n        case GreyCodeOp::Remove:\n            cur = T::remove(cur,\
    \ A[idx]);\n            break;\n        case GreyCodeOp::Access:\n           \
    \ res[idx] = cur;\n            break;\n        }\n    }\n    return res;\n}\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Utility/GreyCode.hpp
  requiredBy: []
  timestamp: '2025-12-14 15:22:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/CF/CF1070-F.test.cpp
documentation_of: Src/Utility/GreyCode.hpp
layout: document
title: "\u30B0\u30EC\u30A4\u30B3\u30FC\u30C9\u306B\u3088\u308B\u90E8\u5206\u96C6\u5408\
  \u5217\u6319"
---

# 概要

$0$ 以上 $2^n$ 未満の要素からなる順列であって、任意の隣接する $2$ 要素のpopcountの差が $1$ であるものを取得する。

これによって、例えばbit全探索で $\Theta (N2^{N})$ かかるパートを $O(2^N)$ に改善できる事があるかもしれない。

- あまり頭の良いことをしなくても、例えばDFSで $O(2^N)$ は達成できるのだが、グレイコードをしたほうが定数倍がよさそう

## ライブラリの使い方

### GreyCode

```cpp
std::vector<std::pair<GreyCodeOp, usize>> GreyCode(usize n)
```

順列を得るための操作の命令の列が与えられる。 `GreyCodeOp`とは以下のような`enum class`であり、`second`に入っている非負整数(`idx`と呼ぶ)に応じて以下のような意味がある

```cpp
enum class GreyCodeOp {
    Add, // 2^idxを足す
    Remove, // 2^idxを引く
    Access // 現在idxがある
};
```

**計算量:** $O(2^{n})$

### EnumerateSubsetProduct

```cpp
template <concepts::SubsetProd T>
std::vector<typename T::Element> EnumerateSubsetProduct(std::vector<typename T::Element> A)
```

先述の`Add, Remove`の演算を`T`に与えたとき、 $2^{n}$ 個の要素を列挙して返す。

返り値の $i$ 番目の要素は $i$ の二進数表示で立っている桁が $S_i = \\{ j_1, j_2, \dots, j_k \\}$ だとしたとき、 $\prod_{j\in S_i} A_j$ である。

テンプレートの雛形

```cpp
struct SPD {
    using Element = ;
    static Element identity() {
    } 
    static Element add(Element l, Element r) {
    }
    static Element remove(Element l, Element r) {
    }
};
```

ここで、`remove`とは`l`に含まれている`r`を削除する関数である。可換群の逆元を計算するのとは若干違うことに注意する必要があるかもしれない。
- たとえば`add`が掛け算をする関数だったとして、`remove`に与えられる引数は、`l`が`r`の倍数であることが保証される。(そのため、整数で閉じていると考えてよい)

**計算量**

- $A$ の要素数を $N$ とする
- `add, remove`を合計 $2^N - 1$ 回呼び出す
- `identity()`を丁度一回呼び出す
- `GreyCode(N)`を一回呼び出す
- $+O(2^N)$
