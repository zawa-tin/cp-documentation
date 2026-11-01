#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <optional>
#include <utility>
#include <vector>

namespace zawa {

template <std::integral T,class U>
class TreeCenters {
public:

    explicit TreeCenters(std::vector<std::vector<std::pair<T,U>>> g) 
        : m_g{std::move(g)},m_path{},m_root{} {
        assert(size() and "TreeCenters: empty graph is not a tree");
        auto d0=bfs(0).first;
        const T p=std::ranges::max_element(d0)-d0.begin();
        auto [dp,prev]=bfs(p);
        const T q=std::ranges::max_element(dp)-dp.begin();
        auto dq=bfs(q).first;
        for (i32 v = static_cast<i32>(q) ; ; v = prev[v]) {
            m_path.push_back(v);
            if (static_cast<T>(v)==p)
                break;
        }
        const auto [u,v]=[&]() -> std::pair<T,T> {
            for (usize i = 0 ; i < m_path.size() ; i++)
                if (dq[m_path[i]]==dp[m_path[i]])
                    return {m_path[i],m_path[i]};
            for (usize i = 0 ; i + 1 < m_path.size() ; i++) {
                T u=m_path[i],v=m_path[i+1];
                if (dq[u]<dp[u] and dq[v]>dp[v])
                    return {u,v};
            }
            // std::unreachable();
            assert(0);
            return {0,0};
        }();
        if (u==v)
            m_root=v;
        else {
            U w=0;
            for (auto it=m_g[u].begin() ; it != m_g[u].end() ; it++)
                if (it->first==v) {
                    w=it->second;
                    it=m_g[u].erase(it);
                    break;
                }
            for (auto it=m_g[v].begin() ; it != m_g[v].end() ; it++)
                if (it->first==u) {
                    it=m_g[v].erase(it);
                    break;
                }
            assert(w>0);
            std::vector<std::pair<T,U>> adj;
            adj.push_back({u,w/2});
            adj.push_back({v,w/2+w%2});
            dp.push_back(dp[v]+w/2+w%2);
            dq.push_back(dq[u]+w/2);
            m_root=size();
            m_g.push_back(std::move(adj));
        }
        m_farthest.resize(size());
        for (usize i = 0 ; i < size() ; i++)
            m_farthest[i]=dp[i]<dq[i]?std::pair{q,dq[i]}:std::pair{p,dp[i]};
        m_par.resize(size(),-1);
        dfs(m_root,-1);
    }

    explicit TreeCenters(std::vector<std::vector<T>> g) : TreeCenters(convert(std::move(g))) {}

    inline usize size() const noexcept {
        return m_g.size();
    }

    inline const std::vector<T>& diameterPath() const {
        return m_path;
    }

    U diameterLength() const {
        return m_farthest[m_path[0]].second;
    }

    inline T root() const noexcept {
        return m_root;
    }

    inline const std::vector<std::pair<T,U>>& operator[](usize v) const noexcept {
        assert(v<size());
        return m_g[v];
    }

    inline i32 parent(usize v) const noexcept {
        assert(v<size());
        return m_par[v];
    }
    
    inline const std::pair<T,U>& farthest(usize v) const noexcept {
        assert(v<size());
        return m_farthest[v];
    }

private:

    std::pair<std::vector<U>,std::vector<i32>> bfs(T s) const {
        std::vector<T> que{s};
        std::vector<U> dist(size(),static_cast<U>(-1));
        dist[s]=0;
        std::vector<i32> prev(size(),-1);
        for (usize t = 0 ; t < que.size() ; t++) {
            const T v=que[t];
            for (auto [x,w] : m_g[v]) {
                assert(w > 0 and "TreeCenters: edge weight must be positive");
                if (dist[x]==-1) {
                    dist[x]=dist[v]+w;
                    prev[x]=v;
                    que.push_back(x);
                }
            }
        }
        return {std::move(dist),std::move(prev)};
    }

    void dfs(T v,T p) {
        m_par[v]=p;
        for (auto it=m_g[v].begin() ; it!=m_g[v].end() ; ) {
            if (it->first==p)
                it=m_g[v].erase(it);
            else {
                dfs(it->first,v);
                it++;
            }
        }
    }

    static std::vector<std::vector<std::pair<T,U>>> convert(std::vector<std::vector<T>> g) {
        std::vector<std::vector<std::pair<T,U>>> res(g.size());
        for (usize i = 0 ; i < g.size() ; i++)
            for (T x : g[i])
                res[i].push_back({x,U{1}});
        return res;
    }

    std::vector<std::vector<std::pair<T,U>>> m_g;

    std::vector<T> m_path;

    T m_root;

    std::vector<i32> m_par;

    std::vector<std::pair<T,U>> m_farthest;

};

} // namespace zawa
