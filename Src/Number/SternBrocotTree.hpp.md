---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/stern_brocot_tree.test.cpp
    title: Test/LC/stern_brocot_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Number/SternBrocotTree.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Number/SternBrocotTree.hpp\"\n\n#include\
    \ <algorithm>\n#include <concepts>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n#include <tuple>\n\nnamespace zawa {\n\nnamespace SternBrocotTree\
    \ {\n\nnamespace sbt_internal {\n\ntemplate <class T>\nconcept Integer = std::integral<T>\
    \ or std::same_as<T, __int128_t> or std::same_as<T, __uint128_t>;\n\n} // namespace\
    \ sbt_internal\n\nenum Direction {\n    Left,\n    Right\n};\n\ntemplate <sbt_internal::Integer\
    \ T>\nusing Path = std::vector<std::pair<Direction, T>>;\n\ntemplate <sbt_internal::Integer\
    \ T>\nusing Node = std::pair<T, T>;\n\ntemplate <sbt_internal::Integer T>\nPath<T>\
    \ Encode(Node<T> node) {\n    auto [a, b] = node;\n    u32 d = [&]() {\n     \
    \   if (a < b) {\n            std::swap(a, b);\n            return 0;\n      \
    \  }\n        else {\n            return 1;\n        }\n    }();\n    std::vector<T>\
    \ quos;\n    while (b) {\n        quos.push_back(a / b);\n        T r = a % b;\n\
    \        a = b;\n        b = r;\n    }\n    if (quos.size()) {\n        quos.back()--;\n\
    \        if (quos.back() == 0)\n            quos.pop_back();\n    }\n    Path<T>\
    \ res;\n    for (T q : quos) {\n        res.push_back({static_cast<Direction>(d),\
    \ q});\n        d ^= 1;\n    }\n    return res;\n}\n\nnamespace sbt_internal {\n\
    \ntemplate <Integer T>\nstd::tuple<Node<T>, Node<T>, Node<T>> Decode(const Path<T>&\
    \ path) {\n    T a = 0, b = 1, c = 1, d = 1, e = 1, f = 0;\n    for (auto [direction,\
    \ step] : path) {\n        if (direction == Left) {\n            e = c + (step\
    \ - 1) * a;\n            f = d + (step - 1) * b;\n            c += step * a;\n\
    \            d += step * b;\n        }\n        else if (direction == Right) {\n\
    \            a = c + (step - 1) * e;\n            b = d + (step - 1) * f;\n  \
    \          c += step * e;\n            d += step * f;\n        } \n    }\n   \
    \ return {Node<T>{a, b}, Node<T>{c, d}, Node<T>{e, f}};\n}\n\n} // namespace sbt_internal\n\
    \ntemplate <sbt_internal::Integer T>\nNode<T> Decode(const Path<T>& path) {\n\
    \    return std::get<1>(sbt_internal::Decode(path));\n}\n\ntemplate <sbt_internal::Integer\
    \ T>\nNode<T> LCA(Node<T> p, Node<T> q) {\n    auto a = Encode(p), b = Encode(q);\n\
    \    Path<T> path;\n    for (usize i = 0 ; i < std::min(a.size(), b.size()) ;\
    \ i++) {\n        if (a[i].first != b[i].first)\n            break;\n        path.push_back({a[i].first,\
    \ std::min(a[i].second, b[i].second)});\n        if (a[i].second != b[i].second)\n\
    \            break;\n    }\n    return Decode(path);\n}\n\n// depth is 0-indexed\n\
    template <sbt_internal::Integer T>\nstd::optional<Node<T>> Ancestor(u64 dep, Node<T>\
    \ n) {\n    Path<T> path;\n    for (auto [direction, step] : Encode(n)) {\n  \
    \      if (dep == 0)\n           break;\n        u64 s = std::min<u64>(dep, step);\n\
    \        path.push_back({direction, s});\n        dep -= s;\n    }\n    if (dep)\n\
    \        return std::nullopt;\n    else\n        return Decode(path);\n}\n\ntemplate\
    \ <sbt_internal::Integer T>\nstd::pair<Node<T>, Node<T>> Range(Node<T> n) {\n\
    \    Node<T> l, r;\n    std::tie(l, std::ignore, r) = sbt_internal::Decode(Encode(n));\n\
    \    return {l, r};\n}\n\n} // namespace SternBrocotTree\n\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <concepts>\n#include <optional>\n#include <utility>\n#include <vector>\n\
    #include <tuple>\n\nnamespace zawa {\n\nnamespace SternBrocotTree {\n\nnamespace\
    \ sbt_internal {\n\ntemplate <class T>\nconcept Integer = std::integral<T> or\
    \ std::same_as<T, __int128_t> or std::same_as<T, __uint128_t>;\n\n} // namespace\
    \ sbt_internal\n\nenum Direction {\n    Left,\n    Right\n};\n\ntemplate <sbt_internal::Integer\
    \ T>\nusing Path = std::vector<std::pair<Direction, T>>;\n\ntemplate <sbt_internal::Integer\
    \ T>\nusing Node = std::pair<T, T>;\n\ntemplate <sbt_internal::Integer T>\nPath<T>\
    \ Encode(Node<T> node) {\n    auto [a, b] = node;\n    u32 d = [&]() {\n     \
    \   if (a < b) {\n            std::swap(a, b);\n            return 0;\n      \
    \  }\n        else {\n            return 1;\n        }\n    }();\n    std::vector<T>\
    \ quos;\n    while (b) {\n        quos.push_back(a / b);\n        T r = a % b;\n\
    \        a = b;\n        b = r;\n    }\n    if (quos.size()) {\n        quos.back()--;\n\
    \        if (quos.back() == 0)\n            quos.pop_back();\n    }\n    Path<T>\
    \ res;\n    for (T q : quos) {\n        res.push_back({static_cast<Direction>(d),\
    \ q});\n        d ^= 1;\n    }\n    return res;\n}\n\nnamespace sbt_internal {\n\
    \ntemplate <Integer T>\nstd::tuple<Node<T>, Node<T>, Node<T>> Decode(const Path<T>&\
    \ path) {\n    T a = 0, b = 1, c = 1, d = 1, e = 1, f = 0;\n    for (auto [direction,\
    \ step] : path) {\n        if (direction == Left) {\n            e = c + (step\
    \ - 1) * a;\n            f = d + (step - 1) * b;\n            c += step * a;\n\
    \            d += step * b;\n        }\n        else if (direction == Right) {\n\
    \            a = c + (step - 1) * e;\n            b = d + (step - 1) * f;\n  \
    \          c += step * e;\n            d += step * f;\n        } \n    }\n   \
    \ return {Node<T>{a, b}, Node<T>{c, d}, Node<T>{e, f}};\n}\n\n} // namespace sbt_internal\n\
    \ntemplate <sbt_internal::Integer T>\nNode<T> Decode(const Path<T>& path) {\n\
    \    return std::get<1>(sbt_internal::Decode(path));\n}\n\ntemplate <sbt_internal::Integer\
    \ T>\nNode<T> LCA(Node<T> p, Node<T> q) {\n    auto a = Encode(p), b = Encode(q);\n\
    \    Path<T> path;\n    for (usize i = 0 ; i < std::min(a.size(), b.size()) ;\
    \ i++) {\n        if (a[i].first != b[i].first)\n            break;\n        path.push_back({a[i].first,\
    \ std::min(a[i].second, b[i].second)});\n        if (a[i].second != b[i].second)\n\
    \            break;\n    }\n    return Decode(path);\n}\n\n// depth is 0-indexed\n\
    template <sbt_internal::Integer T>\nstd::optional<Node<T>> Ancestor(u64 dep, Node<T>\
    \ n) {\n    Path<T> path;\n    for (auto [direction, step] : Encode(n)) {\n  \
    \      if (dep == 0)\n           break;\n        u64 s = std::min<u64>(dep, step);\n\
    \        path.push_back({direction, s});\n        dep -= s;\n    }\n    if (dep)\n\
    \        return std::nullopt;\n    else\n        return Decode(path);\n}\n\ntemplate\
    \ <sbt_internal::Integer T>\nstd::pair<Node<T>, Node<T>> Range(Node<T> n) {\n\
    \    Node<T> l, r;\n    std::tie(l, std::ignore, r) = sbt_internal::Decode(Encode(n));\n\
    \    return {l, r};\n}\n\n} // namespace SternBrocotTree\n\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Number/SternBrocotTree.hpp
  requiredBy: []
  timestamp: '2025-08-23 22:47:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/stern_brocot_tree.test.cpp
