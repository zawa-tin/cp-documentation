#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <array>
#include <bit>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>

namespace zawa {

namespace internal {

template <concepts::Group G,usize N>
class StaticHypercubeSumSolver {
public:

    using T = typename G::Element;

    StaticHypercubeSumSolver(std::array<usize,N> sz,std::array<usize,N+1> prod,std::vector<T> a)
        : m_size{sz}, m_prod{prod}, m_sum{std::move(a)} {
        for (usize axis = 0 ; axis < N ; axis++)
            for (usize i = 0 ; i < prod[N] ; i++)
                if (i/m_prod[axis]%m_size[axis])
                    m_sum[i] = G::operation(m_sum[i],m_sum[i-m_prod[axis]]);
    }

    template <std::integral IDX>
    T product(const std::array<std::pair<IDX,IDX>,N>& lr) const {
        for (usize i = 0 ; i < N ; i++) {
            assert(static_cast<IDX>(0) <= lr[i].first and lr[i].first <= static_cast<IDX>(m_size[i]));
            assert(static_cast<IDX>(0) <= lr[i].second and lr[i].second <= static_cast<IDX>(m_size[i]));
            assert(lr[i].first <= lr[i].second);
        }
        T res = G::identity();
        auto dfs = [&](auto dfs,usize axis,usize idx,bool sign) -> void {
            if (axis == N) {
                if (sign)
                    res = G::operation(res,G::inverse(m_sum[idx]));
                else
                    res = G::operation(res,m_sum[idx]);
                return;
            }
            if (lr[axis].second)
                dfs(dfs,axis+1,idx+m_prod[axis]*(lr[axis].second-1),sign);
            if (lr[axis].first)
                dfs(dfs,axis+1,idx+m_prod[axis]*(lr[axis].first-1),!sign);
        };
        dfs(dfs,0,0,0);
        return res;
    }

    template <std::integral IDX>
    T product(const std::array<IDX,N>& l,const std::array<IDX,N>& r) const {
        std::array<std::pair<IDX,IDX>,N> lr;
        for (usize i = 0 ; i < N ; i++)
            lr[i] = {l[i],r[i]};
        return product(lr);
    }

private:

    std::array<usize,N> m_size;

    std::array<usize,N+1> m_prod;

    std::vector<T> m_sum;

};

} // namespace internal

template <concepts::Group G,usize N>
class RuisekiwaND {
public:

    using T = typename G::Element;

    template <std::integral IDX>
    RuisekiwaND(std::array<IDX,N> sz) {
        m_prod[0] = 1;
        for (usize i = 0 ; i < N ; i++) {
            m_size[i] = static_cast<usize>(sz[i]);
            m_prod[i+1] = m_prod[i]*m_size[i];
        }
        m_a.resize(m_prod[N],G::identity());
    }

    template <std::integral IDX>
    void operation(const std::array<IDX,N>& p,const T& v) {
        usize idx = 0;
        for (usize i = 0 ; i < N ; i++) {
            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));
            idx += m_prod[i]*p[i];
        }
        m_a[idx] = G::operation(m_a[idx],v);
    }

    template <std::integral IDX>
    void assign(const std::array<IDX,N>& p,T v) {
        usize idx = 0;
        for (usize i = 0 ; i < N ; i++) {
            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));
            idx += m_prod[i]*p[i];
        }
        m_a[idx] = std::move(v);
    }

    template <std::integral IDX>
    const T& get(const std::array<IDX,N>& p) const {
        assert(m_flag == false or !"RuisekiwaND::get: data is already moved");
        usize idx = 0;
        for (usize i = 0 ; i < N ; i++) {
            assert(static_cast<IDX>(0) <= p[i] and p[i] < static_cast<IDX>(m_size[i]));
            idx += m_prod[i]*p[i];
        }
        return m_a[idx];
    }

    internal::StaticHypercubeSumSolver<G,N> build() const {
        assert(m_flag == false or !"RuisekiwaND::build: data is already moved");
        return internal::StaticHypercubeSumSolver<G,N>(m_size,m_prod,m_a);
    }

    internal::StaticHypercubeSumSolver<G,N> inplaceBuild() {
        assert(m_flag == false or !"RuisekiwaND::inplaceBuild: data is already moved");
        m_flag = true;
        return internal::StaticHypercubeSumSolver<G,N>(m_size,m_prod,std::move(m_a));
    }

private:

    std::array<usize,N> m_size;

    std::array<usize,N+1> m_prod;

    std::vector<T> m_a;

    bool m_flag = false;

};

} // namespace zawa
