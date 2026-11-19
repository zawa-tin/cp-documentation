#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>
#include <iterator>
#include <limits>
#include <unordered_map>

namespace zawa {

template <std::integral T,std::integral U>
class PowersetConstruction {
public:

    PowersetConstruction() = default;

    PowersetConstruction(usize N,usize alpMax,T start,std::vector<T> accept)
        : m_n{N}, m_alp{alpMax}, m_st{start}, m_accept{0}, m_to(alpMax,std::vector<u64>(N)), m_epsilon(N) {
        assert(N < 64);
        assert(alpMax <= static_cast<usize>(std::numeric_limits<U>::max()));
        assert(static_cast<usize>(start)<size());
        for (T v : accept) {
            assert(static_cast<usize>(v)<size());
            m_accept|=u64{1}<<v;
        }
    }

    inline usize size() const noexcept {
        return m_n;
    }

    inline usize sigma() const noexcept {
        return m_alp;
    }

    void addTransition(T from, T to, U c) {
        assert(static_cast<usize>(from) < size());
        assert(static_cast<usize>(to) < size());
        assert(static_cast<usize>(c) < sigma());
        m_to[c][from]|=u64{1}<<to;
    }

    void addEpsilonTransition(T from,T to) {
        assert(static_cast<usize>(from) < size());
        assert(static_cast<usize>(to) < size());
        m_epsilon[from]|=u64{1}<<to;
    }

    std::pair<std::vector<std::vector<T>>,std::vector<bool>> build() {
        std::vector<u64> epsilon(size());
        for (usize i = 0 ; i < size() ; i++)
            epsilon[i]=epsilonClosure(i);
        for (usize i = 0 ; i < size() ; i++)
            for (usize j = 0 ; j < sigma() ; j++)
                for (usize k = 0 ; k < size() ; k++)
                    if (m_to[j][i]>>k&1)
                        m_to[j][i]|=epsilon[k];
        std::unordered_map<u64,T> id;
        T inf=std::numeric_limits<T>::max();
        std::vector to(1,std::vector<T>(sigma(),inf));
        std::vector<std::pair<u64,T>> que;
        id[epsilon[m_st]]=0;
        que.push_back({epsilon[m_st],T{0}});
        for (usize t = 0 ; t < que.size() ; t++) {
            auto [b,v]=que[t];
            std::vector<T> nw;
            for (usize i = 0 ; i < size() ; i++)
                if (b>>i&1)
                    nw.push_back(i);
            for (usize i = 0 ; i < sigma() ; i++) {
                u64 nxt=0;
                for (T j : nw)
                    nxt|=m_to[i][j];
                if (!nxt)
                    to[v][i]=inf;
                else if (auto it=id.find(nxt) ; it!=id.end())
                    to[v][i]=it->second;
                else {
                    T x=std::ssize(to);
                    to.push_back(std::vector<T>(sigma(),inf));
                    to[v][i]=x;
                    id[nxt]=x;
                    que.push_back({nxt,x});
                }
            }
        }
        const usize n=id.size();
        for (usize i = 0 ; i < n ; i++)
            std::ranges::replace(to[i],inf,static_cast<T>(n));
        std::vector<bool> accept(n);
        for (auto [b,v] : id)
            accept[v]=(b&m_accept)>0;
        return {std::move(to),std::move(accept)};
    }

private:

    usize m_n,m_alp;

    T m_st;

    u64 m_accept;

    std::vector<std::vector<u64>> m_to;

    std::vector<u64> m_epsilon;

    u64 epsilonClosure(T s) {
        u64 vis=u64{1}<<s;
        std::vector<T> que{s};
        for (usize t = 0 ; t < que.size() ; t++) {
            T v=que[t];
            for (usize i = 0 ; i < size() ; i++)
                if (!(vis>>i&1) and m_epsilon[v]>>i&1) {
                    vis|=u64{1}<<i;
                    que.push_back(i);
                }
        }
        return vis;
    }

};

} // namespace zawa
