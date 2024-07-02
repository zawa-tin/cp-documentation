#pragma once

#include "./Tree.hpp"
#include "./LowestCommonAncestor.hpp"

#include <algorithm>

namespace zawa {

class AuxiliaryTree : public LowestCommonAncestor {
public:
    using V = u32;
    AuxiliaryTree() = default;
    AuxiliaryTree(const Tree& T, V r = 0u) 
        : LowestCommonAncestor{ T, r }, T_(T.size()), dist_(T.size()), used_(T.size()) {}

    V construct(const std::vector<V>& vs) {
        assert(vs.size());
        clear();
        vs_ = vs;
        return build();
    }

    const std::vector<V>& operator[](V v) const {
        verify(v);
        return T_[v];
    }

    inline bool contains(V v) const {
        assert(verify(v));
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
    Tree T_{}; 
    std::vector<V> vs_{};
    std::vector<u32> dist_{};
    std::vector<bool> used_{};

    void addEdge(V p, V v) {
        assert(depth(p) < depth(v));
        AddEdge(T_, p, v);
        dist_[v] = depth(v) - depth(p);
    }

    V build() {
        std::sort(vs_.begin(), vs_.end(), [&](V u, V v) -> bool {
                return left(u) < left(v);
                });
        vs_.erase(std::unique(vs_.begin(), vs_.end()), vs_.end());
        V k{(V)vs_.size()};
        std::vector<V> stack;
        stack.reserve(2u * vs_.size());
        stack.emplace_back(vs_[0]);
        for (u32 i{} ; i + 1 < k ; i++) {
            if (!LowestCommonAncestor::isAncestor(vs_[i], vs_[i + 1])) {
                V w{LowestCommonAncestor::lca(vs_[i], vs_[i + 1])};
                V l{stack.back()};
                stack.pop_back();
                while (stack.size() and LowestCommonAncestor::depth(w) < LowestCommonAncestor::depth(stack.back())) {
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
