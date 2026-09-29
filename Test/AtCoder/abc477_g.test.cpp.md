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
    path: Src/DataStructure/Bucket/BucketRangeProduct.hpp
    title: "\u30D0\u30B1\u30C3\u30C8\u5206\u5272\u306B\u3088\u308B\u533A\u9593\u30AF\
      \u30A8\u30EA\u51E6\u7406"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RMQ/PM1RMQ.hpp
    title: Src/DataStructure/RMQ/PM1RMQ.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/MoonTree.hpp
    title: Src/Graph/Tree/MoonTree.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  - icon: ':heavy_check_mark:'
    path: Src/Utility/Mo.hpp
    title: Src/Utility/Mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc477/tasks/abc477_g
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"Test/AtCoder/abc477_g.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/abc477/tasks/abc477_g\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(T l,T r) noexcept {\n        return l + r;\n    }\n    static constexpr\
    \ T inverse(T v) noexcept {\n        return -v;\n    }\n    template <class U>\n\
    \    static constexpr T power(T v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n\
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/Bucket/BucketRangeProduct.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
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
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/Bucket/BucketRangeProduct.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <limits>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid M>\nclass\
    \ BucketRangeQuery {\npublic:\n\n    using V = typename M::Element;\n\n    inline\
    \ usize size() const {\n        return m_n;\n    }\n\n    inline usize bucketSize()\
    \ const {\n        return m_b;\n    }\n\n    BucketRangeQuery() = default;\n\n\
    \    BucketRangeQuery(usize N,usize B = std::numeric_limits<usize>::max()) \n\
    \        : m_n{N},m_b{BucketSize(N,B)}, m_data(N,M::identity()), m_bucket((m_n+m_b-1)/m_b,M::identity())\
    \ {\n        for (usize i = 0 ; i < size() ; i++)\n            m_bucket[i/bucketSize()]\
    \ = M::operation(m_bucket[i/bucketSize()],m_data[i]);\n    }\n\n    BucketRangeQuery(std::vector<V>\
    \ A,usize B = std::numeric_limits<usize>::max())\n        : m_n{A.size()},m_b{BucketSize(A.size(),B)},m_data(std::move(A)),m_bucket((m_n+m_b-1)/m_b,M::identity())\
    \ {\n        for (usize i = 0 ; i < size() ; i++)\n            m_bucket[i/bucketSize()]\
    \ = M::operation(m_bucket[i/bucketSize()],m_data[i]);\n    }\n\n    V product(usize\
    \ l,usize r) const {\n        assert(l <= r and r <= size());\n        V res =\
    \ M::identity();\n        while (l < r and l % bucketSize())\n            res\
    \ = M::operation(res,m_data[l++]);\n        while (l + bucketSize() <= r) {\n\
    \            res = M::operation(res,m_bucket[l/bucketSize()]);\n            l\
    \ += bucketSize();\n        }\n        while (l < r)\n            res = M::operation(res,m_data[l++]);\n\
    \        return res;\n    }\n\n    V operator[](usize i) const {\n        assert(i\
    \ < size());\n        return m_data[i];\n    }\n\n    V bucketValue(usize i) const\
    \ {\n        assert(i < m_bucket.size());\n        return m_bucket[i];\n    }\n\
    \n    void assign(usize i,V x) {\n        assert(i < size());\n        const usize\
    \ idx = i/bucketSize();\n        if constexpr (concepts::Group<M>) {\n       \
    \     m_bucket[idx] = M::operation(m_bucket[idx],M::inverse(m_data[i]));\n   \
    \         m_data[i] = std::move(x);\n            m_bucket[idx] = M::operation(m_bucket[idx],m_data[i]);\n\
    \        }\n        else {\n            m_data[i] = std::move(x);\n          \
    \  m_bucket[idx] = M::identity();\n            const usize l = idx*bucketSize(),r\
    \ = std::min(size(),(idx+1)*bucketSize());\n            for (usize j = l ; j <\
    \ r ; j++)\n                m_bucket[idx] = M::operation(m_bucket[idx],m_data[j]);\n\
    \        }\n    }\n\n    void operation(usize i,V x) {\n        assert(i < size());\n\
    \        m_bucket[i/bucketSize()] = M::operation(m_bucket[i/bucketSize()],x);\n\
    \        m_data[i] = M::operation(m_data[i],x);\n    }\n\n    template <class\
    \ F>\n    requires std::predicate<F,V>\n    usize maxRight(usize i,F f) const\
    \ {\n        assert(i <= size());\n        assert(f(M::identity()));\n       \
    \ V pd = M::identity();\n        while (i < size() and i % bucketSize()) {\n \
    \           V nxt = M::operation(pd,m_data[i]);\n            if (!f(nxt))\n  \
    \              return i;\n            pd = std::move(nxt);\n            i++;\n\
    \        }\n        while (i + bucketSize() <= size()) {\n            V nxt =\
    \ M::operation(pd,m_bucket[i/bucketSize()]);\n            if (!f(nxt))\n     \
    \           break;\n            pd = std::move(nxt);\n            i += bucketSize();\n\
    \        }\n        while (i < size()) {\n            V nxt = M::operation(pd,m_data[i]);\n\
    \            if (!f(nxt))\n                break;\n            pd = std::move(nxt);\n\
    \            i++;\n        }\n        return i;\n    }\n\n    template <class\
    \ F>\n    requires std::predicate<F,V>\n    usize minLeft(usize i,F f) const {\n\
    \        assert(i <= size());\n        assert(f(M::identity()));\n        V pd\
    \ = M::identity();\n        while (i % bucketSize()) {\n            V nxt = M::operation(m_data[i-1],pd);\n\
    \            if (!f(nxt))\n                return i;\n            pd = std::move(nxt);\n\
    \            i--;\n        }\n        while (i) {\n            V nxt = M::operation(m_bucket[i/bucketSize()-1],pd);\n\
    \            if (!f(nxt))\n                break;\n            pd = std::move(nxt);\n\
    \            i -= bucketSize();\n        }\n        while (i) {\n            V\
    \ nxt = M::operation(m_data[i-1],pd);\n            if (!f(nxt))\n            \
    \    break;\n            pd = std::move(nxt);\n            i--;\n        }\n \
    \       return i;\n    }\n\nprivate:\n\n    usize m_n,m_b;\n\n    std::vector<V>\
    \ m_data,m_bucket;\n\n    static usize BucketSize(usize N,usize B) {\n       \
    \ return B == std::numeric_limits<usize>::max() ? std::max<usize>(1,sqrtl(N))\
    \ : B;\n    }\n};\n\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/MoonTree.hpp\"\
    \n\n#line 2 \"Src/Utility/Mo.hpp\"\n\n#line 4 \"Src/Utility/Mo.hpp\"\n\n#line\
    \ 8 \"Src/Utility/Mo.hpp\"\n#include <ranges>\n#include <utility>\n#include <numeric>\n\
    #line 13 \"Src/Utility/Mo.hpp\"\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T>\nstd::vector<usize> Mo(const std::vector<std::pair<T,T>>& P) {\n    if (P.empty())\n\
    \        return {};\n    T minY = std::numeric_limits<T>::max();\n    const u64\
    \ W = [&]() {\n        T minX = std::numeric_limits<T>::max();\n        T maxX\
    \ = std::numeric_limits<T>::min(), maxY = std::numeric_limits<T>::min();\n   \
    \     for (auto [x,y] : P) {\n            minX = std::min(minX,x);\n         \
    \   maxX = std::max(maxX,x);\n            minY = std::min(minY,y);\n         \
    \   maxY = std::max(maxY,y);\n        }\n        return std::max<u64>({1,u64(maxX-minX),u64(maxY-minY)});\n\
    \    }();\n    const usize B = [&]() {\n        u64 sq = std::max<u64>(1,sqrt(P.size()));\n\
    \        return (W + sq - 1) / sq;\n    }();\n    T sub = minY;\n    auto makeRank\
    \ = [&]() -> std::vector<std::pair<T,T>> {\n        std::vector<std::pair<T,T>>\
    \ res(P.size());\n        for (usize i = 0 ; i < P.size() ; i++) {\n         \
    \   res[i].first = (P[i].second - sub) / B;\n            res[i].second = (res[i].first\
    \ & 1 ? -1 : 1) * P[i].first;\n        }\n        return res;\n    };\n    std::vector<usize>\
    \ ord1(P.size()), ord2(P.size());\n    std::iota(ord1.begin(),ord1.end(),0);\n\
    \    std::iota(ord2.begin(),ord2.end(),0);\n    auto rank = makeRank();\n    std::ranges::sort(ord1,[&](usize\
    \ i, usize j) { return rank[i] < rank[j]; });\n    sub -= B / 2;\n    rank = makeRank();\n\
    \    std::ranges::sort(ord2,[&](usize i, usize j) { return rank[i] < rank[j];\
    \ });\n    auto cost = [&](const std::vector<usize>& ord) {\n        u64 res =\
    \ 0;\n        for (usize i = 0 ; i + 1 < ord.size() ; i++) {\n            res\
    \ += abs(P[ord[i+1]].first-P[ord[i]].first);\n            res += abs(P[ord[i+1]].second-P[ord[i]].second);\n\
    \        }\n        return res;\n    };\n    return cost(ord1) <= cost(ord2) ?\
    \ ord1 : ord2;\n}\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\n#line 2 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#line 4 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n\n#line 6 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n#include <array>\n#include <bit>\n\
    #line 12 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n\nnamespace zawa {\n\ntemplate\
    \ <std::totally_ordered T>\nclass PM1RMQ {\nprivate:\n\n    static constexpr usize\
    \ B = 8;\n\n    static constexpr usize BMASK = 7;\n\n    static constexpr usize\
    \ LOGB = 3;\n\n    static constexpr usize TRI = B*(B+1)/2;\n\npublic:\n\n    PM1RMQ()\
    \ = default;\n\n    PM1RMQ(std::vector<T> a) \n        : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},\n\
    \        m_a{std::move(a)}, m_look(innerSize()), m_table(), m_spt(std::bit_width(innerSize()))\n\
    \    {\n        std::vector<u32> minIndex(innerSize());\n        std::vector<bool>\
    \ registered(1u << (B-1));\n        for (usize i = 0,idx = 0 ; i < size() ; idx++)\
    \ {\n            minIndex[idx] = i;\n            for (u8 j = 1 ; ++i < size()\
    \ and j < (u8)B ; j++) {\n                if (m_a[i] < m_a[minIndex[idx]])\n \
    \                   minIndex[idx] = i;\n                if (m_a[i] == m_a[i-1]+1)\n\
    \                    ;\n                else if (m_a[i] == m_a[i-1]-1)\n     \
    \               m_look[idx] |= u8{1} << (j-1);\n                else\n       \
    \             assert(!\"init table does not satisfy |a_i-a_{i+1}| = 1\");\n  \
    \          }\n            if (!registered[m_look[idx]]) {\n                registered[m_look[idx]]\
    \ = 1;\n                registerTable(m_look[idx]);\n            }\n        }\n\
    \        m_spt[0] = std::move(minIndex);\n        for (usize i = 1,len = 2 ; i\
    \ < m_spt.size() ; i++,len <<= 1) {\n            m_spt[i].resize(innerSize()-len+1);\n\
    \            for (usize j = 0 ; j < m_spt[i].size() ; j++) {\n               \
    \ u32 l = m_spt[i-1][j], r = m_spt[i-1][j+(len>>1)];\n                m_spt[i][j]\
    \ = m_a[r] < m_a[l] ? r : l;\n            }\n        }\n    }\n\n    inline usize\
    \ size() const {\n        return m_n;\n    }\n\n    // return leftmost index of\
    \ min{a[l],a[l+1],...,a[r-1]} (min of argmin)\n    // empty is not allowed\n \
    \   usize min(usize l,usize r) const {\n        assert(l < r and r <= size());\n\
    \        usize L = l>>LOGB, R = (r-1)>>LOGB;\n        if (L == R)\n          \
    \  return accessTable(L,l&BMASK,r-(L<<LOGB));\n        u32 res = accessTable(L,l&BMASK,B);\n\
    \        L++;\n        if (L < R) {\n            u32 pd = sptMin(L,R);\n     \
    \       if (m_a[pd] < m_a[res])\n                res = pd;\n        }\n      \
    \  u32 rv = accessTable(R,0u,r-(R<<LOGB));\n        if (m_a[rv] < m_a[res])\n\
    \            res = rv;\n        return static_cast<usize>(res);\n    }\n\n   \
    \ usize operator()(usize l,usize r) const {\n        return min(l,r);\n    }\n\
    \nprivate:\n\n    usize m_n,m_inner;\n\n    std::vector<T> m_a;\n\n    // 0..+1,1..-1\n\
    \    std::vector<u8> m_look;\n\n    std::array<u8,(1u << (B-1))*TRI> m_table;\n\
    \n    std::vector<std::vector<u32>> m_spt;\n\n    inline usize innerSize() const\
    \ {\n        return m_inner;\n    }\n\n    usize encode(usize l,usize r) const\
    \ {\n        // assert(l < r and r <= B);\n        static constexpr std::array<uint32_t,8>\
    \ Row{0,8,15,21,26,30,33,35};\n        return Row[l]+(r-l-1);\n    }\n\n    void\
    \ registerTable(usize info) {\n        const usize offset = TRI*info;\n      \
    \  std::vector<usize> val(B);\n        val[0] = B;\n        for (usize i = 0 ;\
    \ i + 1 < B ; i++) {\n            val[i+1] = val[i];\n            if (info & (1u\
    \ << i))\n                val[i+1]--;\n            else\n                val[i+1]++;\n\
    \        }\n        for (u8 l = 0 ; l < B ; l++) {\n            u8 mn = l;\n \
    \           for (u8 r = l ; r < B ; r++) {\n                if (val[mn] > val[r])\n\
    \                    mn = r;\n                m_table[offset+encode(l,r+1)] =\
    \ mn;\n            }\n        }\n    }\n\n    usize accessTable(usize idx,usize\
    \ l,usize r) const {\n        return (idx<<LOGB) + m_table[m_look[idx]*TRI+encode(l,r)];\n\
    \    }\n\n    u32 sptMin(usize l,usize r) const {\n        usize dep = std::bit_width(r-l)-1,\
    \ i = m_spt[dep][l], j = m_spt[dep][r-(1u<<dep)];\n        return m_a[j] < m_a[i]\
    \ ? j : i;\n    }\n};\n\n} // namespace zawa\n#line 5 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\n#line 9 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\nnamespace zawa {\n\n\
    template <class V>\nclass LowestCommonAncestor {\npublic:\n\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const std::vector<std::vector<V>>& g,V\
    \ r = 0) \n        : m_n{g.size()}, m_inv{}, m_left(size()), m_right(size()),\
    \ m_dep(size())\n    {\n        std::vector<u32> ord;\n        ord.reserve(2*size());\n\
    \        m_inv.reserve(2*size());\n        auto dfs = [&](auto dfs,V v,V p,u32\
    \ d) -> void {\n            m_left[v] = ord.size();\n            ord.push_back(d);\n\
    \            m_inv.push_back(v);\n            m_dep[v] = d;\n            for (V\
    \ x : g[v])\n                if (x != p) {\n                    dfs(dfs,x,v,d+1);\n\
    \                    ord.push_back(d);\n                    m_inv.push_back(v);\n\
    \                }\n            m_right[v] = ord.size();\n        };\n       \
    \ dfs(dfs,r,static_cast<V>(-1),0);\n        m_rmq = PM1RMQ{std::move(ord)};\n\
    \    }\n\n    V lca(V u,V v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        if (u == v)\n            return u;\n        if (m_left[u] > m_left[v])\n\
    \            std::swap(u,v);\n        return m_inv[m_rmq.min(m_left[u],m_right[v])];\n\
    \    }\n\n    V operator()(V u,V v) const {\n        return lca(u,v);\n    }\n\
    \n    inline usize depth(V v) const {\n        assert(verify(v));\n        return\
    \ m_dep[v];\n    }\n\n    usize distance(V u,V v) const {\n        assert(verify(u));\n\
    \        assert(verify(v));\n        return m_dep[u] + m_dep[v] - 2*m_dep[lca(u,v)];\n\
    \    }\n\n    bool isAncestor(V p,V v) const {\n        assert(verify(p));\n \
    \       assert(verify(v));\n        return m_left[p] <= m_left[v] and m_right[v]\
    \ <= m_right[p];\n    }\n\n    std::pair<usize,usize> subtreeRange(V v) const\
    \ {\n        assert(verify(v));\n        return {m_left[v],m_right[v]};\n    }\n\
    \nprotected:\n\n    inline usize size() const {\n        return m_n;\n    }\n\n\
    \    inline bool verify(V v) const {\n        return static_cast<usize>(v) < size();\n\
    \    }\n\n    inline usize left(V v) const {\n        assert(verify(v));\n   \
    \     return m_left[v];\n    }\n\n    inline usize right(V v) const {\n      \
    \  assert(verify(v));\n        return m_right[v];\n    }\n\nprivate:\n\n    usize\
    \ m_n;\n    \n    std::vector<usize> m_inv,m_left,m_right,m_dep;\n\n    PM1RMQ<u32>\
    \ m_rmq;\n};\n\n} // namespace zawa\n#line 5 \"Src/Graph/Tree/MoonTree.hpp\"\n\
    \n#line 9 \"Src/Graph/Tree/MoonTree.hpp\"\n\nnamespace zawa {\n\ntemplate <std::signed_integral\
    \ T, class Add,class Del, class Eval>\nstd::vector<typename std::invoke_result_t<Eval,\
    \ usize>> MoonTree(const std::vector<std::vector<T>>& G,const std::vector<std::pair<T,T>>&\
    \ qs, Add add, Del del, Eval eval, bool reset = false) {\n    const T n = static_cast<T>(G.size());\n\
    \    if (!n) {\n        assert(qs.empty());\n        return {};\n    }\n    std::vector<T>\
    \ in(n),out(n),euler;\n    euler.reserve(2*n);\n    auto dfs=[&](auto dfs,T v,T\
    \ p) -> void {\n        in[v] = static_cast<T>(euler.size());\n        euler.push_back(v);\n\
    \        for (T x : G[v])\n            if (x != p)\n                dfs(dfs,x,v);\n\
    \        out[v] = static_cast<T>(euler.size());\n        euler.push_back(v);\n\
    \    };\n    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));\n    std::vector<std::pair<T,T>>\
    \ path;\n    path.reserve(qs.size());\n    LowestCommonAncestor lca{G,0};\n  \
    \  std::vector<T> extra;\n    extra.reserve(qs.size());\n    for (auto [u,v] :\
    \ qs) {\n        T l=lca(u,v);\n        T i=in[u],j=in[v];\n        if (i>j) {\n\
    \            std::swap(i,j);\n            std::swap(u,v);\n        }\n       \
    \ if (u!=l) {\n            i=out[u];\n            extra.push_back(l);\n      \
    \  }\n        else\n            extra.push_back(n);\n        path.push_back({i,j+1});\n\
    \    }\n    T L=0,R=0;\n    std::vector<typename std::invoke_result_t<Eval, usize>>\
    \ res(qs.size());\n    std::vector<bool> parity(n);\n    auto toggle=[&](T v)\
    \ -> void {\n        parity[v] ? del(v) : add(v);\n        parity[v] = !parity[v];\n\
    \    };\n    for (usize i : Mo(path)) {\n        const auto [l,r] = path[i];\n\
    \        while (R<r) \n            toggle(euler[R++]);\n        while (L>l)\n\
    \            toggle(euler[--L]);\n        while (R>r)\n            toggle(euler[--R]);\n\
    \        while (L<l) \n            toggle(euler[L++]);\n        if (extra[i]<n)\n\
    \            toggle(extra[i]);\n        res[i] = eval(i);\n        if (extra[i]<n)\n\
    \            toggle(extra[i]);\n    }\n    if (reset)\n        while (R>L) \n\
    \            toggle(euler[--R]);\n    return res;\n}\n\n} // namespace zawa\n\
    #line 6 \"Test/AtCoder/abc477_g.test.cpp\"\n#include <iostream>\nusing namespace\
    \ std;\nusing namespace zawa;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n    cin >> N >>\
    \ Q;\n    vector<int> X(N);\n    for (auto& x : X) {\n        cin >> x;\n    \
    \    x--;\n    }\n    vector<vector<int>> G(N);\n    for (int i = 0 ; i < N -\
    \ 1 ; i++) {\n        int u, v;\n        cin >> u >> v;\n        u--; v--;\n \
    \       G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    vector<pair<int,int>>\
    \ UV(Q);\n    vector<int> A(Q),B(Q);\n    for (int i = 0 ; i < Q ; i++) {\n  \
    \      int u,v;\n        cin >> u >> v >> A[i] >> B[i];\n        UV[i] = {--u,--v};\n\
    \    }\n    BucketRangeQuery<AdditiveGroup<int>> seg(N+1);\n    vector<int> cnt(N);\n\
    \    seg.operation(0,N);\n    auto add = [&](int v) -> void {\n        v = X[v];\n\
    \        seg.operation(cnt[v],-1);\n        cnt[v]++;\n        seg.operation(cnt[v],+1);\n\
    \    };\n    auto del = [&](int v) -> void {\n        v = X[v];\n        seg.operation(cnt[v],-1);\n\
    \        cnt[v]--;\n        seg.operation(cnt[v],+1);\n    };\n    auto eval =\
    \ [&](int i) -> int {\n        return seg.product(A[i],B[i]+1);\n    };\n    for\
    \ (int ans : MoonTree(G,UV,add,del,eval))\n        cout << ans << '\\n';\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/abc477/tasks/abc477_g\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\
    \n#include \"../../Src/DataStructure/Bucket/BucketRangeProduct.hpp\"\n#include\
    \ \"../../Src/Graph/Tree/MoonTree.hpp\"\n#include <iostream>\nusing namespace\
    \ std;\nusing namespace zawa;\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n\
    \    cout.tie(0);\n    ios::sync_with_stdio(0);\n    int N,Q;\n    cin >> N >>\
    \ Q;\n    vector<int> X(N);\n    for (auto& x : X) {\n        cin >> x;\n    \
    \    x--;\n    }\n    vector<vector<int>> G(N);\n    for (int i = 0 ; i < N -\
    \ 1 ; i++) {\n        int u, v;\n        cin >> u >> v;\n        u--; v--;\n \
    \       G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    vector<pair<int,int>>\
    \ UV(Q);\n    vector<int> A(Q),B(Q);\n    for (int i = 0 ; i < Q ; i++) {\n  \
    \      int u,v;\n        cin >> u >> v >> A[i] >> B[i];\n        UV[i] = {--u,--v};\n\
    \    }\n    BucketRangeQuery<AdditiveGroup<int>> seg(N+1);\n    vector<int> cnt(N);\n\
    \    seg.operation(0,N);\n    auto add = [&](int v) -> void {\n        v = X[v];\n\
    \        seg.operation(cnt[v],-1);\n        cnt[v]++;\n        seg.operation(cnt[v],+1);\n\
    \    };\n    auto del = [&](int v) -> void {\n        v = X[v];\n        seg.operation(cnt[v],-1);\n\
    \        cnt[v]--;\n        seg.operation(cnt[v],+1);\n    };\n    auto eval =\
    \ [&](int i) -> int {\n        return seg.product(A[i],B[i]+1);\n    };\n    for\
    \ (int ans : MoonTree(G,UV,add,del,eval))\n        cout << ans << '\\n';\n#else\n\
    \    int a,b;\n    cin >> a >> b;\n    cout << a+b << '\\n';\n#endif\n}\n"
  dependsOn:
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/DataStructure/Bucket/BucketRangeProduct.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Graph/Tree/MoonTree.hpp
  - Src/Utility/Mo.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/DataStructure/RMQ/PM1RMQ.hpp
  isVerificationFile: true
  path: Test/AtCoder/abc477_g.test.cpp
  requiredBy: []
  timestamp: '2026-09-30 00:23:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/abc477_g.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/abc477_g.test.cpp
- /verify/Test/AtCoder/abc477_g.test.cpp.html
title: Test/AtCoder/abc477_g.test.cpp
---
