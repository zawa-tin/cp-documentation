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
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    - https://atcoder.jp/contests/abc389/submissions/63369989
    - https://atcoder.jp/contests/abc389/tasks/abc389_f
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc389_f.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc389/tasks/abc389_f\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
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
    #line 5 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n\n#include <bit>\n\
    #include <cassert>\n#include <iterator>\n#include <optional>\n#include <vector>\n\
    \nnamespace zawa {\n\nnamespace Concept {\n\ntemplate <class F, class V>\nconcept\
    \ Predicate = requires {\n    { std::declval<F>()(std::declval<V>()) } -> std::same_as<bool>;\
    \ \n};\n\n} // namespace Concept\n\ntemplate <Concept::Group G>\nclass DualFenwickTree\
    \ {\npublic:\n\n    using V = typename G::Element;\n\n    constexpr static u32\
    \ Log2(usize n) noexcept {\n        return static_cast<u32>(\n               \
    \     std::bit_width(n) - (std::has_single_bit(n) ? 1 : 0)\n                );\n\
    \    }\n\n    DualFenwickTree() = default;\n\n    DualFenwickTree(usize n) : n_{n},\
    \ lg_{Log2(n)}, dat_(n+1, G::identity()) {\n        assert(n);\n    }\n\n    DualFenwickTree(const\
    \ std::vector<V>& d) : n_{d.size()}, lg_{Log2(n_)}, dat_(d.size() + 1, G::identity())\
    \ {\n        assert(d.size());\n        add(0, d[0]);\n        for (usize i =\
    \ 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i - 1]), d[i]));\n\
    \    }\n\n    template <std::input_iterator It>\n    DualFenwickTree(It first,\
    \ It last) \n    : n_{static_cast<usize>(std::distance(first, last))}, lg_{Log2(n_)},\
    \ dat_(n_ + 1, G::identity()) {\n        assert(first != last);\n        V pv\
    \ = static_cast<V>(*first);\n        add(0, pv);\n        for (usize i = 1 ; i\
    \ < n_ ; i++) {\n            first++;\n            V v = static_cast<V>(*first);\n\
    \            add(i, G::operation(G::inverse(pv), v));\n            pv = v;\n \
    \       } \n    }\n\n    inline usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(usize l, usize r, const V& v) {\n        assert(l\
    \ <= r and r <= size());\n        if (l < r) {\n            add(l, v);\n     \
    \       if (r < size()) add(r, G::inverse(v));\n        }\n    }\n\n    void operation(usize\
    \ i, const V& v) {\n        assert(i < size());\n        operation(i, i + 1, v);\n\
    \    }\n\n    V operator[](i32 i) const {\n        assert(0 <= i and i < (i32)size());\n\
    \        V res = G::identity();\n        for (i++ ; i ; i -= lsb(i)) res = G::operation(dat_[i],\
    \ res);\n        return res;\n    }\n\n    void set(usize i, V v) {\n        assert(0\
    \ <= i and i < size());\n        v = G::operation(G::inverse((*this)[i]), v);\n\
    \        operation(i, v);\n    }\n\n    template <class F>\n    requires Concept::Predicate<F,\
    \ V>\n    std::optional<usize> maxRight(usize l, F f) {\n        assert(l < size());\n\
    \        V sum = l ? (*this)[l - 1] : G::identity();\n        usize r = 0;\n \
    \       for (u32 w = lg_ ; w <= lg_ ; w--) {\n            usize next = r | (1u\
    \ << w);\n            if (next >= dat_.size()) continue;\n            V nsum =\
    \ G::operation(sum, dat_[next]);\n            if (f(nsum)) {\n               \
    \ sum = std::move(nsum);\n                r = std::move(next);\n            }\n\
    \        }\n        assert(l <= r);\n        return r == size() and f(sum) ? std::nullopt\
    \ : std::optional{r};\n    }\n\n    // \u5B9F\u88C5\u304C\u5408\u3044\u307E\u305B\
    \u3093\u3002\u982D\u304C\u60AA\u3044\u306E\u3067\n    // template <class F>\n\
    \    // requires Concept::Predicate<F, V>\n    // std::optional<usize> minLeft(usize\
    \ r, F f) const {\n    //     assert(r <= n_);\n    //     V sum = G::identity();\n\
    \    //     usize l = 0;\n    //     for (u32 w = lg_ ; w <= lg_ ; w--) {\n  \
    \  //         u32 next = l | (1u << w);\n    //         if (next >= r) continue;\n\
    \    //         V nsum = G::operation(dat_[next], sum);\n    //         if (!f(nsum))\
    \ {\n    //             sum = std::move(nsum);\n    //             l = std::move(next);\n\
    \    //         }\n    //     }\n    //     assert(l <= r);\n    //     if (l\
    \ + 1 == r and !f(sum)) return r;\n    //     return l == 0u and f(sum) ? std::nullopt\
    \ : std::optional{l};\n    // }\n\nprivate:\n\n    usize n_;\n\n    u32 lg_;\n\
    \n    std::vector<V> dat_;\n\n    constexpr i32 lsb(i32 x) const noexcept {\n\
    \        return x & -x;\n    }\n\n    void add(i32 i, const V& v) {\n        for\
    \ (i++ ; i <= (i32)size() ; i += lsb(i)) dat_[i] = G::operation(dat_[i], v);\n\
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\
    \n\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 6 \"Src/Sequence/CompressedSequence.hpp\"\
    \n#include <algorithm>\n#line 9 \"Src/Sequence/CompressedSequence.hpp\"\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence\
    \ {\nprivate:\n    std::vector<T> comped_;\n    std::vector<u32> f_;\n    \npublic:\n\
    \n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\n   \
    \ CompressedSequence() = default;\n\n    template <class InputIterator>\n    CompressedSequence(InputIterator\
    \ first, InputIterator last) : comped_(first, last), f_{} {\n        std::sort(comped_.begin(),\
    \ comped_.end());\n        comped_.erase(std::unique(comped_.begin(), comped_.end()),\
    \ comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n};\n\n} // namespace\
    \ zawa\n#line 7 \"Test/AtCoder/abc389_f.test.cpp\"\n\n/*\n * AtCoder Beginner\
    \ Contest 389 - F Rated Range\n * https://atcoder.jp/contests/abc389/submissions/63369989\n\
    \ */\n\n#line 15 \"Test/AtCoder/abc389_f.test.cpp\"\n#include <iostream>\n#line\
    \ 17 \"Test/AtCoder/abc389_f.test.cpp\"\nusing namespace zawa;\nint N, L[200020],\
    \ R[200020], Q, X[300030];\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    \n  \
    \  std::cin >> N;\n    for (int i = 0 ; i < N ; i++) {\n        std::cin >> L[i]\
    \ >> R[i];\n        R[i]++;\n    }\n    std::cin >> Q;\n    for (int i = 0 ; i\
    \ < Q ; i++) std::cin >> X[i];\n    CompressedSequence<int> comp(X, X + Q);  \
    \  \n    std::vector<int> init(comp.size());\n    for (int i = 0 ; i < (int)comp.size()\
    \ ; i++) init[i] = comp.inverse(i);\n    DualFenwickTree<AdditiveGroup<int>> fen{init.begin(),\
    \ init.end()};\n    auto idx = [&](int v) -> int {\n        auto it = fen.maxRight(0,\
    \ [&](int x) -> bool { return x < v; });\n        return it ? it.value() : (int)comp.size();\
    \    \n    };\n    for (int i = 0 ; i < N ; i++) {\n        int l = idx(L[i]),\
    \ r = idx(R[i]);\n        fen.operation(l, r, 1);\n    }\n    for (int i = 0 ;\
    \ i < Q ; i++) {\n        std::cout << fen[comp.at(X[i])] << '\\n';\n    }\n#else\n\
    \    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc389/tasks/abc389_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n#include \"../../Src/Sequence/CompressedSequence.hpp\"\n\n/*\n * AtCoder Beginner\
    \ Contest 389 - F Rated Range\n * https://atcoder.jp/contests/abc389/submissions/63369989\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <vector>\nusing namespace zawa;\nint N, L[200020], R[200020], Q, X[300030];\n\
    int main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    \n    std::cin >> N;\n    for (int\
    \ i = 0 ; i < N ; i++) {\n        std::cin >> L[i] >> R[i];\n        R[i]++;\n\
    \    }\n    std::cin >> Q;\n    for (int i = 0 ; i < Q ; i++) std::cin >> X[i];\n\
    \    CompressedSequence<int> comp(X, X + Q);    \n    std::vector<int> init(comp.size());\n\
    \    for (int i = 0 ; i < (int)comp.size() ; i++) init[i] = comp.inverse(i);\n\
    \    DualFenwickTree<AdditiveGroup<int>> fen{init.begin(), init.end()};\n    auto\
    \ idx = [&](int v) -> int {\n        auto it = fen.maxRight(0, [&](int x) -> bool\
    \ { return x < v; });\n        return it ? it.value() : (int)comp.size();    \n\
    \    };\n    for (int i = 0 ; i < N ; i++) {\n        int l = idx(L[i]), r = idx(R[i]);\n\
    \        fen.operation(l, r, 1);\n    }\n    for (int i = 0 ; i < Q ; i++) {\n\
    \        std::cout << fen[comp.at(X[i])] << '\\n';\n    }\n#else\n    std::cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Sequence/CompressedSequence.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc389_f.test.cpp
  requiredBy: []
  timestamp: '2025-03-03 23:11:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc389_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc389_f.test.cpp
- /verify/Test/AtCoder/abc389_f.test.cpp.html
title: Test/AtCoder/abc389_f.test.cpp
---
