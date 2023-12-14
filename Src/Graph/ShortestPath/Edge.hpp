#pragma once

#include "../../Template/TypeAlias.hpp"

namespace zawa {

namespace internal {

class Edge {
protected:
    static constexpr u32 INVALID{static_cast<u32>(-1)};
public:
    u32 parent{INVALID}; 
    u32 id{INVALID};
    Edge() = default;
    Edge(u32 parent, u32 id) : parent{parent}, id{id} {}
    Edge& operator=(const Edge& edge) {
        parent = edge.parent;
        id = edge.id;
        return *this;
    }
    inline bool exist() const noexcept {
        return parent != INVALID;
    }
    static constexpr u32 invalid() noexcept {
        return INVALID; 
    }
};

template <class Weight>
class WeightedEdge : public Edge {
public:
    Weight weight{INVALID};
    WeightedEdge() = default;
    WeightedEdge(u32 parent, const Weight& weight, u32 id)
        : Edge{parent, id}, weight{weight} {}

    WeightedEdge& operator=(const WeightedEdge& edge) {
        parent = edge.parent;
        id = edge.id;
        weight = edge.weight;
        return *this;
    }

};

} // namespace internal

} // namespace zawa
