---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MaxMonoid.hpp
    title: "max\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
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
    PROBLEM: https://atcoder.jp/contests/abc288/tasks/abc288_e
    links:
    - https://atcoder.jp/contests/abc288/tasks/abc288_e
  bundledCode: "#line 1 \"Test/AtCoder/abc288_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc288/tasks/abc288_e\"\
    \n\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
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
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Monoid/MaxMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <optional>\n\nnamespace zawa {\n\ntemplate <class T>\nclass\
    \ MaxMonoid {\npublic:\n    using Element = std::optional<T>;\n    static constexpr\
    \ Element identity() noexcept {\n        return std::nullopt;\n    }\n    static\
    \ constexpr Element operation(const Element& l, const Element& r) noexcept {\n\
    \        if (l and r) {\n            return std::max(l, r);\n        }\n     \
    \   else if (l) {\n            return l;\n        }\n        else if (r) {\n \
    \           return r;\n        }\n        else {\n            return std::nullopt;\n\
    \        }\n    }\n};\n\n} // namespace zawa\n#line 5 \"Test/AtCoder/abc288_e.test.cpp\"\
    \n\n#include <iostream>\n#line 8 \"Test/AtCoder/abc288_e.test.cpp\"\n\nusing namespace\
    \ zawa;\nusing M = MaxMonoid<int>;\nusing MD = M::Element;\n\nint main() {\n \
    \   int n, m; std::cin >> n >> m;\n    std::vector<int> a(n);\n    for (auto&\
    \ v : a) std::cin >> v;\n    std::vector<MD> c(n);\n    for (auto& v : c) {\n\
    \        int x; std::cin >> x;\n        v = -x;\n    }\n    std::vector<int> x(n);\n\
    \    for (int _{} ; _ < m ; _++) {\n        int v; std::cin >> v;\n        x[v\
    \ - 1] = true;\n    }\n\n    SparseTable<M> spt(c);\n    \n    const long long\
    \ INF{(long long)1e18};\n    std::vector<long long> dp(n + 1, INF);\n    dp[0]\
    \ = 0;\n\n    for (int i{} ; i < n ; i++) {\n        std::vector<long long> nxt(n\
    \ + 1, INF);\n        for (int j{} ; j <= i ; j++) {\n            if (!x[i]) {\n\
    \                nxt[j] = std::min(nxt[j], dp[j]);\n            }\n          \
    \  long long cost{(long long)a[i] - spt.product(i - j, i + 1).value()};\n    \
    \        nxt[j + 1] = std::min(nxt[j + 1], dp[j] + cost);\n        }\n       \
    \ dp = std::move(nxt);\n    }\n\n    long long ans{*std::min_element(dp.begin(),\
    \ dp.end())};\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc288/tasks/abc288_e\"\n\n\
    #include \"../../Src/DataStructure/SparseTable/SparseTable.hpp\"\n#include \"\
    ../../Src/Algebra/Monoid/MaxMonoid.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nusing namespace zawa;\nusing M = MaxMonoid<int>;\nusing MD = M::Element;\n\n\
    int main() {\n    int n, m; std::cin >> n >> m;\n    std::vector<int> a(n);\n\
    \    for (auto& v : a) std::cin >> v;\n    std::vector<MD> c(n);\n    for (auto&\
    \ v : c) {\n        int x; std::cin >> x;\n        v = -x;\n    }\n    std::vector<int>\
    \ x(n);\n    for (int _{} ; _ < m ; _++) {\n        int v; std::cin >> v;\n  \
    \      x[v - 1] = true;\n    }\n\n    SparseTable<M> spt(c);\n    \n    const\
    \ long long INF{(long long)1e18};\n    std::vector<long long> dp(n + 1, INF);\n\
    \    dp[0] = 0;\n\n    for (int i{} ; i < n ; i++) {\n        std::vector<long\
    \ long> nxt(n + 1, INF);\n        for (int j{} ; j <= i ; j++) {\n           \
    \ if (!x[i]) {\n                nxt[j] = std::min(nxt[j], dp[j]);\n          \
    \  }\n            long long cost{(long long)a[i] - spt.product(i - j, i + 1).value()};\n\
    \            nxt[j + 1] = std::min(nxt[j + 1], dp[j] + cost);\n        }\n   \
    \     dp = std::move(nxt);\n    }\n\n    long long ans{*std::min_element(dp.begin(),\
    \ dp.end())};\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - Src/DataStructure/SparseTable/SparseTable.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MaxMonoid.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc288_e.test.cpp
  requiredBy: []
  timestamp: '2024-02-09 20:29:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc288_e.test.cpp
layout: document
title: ABC288-E Wish List
---

番号昇順に買うか買わないかを決定する。 $C_j$ の寄与は後ろの要素には全く影響されないので、そこからDPを考えることができる。

$\text{DP}_{i, j}$ $i$ 番目までの商品を考慮した、 $j$ 個の商品を既に購入している時の最小値

区間minの形になっているのでSparseTableで高速化できる。
