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

    usize N, M;
    std::vector<std::vector<E>> G;

public:
    AdjacentList() = default;
    AdjacentList(usize N) : N{ N }, M{ 0 }, G(N) {}

    void addDirectedEdge(u32 from, u32 to, const CostType& weight = 1) {
        G[from].emplace_back(from, to, weight, M++);
    }

    void addUndirectedEdge(u32 u, u32 v, const CostType& weight = 1) {
        G[u].emplace_back(u, v, weight, M);
        G[v].emplace_back(v, u, weight, M++);
    }

    inline std::vector<E> operator[](u32 v) {
        assert(v < N);
        return G[v];
    }

    inline const std::vector<E>& operator[](u32 v) const {
        assert(v < N);
        return G[v];
    }

    inline usize sizeV() const {
        return N;
    }

    inline usize sizeE() const {
        return M;
    }
};

template <class CostType>
using Graph = AdjacentList<CostType>;

} // namespace zawa
