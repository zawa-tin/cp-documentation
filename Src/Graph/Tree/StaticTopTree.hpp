#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <utility>
#include <vector>
#include <ostream>
#include <string>
#include <tuple>

namespace zawa {

using STTGraph = std::vector<std::vector<std::pair<usize, usize>>>;

enum class STTOp {
    Vertex,
    AddVertex,
    AddEdge,
    Rake,
    Compress
};
std::ostream& operator<<(std::ostream& os, STTOp v) {
    static std::string name[]{"Vertex", "AddVertex", "AddEdge", "Rake", "Compress"};
    os << name[static_cast<int>(v)];
    return os;
}

class StaticTopTree {
private:

    static constexpr u32 Bit = 30;
    
    static constexpr u32 Mask = (1 << Bit) - 1;

public:

    static constexpr usize Empty = 0;

    struct Node {
        STTOp type;
        usize par;
        u64 ch;
        usize invV, invE;
        usize height;
        inline usize operator[](usize i) const {
            assert(i < 2);
            return i ? (ch >> Bit) : (ch & Mask);
        }
    };

    StaticTopTree() = default;

    StaticTopTree(STTGraph g, usize root) 
        : m_nodes(1), m_posVertex(g.size(), Empty), m_posEdge(g.size(), Empty) {
        removeParent(g, root, Empty);
        hld(g, root);
        m_nodes.reserve(g.size() << 1);
        m_root = dfs(g, root);
    }

    inline usize size() const {
        return m_nodes.size();
    }

    inline usize root() const {
        return m_root;
    }

    const Node& operator[](usize i) const {
        assert(i < size());
        return m_nodes[i];
    }

    usize posVertex(usize v) const {
        assert(v < m_posVertex.size());
        return m_posVertex[v];
    }

    usize posEdge(usize e) const {
        assert(e < m_posEdge.size());
        return m_posEdge[e];
    }

private:

    std::vector<Node> m_nodes;

    std::vector<usize> m_posVertex, m_posEdge;

    usize m_root;

    void removeParent(STTGraph& g, usize v, usize p) {
        for (usize i = 0 ; i + 1 < g[v].size() ; ) {
            if (g[v][i].first == p)
                swap(g[v][i], g[v].back());
            else
                removeParent(g, g[v][i++].first, v);
        }
        if (g[v].size()) {
            if (g[v].back().first == p)
                g[v].pop_back();
            else
                removeParent(g, g[v].back().first, v);
        }
    }

    usize hld(STTGraph& g, usize v) {
        if (g[v].empty())
            return 1;
        usize res = hld(g, g[v][0].first), mx = res;
        for (usize i = 1 ; i < g[v].size() ; i++) {
            usize ch = hld(g, g[v][i].first);
            if (mx < ch) {
                swap(g[v][0], g[v][i]);
                mx = ch;
            }
            res += ch;
        }
        return ++res;
    }

    usize makeNode(Node&& node) {
        const usize res = m_nodes.size();
        m_nodes.push_back(std::move(node));
        return res;
    }

    usize compressStrategy(const STTGraph& g, const std::vector<std::pair<usize, usize>>& path) {
        assert(path.size());
        std::vector<std::tuple<usize, usize, usize>> stk;
        stk.reserve(path.size());
        auto merge = [&](auto&& l, auto&& r) {
            auto [nl, vl, hl] = std::move(l);
            auto [nr, vr, hr] = std::move(r);
            usize e = g[vl][0].second;
            usize h = std::max(hl, hr) + 1;
            Node cur{STTOp::Compress, Empty, nl | (u64{nr} << Bit), Empty, e, h};
            usize merged = makeNode(std::move(cur));
            m_posEdge[e] = m_nodes[nl].par = m_nodes[nr].par = merged;
            return std::tuple<usize, usize, usize>{merged, vr, h};
        };
        for (auto [nd, v] : path) {
            stk.push_back({nd, v, m_nodes[nd].height});
            while (true) {
                usize len = stk.size();
                if (len >= 3 and (std::get<2>(stk[len - 3]) == std::get<2>(stk[len - 2]) or std::get<2>(stk[len - 3]) < std::get<2>(stk[len - 1]))) {
                    auto tmp = std::move(stk.back());
                    stk.pop_back();
                    auto r = std::move(stk.back());
                    stk.pop_back();
                    auto l = std::move(stk.back());
                    stk.pop_back();
                    stk.push_back(merge(std::move(l), std::move(r)));
                    stk.push_back(std::move(tmp));
                }
                else if (len >= 2 and std::get<2>(stk[len - 2]) <= std::get<2>(stk[len - 1])) {
                    auto r = std::move(stk.back());
                    stk.pop_back();
                    auto l = std::move(stk.back());
                    stk.pop_back();
                    stk.push_back(merge(std::move(l), std::move(r)));
                }
                else
                    break;
            }
        }
        auto pd = std::move(stk.back());
        stk.pop_back();
        while (stk.size()) {
            auto tmp = merge(std::move(stk.back()), std::move(pd));
            pd = std::move(tmp);
            stk.pop_back();
        }
        return std::get<0>(pd);
    }

