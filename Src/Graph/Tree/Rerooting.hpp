#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <concepts>

namespace zawa {

namespace concepts {

template <class T>
concept TreeDP = requires {
    typename T::Tree;
    typename T::Cluster;
    typename T::Edge;
    typename T::Vertex;
    { T::Convert(std::declval<typename T::Vertex>()) } -> std::same_as<typename T::Tree>;
    { T::AddEdge(std::declval<typename T::Tree>(), std::declval<typename T::Edge>()) } -> std::same_as<typename T::Cluster>;
    { T::Merge(std::declval<typename T::Cluster>(), std::declval<typename T::Cluster>()) } -> std::same_as<typename T::Cluster>;
    { T::AddVertex(std::declval<typename T::Cluster>(), std::declval<typename T::Vertex>()) } -> std::same_as<typename T::Tree>;
};

}

template <concepts::TreeDP DP,std::integral T>
class Rerooting {
public:

    using Tree = DP::Tree;

    using Cluster = DP::Cluster;

    using Edge = DP::Edge;

    using Vertex = DP::Vertex;

    Rerooting(usize n,std::vector<std::pair<T,T>> ed,std::vector<Vertex> vs,std::vector<Edge> es) 
    : m_n{n}, m_edges{std::move(ed)}, m_alls(n), m_sides(m_edges.size()) {
        assert(m_edges.size()+1==n); 
        assert(m_edges.size()==es.size());
        assert(n==vs.size());
        if (n==1) {
            m_alls[0]=DP::Convert(vs[0]);
            return;
        }
        std::vector<std::vector<std::pair<T,u32>>> g(n);
        for (usize i = 0 ; auto [u,v] : m_edges) {
            g[u].push_back({v,i});
            g[v].push_back({u,i});
            i++;
        }
        std::vector<Tree> dp(n);
        auto dfs1=[&](auto dfs,T v,T p) -> Tree {
            if (std::ssize(g[v])==1 and g[v][0].first==p)
                return dp[v]=DP::Convert(vs[v]);
            usize idx=g[v][0].first==p?1:0;
            assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);
            Cluster prod=DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]);
            for (idx++ ; idx<g[v].size() ; idx++) 
                if (g[v][idx].first!=p) {
                    assignToSides(dfs(dfs,g[v][idx].first,v),g[v][idx].second,g[v][idx].first);
                    prod=DP::Merge(prod,DP::AddEdge(dp[g[v][idx].first],es[g[v][idx].second]));
                }
            return dp[v]=DP::AddVertex(std::move(prod),vs[v]);
        };
        dfs1(dfs1,0,static_cast<T>(0));
        auto dfs2=[&](auto dfs,T v,T p,Tree t) -> void {
            const usize k=g[v].size();
            std::vector<Cluster> clusters(k);
            for (usize i = 0 ; i < k ; i++) {
                if (g[v][i].first==p) {
                    assignToSides(t,g[v][i].second,p);
                    clusters[i]=DP::AddEdge(t,es[g[v][i].second]);
                }
                else
                    clusters[i]=DP::AddEdge(dp[g[v][i].first],es[g[v][i].second]);
            }
            if (k==1) {
                m_alls[v]=DP::AddVertex(clusters[0],vs[v]);
                if (g[v][0].first!=p) {
                    assert(!v);
                    dfs(dfs,g[v][0].first,v,DP::Convert(vs[v]));
                }
            }
            else {
                std::vector<Cluster> pref=clusters,suf=clusters;
                for (usize i = 1 ; i < k ; i++) {
                    pref[i]=DP::Merge(pref[i-1],clusters[i]);
                    suf[k-i-1]=DP::Merge(clusters[k-i-1],suf[k-i]);
                }
                m_alls[v]=DP::AddVertex(pref[k-1],vs[v]);
                for (usize i = 0 ; i < g[v].size() ; i++) 
                    if (g[v][i].first!=p) {
                        Cluster pc=i?(i+1<g[v].size()?DP::Merge(pref[i-1],suf[i+1]):pref[k-2]):suf[1];
                        dfs(dfs,g[v][i].first,v,DP::AddVertex(pc,vs[v]));
                    }
            }
        };
        dfs2(dfs2,0,static_cast<T>(0),Tree{});
    }

    inline usize size() const noexcept {
        return m_n;
    }

    const Tree& operator[](usize i) const noexcept {
        assert(i < size());
        return m_alls[i];
    }

    const Tree& side(usize i,T v) const {
        assert(i < m_sides.size()); 
        if (m_edges[i].first==v)
            return m_sides[i].first;
        else if (m_edges[i].second==v)
            return m_sides[i].second;
        assert(0);
        return m_sides[i].first;
    }

private:

    void assignToSides(Tree t,usize idx,T v) {
        if (m_edges[idx].first==v)
            m_sides[idx].first=std::move(t);
        else
            m_sides[idx].second=std::move(t);
    }

    usize m_n;

    std::vector<std::pair<T,T>> m_edges;

    std::vector<Tree> m_alls;

    std::vector<std::pair<Tree,Tree>> m_sides;

};

} // namespace zawa
