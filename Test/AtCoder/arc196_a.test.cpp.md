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
    path: Src/DataStructure/Other/PriorityProductSet.hpp
    title: "\u6607\u9806 $K$ \u500B\u306E\u548C\u3092\u53D6\u308C\u308Bpriority_queue"
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
    - https://atcoder.jp/contests/arc196/submissions/64618439
    - https://atcoder.jp/contests/arc196/tasks/arc196_a
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/arc196_a.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc196/tasks/arc196_a\"\n\n\
    /*\n * AtCoder Regular Contest 196 (Div. 1) A - Adjacent Delete\n * https://atcoder.jp/contests/arc196/submissions/64618439\n\
    \ */\n\n#line 2 \"Src/DataStructure/Other/PriorityProductSet.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/Other/PriorityProductSet.hpp\"\
    \n\n#include <cassert>\n#include <optional>\n#include <utility>\n#include <queue>\n\
    \nnamespace zawa {\n\n// 1-indexed\ntemplate <concepts::Group G>\nclass PriorityProductSet\
    \ {\npublic:\n\n    using V = G::Element;\n\n    PriorityProductSet() = default;\n\
    \n    PriorityProductSet(usize K) : m_K{K} {}\n\n    void insert(V&& v) {\n  \
    \      pushSmall(std::move(v));\n        adjust();\n    }\n\n    void insert(const\
    \ V& v) {\n        insert(V{v});\n    }\n\n    usize size() const {\n        return\
    \ m_small.size() + m_big.size();\n    }\n\n    inline usize K() const {\n    \
    \    return m_K;\n    }\n\n    void setK(usize K) {\n        m_K = K;\n      \
    \  adjust();\n    }\n\n    std::optional<V> product() const {\n        return\
    \ m_small.size() == m_K ? std::optional<V>{m_sv} : std::nullopt;\n    }\n\n  \
    \  std::optional<V> productRemain() const {\n        return m_small.size() ==\
    \ m_K ? std::optional<V>{m_bv} : std::nullopt;\n    }\n\n    V productAll() const\
    \ {\n        return G::operation(m_sv, m_bv);\n    }\n\n    V popK() {\n     \
    \   assert(m_K >= 1u and size() >= m_K);\n        V res = popSmall(); \n     \
    \   adjust();\n        return res;\n    }\n\nprivate:\n\n    std::priority_queue<V>\
    \ m_small;\n\n    std::priority_queue<V, std::vector<V>, std::greater<V>> m_big;\n\
    \n    V m_sv = G::identity(), m_bv = G::identity();\n\n    usize m_K = 0;\n\n\
    \    void pushSmall(V&& v) {\n        m_sv = G::operation(m_sv, v);\n        m_small.push(std::move(v));\n\
    \    }\n\n    V popSmall() {\n        assert(m_small.size());\n        V res =\
    \ m_small.top();\n        m_small.pop();\n        m_sv = G::operation(m_sv, G::inverse(res));\n\
    \        return res;\n    }\n\n    void pushBig(V&& v) {\n        m_bv = G::operation(m_bv,\
    \ v);\n        m_big.push(std::move(v));\n    }\n\n    V popBig() {\n        assert(m_big.size());\n\
    \        V res = m_big.top();\n        m_big.pop();\n        m_bv = G::operation(m_bv,\
    \ G::inverse(res));\n        return res;\n    }\n\n    void adjust() {\n     \
    \   while (m_small.size() > m_K) pushBig(popSmall());\n        while (m_small.size()\
    \ < m_K and m_big.size()) pushSmall(popBig());\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(const T& l, const T& r) noexcept {\n        return l + r;\n    }\n\
    \    static constexpr T inverse(const T& v) noexcept {\n        return -v;\n \
    \   }\n};\n\n} // namespace zawa\n#line 11 \"Test/AtCoder/arc196_a.test.cpp\"\n\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\nusing namespace\
    \ zawa;\nint N, A[300030];\nlong long solve() {\n    std::vector<long long> pref(N\
    \ + 1);\n    {\n        PriorityProductSet<AdditiveGroup<long long>> set;\n  \
    \      for (int i = 0 ; i < N ; i += 2) {\n            set.setK(i/2);\n      \
    \      pref[i] = set.productRemain().value() - set.product().value();\n      \
    \      set.insert(A[i]);\n            if (i + 1 < N) set.insert(A[i + 1]);\n \
    \       }\n        if (N % 2 == 0) {\n            set.setK(N/2);\n           \
    \ pref[N] = set.productRemain().value() - set.product().value();\n           \
    \ return pref[N];\n        }\n    }\n    std::vector<long long> suf(N + 1);\n\
    \    {\n        PriorityProductSet<AdditiveGroup<long long>> set;\n        for\
    \ (int i = N ; i >= 0 ; i -= 2) {\n            set.setK((N-i)/2);\n          \
    \  suf[i] = set.productRemain().value() - set.product().value();\n           \
    \ if (i - 1 >= 0) set.insert(A[i - 1]);\n            if (i - 2 >= 0) set.insert(A[i\
    \ - 2]);\n        }\n    }\n    // for (auto p : pref) std::cout << p << ' ';\n\
    \    // std::cout << std::endl;\n    // for (auto p : suf) std::cout << p << '\
    \ ';\n    // std::cout << std::endl;\n    long long ans = 0;\n    for (int i =\
    \ 0 ; i < N ; i += 2) {\n        ans = std::max(ans, pref[i] + suf[i + 1]);\n\
    \    }\n    return ans;\n}\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cin\
    \ >> N;\n    for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n    std::cout <<\
    \ solve() << '\\n';\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc196/tasks/arc196_a\"\n\n\
    /*\n * AtCoder Regular Contest 196 (Div. 1) A - Adjacent Delete\n * https://atcoder.jp/contests/arc196/submissions/64618439\n\
    \ */\n\n#include \"../../Src/DataStructure/Other/PriorityProductSet.hpp\"\n#include\
    \ \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\nusing namespace zawa;\nint N, A[300030];\nlong\
    \ long solve() {\n    std::vector<long long> pref(N + 1);\n    {\n        PriorityProductSet<AdditiveGroup<long\
    \ long>> set;\n        for (int i = 0 ; i < N ; i += 2) {\n            set.setK(i/2);\n\
    \            pref[i] = set.productRemain().value() - set.product().value();\n\
    \            set.insert(A[i]);\n            if (i + 1 < N) set.insert(A[i + 1]);\n\
    \        }\n        if (N % 2 == 0) {\n            set.setK(N/2);\n          \
    \  pref[N] = set.productRemain().value() - set.product().value();\n          \
    \  return pref[N];\n        }\n    }\n    std::vector<long long> suf(N + 1);\n\
    \    {\n        PriorityProductSet<AdditiveGroup<long long>> set;\n        for\
    \ (int i = N ; i >= 0 ; i -= 2) {\n            set.setK((N-i)/2);\n          \
    \  suf[i] = set.productRemain().value() - set.product().value();\n           \
    \ if (i - 1 >= 0) set.insert(A[i - 1]);\n            if (i - 2 >= 0) set.insert(A[i\
    \ - 2]);\n        }\n    }\n    // for (auto p : pref) std::cout << p << ' ';\n\
    \    // std::cout << std::endl;\n    // for (auto p : suf) std::cout << p << '\
    \ ';\n    // std::cout << std::endl;\n    long long ans = 0;\n    for (int i =\
    \ 0 ; i < N ; i += 2) {\n        ans = std::max(ans, pref[i] + suf[i + 1]);\n\
    \    }\n    return ans;\n}\nint main() {\n#ifdef ATCODER\n    std::cin.tie(nullptr);\n\
    \    std::cout.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cin\
    \ >> N;\n    for (int i = 0 ; i < N ; i++) std::cin >> A[i];\n    std::cout <<\
    \ solve() << '\\n';\n#else\n    std::cout << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/DataStructure/Other/PriorityProductSet.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc196_a.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 19:44:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc196_a.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc196_a.test.cpp
- /verify/Test/AtCoder/arc196_a.test.cpp.html
title: Test/AtCoder/arc196_a.test.cpp
---
