#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../DataStructure/RMQ/PM1RMQ.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class V>
class LowestCommonAncestor {
public:

    LowestCommonAncestor() = default;

    LowestCommonAncestor(std::vector<std::vector<V>> g,V r = 0) 
        : m_n{g.size()}, m_inv{}, m_left(size()), m_right(size()), m_dep(size())
    {
        std::vector<u32> ord;
        ord.reserve(2*size());
        m_inv.reserve(2*size());
        auto dfs = [&](auto dfs,V v,V p,u32 d) -> void {
            m_left[v] = ord.size();
            ord.push_back(d);
            m_inv.push_back(v);
            m_dep[v] = d;
            for (V x : g[v])
                if (x != p) {
                    dfs(dfs,x,v,d+1);
                    ord.push_back(d);
                    m_inv.push_back(v);
                }
            m_right[v] = ord.size();
        };
        dfs(dfs,r,static_cast<V>(-1),0);
        m_rmq = PM1RMQ{std::move(ord)};
    }

    V lca(V u,V v) const {
        assert(verify(u));
        assert(verify(v));
        if (u == v)
            return u;
        if (m_left[u] > m_left[v])
            std::swap(u,v);
        return m_inv[m_rmq.min(m_left[u],m_right[v])];
    }

    V operator()(V u,V v) const {
        return lca(u,v);
    }

    inline usize depth(V v) const {
        assert(verify(v));
        return m_dep[v];
    }

    usize distance(V u,V v) const {
        assert(verify(u));
        assert(verify(v));
        return m_dep[u] + m_dep[v] - 2*m_dep[lca(u,v)];
    }

    bool isAncestor(V p,V v) const {
        assert(verify(p));
        assert(verify(v));
        return m_left[p] <= m_left[v] and m_right[v] <= m_right[p];
    }

    std::pair<usize,usize> subtreeRange(V v) const {
        assert(verify(v));
        return {m_left[v],m_right[v]};
    }

protected:

    inline usize size() const {
        return m_n;
    }

    inline bool verify(V v) const {
        return static_cast<usize>(v) < size();
    }

    inline usize left(V v) const {
        assert(verify(v));
        return m_left[v];
    }

    inline usize right(V v) const {
        assert(verify(v));
        return m_right[v];
    }

private:

    usize m_n;
    
    std::vector<usize> m_inv,m_left,m_right,m_dep;

    PM1RMQ<u32> m_rmq;
};

} // namespace zawa
