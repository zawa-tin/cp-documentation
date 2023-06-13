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
    Graph<CostType> graph_;
    std::vector<u32> id_;
    usize countComponents_;

    std::vector<std::vector<u32>> componentsV_, componentsE_;


public:
    ConnectedComponents() = default;
    ConnectedComponents(const Graph<CostType>& graph) 
        : graph_(graph), id_(graph.sizeV()), countComponents_{}, componentsV_{}, componentsE_{} {

        const u32 inf = std::numeric_limits<u32>::max();

        std::fill(id_.begin(), id_.end(), inf);
        id_.shrink_to_fit();


        auto search = [&](u32 s) -> void {
            std::stack<std::pair<u32, u32>> stk;
            stk.push({ s, inf }); 
            while (stk.size()) {
                auto [v, eid] = stk.top();
                stk.pop();
                id_[v] = countComponents_;
                for (const auto& e : graph_[v]) {
                    if (id_[e.to()] == inf) {
                        stk.push({ e.to(), e.id() });
                    }
                }
            }
        };

        for (u32 i = 0 ; i < graph_.sizeV() ; i++) {
            if (id_[i] < inf) continue;
            search(i);
            countComponents_++;
        }

        componentsV_.resize(countComponents_);
        for (u32 i = 0 ; i < graph_.sizeV() ; i++) {
            componentsV_[id_[i]].push_back(i);
        }
        componentsV_.shrink_to_fit();
        for (auto& comp : componentsV_) {
            comp.shrink_to_fit();
        }

        componentsE_.resize(countComponents_);
        for (u32 i = 0 ; i < graph_.sizeE() ; i++) {
            componentsE_[id_[graph_.getEdge(i).from()]].push_back(i);
        }
        componentsE_.shrink_to_fit();
        for (auto& comp : componentsE_) {
            comp.shrink_to_fit();
        }
    }

    inline usize size() const {
        return countComponents_;
    }

    inline usize sizeV(u32 i) const {
        assert(i < countComponents_);
        return componentsV_[i].size();
    }

    inline usize sizeE(u32 i) const {
        assert(i < countComponents_);
        return componentsE_[i].size();
    }

    inline u32 operator[](u32 v) const {
        assert(v < graph_.sizeV());
        return id_[v];
    }

    inline u32 getVId(u32 v) const {
        assert(v < graph_.sizeV());
        return id_[v];
    }   

    inline u32 getEId(u32 v) const {
        assert(v < graph_.sizeE());
        return id_[graph_.getEdge(v).from()];
    }   

    inline bool same(u32 u, u32 v) const {
        assert(u < graph_.sizeV());
        assert(v < graph_.sizeV());
        return id_[u] == id_[v];
    }

    inline std::vector<std::vector<u32>> enumerateV() const {
        return componentsV_;
    }

    inline std::vector<u32> enumerateV(u32 i) const {
        assert(i < countComponents_);
        return componentsV_[i];
    }

    inline std::vector<std::vector<Edge<CostType>>> enumerateE() const {
        std::vector res(countComponents_, std::vector<Edge<CostType>>());
        for (u32 i = 0 ; i < countComponents_ ; i++) {
            for (auto eid_ : componentsE_[i]) {
                res[i].push_back(graph_.getEdge(eid_));
            }
        }
        return res;
    }

    inline std::vector<Edge<CostType>> enumerateE(u32 i) const {
        assert(i < countComponents_);
        std::vector<CostType> res(componentsE_[i].size());
        for (u32 j = 0 ; j < componentsE_[i].size() ; j++) {
            res[j] = graph_.getEdge(componentsE_[i][j]);
        }
        return res;
    }

    inline bool hasCycle(u32 i) const {
        assert(i < countComponents_);
        return sizeE(i) + 1 > sizeV(i);
    }
};

} // namespace zawa
