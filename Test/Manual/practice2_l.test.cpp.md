---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
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
    - https://atcoder.jp/contests/practice2/submissions/47372035
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/practice2_l.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Library Practice Contest - L Lazy Segment Tree\n * https://atcoder.jp/contests/practice2/submissions/47372035\n\
    \ */\n\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n#line\
    \ 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#include <vector>\n#include <iterator>\n#include <cassert>\n#include <ostream>\n\
    \n#include <iostream>\n\nnamespace zawa {\n\ntemplate <class Structure>\nclass\
    \ LazySegmentTree {\npublic:\n    using VM = typename Structure::ValueMonoid;\n\
    \    using OM = typename Structure::OperatorMonoid;\n    using Value = typename\
    \ VM::Element;\n    using Operator = typename OM::Element;\n\nprivate:\n    static\
    \ constexpr u32 parent(u32 v) noexcept {\n        return v >> 1;\n    }\n    static\
    \ constexpr u32 left(u32 v) noexcept {\n        return v << 1;\n    }\n    static\
    \ constexpr u32 right(u32 v) noexcept {\n        return v << 1 | 1;\n    }\n \
    \   static constexpr u32 depth(u32 v) noexcept {\n        return 31u - __builtin_clz(v);\n\
    \    }\n    static constexpr u32 trailingZeros(u32 v) noexcept {\n        return\
    \ __builtin_ctz(v);\n    }\n\n    struct Node {\n        Value v_{ VM::identity()\
    \ };\n        Operator o_{ OM::identity() };\n        Node() = default;\n    \
    \    Node(const Value& v, const Operator& o) : v_{v}, o_{o} {}\n    };\n\n   \
    \ usize n_{};\n    std::vector<Node> dat_;\n\n    static Value action(const Node&\
    \ node) {\n        return Structure::mapping(node.v_, node.o_);\n    }\n\n   \
    \ // \u30CE\u30FC\u30C9v\u306E\u5B50\u306B\u4F5C\u7528\u3092\u4F1D\u64AD\u3055\
    \u305B\u308B\n    void propagate(u32 v) {\n        dat_[left(v)].o_ = OM::operation(dat_[left(v)].o_,\
    \ dat_[v].o_);\n        dat_[right(v)].o_ = OM::operation(dat_[right(v)].o_, dat_[v].o_);\n\
    \        dat_[v].o_ = OM::identity();\n    }\n\n    // \u30CE\u30FC\u30C9v\u306E\
    \u7956\u5148\u306E\u30CE\u30FC\u30C9\u306E\u4F5C\u7528\u7D20\u3092\u5168\u3066\
    \u9069\u7528\u3059\u308B\n    void propagateAncestor(u32 v) {\n        u32 dep{depth(v)};\n\
    \        u32 zeros{trailingZeros(v)};\n        for (u32 d{dep} ; d != zeros ;\
    \ d--) {\n            propagate(v >> d);\n        }\n    }\n\n    // \u30CE\u30FC\
    \u30C9v\u306E\u5024\u3092\u518D\u8A08\u7B97\u3059\u308B\n    void recalc(u32 v)\
    \ {\n        dat_[v].v_ = VM::operation(action(dat_[left(v)]), action(dat_[right(v)]));\n\
    \    }\n\n    // \u8981\u7D20v\u3092\u6301\u3064\u30CE\u30FC\u30C9\u306E\u7956\
    \u5148\u3092\u518D\u8A08\u7B97\u3059\u308B\n    void recalcAncestor(u32 v) {\n\
    \        v >>= trailingZeros(v);\n        for (v = parent(v) ; v ; v = parent(v))\
    \ {\n            recalc(v);\n        }\n    }\n\n    template <class InputIterator>\n\
    \    void datInit(InputIterator first) {\n        auto it{first};\n        for\
    \ (u32 i{} ; i < n_ ; i++) {\n            dat_[i + n_].v_ = *it;\n           \
    \ it++;\n        }\n        for (u32 i{static_cast<u32>(n_)} ; --i ; ) {\n   \
    \         dat_[i].v_ = VM::operation(dat_[left(i)].v_, dat_[right(i)].v_);\n \
    \       }\n    }\n\npublic:\n    \n    LazySegmentTree() = default;\n    LazySegmentTree(usize\
    \ n) : n_{n}, dat_((n << 1)) {\n        assert(n_);\n    }\n    LazySegmentTree(const\
    \ std::vector<Value>& a) : n_{a.size()}, dat_((a.size() << 1)) {\n        assert(!a.empty());\n\
    \        datInit(a.begin());\n    }\n    template <class InputIterator>\n    LazySegmentTree(InputIterator\
    \ first, InputIterator last) \n        : n_{static_cast<usize>(std::distance(first,\
    \ last))}, dat_(std::distance(first, last) << 1) {\n        assert(n_);\n    \
    \    datInit(first);\n    }\n\n    usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(u32 i, const Operator& o) {\n        assert(i\
    \ < n_);\n        i += size();\n        propagateAncestor(i);\n        dat_[i].o_\
    \ = OM::operation(dat_[i].o_, o);\n        recalcAncestor(i);\n    }\n\n    void\
    \ operation(u32 L, u32 R, const Operator& o) {\n        assert(L <= R and R <=\
    \ n_);\n        L += size();\n        R += size();\n        propagateAncestor(L);\n\
    \        propagateAncestor(R);\n        for (u32 l = L, r = R ; l < r ; l = parent(l),\
    \ r = parent(r)) {\n            if (l & 1) {\n                dat_[l].o_ = OM::operation(dat_[l].o_,\
    \ o);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                dat_[r].o_ = OM::operation(dat_[r].o_, o);\n \
    \           }\n        }\n        recalcAncestor(L);\n        recalcAncestor(R);\n\
    \    }\n\n    void set(u32 i, const Value& v) {\n        assert(i < n_);\n   \
    \     i += size();\n        for (u32 d{depth(i)} ; d ; d--) {\n            propagate(i\
    \ >> d);\n        }\n        dat_[i] = Node{ v, OM::identity() };\n        for\
    \ (i = parent(i) ; i ; i = parent(i)) {\n            recalc(i);\n        }\n \
    \   }\n\n    Value operator[](u32 i) {\n        assert(i < n_);\n        i +=\
    \ size();\n        for (u32 d{depth(i)} ; d ; d--) {\n            propagate(i\
    \ >> d);\n        }\n        return action(dat_[i]);\n    }\n\n    Value product(u32\
    \ L, u32 R) {\n        assert(L <= R and R <= n_);\n        L += size();\n   \
    \     R += size();\n        propagateAncestor(L);\n        propagateAncestor(R);\n\
    \        recalcAncestor(L);\n        recalcAncestor(R);\n        Value l{VM::identity()},\
    \ r{VM::identity()};\n        for ( ; L < R ; L = parent(L), R = parent(R)) {\n\
    \            if (L & 1) {\n                l = VM::operation(l, action(dat_[L]));\n\
    \                L++;\n            }\n            if (R & 1) {\n             \
    \   R--;\n                r = VM::operation(action(dat_[R]), r);\n           \
    \ }\n        }\n        return VM::operation(l, r);\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const LazySegmentTree& seg) {\n        usize size{seg.dat_.size()};\n\
    \        os << \"Value :\\n\";\n        for (u32 i{1} ; i < size ; i++) {\n  \
    \          os << seg.dat_[i].v_ << (i + 1 == size ? \"\\n\" : \" \");\n      \
    \  }\n        os << \"Operator :\\n\";\n        for (u32 i{1} ; i < size ; i++)\
    \ {\n            os << seg.dat_[i].o_ << (i + 1 == size ? \"\\n\" : \" \");\n\
    \        }\n        os << \"Action :\\n\";\n        for (u32 i{1} ; i < size ;\
    \ i++) {\n            os << action(seg.dat_[i]) << (i + 1 == size ? \"\\n\" :\
    \ \" \");\n        }\n        return os;\n    }\n\n/*\n    template <class F>\n\
    \    u32 maxRight(u32 l, const F& f) {\n\n    }\n\n    template <class F>\n  \
    \  u32 minLeft(u32 r, const F& f) {\n\n    }\n*/\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 6 \"Src/Template/IOSetting.hpp\"\n#include <iomanip>\n\nnamespace zawa\
    \ {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 10 \"Test/Manual/practice2_l.test.cpp\"\n\nstruct\
    \ vDat {\n    long long zero{}, one{}, inv{};\n    vDat() {}\n    vDat(long long\
    \ z, long long o, long long i) : zero{z}, one{o}, inv{i} {}\n    vDat flip() const\
    \ {\n        return vDat{one, zero, one * zero - inv};\n    }\n};\n\nstruct vM\
    \ {\n    using Element = vDat;\n    static vDat identity() {\n        return vDat();\n\
    \    }\n    static vDat operation(const vDat& a, const vDat& b) {\n        return\
    \ vDat{\n            a.zero + b.zero,\n            a.one + b.one,\n          \
    \  a.inv + b.inv + a.one * b.zero\n        };\n    }\n};\n\nstruct oM {\n    using\
    \ Element = bool;\n    static bool identity() {\n        return false;\n    }\n\
    \    static bool operation(bool a, bool b) {\n        return a ^ b;\n    }\n};\n\
    \nstruct Structure {\n    using ValueMonoid = vM;\n    using OperatorMonoid =\
    \ oM;\n    static vDat mapping(const vDat& a, bool b) {\n        return (b ? a.flip()\
    \ : a);\n    }\n};\n\n#line 55 \"Test/Manual/practice2_l.test.cpp\"\n\nvoid solve()\
    \ {\n    using namespace zawa;\n    SetFastIO();\n    int n, q; std::cin >> n\
    \ >> q;\n    std::vector<vDat> a(n);\n    for (auto& x : a) {\n        int v;\
    \ std::cin >> v;\n        if (v == 0) x = vDat{ 1, 0, 0 };\n        else if (v\
    \ == 1) x = vDat{ 0, 1, 0 };\n        else assert(false);\n    } \n    LazySegmentTree<Structure>\
    \ seg(a); \n    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n\
    \        int l, r; std::cin >> l >> r;\n        l--;\n        if (t == 1) {\n\
    \            seg.operation(l, r, true);\n        } \n        else if (t == 2)\
    \ {\n            std::cout << seg.product(l, r).inv << std::endl;\n        }\n\
    \    }\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout\
    \ << \"Hello World\" << std::endl;\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Library Practice Contest - L Lazy Segment Tree\n * https://atcoder.jp/contests/practice2/submissions/47372035\n\
    \ */\n\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\
    #include \"../../Src/Template/IOSetting.hpp\"\n\nstruct vDat {\n    long long\
    \ zero{}, one{}, inv{};\n    vDat() {}\n    vDat(long long z, long long o, long\
    \ long i) : zero{z}, one{o}, inv{i} {}\n    vDat flip() const {\n        return\
    \ vDat{one, zero, one * zero - inv};\n    }\n};\n\nstruct vM {\n    using Element\
    \ = vDat;\n    static vDat identity() {\n        return vDat();\n    }\n    static\
    \ vDat operation(const vDat& a, const vDat& b) {\n        return vDat{\n     \
    \       a.zero + b.zero,\n            a.one + b.one,\n            a.inv + b.inv\
    \ + a.one * b.zero\n        };\n    }\n};\n\nstruct oM {\n    using Element =\
    \ bool;\n    static bool identity() {\n        return false;\n    }\n    static\
    \ bool operation(bool a, bool b) {\n        return a ^ b;\n    }\n};\n\nstruct\
    \ Structure {\n    using ValueMonoid = vM;\n    using OperatorMonoid = oM;\n \
    \   static vDat mapping(const vDat& a, bool b) {\n        return (b ? a.flip()\
    \ : a);\n    }\n};\n\n#include <iostream>\n#include <vector>\n#include <cassert>\n\
    \nvoid solve() {\n    using namespace zawa;\n    SetFastIO();\n    int n, q; std::cin\
    \ >> n >> q;\n    std::vector<vDat> a(n);\n    for (auto& x : a) {\n        int\
    \ v; std::cin >> v;\n        if (v == 0) x = vDat{ 1, 0, 0 };\n        else if\
    \ (v == 1) x = vDat{ 0, 1, 0 };\n        else assert(false);\n    } \n    LazySegmentTree<Structure>\
    \ seg(a); \n    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n\
    \        int l, r; std::cin >> l >> r;\n        l--;\n        if (t == 1) {\n\
    \            seg.operation(l, r, true);\n        } \n        else if (t == 2)\
    \ {\n            std::cout << seg.product(l, r).inv << std::endl;\n        }\n\
    \    }\n}\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout\
    \ << \"Hello World\" << std::endl;\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  isVerificationFile: true
  path: Test/Manual/practice2_l.test.cpp
  requiredBy: []
  timestamp: '2024-09-10 19:45:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/practice2_l.test.cpp
layout: document
title: ALPC-L Lazy Segment Tree
---

以下の様にデータを持つ

```cpp
struct {
    long long zero; // 区間に含まれる0の数
    long long one; // 区間に含まれる1の数
    long long inv; // 区間転倒数
};
```

単位元は`{ 0, 0, 0 }`、区間をマージする時は、invに前のoneと後ろのzeroの積を足せば良い

区間のflipは「元々の転倒数 + flip後の転倒数 = 0の数と1の数の積」を利用する
