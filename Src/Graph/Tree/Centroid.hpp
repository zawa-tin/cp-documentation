#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./Tree.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class Centroid {
public:

    using Vertex = u32;

    Centroid() = default;

    Centroid(const Tree& T) : T_{T}, size_(T_.size(), usize{1}) {}
    Centroid(Tree&& T) : T_{std::move(T)}, size_(T_.size(), usize{1}) {}

    inline usize size() const noexcept {
        return T_.size();
    }

    inline usize size(Vertex v) const noexcept {
        assert(v < size());
        return size_[v];
    }

    bool isRemoved(Vertex v) const noexcept {
        assert(v < size());
        return size_[v] == 0u;
    }

    void remove(Vertex v) noexcept {
        assert(v < size());
        size_[v] = 0u;
    }

    const std::vector<Vertex>& operator[](Vertex v) const noexcept {
        assert(v < size());
        return T_[v];
    }

    // @response: centroid of component which v belongs
    Vertex rooting(Vertex v) {
        assert(v < size());
        assert(!isRemoved(v));
        usize all{dfsSize(v, INVALID)};
        Vertex par{INVALID};
        bool fn{false};
        while (!fn) {
            fn = true;
            for (Vertex x : T_[v]) {
                if (x == par or isRemoved(x) or usize{2} * size_[x] <= all) {
                    continue;
                }
                fn = false;
                par = v;
                v = x;
                break;
            }
        }
        return v;
    }

    std::vector<Vertex> component(Vertex v) const {
        assert(v < size());
        assert(!isRemoved(v));
        std::vector<Vertex> res;
        dfsComponent(v, INVALID, res);
        return res;
    }

    std::vector<Vertex> adjlist(Vertex v) const {
        assert(v < size());
        std::vector<Vertex> res;
        res.reserve(T_[v].size());
        for (auto x : T_[v]) if (!isRemoved(x)) {
            res.emplace_back(x);
        }
        return res;
    }

private:
    static constexpr Vertex INVALID{static_cast<u32>(-1)};
    Tree T_{};
    std::vector<usize> size_{};

    usize dfsSize(Vertex v, u32 par) {
        size_[v] = 1u;
        for (Vertex x : T_[v]) if (x != par and !isRemoved(x)) {
            size_[v] += dfsSize(x, v);
        }
        return size_[v];
    }

    void dfsComponent(Vertex v, Vertex par, std::vector<Vertex>& comp) const {
        comp.emplace_back(v);
        for (Vertex x : T_[v]) if (x != par and !isRemoved(x)) {
            dfsComponent(x, v, comp);
        }
    }
};

} // namespace zawa
