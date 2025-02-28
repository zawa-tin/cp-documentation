---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/DualFenwickTree.hpp
    title: Dual Fenwick Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/arc088/submissions/63213121
    - https://atcoder.jp/contests/arc088/tasks/arc088_c
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/arc088_e.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc088/tasks/arc088_c\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(const T& l, const T& r) noexcept {\n        return l + r;\n    }\n\
    \    static constexpr T inverse(const T& v) noexcept {\n        return -v;\n \
    \   }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#include <concepts>\n\n\
    namespace zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Monoid\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n    { T::operation(std::declval<typename T::Element>(), std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\n} // namespace\n\
    \n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\n\nnamespace\
    \ zawa {\n\nnamespace Concept {\n\ntemplate <class T>\nconcept Inversible = requires\
    \ {\n    typename T::Element;\n    { T::inverse(std::declval<typename T::Element>())\
    \ } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class T>\nconcept Group\
    \ = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\n} // namespace zawa\n\
    #line 5 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <Concept::Group G>\nclass DualFenwickTree\
    \ {\npublic:\n\n    using V = typename G::Element;\n\n    DualFenwickTree() =\
    \ default;\n\n    DualFenwickTree(usize n) : n_{n}, dat_(n+1, G::identity()) {\n\
    \        assert(n);\n    }\n\n    DualFenwickTree(const std::vector<V>& d) : n_{d.size()},\
    \ dat_(d.size() + 1, G::identity()) {\n        assert(d.size());\n        add(0,\
    \ d[0]);\n        for (usize i = 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i\
    \ - 1]), d[i]));\n    }\n\n    inline usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(usize l, usize r, const V& v) {\n        assert(l\
    \ <= r and r <= (i32)size());\n        if (l < r) {\n            add(l, v);\n\
    \            if (r < size()) add(r, G::inverse(v));\n        }\n    }\n\n    void\
    \ operation(usize i, const V& v) {\n        assert(i < size());\n        operation(i,\
    \ i + 1, v);\n    }\n\n    V operator[](i32 i) const {\n        assert(0 <= i\
    \ and i < (i32)size());\n        V res = G::identity();\n        for (i++ ; i\
    \ ; i -= lsb(i)) res = G::operation(dat_[i], res);\n        return res;\n    }\n\
    \n    void set(usize i, V v) {\n        assert(0 <= i and i < size());\n     \
    \   v = G::operation(G::inverse((*this)[i]), v);\n        operation(i, v);\n \
    \   }\n\nprivate:\n\n    usize n_;\n\n    std::vector<V> dat_;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n\n    void add(i32\
    \ i, const V& v) {\n        for (i++ ; i <= (i32)size() ; i += lsb(i)) dat_[i]\
    \ = G::operation(dat_[i], v);\n    }\n};\n\n} // namespace zawa\n#line 6 \"Test/AtCoder/arc088_e.test.cpp\"\
    \n\n/*\n * AtCoder Regular Contest 088 - E Papple Sort\n * https://atcoder.jp/contests/arc088/submissions/63213121\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include\
    \ <numeric>\nusing namespace zawa;\nstd::string S;\nstd::vector<int> pos[26];\n\
    std::vector<std::pair<int, int>> match[26];\nbool is_palin() {\n    int odd =\
    \ 0;\n    for (int i = 0 ; i < 26 ; i++) odd += pos[i].size() & 1;\n    return\
    \ odd <= 1;\n}\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n   \
    \ std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cin\
    \ >> S;\n    for (int i = 0 ; i < (int)S.size() ; i++) pos[S[i] - 'a'].push_back(i);\n\
    \    if (is_palin()) {\n        for (int i = 0 ; i < 26 ; i++) {\n           \
    \ match[i].reserve(pos[i].size() / 2);\n            for (int j = 0, k = (int)pos[i].size()\
    \ - 1 ; j < k ; j++, k--) {\n                match[i].push_back({ pos[i][j], pos[i][k]\
    \ });\n            }\n            std::reverse(match[i].begin(), match[i].end());\n\
    \        }\n        std::vector<int> init(S.size());\n        std::iota(init.begin(),\
    \ init.end(), 0);\n        DualFenwickTree<AdditiveGroup<int>> fen{init};\n  \
    \      long long ans = 0;\n        for (int l = 0, r = (int)S.size() - 1 ; l <\
    \ r ; l++, r--) {\n            int min = (int)1e9, arg = -1;\n            for\
    \ (int i = 0 ; i < 26 ; i++) if (match[i].size()) {\n                auto [ll,\
    \ rr] = match[i].back();\n                int cost = fen[ll] - l + r - fen[rr];\n\
    \                if (min > cost) {\n                    min = cost;\n        \
    \            arg = i;\n                }\n            }\n            assert(arg\
    \ != -1);\n            auto [ll, rr] = match[arg].back();\n            match[arg].pop_back();\n\
    \            ans += min;\n            fen.operation(0, ll, 1);\n            fen.operation(rr\
    \ + 1, S.size(), -1);\n        }\n        std::cout << ans << '\\n';\n    }\n\
    \    else {\n        std::cout << -1 << '\\n';\n    }\n#else\n    std::cout <<\
    \ \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc088/tasks/arc088_c\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n\n/*\n * AtCoder Regular Contest 088 - E Papple Sort\n * https://atcoder.jp/contests/arc088/submissions/63213121\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include\
    \ <numeric>\nusing namespace zawa;\nstd::string S;\nstd::vector<int> pos[26];\n\
    std::vector<std::pair<int, int>> match[26];\nbool is_palin() {\n    int odd =\
    \ 0;\n    for (int i = 0 ; i < 26 ; i++) odd += pos[i].size() & 1;\n    return\
    \ odd <= 1;\n}\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n   \
    \ std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cin\
    \ >> S;\n    for (int i = 0 ; i < (int)S.size() ; i++) pos[S[i] - 'a'].push_back(i);\n\
    \    if (is_palin()) {\n        for (int i = 0 ; i < 26 ; i++) {\n           \
    \ match[i].reserve(pos[i].size() / 2);\n            for (int j = 0, k = (int)pos[i].size()\
    \ - 1 ; j < k ; j++, k--) {\n                match[i].push_back({ pos[i][j], pos[i][k]\
    \ });\n            }\n            std::reverse(match[i].begin(), match[i].end());\n\
    \        }\n        std::vector<int> init(S.size());\n        std::iota(init.begin(),\
    \ init.end(), 0);\n        DualFenwickTree<AdditiveGroup<int>> fen{init};\n  \
    \      long long ans = 0;\n        for (int l = 0, r = (int)S.size() - 1 ; l <\
    \ r ; l++, r--) {\n            int min = (int)1e9, arg = -1;\n            for\
    \ (int i = 0 ; i < 26 ; i++) if (match[i].size()) {\n                auto [ll,\
    \ rr] = match[i].back();\n                int cost = fen[ll] - l + r - fen[rr];\n\
    \                if (min > cost) {\n                    min = cost;\n        \
    \            arg = i;\n                }\n            }\n            assert(arg\
    \ != -1);\n            auto [ll, rr] = match[arg].back();\n            match[arg].pop_back();\n\
    \            ans += min;\n            fen.operation(0, ll, 1);\n            fen.operation(rr\
    \ + 1, S.size(), -1);\n        }\n        std::cout << ans << '\\n';\n    }\n\
    \    else {\n        std::cout << -1 << '\\n';\n    }\n#else\n    std::cout <<\
    \ \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc088_e.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 18:42:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc088_e.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc088_e.test.cpp
- /verify/Test/AtCoder/arc088_e.test.cpp.html
title: Test/AtCoder/arc088_e.test.cpp
---
