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
        : m_g{move(g)}, m_nodes(1), m_posVertex(m_g.size(), Empty), m_posEdge(m_g.size(), Empty) {
        removeParent(root, Empty);
        hld(root);
        m_nodes.reserve(m_g.size() << 1);
        m_root = dfs(root);
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

    STTGraph m_g;

    std::vector<Node> m_nodes;

    std::vector<usize> m_posVertex, m_posEdge;

    usize m_root;

    void removeParent(usize v, usize p) {
        for (usize i = 0 ; i + 1 < m_g[v].size() ; ) {
            if (m_g[v][i].first == p)
                swap(m_g[v][i], m_g[v].back());
            else
                removeParent(m_g[v][i++].first, v);
        }
        if (m_g[v].size()) {
            if (m_g[v].back().first == p)
                m_g[v].pop_back();
            else
                removeParent(m_g[v].back().first, v);
        }
    }

    usize hld(usize v) {
        if (m_g[v].empty())
            return 1;
        usize res = 1, mx = 0, arg = 0;
        for (usize i = 0 ; i < m_g[v].size() ; i++) {
            usize ch = hld(m_g[v][i].first);
            if (mx < ch) {
                arg = i;
                mx = ch;
            }
            res += ch;
        }
        if (arg)
            std::swap(m_g[v][0], m_g[v][arg]);
        return res;
    }

    usize makeNode(Node&& node) {
        const usize res = m_nodes.size();
        m_nodes.push_back(std::move(node));
        return res;
    }

    usize compressStrategy(const std::vector<std::pair<usize, usize>>& path) {
        assert(path.size());
        std::vector<std::tuple<usize, usize, usize>> stk;
        stk.reserve(path.size());
        auto merge = [&]() {
            auto [nr, vr, hr] = std::move(stk.back());
            stk.pop_back();
            auto [nl, vl, hl] = std::move(stk.back());
            stk.pop_back();
            usize e = m_g[vl][0].second;
            usize h = std::max(hl, hr) + 1;
            Node cur{STTOp::Compress, Empty, nl | (u64{nr} << Bit), Empty, e, h};
            usize merged = makeNode(std::move(cur));
            m_posEdge[e] = m_nodes[nl].par = m_nodes[nr].par = merged;
            stk.emplace_back(merged, vr, h);
        };
        for (auto [nd, v] : path) {
            stk.push_back({nd, v, m_nodes[nd].height});
            while (true) {
                usize len = stk.size();
                if (len >= 3 and (std::get<2>(stk[len - 3]) == std::get<2>(stk[len - 2]) or std::get<2>(stk[len - 3]) < std::get<2>(stk[len - 1]))) {
                    auto tmp = std::move(stk.back());
                    stk.pop_back();
                    merge();
                    stk.push_back(std::move(tmp));
                }
                else if (len >= 2 and std::get<2>(stk[len - 2]) <= std::get<2>(stk[len - 1]))
                    merge();
                else
                    break;
            }
        }
        while (stk.size() >= 2)
            merge();
        return std::get<0>(stk.back());
    }

    usize rakeStrategy(usize v, const std::vector<usize> ch) {
        if (ch.empty()) {
            Node cur{STTOp::Vertex, Empty, 0, v, Empty, 0};
            return m_posVertex[v] = makeNode(std::move(cur));
        }
        std::vector<std::pair<usize, usize>> stk;
        auto merge = [&]() {
            auto [rnd, rh] = std::move(stk.back());
            stk.pop_back();
            auto [lnd, lh] = std::move(stk.back());
            stk.pop_back();
            usize h = std::max(lh, rh) + 1;
            Node cur{STTOp::Rake, Empty, lnd | (u64{rnd} << Bit), Empty, Empty, h};
            usize merged = makeNode(std::move(cur));
            stk.emplace_back(m_nodes[lnd].par = m_nodes[rnd].par = merged, h);
        };
        usize pd = [&]() -> usize {
            for (usize nd : ch) {
                stk.push_back({nd, m_nodes[nd].height});
                while (true) {
                    usize len = stk.size();
                    if (len >= 3 and (stk[len - 3].second == stk[len - 2].second or stk[len - 3].second < stk[len - 1].second)) {
                        auto tmp = std::move(stk.back());
                        stk.pop_back();
                        merge();
                        stk.push_back(std::move(tmp));
                    }
                    else if (len >= 2 and stk[len - 2].second <= stk[len - 1].second)
                        merge();
                    else
                        break;
                }
            }
            while (stk.size() >= 2)
                merge();
            return stk.back().first;
        }();
        Node cur{STTOp::AddVertex, Empty, pd, v, Empty, m_nodes[pd].height + 1};
        return m_posVertex[v] = m_nodes[pd].par = makeNode(std::move(cur));
    }

    usize dfs(usize v) {
        std::vector<std::pair<usize, usize>> path;
        for ( ; ; v = m_g[v][0].first) {
            path.emplace_back(dfsLight(v), v);
            if (m_g[v].empty())
                break;
        }
        return compressStrategy(path);
    }

    usize dfsLight(usize v) {
        std::vector<usize> chs;
        chs.reserve(m_g[v].size());
        for (usize i = 1 ; i < m_g[v].size() ; i++) {
            const auto [x, e] = m_g[v][i];
            const usize nd = dfs(x);
            Node cur{STTOp::AddEdge, Empty, nd, Empty, e, m_nodes[nd].height + 1};
            const usize ch = makeNode(std::move(cur));
            chs.push_back(m_posEdge[e] = m_nodes[nd].par = ch);
        }
        return rakeStrategy(v, chs);
    }
};

} // namespace zawa
