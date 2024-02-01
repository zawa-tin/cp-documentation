---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc288_e.test.cpp
    title: ABC288-E Wish List
  - icon: ':heavy_check_mark:'
    path: Test/LC/lca.test.cpp
    title: Test/LC/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/staticrmq.test.cpp
    title: Test/LC/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n\nnamespace zawa\
    \ {\n\ntemplate <class Structure>\nclass SparseTable {\nprivate:\n    using Value\
    \ = typename Structure::Element;\n    std::vector<u32> L;\n    std::vector<std::vector<Value>>\
    \ dat;\npublic:\n\n    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <ostream>\n\nnamespace zawa {\n\ntemplate <class\
    \ Structure>\nclass SparseTable {\nprivate:\n    using Value = typename Structure::Element;\n\
    \    std::vector<u32> L;\n    std::vector<std::vector<Value>> dat;\npublic:\n\n\
    \    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/DataStructure/SparseTable/SparseTable.hpp
  requiredBy:
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  timestamp: '2023-11-01 12:01:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/staticrmq.test.cpp
  - Test/LC/lca.test.cpp
  - Test/AtCoder/abc288_e.test.cpp
documentation_of: Src/DataStructure/SparseTable/SparseTable.hpp
layout: document
title: Sparse Table
---

ドキュメントを書く気力が行方不明！

等冪則を持つ演算、忘れがち(Disjoint Sparse Tableを書きましょう....)
