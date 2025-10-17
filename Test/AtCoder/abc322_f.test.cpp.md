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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc322/submissions/67058865
    - https://atcoder.jp/contests/abc322/tasks/abc322_f
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc322_f.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc322/tasks/abc322_f\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * https://atcoder.jp/contests/abc322/submissions/67058865\n * AtCoder\
    \ Beginner Contest 322 F - Vacation Query\n */\n\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
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
    \ 1 == nr) {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            return;\n\
    \        }\n        propagate(nd); \n        const usize m = (nl + nr) >> 1;\n\
    \        i < m ? operation(i, o, nd << 1 | 0, nl, m) : operation(i, o, nd << 1\
    \ | 1, m, nr);\n        recalc(nd);\n    }\n\n    void assign(usize i, const V&\
    \ v, usize nd, usize nl, usize nr) {\n        if (nl == i and i + 1 == nr) {\n\
    \            m_dat[nd] = v;\n            return;\n        }\n        propagate(nd);\
    \ \n        const usize m = (nl + nr) >> 1;\n        i < m ? assign(i, v, nd <<\
    \ 1 | 0, nl, m) : assign(i, v, nd << 1 | 1, m, nr);\n        recalc(nd);\n   \
    \ }\n\n    void partition_range(usize ql, usize qr, std::vector<NodeInfo>& res,\
    \ usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return;\n\
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
    \ zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 11 \"Test/AtCoder/abc322_f.test.cpp\"\n\n#include <utility>\n#line\
    \ 17 \"Test/AtCoder/abc322_f.test.cpp\"\n\nusing pii = std::pair<int, int>;\n\n\
    void chmax(int& a, int b) {\n    a = std::max(a, b);\n}\n\nstruct vD {\n    int\
    \ max[2]{ 0, 0 };\n    pii left{}, right{};\n    bool allSame{true};\n\n    vD()\
    \ = default;\n\n    vD flip() const {\n        vD res{};\n        res.max[0] =\
    \ max[1];\n        res.max[1] = max[0];\n        res.left = pii{left.first ^ 1,\
    \ left.second};\n        res.right = pii{right.first ^ 1, right.second};\n   \
    \     res.allSame = allSame;\n        return res;\n    }\n};\n\nstruct vM {\n\
    \    using Element = vD;\n    static vD identity() {\n        return vD{};\n \
    \   }\n    static vD operation(const vD& L, const vD& R) {\n        vD res{};\n\
    \n        res.max[0] = std::max(L.max[0], R.max[0]);\n        res.max[1] = std::max(L.max[1],\
    \ R.max[1]);\n\n        res.left.first = L.left.first;\n        res.left.second\
    \ = L.left.second;\n        if (L.allSame and L.left.first == R.left.first) res.left.second\
    \ += R.left.second;\n\n        res.right.first = R.right.first;\n        res.right.second\
    \ = R.right.second;\n        if (R.allSame and R.right.first == L.right.first)\
    \ res.right.second += L.right.second;\n\n        res.allSame = L.allSame and R.allSame\
    \ and L.left.first == R.right.first;\n\n        if (L.right.first == R.left.first)\
    \ chmax(res.max[L.right.first], L.right.second + R.left.second);\n        chmax(res.max[res.left.first],\
    \ res.left.second);\n        chmax(res.max[res.right.first], res.right.second);\n\
    \n        return res;\n    }\n};\n\nstruct oM {\n    using Element = bool;\n \
    \   static bool identity() {\n        return false;\n    }\n    static bool operation(bool\
    \ l, bool r) {\n        return l ^ r;\n    }\n};\n\nstruct Structure {\n    using\
    \ ValueMonoid = vM;\n    using OperatorMonoid = oM;\n    static vD mapping(const\
    \ vD& a, bool b) {\n        return (b ? a.flip() : a);\n    }\n};\n\nint main()\
    \ {\n#ifdef ATCODER\n    using namespace zawa;\n    SetFastIO();\n\n    int n,\
    \ q; std::cin >> n >> q;\n    std::vector<vD> init(n);\n    for (int i{} ; i <\
    \ n ; i++) {\n        char c; std::cin >> c;\n        if (c == '0') {\n      \
    \      init[i].left = pii{0, 1};\n            init[i].right = pii{0, 1};\n   \
    \         init[i].max[0] = 1;\n            init[i].max[1] = 0;\n            init[i].allSame\
    \ = true;\n        }\n        else if (c == '1') {\n            init[i].left =\
    \ pii{1, 1};\n            init[i].right = pii{1, 1};\n            init[i].max[0]\
    \ = 0;\n            init[i].max[1] = 1;\n            init[i].allSame = true;\n\
    \        }\n        else {\n            assert(false);\n        }\n    }\n\n \
    \   LazySegmentTree<Structure> seg(init);\n    for (int _{} ; _ < q ; _++) {\n\
    \        int c, l, r; std::cin >> c >> l >> r;\n        l--;\n        if (c ==\
    \ 1) {\n            seg.operation(l, r, true);\n        }\n        else if (c\
    \ == 2) {\n            auto prod{seg.product(l, r)};\n            int ans{prod.max[1]};\n\
    \            std::cout << ans << '\\n';\n        }\n        else {\n         \
    \   assert(false);\n        }\n    }\n#else\n    std::cout << \"Hello World\\\
    n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc322/tasks/abc322_f\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * https://atcoder.jp/contests/abc322/submissions/67058865\n * AtCoder\
    \ Beginner Contest 322 F - Vacation Query\n */\n\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n\n#include <utility>\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n#include <cassert>\n\n\
    using pii = std::pair<int, int>;\n\nvoid chmax(int& a, int b) {\n    a = std::max(a,\
    \ b);\n}\n\nstruct vD {\n    int max[2]{ 0, 0 };\n    pii left{}, right{};\n \
    \   bool allSame{true};\n\n    vD() = default;\n\n    vD flip() const {\n    \
    \    vD res{};\n        res.max[0] = max[1];\n        res.max[1] = max[0];\n \
    \       res.left = pii{left.first ^ 1, left.second};\n        res.right = pii{right.first\
    \ ^ 1, right.second};\n        res.allSame = allSame;\n        return res;\n \
    \   }\n};\n\nstruct vM {\n    using Element = vD;\n    static vD identity() {\n\
    \        return vD{};\n    }\n    static vD operation(const vD& L, const vD& R)\
    \ {\n        vD res{};\n\n        res.max[0] = std::max(L.max[0], R.max[0]);\n\
    \        res.max[1] = std::max(L.max[1], R.max[1]);\n\n        res.left.first\
    \ = L.left.first;\n        res.left.second = L.left.second;\n        if (L.allSame\
    \ and L.left.first == R.left.first) res.left.second += R.left.second;\n\n    \
    \    res.right.first = R.right.first;\n        res.right.second = R.right.second;\n\
    \        if (R.allSame and R.right.first == L.right.first) res.right.second +=\
    \ L.right.second;\n\n        res.allSame = L.allSame and R.allSame and L.left.first\
    \ == R.right.first;\n\n        if (L.right.first == R.left.first) chmax(res.max[L.right.first],\
    \ L.right.second + R.left.second);\n        chmax(res.max[res.left.first], res.left.second);\n\
    \        chmax(res.max[res.right.first], res.right.second);\n\n        return\
    \ res;\n    }\n};\n\nstruct oM {\n    using Element = bool;\n    static bool identity()\
    \ {\n        return false;\n    }\n    static bool operation(bool l, bool r) {\n\
    \        return l ^ r;\n    }\n};\n\nstruct Structure {\n    using ValueMonoid\
    \ = vM;\n    using OperatorMonoid = oM;\n    static vD mapping(const vD& a, bool\
    \ b) {\n        return (b ? a.flip() : a);\n    }\n};\n\nint main() {\n#ifdef\
    \ ATCODER\n    using namespace zawa;\n    SetFastIO();\n\n    int n, q; std::cin\
    \ >> n >> q;\n    std::vector<vD> init(n);\n    for (int i{} ; i < n ; i++) {\n\
    \        char c; std::cin >> c;\n        if (c == '0') {\n            init[i].left\
    \ = pii{0, 1};\n            init[i].right = pii{0, 1};\n            init[i].max[0]\
    \ = 1;\n            init[i].max[1] = 0;\n            init[i].allSame = true;\n\
    \        }\n        else if (c == '1') {\n            init[i].left = pii{1, 1};\n\
    \            init[i].right = pii{1, 1};\n            init[i].max[0] = 0;\n   \
    \         init[i].max[1] = 1;\n            init[i].allSame = true;\n        }\n\
    \        else {\n            assert(false);\n        }\n    }\n\n    LazySegmentTree<Structure>\
    \ seg(init);\n    for (int _{} ; _ < q ; _++) {\n        int c, l, r; std::cin\
    \ >> c >> l >> r;\n        l--;\n        if (c == 1) {\n            seg.operation(l,\
    \ r, true);\n        }\n        else if (c == 2) {\n            auto prod{seg.product(l,\
    \ r)};\n            int ans{prod.max[1]};\n            std::cout << ans << '\\\
    n';\n        }\n        else {\n            assert(false);\n        }\n    }\n\
    #else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Template/IOSetting.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc322_f.test.cpp
  requiredBy: []
  timestamp: '2025-10-17 20:47:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc322_f.test.cpp
layout: document
title: ABC322-F Vacation Query
---

遅延セグ木に乗せる構造を以下の様に設計する

- 値が担当している区間における連続する0の長さの最大長
- 値が担当している区間における連続する1の長さの最大長
- 値が担当している区間における一番左に連続している値の種類とその長さ
- 値が担当している区間における一番右に連続している値の種類とその長さ
- 値が担当している区間で値の種類が全て同じか？

`product` (値のマージ) では、この意味に沿うようによしなに頑張る。

`operation`(値の更新)では、01列のflipなのでい つ も ので良い