    usize rakeStrategy(usize v, const std::vector<usize> ch) {
        if (ch.empty()) {
            Node cur{STTOp::Vertex, Empty, 0, v, Empty, 0};
            return m_posVertex[v] = makeNode(std::move(cur));
        }
        auto merge = [&](auto&& l, auto&& r) -> std::pair<usize, usize> {
            usize h = std::max(l.second, r.second) + 1;
            Node cur{STTOp::Rake, Empty, l.first | (u64{r.first} << Bit), Empty, Empty, h};
            usize merged = makeNode(std::move(cur));
            return {m_nodes[l.first].par = m_nodes[r.first].par = merged, h};
        };
        usize pd = [&]() -> usize {
            std::vector<std::pair<usize, usize>> stk;
            for (usize nd : ch) {
                stk.push_back({nd, m_nodes[nd].height});
                while (true) {
                    usize len = stk.size();
                    if (len >= 3 and (stk[len - 3].second == stk[len - 2].second or stk[len - 3].second < stk[len - 1].second)) {
                        auto tmp = std::move(stk.back());
                        stk.pop_back();
                        auto r = std::move(stk.back());
                        stk.pop_back();
                        auto l = std::move(stk.back());
                        stk.pop_back();
                        stk.push_back(merge(l, r));
                        stk.push_back(std::move(tmp));
                    }
                    else if (len >= 2 and stk[len - 2].second <= stk[len - 1].second) {
                        auto r = std::move(stk.back());
                        stk.pop_back();
                        auto l = std::move(stk.back());
                        stk.pop_back();
                        stk.push_back(merge(l, r));
                    }
                    else
                        break;
                }
            }
            auto res = std::move(stk.back());
            stk.pop_back();
            while (stk.size()) {
                auto tmp = merge(std::move(stk.back()), std::move(res));
                res = std::move(tmp);
                stk.pop_back();
            }
            return res.first;
        }();
        Node cur{STTOp::AddVertex, Empty, pd, v, Empty, m_nodes[pd].height + 1};
        return m_posVertex[v] = m_nodes[pd].par = makeNode(std::move(cur));
    }

    usize dfs(const STTGraph& g, usize v) {
        std::vector<std::pair<usize, usize>> path;
        for ( ; ; v = g[v][0].first) {
            path.emplace_back(dfsLight(g, v), v);
            if (g[v].empty())
                break;
        }
        return compressStrategy(g, path);
    }

    usize dfsLight(const STTGraph& g, usize v) {
        std::vector<usize> chs;
        chs.reserve(g[v].size());
        for (usize i = 1 ; i < g[v].size() ; i++) {
            const auto [x, e] = g[v][i];
            const usize nd = dfs(g, x);
            Node cur{STTOp::AddEdge, Empty, nd, Empty, e, m_nodes[nd].height + 1};
            const usize ch = makeNode(std::move(cur));
            chs.push_back(m_posEdge[e] = m_nodes[nd].par = ch);
        }
        return rakeStrategy(v, chs);
    }
};

} // namespace zawa
