#pragma once

#include "../Template/TypeAlias.hpp"
#include "./Basis/AdjacentList.hpp"

#include <vector>
#include <cassert>
#include <limits>
#include <algorithm>
#include <utility>
#include <stack>

namespace zawa {

template <class CostType = u32>
class ConnectedComponents {
private:
    Graph<CostType> G;
    std::vector<u32> id;
    std::vector<bool> cycle;
    usize countComponents;

    std::vector<std::vector<u32>> componentsV;
    std::vector<std::vector<Edge<u32>>> componentsE;


public:
    ConnectedComponents() = default;
    ConnectedComponents(const Graph<CostType>& G_) 
        : G(G_), id(G_.sizeV()), cycle(G_.sizeV()), countComponents{}, componentsV{}, componentsE{} {

        const u32 inf = std::numeric_limits<u32>::max();

        std::fill(id.begin(), id.end(), inf);
        id.shrink_to_fit();


        auto search = [&](u32 s) -> void {
            std::stack<std::pair<u32, u32>> stk;
            stk.push({ s, inf }); 
            while (stk.size()) {
                auto [v, eid] = stk.top();
                stk.pop();
                id[v] = countComponents;
                for (const auto& e : G[v]) {
                    if (e.id == eid) continue;
                    if (id[e.to] != inf) {
                        cycle[countComponents] = true;
                    }
                    else {
                        stk.push({ e.to, e.id });
                    }
                }
            }
        };

        for (u32 i = 0 ; i < G.sizeV() ; i++) {
            if (id[i] < inf) continue;
            cycle.push_back(false);
            search(i);
            countComponents++;
        }

        cycle.shrink_to_fit();

        componentsV.resize(countComponents);
        for (u32 i = 0 ; i < G.sizeV() ; i++) {
            componentsV[id[i]].push_back(i);
        }
        componentsV.shrink_to_fit();
        for (auto& comp : componentsV) {
            comp.shrink_to_fit();
        }

        componentsE.resize(countComponents);
        for (u32 i = 0 ; i < G.sizeV() ; i++) {
            componentsE[id[i]].push_back(i);
        }
        components.shrink_to_fit();
        for (auto& comp : components) {
            comp.shrink_to_fit();
        }
    }

    inline usize size() const {
        return countComponents;
    }

    inline usize size(u32 i) const {
        assert(i < countComponents);
        return components[i].size();
    }

    inline u32 operator[](u32 v) const {
        assert(v < G.sizeV());
        return id[v];
    }

    inline u32 getId(u32 v) const {
        assert(v < G.sizeV());
        return id[v];
    }   

    inline bool same(u32 u, u32 v) const {
        assert(u < G.sizeV());
        assert(v < G.sizeV());
        return id[u] == id[v];
    }

    inline bool hasCycle(u32 i) const {
        assert(i < countComponents);
        return cycle[i];
    }

    inline std::vector<std::vector<u32>> enumerate() const {
        return components;
    }

    inline std::vector<u32> enumerate(u32 i) const {
        assert(i < countComponents);
        return components[i];
    }
};

} // namespace zawa
