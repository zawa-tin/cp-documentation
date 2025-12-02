#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>
#include <ostream>
#include <string>

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
public:

    static constexpr usize Empty = std::numeric_limits<usize>::max();

    struct Node {
        STTOp type;
        usize par;
        std::array<usize, 2> ch;
        usize invV, invE;
        usize height;
    };

    StaticTopTree() = default;

    StaticTopTree(STTGraph g, usize root) 
        : m_nodes{}, m_posVertex(g.size(), Empty), m_posEdge(g.size(), Empty) {
        removeParent(g, root, Empty);
        hld(g, root);
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
        auto rec = [&](auto rec, usize l, usize r) -> std::pair<usize, usize> {
            assert(l < r);
            if (l + 1 == r)
                return path[l];
            usize m = (l + r) / 2;
            auto [lnd, lv] = rec(rec, l, m);
            auto [rnd, rv] = rec(rec, m, r);
            const usize e = g[lv][0].second;
            Node cur{STTOp::Compress, Empty, {lnd, rnd}, Empty, e, std::max(m_nodes[lnd].height, m_nodes[rnd].height) + 1};
            const usize merged = makeNode(std::move(cur));
            m_posEdge[e] = m_nodes[lnd].par = m_nodes[rnd].par = merged;
            return {merged, rv};
        };
        return rec(rec, 0, path.size()).first;
    }

    usize rakeStrategy(usize v, const std::vector<usize> ch) {
        if (ch.empty()) {
            Node cur{STTOp::Vertex, Empty, {Empty, Empty}, v, Empty, 0};
            return m_posVertex[v] = makeNode(std::move(cur));
        }
        auto rec = [&](auto rec, usize l, usize r) -> usize {
            assert(l < r);
            if (l + 1 == r)
                return ch[l];
            usize m = (l + r) / 2;
            usize lnd = rec(rec, l, m), rnd = rec(rec, m, r);
            Node cur{STTOp::Rake, Empty, {lnd, rnd}, v, Empty, std::max(m_nodes[lnd].height, m_nodes[rnd].height) + 1};
            const usize merged = makeNode(std::move(cur));
            return m_nodes[lnd].par = m_nodes[rnd].par = merged;
        };
        usize pd = rec(rec, 0, ch.size());
        Node cur{STTOp::AddVertex, Empty, {pd, Empty}, v, Empty, m_nodes[pd].height + 1};
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
            Node cur{STTOp::AddEdge, Empty, {nd, Empty}, Empty, e, m_nodes[nd].height + 1};
            const usize ch = makeNode(std::move(cur));
            chs.push_back(m_posEdge[e] = m_nodes[nd].par = ch);
        }
        return rakeStrategy(v, chs);
    }
};

} // namespace zawa
