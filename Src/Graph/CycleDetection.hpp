#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <concepts>
#include <iterator>
#include <optional>
#include <utility>
#include <vector>

namespace zawa {

template <std::integral T,std::integral U>
std::optional<std::pair<std::vector<T>,std::vector<U>>> CycleDetection(const std::vector<std::vector<std::pair<T,U>>>& G) {
    const usize N = G.size();
    std::vector<u8> col(N);
    std::vector<T> vs;
    std::vector<U> es;
    auto dfs = [&](auto dfs,T v,U id) -> std::optional<T> {
        vs.push_back(v);
        col[v] = 1;
        for (auto [x,i] : G[v])
            if (i != id and col[x] < u8{2}) {
                es.push_back(i);
                if (col[x])
                    return x;
                else if (auto ret = dfs(dfs,x,i) ; ret.has_value())
                    return ret;
                es.pop_back();
            }
        vs.pop_back(); 
        col[v] = 2;
        return std::nullopt;
    };
    for (usize i = 0 ; i < N ; i++)
        if (col[i] == 0) {
            auto ret = dfs(dfs,i,static_cast<U>(-1));
            if (ret.has_value()) {
                auto it = std::ranges::find(vs,*ret);
                auto d = std::distance(vs.begin(),it);
                es.erase(es.begin(),es.begin()+d);
                vs.erase(vs.begin(),vs.begin()+d);
                return std::pair{std::move(vs),std::move(es)};
            }
        }
    return std::nullopt;
}

// こっちは多重辺ダメ
template <std::integral T, bool directed>
std::optional<std::vector<T>> CycleDetection(const std::vector<std::vector<T>>& G) {
    const usize N = G.size();
    std::vector<u8> col(N);
    std::vector<T> vs;
    auto dfs = [&](auto dfs,T v,T p) -> std::optional<T> {
        col[v] = 1;
        vs.push_back(v);
        if constexpr (directed) {
            for (T x : G[v])
                if (col[x] < u8{2}) {
                    if (col[x])
                        return x;
                    else if (auto ret = dfs(dfs,x,v) ; ret.has_value())
                        return ret;
                }
        }
        else {
            for (T x : G[v])
                if (x != p) {
                    if (col[x])
                        return x;
                    else if (auto ret = dfs(dfs,x,v) ; ret.has_value())
                        return ret;
                }
        }
        vs.pop_back();
        col[v] = 2;
        return std::nullopt;
    };
    for (usize i = 0 ; i < N ; i++)
        if (col[i] == 0) {
            auto ret = dfs(dfs,i,static_cast<T>(-1));
            if (ret.has_value()) {
                auto it = std::ranges::find(vs,*ret);
                vs.erase(vs.begin(),it);
                return vs;
            }
        }
    return std::nullopt;
}

} // namespace zawa
