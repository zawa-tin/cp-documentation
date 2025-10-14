---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/GroupConcept.hpp
    title: Src/Algebra/Group/GroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/FenwickTree/FenwickTree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/Number/IntegerDivision.hpp
    title: "\u6574\u6570\u540C\u58EB\u306E\u5207\u308A\u6368\u3066/\u5207\u308A\u4E0A\
      \u3052\u9664\u7B97"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Set/OfflineOrderedSet.hpp
    title: Src/DataStructure/Set/OfflineOrderedSet.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/ordered_set/OfflineOrderedSet.test.cpp
    title: Test/LC/ordered_set/OfflineOrderedSet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/DataStructure/Set/FenwickSet.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 2 \"Src/Number/IntegerDivision.hpp\"\n\n#include\
    \ <type_traits>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class T>\n\
    constexpr T DivFloor(T a, T b) {\n    static_assert(std::is_integral_v<T>, \"\
    DivFloor argument must be Integer\");\n    assert(b != T{});\n    if constexpr\
    \ (std::is_unsigned_v<T>) {\n        return a / b;\n    }\n    else {\n      \
    \  if (b < 0) {\n            a *= -1;\n            b *= -1;\n        }\n     \
    \   return (a >= 0 ? a / b : (a - b + 1) / b);\n    }\n}\n\ntemplate <class T>\n\
    constexpr T DivCeil(T a, T b) {\n    static_assert(std::is_integral_v<T>, \"DivCeil\
    \ argument must be Integer\");\n    assert(b != T{});\n    if constexpr (std::is_unsigned_v<T>)\
    \ {\n        return (a + b - 1) / b;\n    }\n    else {\n        if (b < 0) {\n\
    \            a *= -1;\n            b *= -1;\n        }\n        return (a >= 0\
    \ ? (a + b - 1) / b : a / b);\n    }\n}\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\n#include <vector>\n#line 8 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n#include <ostream>\n#include <functional>\n#line 11 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\nclass FenwickTree\
    \ {\npublic:\n\n    using VM = Monoid;\n    \n    using V = typename VM::Element;\n\
    \n    FenwickTree() = default;\n\n    explicit FenwickTree(usize n) : m_n{ n },\
    \ m_bitwidth{ std::__lg(n) + 1 }, m_a(n, VM::identity()), m_dat(n + 1, VM::identity())\
    \ {\n        m_dat.shrink_to_fit();\n        m_a.shrink_to_fit();\n    }\n\n \
    \   explicit FenwickTree(const std::vector<V>& a) : m_n{ a.size() }, m_bitwidth{\
    \ std::__lg(a.size()) + 1 }, m_a(a), m_dat(a.size() + 1, VM::identity()) {\n \
    \       m_dat.shrink_to_fit();  \n        m_a.shrink_to_fit();\n        for (i32\
    \ i{} ; i < static_cast<i32>(m_n) ; i++) {\n            addDat(i, a[i]);\n   \
    \     }\n    }\n\n    inline usize size() const noexcept {\n        return m_n;\n\
    \    }\n\n    // return a[i]\n    const V& get(usize i) const noexcept {\n   \
    \     assert(i < size());\n        return m_a[i];\n    }\n\n    // return a[i]\n\
    \    const V& operator[](usize i) const noexcept {\n        assert(i < size());\n\
    \        return m_a[i];\n    }\n\n    // a[i] <- a[i] + v\n    void operation(usize\
    \ i, const V& v) {\n        assert(i < size());\n        addDat(i, v);\n     \
    \   m_a[i] = VM::operation(m_a[i], v);\n    }\n\n    // a[i] <- v\n    void assign(usize\
    \ i, const V& v) requires concepts::Inversible<Monoid> {\n        assert(i < size());\n\
    \        addDat(i, VM::operation(VM::inverse(m_a[i]), v));\n        m_a[i] = v;\n\
    \    }\n\n    // return a[0] + a[1] + ... + a[r - 1]\n    V prefixProduct(usize\
    \ r) const {\n        assert(r <= size());\n        return product(r);\n    }\n\
    \n    // return a[l] + a[l + 1] ... + a[r - 1]\n    V product(usize l, usize r)\
    \ const requires concepts::Inversible<Monoid> {\n        assert(l <= r and r <=\
    \ size());\n        return VM::operation(VM::inverse(product(l)), product(r));\n\
    \    }\n\n    template <class Function>\n    usize maxRight(usize l, const Function&\
    \ f) const requires concepts::Inversible<Monoid> {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"maxRight's argument f must be function bool(T)\"\
    );\n        assert(l <= size());\n        assert(f(VM::identity()));\n       \
    \ V sum{ VM::inverse(product(l)) }; \n        usize r{};\n        for (usize bit{\
    \ m_bitwidth } ; bit ; ) {\n            bit--;\n            usize nxt{ r | (1u\
    \ << bit) };\n            if (nxt < m_dat.size() and (nxt <= l or f(VM::operation(sum,\
    \ m_dat[nxt])))) {\n                sum = VM::operation(sum, m_dat[nxt]);\n  \
    \              r = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return r;\n    }\n\n    template <class Function>\n    usize\
    \ minLeft(usize r, const Function& f) const requires concepts::Inversible<Monoid>\
    \ {\n        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>,\
    \ \"minLeft's argument f must be function bool(T)\");\n        assert(r <= size());\n\
    \        assert(f(VM::identity()));\n        V sum{ product(r) };\n        usize\
    \ l{};\n        for (usize bit{ m_bitwidth } ; bit ; ) {\n            bit--;\n\
    \            usize nxt{ l | (1u << bit) };\n            if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]),\
    \ sum))) {\n                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);\n\
    \                l = std::move(nxt);\n            }\n        }\n        assert(l\
    \ <= r);\n        return l;\n    }\n\n    // debug print\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const FenwickTree& ft) {\n        for (usize i{}\
    \ ; i <= ft.size() ; i++) {\n            os << ft.prefixProduct(i) << (i == ft.size()\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n\nprivate:\n\n    usize\
    \ m_n{};\n\n    usize m_bitwidth{};\n\n    std::vector<V> m_a, m_dat;\n\n    constexpr\
    \ i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n    \n    //\
    \ a[i] <- a[i] + v\n    void addDat(i32 i, const V& v) {\n        assert(0 <=\
    \ i and i < static_cast<i32>(m_n));\n        for ( i++ ; i < static_cast<i32>(m_dat.size())\
    \ ; i += lsb(i)) {\n            m_dat[i] = VM::operation(m_dat[i], v);\n     \
    \   }\n    }\n\n    // return a[0] + a[1] + .. + a[i - 1]\n    V product(i32 i)\
    \ const {\n        assert(0 <= i and i <= static_cast<i32>(m_n));\n        V res{\
    \ VM::identity() };\n        for ( ; i > 0 ; i -= lsb(i)) {\n            res =\
    \ VM::operation(res, m_dat[i]);\n        }\n        return res;\n    }\n\n};\n\
    \n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n    using Element\
    \ = T;\n    static constexpr T identity() noexcept {\n        return T{};\n  \
    \  }\n    static constexpr T operation(const T& l, const T& r) noexcept {\n  \
    \      return l + r;\n    }\n    static constexpr T inverse(const T& v) noexcept\
    \ {\n        return -v;\n    }\n};\n\n} // namespace zawa\n#line 7 \"Src/DataStructure/Set/FenwickSet.hpp\"\
    \n\n#include <bit>\n#line 11 \"Src/DataStructure/Set/FenwickSet.hpp\"\n#include\
    \ <optional>\n\nnamespace zawa {\n\nclass FenwickSet {\npublic:\n\n    FenwickSet()\
    \ = default;\n\n    explicit FenwickSet(usize n) \n        : m_n{n}, m_m{DivCeil<usize>(n,\
    \ 64)}, m_dat(m_m), m_fen(m_m), m_all{} {}\n\n    constexpr usize maxValue() const\
    \ {\n        return m_n;\n    }\n\n    usize size() const {\n        return m_all;\n\
    \    }\n\n    void insert(i32 x) {\n        assert(0 <= x);\n        assert(static_cast<usize>(x)\
    \ < maxValue());\n        if ((m_dat[x / 64] >> (x % 64)) & 1) \n            return;\n\
    \        m_dat[x / 64] |= u64{1} << (x % 64);\n        m_fen.operation(x / 64,\
    \ 1);\n        m_all++;\n    }\n\n    void erase(i32 x) {\n        assert(static_cast<usize>(x)\
    \ < maxValue());\n        if ((m_dat[x / 64] >> (x % 64)) & 1) {\n           \
    \ m_dat[x / 64] ^= u64{1} << (x % 64);\n            m_fen.operation(x / 64, -1);\n\
    \            m_all--;\n        }\n    }\n\n    bool contains(i32 x) const {\n\
    \        assert(static_cast<usize>(x) < maxValue());\n        return (m_dat[x\
    \ / 64] >> (x % 64)) & 1;\n    }\n\n    // 1-indexed\n    std::optional<usize>\
    \ kth(i32 k) const {\n        assert(k > 0);\n        if (static_cast<usize>(k)\
    \ > m_all) \n            return std::nullopt;\n        const usize idx = m_fen.maxRight(0,\
    \ [&](i32 v) { return v < k; });\n        i32 sum = m_fen.prefixProduct(idx);\n\
    \        assert(sum < k);\n        for (usize i = 0 ; i < 64 ; i++)\n        \
    \    if ((m_dat[idx] >> i) & 1) {\n                sum++;\n                if\
    \ (sum == k) \n                    return idx * 64 + i;\n            }\n     \
    \   assert(!\"Fenwick Set library bug\");\n        return std::nullopt;\n    }\n\
    \n    usize countLessEqual(i32 x) const {\n        if (x < 0) \n            return\
    \ 0;\n        if (static_cast<usize>(x) >= maxValue()) \n            return m_all;\n\
    \        usize sum = m_fen.prefixProduct(x / 64);\n        for (i32 i = 0 ; i\
    \ <= x % 64 ; i++) \n            sum += (m_dat[x / 64] >> i) & 1;\n        return\
    \ sum;\n    }\n\n    std::optional<usize> prevEqual(i32 x) const {\n        if\
    \ (countLessEqual(x) == 0) \n            return std::nullopt;\n        for (usize\
    \ i = x % 64 + 1 ; i-- ; ) \n            if ((m_dat[x / 64] >> i) & 1) \n    \
    \            return (x / 64) * 64 + i;\n        const usize idx = m_fen.minLeft(x\
    \ / 64, [](i32 v) { return v <= 0; });\n        for (usize i = 64 ; i-- ; ) \n\
    \            if ((m_dat[idx] >> i) & 1)\n                return idx * 64 + i;\n\
    \        assert(!\"Fenwick Set library bug\");\n        return std::nullopt;\n\
    \    }\n\n    std::optional<usize> nextEqual(i32 x) const {\n        if (m_all\
    \ == countLessEqual(x - 1))\n            return std::nullopt;\n        for (usize\
    \ i = x % 64 ; i < 64 ; i++)\n            if ((m_dat[x / 64] >> i) & 1)\n    \
    \            return (x / 64) * 64 + i;\n        const usize idx = m_fen.maxRight(x\
    \ / 64 + 1, [](i32 v) { return v <= 0; });\n        for (usize i = 0 ; i < 64\
    \ ; i++)\n            if ((m_dat[idx] >> i) & 1)\n                return idx *\
    \ 64 + i;\n        assert(!\"Fenwick Set library bug\");\n        return std::nullopt;\n\
    \    }\n\nprivate:\n\n    usize m_n{}, m_m{};\n    \n    std::vector<u64> m_dat;\n\
    \n    FenwickTree<AdditiveGroup<i32>> m_fen;\n\n    usize m_all{0};\n\n};\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include \"../../Template/TypeAlias.hpp\"\n#include \"../../Number/IntegerDivision.hpp\"\
    \n#include \"../FenwickTree/FenwickTree.hpp\"\n#include \"../../Algebra/Group/AdditiveGroup.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#include <vector>\n#include <optional>\n\
    \nnamespace zawa {\n\nclass FenwickSet {\npublic:\n\n    FenwickSet() = default;\n\
    \n    explicit FenwickSet(usize n) \n        : m_n{n}, m_m{DivCeil<usize>(n, 64)},\
    \ m_dat(m_m), m_fen(m_m), m_all{} {}\n\n    constexpr usize maxValue() const {\n\
    \        return m_n;\n    }\n\n    usize size() const {\n        return m_all;\n\
    \    }\n\n    void insert(i32 x) {\n        assert(0 <= x);\n        assert(static_cast<usize>(x)\
    \ < maxValue());\n        if ((m_dat[x / 64] >> (x % 64)) & 1) \n            return;\n\
    \        m_dat[x / 64] |= u64{1} << (x % 64);\n        m_fen.operation(x / 64,\
    \ 1);\n        m_all++;\n    }\n\n    void erase(i32 x) {\n        assert(static_cast<usize>(x)\
    \ < maxValue());\n        if ((m_dat[x / 64] >> (x % 64)) & 1) {\n           \
    \ m_dat[x / 64] ^= u64{1} << (x % 64);\n            m_fen.operation(x / 64, -1);\n\
    \            m_all--;\n        }\n    }\n\n    bool contains(i32 x) const {\n\
    \        assert(static_cast<usize>(x) < maxValue());\n        return (m_dat[x\
    \ / 64] >> (x % 64)) & 1;\n    }\n\n    // 1-indexed\n    std::optional<usize>\
    \ kth(i32 k) const {\n        assert(k > 0);\n        if (static_cast<usize>(k)\
    \ > m_all) \n            return std::nullopt;\n        const usize idx = m_fen.maxRight(0,\
    \ [&](i32 v) { return v < k; });\n        i32 sum = m_fen.prefixProduct(idx);\n\
    \        assert(sum < k);\n        for (usize i = 0 ; i < 64 ; i++)\n        \
    \    if ((m_dat[idx] >> i) & 1) {\n                sum++;\n                if\
    \ (sum == k) \n                    return idx * 64 + i;\n            }\n     \
    \   assert(!\"Fenwick Set library bug\");\n        return std::nullopt;\n    }\n\
    \n    usize countLessEqual(i32 x) const {\n        if (x < 0) \n            return\
    \ 0;\n        if (static_cast<usize>(x) >= maxValue()) \n            return m_all;\n\
    \        usize sum = m_fen.prefixProduct(x / 64);\n        for (i32 i = 0 ; i\
    \ <= x % 64 ; i++) \n            sum += (m_dat[x / 64] >> i) & 1;\n        return\
    \ sum;\n    }\n\n    std::optional<usize> prevEqual(i32 x) const {\n        if\
    \ (countLessEqual(x) == 0) \n            return std::nullopt;\n        for (usize\
    \ i = x % 64 + 1 ; i-- ; ) \n            if ((m_dat[x / 64] >> i) & 1) \n    \
    \            return (x / 64) * 64 + i;\n        const usize idx = m_fen.minLeft(x\
    \ / 64, [](i32 v) { return v <= 0; });\n        for (usize i = 64 ; i-- ; ) \n\
    \            if ((m_dat[idx] >> i) & 1)\n                return idx * 64 + i;\n\
    \        assert(!\"Fenwick Set library bug\");\n        return std::nullopt;\n\
    \    }\n\n    std::optional<usize> nextEqual(i32 x) const {\n        if (m_all\
    \ == countLessEqual(x - 1))\n            return std::nullopt;\n        for (usize\
    \ i = x % 64 ; i < 64 ; i++)\n            if ((m_dat[x / 64] >> i) & 1)\n    \
    \            return (x / 64) * 64 + i;\n        const usize idx = m_fen.maxRight(x\
    \ / 64 + 1, [](i32 v) { return v <= 0; });\n        for (usize i = 0 ; i < 64\
    \ ; i++)\n            if ((m_dat[idx] >> i) & 1)\n                return idx *\
    \ 64 + i;\n        assert(!\"Fenwick Set library bug\");\n        return std::nullopt;\n\
    \    }\n\nprivate:\n\n    usize m_n{}, m_m{};\n    \n    std::vector<u64> m_dat;\n\
    \n    FenwickTree<AdditiveGroup<i32>> m_fen;\n\n    usize m_all{0};\n\n};\n\n\
    } // namespace zawa\n"
  dependsOn:
  - Src/Template/TypeAlias.hpp
  - Src/Number/IntegerDivision.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: false
  path: Src/DataStructure/Set/FenwickSet.hpp
  requiredBy:
  - Src/DataStructure/Set/OfflineOrderedSet.hpp
  timestamp: '2025-10-14 12:56:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/ordered_set/OfflineOrderedSet.test.cpp
documentation_of: Src/DataStructure/Set/FenwickSet.hpp
layout: document
redirect_from:
- /library/Src/DataStructure/Set/FenwickSet.hpp
- /library/Src/DataStructure/Set/FenwickSet.hpp.html
title: Src/DataStructure/Set/FenwickSet.hpp
---
