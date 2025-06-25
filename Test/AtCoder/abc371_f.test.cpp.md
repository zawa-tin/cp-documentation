---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
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
    - https://atcoder.jp/contests/abc371/submissions/67058774
    - https://atcoder.jp/contests/abc371/tasks/abc371_f
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc371_f.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc371/tasks/abc371_f\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept MonoidWithAction\
    \ = requires {\n    requires Monoid<typename T::ValueMonoid>;\n    requires Monoid<typename\
    \ T::OperatorMonoid>;\n    { T::mapping(\n            std::declval<typename T::ValueMonoid::Element>(),\n\
    \            std::declval<typename T::OperatorMonoid::Element>()\n           \
    \ ) } -> std::same_as<typename T::ValueMonoid::Element>; \n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <ranges>\n\
    #include <tuple>\n#include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::MonoidWithAction\
    \ S>\nclass LazySegmentTree {\npublic:\n\n    using VM = S::ValueMonoid;\n\n \
    \   using V = typename VM::Element;\n\n    using OM = S::OperatorMonoid;\n\n \
    \   using O = typename OM::Element;\n\n    LazySegmentTree() = default;\n\n  \
    \  explicit LazySegmentTree(usize n) \n        : m_n{n}, m_sz{1u << (std::bit_width(n))},\
    \ m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {}\n\n \
    \   explicit LazySegmentTree(const std::vector<V>& a)\n        : m_n{a.size()},\
    \ m_sz{1u << (std::bit_width(a.size()))}, m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz\
    \ << 1, OM::identity()) {\n        std::ranges::copy(a, m_dat.begin() + inner_size());\n\
    \        for (usize i = inner_size() ; --i ; ) recalc(i);\n    }\n\n    [[nodiscard]]\
    \ inline usize size() const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]]\
    \ V operator[](usize i) {\n        assert(i < size());\n        return get(i,\
    \ 1, 0, inner_size());\n    }\n\n    [[nodiscard]] V get(usize i) {\n        return\
    \ (*this)[i];\n    }\n\n    [[nodiscard]] V product(usize l, usize r) {\n    \
    \    assert(l <= r and r <= size());\n        return product(l, r, 1, 0, inner_size());\n\
    \    }\n\n    void operation(usize l, usize r, const O& o) {\n        assert(l\
    \ <= r and r <= size());\n        return operation(l, r, o, 1, 0, inner_size());\n\
    \    }\n\n    void assign(usize i, const V& v) {\n        assert(i < size());\n\
    \        assign(i, v, 1, 0, inner_size());\n    }\n\n    void operation(usize\
    \ i, const O& o) {\n        assert(i < size());\n        operation(i, o, 1, 0,\
    \ inner_size());\n    }\n\nprivate:\n\n    using NodeInfo = std::tuple<usize,\
    \ usize, usize>;\n\npublic:\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize maxRight(usize l, F f) {\n        assert(l <= size());\n     \
    \   if (!f(VM::identity())) return l;\n        if (l == size()) return size();\n\
    \        std::vector<NodeInfo> ranges;\n        partition_range(l, size(), ranges,\
    \ 1, 0, inner_size());\n        V prod = VM::identity();\n        for (auto [nd,\
    \ nl, nr] : ranges) {\n            if (!f(VM::operation(prod, m_dat[nd]))) {\n\
    \                return maxRight(f, prod, nd, nl, nr);\n            }\n      \
    \      else {\n                prod = VM::operation(prod, m_dat[nd]);\n      \
    \      }\n        }\n        return size();\n    }\n\n    template <class F>\n\
    \    requires std::predicate<F, V>\n    usize minLeft(usize r, F f) {\n      \
    \  assert(r <= size());\n        if (!f(VM::identity())) return r;\n        if\
    \ (!r) return 0;\n        std::vector<NodeInfo> ranges;\n        partition_range(0,\
    \ r, ranges, 1, 0, inner_size());\n        V prod = VM::identity();\n        for\
    \ (auto [nd, nl, nr] : ranges | std::views::reverse) {\n            if (!f(VM::operation(m_dat[nd],\
    \ prod))) {\n                return minLeft(f, prod, nd, nl, nr);\n          \
    \  }\n            else {\n                prod = VM::operation(prod, m_dat[nd]);\n\
    \            }\n        }\n        return 0;\n    }\n\nprivate:\n\n    usize m_n{},\
    \ m_sz{};\n\n    std::vector<V> m_dat;\n\n    std::vector<O> m_lazy;\n\n    inline\
    \ usize inner_size() const noexcept {\n        return m_sz;\n    }\n    \n   \
    \ void recalc(usize nd) {\n        // assert(nd < inner_size());\n        m_dat[nd]\
    \ = VM::operation(m_dat[nd << 1 | 0], m_dat[nd << 1 | 1]);\n    }\n\n    void\
    \ propagate(usize nd) {\n        // assert(nd < inner_size());\n        for (usize\
    \ ch : {nd << 1 | 0, nd << 1 | 1}) {\n            m_dat[ch] = S::mapping(m_dat[ch],\
    \ m_lazy[nd]);\n            m_lazy[ch] = OM::operation(m_lazy[ch], m_lazy[nd]);\n\
    \        }\n        m_lazy[nd] = OM::identity();\n    }\n\n    V product(usize\
    \ ql, usize qr, usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <=\
    \ ql) return VM::identity();\n        if (ql <= nl and nr <= qr) return m_dat[nd];\n\
    \        propagate(nd);\n        const usize m = (nl + nr) >> 1;\n        return\
    \ VM::operation(\n                product(ql, qr, nd << 1 | 0, nl, m),\n     \
    \           product(ql, qr, nd << 1 | 1, m, nr)\n                );\n    }\n\n\
    \    V get(usize i, usize nd, usize nl, usize nr) {\n        if (nd >= inner_size())\
    \ return m_dat[nd];\n        propagate(nd);\n        const usize m = (nl + nr)\
    \ >> 1;\n        return i < m ? get(i, nd << 1 | 0, nl, m) : get(i, nd << 1 |\
    \ 1, m, nr);\n    }\n\n    void operation(usize ql, usize qr, const O& o, usize\
    \ nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return;\n     \
    \   if (ql <= nl and nr <= qr) {\n            m_dat[nd] = S::mapping(m_dat[nd],\
    \ o);\n            m_lazy[nd] = OM::operation(m_lazy[nd], o);\n            return;\n\
    \        }\n        propagate(nd);\n        const usize m = (nl + nr) >> 1;\n\
    \        operation(ql, qr, o, nd << 1 | 0, nl, m);\n        operation(ql, qr,\
    \ o, nd << 1 | 1, m, nr);\n        recalc(nd);\n    }\n\n    void operation(usize\
    \ i, const O& o, usize nd, usize nl, usize nr) {\n        if (nl == i and i +\
    \ 1 == nr) {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            //\
    \ \u8449\u9802\u70B9\u306A\u306E\u3067\u3001lazy\u3078\u306Eop\u306F\u4E0D\u8981\
    \n            return;\n        }\n        propagate(nd); \n        const usize\
    \ m = (nl + nr) >> 1;\n        i < m ? operation(i, o, nd << 1 | 0, nl, m) : operation(i,\
    \ o, nd << 1 | 1, m, nr);\n        recalc(nd);\n    }\n\n    void assign(usize\
    \ i, const V& v, usize nd, usize nl, usize nr) {\n        if (nl == i and i +\
    \ 1 == nr) {\n            m_dat[nd] = v;\n            return;\n        }\n   \
    \     propagate(nd); \n        const usize m = (nl + nr) >> 1;\n        i < m\
    \ ? assign(i, v, nd << 1 | 0, nl, m) : assign(i, v, nd << 1 | 1, m, nr);\n   \
    \     recalc(nd);\n    }\n\n    void partition_range(usize ql, usize qr, std::vector<NodeInfo>&\
    \ res, usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return;\n\
    \        if (ql <= nl and nr <= qr) {\n            res.emplace_back(nd, nl, nr);\n\
    \            return;\n        }\n        propagate(nd);\n        const usize m\
    \ = (nl + nr) >> 1;\n        partition_range(ql, qr, res, nd << 1 | 0, nl, m);\n\
    \        partition_range(ql, qr, res, nd << 1 | 1, m, nr);\n    }\n\n    template\
    \ <class F>\n    requires std::predicate<F, V>\n    usize maxRight(F f, const\
    \ V& prod, usize nd, usize nl, usize nr) {\n        if (nd >= inner_size()) return\
    \ nl;\n        propagate(nd);\n        const usize m = (nl + nr) >> 1, lch = nd\
    \ << 1 | 0, rch = nd << 1 | 1;\n        return f(VM::operation(prod, m_dat[lch]))\
    \ ? \n            maxRight(f, VM::operation(prod, m_dat[lch]), rch, m, nr) : maxRight(f,\
    \ prod, lch, nl, m);\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize minLeft(F f, const V& prod, usize nd, usize nl, usize nr) {\n\
    \        if (nd >= inner_size()) return nr;\n        propagate(nd);\n        const\
    \ usize m = (nl + nr) >> 1, lch = nd << 1 | 0, rch = nd << 1 | 1;\n        return\
    \ f(VM::operation(m_dat[rch], prod)) ? \n            minLeft(f, VM::operation(m_dat[rch],\
    \ prod), lch, nl, m) : minLeft(f, prod, rch, m, nr);\n    }\n};\n\n} // namespace\
    \ zawa\n#line 5 \"Test/AtCoder/abc371_f.test.cpp\"\n\n/*\n * AtCoder Beginner\
    \ Contest 371 F - Takahashi in Narrow Road\n * https://atcoder.jp/contests/abc371/submissions/67058774\n\
    \ */\n\n#include <iostream>\nconst int INF = (int)1e9;\nstruct VD {\n    long\
    \ long sum = 0;\n    int cnt = 0, min = INF, max = -INF;\n    VD() = default;\n\
    \    VD(int v) : sum{v}, cnt{1}, min{v}, max{v} {}\n    VD(int v, int c) : sum{(long\
    \ long)v * c}, cnt{c}, min{v}, max{v} {}\n    VD(long long s, int c, int mn, int\
    \ mx) : sum{s}, cnt{c}, min{mn}, max{mx} {}\n};\nstruct VM {\n    using Element\
    \ = VD;\n    static Element identity() { return VD{}; }\n    static Element operation(Element\
    \ L, Element R) {\n        L.sum += R.sum;\n        L.cnt += R.cnt;\n        L.min\
    \ = std::min(L.min, R.min);\n        L.max = std::max(L.max, R.max);\n       \
    \ return L;\n    }\n};\nstruct OM {\n    using Element = int;\n    static Element\
    \ identity() { return INF; }\n    static Element operation(Element L, Element\
    \ R) {\n        return R == INF ? L : R;\n    }\n};\nstruct S {\n    using ValueMonoid\
    \ = VM;\n    using OperatorMonoid = OM;\n    static VM::Element mapping(VM::Element\
    \ L, OM::Element R) {\n        if (R == INF) return L;\n        return VM::Element{R,\
    \ L.cnt};\n    }\n};\nlong long solve() {\n    int N;\n    std::cin >> N;\n  \
    \  std::vector<VD> init(N);\n    for (int i = 0 ; i < N ; i++) {\n        int\
    \ x;\n        std::cin >> x;\n        init[i] = VD{x - i};\n    }\n    zawa::LazySegmentTree<S>\
    \ seg{init};\n    int Q;\n    std::cin >> Q;\n    long long ans = 0;\n    while\
    \ (Q--) {\n        int T, G;\n        std::cin >> T >> G;\n        T--;\n    \
    \    G -= T;\n        const int cur = seg[T].min;\n        if (G < cur) {\n  \
    \          const auto l = seg.minLeft(T + 1, [&](const VD& v) { return G <= v.min;\
    \ });\n            const auto prod = seg.product(l, T + 1);\n            ans +=\
    \ prod.sum - (long long)G * prod.cnt;\n            seg.operation(l, T + 1, G);\n\
    \        }\n        else if (cur < G) {\n            const auto r = seg.maxRight(T,\
    \ [&](const VD& v) { return v.max <= G; });\n            const auto prod = seg.product(T,\
    \ r);\n            ans += (long long)G * prod.cnt - prod.sum;\n            seg.operation(T,\
    \ r, G);\n        }\n    }\n    return ans;\n}\nint main() {\n#ifdef ATCODER\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::cout << solve() << '\\n';\n#else\n    std::cout << \"Hello World\\n\"\
    ;\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc371/tasks/abc371_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n/*\n\
    \ * AtCoder Beginner Contest 371 F - Takahashi in Narrow Road\n * https://atcoder.jp/contests/abc371/submissions/67058774\n\
    \ */\n\n#include <iostream>\nconst int INF = (int)1e9;\nstruct VD {\n    long\
    \ long sum = 0;\n    int cnt = 0, min = INF, max = -INF;\n    VD() = default;\n\
    \    VD(int v) : sum{v}, cnt{1}, min{v}, max{v} {}\n    VD(int v, int c) : sum{(long\
    \ long)v * c}, cnt{c}, min{v}, max{v} {}\n    VD(long long s, int c, int mn, int\
    \ mx) : sum{s}, cnt{c}, min{mn}, max{mx} {}\n};\nstruct VM {\n    using Element\
    \ = VD;\n    static Element identity() { return VD{}; }\n    static Element operation(Element\
    \ L, Element R) {\n        L.sum += R.sum;\n        L.cnt += R.cnt;\n        L.min\
    \ = std::min(L.min, R.min);\n        L.max = std::max(L.max, R.max);\n       \
    \ return L;\n    }\n};\nstruct OM {\n    using Element = int;\n    static Element\
    \ identity() { return INF; }\n    static Element operation(Element L, Element\
    \ R) {\n        return R == INF ? L : R;\n    }\n};\nstruct S {\n    using ValueMonoid\
    \ = VM;\n    using OperatorMonoid = OM;\n    static VM::Element mapping(VM::Element\
    \ L, OM::Element R) {\n        if (R == INF) return L;\n        return VM::Element{R,\
    \ L.cnt};\n    }\n};\nlong long solve() {\n    int N;\n    std::cin >> N;\n  \
    \  std::vector<VD> init(N);\n    for (int i = 0 ; i < N ; i++) {\n        int\
    \ x;\n        std::cin >> x;\n        init[i] = VD{x - i};\n    }\n    zawa::LazySegmentTree<S>\
    \ seg{init};\n    int Q;\n    std::cin >> Q;\n    long long ans = 0;\n    while\
    \ (Q--) {\n        int T, G;\n        std::cin >> T >> G;\n        T--;\n    \
    \    G -= T;\n        const int cur = seg[T].min;\n        if (G < cur) {\n  \
    \          const auto l = seg.minLeft(T + 1, [&](const VD& v) { return G <= v.min;\
    \ });\n            const auto prod = seg.product(l, T + 1);\n            ans +=\
    \ prod.sum - (long long)G * prod.cnt;\n            seg.operation(l, T + 1, G);\n\
    \        }\n        else if (cur < G) {\n            const auto r = seg.maxRight(T,\
    \ [&](const VD& v) { return v.max <= G; });\n            const auto prod = seg.product(T,\
    \ r);\n            ans += (long long)G * prod.cnt - prod.sum;\n            seg.operation(T,\
    \ r, G);\n        }\n    }\n    return ans;\n}\nint main() {\n#ifdef ATCODER\n\
    \    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::cout << solve() << '\\n';\n#else\n    std::cout << \"Hello World\\n\"\
    ;\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc371_f.test.cpp
  requiredBy: []
  timestamp: '2025-06-25 17:03:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc371_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc371_f.test.cpp
- /verify/Test/AtCoder/abc371_f.test.cpp.html
title: Test/AtCoder/abc371_f.test.cpp
---
