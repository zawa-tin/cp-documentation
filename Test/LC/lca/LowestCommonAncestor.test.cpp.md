---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ChminMonoid.hpp
    title: Src/Algebra/Monoid/ChminMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  - icon: ':heavy_check_mark:'
    path: Src/Template/IOSetting.hpp
    title: "io\u307E\u308F\u308A\u306E\u8A2D\u5B9A"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Test/LC/lca/LowestCommonAncestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\
    \n\n#line 4 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <optional>\n\nnamespace zawa {\n\ntemplate <class T, class U>\nclass ChminMonoidData\
    \ {\nprivate:\n    std::optional<T> priority_{};\n    U value_{};\npublic:\n \
    \   ChminMonoidData() = default;\n    ChminMonoidData(const U& value)\n      \
    \  : priority_{std::nullopt}, value_{value} {}\n    ChminMonoidData(const T& priority,\
    \ const U& value)\n        : priority_{priority}, value_{value} {}\n\n    constexpr\
    \ bool infty() const noexcept {\n        return !priority_.has_value();\n    }\n\
    \    constexpr const T& priority() const noexcept {\n        return priority_.value();\n\
    \    }\n    constexpr const U& value() const noexcept {\n        return value_;\n\
    \    }\n    friend constexpr bool operator<(const ChminMonoidData& l, const ChminMonoidData&\
    \ r) {\n        if (l.infty()) return false;\n        else if (r.infty()) return\
    \ true;\n        else return l.priority() < r.priority();\n    }\n};\n\ntemplate\
    \ <class T, class U>\nstruct ChminMonoid {\n    using Element = ChminMonoidData<T,\
    \ U>;\n    static Element identity() noexcept {\n        return Element{};\n \
    \   }\n    // \u30BF\u30A4\u30D6\u30EC\u30FC\u30AF\u306Fl\u5074\u3092\u512A\u5148\
    \u3059\u308B\u3088\u3046\u306B\u306A\u3063\u3066\u3044\u308B\u3002\n    static\
    \ Element operation(const Element& l, const Element& r) noexcept {\n        return\
    \ (r < l ? r : l);\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#include <vector>\n\
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
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 6 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 9 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class V>\nclass LowestCommonAncestor {\nprivate:\n\
    \    using Monoid = ChminMonoid<u32, V>;\n\npublic:\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const std::vector<std::vector<V>>& tree,\
    \ V r = V{}) \n        : n_{tree.size()}, depth_(tree.size()), L_(tree.size()),\
    \ R_(tree.size()), st_{} {\n            std::vector<typename Monoid::Element>\
    \ init;\n            init.reserve(2 * size());\n            auto dfs{[&](auto\
    \ dfs, V v, V p) -> void {\n                depth_[v] = (p == INVALID ? 0u : depth_[p]\
    \ + 1);\n                L_[v] = (u32)init.size();\n                for (auto\
    \ x : tree[v]) {\n                    if (x == p) {\n                        continue;\n\
    \                    }\n                    init.emplace_back(depth_[v], v);\n\
    \                    dfs(dfs, x, v);\n                }\n                R_[v]\
    \ = (u32)init.size();\n            }};\n            dfs(dfs, r, INVALID);\n  \
    \          st_ = SparseTable<Monoid>(init);\n    }\n\n    V operator()(V u, V\
    \ v) const {\n        assert(verify(u));\n        assert(verify(v));\n       \
    \ if (L_[u] > L_[v]) {\n            std::swap(u, v);\n        }\n        return\
    \ u == v ? u : st_.product(L_[u], R_[v]).value();\n    }\n\n    V lca(V u, V v)\
    \ const {\n        return (*this)(u, v);\n    }\n\n    inline u32 depth(V v) const\
    \ noexcept {\n        assert(verify(v));\n        return depth_[v];\n    }\n\n\
    \    u32 distance(V u, V v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        return depth(u) + depth(v) - 2u * depth((*this)(u, v));\n    }\n\n  \
    \  bool isAncestor(V p, V v) const {\n        assert(verify(p));\n        assert(verify(v));\n\
    \        return L_[p] <= L_[v] and R_[v] <= R_[p];\n    }\n\nprotected:\n    u32\
    \ left(V v) const noexcept {\n        return L_[v];\n    }\n\n    inline usize\
    \ size() const {\n        return n_;\n    }\n\n    inline bool verify(V v) const\
    \ {\n        return v < (V)size();\n    }\n\nprivate:\n    static constexpr V\
    \ INVALID{static_cast<V>(-1)};\n    usize n_{};\n    std::vector<u32> depth_,\
    \ L_, R_;\n    SparseTable<Monoid> st_;\n};\n\n} // namespace zawa\n#line 5 \"\
    Test/LC/lca/LowestCommonAncestor.test.cpp\"\nusing namespace zawa;\n\nint main()\
    \ {\n    SetFastIO();\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::vector<int>>\
    \ T(N);\n    for (int i{1} ; i < N ; i++) {\n        int p;\n        std::cin\
    \ >> p;\n        T[p].push_back(i);\n    }\n    LowestCommonAncestor lca{T, 0};\n\
    \    while (Q--) {\n        int u, v;\n        std::cin >> u >> v;\n        std::cout\
    \ << lca(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../../Src/Graph/Tree/LowestCommonAncestor.hpp\"\nusing namespace\
    \ zawa;\n\nint main() {\n    SetFastIO();\n    int N, Q;\n    std::cin >> N >>\
    \ Q;\n    std::vector<std::vector<int>> T(N);\n    for (int i{1} ; i < N ; i++)\
    \ {\n        int p;\n        std::cin >> p;\n        T[p].push_back(i);\n    }\n\
    \    LowestCommonAncestor lca{T, 0};\n    while (Q--) {\n        int u, v;\n \
    \       std::cin >> u >> v;\n        std::cout << lca(u, v) << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Algebra/Monoid/ChminMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  isVerificationFile: true
  path: Test/LC/lca/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:29:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/lca/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/lca/LowestCommonAncestor.test.cpp
- /verify/Test/LC/lca/LowestCommonAncestor.test.cpp.html
title: Test/LC/lca/LowestCommonAncestor.test.cpp
---