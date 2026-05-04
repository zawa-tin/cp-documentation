---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Group/AdditiveGroup.hpp
    title: "\u52A0\u6CD5\u7FA4"
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp
    title: Persistent Segment Tree
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
    - https://atcoder.jp/contests/abc453/submissions/75029259
    - https://atcoder.jp/contests/abc453/tasks/abc453_g
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/abc453_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc453/tasks/abc453_g\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 453 G - Copy Query\n * https://atcoder.jp/contests/abc453/submissions/75029259\n\
    \ */\n\n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\n\
    template <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n \
    \   static constexpr T identity() noexcept {\n        return T{};\n    }\n   \
    \ static constexpr T operation(T l,T r) noexcept {\n        return l + r;\n  \
    \  }\n    static constexpr T inverse(T v) noexcept {\n        return -v;\n   \
    \ }\n    template <class U>\n    static constexpr T power(T v,U exp) noexcept\
    \ {\n        return v * static_cast<T>(exp);\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp\"\n\n#line 2\
    \ \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\n\
    namespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\n#include <concepts>\n\
    \nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup\
    \ = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 9 \"Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp\"\
    \n#include <deque>\n#include <numeric>\n#include <vector>\n\nnamespace zawa {\n\
    \ntemplate <concepts::Monoid M>\nclass PersistentSegmentTree {\npublic:\n\n  \
    \  using V = typename M::Element;\n\n    struct Node {\n\n        V value = M::identity();\n\
    \n        Node* left = nullptr;\n\n        Node* right = nullptr;\n\n        Node()\
    \ = default;\n\n        explicit Node(V v) : value{std::move(v)} {}\n\n      \
    \  Node(V v,Node* l,Node* r) : value{std::move(v)},left{l},right{r} {}\n    };\n\
    \n    PersistentSegmentTree() = default;\n\n    explicit PersistentSegmentTree(std::vector<V>\
    \ a) : m_n{a.size()}, m_m{std::bit_ceil(a.size())}, m_dat{} {\n        // m_pool.reserve(2*innerSize());\n\
    \        construct(std::move(a));\n    }\n\n    explicit PersistentSegmentTree(usize\
    \ n) : m_n{n}, m_m{std::bit_ceil(n)}, m_dat{} {\n        // m_pool.reserve(2*innerSize());\n\
    \        construct(std::vector(m_n,M::identity()));\n    }\n\n    inline usize\
    \ size() const {\n        return m_n;\n    }\n\n    inline usize versionSize()\
    \ const {\n        return m_dat.size();\n    }\n\n    V get(usize ver,usize i)\
    \ const {\n        assert(ver < versionSize());\n        assert(i < size());\n\
    \        return get(m_dat[ver],i,0u,innerSize());\n    }\n\n    V get(usize i)\
    \ const {\n        assert(m_dat.size());\n        return get(m_dat.back(),i,0u,innerSize());\n\
    \    }\n\n    V product(usize ver,usize l,usize r) const {\n        assert(ver\
    \ < versionSize());\n        assert(l <= r and r <= size());\n        return product(m_dat[ver],l,r,0u,innerSize());\n\
    \    }\n\n    V product(usize l,usize r) const {\n        assert(m_dat.size());\n\
    \        return product(m_dat.back(),l,r,0u,innerSize());\n    }\n\n    usize\
    \ assign(usize ver,usize i,V v) {\n        assert(ver < versionSize());\n    \
    \    assert(i < size());\n        const usize res = m_dat.size();\n        m_dat.push_back(assign(m_dat[ver],i,std::move(v),0u,innerSize()));\n\
    \        return res;\n    }\n\n    usize assign(usize i,V v) {\n        return\
    \ assign(m_dat.size()-1,i,std::move(v));\n    }\n\n    usize operation(usize ver,usize\
    \ i,V v) {\n        assert(ver < versionSize());\n        assert(i < size());\n\
    \        const usize res = m_dat.size();\n        m_dat.push_back(operation(m_dat[ver],i,std::move(v),0u,innerSize()));\n\
    \        return res;\n    }\n\n    usize operation(usize i,V v) {\n        return\
    \ operation(m_dat.size()-1,i,std::move(v));\n    }\n\n    Node* access(usize ver)\
    \ const {\n        assert(ver < versionSize());\n        return m_dat[ver];\n\
    \    }\n\n    usize construct(std::vector<V> a) {\n        assert(a.size() ==\
    \ size());\n        a.resize(innerSize(),M::identity());\n        auto rec = [&](auto\
    \ rec,usize l,usize r) -> Node* {\n            if (l + 1 == r)\n             \
    \   return makeNode(a[l]);\n            const usize m = std::midpoint(l,r); \n\
    \            return merge(rec(rec,l,m),rec(rec,m,r));\n        };\n        const\
    \ usize res = m_dat.size();\n        m_dat.push_back(rec(rec,0u,innerSize()));\n\
    \        return res;\n    }\n\n    usize copy(usize from,usize to,usize l,usize\
    \ r) {\n        assert(from < versionSize());\n        assert(to < versionSize());\n\
    \        assert(l <= r and r <= size());\n        const usize res = m_dat.size();\n\
    \        m_dat.push_back(copy(m_dat[from],m_dat[to],l,r,0u,innerSize()));\n  \
    \      return res;\n    }\n\nprivate:\n\n    usize m_n, m_m;\n\n    std::vector<Node*>\
    \ m_dat;\n\n    std::deque<Node> m_pool;\n\n    inline usize innerSize() const\
    \ {\n        return m_m;\n    }\n\n    inline Node* makeNode(V v) {\n        m_pool.emplace_back(std::move(v));\n\
    \        return &m_pool.back();\n    }\n\n    inline Node* merge(Node* l,Node*\
    \ r) {\n        m_pool.emplace_back(M::operation(l->value,r->value),l,r);\n  \
    \      return &m_pool.back();\n    }\n\n    V get(const Node* node,usize i,usize\
    \ l,usize r) const {\n        if (l + 1 == r)\n            return node->value;\n\
    \        const usize m = std::midpoint(l,r);\n        if (i < m)\n           \
    \ return get(node->left,i,l,m);\n        else\n            return get(node->right,i,m,r);\n\
    \    }\n\n    V product(const Node* node,usize l,usize r,usize nl,usize nr) const\
    \ {\n        if (nr <= l or r <= nl)\n            return M::identity();\n    \
    \    if (l <= nl and nr <= r)\n            return node->value;\n        const\
    \ usize m = std::midpoint(nl,nr);\n        return M::operation(product(node->left,l,r,nl,m),product(node->right,l,r,m,nr));\n\
    \    }\n\n    Node* assign(const Node* node,usize i,V v,usize l,usize r) {\n \
    \       if (l + 1 == r)\n            return makeNode(std::move(v));\n        const\
    \ usize m = std::midpoint(l,r);\n        if (i < m)\n            return merge(assign(node->left,i,std::move(v),l,m),node->right);\n\
    \        else\n            return merge(node->left,assign(node->right,i,std::move(v),m,r));\n\
    \    }\n\n    Node* operation(const Node* node,usize i,V v,usize l,usize r) {\n\
    \        if (l + 1 == r)\n            return makeNode(M::operation(node->value,std::move(v)));\n\
    \        const usize m = std::midpoint(l,r);\n        if (i < m)\n           \
    \ return merge(operation(node->left,i,std::move(v),l,m),node->right);\n      \
    \  else\n            return merge(node->left,operation(node->right,i,std::move(v),m,r));\n\
    \    }\n\n    Node* copy(Node* from,Node* to,usize l,usize r,usize nl,usize nr)\
    \ {\n        if (nr <= l or r <= nl)\n            return to;\n        if (l <=\
    \ nl and nr <= r)\n            return from;\n        const usize m = std::midpoint(nl,nr);\n\
    \        return merge(copy(from->left,to->left,l,r,nl,m),copy(from->right,to->right,l,r,m,nr));\n\
    \    }\n};\n\n\n} // namespace zawa\n#line 11 \"Test/AtCoder/abc453_g.test.cpp\"\
    \n\n#include <iostream>\n#line 14 \"Test/AtCoder/abc453_g.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n  \
    \  ios::sync_with_stdio(0);\n    int N,M,Q;\n    cin >> N >> M >> Q;\n    vector<int>\
    \ P(N);\n    zawa::PersistentSegmentTree<zawa::AdditiveGroup<long long>> seg(M);\n\
    \    while (Q--) {\n        int T;\n        cin >> T;\n        if (T == 1) {\n\
    \            int x,y;\n            cin >> x >> y;\n            P[--x] = P[--y];\n\
    \        }\n        else if (T == 2) {\n            int x,y,z;\n            cin\
    \ >> x >> y >> z;\n            x--; y--;\n            P[x] = seg.assign(P[x],y,z);\n\
    \        }\n        else if (T == 3) {\n            int x,l,r;\n            cin\
    \ >> x >> l >> r;\n            x--; l--;\n            cout << seg.product(P[x],l,r)\
    \ << '\\n';\n        }\n        else\n            assert(0);\n    }\n#else\n \
    \   cout << \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc453/tasks/abc453_g\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Beginner Contest 453 G - Copy Query\n * https://atcoder.jp/contests/abc453/submissions/75029259\n\
    \ */\n\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main()\
    \ {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N,M,Q;\n    cin >> N >> M >> Q;\n    vector<int> P(N);\n    zawa::PersistentSegmentTree<zawa::AdditiveGroup<long\
    \ long>> seg(M);\n    while (Q--) {\n        int T;\n        cin >> T;\n     \
    \   if (T == 1) {\n            int x,y;\n            cin >> x >> y;\n        \
    \    P[--x] = P[--y];\n        }\n        else if (T == 2) {\n            int\
    \ x,y,z;\n            cin >> x >> y >> z;\n            x--; y--;\n           \
    \ P[x] = seg.assign(P[x],y,z);\n        }\n        else if (T == 3) {\n      \
    \      int x,l,r;\n            cin >> x >> l >> r;\n            x--; l--;\n  \
    \          cout << seg.product(P[x],l,r) << '\\n';\n        }\n        else\n\
    \            assert(0);\n    }\n#else\n    cout << \"Hello World\\n\";\n#endif\n\
    }\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc453_g.test.cpp
  requiredBy: []
  timestamp: '2026-05-04 13:04:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc453_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc453_g.test.cpp
- /verify/Test/AtCoder/abc453_g.test.cpp.html
title: Test/AtCoder/abc453_g.test.cpp
---
