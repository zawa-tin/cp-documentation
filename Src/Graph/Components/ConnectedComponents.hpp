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
        const u32 u, v, id;
        Edge(u32 u, u32 v, u32 id) : u{ u }, v{ v }, id{ id } {}
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
        std::vector<u32> vs() const noexcept {
            return vs_;
        }
        std::vector<u32> es() const noexcept {
            return es_;
        }
        bool hasCycle() const {
            return not (n() == m() + 1);
        }
    };

    constexpr static u32 INVALID{ std::numeric_limits<u32>::max() };

    std::vector<std::vector<u32>> graph;
    std::vector<std::pair<u32, u32>> edges;

    std::vector<u32> colV, colE;
    std::vector<Component> components;

    bool isBuilt;

    void dfs(u32 s) {
        colV[s] = components.size();
        std::stack<u32> stk{ { s } };
        while (stk.size()) {
            u32 v{ stk.top() };
            stk.pop();
            for (auto x : graph[v]) {
                if (colV[x] == INVALID) {
                    colV[x] = components.size();
                    stk.push(x);
                }
            }
        }
    }

    void buildComponents() {
        std::vector<std::vector<u32>> vs(components.size()), es(components.size());
        for (u32 v{} ; v < n() ; v++) {
            vs[colV[v]].emplace_back(v);
        }
        for (u32 e{} ; e < m() ; e++) {
            es[colE[e]].emplace_back(e);
        }
        for (u32 i{} ; i < components.size() ; i++) {
            components[i] = Component(vs[i], es[i]);
        }
    }

public:
    ConnectedComponents() = default;

    ConnectedComponents(usize n) 
        : graph(n), edges{}, colV(n, INVALID), colE{}, components{}, isBuilt{} {
        graph.shrink_to_fit();
    }
    
    void addEdge(u32 u, u32 v) {
        assert(not isBuilt);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        edges.emplace_back(u, v);
    }

    inline usize n() const noexcept {
        return graph.size();
    }

    inline usize m() const noexcept {
        return edges.size();
    }

    Edge edge(u32 e) const {
        assert(e < m());
        return Edge{ edges[e].first, edges[e].second, e };
    }

    void build() {
        assert(not isBuilt);
        colV.shrink_to_fit();
        for (u32 v{} ; v < n() ; v++) {
            if (colV[v] == INVALID) {
                dfs(v);
                components.emplace_back();
            }
        }
        colE.resize(m());
        colE.shrink_to_fit();
        for (u32 e{} ; e < m() ; e++) {
            colE[e] = colV[edges[e].first];
        }
        buildComponents();
        isBuilt = true;
    }

    inline u32 operator[](const u32 v) const noexcept {
        assert(isBuilt);
        assert(v < n());
        return colV[v];
    }

    inline u32 colorV(u32 v) const noexcept {
        assert(isBuilt);
        assert(v < n());
        return colV[v];
    }

    inline u32 colorE(u32 e) const noexcept {
        assert(isBuilt);
        assert(e < m());
        return colE[e];
    }

    inline bool same(u32 u, u32 v) const noexcept {
        assert(isBuilt);
        assert(u < n());
        assert(v < n());
        return colV[u] == colV[v];
    }

    inline usize size() const noexcept {
        assert(isBuilt);
        return components.size();
    }

    inline usize n(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components[c].n();
    }

    inline std::vector<u32> vs(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components[c].vs();
    }

    inline usize m(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components[c].m();
    }

    inline std::vector<u32> es(u32 c) const noexcept {
        assert(isBuilt);
        assert(c < size());
        return components[c].es();
    }

    inline bool hasCycle(u32 c) const {
        assert(isBuilt);
        assert(c < size());
        return components[c].hasCycle();
    }

};

} // namespace zawa
