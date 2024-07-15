---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AdditionMonoid.hpp
    title: Src/Algebra/Monoid/AdditionMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/Number/ModInt.hpp
    title: Src/Number/ModInt.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Test/LC/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 2 \"Src/Number/ModInt.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Number/ModInt.hpp\"\
    \n\n#include <type_traits>\n#include <iostream>\n#include <utility>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\ntemplate <class T, T mod>\nclass StaticModInt\
    \ {\nprivate:\n    using mint = StaticModInt;\n\n    T v_{};\n\n    static constexpr\
    \ void templateTypeAssert() {\n        static_assert(std::is_integral_v<T>, \"\
    ModInt template argument must be integral\");\n        static_assert(mod > 0,\
    \ \"mod must be positive\");\n    }\n\n    i64 extendGCD(i64 a, i64 b, i64& x,\
    \ i64& y) const {\n       i64 d{a};\n       if (b) {\n           d = extendGCD(b,\
    \ a % b, y, x);\n           y -= (a / b) * x;\n       }\n       else {\n     \
    \      x = 1;\n           y = 0;\n       }\n       return d;\n    }\n\npublic:\n\
    \n    constexpr StaticModInt() {\n        templateTypeAssert();\n    }\n    template\
    \ <class ArgType>\n    constexpr StaticModInt(ArgType v) : v_{ static_cast<T>(((v\
    \ % mod) + mod) % mod) } {\n        templateTypeAssert();\n        static_assert(std::is_integral_v<ArgType>,\
    \ \"ModInt constructor Argument Must Be Integral\");\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& value) {\n        is >> value.v_;\n     \
    \   return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ mint& value) {\n        os << value.v_;\n        return os;\n    }\n\n    T\
    \ v() const {\n        return v_;\n    }\n\n    bool operator==(const mint& rhs)\
    \ const {\n        return v_ == rhs.v_;\n    }\n\n    mint operator+() const {\n\
    \        return *this;\n    }\n    mint& operator+=(const mint& rhs) {\n     \
    \   v_ = (v_ < mod - rhs.v_ ? v_ + rhs.v_ : v_ + rhs.v_ - mod);\n        return\
    \ *this;\n    }\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n\
    \        return mint{lhs} += rhs;\n    }\n    mint& operator++() {\n        v_\
    \ = (v_ + 1 == mod ? 0 : v_ + 1);\n        return *this;\n    }\n    mint operator++(int)\
    \ {\n        mint res{*this};\n        ++*this;\n        return res;\n    }\n\n\
    \    mint operator-() const {\n        return mod - v_;\n    }\n    mint& operator-=(const\
    \ mint& rhs) {\n        v_ = (v_ >= rhs.v_ ? v_ - rhs.v_ : v_ + (mod - rhs.v_));\n\
    \        return *this;\n    }\n    friend mint operator-(const mint& lhs, const\
    \ mint& rhs) {\n        return mint{lhs} -= rhs;\n    }\n    mint& operator--()\
    \ {\n        v_ = (v_ ? v_ - 1 : mod - 1);\n        return *this;\n    }\n   \
    \ mint operator--(int) {\n        mint res{*this};\n        --*this;\n       \
    \ return res;\n    }\n\n    mint& operator*=(const mint& rhs) {\n        u64 mult{\
    \ static_cast<u64>(v_) * static_cast<u64>(rhs.v_) };\n        v_ = static_cast<T>(mult\
    \ % mod);\n        return *this;\n    }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) {\n        return mint{lhs} *= rhs;\n    }\n\n    mint\
    \ inverse() const {\n        i64 res{}, hoge{};\n        assert(extendGCD(static_cast<i64>(v_),\
    \ static_cast<i64>(mod), res, hoge) == 1);\n        return mint{res};\n    }\n\
    \    mint& operator/=(const mint& rhs) {\n        return *this *= rhs.inverse();\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint{lhs} /= rhs;\n    }\n\n    mint pow(u64 k) const {\n        mint\
    \ res{1}, base{k};\n        while (k) {\n            if (k & 1) res *= base;\n\
    \            base *= base; \n            k >>= 1;\n        }\n        return res;\n\
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n\
    #line 4 \"Src/Template/IOSetting.hpp\"\n\n#line 6 \"Src/Template/IOSetting.hpp\"\
    \n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 5 \"Test/LC/range_affine_range_sum.test.cpp\"\n\
    \n#line 7 \"Test/LC/range_affine_range_sum.test.cpp\"\n#include <vector>\n#line\
    \ 10 \"Test/LC/range_affine_range_sum.test.cpp\"\n\nusing namespace zawa;\n\n\
    using mint = StaticModInt<u32, 998244353>;\n\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::pair<mint, mint>& a) {\n    os << '(' << a.first << ',' << a.second\
    \ << ')';\n    return os;\n}\n\nstd::pair<mint, mint> operator+(const std::pair<mint,\
    \ mint>& a, const std::pair<mint, mint>& b) {\n    return std::pair<mint, mint>{\
    \ a.first + b.first, a.second + b.second };\n}\n\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#line 4 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\n#line 6 \"\
    Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include <iterator>\n#line\
    \ 8 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include <ostream>\n\
    \n#line 11 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class Structure>\nclass LazySegmentTree {\npublic:\n   \
    \ using VM = typename Structure::ValueMonoid;\n    using OM = typename Structure::OperatorMonoid;\n\
    \    using Value = typename VM::Element;\n    using Operator = typename OM::Element;\n\
    \nprivate:\n    static constexpr u32 parent(u32 v) noexcept {\n        return\
    \ v >> 1;\n    }\n    static constexpr u32 left(u32 v) noexcept {\n        return\
    \ v << 1;\n    }\n    static constexpr u32 right(u32 v) noexcept {\n        return\
    \ v << 1 | 1;\n    }\n    static constexpr u32 depth(u32 v) noexcept {\n     \
    \   return 31u - __builtin_clz(v);\n    }\n    static constexpr u32 trailingZeros(u32\
    \ v) noexcept {\n        return __builtin_ctz(v);\n    }\n\n    struct Node {\n\
    \        Value v_{ VM::identity() };\n        Operator o_{ OM::identity() };\n\
    \        Node() = default;\n        Node(const Value& v, const Operator& o) :\
    \ v_{v}, o_{o} {}\n    };\n\n    usize n_{};\n    std::vector<Node> dat_;\n\n\
    \    static Value action(const Node& node) {\n        return Structure::mapping(node.v_,\
    \ node.o_);\n    }\n\n    // \u30CE\u30FC\u30C9v\u306E\u5B50\u306B\u4F5C\u7528\
    \u3092\u4F1D\u64AD\u3055\u305B\u308B\n    void propagate(u32 v) {\n        dat_[left(v)].o_\
    \ = OM::operation(dat_[left(v)].o_, dat_[v].o_);\n        dat_[right(v)].o_ =\
    \ OM::operation(dat_[right(v)].o_, dat_[v].o_);\n        dat_[v].o_ = OM::identity();\n\
    \    }\n\n    // \u30CE\u30FC\u30C9v\u306E\u7956\u5148\u306E\u30CE\u30FC\u30C9\
    \u306E\u4F5C\u7528\u7D20\u3092\u5168\u3066\u9069\u7528\u3059\u308B\n    void propagateAncestor(u32\
    \ v) {\n        u32 dep{depth(v)};\n        u32 zeros{trailingZeros(v)};\n   \
    \     for (u32 d{dep} ; d != zeros ; d--) {\n            propagate(v >> d);\n\
    \        }\n    }\n\n    // \u30CE\u30FC\u30C9v\u306E\u5024\u3092\u518D\u8A08\u7B97\
    \u3059\u308B\n    void recalc(u32 v) {\n        dat_[v].v_ = VM::operation(action(dat_[left(v)]),\
    \ action(dat_[right(v)]));\n    }\n\n    // \u8981\u7D20v\u3092\u6301\u3064\u30CE\
    \u30FC\u30C9\u306E\u7956\u5148\u3092\u518D\u8A08\u7B97\u3059\u308B\n    void recalcAncestor(u32\
    \ v) {\n        v >>= trailingZeros(v);\n        for (v = parent(v) ; v ; v =\
    \ parent(v)) {\n            recalc(v);\n        }\n    }\n\n    template <class\
    \ InputIterator>\n    void datInit(InputIterator first) {\n        auto it{first};\n\
    \        for (u32 i{} ; i < n_ ; i++) {\n            dat_[i + n_].v_ = *it;\n\
    \            it++;\n        }\n        for (u32 i{static_cast<u32>(n_)} ; --i\
    \ ; ) {\n            dat_[i].v_ = VM::operation(dat_[left(i)].v_, dat_[right(i)].v_);\n\
    \        }\n    }\n\npublic:\n    \n    LazySegmentTree() = default;\n    LazySegmentTree(usize\
    \ n) : n_{n}, dat_((n << 1)) {\n        assert(n_);\n    }\n    LazySegmentTree(const\
    \ std::vector<Value>& a) : n_{a.size()}, dat_((a.size() << 1)) {\n        assert(!a.empty());\n\
    \        datInit(a.begin());\n    }\n    template <class InputIterator>\n    LazySegmentTree(InputIterator\
    \ first, InputIterator last) \n        : n_{static_cast<usize>(std::distance(first,\
    \ last))}, dat_(std::distance(first, last) << 1) {\n        assert(n_);\n    \
    \    datInit(first);\n    }\n\n    usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(u32 i, const Operator& o) {\n        assert(i\
    \ < n_);\n        i += size();\n        propagateAncestor(i);\n        dat_[i].o_\
    \ = OM::operation(dat_[i].o_, o);\n        recalcAncestor(i);\n    }\n\n    void\
    \ operation(u32 L, u32 R, const Operator& o) {\n        assert(L < n_);\n    \
    \    assert(L <= R and R <= n_);\n        L += size();\n        R += size();\n\
    \        propagateAncestor(L);\n        propagateAncestor(R);\n        for (u32\
    \ l = L, r = R ; l < r ; l = parent(l), r = parent(r)) {\n            if (l &\
    \ 1) {\n                dat_[l].o_ = OM::operation(dat_[l].o_, o);\n         \
    \       l++;\n            }\n            if (r & 1) {\n                r--;\n\
    \                dat_[r].o_ = OM::operation(dat_[r].o_, o);\n            }\n \
    \       }\n        recalcAncestor(L);\n        recalcAncestor(R);\n    }\n\n \
    \   void set(u32 i, const Value& v) {\n        assert(i < n_);\n        i += size();\n\
    \        for (u32 d{depth(i)} ; d ; d--) {\n            propagate(i >> d);\n \
    \       }\n        dat_[i] = Node{ v, OM::identity() };\n        for (i = parent(i)\
    \ ; i ; i = parent(i)) {\n            recalc(i);\n        }\n    }\n\n    Value\
    \ operator[](u32 i) {\n        assert(i < n_);\n        i += size();\n       \
    \ for (u32 d{depth(i)} ; d ; d--) {\n            propagate(i >> d);\n        }\n\
    \        return action(dat_[i]);\n    }\n\n    Value product(u32 L, u32 R) {\n\
    \        assert(L < n_);\n        assert(L <= R and R <= n_);\n        L += size();\n\
    \        R += size();\n        propagateAncestor(L);\n        propagateAncestor(R);\n\
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
    #line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nstruct AdditionMonoid {\n    using Element = T;\n    static T identity()\
    \ noexcept {\n        return T{};\n    }\n    static T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Monoid/AffineMonoid.hpp\"\n\n#line 4 \"Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass Affine {\nprivate:\n    T a_{1},\
    \ b_{};\npublic:\n    constexpr Affine() {}\n    constexpr Affine(const T& a,\
    \ const T& b) : a_{a}, b_{b} {}\n    T a() const noexcept {\n        return a_;\n\
    \    }\n    T b() const noexcept {\n        return b_;\n    }\n    constexpr T\
    \ mapping(const T& x) const {\n        return a_ * x + b_;\n    }\n    constexpr\
    \ T operator()(const T& x) const {\n        return a_ * x + b_;\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Affine& affine) {\n       \
    \ os << '(' << affine.a_ << ',' << affine.b_ << ')';\n        return os;\n   \
    \ }\n};\n\ntemplate <class T>\nstruct AffineMonoid {\n    using Element = Affine<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return Element{};\n\
    \    }\n    static constexpr Element operation(const Element& l, const Element&\
    \ r) noexcept {\n        return Element{ l.a() * r.a(), l.b() * r.a() + r.b()\
    \ };\n    }\n};\n\n} // namespace zawa\n#line 27 \"Test/LC/range_affine_range_sum.test.cpp\"\
    \n\nstruct Structure {\n    using ValueMonoid = AdditionMonoid<std::pair<mint,\
    \ mint>>;\n    using OperatorMonoid = AffineMonoid<mint>;\n    static std::pair<mint,\
    \ mint> mapping(const std::pair<mint, mint>& v, const Affine<mint>& o) {\n   \
    \     return { o.a() * v.first + o.b() * v.second, v.second };\n    }\n};\n\n\
    int main() {\n    int n, q; std::cin >> n >> q;\n    std::vector<std::pair<mint,\
    \ mint>> a(n);\n    for (auto& x : a) {\n        std::cin >> x.first;\n      \
    \  x.second = 1;\n    }\n    LazySegmentTree<Structure> seg(a);\n    for (int\
    \ _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if (t == 0) {\n\
    \            int l, r; std::cin >> l >> r;\n            mint b, c; std::cin >>\
    \ b >> c;\n            seg.operation(l, r, Affine{ b, c });\n        }\n     \
    \   else if (t == 1) {\n            int l, r; std::cin >> l >> r;\n          \
    \  std::cout << seg.product(l, r).first << std::endl;\n        }\n        else\
    \ {\n            assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../Src/Number/ModInt.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <cassert>\n#include <utility>\n\
    \nusing namespace zawa;\n\nusing mint = StaticModInt<u32, 998244353>;\n\nstd::ostream&\
    \ operator<<(std::ostream& os, const std::pair<mint, mint>& a) {\n    os << '('\
    \ << a.first << ',' << a.second << ')';\n    return os;\n}\n\nstd::pair<mint,\
    \ mint> operator+(const std::pair<mint, mint>& a, const std::pair<mint, mint>&\
    \ b) {\n    return std::pair<mint, mint>{ a.first + b.first, a.second + b.second\
    \ };\n}\n\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/AdditionMonoid.hpp\"\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n\nstruct Structure {\n    using ValueMonoid = AdditionMonoid<std::pair<mint,\
    \ mint>>;\n    using OperatorMonoid = AffineMonoid<mint>;\n    static std::pair<mint,\
    \ mint> mapping(const std::pair<mint, mint>& v, const Affine<mint>& o) {\n   \
    \     return { o.a() * v.first + o.b() * v.second, v.second };\n    }\n};\n\n\
    int main() {\n    int n, q; std::cin >> n >> q;\n    std::vector<std::pair<mint,\
    \ mint>> a(n);\n    for (auto& x : a) {\n        std::cin >> x.first;\n      \
    \  x.second = 1;\n    }\n    LazySegmentTree<Structure> seg(a);\n    for (int\
    \ _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if (t == 0) {\n\
    \            int l, r; std::cin >> l >> r;\n            mint b, c; std::cin >>\
    \ b >> c;\n            seg.operation(l, r, Affine{ b, c });\n        }\n     \
    \   else if (t == 1) {\n            int l, r; std::cin >> l >> r;\n          \
    \  std::cout << seg.product(l, r).first << std::endl;\n        }\n        else\
    \ {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/Number/ModInt.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-07-15 23:06:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/range_affine_range_sum.test.cpp
- /verify/Test/LC/range_affine_range_sum.test.cpp.html
title: Test/LC/range_affine_range_sum.test.cpp
---
