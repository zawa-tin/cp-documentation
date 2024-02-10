#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

class Sack {
private:    
    static constexpr u32 INVALID{static_cast<u32>(-1)};
    usize n_{};
    std::vector<std::vector<u32>> g_;
    std::vector<u32> sz_, euler_, L_, R_;

    u32 dfsHLD(u32 v, u32 p) {
        sz_[v] = 1;
        usize m{g_[v].size()};
        usize max{};
        if (m > 1u and g_[v][0] == p) std::swap(g_[v][0], g_[v][1]);
        for (u32 i{} ; i < m ; i++) if (g_[v][i] != p) {
            sz_[v] += dfsHLD(g_[v][i], v);
            if (max < sz_[g_[v][i]]) {
                max = sz_[g_[v][i]];
                if (i) std::swap(g_[v][0], g_[v][i]);
            }
        }
        return sz_[v];
    }

    void dfsEuler(u32 v, u32 p, u32& t) {
        euler_[t] = v;
        L_[v] = t++;
        for (auto x : g_[v]) if (x != p) {
            dfsEuler(x, v, t);
        }
        R_[v] = t;
    }

public:
    constexpr usize size() const noexcept {
        return n_;
    }

    Sack() = default;
    Sack(u32 n) 
        : n_{n}, g_(n), sz_(n), euler_(n), L_(n), R_(n) {
        assert(n);
        g_.shrink_to_fit();
        sz_.shrink_to_fit();
        euler_.shrink_to_fit();
        L_.shrink_to_fit();
        R_.shrink_to_fit();
    }
    void addEdge(u32 u, u32 v) {
        assert(u < size());
        assert(v < size());
        g_[u].emplace_back(v);
        g_[v].emplace_back(u);
    }

    const std::vector<u32>& operator[](u32 v) const noexcept {
        assert(v < size());
        return g_[v];
    }

    template <class ADD, class DEL, class QUERY, class RESET>
    u32 execute(u32 root, const ADD& add, const DEL& del, const QUERY& query, const RESET& reset) {
        dfsHLD(root, INVALID);
        u32 t{};
        dfsEuler(root, INVALID, t);
        
        auto sack{[&](auto dfs, u32 v, u32 p, bool keep) -> void {
            usize m{g_[v].size()};
            for (u32 i{1} ; i < m ; i++) if (g_[v][i] != p) {
                dfs(dfs, g_[v][i], v, false);
            }
            if (sz_[v] > 1u) dfs(dfs, g_[v][0], v, true);
            if (sz_[v] > 1u) {
                for (u32 i{R_[g_[v][0]]} ; i < R_[v] ; i++) {
                    add(euler_[i]);
                }
            }
            add(v);
            query(v);
            if (!keep) {
                for (u32 i{L_[v]} ; i < R_[v] ; i++) {
                    del(euler_[i]);
                }
                reset();
            }
        }};
        sack(sack, root, INVALID, false);

        return sz_[root];
    }
};

} // namespace zawa
