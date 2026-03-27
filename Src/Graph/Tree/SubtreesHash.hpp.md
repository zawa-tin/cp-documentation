---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/arc194_d.test.cpp
    title: Test/AtCoder/arc194_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/rooted_tree_isomorphism_classification.test.cpp
    title: Test/LC/rooted_tree_isomorphism_classification.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/SubtreesHash.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Graph/Tree/SubtreesHash.hpp\"\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <vector>\n#include <map>\n\nnamespace\
    \ zawa {\n\nclass SubtreesHasher {\npublic:\n\n    SubtreesHasher() = default;\n\
    \n    template <class G>\n    std::vector<usize> operator()(const G& g, usize\
    \ r = 0u) {\n        std::vector<usize> res(g.size());\n        auto dfs = [&](auto\
    \ dfs, usize v, usize p) -> usize {\n            std::vector<usize> ch;\n    \
    \        ch.reserve(g[v].size());\n            for (usize x : g[v]) if (x != p)\
    \ {\n                ch.push_back(dfs(dfs, x, v));\n            }\n          \
    \  std::sort(ch.begin(), ch.end());\n            return res[v] = mapping(std::move(ch));\n\
    \        };\n        dfs(dfs, r, std::numeric_limits<u32>::max());\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::map<std::vector<usize>, usize> map;\n\n\
    \    usize mapping(std::vector<usize>&& A) {\n        usize cur = map.size();\n\
    \        return map.try_emplace(std::move(A), cur).first->second;\n    }\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n#include <vector>\n#include <map>\n\nnamespace zawa {\n\nclass\
    \ SubtreesHasher {\npublic:\n\n    SubtreesHasher() = default;\n\n    template\
    \ <class G>\n    std::vector<usize> operator()(const G& g, usize r = 0u) {\n \
    \       std::vector<usize> res(g.size());\n        auto dfs = [&](auto dfs, usize\
    \ v, usize p) -> usize {\n            std::vector<usize> ch;\n            ch.reserve(g[v].size());\n\
    \            for (usize x : g[v]) if (x != p) {\n                ch.push_back(dfs(dfs,\
    \ x, v));\n            }\n            std::sort(ch.begin(), ch.end());\n     \
    \       return res[v] = mapping(std::move(ch));\n        };\n        dfs(dfs,\
    \ r, std::numeric_limits<u32>::max());\n        return res;\n    }\n\nprivate:\n\
    \n    std::map<std::vector<usize>, usize> map;\n\n    usize mapping(std::vector<usize>&&\
    \ A) {\n        usize cur = map.size();\n        return map.try_emplace(std::move(A),\
    \ cur).first->second;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/SubtreesHash.hpp
  requiredBy: []
  timestamp: '2025-04-09 18:50:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/arc194_d.test.cpp
  - Test/LC/rooted_tree_isomorphism_classification.test.cpp
documentation_of: Src/Graph/Tree/SubtreesHash.hpp
layout: document
title: "\u6839\u4ED8\u304D\u6728\u306E\u5404\u90E8\u5206\u6728\u3092\u30CF\u30C3\u30B7\
  \u30E5\u5024\u306B\u5909\u63DB\u3057\u305F\u5217"
---

## 概要

[Rooted Tree Isomorphism Classification](https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification) をします。$O(N\log N)$でやる代わりに、ハッシュ値が衝突することはありません。

## ライブラリの使い方

```cpp
SubtreesHasher()
```

ハッシュ列を返す関数オブジェクト

複数の木に対して同型判定をしたい場合は単一の関数オブジェクトを利用すること

```cpp
template <class G>
std::vector<usize> SubtreesHasher::operator()(const G& g, usize r = 0u)
```

`g`を`r`を根とした木の隣接リストと捉え、各頂点 $v$ の部分木のハッシュ値を返す。

operator()を二回以上呼ぶとき、返り値の $\max + 1$ が種類数と限らないことに注意

- LCのテストでは一回しか呼ばないため、 $\max + 1$ が種類数と一致している
