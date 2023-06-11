#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>

namespace zawa {

template <class CostType>
struct Edge {
    u32 from, to;
    CostType weight;
    u32 id;

    Edge() = default;
    Edge(u32 from_, u32 to_, const CostType& weight_, u32 id = -1)
        : from{ from_ }, to{ to_ }, weight{ weight_ }, id{ id } {}
};

template <class CostType>
class AdjacentList {
private:
    using E = Edge<CostType>;

    usize n, m;
    std::vector<E> edges;
    std::vector<std::vector<E>> g;

public:
    AdjacentList() = default;
    AdjacentList(usize n_) : n{ n_ }, m{}, g(n_) {}

    void addDirectedEdge(u32 from, u32 to, const CostType& weight = 1) {
        edges.emplace_back(from, to, weight, m);
        g[from].emplace_back(from, to, weight, m++);
    }

    void addUndirectedEdge(u32 u, u32 v, const CostType& weight = 1) {
        edges.emplace_back(u, v, weight, m);
        g[u].emplace_back(u, v, weight, m);
        g[v].emplace_back(v, u, weight, m++);
    }

    inline std::vector<E> operator[](u32 v) {
        assert(v < n);
        return g[v];
    }

    inline const std::vector<E>& operator[](u32 v) const {
        assert(v < n);
        return g[v];
    }

    inline usize sizeV() const {
        return n;
    }

    inline usize sizeE() const {
        return m;
    }

    inline std::vector<E> enumerateEdges() const {
        return edges;
    }

    inline E getEdge(u32 i) const {
        assert(i < m);
        return edges[i];
    }
};

template <class CostType>
using Graph = AdjacentList<CostType>;

} // namespace zawa
