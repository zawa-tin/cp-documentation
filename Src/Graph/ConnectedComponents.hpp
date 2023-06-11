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
    Graph<CostType> graph;
    std::vector<u32> id;
    usize countComponents;

    std::vector<std::vector<u32>> componentsV, componentsE;


public:
    ConnectedComponents() = default;
    ConnectedComponents(const Graph<CostType>& graph_) 
        : graph(graph_), id(graph_.sizeV()), countComponents{}, componentsV{}, componentsE{} {

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
                for (const auto& e : graph[v]) {
                    if (id[e.to] == inf) {
                        stk.push({ e.to, e.id });
                    }
                }
            }
        };

        for (u32 i = 0 ; i < graph.sizeV() ; i++) {
            if (id[i] < inf) continue;
            search(i);
            countComponents++;
        }

        componentsV.resize(countComponents);
        for (u32 i = 0 ; i < graph.sizeV() ; i++) {
            componentsV[id[i]].push_back(i);
        }
        componentsV.shrink_to_fit();
        for (auto& comp : componentsV) {
            comp.shrink_to_fit();
        }

        componentsE.resize(countComponents);
        for (u32 i = 0 ; i < graph.sizeE() ; i++) {
            componentsE[id[graph.getEdge(i).from]].push_back(i);
        }
        componentsE.shrink_to_fit();
        for (auto& comp : componentsE) {
            comp.shrink_to_fit();
        }
    }

    inline usize size() const {
        return countComponents;
    }

    inline usize sizeV(u32 i) const {
        assert(i < countComponents);
        return componentsV[i].size();
    }

    inline usize sizeE(u32 i) const {
        assert(i < countComponents);
        return componentsE[i].size();
    }

    inline u32 operator[](u32 v) const {
        assert(v < graph.sizeV());
        return id[v];
    }

    inline u32 getVId(u32 v) const {
        assert(v < graph.sizeV());
        return id[v];
    }   

    inline u32 getEId(u32 v) const {
        assert(v < graph.sizeE());
        return id[graph.getEdge(v).from];
    }   

    inline bool same(u32 u, u32 v) const {
        assert(u < graph.sizeV());
        assert(v < graph.sizeV());
        return id[u] == id[v];
    }

    inline std::vector<std::vector<u32>> enumerateV() const {
        return componentsV;
    }

    inline std::vector<u32> enumerateV(u32 i) const {
        assert(i < countComponents);
        return componentsV[i];
    }

    inline std::vector<std::vector<Edge<CostType>>> enumerateE() const {
        std::vector res(countComponents, std::vector<Edge<CostType>>());
        for (u32 i = 0 ; i < countComponents ; i++) {
            for (auto eid : componentsE[i]) {
                res[i].push_back(graph.getEdge(eid));
            }
        }
        return res;
    }

    inline std::vector<Edge<CostType>> enumerateE(u32 i) const {
        assert(i < countComponents);
        std::vector<CostType> res(componentsE[i].size());
        for (u32 j = 0 ; j < componentsE[i].size() ; j++) {
            res[j] = graph.getEdge(componentsE[i][j]);
        }
        return res;
    }

    inline bool hasCycle(u32 i) const {
        assert(i < countComponents);
        return sizeE(i) + 1 > sizeV(i);
    }
};

} // namespace zawa
