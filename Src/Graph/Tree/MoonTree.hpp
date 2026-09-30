#pragma once

#include "../../Utility/Mo.hpp"
#include "./OfflineLowestCommonAncestor.hpp"

#include <concepts>
#include <utility>
#include <vector>

namespace zawa {

template <std::signed_integral T, class Add,class Del, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize>> MoonTree(const std::vector<std::vector<T>>& G,const std::vector<std::pair<T,T>>& qs, Add add, Del del, Eval eval, bool reset = false) {
    const T n = static_cast<T>(G.size());
    if (!n) {
        assert(qs.empty());
        return {};
    }
    std::vector<T> in(n),out(n),euler;
    euler.reserve(2*n);
    auto dfs=[&](auto dfs,T v,T p) -> void {
        in[v] = static_cast<T>(euler.size());
        euler.push_back(v);
        for (T x : G[v])
            if (x != p)
                dfs(dfs,x,v);
        out[v] = static_cast<T>(euler.size());
        euler.push_back(v);
    };
    dfs(dfs,static_cast<T>(0),static_cast<T>(-1));
    std::vector<std::pair<T,T>> path;
    path.reserve(qs.size());
    std::vector<T> extra;
    extra.reserve(qs.size());
    std::vector<T> lcas = OfflineLowestCommonAncestor(G,qs);
    // for (auto [u,v] : qs) {
    for (u32 idx = 0 ; idx < qs.size() ; idx++) {
        auto [u,v] = qs[idx];
        T l=lcas[idx];
        T i=in[u],j=in[v];
        if (i>j) {
            std::swap(i,j);
            std::swap(u,v);
        }
        if (u!=l) {
            i=out[u];
            extra.push_back(l);
        }
        else
            extra.push_back(n);
        path.push_back({i,j+1});
    }
    T L=0,R=0;
    std::vector<typename std::invoke_result_t<Eval, usize>> res(qs.size());
    std::vector<bool> parity(n);
    auto toggle=[&](T v) -> void {
        parity[v] ? del(v) : add(v);
        parity[v] = !parity[v];
    };
    for (usize i : Mo(path)) {
        const auto [l,r] = path[i];
        while (R<r) 
            toggle(euler[R++]);
        while (L>l)
            toggle(euler[--L]);
        while (R>r)
            toggle(euler[--R]);
        while (L<l) 
            toggle(euler[L++]);
        if (extra[i]<n)
            toggle(extra[i]);
        res[i] = eval(i);
        if (extra[i]<n)
            toggle(extra[i]);
    }
    if (reset)
        while (R>L) 
            toggle(euler[--R]);
    return res;
}

} // namespace zawa
