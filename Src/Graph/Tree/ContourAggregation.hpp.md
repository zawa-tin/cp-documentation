---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/ChminMonoid.hpp
    title: "chmin\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/Heap/BinaryHeap.hpp
    title: "Binary Heap (\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SparseTable/SparseTable.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/Centroid.hpp
    title: "\u6728\u306E\u91CD\u5FC3"
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
    title: Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
    title: Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/ContourAggregation.hpp\"\n\n#line 2 \"Src/Graph/Tree/Centroid.hpp\"\
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
    \n\n#line 2 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\n\n#line 4 \"Src/Algebra/Monoid/ChminMonoid.hpp\"\
    \n\n#include <algorithm>\n#include <optional>\n\nnamespace zawa {\n\ntemplate\
    \ <class T, class U>\nclass ChminMonoidData {\nprivate:\n    std::optional<T>\
    \ priority_{};\n    U value_{};\npublic:\n    ChminMonoidData() = default;\n \
    \   ChminMonoidData(const U& value)\n        : priority_{std::nullopt}, value_{value}\
    \ {}\n    ChminMonoidData(const T& priority, const U& value)\n        : priority_{priority},\
    \ value_{value} {}\n\n    constexpr bool infty() const noexcept {\n        return\
    \ !priority_.has_value();\n    }\n    constexpr const T& priority() const noexcept\
    \ {\n        return priority_.value();\n    }\n    constexpr const U& value()\
    \ const noexcept {\n        return value_;\n    }\n    friend constexpr bool operator<(const\
    \ ChminMonoidData& l, const ChminMonoidData& r) {\n        if (l.infty()) return\
    \ false;\n        else if (r.infty()) return true;\n        else return l.priority()\
    \ < r.priority();\n    }\n};\n\ntemplate <class T, class U>\nstruct ChminMonoid\
    \ {\n    using Element = ChminMonoidData<T, U>;\n    static Element identity()\
    \ noexcept {\n        return Element{};\n    }\n    static Element operation(const\
    \ Element& l, const Element& r) noexcept {\n        return (r < l ? r : l);\n\
    \    }\n};\n\n} // namespace zawa\n#line 2 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n\n#line 4 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\n\n#line 7 \"Src/DataStructure/SparseTable/SparseTable.hpp\"\
    \n#include <ostream>\n\nnamespace zawa {\n\ntemplate <class Structure>\nclass\
    \ SparseTable {\nprivate:\n    using Value = typename Structure::Element;\n  \
    \  std::vector<u32> L;\n    std::vector<std::vector<Value>> dat;\npublic:\n\n\
    \    SparseTable() : L{}, dat{} {}\n    SparseTable(const std::vector<Value>&\
    \ a) : L(a.size() + 1), dat{} {\n        for (u32 i{1} ; i < L.size() ; i++) {\n\
    \            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n        }\n        dat.resize(L.back()\
    \ + 1);\n        dat[0] = a;\n        for (u32 i{1}, len{2} ; i < dat.size() ;\
    \ i++, len <<= 1) {\n            dat[i] = dat[i - 1];\n            for (u32 j{}\
    \ ; j + len - 1 < dat[i].size() ; j++) {\n                dat[i][j] = Structure::operation(dat[i\
    \ - 1][j], dat[i - 1][j + (len >> 1)]);\n            }\n        }\n    }\n\n \
    \   Value product(u32 l, u32 r) const {\n        assert(l <= r);\n        assert(l\
    \ < dat[0].size());\n        assert(r <= dat[0].size());\n        u32 now{L[r\
    \ - l]};\n        return Structure::operation(dat[now][l], dat[now][r - (1 <<\
    \ now)]);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ SparseTable<Structure>& spt) {\n        for (u32 i{}, len{1} ; i < spt.dat.size()\
    \ ; i++, len <<= 1) {\n            os << \"length = \" << len << '\\n';\n    \
    \        for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {\n           \
    \     os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\\n' : ' ');\n \
    \           }\n        }\n        return os;\n    }\n};\n\n} // namespace zawa\n\
    #line 6 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\n\n#line 9 \"Src/Graph/Tree/LowestCommonAncestor.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class V>\nclass LowestCommonAncestor {\nprivate:\n\
    \    using Monoid = ChminMonoid<u32, V>;\n\npublic:\n    LowestCommonAncestor()\
    \ = default;\n\n    LowestCommonAncestor(const std::vector<std::vector<V>>& tree,\
    \ V r = V{}) \n        : n_{tree.size()}, depth_(tree.size()), L_(tree.size()),\
    \ R_(tree.size()), st_{} {\n            std::vector<typename Monoid::Element>\
    \ init;\n            init.reserve(2 * size());\n            auto dfs{[&](auto\
    \ dfs, V v, V p) -> void {\n                depth_[v] = (p == INVALID ? 0u : depth_[p]\
    \ + 1);\n                L_[v] = (u32)init.size();\n                for (auto\
    \ x : tree[v]) {\n                    if (x == p) {\n                        continue;\n\
    \                    }\n                    init.emplace_back(depth_[v], v);\n\
    \                    dfs(dfs, x, v);\n                }\n                R_[v]\
    \ = (u32)init.size();\n            }};\n            dfs(dfs, r, INVALID);\n  \
    \          st_ = SparseTable<Monoid>(init);\n    }\n\n    V operator()(V u, V\
    \ v) const {\n        assert(verify(u));\n        assert(verify(v));\n       \
    \ if (L_[u] > L_[v]) {\n            std::swap(u, v);\n        }\n        return\
    \ u == v ? u : st_.product(L_[u], R_[v]).value();\n    }\n\n    V lca(V u, V v)\
    \ const {\n        return (*this)(u, v);\n    }\n\n    inline u32 depth(V v) const\
    \ noexcept {\n        assert(verify(v));\n        return depth_[v];\n    }\n\n\
    \    u32 distance(V u, V v) const {\n        assert(verify(u));\n        assert(verify(v));\n\
    \        return depth(u) + depth(v) - 2u * depth((*this)(u, v));\n    }\n\n  \
    \  bool isAncestor(V p, V v) const {\n        assert(verify(p));\n        assert(verify(v));\n\
    \        return L_[p] <= L_[v] and R_[v] <= R_[p];\n    }\n\nprotected:\n    u32\
    \ left(V v) const noexcept {\n        return L_[v];\n    }\n\n    inline usize\
    \ size() const {\n        return n_;\n    }\n\n    inline bool verify(V v) const\
    \ {\n        return v < (V)size();\n    }\n\nprivate:\n    static constexpr V\
    \ INVALID{static_cast<V>(-1)};\n    usize n_{};\n    std::vector<u32> depth_,\
    \ L_, R_;\n    SparseTable<Monoid> st_;\n};\n\n} // namespace zawa\n#line 2 \"\
    Src/DataStructure/Heap/BinaryHeap.hpp\"\n\n#line 4 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\
    \n\n#line 7 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\n#include <concepts>\n#line\
    \ 10 \"Src/DataStructure/Heap/BinaryHeap.hpp\"\n#include <functional>\n\nnamespace\
    \ zawa {\n\ntemplate <class T, class Comp = std::less<T>>\nrequires std::strict_weak_order<Comp,\
    \ const T&, const T&>\nclass BinaryHeap {\nprivate:\n\n    Comp m_comp;\n\n  \
    \  std::vector<T> m_dat;\n\npublic:\n\n    inline usize size() const {\n     \
    \   return m_dat.size() - 1;\n    }\n\n    inline bool empty() const {\n     \
    \   return m_dat.size() == 1;\n    }\n\n    inline const Comp& comp() const {\n\
    \        return m_comp;\n    }\n\n    using const_iterator = typename decltype(m_dat)::const_iterator;\n\
    \n    const_iterator begin() const {\n        return m_dat.begin() + 1;\n    }\n\
    \n    const_iterator end() const {\n        return m_dat.end();\n    }\n\n   \
    \ BinaryHeap(Comp comp = {}) \n        : m_comp{comp}, m_dat(1) {}\n\n    template\
    \ <std::forward_iterator It>\n    requires std::same_as<std::iter_value_t<It>,\
    \ T>\n    BinaryHeap(It first, It last, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(1) {\n        m_dat.insert(m_dat.end(), first, last);\n        build();\n\
    \    }\n\n    BinaryHeap(std::vector<T>&& a, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(a.size() + 1) {\n        std::ranges::copy(std::make_move_iterator(a.begin()),\
    \ std::make_move_iterator(a.end()), m_dat.begin() + 1);\n        build();\n  \
    \  }\n\n    BinaryHeap(const std::vector<T>& a, Comp comp = {}) \n        : m_comp{comp},\
    \ m_dat(a.size() + 1) {\n        std::ranges::copy(a.begin(), a.end(), m_dat.begin()\
    \ + 1);\n        build();\n    }\n\n    const T& top() const {\n        assert(size()\
    \ and \"HeapUnderFlow\");\n        return m_dat[1];\n    }\n\n    void push(T&&\
    \ v) {\n        m_dat.push_back(std::move(v));\n        upHeap(size());\n    }\n\
    \n    void push(const T& v) {\n        m_dat.push_back(v);\n        upHeap(size());\n\
    \    }\n\n    void pop() {\n        assert(size() and \"HeapUnderFlow\");\n  \
    \      if (size() > 1)\n            std::swap(m_dat[1], m_dat.back());\n     \
    \   m_dat.pop_back();\n        if (size() > 1)\n            downHeap(1, size());\n\
    \    }\n\nprivate:\n\n    void build() {\n        const usize n = size();\n  \
    \      for (usize i = (n >> 1) ; i ; i--) \n            downHeap(i, n);\n    }\n\
    \n    void upHeap(usize i) {\n        while (i >> 1 and m_comp(m_dat[i], m_dat[i\
    \ >> 1])) {\n            std::swap(m_dat[i], m_dat[i >> 1]);\n            i >>=\
    \ 1;\n        }\n    }\n\n    void downHeap(usize i, usize n) {\n        while\
    \ ((i << 1) <= n) {\n            usize j = i << 1;\n            if (j + 1 <= n\
    \ and m_comp(m_dat[j + 1], m_dat[j]))\n                j++;\n            if (!m_comp(m_dat[j],\
    \ m_dat[i]))\n                break;\n            std::swap(m_dat[i], m_dat[j]);\n\
    \            i = j;\n        }\n    }\n};\n\n} // namespace zawa\n#line 6 \"Src/Graph/Tree/ContourAggregation.hpp\"\
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
    \    std::vector<std::vector<usize>> m_inv;\n    \n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./Centroid.hpp\"\n#include \"./LowestCommonAncestor.hpp\"\
    \n#include \"../../DataStructure/Heap/BinaryHeap.hpp\"\n\n#include <cassert>\n\
    #include <concepts>\n#include <numeric>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa {\n\ntemplate <std::integral V>\nclass ContourAggregation\
    \ {\npublic:\n\n    ContourAggregation(std::vector<std::vector<V>> G) : m_lca{G},\
    \ m_cent(1), m_par(1), m_ch(1), m_offset(1) {\n        const usize N = G.size();\n\
    \        assert(N);\n        m_inv.resize(N);\n        m_pos.resize(N);\n    \
    \    m_ord.reserve(2 * N);\n        Centroid ce{std::move(G)};\n        std::vector<i32>\
    \ dist(N,-1);\n\n        auto makeNode = [&]() -> usize {\n            const usize\
    \ res = m_cent.size();\n            m_cent.push_back(N);\n            m_par.push_back(0);\n\
    \            m_ch.emplace_back();\n            m_offset.emplace_back();\n    \
    \        return res;\n        };\n\n        auto createOffset = [&](usize nd,std::vector<V>\
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
    \    std::vector<std::vector<usize>> m_inv;\n    \n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Graph/Tree/Centroid.hpp
  - Src/Template/TypeAlias.hpp
  - Src/Graph/Tree/LowestCommonAncestor.hpp
  - Src/Algebra/Monoid/ChminMonoid.hpp
  - Src/DataStructure/SparseTable/SparseTable.hpp
  - Src/DataStructure/Heap/BinaryHeap.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/ContourAggregation.hpp
  requiredBy: []
  timestamp: '2026-02-27 21:59:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/LC/vertex_add_range_contour_sum_on_tree.test.cpp
  - Test/LC/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: Src/Graph/Tree/ContourAggregation.hpp
layout: document
title: "\u6728\u4E0A\u306E\u7B49\u9AD8\u7DDA\u30AF\u30A8\u30EA"
---

## 概要

木上の頂点 $v$ から距離 $l$ 以上 $r$ 未満の全ての頂点を $O(\log N)$ 個の区間にして表現する。

区間更新区間総積はできなくて、普通のセグ木か双対セグ木と合わせて使うことになるだろう。

## ライブラリの使い方

### コンストラクタ

```cpp
template <std::integral V>
ContourAggregation(std::vector<std::vector<V>> G)
```

隣接リスト、無向辺であること。

### size

```cpp
inline usize size() const
```

必要になるデータ構造の要素数

### point

```cpp
std::vector<usize> point(V v) const;
```

$v$ の一点取得に使う

### contour

```cpp
std::vector<std::pair<usize,usize>> contour(V v, usize l, usize r) const
std::vector<std::pair<usize,usize>> contour(V v, usize d) const {
```

頂点 $v$ の距離 $l$ 以上 $r$ 未満

頂点 $v$ の距離が丁度 $d$ に対応