documentation_of: Src/Number/SternBrocotTree.hpp
layout: document
title: Stern-Brocot Tree
---

## 概要

有理数の問題では、この構造を考えると、嬉しいことがあります！

## ライブラリの使い方

他のライブラリとは異なり、`SternBrocotTree`という名前空間の下で型エイリアスや関数を提供している。

### Node

```cpp
template <sbt_internal::Integer T>
using Node = std::pair<T, T>;
```

有理数を表す。`T`は`std::integral`または128bit整数である必要がある。

### Path

```cpp
enum Direction {
    Left,
    Right
};

template <sbt_internal::Integer T>
using Path = std::vector<std::pair<Direction, T>>;
```

Stern-Brocot Tree(SBT)の根からのパスを表す。SBTは二分木であり左子に進むことを`Left`、右子に進むことを`Right`で表す。

パスは非常に長くなることがあるため、連長圧縮して表現されている。

- 既約分数 $\frac{a}{b}$ のパスを連長圧縮するとその長さは $O(\log\max\\{a, b\\})$ になることが知られている。

### Encode

```
template <sbt_internal::Integer T>
Path<T> Encode(Node<T> node)
```

`node` に対応するパスを返す。

**計算量**: $O(\log \max\\{ a, b \\})$

### Decode

```
template <sbt_internal::Integer T>
Node<T> Decode(const Path<T>& path)
```

`path`に対応する`Node`を返す。

**計算量**: `path`の要素数を $n$ として $O(n)$

### LCA

```
template <sbt_internal::Integer T>
Node<T> LCA(Node<T> p, Node<T> q)
```

`p, q`に対応するLCAの`Node`を返す。 $p\le \frac{a}{b} \le q$ を満たす $\frac{a}{b}$ であって $b$ が最小であるものを見つけることに対応している。

**計算量**: `Encode`を2回、`Decode`を1回呼び出すことがボトルネック

### Ancestor

```
template <sbt_internal::Integer T>
std::optional<Node<T>> Ancestor(u64 dep, Node<T> n)
```

`n`に対応するパス上の深さ`dep`の頂点を返す。根の深さを $0$ としている。

**計算量**: `Encode, Decode`をそれぞれ1回呼び出すことがボトルネック

### Range

```
template <sbt_internal::Integer T>
std::pair<Node<T>, Node<T>> Range(Node<T> n)
```

`n`の部分木の有理数は有理数の開区間を成す。この両端を返す。

**計算量**: `Decode`を一回呼び出す
