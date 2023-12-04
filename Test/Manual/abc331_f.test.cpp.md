---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/RollingHashMonoid.hpp
    title: "\u30ED\u30EA\u30CF\u3092\u30BB\u30B0\u6728\u306B\u306E\u305B\u308B\u6642\
      \u306E\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/Number/Mersenne61ModInt.hpp
    title: Src/Number/Mersenne61ModInt.hpp
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
    - https://atcoder.jp/contests/abc331/submissions/48195607
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/Manual/abc331_f.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * ABC331-F Palindrome Query\n * https://atcoder.jp/contests/abc331/submissions/48195607\n\
    \ */\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
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
    \ zawa\n#line 2 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\n#line 2 \"Src/Number/Mersenne61ModInt.hpp\"\
    \n\n#line 4 \"Src/Number/Mersenne61ModInt.hpp\"\n\nnamespace zawa {\n\n// @reference:\
    \ https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\nclass Mersenne61ModInt\
    \ {\npublic:\n    using Value = u64;\nprivate:\n    static constexpr Value MOD{(1ull\
    \ << 61) - 1}; // == MASK61\n    static constexpr Value MASK30{(1ull << 30) -\
    \ 1};\n    static constexpr Value MASK31{(1ull << 31) - 1};\n    Value v_{};\n\
    public:\n    constexpr Mersenne61ModInt() {}\n\n    static constexpr Value Mod()\
    \ noexcept {\n        return MOD;\n    }\n    static constexpr Value Modulo(const\
    \ Value& v) noexcept {\n        Value res{(v >> 61) + (v & MOD)};\n        res\
    \ = (res >= MOD ? res - MOD : res);\n        return res;\n    }\n    static constexpr\
    \ Value UnsafeMul(const Value& a, const Value& b) noexcept {\n        Value fa{a\
    \ >> 31}, fb{b >> 31};\n        Value ba{a & MASK31}, bb{b & MASK31};\n      \
    \  Value mid{fa * bb + fb * ba};\n        return Value{2}*fa*fb + (mid >> 30)\
    \ + ((mid & MASK30) << 31) + ba*bb;\n    }\n    static constexpr Value Mul(const\
    \ Value& a, const Value& b) noexcept {\n        return Modulo(UnsafeMul(a, b));\n\
    \    }\n};\n\n};\n#line 5 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\n#include\
    \ <random>\n#line 8 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\nnamespace\
    \ zawa {\n\nstruct RollingHashMonoidData {\n    using Value = Mersenne61ModInt::Value;\n\
    \    using Size = usize;\n    static Value base;\n    Value hash{}, pow{base};\n\
    \    usize len{};\n\n    constexpr RollingHashMonoidData() = default;\n    constexpr\
    \ RollingHashMonoidData(Value h, Value p, usize l) : hash{h}, pow{p}, len{l} {}\n\
    \    \n    // \u5358\u4E00\u8981\u7D20v\u304B\u3089\u306A\u308B\u30CF\u30C3\u30B7\
    \u30E5\u3092\u8FD4\u3059\n    template <class T>\n    static constexpr RollingHashMonoidData\
    \ generate(const T& v) {\n        static_assert(std::is_convertible_v<T, Value>,\
    \ \"v must be convertible unsigned interger value\");\n        return RollingHashMonoidData{v,\
    \ base, 1};\n    }\n\n    static Value randomValue(const Value& sigma) {\n   \
    \     return std::mt19937{std::random_device{}()}() % (Mersenne61ModInt::Mod()\
    \ - sigma) + sigma + 1;\n    }\n\n    friend constexpr bool operator==(const RollingHashMonoidData&\
    \ lhs, const RollingHashMonoidData& rhs) {\n        return lhs.hash == rhs.hash\
    \ and lhs.len == rhs.len;\n    }\n    friend constexpr bool operator!=(const RollingHashMonoidData&\
    \ lhs, const RollingHashMonoidData& rhs) {\n        return lhs.hash != rhs.hash\
    \ or lhs.len != rhs.len;\n    }\n};\n\nstruct RollingHashMonoid {\n    using Modulo\
    \ = Mersenne61ModInt;\n    using Element = RollingHashMonoidData;\n    static\
    \ constexpr Element identity() noexcept {\n        return Element{};\n    }\n\
    \    static constexpr Element operation(const Element& lhs, const Element& rhs)\
    \ noexcept {\n        return Element{\n            Modulo::Modulo(Modulo::UnsafeMul(lhs.hash,\
    \ rhs.pow) + rhs.hash),\n            Modulo::Mul(lhs.pow, rhs.pow),\n        \
    \    lhs.len + rhs.len\n        };\n    }\n};\n\n} // namespace zawa\n#line 11\
    \ \"Test/Manual/abc331_f.test.cpp\"\nusing namespace zawa;\n\n#line 16 \"Test/Manual/abc331_f.test.cpp\"\
    \n#include <string>\n#line 18 \"Test/Manual/abc331_f.test.cpp\"\n\nusing Value\
    \ = RollingHashMonoidData::Value;\n\nValue RollingHashMonoidData::base{\n    RollingHashMonoidData::randomValue(26)\n\
    };\n\nvoid solve() {\n    SetFastIO();\n    int n, q; std::cin >> n >> q;\n  \
    \  std::string s; std::cin >> s;\n\n    std::vector<RollingHashMonoidData> init(n),\
    \ tini(n); \n    for (int i{} ; i < n ; i++) {\n        init[i] = RollingHashMonoidData::generate((Value)s[i]);\n\
    \        tini[n - i - 1] = RollingHashMonoidData::generate((Value)s[i]);\n   \
    \ }\n\n    SegmentTree<RollingHashMonoid> seg(init), ges(tini);\n    for (int\
    \ _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if (t == 1) {\n\
    \            int x; std::cin >> x;\n            x--;\n            char c; std::cin\
    \ >> c;\n            seg.set(x, RollingHashMonoidData::generate((Value)c));\n\
    \            ges.set(n - x - 1, RollingHashMonoidData::generate((Value)c));\n\
    \        }\n        else if (t == 2) {\n            int l, r; std::cin >> l >>\
    \ r;\n            l--;\n            bool ans{seg.product(l, r) == ges.product(n\
    \ - r, n - l)};\n            std::cout << (ans ? \"Yes\" : \"No\") << '\\n';\n\
    \        }\n        else {\n            assert(!\"input fail\");\n        }\n\
    \    }\n }\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * ABC331-F Palindrome Query\n * https://atcoder.jp/contests/abc331/submissions/48195607\n\
    \ */\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/RollingHashMonoid.hpp\"\nusing namespace\
    \ zawa;\n\n#include <cassert>\n#include <iostream>\n#include <random>\n#include\
    \ <string>\n#include <vector>\n\nusing Value = RollingHashMonoidData::Value;\n\
    \nValue RollingHashMonoidData::base{\n    RollingHashMonoidData::randomValue(26)\n\
    };\n\nvoid solve() {\n    SetFastIO();\n    int n, q; std::cin >> n >> q;\n  \
    \  std::string s; std::cin >> s;\n\n    std::vector<RollingHashMonoidData> init(n),\
    \ tini(n); \n    for (int i{} ; i < n ; i++) {\n        init[i] = RollingHashMonoidData::generate((Value)s[i]);\n\
    \        tini[n - i - 1] = RollingHashMonoidData::generate((Value)s[i]);\n   \
    \ }\n\n    SegmentTree<RollingHashMonoid> seg(init), ges(tini);\n    for (int\
    \ _{} ; _ < q ; _++) {\n        int t; std::cin >> t;\n        if (t == 1) {\n\
    \            int x; std::cin >> x;\n            x--;\n            char c; std::cin\
    \ >> c;\n            seg.set(x, RollingHashMonoidData::generate((Value)c));\n\
    \            ges.set(n - x - 1, RollingHashMonoidData::generate((Value)c));\n\
    \        }\n        else if (t == 2) {\n            int l, r; std::cin >> l >>\
    \ r;\n            l--;\n            bool ans{seg.product(l, r) == ges.product(n\
    \ - r, n - l)};\n            std::cout << (ans ? \"Yes\" : \"No\") << '\\n';\n\
    \        }\n        else {\n            assert(!\"input fail\");\n        }\n\
    \    }\n }\n\nint main() {\n#ifdef ATCODER\n    solve();\n#else\n    std::cout\
    \ << \"Hello World\" << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Algebra/Monoid/RollingHashMonoid.hpp
  - Src/Number/Mersenne61ModInt.hpp
  isVerificationFile: true
  path: Test/Manual/abc331_f.test.cpp
  requiredBy: []
  timestamp: '2023-12-04 22:40:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/Manual/abc331_f.test.cpp
layout: document
redirect_from:
- /verify/Test/Manual/abc331_f.test.cpp
- /verify/Test/Manual/abc331_f.test.cpp.html
title: Test/Manual/abc331_f.test.cpp
---
