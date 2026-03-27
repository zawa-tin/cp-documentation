---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Graph/Tree/StaticTopTree.hpp
    title: Src/Graph/Tree/StaticTopTree.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc269_h.test.cpp
    title: Test/AtCoder/abc269_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/AtCoder/abc351_g.test.cpp
    title: Test/AtCoder/abc351_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Src/Graph/Tree/DynamicTreeDP.hpp\"\n\n#line 2 \"Src/Graph/Tree/StaticTopTree.hpp\"\
    \n\n#line 2 \"Src/Template/TypeAlias.hpp\"\n\n#include <cstdint>\n#include <cstddef>\n\
    \nnamespace zawa {\n\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing i128 = __int128_t;\n\nusing u8 = std::uint8_t;\n\
    using u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\
    \nusing usize = std::size_t;\n\n} // namespace zawa\n#line 4 \"Src/Graph/Tree/StaticTopTree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include <string>\n#include <tuple>\n\nnamespace zawa {\n\nusing STTGraph = std::vector<std::vector<std::pair<usize,\
    \ usize>>>;\n\nenum class STTOp {\n    Vertex,\n    AddVertex,\n    AddEdge,\n\
    \    Rake,\n    Compress\n};\nstd::string STTOpName(STTOp v) {\n    static std::string\
    \ name[]{\"Vertex\", \"AddVertex\", \"AddEdge\", \"Rake\", \"Compress\"};\n  \
    \  return name[static_cast<usize>(v)];\n}\n\nclass StaticTopTree {\nprivate:\n\
    \n    static constexpr u32 Bit = 30;\n    \n    static constexpr u32 Mask = (1\
    \ << Bit) - 1;\n\npublic:\n\n    static constexpr usize Empty = 0;\n\n    struct\
    \ Node {\n        STTOp type;\n        usize par;\n        u64 ch;\n        usize\
    \ invV, invE;\n        usize height;\n        inline usize operator[](usize i)\
    \ const {\n            assert(i < 2);\n            return i ? (ch >> Bit) : (ch\
    \ & Mask);\n        }\n    };\n\n    StaticTopTree() = default;\n\n    StaticTopTree(STTGraph\
    \ g, usize root) \n        : m_g{move(g)}, m_nodes(1), m_posVertex(m_g.size(),\
    \ Empty), m_posEdge(m_g.size(), Empty) {\n        removeParent(root, Empty);\n\
    \        hld(root);\n        m_nodes.reserve(m_g.size() << 1);\n        m_root\
    \ = dfs(root);\n    }\n\n    inline usize size() const {\n        return m_nodes.size();\n\
    \    }\n\n    inline usize root() const {\n        return m_root;\n    }\n\n \
    \   const Node& operator[](usize i) const {\n        assert(i < size());\n   \
    \     return m_nodes[i];\n    }\n\n    usize posVertex(usize v) const {\n    \
    \    assert(v < m_posVertex.size());\n        return m_posVertex[v];\n    }\n\n\
    \    usize posEdge(usize e) const {\n        assert(e < m_posEdge.size());\n \
    \       return m_posEdge[e];\n    }\n\nprivate:\n\n    STTGraph m_g;\n\n    std::vector<Node>\
    \ m_nodes;\n\n    std::vector<usize> m_posVertex, m_posEdge;\n\n    usize m_root;\n\
    \n    void removeParent(usize v, usize p) {\n        for (usize i = 0 ; i + 1\
    \ < m_g[v].size() ; ) {\n            if (m_g[v][i].first == p)\n             \
    \   swap(m_g[v][i], m_g[v].back());\n            else\n                removeParent(m_g[v][i++].first,\
    \ v);\n        }\n        if (m_g[v].size()) {\n            if (m_g[v].back().first\
    \ == p)\n                m_g[v].pop_back();\n            else\n              \
    \  removeParent(m_g[v].back().first, v);\n        }\n    }\n\n    usize hld(usize\
    \ v) {\n        if (m_g[v].empty())\n            return 1;\n        usize res\
    \ = 1, mx = 0, arg = 0;\n        for (usize i = 0 ; i < m_g[v].size() ; i++) {\n\
    \            usize ch = hld(m_g[v][i].first);\n            if (mx < ch) {\n  \
    \              arg = i;\n                mx = ch;\n            }\n           \
    \ res += ch;\n        }\n        if (arg)\n            std::swap(m_g[v][0], m_g[v][arg]);\n\
    \        return res;\n    }\n\n    usize makeNode(Node&& node) {\n        const\
    \ usize res = m_nodes.size();\n        m_nodes.push_back(std::move(node));\n \
    \       return res;\n    }\n\n    usize compressStrategy(const std::vector<std::pair<usize,\
    \ usize>>& path) {\n        assert(path.size());\n        std::vector<std::tuple<usize,\
    \ usize, usize>> stk;\n        stk.reserve(path.size());\n        auto merge =\
    \ [&]() {\n            auto [nr, vr, hr] = std::move(stk.back());\n          \
    \  stk.pop_back();\n            auto [nl, vl, hl] = std::move(stk.back());\n \
    \           stk.pop_back();\n            usize e = m_g[vl][0].second;\n      \
    \      usize h = std::max(hl, hr) + 1;\n            Node cur{STTOp::Compress,\
    \ Empty, nl | (u64{nr} << Bit), Empty, e, h};\n            usize merged = makeNode(std::move(cur));\n\
    \            m_posEdge[e] = m_nodes[nl].par = m_nodes[nr].par = merged;\n    \
    \        stk.emplace_back(merged, vr, h);\n        };\n        for (auto [nd,\
    \ v] : path) {\n            stk.push_back({nd, v, m_nodes[nd].height});\n    \
    \        while (true) {\n                usize len = stk.size();\n           \
    \     if (len >= 3 and (std::get<2>(stk[len - 3]) == std::get<2>(stk[len - 2])\
    \ or std::get<2>(stk[len - 3]) < std::get<2>(stk[len - 1]))) {\n             \
    \       auto tmp = std::move(stk.back());\n                    stk.pop_back();\n\
    \                    merge();\n                    stk.push_back(std::move(tmp));\n\
    \                }\n                else if (len >= 2 and std::get<2>(stk[len\
    \ - 2]) <= std::get<2>(stk[len - 1]))\n                    merge();\n        \
    \        else\n                    break;\n            }\n        }\n        while\
    \ (stk.size() >= 2)\n            merge();\n        return std::get<0>(stk.back());\n\
    \    }\n\n    usize rakeStrategy(usize v, const std::vector<usize>& ch) {\n  \
    \      if (ch.empty()) {\n            Node cur{STTOp::Vertex, Empty, 0, v, Empty,\
    \ 0};\n            return m_posVertex[v] = makeNode(std::move(cur));\n       \
    \ }\n        std::vector<std::pair<usize, usize>> stk;\n        auto merge = [&]()\
    \ {\n            auto [rnd, rh] = std::move(stk.back());\n            stk.pop_back();\n\
    \            auto [lnd, lh] = std::move(stk.back());\n            stk.pop_back();\n\
    \            usize h = std::max(lh, rh) + 1;\n            Node cur{STTOp::Rake,\
    \ Empty, lnd | (u64{rnd} << Bit), Empty, Empty, h};\n            usize merged\
    \ = makeNode(std::move(cur));\n            stk.emplace_back(m_nodes[lnd].par =\
    \ m_nodes[rnd].par = merged, h);\n        };\n        usize pd = [&]() -> usize\
    \ {\n            for (usize nd : ch) {\n                stk.push_back({nd, m_nodes[nd].height});\n\
    \                while (true) {\n                    usize len = stk.size();\n\
    \                    if (len >= 3 and (stk[len - 3].second == stk[len - 2].second\
    \ or stk[len - 3].second < stk[len - 1].second)) {\n                        auto\
    \ tmp = std::move(stk.back());\n                        stk.pop_back();\n    \
    \                    merge();\n                        stk.push_back(std::move(tmp));\n\
    \                    }\n                    else if (len >= 2 and stk[len - 2].second\
    \ <= stk[len - 1].second)\n                        merge();\n                \
    \    else\n                        break;\n                }\n            }\n\
    \            while (stk.size() >= 2)\n                merge();\n            return\
    \ stk.back().first;\n        }();\n        Node cur{STTOp::AddVertex, Empty, pd,\
    \ v, Empty, m_nodes[pd].height + 1};\n        return m_posVertex[v] = m_nodes[pd].par\
    \ = makeNode(std::move(cur));\n    }\n\n    usize dfs(usize v) {\n        std::vector<std::pair<usize,\
    \ usize>> path;\n        for ( ; ; v = m_g[v][0].first) {\n            path.emplace_back(dfsLight(v),\
    \ v);\n            if (m_g[v].empty())\n                break;\n        }\n  \
    \      return compressStrategy(path);\n    }\n\n    usize dfsLight(usize v) {\n\
    \        std::vector<usize> chs;\n        chs.reserve(m_g[v].size());\n      \
    \  for (usize i = 1 ; i < m_g[v].size() ; i++) {\n            const auto [x, e]\
    \ = m_g[v][i];\n            const usize nd = dfs(x);\n            Node cur{STTOp::AddEdge,\
    \ Empty, nd, Empty, e, m_nodes[nd].height + 1};\n            const usize ch =\
    \ makeNode(std::move(cur));\n            chs.push_back(m_posEdge[e] = m_nodes[nd].par\
    \ = ch);\n        }\n        return rakeStrategy(v, chs);\n    }\n};\n\n} // namespace\
    \ zawa\n#line 4 \"Src/Graph/Tree/DynamicTreeDP.hpp\"\n\n#include <concepts>\n\
    #include <variant>\n// #include <iostream>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T>\nconcept DynamicTreeDPInterface = requires {\n    typename\
    \ T::Vertex;\n    typename T::Edge;\n    typename T::PathCluster;\n    typename\
    \ T::PointCluster;\n    { T::vertex(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::PathCluster>;\n    { T::addVertex(std::declval<typename T::PointCluster>(),\
    \ std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;\n\
    \    { T::addEdge(std::declval<typename T::PathCluster>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::PointCluster>;\n    { T::rake(std::declval<typename\
    \ T::PointCluster>(), std::declval<typename T::PointCluster>()) } -> std::same_as<typename\
    \ T::PointCluster>;\n    { T::compress(std::declval<typename T::PathCluster>(),\
    \ std::declval<typename T::Edge>(), std::declval<typename T::PathCluster>()) }\
    \ -> std::same_as<typename T::PathCluster>;\n};\n\n} // namespace concepts\n\n\
    using DynamicTreeDPGraph = STTGraph;\n\ntemplate <concepts::DynamicTreeDPInterface\
    \ T>\nclass DynamicTreeDP {\npublic:\n\n    using Vertex = typename T::Vertex;\n\
    \n    using Edge = typename T::Edge;\n\n    using Path = typename T::PathCluster;\n\
    \n    using Point = typename T::PointCluster;\n\nprivate:\n\n    using Item =\
    \ std::variant<Path, Point>;\n\n    static constexpr usize PathId = 0;\n\n   \
    \ static constexpr usize PointId = 1;\n\npublic:\n\n    DynamicTreeDP() = default;\n\
    \n    DynamicTreeDP(const DynamicTreeDPGraph& g, usize root, std::vector<Vertex>\
    \ vs, std::vector<Edge> es)\n        : m_n{g.size()}, m_vs{vs}, m_es{es}, m_stt{g,\
    \ root}, m_dp(m_stt.size()) {\n        assert(g.size() == m_vs.size());\n    \
    \    assert(g.empty() or g.size() == m_es.size() + 1);\n        for (usize i =\
    \ 0 ; i < m_stt.size() ; i++)\n            if (i != StaticTopTree::Empty)\n  \
    \              recalc(i);\n        //std::cerr << \"STT's Height is \" << m_stt[m_stt.root()].height\
    \ << std::endl;\n    }\n\n    inline usize size() const {\n        return m_n;\n\
    \    }\n\n    Path operator()() const {\n        return std::get<PathId>(m_dp[m_stt.root()]);\n\
    \    }\n\n    const Vertex& getVertex(usize v) const {\n        assert(v < size());\n\
    \        return m_vs[v];\n    }\n\n    void assignVertex(usize v, Vertex val)\
    \ {\n        assert(v < size());\n        m_vs[v] = std::move(val);\n        recalcAncestor(m_stt.posVertex(v));\n\
    \    }\n\n    const Edge& getEdge(usize e) const {\n        assert(e < size());\n\
    \        return m_es[e];\n    }\n\n    void assignEdge(usize e, Edge val) {\n\
    \        assert(e < m_es.size());\n        m_es[e] = std::move(val);\n       \
    \ recalcAncestor(m_stt.posEdge(e));\n    }\n\n    template <class F>\n    void\
    \ visit(F f) const {\n        for (usize i = 0 ; i < m_stt.size() ; i++)\n   \
    \         if (i != StaticTopTree::Empty) {\n                const auto& node =\
    \ m_stt[i];\n                std::string name = STTOpName(node.type);\n      \
    \          usize par = node.par;\n                if (std::holds_alternative<Path>(m_dp[i]))\n\
    \                    f(i, name, par, std::get<PathId>(m_dp[i]));\n           \
    \     else\n                    f(i, name, par, std::get<PointId>(m_dp[i]));\n\
    \            }\n    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<Vertex>\
    \ m_vs;\n\n    std::vector<Edge> m_es;\n\n    StaticTopTree m_stt;\n\n    std::vector<Item>\
    \ m_dp;\n\n    void recalc(usize i) {\n        const StaticTopTree::Node& node\
    \ = m_stt[i];\n        switch (node.type) {\n        case STTOp::Vertex:\n   \
    \     {\n            const Vertex& v = m_vs[node.invV];\n            m_dp[i] =\
    \ Item{std::in_place_index<PathId>, T::vertex(v)};\n            break;\n     \
    \   }\n        case STTOp::AddVertex:\n        {\n            const Point& ch\
    \ = std::get<PointId>(m_dp[node[0]]);\n            const Vertex& v = m_vs[node.invV];\n\
    \            m_dp[i] = Item{std::in_place_index<PathId>, T::addVertex(ch, v)};\n\
    \            break;\n        }\n        case STTOp::AddEdge:\n        {\n    \
    \        const Path& ch = std::get<PathId>(m_dp[node[0]]);\n            const\
    \ Edge& e = m_es[node.invE];\n            m_dp[i] = Item{std::in_place_index<PointId>,\
    \ T::addEdge(ch, e)};\n            break;\n        }\n        case STTOp::Rake:\n\
    \        {\n            const Point& l = std::get<PointId>(m_dp[node[0]]);\n \
    \           const Point& r = std::get<PointId>(m_dp[node[1]]);\n            m_dp[i]\
    \ = Item{std::in_place_index<PointId>, T::rake(l, r)};\n            break;\n \
    \       }\n        case STTOp::Compress:\n        {\n            const Path& l\
    \ = std::get<PathId>(m_dp[node[0]]);\n            const Edge& e = m_es[node.invE];\n\
    \            const Path& r = std::get<PathId>(m_dp[node[1]]);\n            m_dp[i]\
    \ = Item{std::in_place_index<PathId>, T::compress(l, e, r)};\n            break;\n\
    \        }\n        default:\n            break;\n        }\n    }\n\n    void\
    \ recalcAncestor(usize i) {\n        for ( ; i != StaticTopTree::Empty ; i = m_stt[i].par)\n\
    \            recalc(i);\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"./StaticTopTree.hpp\"\n\n#include <concepts>\n\
    #include <variant>\n// #include <iostream>\n\nnamespace zawa {\n\nnamespace concepts\
    \ {\n\ntemplate <class T>\nconcept DynamicTreeDPInterface = requires {\n    typename\
    \ T::Vertex;\n    typename T::Edge;\n    typename T::PathCluster;\n    typename\
    \ T::PointCluster;\n    { T::vertex(std::declval<typename T::Vertex>()) } -> std::same_as<typename\
    \ T::PathCluster>;\n    { T::addVertex(std::declval<typename T::PointCluster>(),\
    \ std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;\n\
    \    { T::addEdge(std::declval<typename T::PathCluster>(), std::declval<typename\
    \ T::Edge>()) } -> std::same_as<typename T::PointCluster>;\n    { T::rake(std::declval<typename\
    \ T::PointCluster>(), std::declval<typename T::PointCluster>()) } -> std::same_as<typename\
    \ T::PointCluster>;\n    { T::compress(std::declval<typename T::PathCluster>(),\
    \ std::declval<typename T::Edge>(), std::declval<typename T::PathCluster>()) }\
    \ -> std::same_as<typename T::PathCluster>;\n};\n\n} // namespace concepts\n\n\
    using DynamicTreeDPGraph = STTGraph;\n\ntemplate <concepts::DynamicTreeDPInterface\
    \ T>\nclass DynamicTreeDP {\npublic:\n\n    using Vertex = typename T::Vertex;\n\
    \n    using Edge = typename T::Edge;\n\n    using Path = typename T::PathCluster;\n\
    \n    using Point = typename T::PointCluster;\n\nprivate:\n\n    using Item =\
    \ std::variant<Path, Point>;\n\n    static constexpr usize PathId = 0;\n\n   \
    \ static constexpr usize PointId = 1;\n\npublic:\n\n    DynamicTreeDP() = default;\n\
    \n    DynamicTreeDP(const DynamicTreeDPGraph& g, usize root, std::vector<Vertex>\
    \ vs, std::vector<Edge> es)\n        : m_n{g.size()}, m_vs{vs}, m_es{es}, m_stt{g,\
    \ root}, m_dp(m_stt.size()) {\n        assert(g.size() == m_vs.size());\n    \
    \    assert(g.empty() or g.size() == m_es.size() + 1);\n        for (usize i =\
    \ 0 ; i < m_stt.size() ; i++)\n            if (i != StaticTopTree::Empty)\n  \
    \              recalc(i);\n        //std::cerr << \"STT's Height is \" << m_stt[m_stt.root()].height\
    \ << std::endl;\n    }\n\n    inline usize size() const {\n        return m_n;\n\
    \    }\n\n    Path operator()() const {\n        return std::get<PathId>(m_dp[m_stt.root()]);\n\
    \    }\n\n    const Vertex& getVertex(usize v) const {\n        assert(v < size());\n\
    \        return m_vs[v];\n    }\n\n    void assignVertex(usize v, Vertex val)\
    \ {\n        assert(v < size());\n        m_vs[v] = std::move(val);\n        recalcAncestor(m_stt.posVertex(v));\n\
    \    }\n\n    const Edge& getEdge(usize e) const {\n        assert(e < size());\n\
    \        return m_es[e];\n    }\n\n    void assignEdge(usize e, Edge val) {\n\
    \        assert(e < m_es.size());\n        m_es[e] = std::move(val);\n       \
    \ recalcAncestor(m_stt.posEdge(e));\n    }\n\n    template <class F>\n    void\
    \ visit(F f) const {\n        for (usize i = 0 ; i < m_stt.size() ; i++)\n   \
    \         if (i != StaticTopTree::Empty) {\n                const auto& node =\
    \ m_stt[i];\n                std::string name = STTOpName(node.type);\n      \
    \          usize par = node.par;\n                if (std::holds_alternative<Path>(m_dp[i]))\n\
    \                    f(i, name, par, std::get<PathId>(m_dp[i]));\n           \
    \     else\n                    f(i, name, par, std::get<PointId>(m_dp[i]));\n\
    \            }\n    }\n\nprivate:\n\n    usize m_n;\n\n    std::vector<Vertex>\
    \ m_vs;\n\n    std::vector<Edge> m_es;\n\n    StaticTopTree m_stt;\n\n    std::vector<Item>\
    \ m_dp;\n\n    void recalc(usize i) {\n        const StaticTopTree::Node& node\
    \ = m_stt[i];\n        switch (node.type) {\n        case STTOp::Vertex:\n   \
    \     {\n            const Vertex& v = m_vs[node.invV];\n            m_dp[i] =\
    \ Item{std::in_place_index<PathId>, T::vertex(v)};\n            break;\n     \
    \   }\n        case STTOp::AddVertex:\n        {\n            const Point& ch\
    \ = std::get<PointId>(m_dp[node[0]]);\n            const Vertex& v = m_vs[node.invV];\n\
    \            m_dp[i] = Item{std::in_place_index<PathId>, T::addVertex(ch, v)};\n\
    \            break;\n        }\n        case STTOp::AddEdge:\n        {\n    \
    \        const Path& ch = std::get<PathId>(m_dp[node[0]]);\n            const\
    \ Edge& e = m_es[node.invE];\n            m_dp[i] = Item{std::in_place_index<PointId>,\
    \ T::addEdge(ch, e)};\n            break;\n        }\n        case STTOp::Rake:\n\
    \        {\n            const Point& l = std::get<PointId>(m_dp[node[0]]);\n \
    \           const Point& r = std::get<PointId>(m_dp[node[1]]);\n            m_dp[i]\
    \ = Item{std::in_place_index<PointId>, T::rake(l, r)};\n            break;\n \
    \       }\n        case STTOp::Compress:\n        {\n            const Path& l\
    \ = std::get<PathId>(m_dp[node[0]]);\n            const Edge& e = m_es[node.invE];\n\
    \            const Path& r = std::get<PathId>(m_dp[node[1]]);\n            m_dp[i]\
    \ = Item{std::in_place_index<PathId>, T::compress(l, e, r)};\n            break;\n\
    \        }\n        default:\n            break;\n        }\n    }\n\n    void\
    \ recalcAncestor(usize i) {\n        for ( ; i != StaticTopTree::Empty ; i = m_stt[i].par)\n\
    \            recalc(i);\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn:
  - Src/Graph/Tree/StaticTopTree.hpp
  - Src/Template/TypeAlias.hpp
  isVerificationFile: false
  path: Src/Graph/Tree/DynamicTreeDP.hpp
  requiredBy: []
  timestamp: '2025-12-03 17:47:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Test/AtCoder/abc269_h.test.cpp
  - Test/AtCoder/abc351_g.test.cpp
  - Test/LC/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: Src/Graph/Tree/DynamicTreeDP.hpp
