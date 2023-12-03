---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
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
    PROBLEM: https://atcoder.jp/contests/abc276/tasks/abc276_f
    links:
    - https://atcoder.jp/contests/abc276/tasks/abc276_f
  bundledCode: "#line 1 \"Test/AtCoder/abc276_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_f\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n#include <iomanip>\n\
    \nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Number/ModInt.hpp\"\n\n#line 4 \"Src/Number/ModInt.hpp\"\
    \n\n#include <type_traits>\n#line 7 \"Src/Number/ModInt.hpp\"\n#include <utility>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class T, T mod>\nclass StaticModInt\
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
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 4 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#include <vector>\n\
    #line 7 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n#include <ostream>\n\
    #include <functional>\n#line 10 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class Group>\nclass FenwickTree {\nprivate:\n\
    \    using Value = typename Group::Element;\n\n    usize n_;\n    u32 bitWidth_;\n\
    \    std::vector<Value> a_, dat_;\n\n    constexpr i32 lsb(i32 x) const noexcept\
    \ {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i] + v\n    void addDat(i32\
    \ i, const Value& v) {\n        assert(0 <= i and i < static_cast<i32>(n_));\n\
    \        for ( i++ ; i < static_cast<i32>(dat_.size()) ; i += lsb(i)) {\n    \
    \        dat_[i] = Group::operation(dat_[i], v);\n        }\n    }\n\n    // return\
    \ a[0] + a[1] + .. + a[i - 1]\n    Value product(i32 i) const {\n        assert(0\
    \ <= i and i <= static_cast<i32>(n_));\n        Value res{ Group::identity() };\n\
    \        for ( ; i > 0 ; i -= lsb(i)) {\n            res = Group::operation(res,\
    \ dat_[i]);\n        }\n        return res;\n    }\n\npublic:\n    FenwickTree()\
    \ : n_{}, bitWidth_{}, a_{}, dat_{} {}\n\n    FenwickTree(usize n) : n_{ n },\
    \ bitWidth_{ std::__lg(static_cast<u32>(n)) + 1 }, a_(n), dat_(n + 1, Group::identity())\
    \ {\n        dat_.shrink_to_fit();\n    }\n\n    FenwickTree(const std::vector<Value>&\
    \ a) : n_{ a.size() }, bitWidth_{ std::__lg(static_cast<u32>(a.size())) + 1 },\
    \ a_(a), dat_(a.size() + 1, Group::identity()) {\n        dat_.shrink_to_fit();\
    \  \n        for (i32 i{} ; i < static_cast<i32>(n_) ; i++) {\n            addDat(i,\
    \ a[i]);\n        }\n    }\n\n    // return a[i]\n    const Value& get(usize i)\
    \ const noexcept {\n        assert(i < n_);\n        return a_[i];\n    }\n\n\
    \    // return a[i]\n    const Value& operator[](usize i) const noexcept {\n \
    \       assert(i < n_);\n        return a_[i];\n    }\n\n    usize size() const\
    \ noexcept {\n        return n_;\n    }\n\n    // a[i] <- a[i] + v\n    void operation(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, v);\n     \
    \   a_[i] = Group::operation(a_[i], v);\n    }\n\n    // a[i] <- v\n    void set(usize\
    \ i, const Value& v) {\n        assert(i < n_);\n        addDat(i, Group::operation(Group::inverse(a_[i]),\
    \ v));\n        a_[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n\
    \    Value prefixProduct(usize r) const {\n        assert(r <= n_);\n        return\
    \ product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n    Value\
    \ product(usize l, usize r) const {\n        assert(l <= r and r <= n_);\n   \
    \     return Group::operation(Group::inverse(product(l)), product(r));\n    }\n\
    \n    template <class Function>\n    u32 maxRight(usize l, const Function& f)\
    \ const {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>,\
    \ \"maxRight's argument f must be function bool(T)\");\n        assert(l < n_);\n\
    \        Value sum{ Group::inverse(product(l)) }; \n        u32 r{};\n       \
    \ for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n            u32 nxt{\
    \ r | (1u << bit) };\n            if (nxt < dat_.size() and f(Group::operation(sum,\
    \ dat_[nxt]))) {\n                sum = Group::operation(sum, dat_[nxt]);\n  \
    \              r = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return r;\n    }\n\n    template <class Function>\n    u32 minLeft(usize\
    \ r, const Function& f) const {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(Value)>>, \"minLeft's argument f must be function bool(T)\"\
    );\n        assert(r <= n_);\n        Value sum{ product(r) };\n        u32 l{};\n\
    \        for (u32 bit{ bitWidth_ } ; bit ; ) {\n            bit--;\n         \
    \   u32 nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]),\
    \ sum))) {\n                sum = Group::operation(Group::inverse(dat_[nxt]),\
    \ sum);\n                l = std::move(nxt);\n            }\n        }\n     \
    \   assert(l <= r);\n        return l;\n    }\n\n    // debug print\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {\n      \
    \  for (u32 i{} ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i)\
    \ << (i == ft.size() ? \"\" : \" \");\n        }\n        return os;\n    }\n\n\
    };\n\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n   \
    \ using Element = T;\n    static constexpr T identity() noexcept {\n        return\
    \ T{};\n    }\n    static constexpr T operation(const T& l, const T& r) noexcept\
    \ {\n        return l + r;\n    }\n    static constexpr T inverse(const T& v)\
    \ noexcept {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 8 \"\
    Test/AtCoder/abc276_f.test.cpp\"\n\n#line 10 \"Test/AtCoder/abc276_f.test.cpp\"\
    \n\nusing namespace zawa;\nusing m32 = StaticModInt<u32, 998244353>;\n\nint main()\
    \ {\n    SetFastIO();\n    usize n; std::cin >> n;\n\n    const usize sz{ 200200\
    \ };\n    FenwickTree<AdditiveGroup<m32>> ft1(sz), ft2(sz);\n\n    m32 now{};\n\
    \    m32 ans{};\n    for (u32 k{1} ; k <= n ; k++) {\n        m32 a; std::cin\
    \ >> a;\n        now += (m32{2} * ft1.prefixProduct(a.v() + 1) + m32{1}) * a;\n\
    \        now += m32{2} * ft2.product(a.v() + 1, sz);\n        ans = now / (m32{k}\
    \ * m32{k});\n\n        std::cout << ans << '\\n';\n\n        ft1.operation(a.v(),\
    \ m32{1});\n        ft2.operation(a.v(), a);\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_f\"\n\n\
    #include \"../../Src/Template/TypeAlias.hpp\"\n#include \"../../Src/Template/IOSetting.hpp\"\
    \n#include \"../../Src/Number/ModInt.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n\n#include <iostream>\n\
    \nusing namespace zawa;\nusing m32 = StaticModInt<u32, 998244353>;\n\nint main()\
    \ {\n    SetFastIO();\n    usize n; std::cin >> n;\n\n    const usize sz{ 200200\
    \ };\n    FenwickTree<AdditiveGroup<m32>> ft1(sz), ft2(sz);\n\n    m32 now{};\n\
    \    m32 ans{};\n    for (u32 k{1} ; k <= n ; k++) {\n        m32 a; std::cin\
    \ >> a;\n        now += (m32{2} * ft1.prefixProduct(a.v() + 1) + m32{1}) * a;\n\
    \        now += m32{2} * ft2.product(a.v() + 1, sz);\n        ans = now / (m32{k}\
    \ * m32{k});\n\n        std::cout << ans << '\\n';\n\n        ft1.operation(a.v(),\
    \ m32{1});\n        ft2.operation(a.v(), a);\n    }\n}\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Template/IOSetting.hpp
  - Src/Number/ModInt.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc276_f.test.cpp
  requiredBy: []
  timestamp: '2023-12-03 18:29:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc276_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc276_f.test.cpp
- /verify/Test/AtCoder/abc276_f.test.cpp.html
title: Test/AtCoder/abc276_f.test.cpp
---
