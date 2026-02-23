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
    path: Src/Graph/Tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"Test/LC/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"Src/Template/IOSetting.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Template/IOSetting.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nnamespace zawa {\n\nvoid SetFastIO()\
    \ {\n    std::cin.tie(nullptr)->sync_with_stdio(false);\n}\n\nvoid SetPrecision(u32\
    \ dig) {\n    std::cout << std::fixed << std::setprecision(dig);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"Src/DataStructure/FenwickTree/FenwickTree.hpp\"\n\n#line 2 \"\
    Src/Algebra/Group/GroupConcept.hpp\"\n\n#line 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
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
    \n\n#include <vector>\n#include <cassert>\n#include <ostream>\n#include <functional>\n\
    #include <type_traits>\n\nnamespace zawa {\n\ntemplate <concepts::Monoid Monoid>\n\
    class FenwickTree {\npublic:\n\n    using VM = Monoid;\n    \n    using V = typename\
    \ VM::Element;\n\n    FenwickTree() = default;\n\n    explicit FenwickTree(usize\
    \ n) : m_n{ n }, m_bitwidth{ std::__lg(n) + 1 }, m_a(n, VM::identity()), m_dat(n\
    \ + 1, VM::identity()) {\n        m_dat.shrink_to_fit();\n        m_a.shrink_to_fit();\n\
    \    }\n\n    explicit FenwickTree(const std::vector<V>& a) : m_n{ a.size() },\
    \ m_bitwidth{ std::__lg(a.size()) + 1 }, m_a(a), m_dat(a.size() + 1, VM::identity())\
    \ {\n        m_dat.shrink_to_fit();  \n        m_a.shrink_to_fit();\n        for\
    \ (i32 i{} ; i < static_cast<i32>(m_n) ; i++) {\n            addDat(i, a[i]);\n\
    \        }\n    }\n\n    inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    // return a[i]\n    const V& get(usize i) const noexcept\
    \ {\n        assert(i < size());\n        return m_a[i];\n    }\n\n    // return\
    \ a[i]\n    const V& operator[](usize i) const noexcept {\n        assert(i <\
    \ size());\n        return m_a[i];\n    }\n\n    // a[i] <- a[i] + v\n    void\
    \ operation(usize i, const V& v) {\n        assert(i < size());\n        addDat(i,\
    \ v);\n        m_a[i] = VM::operation(m_a[i], v);\n    }\n\n    // a[i] <- v\n\
    \    void assign(usize i, const V& v) requires concepts::Inversible<Monoid> {\n\
    \        assert(i < size());\n        addDat(i, VM::operation(VM::inverse(m_a[i]),\
    \ v));\n        m_a[i] = v;\n    }\n\n    // return a[0] + a[1] + ... + a[r -\
    \ 1]\n    V prefixProduct(usize r) const {\n        assert(r <= size());\n   \
    \     return product(r);\n    }\n\n    // return a[l] + a[l + 1] ... + a[r - 1]\n\
    \    V product(usize l, usize r) const requires concepts::Inversible<Monoid> {\n\
    \        assert(l <= r and r <= size());\n        return VM::operation(VM::inverse(product(l)),\
    \ product(r));\n    }\n\n    template <class Function>\n    usize maxRight(usize\
    \ l, const Function& f) const requires concepts::Inversible<Monoid> {\n      \
    \  static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, \"\
    maxRight's argument f must be function bool(T)\");\n        assert(l <= size());\n\
    \        assert(f(VM::identity()));\n        V sum{ VM::inverse(product(l)) };\
    \ \n        usize r{};\n        for (usize bit{ m_bitwidth } ; bit ; ) {\n   \
    \         bit--;\n            usize nxt{ r | (1u << bit) };\n            if (nxt\
    \ < m_dat.size() and (nxt <= l or f(VM::operation(sum, m_dat[nxt])))) {\n    \
    \            sum = VM::operation(sum, m_dat[nxt]);\n                r = std::move(nxt);\n\
    \            }\n        }\n        assert(l <= r);\n        return r;\n    }\n\
    \n    template <class Function>\n    usize minLeft(usize r, const Function& f)\
    \ const requires concepts::Inversible<Monoid> {\n        static_assert(std::is_convertible_v<decltype(f),\
    \ std::function<bool(V)>>, \"minLeft's argument f must be function bool(T)\");\n\
    \        assert(r <= size());\n        assert(f(VM::identity()));\n        V sum{\
    \ product(r) };\n        usize l{};\n        for (usize bit{ m_bitwidth } ; bit\
    \ ; ) {\n            bit--;\n            usize nxt{ l | (1u << bit) };\n     \
    \       if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]), sum))) {\n\
    \                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);\n        \
    \        l = std::move(nxt);\n            }\n        }\n        assert(l <= r);\n\
    \        return l;\n    }\n\n    // debug print\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const FenwickTree& ft) {\n        for (usize i{} ; i <= ft.size() ; i++)\
    \ {\n            os << ft.prefixProduct(i) << (i == ft.size() ? \"\" : \" \");\n\
    \        }\n        return os;\n    }\n\nprivate:\n\n    usize m_n{};\n\n    usize\
    \ m_bitwidth{};\n\n    std::vector<V> m_a, m_dat;\n\n    constexpr i32 lsb(i32\
    \ x) const noexcept {\n        return x & -x;\n    }\n    \n    // a[i] <- a[i]\
    \ + v\n    void addDat(i32 i, const V& v) {\n        assert(0 <= i and i < static_cast<i32>(m_n));\n\
    \        for ( i++ ; i < static_cast<i32>(m_dat.size()) ; i += lsb(i)) {\n   \
    \         m_dat[i] = VM::operation(m_dat[i], v);\n        }\n    }\n\n    // return\
    \ a[0] + a[1] + .. + a[i - 1]\n    V product(i32 i) const {\n        assert(0\
    \ <= i and i <= static_cast<i32>(m_n));\n        V res{ VM::identity() };\n  \
    \      for ( ; i > 0 ; i -= lsb(i)) {\n            res = VM::operation(res, m_dat[i]);\n\
    \        }\n        return res;\n    }\n\n};\n\n} // namespace zawa\n#line 2 \"\
    Src/Algebra/Group/AdditiveGroup.hpp\"\n\nnamespace zawa {\n\ntemplate <class T>\n\
    class AdditiveGroup {\npublic:\n    using Element = T;\n    static constexpr T\
    \ identity() noexcept {\n        return T{};\n    }\n    static constexpr T operation(const\
    \ T& l, const T& r) noexcept {\n        return l + r;\n    }\n    static constexpr\
    \ T inverse(const T& v) noexcept {\n        return -v;\n    }\n};\n\n} // namespace\
    \ zawa\n#line 2 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\n#line 4 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n#include <cmath>\n#include <limits>\n#include <optional>\n#include <utility>\n\
    #line 13 \"Src/Graph/Tree/HeavyLightDecomposition.hpp\"\n\nnamespace zawa {\n\n\
    template <std::integral V>\nclass HeavyLightDecomposition {\npublic:\n\n    HeavyLightDecomposition()\
    \ = default;\n\n    HeavyLightDecomposition(std::vector<std::vector<V>> T, V root\
    \ = 0u) \n        : m_n{T.size()}, m_par(m_n), m_top(m_n), m_idx(m_n), \n    \
    \    m_inv(m_n), m_bottom(m_n),  m_size(m_n, usize{1}), m_dep(m_n) {\n\n     \
    \       auto dfs1 = [&](auto dfs, V v, V p, usize d) -> usize {\n            \
    \    m_par[v] = p;\n                m_dep[v] = d;\n                if (p != INVALID)\
    \ {\n                    for (usize i = 0 ; i + 1 < T[v].size() ; i++) \n    \
    \                    if (T[v][i] == p) {\n                            std::swap(T[v][i],\
    \ T[v].back());\n                            break;\n                        }\n\
    \                    assert(T[v].back() == p);\n                    T[v].pop_back();\n\
    \                }\n                for (V x : T[v])\n                    m_size[v]\
    \ += dfs(dfs, x, v, d + 1);\n                for (usize i = 1 ; i < T[v].size()\
    \ ; i++) \n                    if (m_size[T[v][0]] < m_size[T[v][i]])\n      \
    \                  std::swap(T[v][0], T[v][i]);\n                return m_size[v];\n\
    \            };\n\n            auto dfs2 = [&](auto dfs, V v, V idx, V top) ->\
    \ V {\n                m_idx[v] = idx++;\n                m_inv[m_idx[v]] = v;\n\
    \                m_top[v] = top;\n                if (T[v].size()) {\n       \
    \             idx = dfs(dfs, T[v][0], idx, top);\n                    for (usize\
    \ i = 1 ; i < T[v].size() ; i++)\n                        idx = dfs(dfs, T[v][i],\
    \ idx, T[v][i]);\n                }\n                return idx;\n           \
    \ };\n\n            dfs1(dfs1, root, INVALID, 0u);\n            dfs2(dfs2, root,\
    \ 0u, root);\n\n            for (usize i = 0 ; i < m_n ; i++)\n              \
    \  if (m_dep[m_bottom[m_top[i]]] < m_dep[i])\n                    m_bottom[m_top[i]]\
    \ = i;\n        }\n\n    inline usize size() const noexcept {\n        return\
    \ m_n;\n    }\n\n    usize size(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_size[v];\n    }\n\n    usize depth(V v) const noexcept {\n \
    \       assert(v < (V)size());\n        return m_dep[v];\n    }\n\n    V parent(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_par[v];\n\
    \    }\n\n    V index(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_idx[v];\n    }\n\n    V operator[](V v) const noexcept {\n \
    \       assert(v < (V)size());\n        return m_idx[v];\n    }\n\n    V top(V\
    \ v) const noexcept {\n        assert(v < (V)size());\n        return m_top[v];\n\
    \    }\n\n    V bottom(V v) const noexcept {\n        assert(v < (V)size());\n\
    \        return m_bottom[m_top[v]];\n    }\n\n    std::pair<V, V> heavyPath(V\
    \ v) const {\n        assert(v < (V)size());\n        return {top(v), bottom(v)};\n\
    \    }\n\n    std::vector<std::pair<V, V>> decomp(V s, V t) const {\n        assert(s\
    \ < (V)size());\n        assert(t < (V)size());\n        std::vector<std::pair<V,\
    \ V>> res, ser;\n        while (m_top[s] != m_top[t]) {\n            if (m_dep[m_top[s]]\
    \ >= m_dep[m_top[t]]) {\n                res.emplace_back(s, m_top[s]);\n    \
    \            s = m_top[s];\n                if (m_par[s] != INVALID) s = m_par[s];\n\
    \            }\n            else {\n                ser.emplace_back(m_top[t],\
    \ t);\n                t = m_top[t];\n                if (m_par[t] != INVALID)\
    \ t = m_par[t];\n            }\n        }\n        res.emplace_back(s, t);\n \
    \       std::reverse(ser.begin(), ser.end());\n        res.insert(res.end(), ser.begin(),\
    \ ser.end()); \n        return res;\n    }\n\n    std::vector<std::pair<V, V>>\
    \ operator()(V s, V t) const {\n        return decomp(s, t);\n    }\n\n    V lca(V\
    \ u, V v) const {\n        assert(u < (V)size());\n        assert(v < (V)size());\n\
    \        while (m_top[u] != m_top[v]) {\n            if (m_dep[m_top[u]] >= m_dep[m_top[v]])\
    \ {\n                u = m_top[u];\n                if (m_par[u] != INVALID) u\
    \ = m_par[u];\n            }\n            else {\n                v = m_top[v];\n\
    \                if (m_par[v] != INVALID) v = m_par[v];\n            }\n     \
    \   }\n        return (m_dep[u] <= m_dep[v] ? u : v);\n    }\n\n    // is p ancestor\
    \ of v ?\n    bool isAncestor(V v, V p) const {\n        assert(v < size());\n\
    \        assert(p < size());\n        if (m_dep[v] < m_dep[p]) return false;\n\
    \        while (v != INVALID and m_top[v] != m_top[p]) {\n            v = m_par[m_top[v]];\n\
    \        }\n        return v != INVALID;\n    }\n\n    std::optional<V> levelAncestor(V\
    \ v, usize step) const {\n        assert(v < (V)size());\n        if (step > m_dep[v])\
    \ return std::nullopt;\n        while (true) {\n            usize dist{m_dep[v]\
    \ - m_dep[m_top[v]]};\n            if (dist >= step) break;\n            step\
    \ -= dist + 1;\n            v = m_par[m_top[v]];\n        }\n        step = (m_dep[v]\
    \ - m_dep[m_top[v]]) - step;\n        return m_inv[m_idx[m_top[v]] + step];\n\
    \    }\n\n    std::optional<V> jump(V s, V t, usize step) const {\n        assert(s\
    \ < (V)size());\n        assert(t < (V)size());\n        V uu{INVALID}, vv{INVALID};\n\
    \        usize d{};\n        for (auto [u, v] : decomp(s, t)) {\n            usize\
    \ dist{std::max(m_dep[u], m_dep[v]) - std::min(m_dep[u], m_dep[v])};\n       \
    \     if (dist >= step) {\n                uu = u;\n                vv = v;\n\
    \                d = dist;\n                break;\n            }\n          \
    \  step -= dist + 1;\n        }\n        if (uu == INVALID) return std::nullopt;\n\
    \        if (m_dep[uu] <= m_dep[vv])\n            return m_inv[m_idx[uu] + step];\n\
    \        else\n            return m_inv[m_idx[vv] + (d - step)];\n    }\n\n  \
    \  usize distance(V s, V t) const {\n        assert(s < (V)size());\n        assert(t\
    \ < (V)size());\n        usize res{};\n        for (auto [u, v] : decomp(s, t))\
    \ {\n            if (m_dep[u] > m_dep[v]) std::swap(u, v);\n            res +=\
    \ m_dep[v] - m_dep[u] + 1;\n        }\n        return --res;\n    }\n\nprivate:\n\
    \n    static constexpr V INVALID{static_cast<V>(-1)};\n\n    usize m_n{};\n\n\
    \    std::vector<V> m_par{}, m_top{}, m_idx{}, m_inv{}, m_bottom{};\n\n    std::vector<usize>\
    \ m_size{}, m_dep{};\n};\n\n} // namespace zawa\n#line 7 \"Test/LC/vertex_add_path_sum.test.cpp\"\
    \n\n#line 12 \"Test/LC/vertex_add_path_sum.test.cpp\"\n\nint main() {\n    using\
    \ namespace zawa; \n    SetFastIO();\n\n    int N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<int> A(N);\n    for (int& a : A) std::cin >> a;\n    std::vector<std::vector<int>>\
    \ T(N);\n    for (int _{} ; _ < N - 1 ; _++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        T[u].push_back(v);\n        T[v].push_back(u);\n       \
    \ // AddEdge(T, u, v);\n    }\n    HeavyLightDecomposition hld(T);\n    std::vector<long\
    \ long> init(N);\n    for (int v{} ; v < N ; v++) {\n        init[hld[v]] = A[v];\n\
    \    }\n    FenwickTree<AdditiveGroup<long long>> fen{init};\n    while (Q--)\
    \ {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n         \
    \   int p, x;\n            std::cin >> p >> x;\n            fen.operation(hld[p],\
    \ x);\n        }\n        else if (t == 1) {\n            int u, v;\n        \
    \    std::cin >> u >> v;\n            long long ans{};\n            for (auto\
    \ [u, v] : hld(u, v)) {\n                u = hld[u];\n                v = hld[v];\n\
    \                if (u > v) std::swap(u, v);\n                ans += fen.product(u,\
    \ v + 1);\n            }\n            std::cout << ans << '\\n';\n        }\n\
    \        else {\n            assert(false);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../Src/Template/IOSetting.hpp\"\n#include \"../../Src/DataStructure/FenwickTree/FenwickTree.hpp\"\
    \n#include \"../../Src/Algebra/Group/AdditiveGroup.hpp\"\n#include \"../../Src/Graph/Tree/HeavyLightDecomposition.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \nint main() {\n    using namespace zawa; \n    SetFastIO();\n\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int& a : A) std::cin\
    \ >> a;\n    std::vector<std::vector<int>> T(N);\n    for (int _{} ; _ < N - 1\
    \ ; _++) {\n        int u, v;\n        std::cin >> u >> v;\n        T[u].push_back(v);\n\
    \        T[v].push_back(u);\n        // AddEdge(T, u, v);\n    }\n    HeavyLightDecomposition\
    \ hld(T);\n    std::vector<long long> init(N);\n    for (int v{} ; v < N ; v++)\
    \ {\n        init[hld[v]] = A[v];\n    }\n    FenwickTree<AdditiveGroup<long long>>\
    \ fen{init};\n    while (Q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int p, x;\n            std::cin >> p >> x;\n \
    \           fen.operation(hld[p], x);\n        }\n        else if (t == 1) {\n\
    \            int u, v;\n            std::cin >> u >> v;\n            long long\
    \ ans{};\n            for (auto [u, v] : hld(u, v)) {\n                u = hld[u];\n\
    \                v = hld[v];\n                if (u > v) std::swap(u, v);\n  \
    \              ans += fen.product(u, v + 1);\n            }\n            std::cout\
    \ << ans << '\\n';\n        }\n        else {\n            assert(false);\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - Src/Template/IOSetting.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/FenwickTree/FenwickTree.hpp
  - Src/Algebra/Group/GroupConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  - Src/Algebra/Group/AdditiveGroup.hpp
  - Src/Graph/Tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: Test/LC/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2026-02-23 15:51:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/LC/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/Test/LC/vertex_add_path_sum.test.cpp
- /verify/Test/LC/vertex_add_path_sum.test.cpp.html
title: Test/LC/vertex_add_path_sum.test.cpp
---
