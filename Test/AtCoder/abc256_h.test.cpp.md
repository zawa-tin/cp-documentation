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
    path: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
    title: Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
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
    - https://atcoder.jp/contests/abc256/submissions/67095836
    - https://atcoder.jp/contests/abc256/tasks/abc256_h
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc256_h.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc256/tasks/abc256_h\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 256 Ex - I like Query Problem\n * https://atcoder.jp/contests/abc256/submissions/67095836\n\
    \ */\n\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
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
    \ concepts\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <ranges>\n\
    #include <vector>\n\nnamespace zawa {\n\n// ref: https://codeforces.com/blog/entry/57319\n\
    template <concepts::MonoidWithAction S>\nclass SegmentTreeBeats {\npublic:\n\n\
    \    using VM = typename S::ValueMonoid;\n\n    using OM = typename S::OperatorMonoid;\n\
    \n    using V = typename VM::Element;\n\n    using O = typename OM::Element;\n\
    \n    SegmentTreeBeats() = default;\n\n    explicit SegmentTreeBeats(usize n)\
    \ \n        : m_n{n}, m_sz{1u << std::bit_width(n)}, m_dat(m_sz << 1, VM::identity()),\
    \ m_lazy(m_sz << 1, OM::identity()) {}\n\n    explicit SegmentTreeBeats(const\
    \ std::vector<V>& a) \n        : m_n{a.size()}, m_sz{1u << std::bit_width(a.size())},\
    \ m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {\n    \
    \    std::ranges::copy(a, m_dat.begin() + inner_size());\n        for (usize i\
    \ = inner_size() ; --i ; ) recalc(i);\n    }\n\n    [[nodiscard]] inline usize\
    \ size() const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]] V operator[](usize\
    \ i) {\n        assert(i < size());\n        return get(i, 1, 0, inner_size());\n\
    \    }\n\n    [[nodiscard]] V get(usize i) {\n        return (*this)[i];\n   \
    \ }\n\n    [[nodiscard]] V product(usize l, usize r) {\n        assert(l <= r\
    \ and r <= size());\n        return product(l, r, 1, 0, inner_size());\n    }\n\
    \n    template <class BREAK_CONDITION, class TAG_CONDITION>\n    requires (std::predicate<BREAK_CONDITION,\
    \ V, O> and std::predicate<TAG_CONDITION, V, O>)\n    void operation(usize l,\
    \ usize r, const O& o, BREAK_CONDITION break_condition, TAG_CONDITION tag_condition)\
    \ {\n        assert(l <= r and r <= size());\n        operation(l, r, o, 1, 0,\
    \ inner_size(), break_condition, tag_condition);\n    }\n\n    void assign(usize\
    \ i, const V& v) {\n        assert(i < size());\n        assign(i, v, 1, 0, inner_size());\n\
    \    }\n\n    template <class BREAK_CONDITION, class TAG_CONDITION>\n    requires\
    \ (std::predicate<BREAK_CONDITION, V, O> and std::predicate<TAG_CONDITION, V,\
    \ O>)\n    void operation(usize i, const O& o, BREAK_CONDITION break_condition,\
    \ TAG_CONDITION tag_condition) {\n        assert(i < size());\n        operation(i,\
    \ o, 1, 0, inner_size(), break_condition, tag_condition);\n    }\n\nprivate:\n\
    \n    using NodeInfo = std::tuple<usize, usize, usize>;\n\npublic:\n\n    template\
    \ <class F>\n    requires std::predicate<F, V>\n    usize maxRight(usize l, F\
    \ f) {\n        assert(l <= size());\n        if (!f(VM::identity())) return l;\n\
    \        if (l == size()) return size();\n        std::vector<NodeInfo> ranges;\n\
    \        partition_range(l, size(), ranges, 1, 0, inner_size());\n        V prod\
    \ = VM::identity();\n        for (auto [nd, nl, nr] : ranges) {\n            if\
    \ (!f(VM::operation(prod, m_dat[nd]))) {\n                return maxRight(f, prod,\
    \ nd, nl, nr);\n            }\n            else {\n                prod = VM::operation(prod,\
    \ m_dat[nd]);\n            }\n        }\n        return size();\n    }\n\n   \
    \ template <class F>\n    requires std::predicate<F, V>\n    usize minLeft(usize\
    \ r, F f) {\n        assert(r <= size());\n        if (!f(VM::identity())) return\
    \ r;\n        if (!r) return 0;\n        std::vector<NodeInfo> ranges;\n     \
    \   partition_range(0, r, ranges, 1, 0, inner_size());\n        V prod = VM::identity();\n\
    \        for (auto [nd, nl, nr] : ranges | std::views::reverse) {\n          \
    \  if (!f(VM::operation(m_dat[nd], prod))) {\n                return minLeft(f,\
    \ prod, nd, nl, nr);\n            }\n            else {\n                prod\
    \ = VM::operation(prod, m_dat[nd]);\n            }\n        }\n        return\
    \ 0;\n    }\n\nprivate:\n\n    usize m_n{}, m_sz{};\n\n    std::vector<V> m_dat{};\n\
    \n    std::vector<O> m_lazy{};\n\n    inline usize inner_size() const noexcept\
    \ {\n        return m_sz;\n    }\n\n    void recalc(usize v) {\n        m_dat[v]\
    \ = VM::operation(m_dat[v << 1 | 0], m_dat[v << 1 | 1]);\n    }\n\n    void propagate(usize\
    \ v) {\n        if (v < inner_size()) {\n            const usize lch = v << 1\
    \ | 0, rch = v << 1 | 1;\n            m_dat[lch] = S::mapping(m_dat[lch], m_lazy[v]);\n\
    \            m_lazy[lch] = OM::operation(m_lazy[lch], m_lazy[v]);\n          \
    \  m_dat[rch] = S::mapping(m_dat[rch], m_lazy[v]);\n            m_lazy[rch] =\
    \ OM::operation(m_lazy[rch], m_lazy[v]);\n            m_lazy[v] = OM::identity();\n\
    \        }\n    }\n\n    V product(usize ql, usize qr, usize nd, usize nl, usize\
    \ nr) {\n        if (qr <= nl or nr <= ql) return VM::identity();\n        if\
    \ (ql <= nl and nr <= qr) return m_dat[nd];\n        propagate(nd);\n        const\
    \ usize m = (nl + nr) >> 1;\n        return VM::operation(\n                product(ql,\
    \ qr, nd << 1 | 0, nl, m),\n                product(ql, qr, nd << 1 | 1, m, nr)\n\
    \                );\n    }\n\n    V get(usize i, usize nd, usize nl, usize nr)\
    \ {\n        if (nd >= inner_size()) return m_dat[nd];\n        propagate(nd);\n\
    \        const usize m = (nl + nr) >> 1;\n        return i < m ? get(i, nd <<\
    \ 1 | 0, nl, m) : get(i, nd << 1 | 1, m, nr);\n    }\n\n    template <class BREAK_CONDITION,\
    \ class TAG_CONDITION>\n    requires (std::predicate<BREAK_CONDITION, V, O> and\
    \ std::predicate<TAG_CONDITION, V, O>)\n    void operation(usize ql, usize qr,\
    \ const O& o, usize nd, usize nl, usize nr, BREAK_CONDITION break_condition, TAG_CONDITION\
    \ tag_condition) {\n        assert(nd < m_dat.size() or !\"failed to operation\
    \ to node such that length is 1. break_condition or/and tag_condition is something\
    \ wrong\");\n        if (qr <= nl or nr <= ql or break_condition(m_dat[nd], o))\
    \ return;\n        if (ql <= nl and nr <= qr and tag_condition(m_dat[nd], o))\
    \ {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            m_lazy[nd]\
    \ = OM::operation(m_lazy[nd], o);\n            return;\n        }\n        propagate(nd);\n\
    \        const usize m = (nl + nr) >> 1;\n        operation(ql, qr, o, nd << 1\
    \ | 0, nl, m, break_condition, tag_condition);\n        operation(ql, qr, o, nd\
    \ << 1 | 1, m, nr, break_condition, tag_condition);\n        recalc(nd);\n   \
    \ }\n\n    template <class BREAK_CONDITION, class TAG_CONDITION>\n    requires\
    \ (std::predicate<BREAK_CONDITION, V, O> and std::predicate<TAG_CONDITION, V,\
    \ O>)\n    void operation(usize i, const O& o, usize nd, usize nl, usize nr, BREAK_CONDITION\
    \ break_condition, TAG_CONDITION tag_condition) {\n        if (break_condition(m_dat[nd],\
    \ o)) return;\n        if (nd >= inner_size()) {\n            assert(tag_condition(m_dat[nd],\
    \ o) or !\"failed to operation to node such that length is 1. break_condition\
    \ or/and tag_condition is something wrong\");\n            m_dat[nd] = S::mapping(m_dat[nd],\
    \ o);\n            // \u8449\u9802\u70B9\u306A\u306E\u3067\u3001lazy\u3078\u306E\
    op\u306F\u4E0D\u8981\n            return;\n        }\n        propagate(nd); \n\
    \        const usize m = (nl + nr) >> 1;\n        i < m ? operation(i, o, nd <<\
    \ 1 | 0, nl, m, break_condition, tag_condition) : operation(i, o, nd << 1 | 1,\
    \ m, nr, break_condition, tag_condition);\n        recalc(nd);\n    }\n\n    void\
    \ assign(usize i, const V& v, usize nd, usize nl, usize nr) {\n        if (nd\
    \ >= inner_size()) {\n            m_dat[nd] = v;\n            return;\n      \
    \  }\n        propagate(nd); \n        const usize m = (nl + nr) >> 1;\n     \
    \   i < m ? assign(i, v, nd << 1 | 0, nl, m) : assign(i, v, nd << 1 | 1, m, nr);\n\
    \        recalc(nd);\n    }\n\n    void partition_range(usize ql, usize qr, std::vector<NodeInfo>&\
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
    \ zawa\n#line 10 \"Test/AtCoder/abc256_h.test.cpp\"\nusing namespace zawa;\n\n\
    #line 13 \"Test/AtCoder/abc256_h.test.cpp\"\n#include <iostream>\n#line 15 \"\
    Test/AtCoder/abc256_h.test.cpp\"\n\nstruct VD {\n    long long sum = 0;\n    int\
    \ val = 0, cnt = 0;\n    bool same = true;\n};\nstruct VM {\n    using Element\
    \ = VD;\n    static VD identity() {\n        return VD{};\n    }\n    static VD\
    \ operation(const VD& L, const VD& R) {\n        if (L.cnt == 0) return R;\n \
    \       if (R.cnt == 0) return L;\n        long long sum = L.sum + R.sum;\n  \
    \      int val = L.val, cnt = L.cnt + R.cnt;\n        bool same = L.same and R.same\
    \ and L.val == R.val;\n        return {sum,val,cnt,same};\n    }\n};\nusing OD\
    \ = std::pair<int, long long>;\nstd::ostream& operator<<(std::ostream& os, const\
    \ VD& v) {\n    os << '[' << v.sum << ',' << v.cnt << ',' << v.val << ',' << v.same\
    \ << ']';\n    return os;\n}\nstd::ostream& operator<<(std::ostream& os, const\
    \ OD& v) {\n    os << '(' << v.first << ',' << v.second << ')';\n    return os;\n\
    }\nstruct OM {\n    using Element = OD;\n    static Element identity() {\n   \
    \     return {-1, -1};\n    }\n    // division -> 0, set -> 1\n    static Element\
    \ operation(const Element L, const Element R) {\n        if (L.first == -1) return\
    \ R;\n        else if (R.first == -1) return L;\n        else if (R.first == 1)\
    \ return R; // R\u304C\u4EE3\u5165\n        else if (L.first == 0) return {0,L.second*R.second};\n\
    \        else return {1,L.second / R.second};\n    }\n};\nstruct ACT {\n    using\
    \ ValueMonoid = VM;\n    using OperatorMonoid = OM;\n    static VM::Element mapping(VM::Element\
    \ v, OM::Element o) {\n        if (o.first == 0) {\n            v.val /= o.second;\n\
    \            v.sum = (long long)v.val * v.cnt;\n        }\n        if (o.first\
    \ == 1) {\n            v.val = o.second;\n            v.sum = (long long)v.val\
    \ * v.cnt;\n        }\n        return v;\n    }\n};\nbool division_break_condition(const\
    \ VD& v, const OD&) {\n    return v.same and v.val == 0;\n}\nbool set_break_condition(const\
    \ VD&, const OD&) {\n    return false;\n}\nbool tag_condition(const VD& v, const\
    \ OD&) {\n    return v.same;\n}\n\nvoid solve() {\n    int N, Q;\n    std::cin\
    \ >> N >> Q; \n    std::vector<VD> init(N);\n    for (int i = 0 ; i < N ; i++)\
    \ {\n        int A;\n        std::cin >> A;\n        init[i] = {A,A,1,true};\n\
    \    }\n    SegmentTreeBeats<ACT> seg{init};\n    while (Q--) {\n        int T;\n\
    \        std::cin >> T;\n        if (T == 1) {\n            int L, R, x;\n   \
    \         std::cin >> L >> R >> x;\n            L--;\n            seg.operation(L,\
    \ R, {0,x}, division_break_condition, tag_condition);\n        }\n        else\
    \ if (T == 2) {\n            int L, R, x;\n            std::cin >> L >> R >> x;\n\
    \            L--;\n            seg.operation(L, R, {1,x}, set_break_condition,\
    \ tag_condition);\n        }\n        else if (T == 3) {\n            int L, R;\n\
    \            std::cin >> L >> R;\n            L--;\n            std::cout << seg.product(L,\
    \ R).sum << '\\n';\n        }\n        else assert(false);\n    }\n}\n\nint main()\
    \ {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    solve();\n#else\n    std::cout <<\
    \ \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_h\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 256 Ex - I like Query Problem\n * https://atcoder.jp/contests/abc256/submissions/67095836\n\
    \ */\n\n#include \"../../Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp\"\n\
    using namespace zawa;\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    \nstruct VD {\n    long long sum = 0;\n    int val = 0, cnt = 0;\n    bool same\
    \ = true;\n};\nstruct VM {\n    using Element = VD;\n    static VD identity()\
    \ {\n        return VD{};\n    }\n    static VD operation(const VD& L, const VD&\
    \ R) {\n        if (L.cnt == 0) return R;\n        if (R.cnt == 0) return L;\n\
    \        long long sum = L.sum + R.sum;\n        int val = L.val, cnt = L.cnt\
    \ + R.cnt;\n        bool same = L.same and R.same and L.val == R.val;\n      \
    \  return {sum,val,cnt,same};\n    }\n};\nusing OD = std::pair<int, long long>;\n\
    std::ostream& operator<<(std::ostream& os, const VD& v) {\n    os << '[' << v.sum\
    \ << ',' << v.cnt << ',' << v.val << ',' << v.same << ']';\n    return os;\n}\n\
    std::ostream& operator<<(std::ostream& os, const OD& v) {\n    os << '(' << v.first\
    \ << ',' << v.second << ')';\n    return os;\n}\nstruct OM {\n    using Element\
    \ = OD;\n    static Element identity() {\n        return {-1, -1};\n    }\n  \
    \  // division -> 0, set -> 1\n    static Element operation(const Element L, const\
    \ Element R) {\n        if (L.first == -1) return R;\n        else if (R.first\
    \ == -1) return L;\n        else if (R.first == 1) return R; // R\u304C\u4EE3\u5165\
    \n        else if (L.first == 0) return {0,L.second*R.second};\n        else return\
    \ {1,L.second / R.second};\n    }\n};\nstruct ACT {\n    using ValueMonoid = VM;\n\
    \    using OperatorMonoid = OM;\n    static VM::Element mapping(VM::Element v,\
    \ OM::Element o) {\n        if (o.first == 0) {\n            v.val /= o.second;\n\
    \            v.sum = (long long)v.val * v.cnt;\n        }\n        if (o.first\
    \ == 1) {\n            v.val = o.second;\n            v.sum = (long long)v.val\
    \ * v.cnt;\n        }\n        return v;\n    }\n};\nbool division_break_condition(const\
    \ VD& v, const OD&) {\n    return v.same and v.val == 0;\n}\nbool set_break_condition(const\
    \ VD&, const OD&) {\n    return false;\n}\nbool tag_condition(const VD& v, const\
    \ OD&) {\n    return v.same;\n}\n\nvoid solve() {\n    int N, Q;\n    std::cin\
    \ >> N >> Q; \n    std::vector<VD> init(N);\n    for (int i = 0 ; i < N ; i++)\
    \ {\n        int A;\n        std::cin >> A;\n        init[i] = {A,A,1,true};\n\
    \    }\n    SegmentTreeBeats<ACT> seg{init};\n    while (Q--) {\n        int T;\n\
    \        std::cin >> T;\n        if (T == 1) {\n            int L, R, x;\n   \
    \         std::cin >> L >> R >> x;\n            L--;\n            seg.operation(L,\
    \ R, {0,x}, division_break_condition, tag_condition);\n        }\n        else\
    \ if (T == 2) {\n            int L, R, x;\n            std::cin >> L >> R >> x;\n\
    \            L--;\n            seg.operation(L, R, {1,x}, set_break_condition,\
    \ tag_condition);\n        }\n        else if (T == 3) {\n            int L, R;\n\
    \            std::cin >> L >> R;\n            L--;\n            std::cout << seg.product(L,\
    \ R).sum << '\\n';\n        }\n        else assert(false);\n    }\n}\n\nint main()\
    \ {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n    std::cout.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    solve();\n#else\n    std::cout <<\
    \ \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc256_h.test.cpp
  requiredBy: []
  timestamp: '2025-06-27 19:09:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc256_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc256_h.test.cpp
- /verify/Test/AtCoder/abc256_h.test.cpp.html
title: Test/AtCoder/abc256_h.test.cpp
---