layout: document
title: "Static Top Tree + \u6728DP"
---

## 雛形

```cpp
struct DP {
    using Vertex = ;
    using Edge = ;
    using PathCluster = ;
    using PointCluster = ;
    static PathCluster vertex(const Vertex&) {
    }
    static PathCluster addVertex(const PointCluster&, const Vertex&) {
    }
    static PointCluster addEdge(const PathCluster&, const Edge&) {
    }
    static PointCluster rake(const PointCluster, const PointCluster) {
    }
    static PathCluster compress(const PathCluster& p, const Edge& e, const PathCluster& c) {
    }
};
```

compressだけ引数の順番に注意。 $p$ が根に近いPath Cluster、 $c$ が根から離れたPath Cluster、 $e$ が間にあるHeavy Edgeに対応する。

```cpp
struct Printer {
    void operator()(int v, string type, int par, DP::PathCluster p) const {
    }
    void operator()(int v, string type, int par, DP::PointCluster p) const {
    }
};
```

この`operator()`を適切に定義し、`Printer`の実体を`visit`メンバに与えるとStatic Top Treeのすべてのノードを出力する。

ノード番号は1-indexであり、葉側にあるノードほど頂点番号が小さい。

なので、`DynamicTreeDP`を使わず`StaticTopTree`を用いてそのまま木dpなどを書くときは再帰をせずに $1$ から昇順にループを回せばよい。

- [Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)などの子側のデータを保持しておく必要がない時にこのようなことをするかもしれない

## ライブラリの使い方

```cpp
DynamicTreeDP(const DynamicTreeDPGraph& g, usize root, std::vector<Vertex> vs, std::vector<Edge> es)
```

`DynamicTreeDPGraph`とは`vector<vector<pair<usize, usize>>>`である。いつもの隣接リストで、`first`には接続先、`second`には辺番号を収める。

子から親方向への辺が存在していれば良い。両方向に辺が張られていても問題なく動作する。

`root`は根の頂点番号

`vs`は各頂点に対応する情報

`es`は各辺に対応する情報

他のメンバは実装見ればわかると思います。
