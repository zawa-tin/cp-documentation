#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>

namespace zawa {

template <class CostType>
class Edge {
private:
    u32 from_, to_;
    CostType weight_;
    u32 id_;

public:
    Edge() = default;
    Edge(u32 from, u32 to, const CostType& weight, u32 id)
        : from_{ from }, to_{ to }, weight_{ weight }, id_{ id } {}

    inline u32 from() const noexcept {
        return from_;
    }

    inline u32 to() const noexcept {
        return to_;
    }

    inline CostType weight() const {
        return weight_;
    }

    inline u32 id() const noexcept {
        return id_;
    }

};

template <class CostType>
class AdjacentList {
private:
    using E = Edge<CostType>;

    usize n_, m_;
    std::vector<E> edges_;
    std::vector<std::vector<E>> g_;

public:
    AdjacentList() = default;
    AdjacentList(usize n) : n_{ n }, m_{}, g_(n) {}

    void addDirectedEdge(u32 from, u32 to, const CostType& weight = 1) {
        edges_.emplace_back(from, to, weight, m_);
        g_[from].emplace_back(from, to, weight, m_++);
    }

    void addUndirectedEdge(u32 u, u32 v, const CostType& weight = 1) {
        edges_.emplace_back(u, v, weight, m_);
        g_[u].emplace_back(u, v, weight, m_);
        g_[v].emplace_back(v, u, weight, m_++);
    }

    inline std::vector<E> operator[](u32 v) {
        assert(v < n_);
        return g_[v];
    }

    inline const std::vector<E>& operator[](u32 v) const {
        assert(v < n_);
        return g_[v];
    }

    inline usize sizeV() const noexcept {
        return n_;
    }

    inline usize sizeE() const noexcept {
        return m_;
    }

    inline std::vector<E> enumerateEdges() const {
        return edges_;
    }

    inline E getEdge(u32 i) const {
        assert(i < m_);
        return edges_[i];
    }
};

template <class CostType>
using Graph = AdjacentList<CostType>;

} // namespace zawa
