#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class V>
class Centroid {
public:

    Centroid() = default;

    Centroid(const std::vector<std::vector<V>>& T) : T_{T}, size_(T_.size(), usize{1}) {}
    Centroid(std::vector<std::vector<V>>&& T) : T_{std::move(T)}, size_(T_.size(), usize{1}) {}

    inline usize size() const noexcept {
        return T_.size();
    }

    inline usize size(V v) const noexcept {
        assert(v < (V)size());
        return size_[v];
    }

    bool isRemoved(V v) const noexcept {
        assert(v < (V)size());
        return size_[v] == 0u;
    }

    void remove(V v) noexcept {
        assert(v < (V)size());
        size_[v] = 0u;
    }

    const std::vector<V>& operator[](V v) const noexcept {
        assert(v < (V)size());
        return T_[v];
    }

    // @response: centroid of component which v belongs
    V rooting(V v) {
        assert(v < (V)size());
        assert(!isRemoved(v));
        usize all{dfsSize(v, INVALID)};
        V par{INVALID};
        bool fn{false};
        while (!fn) {
            fn = true;
            for (V x : T_[v]) {
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

    std::vector<V> component(V v) const {
        assert(v < (V)size());
        assert(!isRemoved(v));
        std::vector<V> res;
        dfsComponent(v, INVALID, res);
        return res;
    }

    std::vector<V> adjlist(V v) const {
        assert(v < (V)size());
        std::vector<V> res;
        res.reserve(T_[v].size());
        for (auto x : T_[v]) if (!isRemoved(x)) {
            res.emplace_back(x);
        }
        return res;
    }

private:
    static constexpr V INVALID{static_cast<V>(-1)};
    std::vector<std::vector<V>> T_{};
    std::vector<usize> size_{};

    usize dfsSize(V v, V par) {
        size_[v] = 1u;
        for (V x : T_[v]) if (x != par and !isRemoved(x)) {
            size_[v] += dfsSize(x, v);
        }
        return size_[v];
    }

    void dfsComponent(V v, V par, std::vector<V>& comp) const {
        comp.emplace_back(v);
        for (V x : T_[v]) if (x != par and !isRemoved(x)) {
            dfsComponent(x, v, comp);
        }
    }
};

} // namespace zawa
