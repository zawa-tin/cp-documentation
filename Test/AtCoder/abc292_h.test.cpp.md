---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/AdditionMonoid.hpp
    title: Src/Algebra/Monoid/AdditionMonoid.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MaxMonoid.hpp
    title: "max\u6F14\u7B97\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/PrefixProductMonoid.hpp
    title: "\u533A\u9593Prefix\u7DCF\u7A4D\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTree.hpp
    title: Segment Tree
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
    ERROR: 1e-9
    PROBLEM: https://atcoder.jp/contests/abc292/tasks/abc292_ex
    links:
    - https://atcoder.jp/contests/abc292/tasks/abc292_ex
  bundledCode: "#line 1 \"Test/AtCoder/abc292_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_ex\"\
    \n#define ERROR 1e-9\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/AdditionMonoid.hpp\"\n\n\
    namespace zawa {\n\ntemplate <class T>\nstruct AdditionMonoid {\n    using Element\
    \ = T;\n    static T identity() noexcept {\n        return T{};\n    }\n    static\
    \ T operation(const T& a, const T& b) noexcept {\n        return a + b;\n    }\n\
    };\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MaxMonoid.hpp\"\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <optional>\n\nnamespace zawa {\n\n\
    template <class T>\nclass MaxMonoid {\npublic:\n    using Element = std::optional<T>;\n\
    \    static constexpr Element identity() noexcept {\n        return std::nullopt;\n\
    \    }\n    static constexpr Element operation(const Element& l, const Element&\
    \ r) noexcept {\n        if (l and r) {\n            return std::max(l, r);\n\
    \        }\n        else if (l) {\n            return l;\n        }\n        else\
    \ if (r) {\n            return r;\n        }\n        else {\n            return\
    \ std::nullopt;\n        }\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/PrefixProductMonoid.hpp\"\
    \n\n#include <type_traits>\n\nnamespace zawa {\n\ntemplate <class Value>\nclass\
    \ PrefixProductMonoidData {\n    Value product_{}, prefix_{};\npublic:\n    PrefixProductMonoidData()\
    \ = default;\n    PrefixProductMonoidData(const Value& product, const Value& prefix)\n\
    \        : product_{product}, prefix_{prefix} {}\n\n    inline const Value& product()\
    \ const noexcept {\n        return product_;\n    }\n    inline const Value& prefix()\
    \ const noexcept {\n        return prefix_;\n    }\n};\n\ntemplate <class O, class\
    \ F>\nclass PrefixProductMonoid {\n    static_assert(std::is_same_v<typename O::Element,\
    \ typename F::Element>);\npublic:\n    using Element = PrefixProductMonoidData<typename\
    \ O::Element>;\n    static Element identity() noexcept {\n        return PrefixProductMonoidData{O::identity(),\
    \ F::identity()};\n    }\n    static Element operation(const Element& l, const\
    \ Element& r) noexcept {\n        return PrefixProductMonoidData{\n          \
    \  O::operation(l.product(), r.product()),\n            F::operation(l.prefix(),\
    \ O::operation(l.product(), r.prefix()))\n        };\n    }\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#line 4 \"\
    Src/DataStructure/SegmentTree/SegmentTree.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <functional>\n#line 9 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n#include <ostream>\n\nnamespace zawa {\n\ntemplate <class Monoid>\nclass SegmentTree\
    \ {\npublic:\n    using Value = typename Monoid::Element;\nprivate:\n    constexpr\
    \ u32 left(u32 v) const {\n        return v << 1;\n    }\n    constexpr u32 right(u32\
    \ v) const {\n        return v << 1 | 1;\n    }\n    constexpr u32 parent(u32\
    \ v) const {\n        return v >> 1;\n    }\n\n    usize n_;\n    std::vector<Value>\
    \ dat_;\n\npublic:\n    SegmentTree() = default;\n    SegmentTree(u32 n) : n_{\
    \ n }, dat_(n << 1, Monoid::identity()) {\n        assert(n_);\n    }\n    SegmentTree(const\
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
    \ zawa\n#line 9 \"Test/AtCoder/abc292_h.test.cpp\"\n\n#line 15 \"Test/AtCoder/abc292_h.test.cpp\"\
    \n\nusing namespace zawa; \nusing D = std::optional<long long>;\nusing vM = MaxMonoid<long\
    \ long>;\nstruct oM {\n    using Element = D;\n    static D identity() noexcept\
    \ {\n        return 0LL;\n    }\n    static D operation(const D& l, const D& r)\
    \ noexcept {\n        if (l and r) return l.value() + r.value();\n        else\
    \ return (l ? l : (r ? r : 0LL));\n    }\n};\nusing M = PrefixProductMonoid<oM,\
    \ vM>;\n\nint main() {\n    SetFastIO();\n    SetPrecision(10);\n\n    int n,\
    \ q;\n    long long b;\n    std::cin >> n >> b >> q;\n    std::vector<M::Element>\
    \ a(n);\n    for (int i{} ; i < n ; i++) {\n        long long v; std::cin >> v;\n\
    \        a[i] = M::Element{D{v - b}, D{v - b}};\n    }\n    SegmentTree<M> seg(a);\n\
    \    for (int _{} ; _ < q ; _++) {\n        int c; std::cin >> c;\n        c--;\n\
    \        long long x; std::cin >> x;\n        x -= b;\n        seg.set(c, M::Element{D{x},\
    \ D{x}});\n        auto r{seg.maxRight(0, [](const M::Element& v) -> bool { return\
    \ (!(bool)v.prefix() or v.prefix().value() < 0LL); })};\n        r = std::min<int>(r\
    \ + 1, n);\n        assert(seg.product(0, r).product().has_value());\n       \
    \ long long sum{seg.product(0, r).product().value()};\n        long double ans{(long\
    \ double)(sum + b * (long long)r) / (long double)r};\n        std::cout << ans\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc292/tasks/abc292_ex\"\n\
    #define ERROR 1e-9\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include\
    \ \"../../Src/Algebra/Monoid/AdditionMonoid.hpp\"\n#include \"../../Src/Algebra/Monoid/MaxMonoid.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/PrefixProductMonoid.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <optional>\n\
    #include <vector>\n\nusing namespace zawa; \nusing D = std::optional<long long>;\n\
    using vM = MaxMonoid<long long>;\nstruct oM {\n    using Element = D;\n    static\
    \ D identity() noexcept {\n        return 0LL;\n    }\n    static D operation(const\
    \ D& l, const D& r) noexcept {\n        if (l and r) return l.value() + r.value();\n\
    \        else return (l ? l : (r ? r : 0LL));\n    }\n};\nusing M = PrefixProductMonoid<oM,\
    \ vM>;\n\nint main() {\n    SetFastIO();\n    SetPrecision(10);\n\n    int n,\
    \ q;\n    long long b;\n    std::cin >> n >> b >> q;\n    std::vector<M::Element>\
    \ a(n);\n    for (int i{} ; i < n ; i++) {\n        long long v; std::cin >> v;\n\
    \        a[i] = M::Element{D{v - b}, D{v - b}};\n    }\n    SegmentTree<M> seg(a);\n\
    \    for (int _{} ; _ < q ; _++) {\n        int c; std::cin >> c;\n        c--;\n\
    \        long long x; std::cin >> x;\n        x -= b;\n        seg.set(c, M::Element{D{x},\
    \ D{x}});\n        auto r{seg.maxRight(0, [](const M::Element& v) -> bool { return\
    \ (!(bool)v.prefix() or v.prefix().value() < 0LL); })};\n        r = std::min<int>(r\
    \ + 1, n);\n        assert(seg.product(0, r).product().has_value());\n       \
    \ long long sum{seg.product(0, r).product().value()};\n        long double ans{(long\
    \ double)(sum + b * (long long)r) / (long double)r};\n        std::cout << ans\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/AdditionMonoid.hpp
  - Src/Algebra/Monoid/MaxMonoid.hpp
  - Src/Algebra/Monoid/PrefixProductMonoid.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc292_h.test.cpp
  requiredBy: []
  timestamp: '2024-02-09 20:29:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc292_h.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc292_h.test.cpp
- /verify/Test/AtCoder/abc292_h.test.cpp.html
title: Test/AtCoder/abc292_h.test.cpp
---
