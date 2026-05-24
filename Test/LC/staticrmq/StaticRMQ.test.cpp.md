---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RMQ/StaticRMQ.hpp
    title: Static RMQ
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/DisjointSparseTable.hpp
    title: Disjoint Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Test/LC/staticrmq/StaticRMQ.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"Src/DataStructure/RMQ/StaticRMQ.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 10 \"Src/DataStructure/SparseTable/DisjointSparseTable.hpp\"\
    \n#include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nclass\
    \ DisjointSparseTable {\npublic:\n\n    using V = typename M::Element;\n\n   \
    \ constexpr usize height(usize n) const {\n        return std::max(usize{1}, std::bit_width(n)\
    \ - (usize)std::has_single_bit(n));\n    }\n\n    constexpr usize msb(usize n)\
    \ const {\n        assert(n);\n        return std::bit_width(n) - 1;\n    }\n\n\
    \    DisjointSparseTable() = default;\n\n    template <class S>\n    requires\
    \ std::same_as<V, S> or concepts::Acted<M, S>\n    DisjointSparseTable(const std::vector<S>&\
    \ A) : m_table(height(A.size())) {\n        assert(A.size());\n        for (usize\
    \ i = 1, w = 2 ; i < m_table.size() ; i++, w <<= 1) {\n            m_table[i].resize(A.size());\n\
    \            for (usize j = 0, idx = 0 ; j < A.size() ; j += w, idx++) {\n   \
    \             V prod = M::identity();\n                if (idx & 1) { // ->\n\
    \                    usize m = std::min(A.size() - j, w);\n                  \
    \  for (usize k = 0 ; k < m ; k++) {\n                        if constexpr (std::same_as<V,\
    \ S>)\n                            prod = M::operation(prod, A[j + k]);\n    \
    \                    else\n                            prod = M::acted(prod, A[j\
    \ + k]);\n                        m_table[i][j + k] = prod;\n                \
    \    }\n                }\n                else { // <-\n                    usize\
    \ m = std::min(A.size(), j + w);\n                    for (usize k = m ; k-- >\
    \ j ; ) {\n                        if constexpr (std::same_as<V, S>)\n       \
    \                     prod = M::operation(A[k], prod);\n                     \
    \   else\n                            prod = M::acted(prod, A[k]);\n         \
    \               m_table[i][k] = prod;\n                    }\n               \
    \ }\n            }\n        }\n        m_table[0].resize(A.size());\n        for\
    \ (usize i = 0 ; i < A.size() ; i++) {\n            if constexpr (std::same_as<V,\
    \ S>)\n                m_table[0][i] = A[i];\n            else\n             \
    \   m_table[0][i] = M::acted(M::identity(), A[i]);\n        }\n    }\n\n    template\
    \ <std::input_iterator It>\n    DisjointSparseTable(It first, It last) : DisjointSparseTable(std::vector(first,\
    \ last)) {}\n\n    V product(usize l, usize r) const {\n        assert(l <= r\
    \ and r <= m_table[0].size());\n        if (l == r) return M::identity();\n  \
    \      if (l + 1 == r) return m_table[0][l];\n        usize y = msb(l xor --r);\n\
    \        return M::operation(m_table[y][l], m_table[y][r]);\n    }\n\nprivate:\n\
    \n    std::vector<std::vector<V>> m_table;\n};\n\n} // namespace zawa\n#line 5\
    \ \"Src/DataStructure/RMQ/StaticRMQ.hpp\"\n\n#line 8 \"Src/DataStructure/RMQ/StaticRMQ.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nclass StaticRMQ {\nprivate:\n\
    \n    static constexpr usize B = 16;\n\n    static constexpr usize LOG = 4;\n\n\
    \    static constexpr usize MASK = 15;\n\n    using T = typename M::Element;\n\
    \npublic:\n\n    StaticRMQ() = default;\n\n    StaticRMQ(std::vector<T> A) : m_n{A.size()},\
    \ m_inner{(m_n+B-1)>>LOG}, m_pref(m_n), m_suf(m_n), m_a(std::move(A)), m_spt()\
    \ {\n        std::vector<T> buc;\n        buc.reserve(innerSize());\n        for\
    \ (usize i = 0 ; i < size() ; ) {\n            m_pref[i] = m_a[i];\n         \
    \   while (++i < size() and i & MASK)\n                m_pref[i] = M::operation(m_pref[i-1],m_a[i]);\n\
    \            buc.push_back(m_pref[i-1]);\n        }\n        for (usize i = size()\
    \ ; i ; ) {\n            i--;\n            m_suf[i] = m_a[i];\n            for\
    \ ( ; i & MASK ; i--)\n                m_suf[i-1] = M::operation(m_a[i-1],m_suf[i]);\n\
    \        }\n        m_spt = DisjointSparseTable<M>(std::move(buc));\n    }\n\n\
    \    inline usize size() const noexcept {\n        return m_n;\n    }\n\n    T\
    \ product(usize L,usize R) const {\n        assert(L <= R and R <= size());\n\
    \        if (L == R)\n            return M::identity();\n        const usize l\
    \ = L >> LOG, r = (R-1) >> LOG;\n        if (l == r) {\n            T res = M::identity();\n\
    \            while (L < R)\n                res = M::operation(res,m_a[L++]);\n\
    \            return res;\n        }\n        else\n            return M::operation(M::operation(m_suf[L],m_spt.product(l+1,r)),m_pref[R-1]);\n\
    \    }\n\n    const T& operator[](usize i) const {\n        assert(i < size());\n\
    \        return m_a[i];\n    }\n\nprivate:\n\n    usize m_n, m_inner;\n\n    std::vector<T>\
    \ m_pref,m_suf,m_a;\n\n    DisjointSparseTable<M> m_spt;\n\n    inline usize innerSize()\
    \ const noexcept {\n        return m_inner;\n    }\n};\n\n} // namespace zawa\n\
    #line 3 \"Test/LC/staticrmq/StaticRMQ.test.cpp\"\n#include <iostream>\n#line 5\
    \ \"Test/LC/staticrmq/StaticRMQ.test.cpp\"\nusing namespace std;\nstruct M {\n\
    \    using Element = int;\n    static Element identity() {\n        return (int)1e9;\n\
    \    }\n    static Element operation(Element l, Element r) {\n        return std::min(l,\
    \ r);\n    }\n};\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto& x : A)\n\
    \        cin >> x;\n    zawa::StaticRMQ<M> rmq{std::move(A)};    \n    while (Q--)\
    \ {\n        int l,r;\n        cin >> l >> r;\n        cout << rmq.product(l,r)\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../../Src/DataStructure/RMQ/StaticRMQ.hpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\nstruct M {\n    using Element = int;\n    static\
    \ Element identity() {\n        return (int)1e9;\n    }\n    static Element operation(Element\
    \ l, Element r) {\n        return std::min(l, r);\n    }\n};\nint main() {\n \
    \   cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n\
    \    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto& x : A)\n        cin\
    \ >> x;\n    zawa::StaticRMQ<M> rmq{std::move(A)};    \n    while (Q--) {\n  \
    \      int l,r;\n        cin >> l >> r;\n        cout << rmq.product(l,r) << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - Src/DataStructure/RMQ/StaticRMQ.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/DataStructure/SparseTable/DisjointSparseTable.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  isVerificationFile: true
  path: Test/LC/staticrmq/StaticRMQ.test.cpp
  requiredBy: []
  timestamp: '2026-05-24 17:12:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/staticrmq/StaticRMQ.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/staticrmq/StaticRMQ.test.cpp
- /verify/Test/LC/staticrmq/StaticRMQ.test.cpp.html
title: Test/LC/staticrmq/StaticRMQ.test.cpp
---
