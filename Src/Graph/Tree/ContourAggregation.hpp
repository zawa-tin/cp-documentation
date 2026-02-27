#pragma once

#include "./Centroid.hpp"
#include "./LowestCommonAncestor.hpp"
#include "../../DataStructure/Heap/BinaryHeap.hpp"

#include <cassert>
#include <concepts>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

namespace zawa {

template <std::integral V>
class ContourAggregation {
public:

    ContourAggregation(std::vector<std::vector<V>> G) : m_lca{G}, m_cent(1), m_par(1), m_ch(1), m_offset(1) {
        const usize N = G.size();
        assert(N);
        m_inv.resize(N);
        m_pos.resize(N);
        m_ord.reserve(2 * N);
        Centroid ce{std::move(G)};
        std::vector<i32> dist(N,-1);

        auto makeNode = [&]() -> usize {
            const usize res = m_cent.size();
            m_cent.push_back(N);
            m_par.push_back(0);
            m_ch.emplace_back();
            m_offset.emplace_back();
            return res;
        };

        auto createOffset = [&](usize nd,std::vector<V> vs) {
            std::vector<usize> offset{m_ord.size()};
            if (dist[vs[0]] == 1)
                offset.push_back(m_ord.size());
            for (usize i = 0, j = 0 ; i < vs.size() ; i = j) {
                while (j < vs.size() and dist[vs[i]] == dist[vs[j]]) {
                    m_inv[vs[j]].push_back(m_ord.size());
                    m_ord.push_back(vs[j]);
                    j++;
                }
                offset.push_back(m_ord.size());
            }
            m_offset[nd] = std::move(offset);
        };

        auto compDist = [&](usize i, usize j) -> bool {
            return dist[i] < dist[j];
        };

        // {node id, height, vertices}
        auto dfs = [&](auto dfs, V v) -> std::tuple<usize,usize,std::vector<V>> {
            v = ce.rooting(v);
            std::vector<std::tuple<usize,usize,std::vector<V>>> ch;
            ce.remove(v);
            dist[v] = 0;
            for (V x : ce.adjlist(v)) {
                auto ret = dfs(dfs,x);
                for (V cur : std::get<2>(ret))
                    dist[cur] = m_lca.distance(v,cur);
                m_cent[std::get<0>(ret)] = v;
                ch.push_back(std::move(ret));
            }
            for (auto& dat : ch)
                std::ranges::sort(std::get<2>(dat),compDist);
            { // create single node of {v}
                const usize nd = m_pos[v] = makeNode();
                ch.emplace_back(nd,0u,std::vector<V>{v});
                m_cent[nd] = v;
            }
            auto comp = [&](usize i, usize j) -> bool {
                return std::get<1>(ch[i]) < std::get<1>(ch[j]);
            };
            BinaryHeap<usize,decltype(comp)> heap{[&]()->std::vector<usize>{
                std::vector<usize> res(ch.size()); 
                std::iota(res.begin(),res.end(),0u); 
                return res;
            }(),comp};
            while (std::ssize(heap) > 1) {
                const usize l = heap.top();
                heap.pop();
                const usize r = heap.top();
                heap.pop();
                const usize L = std::get<0>(ch[l]), R = std::get<0>(ch[r]);
                createOffset(L,std::get<2>(ch[l]));
                createOffset(R,std::get<2>(ch[r]));
                // merge here
                std::vector<V> vertices;
                std::ranges::merge(std::move(std::get<2>(ch[l])),std::move(std::get<2>(ch[r])),std::back_inserter(vertices),compDist);
                const usize nd = makeNode();
                m_par[L] = m_par[R] = nd;
                m_cent[L] = m_cent[R] = v;
                const usize h = std::max(std::get<1>(ch[l]),std::get<1>(ch[r]))+1;
                ch.emplace_back(nd,h,std::move(vertices));
                heap.push(ch.size()-1);
                m_ch[nd] = {L,R};
            }
            for (V x : std::get<2>(ch[heap.top()]))
                dist[x] = -1;
            return ch[heap.top()];
        };
        if (N == 1) {
            m_inv[0].push_back(0);
            m_ord.push_back(0);
        }
        else {
            std::vector<bool> vis(N);
            for (V i = 0 ; i < (V)N ; i++)
                if (!vis[i]) {
                    const auto ret = std::get<2>(dfs(dfs,i));
                    for (V v : ret)
                        vis[v] = 1;
                }
        }
    }

    inline usize size() const {
        return m_ord.size();
    }

    std::vector<usize> point(V v) const {
        assert(0 <= v and v < (V)m_inv.size());
        return m_inv[v];
    }

    std::vector<std::pair<usize,usize>> contour(V v, usize l, usize r) const {
        assert(V{0} <= v and v < (V)m_inv.size());
        std::vector<std::pair<usize,usize>> res;
        if (l >= r)
            return res;
        usize nd = m_pos[v];
        if (l == 0)
            res.push_back({m_inv[v][0],m_inv[v][0]+1});
        for ( ; m_par[nd] ; nd = m_par[nd]) {
            const usize cur = m_ch[m_par[nd]].first == nd ? m_ch[m_par[nd]].second : m_ch[m_par[nd]].first;
            const usize sub = m_lca.distance(m_cent[cur],v);
            if (sub >= r)
                continue;
            const usize L = sub >= l ? 0 : l - sub;
            const usize R = std::min(r - sub,m_offset[cur].size()-1);
            if (L >= R)
                continue;
            res.push_back({m_offset[cur][L],m_offset[cur][R]});
        }
        return res;
    }

    std::vector<std::pair<usize,usize>> contour(V v, usize d) const {
        return contour(v,d,d+1);
    }

private:

    LowestCommonAncestor<V> m_lca;

    std::vector<V> m_cent;

    std::vector<usize> m_par;

    std::vector<std::pair<usize,usize>> m_ch;

    std::vector<std::vector<usize>> m_offset;

    std::vector<V> m_ord;

    std::vector<usize> m_pos;

    std::vector<std::vector<usize>> m_inv;
    
};

} // namespace zawa
