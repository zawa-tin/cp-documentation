---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AffineMonoid.hpp
    title: Src/Algebra/Monoid/AffineMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Test/LC/point_set_range_composite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#line 4 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <functional>\n#include <type_traits>\n#include <ostream>\n\
    \nnamespace zawa {\n\ntemplate <class Monoid>\nclass SegmentTree {\npublic:\n\
    \    using Value = typename Monoid::Element;\nprivate:\n    constexpr u32 left(u32\
    \ v) const {\n        return v << 1;\n    }\n    constexpr u32 right(u32 v) const\
    \ {\n        return v << 1 | 1;\n    }\n    constexpr u32 parent(u32 v) const\
    \ {\n        return v >> 1;\n    }\n\n    usize n_;\n    std::vector<Value> dat_;\n\
    \npublic:\n    SegmentTree() = default;\n    SegmentTree(u32 n) : n_{ n }, dat_(n\
    \ << 1, Monoid::identity()) {\n        assert(n_);\n    }\n    SegmentTree(const\
    \ std::vector<Value>& dat) : n_{ dat.size() }, dat_(dat.size() << 1, Monoid::identity())\
    \ {\n        assert(n_);\n        for (u32 i{} ; i < n_ ; i++) {\n           \
    \ dat_[i + n_] = dat[i];\n        }\n        for (u32 i{static_cast<u32>(n_) -\
    \ 1} ; i ; i--) {\n            dat_[i] = Monoid::operation(dat_[left(i)], dat_[right(i)]);\n\
    \        }\n    }\n\n    Value get(u32 i) const {\n        assert(i < n_);\n \
    \       return dat_[i + n_];\n    }\n\n    void set(u32 i, const Value& value)\
    \ {\n        assert(i < n_);\n        i += n_;\n        dat_[i] = value;\n   \
    \     while (i = parent(i), i) {\n            dat_[i] = Monoid::operation(dat_[left(i)],\
    \ dat_[right(i)]);\n        }\n    }\n\n    Value product(u32 l, u32 r) const\
    \ {\n        assert(l < n_);\n        assert(l <= r and r <= n_);\n        Value\
    \ leftValue{ Monoid::identity() }, rightValue{ Monoid::identity() };\n       \
    \ for (l += n_, r += n_ ; l < r ; l = parent(l), r = parent(r)) {\n          \
    \  if (l & 1) {\n                leftValue = Monoid::operation(leftValue, dat_[l++]);\n\
    \            }\n            if (r & 1) {\n                rightValue = Monoid::operation(dat_[--r],\
    \ rightValue);\n            }\n        }\n        return Monoid::operation(leftValue,\
    \ rightValue);\n    }\n\n    template <class Function>\n    u32 maxRight(u32 l,\
    \ const Function& f) {\n        assert(l < n_);\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(f(Monoid::identity()));\n        u32 res{l}, width{1};\n  \
    \      Value prod{ Monoid::identity() };\n        // \u73FE\u5728\u306E\u898B\u3066\
    \u3044\u308B\u9802\u70B9\u306E\u5E45\u3092width\u3067\u6301\u3064\n        //\
    \ \u5883\u754C\u304C\u3042\u308B\u9802\u70B9\u3092\u542B\u3080\u90E8\u5206\u6728\
    \u306E\u6839\u3092\u63A2\u3059\n        // (\u6298\u308A\u8FD4\u3059\u6642\u306F\
    \u5FC5\u8981\u4EE5\u4E0A\u306E\u5E45\u3092\u6301\u3064\u6839\u306B\u306A\u308B\
    \u304C\u3001width\u3092\u6301\u3063\u3066\u3044\u308B\u306E\u3067\u30AA\u30FC\u30D0\
    \u30FC\u3057\u306A\u3044)\n        for (l += n_ ; res + width <= n_ ; l = parent(l),\
    \ width <<= 1) if (l & 1) {\n            if (not f(Monoid::operation(prod, dat_[l])))\
    \ break; \n            res += width;\n            prod = Monoid::operation(prod,\
    \ dat_[l++]);\n        }\n        // \u6839\u304B\u3089\u4E0B\u3063\u3066\u3001\
    \u5883\u754C\u3092\u767A\u898B\u3059\u308B\n        while (l = left(l), width\
    \ >>= 1) {\n            if (res + width <= n_ and f(Monoid::operation(prod, dat_[l])))\
    \ {\n                res += width;\n                prod = Monoid::operation(prod,\
    \ dat_[l++]);\n            } \n        }\n        return res;\n    }\n\n    template\
    \ <class Function>\n    u32 minLeft(u32 r, const Function& f) const {\n      \
    \  assert(r <= n_);\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(f(Monoid::identity()));\n        u32 res{r}, width{1};\n  \
    \      Value prod{ Monoid::identity() };\n        for (r += n_ ; res >= width\
    \ ; r = parent(r), width <<= 1) if (r & 1) {\n            if (not f(Monoid::operation(dat_[r\
    \ - 1], prod))) break;\n            res -= width;\n            prod = Monoid::operation(prod,\
    \ dat_[--r]);\n        }\n        while (r = left(r), width >>= 1) {\n       \
    \     if (res >= width and f(Monoid::operation(dat_[r - 1], prod))) {\n      \
    \          res -= width;\n                prod = Monoid::operation(dat_[--r],\
    \ prod);\n            }\n        }\n        return res;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const SegmentTree& st) {\n        for (u32 i{1}\
    \ ; i < 2 * st.n_ ; i++) {\n            os << st.dat_[i] << (i + 1 == 2 * st.n_\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Number/ModInt.hpp\"\n\n#line 4 \"Src/Number/ModInt.hpp\"\
    \n\n#line 7 \"Src/Number/ModInt.hpp\"\n#include <utility>\n#line 9 \"Src/Number/ModInt.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T, T mod>\nclass StaticModInt {\nprivate:\n\
    \    using mint = StaticModInt;\n\n    T v_{};\n\n    static constexpr void templateTypeAssert()\
    \ {\n        static_assert(std::is_integral_v<T>, \"ModInt template argument must\
    \ be integral\");\n        static_assert(mod > 0, \"mod must be positive\");\n\
    \    }\n\n    i64 extendGCD(i64 a, i64 b, i64& x, i64& y) const {\n       i64\
    \ d{a};\n       if (b) {\n           d = extendGCD(b, a % b, y, x);\n        \
    \   y -= (a / b) * x;\n       }\n       else {\n           x = 1;\n          \
    \ y = 0;\n       }\n       return d;\n    }\n\npublic:\n\n    constexpr StaticModInt()\
    \ {\n        templateTypeAssert();\n    }\n    template <class ArgType>\n    constexpr\
    \ StaticModInt(ArgType v) : v_{ static_cast<T>(((v % mod) + mod) % mod) } {\n\
    \        templateTypeAssert();\n        static_assert(std::is_integral_v<ArgType>,\
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
    \        return a_ * x + b_;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Affine& affine) {\n        os << '(' << affine.a_ << ',' << affine.b_\
    \ << ')';\n        return os;\n    }\n};\n\ntemplate <class T>\nstruct AffineMonoid\
    \ {\n    using Element = Affine<T>;\n    static constexpr Element identity() noexcept\
    \ {\n        return Element{};\n    }\n    static constexpr Element operation(const\
    \ Element& l, const Element& r) noexcept {\n        return Element{ l.a() * r.a(),\
    \ l.b() * r.a() + r.b() };\n    }\n};\n\n} // namespace zawa\n#line 8 \"Test/LC/point_set_range_composite.test.cpp\"\
    \n\nusing namespace zawa;\nusing mint = StaticModInt<u32, 998244353>;\nusing Monoid\
    \ = AffineMonoid<mint>;\n\n#line 15 \"Test/LC/point_set_range_composite.test.cpp\"\
    \n\nint main() {\n    SetFastIO();\n    int n, q; std::cin >> n >> q;\n    std::vector<Affine<mint>>\
    \ init(n);\n    for (int i{} ; i < n ; i++) {\n        u64 a, b; std::cin >> a\
    \ >> b;\n        init[i] = Affine<mint>{ a, b };\n    }\n    SegmentTree<Monoid>\
    \ seg(init);\n    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n\
    \        if (t == 0) {\n            int p, c, d; std::cin >> p >> c >> d;\n  \
    \          seg.set(p, { c, d });\n        }\n        else if (t == 1) {\n    \
    \        int l, r, x; std::cin >> l >> r >> x;\n            std::cout << seg.product(l,\
    \ r).mapping(x) << std::endl;\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n#include \"\
    ../../Src/Number/ModInt.hpp\"\n#include \"../../Src/Algebra/Monoid/AffineMonoid.hpp\"\
    \n\nusing namespace zawa;\nusing mint = StaticModInt<u32, 998244353>;\nusing Monoid\
    \ = AffineMonoid<mint>;\n\n#include <iostream>\n#include <vector>\n\nint main()\
    \ {\n    SetFastIO();\n    int n, q; std::cin >> n >> q;\n    std::vector<Affine<mint>>\
    \ init(n);\n    for (int i{} ; i < n ; i++) {\n        u64 a, b; std::cin >> a\
    \ >> b;\n        init[i] = Affine<mint>{ a, b };\n    }\n    SegmentTree<Monoid>\
    \ seg(init);\n    for (int _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n\
    \        if (t == 0) {\n            int p, c, d; std::cin >> p >> c >> d;\n  \
    \          seg.set(p, { c, d });\n        }\n        else if (t == 1) {\n    \
    \        int l, r, x; std::cin >> l >> r >> x;\n            std::cout << seg.product(l,\
    \ r).mapping(x) << std::endl;\n        }\n        else {\n            assert(false);\n\
    \        }\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Number/ModInt.hpp
  - Src/Algebra/Monoid/AffineMonoid.hpp
  isVerificationFile: true
  path: Test/LC/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-10-03 02:05:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/point_set_range_composite.test.cpp
- /verify/Test/LC/point_set_range_composite.test.cpp.html
title: Test/LC/point_set_range_composite.test.cpp
---