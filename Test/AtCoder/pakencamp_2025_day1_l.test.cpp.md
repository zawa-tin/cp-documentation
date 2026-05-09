---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Action/ActionConcept.hpp
    title: Src/Algebra/Action/ActionConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidAction.hpp
    title: Src/Algebra/Monoid/MonoidAction.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/DualSegmentTree.hpp
    title: "Dual Segment Tree (\u975E\u53EF\u63DB\u5BFE\u5FDC)"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/pakencamp-2025-day1/submissions/75681053
    - https://atcoder.jp/contests/pakencamp-2025-day1/tasks/pakencamp_2025_day1_l
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/pakencamp_2025_day1_l.test.cpp\"\n// #define\
    \ PROBLEM \"https://atcoder.jp/contests/pakencamp-2025-day1/tasks/pakencamp_2025_day1_l\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * \u30D1\u7814\
    \u5408\u5BBF2025 \u7B2C1\u65E5\u300CSpeedRun\u300D L- Typical Addition Problem\n\
    \ * https://atcoder.jp/contests/pakencamp-2025-day1/submissions/75681053\n */\n\
    \n#line 2 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n\n#line 2 \"\
    Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64 =\
    \ std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16\
    \ = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\n\
    using usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Action/ActionConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Action/ActionConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class G, class X>\nconcept Action = requires {\n   \
    \ typename G::Element;\n    { G::action(std::declval<typename G::Element>(), std::declval<X>())\
    \ } -> std::same_as<X>;\n};\n\n// Is appropriate name X-set?\ntemplate <class\
    \ G, class X>\nconcept Acted = requires {\n    typename G::Element;\n    { G::acted(std::declval<typename\
    \ G::Element>(), std::declval<X>()) } -> std::same_as<typename G::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 6 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 10 \"Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\
    \n#include <vector>\n\nnamespace zawa {\n\ntemplate <class M,class T,bool Commutative\
    \ = false>\nrequires concepts::Monoid<M> and concepts::Action<M,T>\nclass DualSegmentTree\
    \ {\npublic:\n\n    using O = M::Element;\n\n    DualSegmentTree() = default;\n\
    \n    explicit DualSegmentTree(usize n) : m_n{n}, m_a(n), m_seg(n<<1,M::identity())\
    \ {}\n\n    explicit DualSegmentTree(usize n,T init) : m_n{n}, m_a(n,init), m_seg(n<<1,M::identity())\
    \ {}\n\n    explicit DualSegmentTree(std::vector<T> a) : m_n{a.size()}, m_a{std::move(a)},\
    \ m_seg(m_n<<1,M::identity()) {}\n\n    inline usize size() const {\n        return\
    \ m_n;\n    }\n\n    void operation(usize l,usize r,O o) {\n        assert(l <=\
    \ r and r <= size());\n        if constexpr (!Commutative) {\n            push(l);\n\
    \            if (l < r)\n                push(r-1);\n        }\n        for (l\
    \ += size(), r += size() ; l < r ; l >>= 1, r >>= 1) {\n            if (l & 1)\
    \ {\n                m_seg[l] = M::operation(m_seg[l],o);\n                l++;\n\
    \            }\n            if (r & 1) {\n                r--;\n             \
    \   m_seg[r] = M::operation(m_seg[r],o);\n            }\n        }\n    }\n\n\
    \    void operation(usize i,O o) {\n        assert(i < size());\n        if constexpr\
    \ (!Commutative)\n            push(i);\n        m_seg[i+size()] = std::move(o);\n\
    \    }\n\n    T get(usize i) const {\n        assert(i < size());\n        O prod\
    \ = M::identity();\n        for (usize v = i+size() ; v ; v >>= 1)\n         \
    \   prod = M::operation(prod,m_seg[v]);\n        return M::action(prod,m_a[i]);\n\
    \    }\n\n    T operator[](usize i) const {\n        assert(i < size());\n   \
    \     return get(i);\n    }\n\n    void assignOperator(usize i,O o) {\n      \
    \  assert(i < size());\n        push(i);\n        m_seg[i+size()] = std::move(o);\n\
    \    }\n\n    void assign(usize i,T x) {\n        assert(i < size());\n      \
    \  assignOperator(i,M::identity());\n        m_a[i] = std::move(x);\n    }\n\n\
    \    std::vector<T> container() const {\n        std::vector<T> res(size());\n\
    \        for (usize i = 0 ; i < size() ; i++)\n            res[i] = get(i);\n\
    \        return res;\n    }\n\nprivate:\n\n    void push(usize i) {\n        assert(i\
    \ < size());\n        i += size();\n        for (usize j = std::bit_width(i) ;\
    \ --j ; ) {\n            usize v = i >> j;\n            m_seg[v<<1|0] = M::operation(m_seg[v<<1|0],m_seg[v]);\n\
    \            m_seg[v<<1|1] = M::operation(m_seg[v<<1|1],m_seg[v]);\n         \
    \   m_seg[v] = M::identity();\n        }\n    }\n\n    usize m_n;\n\n    std::vector<T>\
    \ m_a;\n\n    std::vector<O> m_seg;\n};\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass AdditiveGroup {\npublic:\n \
    \   using Element = T;\n    static constexpr T identity() noexcept {\n       \
    \ return T{};\n    }\n    static constexpr T operation(T l,T r) noexcept {\n \
    \       return l + r;\n    }\n    static constexpr T inverse(T v) noexcept {\n\
    \        return -v;\n    }\n    template <class U>\n    static constexpr T power(T\
    \ v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n    }\n};\n\n\
    } // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidAction.hpp\"\n\n#line\
    \ 4 \"Src/Algebra/Monoid/MonoidAction.hpp\"\n\nnamespace zawa {\n\ntemplate <concepts::Monoid\
    \ M>\nstruct AddSelfAction : public M {\n    // b <- f(b,a)\n    static M::Element\
    \ action(M::Element a, M::Element b) {\n        return M::operation(b,a);\n  \
    \  }\n    // a <- f(a,b)\n    static M::Element acted(M::Element a, M::Element\
    \ b) {\n        return M::operation(a, b);\n    }\n};\n\n} // namespace zawa\n\
    #line 12 \"Test/AtCoder/pakencamp_2025_day1_l.test.cpp\"\nusing namespace zawa;\n\
    \n#line 15 \"Test/AtCoder/pakencamp_2025_day1_l.test.cpp\"\n#include <iostream>\n\
    #line 17 \"Test/AtCoder/pakencamp_2025_day1_l.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,Q;\n    cin >> N >> Q;\n    vector<long long> A(N),B(N);\n    for (auto&\
    \ x : A)\n        cin >> x;\n    for (auto& x : B)\n         cin >> x;\n    DualSegmentTree<AddSelfAction<AdditiveGroup<long\
    \ long>>,long long,true> seg(N);\n    while (Q--) {\n        int T;\n        cin\
    \ >> T;\n        if (T == 1) {\n            int p,x;\n            cin >> p >>\
    \ x;\n            p--;\n            A[p] += seg[p]*B[p];\n            seg.assignOperator(p,0);\n\
    \            B[p] = x;\n        }\n        else if (T == 2) {\n            int\
    \ l,r;\n            cin >> l >> r;\n            seg.operation(--l,r,1);\n    \
    \    }\n        else if (T == 3) {\n            int p;\n            cin >> p;\n\
    \            p--;\n            A[p] += seg[p]*B[p];\n            seg.assignOperator(p,0);\n\
    \            cout << A[p] << '\\n';\n        }\n        else\n            assert(0);\n\
    \    }\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n\
    }\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/pakencamp-2025-day1/tasks/pakencamp_2025_day1_l\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n/*\n * \u30D1\u7814\
    \u5408\u5BBF2025 \u7B2C1\u65E5\u300CSpeedRun\u300D L- Typical Addition Problem\n\
    \ * https://atcoder.jp/contests/pakencamp-2025-day1/submissions/75681053\n */\n\
    \n#include \"../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp\"\n#include\
    \ \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/Algebra/Monoid/MonoidAction.hpp\"\
    \nusing namespace zawa;\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int N,Q;\n    cin >> N >> Q;\n    vector<long\
    \ long> A(N),B(N);\n    for (auto& x : A)\n        cin >> x;\n    for (auto& x\
    \ : B)\n         cin >> x;\n    DualSegmentTree<AddSelfAction<AdditiveGroup<long\
    \ long>>,long long,true> seg(N);\n    while (Q--) {\n        int T;\n        cin\
    \ >> T;\n        if (T == 1) {\n            int p,x;\n            cin >> p >>\
    \ x;\n            p--;\n            A[p] += seg[p]*B[p];\n            seg.assignOperator(p,0);\n\
    \            B[p] = x;\n        }\n        else if (T == 2) {\n            int\
    \ l,r;\n            cin >> l >> r;\n            seg.operation(--l,r,1);\n    \
    \    }\n        else if (T == 3) {\n            int p;\n            cin >> p;\n\
    \            p--;\n            A[p] += seg[p]*B[p];\n            seg.assignOperator(p,0);\n\
    \            cout << A[p] << '\\n';\n        }\n        else\n            assert(0);\n\
    \    }\n#else\n    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n\
    }\n"
  dependsOn:
  - Src/DataStructure/SegmentTree/DualSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Action/ActionConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Algebra/Monoid/MonoidAction.hpp
  isVerificationFile: true
  path: Test/AtCoder/pakencamp_2025_day1_l.test.cpp
  requiredBy: []
  timestamp: '2026-05-10 03:33:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/pakencamp_2025_day1_l.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/pakencamp_2025_day1_l.test.cpp
- /verify/Test/AtCoder/pakencamp_2025_day1_l.test.cpp.html
title: Test/AtCoder/pakencamp_2025_day1_l.test.cpp
---
