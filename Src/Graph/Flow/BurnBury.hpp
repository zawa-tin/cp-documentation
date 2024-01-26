#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Utility/U32Pair.hpp"
#include "Dinic.hpp"

#include <cassert>
#include <unordered_map>
#include <vector>

namespace zawa {

template <class Cost>
class BurnBury {
private:
    usize n_{}, source_{}, sink_{}, graphsize_{};
    Dinic<Cost> mf_{}; 
    Cost common_{};
    std::unordered_map<U32Pair, Cost, U32PairHash> edge_{};
    void addEdge(u32 u, u32 v, const Cost& cost) {
        edge_[U32Pair{ u, v }] += cost;
    }
    constexpr usize size() const noexcept {
        return n_;
    }
public:
    BurnBury() = default;    
    BurnBury(usize n) : n_{n}, source_{n}, sink_{n + 1}, graphsize_{n + 2} {
        assert(n);
    }
    void constant(const Cost& cost) {
        common_ += cost;
    }
    void func1(u32 v, const std::vector<Cost>& cost) {
        assert(v < size());
        assert(cost.size() == (1u << 1));
        if (cost[0] <= cost[1]) {
            addEdge(source_, v, cost[1] - cost[0]);
            constant(cost[0]);
        }
        else {
            addEdge(v, sink_, cost[0] - cost[1]);
            constant(cost[1]);
        }
    }
    void func2(u32 u, u32 v, const std::vector<Cost>& cost) {
        assert(u < size());
        assert(v < size());
        assert(cost.size() == (1u << 2));
        constant(cost[0]);
        func1(u, { Cost{0}, cost[2] - cost[0] });
        func1(v, { Cost{0}, cost[3] - cost[2] });
        assert(cost[1] + cost[2] - cost[0] - cost[3] >= 0);
        addEdge(u, v, cost[1] + cost[2] - cost[0] - cost[3]);
    }
    void func3(u32 u, u32 v, u32 w, const std::vector<Cost>& cost) {
        assert(u < size());
        assert(v < size());
        assert(w < size());
        assert(cost.size() == (1u << 3));
        Cost p{cost[1] + cost[3] + cost[5] + cost[6] - (cost[1] + cost[2] + cost[4] + cost[7])};
        if (p >= 0) {
            constant(cost[0]);
            func1(u, Cost{0}, cost[5] - cost[1]);
            func1(v, Cost{0}, cost[6] - cost[4]);
            func1(w, Cost{0}, cost[3] - cost[2]);
            // 01以外は0
            func2(u, v, { Cost{0}, cost[2] + cost[4] - cost[0] - cost[6], Cost{0}, Cost{0} });
            func2(v, w, { Cost{0}, cost[1] + cost[2] - cost[0] - cost[3], Cost{0}, Cost{0} });
            func2(w, u, { Cost{0}, cost[1] + cost[4] - cost[0] - cost[5], Cost{0}, Cost{0} });
            // 111とすると-p
            addEdge(u, graphsize_, p);
            addEdge(v, graphsize_, p);
            addEdge(w, graphsize_, p);
            addEdge(graphsize_, sink_, p);
            constant(-p);
            graphsize_++;
        }
        else {
            constant(cost[7]);
            func1(u, { cost[2] - cost[6], Cost{0} });
            func1(v, { cost[1] - cost[3], Cost{0} });
            func1(w, { cost[4] - cost[5], Cost{0} });
            // 10の時
            func2(u, v, { Cost{0}, Cost{0}, cost[3] + cost[5] - cost[1] - cost[7], Cost{0} });
            func2(v, w, { Cost{0}, Cost{0}, cost[5] + cost[6] - cost[4] - cost[7], Cost{0} });
            func2(w, u, { Cost{0}, Cost{0}, cost[3] + cost[6] - cost[2] - cost[7], Cost{0} });
            // 000
            addEdge(source_, graphsize_, -p);
            addEdge(graphsize_, u, -p);
            addEdge(graphsize_, v, -p);
            addEdge(graphsize_, w, -p);
            constant(p);
            graphsize_++;
        }
    }

    [[nodiscard]] Cost build() {
        mf_ = Dinic<Cost>(graphsize_);
        for (const auto& [uv, cost] : edge_) {
            mf_.addEdge(uv.first(), uv.second(), cost);
        }
        Cost res{mf_.flow(source_, sink_)};
        res += common_;
        return res;
    }

    [[nodiscard]] std::vector<u32> assign() {
        auto tos{mf_.cut(source_)}, tot{mf_.cut(sink_)};
        std::vector<u32> res(size());
        for (u32 i{} ; i < size() ; i++) {
            if (!tos[i] and !tot[i]) res[i] = 2;
            else if (tos[i]) res[i] = 0;
            else res[i] = 1;
        }
        return res;
    }
};

} // namespace zawa
