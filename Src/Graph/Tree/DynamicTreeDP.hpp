#pragma once

#include "./StaticTopTree.hpp"
#include "./STTDPInterface.hpp"

#include <concepts>
#include <variant>
#include <vector>

namespace zawa {

using DynamicTreeDPGraph = STTGraph;

template <concepts::STTDPInterface T>
class DynamicTreeDP {
public:

    using Vertex = typename T::Vertex;

    using Edge = typename T::Edge;

    using Path = typename T::PathCluster;

    using Point = typename T::PointCluster;

private:

    using Item = std::variant<Path, Point>;

    static constexpr usize PathId = 0;

    static constexpr usize PointId = 1;

public:

    DynamicTreeDP() = default;

    DynamicTreeDP(DynamicTreeDPGraph g, usize root, std::vector<Vertex> vs, std::vector<Edge> es)
        : m_n{g.size()}, m_vs{std::move(vs)}, m_es{std::move(es)}, m_stt{std::move(g), root}, m_dp(m_stt.size()) {
        assert(m_n == m_vs.size());
        assert(m_n == m_es.size() + 1);
        for (usize i = 0 ; i < m_stt.size() ; i++)
            if (i != StaticTopTree::Empty)
                recalc(i);
        //std::cerr << "STT's Height is " << m_stt[m_stt.root()].height << std::endl;
    }

    inline usize size() const {
        return m_n;
    }

    Path operator()() const {
        return std::get<PathId>(m_dp[m_stt.root()]);
    }

    const Vertex& getVertex(usize v) const {
        assert(v < size());
        return m_vs[v];
    }

    void assignVertex(usize v, Vertex val) {
        assert(v < size());
        m_vs[v] = std::move(val);
        recalcAncestor(m_stt.posVertex(v));
    }

    const Edge& getEdge(usize e) const {
        assert(e < size());
        return m_es[e];
    }

    void assignEdge(usize e, Edge val) {
        assert(e < m_es.size());
        m_es[e] = std::move(val);
        recalcAncestor(m_stt.posEdge(e));
    }

    template <class F>
    void visit(F f) const {
        for (usize i = 0 ; i < m_stt.size() ; i++)
            if (i != StaticTopTree::Empty) {
                const auto& node = m_stt[i];
                std::string name = STTOpName(node.type);
                usize par = node.par;
                if (std::holds_alternative<Path>(m_dp[i]))
                    f(i, name, par, std::get<PathId>(m_dp[i]));
                else
                    f(i, name, par, std::get<PointId>(m_dp[i]));
            }
    }

private:

    usize m_n;

    std::vector<Vertex> m_vs;

    std::vector<Edge> m_es;

    StaticTopTree m_stt;

    std::vector<Item> m_dp;

    void recalc(usize i) {
        const StaticTopTree::Node& node = m_stt[i];
        switch (node.type) {
        case STTOp::Vertex:
        {
            const Vertex& v = m_vs[node.invV];
            m_dp[i] = Item{std::in_place_index<PathId>, T::vertex(v)};
            break;
        }
        case STTOp::AddVertex:
        {
            const Point& ch = std::get<PointId>(m_dp[node[0]]);
            const Vertex& v = m_vs[node.invV];
            m_dp[i] = Item{std::in_place_index<PathId>, T::addVertex(ch, v)};
            break;
        }
        case STTOp::AddEdge:
        {
            const Path& ch = std::get<PathId>(m_dp[node[0]]);
            const Edge& e = m_es[node.invE];
            m_dp[i] = Item{std::in_place_index<PointId>, T::addEdge(ch, e)};
            break;
        }
        case STTOp::Rake:
        {
            const Point& l = std::get<PointId>(m_dp[node[0]]);
            const Point& r = std::get<PointId>(m_dp[node[1]]);
            m_dp[i] = Item{std::in_place_index<PointId>, T::rake(l, r)};
            break;
        }
        case STTOp::Compress:
        {
            const Path& l = std::get<PathId>(m_dp[node[0]]);
            const Edge& e = m_es[node.invE];
            const Path& r = std::get<PathId>(m_dp[node[1]]);
            m_dp[i] = Item{std::in_place_index<PathId>, T::compress(l, e, r)};
            break;
        }
        default:
            break;
        }
    }

    void recalcAncestor(usize i) {
        for ( ; i != StaticTopTree::Empty ; i = m_stt[i].par)
            recalc(i);
    }

};

} // namespace zawa
