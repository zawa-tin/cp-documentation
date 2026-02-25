#pragma once

#include "./Centroid.hpp"
#include "../../DataStructure/Heap/BinaryHeap.hpp"

#include <cassert>
#include <concepts>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>
#include <iostream>

namespace zawa {

template <std::integral V>
class ContourAggregation {
public:

    ContourAggregation(std::vector<std::vector<V>> G) : m_cent(1), m_par(1), m_ch(1) {
        const usize N = G.size();
        m_inv.resize(N);
        m_pos.resize(N);
        m_ord.reserve(2 * N);
        Centroid ce{std::move(G)};
        std::vector<i32> dist(N,-1);

        auto makeNode = [&](std::vector<V> vs) -> usize {
            assert(vs.size());
            const usize res = m_cent.size();
            this->m_cent.push_back(N);
            this->m_par.push_back(0);
            this->m_ch.emplace_back();
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
            m_offset.push_back(std::move(offset));
            return res;
        };

        auto compDist = [&](usize i, usize j) -> bool {
            return dist[i] < dist[j];
        };

        // {node id, height, vertices}
        auto dfs = [&](auto dfs, V v) -> std::tuple<usize,usize,std::vector<V>> {
            v = ce.rooting(v);
            std::vector<std::tuple<usize,usize,std::vector<V>>> ch;
            ce.remove(v);
            for (V x : ce.adjlist(v)) {
                auto res = dfs(dfs,x);
                m_cent[std::get<0>(res)] = v;
                ch.push_back(std::move(res));
            }
            std::vector<V> que{v};
            dist[v] = 0;
            for (usize t = 0 ; t < que.size() ; t++) {
                const usize cur = que[t];
                for (V x : ce.adjlist(cur))
                    if (dist[x] == -1) {
                        dist[x] = dist[cur] + 1;
                        que.push_back(x);
                    }
            }
            for (auto& dat : ch)
                std::ranges::sort(std::get<2>(dat),compDist);
            ch.emplace_back(m_pos[v] = makeNode({v}),0u,std::vector<V>{v});

            std::cout << v << " build " << std::endl;
            std::cout << "vertices=";
            for (auto x : que)
                std::cout << x << ' ';
            std::cout << std::endl;
            std::cout << "ch.size()=" << ch.size() << std::endl;

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
                // merge here
                std::vector<V> vertices;
                std::ranges::merge(std::move(std::get<2>(ch[l])),std::move(std::get<2>(ch[r])),std::back_inserter(vertices),compDist);
                const usize nd = makeNode(vertices);
                m_par[l] = m_par[r] = nd;
                const usize h = std::max(std::get<1>(ch[l]),std::get<1>(ch[r]))+1;
                ch.emplace_back(nd,h,std::move(vertices));
                heap.push(ch.size()-1);
                m_ch[nd] = {l,r};
                std::cout << l << " -> " << nd << " <- " << r << std::endl;
            }
            for (V v : que)
                dist[v] = -1;
            return ch[heap.top()];
        };
        std::vector<bool> vis(N);
        for (V i = 0 ; i < (V)N ; i++)
            if (!vis[i])
                for (V v : std::get<2>(dfs(dfs,i)))
                    vis[v] = 1;

        std::cout << "m_pos=";
        for (auto v : m_pos)
            std::cout << v << ' ';
        std::cout << std::endl;
    }

    inline usize size() const {
        return m_ord.size();
    }

    std::vector<usize> point(V v) const {
        assert(0 <= v and v < (V)m_inv.size());
        return m_inv[v];
    }

    std::vector<std::pair<usize,usize>> contour(V v, usize l, usize r) const {
        std::vector<std::pair<usize,usize>> res;
        usize nd = m_pos[v];
        if (l == 0)
            res.push_back({m_offset[nd][0],m_offset[nd][1]});
        while (m_par[nd]) {
            nd = m_par[v];
            const usize cur = m_ch[nd].first == nd ? m_ch[nd].second : m_ch[nd].first;
            if (l + 1 >= m_offset[cur].size())
                continue;
            res.push_back({m_offset[cur][l],m_offset[cur][std::min(r,m_offset[cur].size()-1)]});
        }
        return res;
    }

private:

    std::vector<V> m_cent;

    std::vector<usize> m_par;

    std::vector<std::pair<usize,usize>> m_ch;

    std::vector<V> m_ord;

    std::vector<usize> m_pos;

    std::vector<std::vector<usize>> m_offset, m_inv;

};

} // namespace zawa
