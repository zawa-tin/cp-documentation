#pragma once

#include "../../Template/TypeAlias.hpp"
#include "atcoder/scc.hpp"

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class IncrementalSCCResponse {
public:
    using TimeType = u32;
    static constexpr TimeType invalid() noexcept {
        return INVALID;
    }
    IncrementalSCCResponse() = default;
    IncrementalSCCResponse(const std::vector<TimeType>& T) : time_{T} {
        time_.shrink_to_fit();
    }
    TimeType operator[](u32 i) const noexcept {
        assert(i < time_.size());
        return time_[i];
    }
    bool same(u32 i) const noexcept {
        return time_[i] != INVALID;
    }
private:
    static constexpr TimeType INVALID{static_cast<TimeType>(-1)};
    std::vector<TimeType> time_;
};

class IncrementalSCC {
private:
    using TimeType = IncrementalSCCResponse::TimeType;
    using VType = u32;
    using Edge = std::tuple<TimeType, VType, VType>;
    static constexpr u32 INVALID{IncrementalSCCResponse::invalid()};

    usize n_;
    std::vector<Edge> edges_;
public:
    IncrementalSCC() = default;
    IncrementalSCC(usize n) : n_{n}, edges_{} {}

    inline u32 size() const noexcept {
        return n_;
    }

    constexpr u32 invalid() const noexcept {
        return INVALID;
    }

    u32 addEdge(VType u, VType v) {
        assert(u < n_);
        assert(v < n_);
        TimeType t{static_cast<TimeType>(edges_.size())};
        edges_.emplace_back(t, u, v);
        return t;
    }

    std::pair<VType, VType> getEdge(TimeType t) const {
        assert(t < edges_.size());
        auto [_, u, v]{edges_[t]};
        return std::pair<VType, VType>{ u, v };
    }

    IncrementalSCCResponse build() const {
        std::vector<VType> id(size(), INVALID);
        std::vector<TimeType> res(edges_.size(), INVALID);
        auto rec{[&](auto rec, u32 L, u32 R, const std::vector<Edge>& E) -> void {
            if (E.empty() or L + 1 >= R) {
                return;
            }
            u32 n{};
            for (auto [t, u, v] : E) {
                if (id[u] == INVALID) {
                    id[u] = n++;
                }
                if (id[v] == INVALID) {
                    id[v] = n++;
                }
            }
            u32 mid{(L + R) >> 1};
            atcoder::scc_graph g(n);
            for (auto [t, u, v] : E) {
                if (t < mid) {
                    g.add_edge(id[u], id[v]);
                }
            }
            auto scc{g.scc()};
            std::vector<u32> comp(n);
            for (u32 i{} ; i < scc.size() ; i++) {
                for (auto v : scc[i]) {
                    comp[v] = i;
                }
            }
            std::vector<Edge> EL, ER;
            for (auto [t, u, v] : E) {
                u = id[u];
                v = id[v];
                if (t < mid and comp[u] == comp[v]) {
                    res[t] = std::min(res[t], mid - 1);
                    EL.emplace_back(t, u, v);
                }
                else {
                    ER.emplace_back(t, comp[u], comp[v]);
                }
            }
            for (auto [_, u, v] : E) {
                id[u] = id[v] = INVALID;
            }
            rec(rec, L, mid, EL);
            rec(rec, mid, R, ER);
        }};
        rec(rec, u32{}, edges_.size() + 1, edges_);
        return IncrementalSCCResponse{res};
    }
};

} // namespace zawa
