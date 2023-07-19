#pragma once

#include "../../Template/TypeAlias.hpp"

#include <limits>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#include <cassert>

namespace zawa {

class ConnectedComponents {
public:
    struct Edge {
    private:
        u32 u_, v_, id_;
    public:
        Edge(u32 u, u32 v, u32 id) : u_{ u }, v_{ v }, id_{ id } {}

        inline u32 u() const noexcept {
            return u_;
        }
        inline u32 v() const noexcept {
            return v_;
        }
        inline u32 id() const noexcept {
            return id_;
        }
    };

private:
    class Component {
    private:
        std::vector<u32> vs_, es_;
    public:
        Component() = default;
        Component(const std::vector<u32>& vs, const std::vector<u32>& es) : vs_{ vs }, es_{ es } {
            vs_.shrink_to_fit();
            es_.shrink_to_fit();
        }
        
        inline usize n() const noexcept {
            return vs_.size();
        }
        inline usize m() const noexcept {
            return es_.size();
        }
        const std::vector<u32>& vs() const noexcept {
            return vs_;
        }
        const std::vector<u32>& es() const noexcept {
            return es_;
        }
        bool hasCycle() const {
            return not (n() == m() + 1);
        }
    };

    constexpr static u32 INVALID_{ std::numeric_limits<u32>::max() };

    std::vector<std::vector<u32>> graph_;
    std::vector<std::pair<u32, u32>> edges_;

    std::vector<u32> indexV_, indexE_;
    std::vector<Component> components_;

    bool isBuilt;

    void dfs(u32 s) {
        indexV_[s] = components_.size();
        std::stack<u32> stk{ { s } };
        while (stk.size()) {
            u32 v{ stk.top() };
            stk.pop();
            for (auto x : graph_[v]) {
                if (indexV_[x] == INVALID_) {
                    indexV_[x] = components_.size();
                    stk.push(x);
                }
            }
        }
    }

    void buildComponents() {
        std::vector<std::vector<u32>> vs(components_.size()), es(components_.size());
        for (u32 v{} ; v < n() ; v++) {
            vs[indexV_[v]].emplace_back(v);
        }
        for (u32 e{} ; e < m() ; e++) {
            es[indexE_[e]].emplace_back(e);
        }
        for (u32 i{} ; i < components_.size() ; i++) {
            components_[i] = Component(vs[i], es[i]);
        }
        components_.shrink_to_fit();
    }

public:
    ConnectedComponents() = default;

    ConnectedComponents(usize n) 
        : graph_(n), edges_{}, indexV_(n, INVALID_), indexE_{}, components_{}, isBuilt{} {
        graph_.shrink_to_fit();
    }
    
    void addEdge(u32 u, u32 v) {
        assert(not isBuilt);
        graph_[u].emplace_back(v);
        graph_[v].emplace_back(u);
        edges_.emplace_back(u, v);
    }

    inline usize n() const noexcept {
        return graph_.size();
    }

    inline usize m() const noexcept {
        return edges_.size();
    }

    Edge edge(u32 e) const {
        assert(e < m());
        return Edge{ edges_[e].first, edges_[e].second, e };
    }

    void build() {
        assert(not isBuilt);
        edges_.shrink_to_fit();
        indexV_.shrink_to_fit();
        for (u32 v{} ; v < n() ; v++) {
            if (indexV_[v] == INVALID_) {
                dfs(v);
                components_.emplace_back();
            }
        }
        indexE_.resize(m());
        indexE_.shrink_to_fit();
        for (u32 e{} ; e < m() ; e++) {
            indexE_[e] = indexV_[edges_[e].first];
        }
        buildComponents();
        isBuilt = true;
    }

    inline u32 operator[](const u32 v) const noexcept {
        assert(isBuilt);
        assert(v < n());
        return indexV_[v];
    }

    inline u32 indexV(u32 v) const noexcept {
        assert(isBuilt);
        assert(v < n());
        return indexV_[v];
    }

    inline u32 indexE(u32 e) const noexcept {
        assert(isBuilt);
        assert(e < m());
        return indexE_[e];
    }

    inline bool same(u32 u, u32 v) const noexcept {
        assert(isBuilt);
        assert(u < n());
        assert(v < n());
        return indexV_[u] == indexV_[v];
    }

    inline usize size() const noexcept {
        assert(isBuilt);
        return components_.size();
    }

    inline usize n(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components_[c].n();
    }

    inline const std::vector<u32>& vs(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components_[c].vs();
    }

    inline usize m(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components_[c].m();
    }

    inline const std::vector<u32>& es(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components_[c].es();
    }

    inline bool hasCycle(u32 c) const {
        assert(isBuilt);
        assert(c < size());
        return components_[c].hasCycle();
    }

};

} // namespace zawa
