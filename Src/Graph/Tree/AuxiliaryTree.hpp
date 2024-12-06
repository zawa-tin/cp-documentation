#pragma once

#include "./LowestCommonAncestor.hpp"

#include <algorithm>

namespace zawa {

template <class V>
class AuxiliaryTree : public LowestCommonAncestor<V> {
public:
    using Super = LowestCommonAncestor<V>;

    AuxiliaryTree() = default;
    AuxiliaryTree(const std::vector<std::vector<V>>& T, V r = 0u) 
        : Super{ T, r }, T_(T.size()), dist_(T.size()), used_(T.size()) {}

    V construct(const std::vector<V>& vs) {
        assert(vs.size());
        clear();
        vs_ = vs;
        return build();
    }

    const std::vector<V>& operator[](V v) const {
        assert(Super::verify(v));
        return T_[v];
    }

    inline bool contains(V v) const {
        assert(Super::verify(v));
        return used_[v];
    }

    inline u32 parentEdgeLength(V v) const {
        assert(contains(v));
        return dist_[v];
    }

    std::vector<V> current() const {
        return vs_;
    }

private:
    std::vector<std::vector<V>> T_{}; 
    std::vector<V> vs_{};
    std::vector<u32> dist_{};
    std::vector<bool> used_{};

    void addEdge(V p, V v) {
        assert(Super::depth(p) < Super::depth(v));
        T_[p].push_back(v);
        T_[v].push_back(p);
        dist_[v] = Super::depth(v) - Super::depth(p);
    }

    V build() {
        std::sort(vs_.begin(), vs_.end(), [&](V u, V v) -> bool {
                return Super::left(u) < Super::left(v);
                });
        vs_.erase(std::unique(vs_.begin(), vs_.end()), vs_.end());
        usize k{vs_.size()};
        std::vector<V> stack;
        stack.reserve(2u * vs_.size());
        stack.emplace_back(vs_[0]);
        for (usize i{} ; i + 1 < k ; i++) {
            if (!Super::isAncestor(vs_[i], vs_[i + 1])) {
                V w{Super::lca(vs_[i], vs_[i + 1])};
                V l{stack.back()};
                stack.pop_back();
                while (stack.size() and LowestCommonAncestor<V>::depth(w) < LowestCommonAncestor<V>::depth(stack.back())) {
                    addEdge(stack.back(), l);
                    l = stack.back();
                    stack.pop_back();
                }
                if (stack.empty() or stack.back() != w) {
                    stack.emplace_back(w);
                    vs_.emplace_back(w);
                }
                addEdge(w, l);
            }
            stack.emplace_back(vs_[i + 1]);
        }
        while (stack.size() > 1u) {
            V l{stack.back()};
            stack.pop_back();
            addEdge(stack.back(), l);
        }
        for (V v : vs_) {
            used_[v] = true;
        }
        return stack.back();
    }

    void clear() {
        for (V v : vs_) {
            T_[v].clear();
            used_[v] = false;
            dist_[v] = 0u;
        }
        vs_.clear();
    }
};

} // namespace zawa
