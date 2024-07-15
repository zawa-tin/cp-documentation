---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
    title: "Dual Segment Tree (\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"Test/LC/range_affine_point_get.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#line 2 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\
    \n\n#line 2 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\n\
    \n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp\"\
    \n\n#include <vector>\n#include <iterator>\n#include <ostream>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class Monoid>\nclass CommutativeDualSegmentTree\
    \ {\npublic:\n    using Operator = typename Monoid::Element;\nprotected:\n\n \
    \   static constexpr u32 parent(u32 v) noexcept {\n        return v >> 1;\n  \
    \  }\n    static constexpr u32 left(u32 v) noexcept {\n        return v << 1;\n\
    \    }\n    static constexpr u32 right(u32 v) noexcept {\n        return v <<\
    \ 1 | 1;\n    }\n\n    usize n_;\n    std::vector<Operator> dat_;\n\n    template\
    \ <class InputIterator>\n    inline void initDat(InputIterator first, InputIterator\
    \ last) {\n        for (auto it{ first } ; it != last ; it++) {\n            dat_[n_\
    \ + std::distance(first, it)] = *it;\n        }\n    }\n\n    void push(u32 i)\
    \ {\n        assert(i < n_);\n        i += n_;\n        u32 height{ 32u - __builtin_clz(i)\
    \ };\n        for (u32 h{ height } ; --h ; ) {\n            u32 v{ i >> h };\n\
    \            dat_[left(v)] = Monoid::operation(dat_[left(v)], dat_[v]);\n    \
    \        dat_[right(v)] = Monoid::operation(dat_[right(v)], dat_[v]);\n      \
    \      dat_[v] = Monoid::identity();\n        }\n    }\n\npublic:\n    CommutativeDualSegmentTree()\
    \ = default;\n    CommutativeDualSegmentTree(usize n) \n        : n_{ n }, dat_((n\
    \ << 1), Monoid::identity()) {}\n    CommutativeDualSegmentTree(const std::vector<Operator>&\
    \ dat) \n        : n_{ dat.size() }, dat_((n_ << 1), Monoid::identity()) {\n \
    \       initDat(dat.begin(), dat.end());\n    }\n    template <class InputIterator>\n\
    \    CommutativeDualSegmentTree(InputIterator first, InputIterator last)\n   \
    \     : n_{ static_cast<usize>(std::distance(first, last)) }, dat_((n_ << 1),\
    \ Monoid::identity()) {\n        initDat(first, last);\n    }\n\n    virtual void\
    \ operation(u32 l, u32 r, const Operator& v) {\n        assert(l < n_);\n    \
    \    assert(l <= r and r <= n_);\n        for (l += n_, r += n_ ; l < r ; l =\
    \ parent(l), r = parent(r)) {\n            if (l & 1) {\n                dat_[l]\
    \ = Monoid::operation(dat_[l], v);\n                l++;\n            }\n    \
    \        if (r & 1) {\n                r--;\n                dat_[r] = Monoid::operation(dat_[r],\
    \ v);\n            }\n        }\n    }\n\n    void set(u32 i, const Operator&\
    \ v) {\n        assert(i < n_);\n        push(i);\n        dat_[i + n_] = v;\n\
    \    }\n\n    virtual Operator operator[](u32 i) {\n        assert(i < n_);\n\
    \        Operator res{ Monoid::identity() };\n        for (i += n_ ; i ; i = parent(i))\
    \ {\n            res = Monoid::operation(res, dat_[i]);\n        }\n        return\
    \ res;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const CommutativeDualSegmentTree\
    \ seg) {\n        usize size{ seg.dat_.size() };\n        for (u32 i{1} ; i <\
    \ size ; i++) {\n            os << seg.dat_[i] << (i + 1 == size ? \"\" : \" \"\
    );\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n#line 4 \"\
    Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class Monoid>\nclass DualSegmentTree : public CommutativeDualSegmentTree<Monoid>\
    \ {\nprivate:\n    using Base = CommutativeDualSegmentTree<Monoid>;\npublic:\n\
    \    using Operator = typename Base::Operator;\n    DualSegmentTree() : Base()\
    \ {}\n    DualSegmentTree(u32 n) : Base(n) {}\n    DualSegmentTree(const std::vector<Operator>&\
    \ dat) : Base(dat) {}\n    template <class InputIterator>\n    DualSegmentTree(InputIterator\
    \ first, InputIterator last) : Base(first, last) {}\n    \n    void operation(u32\
    \ l, u32 r, const Operator& v) override {\n        Base::push(l);\n        if\
    \ (l < r) Base::push(r - 1);\n        Base::operation(l, r, v);\n    } \n\n  \
    \  Operator operator[](u32 i) override {\n        Base::push(i);\n        return\
    \ Base::operator[](i);\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Number/ModInt.hpp\"\
    \n\n#line 4 \"Src/Number/ModInt.hpp\"\n\n#include <type_traits>\n#include <iostream>\n\
    #include <utility>\n#line 9 \"Src/Number/ModInt.hpp\"\n\nnamespace zawa {\n\n\
    template <class T, T mod>\nclass StaticModInt {\nprivate:\n    using mint = StaticModInt;\n\
    \n    T v_{};\n\n    static constexpr void templateTypeAssert() {\n        static_assert(std::is_integral_v<T>,\
    \ \"ModInt template argument must be integral\");\n        static_assert(mod >\
    \ 0, \"mod must be positive\");\n    }\n\n    i64 extendGCD(i64 a, i64 b, i64&\
    \ x, i64& y) const {\n       i64 d{a};\n       if (b) {\n           d = extendGCD(b,\
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
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n\n#line 4 \"Src/Algebra/Monoid/AffineMonoid.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass Affine {\nprivate:\n    T a_{1}, b_{};\npublic:\n    constexpr\
    \ Affine() {}\n    constexpr Affine(const T& a, const T& b) : a_{a}, b_{b} {}\n\
    \    T a() const noexcept {\n        return a_;\n    }\n    T b() const noexcept\
    \ {\n        return b_;\n    }\n    constexpr T mapping(const T& x) const {\n\
    \        return a_ * x + b_;\n    }\n    constexpr T operator()(const T& x) const\
    \ {\n        return a_ * x + b_;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Affine& affine) {\n        os << '(' << affine.a_ << ',' << affine.b_\
    \ << ')';\n        return os;\n    }\n};\n\ntemplate <class T>\nstruct AffineMonoid\
    \ {\n    using Element = Affine<T>;\n    static constexpr Element identity() noexcept\
    \ {\n        return Element{};\n    }\n    static constexpr Element operation(const\
    \ Element& l, const Element& r) noexcept {\n        return Element{ l.a() * r.a(),\
    \ l.b() * r.a() + r.b() };\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#line 6 \"Src/Template/IOSetting.hpp\"\
    \n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 7 \"Test/LC/range_affine_point_get.test.cpp\"\n\
    \n#line 10 \"Test/LC/range_affine_point_get.test.cpp\"\n\nint main() {\n    using\
    \ namespace zawa;\n    using mint = StaticModInt<u32, 998244353>;\n    SetFastIO();\n\
    \    int n, q; std::cin >> n >> q;\n    std::vector<mint> a(n);\n    for (auto&\
    \ x : a) std::cin >> x;\n    DualSegmentTree<AffineMonoid<mint>> seg(n);\n   \
    \ for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if (t\
    \ == 0) {\n            int l, r; std::cin >> l >> r;\n            mint b, c; std::cin\
    \ >> b >> c;\n            seg.operation(l, r, Affine{ b, c });\n        }\n  \
    \      else if (t == 1) {\n            int i; std::cin >> i;\n            std::cout\
    \ << seg[i].mapping(a[i]) << '\\n';\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n#include\
    \ \"../../Src/Number/ModInt.hpp\"\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include\
    \ <cassert>\n\nint main() {\n    using namespace zawa;\n    using mint = StaticModInt<u32,\
    \ 998244353>;\n    SetFastIO();\n    int n, q; std::cin >> n >> q;\n    std::vector<mint>\
    \ a(n);\n    for (auto& x : a) std::cin >> x;\n    DualSegmentTree<AffineMonoid<mint>>\
    \ seg(n);\n    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n\
    \        if (t == 0) {\n            int l, r; std::cin >> l >> r;\n          \
    \  mint b, c; std::cin >> b >> c;\n            seg.operation(l, r, Affine{ b,\
    \ c });\n        }\n        else if (t == 1) {\n            int i; std::cin >>\
    \ i;\n            std::cout << seg[i].mapping(a[i]) << '\\n';\n        }\n   \
    \     else {\n            assert(false);\n        }\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  - Src/DataStructure/SegmentTree/CommutativeDualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Number/ModInt.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  - Src/Template/IOSetting.hpp
  isVerificationFile: true
  path: Test/LC/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-07-15 23:06:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/range_affine_point_get.test.cpp
- /verify/Test/LC/range_affine_point_get.test.cpp.html
title: Test/LC/range_affine_point_get.test.cpp
---
