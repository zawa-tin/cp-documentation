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
    path: Src/DataStructure/FenwickTree/DualFenwickTree.hpp
    title: Dual Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/BinaryHeap.hpp
    title: "Binary Heap (\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/RMQ/PM1RMQ.hpp
    title: Src/DataStructure/RMQ/PM1RMQ.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Centroid.hpp
    title: "\u6728\u306E\u91CD\u5FC3"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/ContourAggregation.hpp
    title: "\u6728\u4E0A\u306E\u7B49\u9AD8\u7DDA\u30AF\u30A8\u30EA"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree
  bundledCode: "#line 1 \"Test/LC/vertex_get_range_contour_add_on_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#line 2 \"Src/Graph/Tree/ContourAggregation.hpp\"\n\n#line 2 \"Src/Graph/Tree/Centroid.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Graph/Tree/Centroid.hpp\"\
    \n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace zawa\
    \ {\n\ntemplate <class V>\nclass Centroid {\npublic:\n\n    Centroid() = default;\n\
    \n    Centroid(const std::vector<std::vector<V>>& T) : T_{T}, size_(T_.size(),\
    \ usize{1}) {}\n    Centroid(std::vector<std::vector<V>>&& T) : T_{std::move(T)},\
    \ size_(T_.size(), usize{1}) {}\n\n    inline usize size() const noexcept {\n\
    \        return T_.size();\n    }\n\n    inline usize size(V v) const noexcept\
    \ {\n        assert(v < (V)size());\n        return size_[v];\n    }\n\n    bool\
    \ isRemoved(V v) const noexcept {\n        assert(v < (V)size());\n        return\
    \ size_[v] == 0u;\n    }\n\n    void remove(V v) noexcept {\n        assert(v\
    \ < (V)size());\n        size_[v] = 0u;\n    }\n\n    const std::vector<V>& operator[](V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return T_[v];\n\
    \    }\n\n    // @response: centroid of component which v belongs\n    V rooting(V\
    \ v) {\n        assert(v < (V)size());\n        assert(!isRemoved(v));\n     \
    \   usize all{dfsSize(v, INVALID)};\n        V par{INVALID};\n        bool fn{false};\n\
    \        while (!fn) {\n            fn = true;\n            for (V x : T_[v])\
    \ {\n                if (x == par or isRemoved(x) or usize{2} * size_[x] <= all)\
    \ {\n                    continue;\n                }\n                fn = false;\n\
    \                par = v;\n                v = x;\n                break;\n  \
    \          }\n        }\n        return v;\n    }\n\n    std::vector<V> component(V\
    \ v) const {\n        assert(v < (V)size());\n        assert(!isRemoved(v));\n\
    \        std::vector<V> res;\n        dfsComponent(v, INVALID, res);\n       \
    \ return res;\n    }\n\n    std::vector<V> adjlist(V v) const {\n        assert(v\
    \ < (V)size());\n        std::vector<V> res;\n        res.reserve(T_[v].size());\n\
    \        for (auto x : T_[v]) if (!isRemoved(x)) {\n            res.emplace_back(x);\n\
    \        }\n        return res;\n    }\n\nprivate:\n    static constexpr V INVALID{static_cast<V>(-1)};\n\
    \    std::vector<std::vector<V>> T_{};\n    std::vector<usize> size_{};\n\n  \
    \  usize dfsSize(V v, V par) {\n        size_[v] = 1u;\n        for (V x : T_[v])\
    \ if (x != par and !isRemoved(x)) {\n            size_[v] += dfsSize(x, v);\n\
    \        }\n        return size_[v];\n    }\n\n    void dfsComponent(V v, V par,\
    \ std::vector<V>& comp) const {\n        comp.emplace_back(v);\n        for (V\
    \ x : T_[v]) if (x != par and !isRemoved(x)) {\n            dfsComponent(x, v,\
    \ comp);\n        }\n    }\n};\n\n} // namespace zawa\n#line 2 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\n#line 2 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n#line 4 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bit>\n#line 9 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\
    \n#include <concepts>\n#line 12 \"Src/DataStructure/RMQ/PM1RMQ.hpp\"\n\n\nnamespace\
    \ zawa {\n\ntemplate <std::totally_ordered T>\nclass PM1RMQ {\nprivate:\n\n  \
    \  static constexpr usize B = 8;\n\n    static constexpr usize BMASK = 7;\n\n\
    \    static constexpr usize LOGB = 3;\n\n    static constexpr usize TRI = B*(B+1)/2;\n\
    \npublic:\n\n    PM1RMQ() = default;\n\n    PM1RMQ(std::vector<T> a) \n      \
    \  : m_n{a.size()}, m_inner{(a.size()+B-1)>>LOGB},\n        m_a{std::move(a)},\
    \ m_look(innerSize()), m_table(), m_spt(std::bit_width(innerSize()))\n    {\n\
    \        std::vector<u32> minIndex(innerSize());\n        std::vector<bool> registered(1u\
    \ << (B-1));\n        for (usize i = 0,idx = 0 ; i < size() ; idx++) {\n     \
    \       minIndex[idx] = i;\n            for (u8 j = 1 ; ++i < size() and j < (u8)B\
    \ ; j++) {\n                if (m_a[i] < m_a[minIndex[idx]])\n               \
    \     minIndex[idx] = i;\n                if (m_a[i] == m_a[i-1]+1)\n        \
    \            ;\n                else if (m_a[i] == m_a[i-1]-1)\n             \
    \       m_look[idx] |= u8{1} << (j-1);\n                else\n               \
    \     assert(!\"init table does not satisfy |a_i-a_{i+1}| = 1\");\n          \
    \  }\n            if (!registered[m_look[idx]]) {\n                registered[m_look[idx]]\
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
    \ m_rmq;\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\
    \n\n#line 4 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\n\n#line 10 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\
    \n#include <functional>\n\nnamespace zawa {\n\ntemplate <class T, class Comp =\
    \ std::less<T>>\nrequires std::strict_weak_order<Comp, const T&, const T&>\nclass\
    \ BinaryHeap {\nprivate:\n\n    Comp m_comp;\n\n    std::vector<T> m_dat;\n\n\
    public:\n\n    inline usize size() const {\n        return m_dat.size() - 1;\n\
    \    }\n\n    inline bool empty() const {\n        return m_dat.size() == 1;\n\
    \    }\n\n    inline const Comp& comp() const {\n        return m_comp;\n    }\n\
    \n    using const_iterator = typename decltype(m_dat)::const_iterator;\n\n   \
    \ const_iterator begin() const {\n        return m_dat.begin() + 1;\n    }\n\n\
    \    const_iterator end() const {\n        return m_dat.end();\n    }\n\n    BinaryHeap(Comp\
    \ comp = {}) \n        : m_comp{comp}, m_dat(1) {}\n\n    template <std::forward_iterator\
    \ It>\n    requires std::same_as<std::iter_value_t<It>, T>\n    BinaryHeap(It\
    \ first, It last, Comp comp = {}) \n        : m_comp{comp}, m_dat(1) {\n     \
    \   m_dat.insert(m_dat.end(), first, last);\n        build();\n    }\n\n    BinaryHeap(std::vector<T>&&\
    \ a, Comp comp = {}) \n        : m_comp{comp}, m_dat(a.size() + 1) {\n       \
    \ std::ranges::copy(std::make_move_iterator(a.begin()), std::make_move_iterator(a.end()),\
    \ m_dat.begin() + 1);\n        build();\n    }\n\n    BinaryHeap(const std::vector<T>&\
    \ a, Comp comp = {}) \n        : m_comp{comp}, m_dat(a.size() + 1) {\n       \
    \ std::ranges::copy(a.begin(), a.end(), m_dat.begin() + 1);\n        build();\n\
    \    }\n\n    const T& top() const {\n        assert(size() and \"HeapUnderFlow\"\
    );\n        return m_dat[1];\n    }\n\n    void push(T&& v) {\n        m_dat.push_back(std::move(v));\n\
    \        upHeap(size());\n    }\n\n    void push(const T& v) {\n        m_dat.push_back(v);\n\
    \        upHeap(size());\n    }\n\n    void pop() {\n        assert(size() and\
    \ \"HeapUnderFlow\");\n        if (size() > 1)\n            std::swap(m_dat[1],\
    \ m_dat.back());\n        m_dat.pop_back();\n        if (size() > 1)\n       \
    \     downHeap(1, size());\n    }\n\nprivate:\n\n    void build() {\n        const\
    \ usize n = size();\n        for (usize i = (n >> 1) ; i ; i--) \n           \
    \ downHeap(i, n);\n    }\n\n    void upHeap(usize i) {\n        while (i >> 1\
    \ and m_comp(m_dat[i], m_dat[i >> 1])) {\n            std::swap(m_dat[i], m_dat[i\
    \ >> 1]);\n            i >>= 1;\n        }\n    }\n\n    void downHeap(usize i,\
    \ usize n) {\n        while ((i << 1) <= n) {\n            usize j = i << 1;\n\
    \            if (j + 1 <= n and m_comp(m_dat[j + 1], m_dat[j]))\n            \
    \    j++;\n            if (!m_comp(m_dat[j], m_dat[i]))\n                break;\n\
    \            std::swap(m_dat[i], m_dat[j]);\n            i = j;\n        }\n \
    \   }\n};\n\n} // namespace zawa\n#line 6 \"Src/Graph/Tree/ContourAggregation.hpp\"\
    \n\n#line 9 \"Src/Graph/Tree/ContourAggregation.hpp\"\n#include <numeric>\n#include\
    \ <tuple>\n#line 13 \"Src/Graph/Tree/ContourAggregation.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <std::integral V>\nclass ContourAggregation {\npublic:\n\n   \
    \ ContourAggregation(std::vector<std::vector<V>> G) : m_lca{G}, m_cent(1), m_par(1),\
    \ m_ch(1), m_offset(1) {\n        const usize N = G.size();\n        assert(N);\n\
    \        m_inv.resize(N);\n        m_pos.resize(N);\n        m_ord.reserve(2 *\
    \ N);\n        Centroid ce{std::move(G)};\n        std::vector<i32> dist(N,-1);\n\
    \n        auto makeNode = [&]() -> usize {\n            const usize res = m_cent.size();\n\
    \            m_cent.push_back(N);\n            m_par.push_back(0);\n         \
    \   m_ch.emplace_back();\n            m_offset.emplace_back();\n            return\
    \ res;\n        };\n\n        auto createOffset = [&](usize nd,std::vector<V>\
    \ vs) {\n            std::vector<usize> offset{m_ord.size()};\n            if\
    \ (dist[vs[0]] == 1)\n                offset.push_back(m_ord.size());\n      \
    \      for (usize i = 0, j = 0 ; i < vs.size() ; i = j) {\n                while\
    \ (j < vs.size() and dist[vs[i]] == dist[vs[j]]) {\n                    m_inv[vs[j]].push_back(m_ord.size());\n\
    \                    m_ord.push_back(vs[j]);\n                    j++;\n     \
    \           }\n                offset.push_back(m_ord.size());\n            }\n\
    \            m_offset[nd] = std::move(offset);\n        };\n\n        auto compDist\
    \ = [&](usize i, usize j) -> bool {\n            return dist[i] < dist[j];\n \
    \       };\n\n        // {node id, height, vertices}\n        auto dfs = [&](auto\
    \ dfs, V v) -> std::tuple<usize,usize,std::vector<V>> {\n            v = ce.rooting(v);\n\
    \            std::vector<std::tuple<usize,usize,std::vector<V>>> ch;\n       \
    \     ce.remove(v);\n            dist[v] = 0;\n            for (V x : ce.adjlist(v))\
    \ {\n                auto ret = dfs(dfs,x);\n                for (V cur : std::get<2>(ret))\n\
    \                    dist[cur] = m_lca.distance(v,cur);\n                m_cent[std::get<0>(ret)]\
    \ = v;\n                ch.push_back(std::move(ret));\n            }\n       \
    \     for (auto& dat : ch)\n                std::ranges::sort(std::get<2>(dat),compDist);\n\
    \            { // create single node of {v}\n                const usize nd =\
    \ m_pos[v] = makeNode();\n                ch.emplace_back(nd,0u,std::vector<V>{v});\n\
    \                m_cent[nd] = v;\n            }\n            auto comp = [&](usize\
    \ i, usize j) -> bool {\n                return std::get<1>(ch[i]) < std::get<1>(ch[j]);\n\
    \            };\n            BinaryHeap<usize,decltype(comp)> heap{[&]()->std::vector<usize>{\n\
    \                std::vector<usize> res(ch.size()); \n                std::iota(res.begin(),res.end(),0u);\
    \ \n                return res;\n            }(),comp};\n            while (std::ssize(heap)\
    \ > 1) {\n                const usize l = heap.top();\n                heap.pop();\n\
    \                const usize r = heap.top();\n                heap.pop();\n  \
    \              const usize L = std::get<0>(ch[l]), R = std::get<0>(ch[r]);\n \
    \               createOffset(L,std::get<2>(ch[l]));\n                createOffset(R,std::get<2>(ch[r]));\n\
    \                // merge here\n                std::vector<V> vertices;\n   \
    \             std::ranges::merge(std::move(std::get<2>(ch[l])),std::move(std::get<2>(ch[r])),std::back_inserter(vertices),compDist);\n\
    \                const usize nd = makeNode();\n                m_par[L] = m_par[R]\
    \ = nd;\n                m_cent[L] = m_cent[R] = v;\n                const usize\
    \ h = std::max(std::get<1>(ch[l]),std::get<1>(ch[r]))+1;\n                ch.emplace_back(nd,h,std::move(vertices));\n\
    \                heap.push(ch.size()-1);\n                m_ch[nd] = {L,R};\n\
    \            }\n            for (V x : std::get<2>(ch[heap.top()]))\n        \
    \        dist[x] = -1;\n            return ch[heap.top()];\n        };\n     \
    \   if (N == 1) {\n            m_inv[0].push_back(0);\n            m_ord.push_back(0);\n\
    \        }\n        else {\n            std::vector<bool> vis(N);\n          \
    \  for (V i = 0 ; i < (V)N ; i++)\n                if (!vis[i]) {\n          \
    \          const auto ret = std::get<2>(dfs(dfs,i));\n                    for\
    \ (V v : ret)\n                        vis[v] = 1;\n                }\n      \
    \  }\n    }\n\n    inline usize size() const {\n        return m_ord.size();\n\
    \    }\n\n    std::vector<usize> point(V v) const {\n        assert(0 <= v and\
    \ v < (V)m_inv.size());\n        return m_inv[v];\n    }\n\n    std::vector<std::pair<usize,usize>>\
    \ contour(V v, usize l, usize r) const {\n        assert(V{0} <= v and v < (V)m_inv.size());\n\
    \        std::vector<std::pair<usize,usize>> res;\n        if (l >= r)\n     \
    \       return res;\n        usize nd = m_pos[v];\n        if (l == 0)\n     \
    \       res.push_back({m_inv[v][0],m_inv[v][0]+1});\n        for ( ; m_par[nd]\
    \ ; nd = m_par[nd]) {\n            const usize cur = m_ch[m_par[nd]].first ==\
    \ nd ? m_ch[m_par[nd]].second : m_ch[m_par[nd]].first;\n            const usize\
    \ sub = m_lca.distance(m_cent[cur],v);\n            if (sub >= r)\n          \
    \      continue;\n            const usize L = sub >= l ? 0 : l - sub;\n      \
    \      const usize R = std::min(r - sub,m_offset[cur].size()-1);\n           \
    \ if (L >= R)\n                continue;\n            res.push_back({m_offset[cur][L],m_offset[cur][R]});\n\
    \        }\n        return res;\n    }\n\n    std::vector<std::pair<usize,usize>>\
    \ contour(V v, usize d) const {\n        return contour(v,d,d+1);\n    }\n\nprivate:\n\
    \n    LowestCommonAncestor<V> m_lca;\n\n    std::vector<V> m_cent;\n\n    std::vector<usize>\
    \ m_par;\n\n    std::vector<std::pair<usize,usize>> m_ch;\n\n    std::vector<std::vector<usize>>\
    \ m_offset;\n\n    std::vector<V> m_ord;\n\n    std::vector<usize> m_pos;\n\n\
    \    std::vector<std::vector<usize>> m_inv;\n    \n};\n\n} // namespace zawa\n\
    #line 2 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n\n#line 2 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#line 4 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\n\nnamespace zawa {\n\
    \nnamespace concepts {\n\ntemplate <class T>\nconcept Semigroup = requires {\n\
    \    typename T::Element;\n    { T::operation(std::declval<typename T::Element>(),\
    \ std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;\n\
    };\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\nnamespace zawa {\n\nnamespace\
    \ concepts {\n\ntemplate <class T>\nconcept Identitiable = requires {\n    typename\
    \ T::Element;\n    { T::identity() } -> std::same_as<typename T::Element>;\n};\n\
    \ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\n}\
    \ // namespace\n\n} // namespace zawa\n#line 4 \"Src/Algebra/Group/GroupConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Inversible\
    \ = requires {\n    typename T::Element;\n    { T::inverse(std::declval<typename\
    \ T::Element>()) } -> std::same_as<typename T::Element>;\n};\n\ntemplate <class\
    \ T>\nconcept Group = Monoid<T> and Inversible<T>;\n\n} // namespace Concept\n\
    \n} // namespace zawa\n#line 5 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n\n#line 9 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\n#include <iterator>\n\
    #include <optional>\n#line 12 \"Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class F, class V>\n\
    concept Predicate = requires {\n    { std::declval<F>()(std::declval<V>()) } ->\
    \ std::same_as<bool>; \n};\n\n} // namespace Concept\n\ntemplate <concepts::Group\
    \ G>\nclass DualFenwickTree {\npublic:\n\n    using V = typename G::Element;\n\
    \n    constexpr static u32 Log2(usize n) noexcept {\n        return static_cast<u32>(\n\
    \                    std::bit_width(n) - (std::has_single_bit(n) ? 1 : 0)\n  \
    \              );\n    }\n\n    DualFenwickTree() = default;\n\n    DualFenwickTree(usize\
    \ n) : n_{n}, lg_{Log2(n)}, dat_(n+1, G::identity()) {\n        assert(n);\n \
    \   }\n\n    DualFenwickTree(const std::vector<V>& d) : n_{d.size()}, lg_{Log2(n_)},\
    \ dat_(d.size() + 1, G::identity()) {\n        assert(d.size());\n        add(0,\
    \ d[0]);\n        for (usize i = 1 ; i < d.size() ; i++) add(i, G::operation(G::inverse(d[i\
    \ - 1]), d[i]));\n    }\n\n    template <std::input_iterator It>\n    DualFenwickTree(It\
    \ first, It last) \n    : n_{static_cast<usize>(std::distance(first, last))},\
    \ lg_{Log2(n_)}, dat_(n_ + 1, G::identity()) {\n        assert(first != last);\n\
    \        V pv = static_cast<V>(*first);\n        add(0, pv);\n        for (usize\
    \ i = 1 ; i < n_ ; i++) {\n            first++;\n            V v = static_cast<V>(*first);\n\
    \            add(i, G::operation(G::inverse(pv), v));\n            pv = v;\n \
    \       } \n    }\n\n    inline usize size() const noexcept {\n        return\
    \ n_;\n    }\n\n    void operation(usize l, usize r, const V& v) {\n        assert(l\
    \ <= r and r <= size());\n        if (l < r) {\n            add(l, v);\n     \
    \       if (r < size()) add(r, G::inverse(v));\n        }\n    }\n\n    void operation(usize\
    \ i, const V& v) {\n        assert(i < size());\n        operation(i, i + 1, v);\n\
    \    }\n\n    V operator[](i32 i) const {\n        assert(0 <= i and i < (i32)size());\n\
    \        V res = G::identity();\n        for (i++ ; i ; i -= lsb(i)) res = G::operation(dat_[i],\
    \ res);\n        return res;\n    }\n\n    void set(usize i, V v) {\n        assert(0\
    \ <= i and i < size());\n        v = G::operation(G::inverse((*this)[i]), v);\n\
    \        operation(i, v);\n    }\n\n    template <class F>\n    std::optional<usize>\
    \ maxRight(usize l, F f) const requires concepts::Predicate<F, V> {\n        assert(l\
    \ < size());\n        V sum = l ? (*this)[l - 1] : G::identity();\n        usize\
    \ r = 0;\n        for (u32 w = lg_ ; w <= lg_ ; w--) {\n            usize next\
    \ = r | (1u << w);\n            if (next >= dat_.size()) continue;\n         \
    \   V nsum = G::operation(sum, dat_[next]);\n            if (f(nsum)) {\n    \
    \            sum = std::move(nsum);\n                r = std::move(next);\n  \
    \          }\n        }\n        assert(l <= r);\n        return r == size() and\
    \ f(sum) ? std::nullopt : std::optional{r};\n    }\n\n    // \u5B9F\u88C5\u304C\
    \u5408\u3044\u307E\u305B\u3093\u3002\u982D\u304C\u60AA\u3044\u306E\u3067\n   \
    \ // template <class F>\n    // requires Concept::Predicate<F, V>\n    // std::optional<usize>\
    \ minLeft(usize r, F f) const {\n    //     assert(r <= n_);\n    //     V sum\
    \ = G::identity();\n    //     usize l = 0;\n    //     for (u32 w = lg_ ; w <=\
    \ lg_ ; w--) {\n    //         u32 next = l | (1u << w);\n    //         if (next\
    \ >= r) continue;\n    //         V nsum = G::operation(dat_[next], sum);\n  \
    \  //         if (!f(nsum)) {\n    //             sum = std::move(nsum);\n   \
    \ //             l = std::move(next);\n    //         }\n    //     }\n    //\
    \     assert(l <= r);\n    //     if (l + 1 == r and !f(sum)) return r;\n    //\
    \     return l == 0u and f(sum) ? std::nullopt : std::optional{l};\n    // }\n\
    \nprivate:\n\n    usize n_;\n\n    u32 lg_;\n\n    std::vector<V> dat_;\n\n  \
    \  constexpr i32 lsb(i32 x) const noexcept {\n        return x & -x;\n    }\n\n\
    \    void add(i32 i, const V& v) {\n        for (i++ ; i <= (i32)size() ; i +=\
    \ lsb(i)) dat_[i] = G::operation(dat_[i], v);\n    }\n};\n\n} // namespace zawa\n\
    #line 2 \"Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nclass AdditiveGroup {\npublic:\n    using Element = T;\n    static\
    \ constexpr T identity() noexcept {\n        return T{};\n    }\n    static constexpr\
    \ T operation(T l,T r) noexcept {\n        return l + r;\n    }\n    static constexpr\
    \ T inverse(T v) noexcept {\n        return -v;\n    }\n    template <class U>\n\
    \    static constexpr T power(T v,U exp) noexcept {\n        return v * static_cast<T>(exp);\n\
    \    }\n};\n\n} // namespace zawa\n#line 6 \"Test/LC/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \nusing namespace zawa;\n\n#line 9 \"Test/LC/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \n#include <iostream>\n#line 11 \"Test/LC/vertex_get_range_contour_add_on_tree.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n  \
    \  ios::sync_with_stdio(0);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    for (auto& x : A)\n        cin >> x;\n    vector<vector<int>> G(N);\n\
    \    for (int i = 0 ; i < N - 1 ; i++) {\n       int u, v;\n       cin >> u >>\
    \ v;\n       G[u].push_back(v);\n       G[v].push_back(u);\n    }\n    ContourAggregation\
    \ sol(move(G));\n    cerr << \"size=\" << ssize(sol) << endl;\n    DualFenwickTree<AdditiveGroup<long\
    \ long>> fen(ssize(sol));\n    for (int i = 0 ; i < N ; i++) \n        for (auto\
    \ [L, R] : sol.contour(i,0))\n            fen.operation(L,R,A[i]);\n    while\
    \ (Q--) {\n        int T;\n        cin >> T;\n        if (T == 0) {\n        \
    \    int p, l, r, x;\n            cin >> p >> l >> r >> x;\n            for (auto\
    \ [L, R] : sol.contour(p,l,r))\n                fen.operation(L,R,x);\n      \
    \  }\n        else if (T == 1) {\n            int p;\n            cin >> p;\n\
    \            long long ans = 0;\n            for (auto i : sol.point(p))\n   \
    \             ans += fen[i];\n            cout << ans << '\\n';\n        }\n \
    \       else\n            assert(0);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree\"\
    \n\n#include \"../../Src/Graph/Tree/ContourAggregation.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\nusing namespace zawa;\n\
    \n#include <cassert>\n#include <iostream>\n#include <vector>\nusing namespace\
    \ std;\n\nint main() {\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto& x :\
    \ A)\n        cin >> x;\n    vector<vector<int>> G(N);\n    for (int i = 0 ; i\
    \ < N - 1 ; i++) {\n       int u, v;\n       cin >> u >> v;\n       G[u].push_back(v);\n\
    \       G[v].push_back(u);\n    }\n    ContourAggregation sol(move(G));\n    cerr\
    \ << \"size=\" << ssize(sol) << endl;\n    DualFenwickTree<AdditiveGroup<long\
    \ long>> fen(ssize(sol));\n    for (int i = 0 ; i < N ; i++) \n        for (auto\
    \ [L, R] : sol.contour(i,0))\n            fen.operation(L,R,A[i]);\n    while\
    \ (Q--) {\n        int T;\n        cin >> T;\n        if (T == 0) {\n        \
    \    int p, l, r, x;\n            cin >> p >> l >> r >> x;\n            for (auto\
    \ [L, R] : sol.contour(p,l,r))\n                fen.operation(L,R,x);\n      \
    \  }\n        else if (T == 1) {\n            int p;\n            cin >> p;\n\
    \            long long ans = 0;\n            for (auto i : sol.point(p))\n   \
    \             ans += fen[i];\n            cout << ans << '\\n';\n        }\n \
    \       else\n            assert(0);\n    }\n}\n"
  dependsOn:
  - Src/Graph/Tree/ContourAggregation.hpp
  - Src/Graph/Tree/Centroid.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/DataStructure/RMQ/PM1RMQ.hpp
  - Src/DataStructure/Heap/BinaryHeap.hpp
  - Src/DataStructure/FenwickTree/DualFenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  isVerificationFile: true
  path: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
  requiredBy: []
  timestamp: '2026-05-04 13:04:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
- /verify/Test/LC/vertex_get_range_contour_add_on_tree.test.cpp.html
title: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
---
