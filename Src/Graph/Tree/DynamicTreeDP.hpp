#pragma once

#include "./StaticTopTree.hpp"

#include <concepts>
#include <variant>
#include <iostream>

namespace zawa {

namespace concepts {

template <class T>
concept DynamicTreeDPInterface = requires {
    typename T::Vertex;
    typename T::Edge;
    typename T::PathCluster;
    typename T::PointCluster;
    { T::vertex(std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;
    { T::addVertex(std::declval<typename T::PointCluster>(), std::declval<typename T::Vertex>()) } -> std::same_as<typename T::PathCluster>;
    { T::addEdge(std::declval<typename T::PathCluster>(), std::declval<typename T::Edge>()) } -> std::same_as<typename T::PointCluster>;
    { T::rake(std::declval<typename T::PointCluster>(), std::declval<typename T::PointCluster>()) } -> std::same_as<typename T::PointCluster>;
    { T::compress(std::declval<typename T::PathCluster>(), std::declval<typename T::Edge>(), std::declval<typename T::PathCluster>()) } -> std::same_as<typename T::PathCluster>;
};

} // namespace concepts

using DynamicTreeDPGraph = STTGraph;

template <concepts::DynamicTreeDPInterface T>
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

    DynamicTreeDP(const DynamicTreeDPGraph& g, usize root, std::vector<Vertex> vs, std::vector<Edge> es)
        : m_n{g.size()}, m_vs{vs}, m_es{es}, m_stt{g, root}, m_dp(m_stt.size()) {
        assert(g.size() == m_vs.size());
        assert(g.empty() or g.size() == m_es.size() + 1);
        for (usize i = 0 ; i < m_stt.size() ; i++)
            recalc(i);
        std::cerr << "STT's Height is " << m_stt[m_stt.root()].height << std::endl;
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
            const Point& ch = std::get<PointId>(m_dp[node.ch[0]]);
            const Vertex& v = m_vs[node.invV];
            m_dp[i] = Item{std::in_place_index<PathId>, T::addVertex(ch, v)};
            break;
        }
        case STTOp::AddEdge:
        {
            const Path& ch = std::get<PathId>(m_dp[node.ch[0]]);
            const Edge& e = m_es[node.invE];
            m_dp[i] = Item{std::in_place_index<PointId>, T::addEdge(ch, e)};
            break;
        }
        case STTOp::Rake:
        {
            const Point& l = std::get<PointId>(m_dp[node.ch[0]]);
            const Point& r = std::get<PointId>(m_dp[node.ch[1]]);
            m_dp[i] = Item{std::in_place_index<PointId>, T::rake(l, r)};
            break;
        }
        case STTOp::Compress:
        {
            const Path& l = std::get<PathId>(m_dp[node.ch[0]]);
            const Edge& e = m_es[node.invE];
            const Path& r = std::get<PathId>(m_dp[node.ch[1]]);
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
