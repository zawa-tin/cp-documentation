---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Other/RangeAssigner.hpp
    title: "\u540C\u4E00\u8981\u7D20\u304B\u3089\u306A\u308B\u6975\u5927\u306A\u533A\
      \u9593\u3092\u7BA1\u7406\u3059\u308B"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
    title: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
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
    - https://atcoder.jp/contests/abc430/submissions/70642359
    - https://atcoder.jp/contests/abc430/tasks/abc430_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc430_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc430/tasks/abc430_g\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n    AtCoder Beginner Contest 430 G - Range Set Modifying Query\n    https://atcoder.jp/contests/abc430/submissions/70642359\n\
    \ */\n\n#line 2 \"Src/DataStructure/Other/RangeAssigner.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <concepts>\n#include <utility>\n#include <map>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral Z, class T>\n\
    class RangeAssigner {\npublic:\n\n    RangeAssigner() = default;\n\n    RangeAssigner(Z\
    \ n, T init)\n        : m_min{0}, m_max{n} {\n        m_mp[0] = {n, init};\n \
    \   }\n\n    RangeAssigner(Z min, Z max, T init) \n        : m_min{min}, m_max{max}\
    \ {\n        assert(min <= max);\n        m_mp[m_min] = {max, init};\n    }\n\n\
    \    std::vector<std::tuple<Z, Z, T>> operator()(Z l, Z r) const {\n        assert(m_min\
    \ <= l and l <= r and r <= m_max);\n        std::vector<std::tuple<Z, Z, T>> res;\n\
    \        for (auto it = prev(m_mp.upper_bound(l)) ; it != m_mp.end() and it->first\
    \ < r ; it++)\n            res.emplace_back(std::max(it->first, l), std::min(it->second.first,\
    \ r), it->second.second);\n        return res;\n    }\n\n    std::vector<std::tuple<Z,\
    \ Z, T>> assign(Z l, Z r, T v) {\n        assert(m_min <= l and l <= r and r <=\
    \ m_max);\n        std::vector<std::tuple<Z, Z, T>> res;\n        {\n        \
    \    auto it = prev(m_mp.upper_bound(l));\n            const Z L = it->first,\
    \ R = it->second.first;\n            const T V = it->second.second;\n        \
    \    it->second.first = L;\n            m_mp.erase(it);\n            if (L < l)\n\
    \                m_mp[L] = {l, V};\n            res.emplace_back(l, std::min(r,\
    \ R), V);\n            if (r < R)\n                m_mp[r] = {R, V};\n       \
    \     if (r <= R) {\n                m_mp[l] = {r, v};\n                return\
    \ res;\n            }\n        }\n        auto it = m_mp.upper_bound(l);\n   \
    \     for ( ; it != m_mp.end() and it->second.first <= r ; it = m_mp.erase(it))\n\
    \            res.emplace_back(it->first, it->second.first, it->second.second);\n\
    \        if (it != m_mp.end() and r < it->second.first) {\n            const Z\
    \ L = it->first, R = it->second.first;\n            const T V = it->second.second;\n\
    \            it = m_mp.erase(it);\n            res.emplace_back(L, r, V);\n  \
    \          m_mp[r] = {R, V};\n        }\n        m_mp[l] = {r, v};\n        return\
    \ res;\n    }\n\nprivate:\n\n    std::map<Z, std::pair<Z, T>> m_mp;\n\n    Z m_min,\
    \ m_max;\n\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\nnamespace zawa {\n\
    \nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup = requires {\n\
    \    typename T::Element;\n    { T::operation(std::declval<typename T::Element>(),\
    \ std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept Identitiable = requires {\n    typename\
    \ T::Element;\n    { T::identity() } -> std::same_as<typename T::Element>;\n};\n\
    \ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\n}\
    \ // namespace\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept MonoidWithAction\
    \ = requires {\n    requires Monoid<typename T::ValueMonoid>;\n    requires Monoid<typename\
    \ T::OperatorMonoid>;\n    { T::mapping(\n            std::declval<typename T::ValueMonoid::Element>(),\n\
    \            std::declval<typename T::OperatorMonoid::Element>()\n           \
    \ ) } -> std::same_as<typename T::ValueMonoid::Element>; \n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#line 7 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include <bit>\n\
    #line 9 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include <ranges>\n\
    #include <tuple>\n#line 12 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::MonoidWithAction S>\nclass LazySegmentTree\
    \ {\npublic:\n\n    using VM = S::ValueMonoid;\n\n    using V = typename VM::Element;\n\
    \n    using OM = S::OperatorMonoid;\n\n    using O = typename OM::Element;\n\n\
    \    LazySegmentTree() = default;\n\n    explicit LazySegmentTree(usize n) \n\
    \        : m_n{n}, m_sz{1u << (std::bit_width(n))}, m_dat(m_sz << 1, VM::identity()),\
    \ m_lazy(m_sz << 1, OM::identity()) {}\n\n    explicit LazySegmentTree(const std::vector<V>&\
    \ a)\n        : m_n{a.size()}, m_sz{1u << (std::bit_width(a.size()))}, m_dat(m_sz\
    \ << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {\n        std::ranges::copy(a,\
    \ m_dat.begin() + inner_size());\n        for (usize i = inner_size() ; --i ;\
    \ ) recalc(i);\n    }\n\n    [[nodiscard]] inline usize size() const noexcept\
    \ {\n        return m_n;\n    }\n\n    [[nodiscard]] V operator[](usize i) {\n\
    \        assert(i < size());\n        return get(i, 1, 0, inner_size());\n   \
    \ }\n\n    [[nodiscard]] V get(usize i) {\n        return (*this)[i];\n    }\n\
    \n    [[nodiscard]] V product(usize l, usize r) {\n        assert(l <= r and r\
    \ <= size());\n        return product(l, r, 1, 0, inner_size());\n    }\n\n  \
    \  void operation(usize l, usize r, const O& o) {\n        assert(l <= r and r\
    \ <= size());\n        return operation(l, r, o, 1, 0, inner_size());\n    }\n\
    \n    void assign(usize i, const V& v) {\n        assert(i < size());\n      \
    \  assign(i, v, 1, 0, inner_size());\n    }\n\n    void operation(usize i, const\
    \ O& o) {\n        assert(i < size());\n        operation(i, o, 1, 0, inner_size());\n\
    \    }\n\nprivate:\n\n    using NodeInfo = std::tuple<usize, usize, usize>;\n\n\
    public:\n\n    template <class F>\n    requires std::predicate<F, V>\n    usize\
    \ maxRight(usize l, F f) {\n        assert(l <= size());\n        if (!f(VM::identity()))\
    \ return l;\n        if (l == size()) return size();\n        std::vector<NodeInfo>\
    \ ranges;\n        partition_range(l, size(), ranges, 1, 0, inner_size());\n \
    \       V prod = VM::identity();\n        for (auto [nd, nl, nr] : ranges) {\n\
    \            if (!f(VM::operation(prod, m_dat[nd]))) {\n                return\
    \ maxRight(f, prod, nd, nl, nr);\n            }\n            else {\n        \
    \        prod = VM::operation(prod, m_dat[nd]);\n            }\n        }\n  \
    \      return size();\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize minLeft(usize r, F f) {\n        assert(r <= size());\n      \
    \  if (!f(VM::identity())) return r;\n        if (!r) return 0;\n        std::vector<NodeInfo>\
    \ ranges;\n        partition_range(0, r, ranges, 1, 0, inner_size());\n      \
    \  V prod = VM::identity();\n        for (auto [nd, nl, nr] : ranges | std::views::reverse)\
    \ {\n            if (!f(VM::operation(m_dat[nd], prod))) {\n                return\
    \ minLeft(f, prod, nd, nl, nr);\n            }\n            else {\n         \
    \       prod = VM::operation(prod, m_dat[nd]);\n            }\n        }\n   \
    \     return 0;\n    }\n\nprivate:\n\n    usize m_n{}, m_sz{};\n\n    std::vector<V>\
    \ m_dat;\n\n    std::vector<O> m_lazy;\n\n    inline usize inner_size() const\
    \ noexcept {\n        return m_sz;\n    }\n    \n    void recalc(usize nd) {\n\
    \        // assert(nd < inner_size());\n        m_dat[nd] = VM::operation(m_dat[nd\
    \ << 1 | 0], m_dat[nd << 1 | 1]);\n    }\n\n    void propagate(usize nd) {\n \
    \       // assert(nd < inner_size());\n        for (usize ch : {nd << 1 | 0, nd\
    \ << 1 | 1}) {\n            m_dat[ch] = S::mapping(m_dat[ch], m_lazy[nd]);\n \
    \           m_lazy[ch] = OM::operation(m_lazy[ch], m_lazy[nd]);\n        }\n \
    \       m_lazy[nd] = OM::identity();\n    }\n\n    V product(usize ql, usize qr,\
    \ usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return VM::identity();\n\
    \        if (ql <= nl and nr <= qr) return m_dat[nd];\n        propagate(nd);\n\
    \        const usize m = (nl + nr) >> 1;\n        return VM::operation(\n    \
    \            product(ql, qr, nd << 1 | 0, nl, m),\n                product(ql,\
    \ qr, nd << 1 | 1, m, nr)\n                );\n    }\n\n    V get(usize i, usize\
    \ nd, usize nl, usize nr) {\n        if (nd >= inner_size()) return m_dat[nd];\n\
    \        propagate(nd);\n        const usize m = (nl + nr) >> 1;\n        return\
    \ i < m ? get(i, nd << 1 | 0, nl, m) : get(i, nd << 1 | 1, m, nr);\n    }\n\n\
    \    void operation(usize ql, usize qr, const O& o, usize nd, usize nl, usize\
    \ nr) {\n        if (qr <= nl or nr <= ql) return;\n        if (ql <= nl and nr\
    \ <= qr) {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            m_lazy[nd]\
    \ = OM::operation(m_lazy[nd], o);\n            return;\n        }\n        propagate(nd);\n\
    \        const usize m = (nl + nr) >> 1;\n        operation(ql, qr, o, nd << 1\
    \ | 0, nl, m);\n        operation(ql, qr, o, nd << 1 | 1, m, nr);\n        recalc(nd);\n\
    \    }\n\n    void operation(usize i, const O& o, usize nd, usize nl, usize nr)\
    \ {\n        if (nl == i and i + 1 == nr) {\n            m_dat[nd] = S::mapping(m_dat[nd],\
    \ o);\n            return;\n        }\n        propagate(nd); \n        const\
    \ usize m = (nl + nr) >> 1;\n        i < m ? operation(i, o, nd << 1 | 0, nl,\
    \ m) : operation(i, o, nd << 1 | 1, m, nr);\n        recalc(nd);\n    }\n\n  \
    \  void assign(usize i, const V& v, usize nd, usize nl, usize nr) {\n        if\
    \ (nl == i and i + 1 == nr) {\n            m_dat[nd] = v;\n            return;\n\
    \        }\n        propagate(nd); \n        const usize m = (nl + nr) >> 1;\n\
    \        i < m ? assign(i, v, nd << 1 | 0, nl, m) : assign(i, v, nd << 1 | 1,\
    \ m, nr);\n        recalc(nd);\n    }\n\n    void partition_range(usize ql, usize\
    \ qr, std::vector<NodeInfo>& res, usize nd, usize nl, usize nr) {\n        if\
    \ (qr <= nl or nr <= ql) return;\n        if (ql <= nl and nr <= qr) {\n     \
    \       res.emplace_back(nd, nl, nr);\n            return;\n        }\n      \
    \  propagate(nd);\n        const usize m = (nl + nr) >> 1;\n        partition_range(ql,\
    \ qr, res, nd << 1 | 0, nl, m);\n        partition_range(ql, qr, res, nd << 1\
    \ | 1, m, nr);\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize maxRight(F f, const V& prod, usize nd, usize nl, usize nr) {\n\
    \        if (nd >= inner_size()) return nl;\n        propagate(nd);\n        const\
    \ usize m = (nl + nr) >> 1, lch = nd << 1 | 0, rch = nd << 1 | 1;\n        return\
    \ f(VM::operation(prod, m_dat[lch])) ? \n            maxRight(f, VM::operation(prod,\
    \ m_dat[lch]), rch, m, nr) : maxRight(f, prod, lch, nl, m);\n    }\n\n    template\
    \ <class F>\n    requires std::predicate<F, V>\n    usize minLeft(F f, const V&\
    \ prod, usize nd, usize nl, usize nr) {\n        if (nd >= inner_size()) return\
    \ nr;\n        propagate(nd);\n        const usize m = (nl + nr) >> 1, lch = nd\
    \ << 1 | 0, rch = nd << 1 | 1;\n        return f(VM::operation(m_dat[rch], prod))\
    \ ? \n            minLeft(f, VM::operation(m_dat[rch], prod), lch, nl, m) : minLeft(f,\
    \ prod, rch, m, nr);\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(const T& l, const T& r)\
    \ noexcept {\n        return l + r;\n    }\n    static constexpr T inverse(const\
    \ T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line\
    \ 12 \"Test/AtCoder/abc430_g.test.cpp\"\nusing namespace zawa;\n#line 14 \"Test/AtCoder/abc430_g.test.cpp\"\
    \n#include <iostream>\n#line 16 \"Test/AtCoder/abc430_g.test.cpp\"\nusing namespace\
    \ std;\nstruct MAX {\n    using Element = pair<int, int>;\n    static Element\
    \ identity() {\n        return {-1, 0};\n    }\n    static Element operation(Element\
    \ L, Element R) {\n        if (L.first < R.first)\n            swap(L, R);\n \
    \       if (L.first == R.first)\n            L.second += R.second;\n        return\
    \ L;\n    }\n};\nstruct ACT {\n    using ValueMonoid = MAX;\n    using OperatorMonoid\
    \ = AdditiveGroup<int>;\n    static ValueMonoid::Element mapping(ValueMonoid::Element\
    \ v, OperatorMonoid::Element o) {\n        v.first += o;\n        return v;\n\
    \    }\n};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >> Q;\n    vector rg(60,\
    \ RangeAssigner<int, bool>(N, false));\n    LazySegmentTree<ACT> seg(vector<MAX::Element>(N,\
    \ {0, 1}));\n    while (Q--) {\n        int T, L, R;\n        cin >> T >> L >>\
    \ R;\n        L--;\n        if (T == 1) {\n            int x;\n            cin\
    \ >> x;\n            for (auto [l, r, v] : rg[x - 1].assign(L, R, true)) {\n \
    \               if (v == false)\n                    seg.operation(l, r, 1);\n\
    \            }\n        }\n        else if (T == 2) {\n            int x;\n  \
    \          cin >> x;\n            for (auto [l, r, v] : rg[x - 1].assign(L, R,\
    \ false)) {\n                if (v == true)\n                    seg.operation(l,\
    \ r, -1);\n            }\n        }\n        else if (T == 3) {\n            auto\
    \ [x, y] = seg.product(L, R);\n            cout << x << ' ' << y << '\\n';\n \
    \       }\n        else\n            assert(0);\n    }\n#else\n    cout << \"\
    Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc430/tasks/abc430_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n    AtCoder Beginner Contest 430 G - Range Set Modifying Query\n    https://atcoder.jp/contests/abc430/submissions/70642359\n\
    \ */\n\n#include \"../../Src/DataStructure/Other/RangeAssigner.hpp\"\n#include\
    \ \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \nusing namespace zawa;\n#include <cassert>\n#include <iostream>\n#include <utility>\n\
    using namespace std;\nstruct MAX {\n    using Element = pair<int, int>;\n    static\
    \ Element identity() {\n        return {-1, 0};\n    }\n    static Element operation(Element\
    \ L, Element R) {\n        if (L.first < R.first)\n            swap(L, R);\n \
    \       if (L.first == R.first)\n            L.second += R.second;\n        return\
    \ L;\n    }\n};\nstruct ACT {\n    using ValueMonoid = MAX;\n    using OperatorMonoid\
    \ = AdditiveGroup<int>;\n    static ValueMonoid::Element mapping(ValueMonoid::Element\
    \ v, OperatorMonoid::Element o) {\n        v.first += o;\n        return v;\n\
    \    }\n};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >> Q;\n    vector rg(60,\
    \ RangeAssigner<int, bool>(N, false));\n    LazySegmentTree<ACT> seg(vector<MAX::Element>(N,\
    \ {0, 1}));\n    while (Q--) {\n        int T, L, R;\n        cin >> T >> L >>\
    \ R;\n        L--;\n        if (T == 1) {\n            int x;\n            cin\
    \ >> x;\n            for (auto [l, r, v] : rg[x - 1].assign(L, R, true)) {\n \
    \               if (v == false)\n                    seg.operation(l, r, 1);\n\
    \            }\n        }\n        else if (T == 2) {\n            int x;\n  \
    \          cin >> x;\n            for (auto [l, r, v] : rg[x - 1].assign(L, R,\
    \ false)) {\n                if (v == true)\n                    seg.operation(l,\
    \ r, -1);\n            }\n        }\n        else if (T == 3) {\n            auto\
    \ [x, y] = seg.product(L, R);\n            cout << x << ' ' << y << '\\n';\n \
    \       }\n        else\n            assert(0);\n    }\n#else\n    cout << \"\
    Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/Other/RangeAssigner.hpp
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc430_g.test.cpp
  requiredBy: []
  timestamp: '2025-11-02 16:57:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc430_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc430_g.test.cpp
- /verify/Test/AtCoder/abc430_g.test.cpp.html
title: Test/AtCoder/abc430_g.test.cpp
---
