---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/RollingHashMonoid.hpp
    title: "\u30ED\u30EA\u30CF\u3092\u30BB\u30B0\u6728\u306B\u306E\u305B\u308B\u6642\
      \u306E\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
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
    - https://atcoder.jp/contests/abc331/submissions/68181997
    - https://atcoder.jp/contests/abc331/tasks/abc331_f
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc331_f.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc331/tasks/abc331_f\"\n\n\
    /*\n * AtCoder Beginner Contest 331 F - Palindrome Query\n * https://atcoder.jp/contests/abc331/submissions/68181997\n\
    \ */\n\n#line 2 \"Src/Template/IOSetting.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\n\n#include <iostream>\n\
    #include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO() {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n\
    }\n\nvoid SetPrecision(u32 dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n\
    }\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <ostream>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class SegmentTree {\npublic:\n\n    using VM = Monoid;\n\n    using V = typename\
    \ VM::Element;\n\n    using OM = Monoid;\n\n    using O = typename OM::Element;\n\
    \n    SegmentTree() = default;\n\n    explicit SegmentTree(usize n) : m_n{ n },\
    \ m_dat(n << 1, VM::identity()) {}\n\n    explicit SegmentTree(const std::vector<V>&\
    \ dat) : m_n{ dat.size() }, m_dat(dat.size() << 1, VM::identity()) {\n       \
    \ for (usize i{} ; i < m_n ; i++) {\n            m_dat[i + m_n] = dat[i];\n  \
    \      }\n        for (usize i{m_n} ; i-- ; ) {\n            m_dat[i] = VM::operation(m_dat[left(i)],\
    \ m_dat[right(i)]);\n        }\n    }\n\n    [[nodiscard]] inline usize size()\
    \ const noexcept {\n        return m_n;\n    }\n\n    [[nodiscard]] V get(usize\
    \ i) const {\n        assert(i < size());\n        return m_dat[i + m_n];\n  \
    \  }\n\n    [[nodiscard]] V operator[](usize i) const {\n        assert(i < size());\n\
    \        return m_dat[i + m_n];\n    }\n\n    void operation(usize i, const O&\
    \ value) {\n        assert(i < size());\n        i += size();\n        m_dat[i]\
    \ = OM::operation(m_dat[i], value);\n        while (i = parent(i), i) {\n    \
    \        m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n        }\n\
    \    }\n\n    void assign(usize i, const V& value) {\n        assert(i < size());\n\
    \        i += size();\n        m_dat[i] = value;\n        while (i = parent(i),\
    \ i) {\n            m_dat[i] = VM::operation(m_dat[left(i)], m_dat[right(i)]);\n\
    \        }\n    }\n\n    [[nodiscard]] V product(u32 l, u32 r) const {\n     \
    \   assert(l <= r and r <= size());\n        V L{ VM::identity() }, R{ VM::identity()\
    \ };\n        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r))\
    \ {\n            if (l & 1) {\n                L = VM::operation(L, m_dat[l++]);\n\
    \            }\n            if (r & 1) {\n                R = VM::operation(m_dat[--r],\
    \ R);\n            }\n        }\n        return VM::operation(L, R);\n    }\n\n\
    \    template <class F>\n    requires std::predicate<F, V>\n    [[nodiscard]]\
    \ usize maxRight(usize l, const F& f) {\n        assert(l < size());\n       \
    \ static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{l}, width{1};\n        V prod{ VM::identity() };\n        //\
    \ \u73FE\u5728\u306E\u898B\u3066\u3044\u308B\u9802\u70B9\u306E\u5E45\u3092width\u3067\
    \u6301\u3064\n        // \u5883\u754C\u304C\u3042\u308B\u9802\u70B9\u3092\u542B\
    \u3080\u90E8\u5206\u6728\u306E\u6839\u3092\u63A2\u3059\n        // (\u6298\u308A\
    \u8FD4\u3059\u6642\u306F\u5FC5\u8981\u4EE5\u4E0A\u306E\u5E45\u3092\u6301\u3064\
    \u6839\u306B\u306A\u308B\u304C\u3001width\u3092\u6301\u3063\u3066\u3044\u308B\u306E\
    \u3067\u30AA\u30FC\u30D0\u30FC\u3057\u306A\u3044)\n        for (l += size() ;\
    \ res + width <= size() ; l = parent(l), width <<= 1) if (l & 1) {\n         \
    \   if (not f(VM::operation(prod, m_dat[l]))) break; \n            res += width;\n\
    \            prod = VM::operation(prod, m_dat[l++]);\n        }\n        // \u6839\
    \u304B\u3089\u4E0B\u3063\u3066\u3001\u5883\u754C\u3092\u767A\u898B\u3059\u308B\
    \n        while (l = left(l), width >>= 1) {\n            if (res + width <= size()\
    \ and f(VM::operation(prod, m_dat[l]))) {\n                res += width;\n   \
    \             prod = VM::operation(prod, m_dat[l++]);\n            } \n      \
    \  }\n        return res;\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    [[nodiscard]] usize minLeft(usize r, const F& f) const {\n        assert(r\
    \ <= size());\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(f(VM::identity()));\n\
    \        usize res{r}, width{1};\n        V prod{ VM::identity() };\n        for\
    \ (r += size() ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {\n   \
    \         if (not f(VM::operation(m_dat[r - 1], prod))) break;\n            res\
    \ -= width;\n            prod = VM::operation(prod, m_dat[--r]);\n        }\n\
    \        while (r = left(r), width >>= 1) {\n            if (res >= width and\
    \ f(VM::operation(m_dat[r - 1], prod))) {\n                res -= width;\n   \
    \             prod = VM::operation(m_dat[--r], prod);\n            }\n       \
    \ }\n        return res;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const SegmentTree& st) {\n        for (usize i{1} ; i < 2 * st.size() ;\
    \ i++) {\n            os << st.m_dat[i] << (i + 1 == 2 * st.size() ? \"\" : \"\
    \ \");\n        }\n        return os;\n    }\n\nprivate:\n\n    constexpr u32\
    \ left(u32 v) const {\n        return v << 1;\n    }\n\n    constexpr u32 right(u32\
    \ v) const {\n        return v << 1 | 1;\n    }\n\n    constexpr u32 parent(u32\
    \ v) const {\n        return v >> 1;\n    }\n\n    usize m_n;\n\n    std::vector<V>\
    \ m_dat;\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\
    \n\n#line 2 \"Src/Number/Mersenne61ModInt.hpp\"\n\n#line 4 \"Src/Number/Mersenne61ModInt.hpp\"\
    \n\nnamespace zawa {\n\n// @reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    class Mersenne61ModInt {\npublic:\n    using Value = u64;\nprivate:\n    static\
    \ constexpr Value MOD{(1ull << 61) - 1}; // == MASK61\n    static constexpr Value\
    \ MASK30{(1ull << 30) - 1};\n    static constexpr Value MASK31{(1ull << 31) -\
    \ 1};\n    Value v_{};\npublic:\n    constexpr Mersenne61ModInt() {}\n\n    static\
    \ constexpr Value Mod() noexcept {\n        return MOD;\n    }\n    static constexpr\
    \ Value Modulo(const Value& v) noexcept {\n        Value res{(v >> 61) + (v &\
    \ MOD)};\n        res = (res >= MOD ? res - MOD : res);\n        return res;\n\
    \    }\n    static constexpr Value UnsafeMul(const Value& a, const Value& b) noexcept\
    \ {\n        Value fa{a >> 31}, fb{b >> 31};\n        Value ba{a & MASK31}, bb{b\
    \ & MASK31};\n        Value mid{fa * bb + fb * ba};\n        return Value{2}*fa*fb\
    \ + (mid >> 30) + ((mid & MASK30) << 31) + ba*bb;\n    }\n    static constexpr\
    \ Value Mul(const Value& a, const Value& b) noexcept {\n        return Modulo(UnsafeMul(a,\
    \ b));\n    }\n};\n\n};\n#line 5 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\
    \n#include <random>\n#line 8 \"Src/Algebra/Monoid/RollingHashMonoid.hpp\"\n\n\
    namespace zawa {\n\nstruct RollingHashMonoidData {\n    using Value = Mersenne61ModInt::Value;\n\
    \    using Size = usize;\n    static Value base;\n    Value hash{}, pow{1};\n\
    \    usize len{};\n\n    constexpr RollingHashMonoidData() = default;\n    constexpr\
    \ RollingHashMonoidData(Value h, Value p, usize l) : hash{h}, pow{p}, len{l} {}\n\
    \    template <class T>\n    constexpr RollingHashMonoidData(const T& v) \n  \
    \      : hash{static_cast<Value>(v)}, pow{base}, len{1} {}\n    // RollingHashMonoidData(const\
    \ RollingHashMonoidData& data)\n    //     : hash{data.hash}, pow{data.pow}, len{data.len}\
    \ {}\n    \n    static Value randomValue(const Value& sigma) {\n        return\
    \ std::mt19937{std::random_device{}()}() % (Mersenne61ModInt::Mod() - sigma) +\
    \ sigma + 1;\n    }\n\n    friend constexpr bool operator==(const RollingHashMonoidData&\
    \ lhs, const RollingHashMonoidData& rhs) {\n        return lhs.hash == rhs.hash\
    \ and lhs.len == rhs.len;\n    }\n    friend constexpr bool operator!=(const RollingHashMonoidData&\
    \ lhs, const RollingHashMonoidData& rhs) {\n        return lhs.hash != rhs.hash\
    \ or lhs.len != rhs.len;\n    }\n};\n\nstruct RollingHashMonoid {\n    using Modulo\
    \ = Mersenne61ModInt;\n    using Element = RollingHashMonoidData;\n    static\
    \ constexpr Element identity() noexcept {\n        return Element{};\n    }\n\
    \    static constexpr Element operation(const Element& lhs, const Element& rhs)\
    \ noexcept {\n        return Element{\n            Modulo::Modulo(Modulo::UnsafeMul(lhs.hash,\
    \ rhs.pow) + rhs.hash),\n            Modulo::Mul(lhs.pow, rhs.pow),\n        \
    \    lhs.len + rhs.len\n        };\n    }\n};\n\n} // namespace zawa\n#line 12\
    \ \"Test/AtCoder/abc331_f.test.cpp\"\nusing namespace zawa;\n\n#line 17 \"Test/AtCoder/abc331_f.test.cpp\"\
    \n#include <string>\n#line 19 \"Test/AtCoder/abc331_f.test.cpp\"\n\nusing Value\
    \ = RollingHashMonoidData::Value;\n\nValue RollingHashMonoidData::base{\n    RollingHashMonoidData::randomValue(26)\n\
    };\n\nint main() {\n#ifdef ATCODER\n    SetFastIO();\n    int N, Q; \n    std::cin\
    \ >> N >> Q;\n    std::string S; \n    std::cin >> S;\n\n    std::vector<RollingHashMonoidData>\
    \ init(N), tini(N); \n    for (int i{} ; i < N ; i++) {\n        init[i] = RollingHashMonoidData{S[i]};\n\
    \        tini[N - i - 1] = RollingHashMonoidData{S[i]};\n    }\n    SegmentTree<RollingHashMonoid>\
    \ seg{init}, ges{tini};\n    while(Q--) {\n        int t; \n        std::cin >>\
    \ t;\n        if (t == 1) {\n            int x; \n            std::cin >> x;\n\
    \            x--;\n            char c; \n            std::cin >> c;\n        \
    \    seg.assign(x, RollingHashMonoidData{c});\n            ges.assign(N - x -\
    \ 1, RollingHashMonoidData{c});\n        }\n        else if (t == 2) {\n     \
    \       int l, r; std::cin >> l >> r;\n            l--;\n            bool ans{seg.product(l,\
    \ r) == ges.product(N - r, N - l)};\n            std::cout << (ans ? \"Yes\" :\
    \ \"No\") << '\\n';\n        }\n        else {\n            assert(!\"input fail\"\
    );\n        }\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/abc331/tasks/abc331_f\"\n\n\
    /*\n * AtCoder Beginner Contest 331 F - Palindrome Query\n * https://atcoder.jp/contests/abc331/submissions/68181997\n\
    \ */\n\n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/SegmentTree.hpp\"\
    \n#include \"../../Src/Algebra/Monoid/RollingHashMonoid.hpp\"\nusing namespace\
    \ zawa;\n\n#include <cassert>\n#include <iostream>\n#include <random>\n#include\
    \ <string>\n#include <vector>\n\nusing Value = RollingHashMonoidData::Value;\n\
    \nValue RollingHashMonoidData::base{\n    RollingHashMonoidData::randomValue(26)\n\
    };\n\nint main() {\n#ifdef ATCODER\n    SetFastIO();\n    int N, Q; \n    std::cin\
    \ >> N >> Q;\n    std::string S; \n    std::cin >> S;\n\n    std::vector<RollingHashMonoidData>\
    \ init(N), tini(N); \n    for (int i{} ; i < N ; i++) {\n        init[i] = RollingHashMonoidData{S[i]};\n\
    \        tini[N - i - 1] = RollingHashMonoidData{S[i]};\n    }\n    SegmentTree<RollingHashMonoid>\
    \ seg{init}, ges{tini};\n    while(Q--) {\n        int t; \n        std::cin >>\
    \ t;\n        if (t == 1) {\n            int x; \n            std::cin >> x;\n\
    \            x--;\n            char c; \n            std::cin >> c;\n        \
    \    seg.assign(x, RollingHashMonoidData{c});\n            ges.assign(N - x -\
    \ 1, RollingHashMonoidData{c});\n        }\n        else if (t == 2) {\n     \
    \       int l, r; std::cin >> l >> r;\n            l--;\n            bool ans{seg.product(l,\
    \ r) == ges.product(N - r, N - l)};\n            std::cout << (ans ? \"Yes\" :\
    \ \"No\") << '\\n';\n        }\n        else {\n            assert(!\"input fail\"\
    );\n        }\n    }\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/SegmentTree.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Monoid/RollingHashMonoid.hpp
  - Src/Number/Mersenne61ModInt.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc331_f.test.cpp
  requiredBy: []
  timestamp: '2025-08-03 16:41:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc331_f.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc331_f.test.cpp
- /verify/Test/AtCoder/abc331_f.test.cpp.html
title: Test/AtCoder/abc331_f.test.cpp
---
