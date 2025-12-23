#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

namespace internal {

template <concepts::Group G>
class StaticRectAddSolver {
public:
    
    using T = typename G::Element;

    using const_iterator = typename std::vector<std::vector<T>>::const_iterator;

    explicit StaticRectAddSolver(const std::vector<std::vector<T>>& imos) : m_H{imos.size() - 1}, m_W{imos[0].size() - 1}, m_a(imos) {
        build();
    }

    explicit StaticRectAddSolver(std::vector<std::vector<T>>&& imos) : m_H{imos.size() - 1}, m_W{imos[0].size() - 1}, m_a{std::move(imos)} {
        build();
    }

    inline usize size() const {
        return m_H;
    }

    inline usize height() const {
        return m_H;
    }

    inline usize width() const {
        return m_W;
    }

    const_iterator begin() const {
        return m_a.begin();
    }

    const_iterator end() const {
        return m_a.end();
    }

    const std::vector<T>& operator[](usize i) const {
        assert(i < height() and "invalid access m_sum[i]: StaticRectSumSolver::operator[]");
        return m_a[i];
    }

private:

    usize m_H, m_W;

    std::vector<std::vector<T>> m_a;

    void build() {
        for (usize i = 0 ; i < m_H ; i++)
            for (usize j = 1 ; j <= m_W ; j++)
                m_a[i][j] = G::operation(m_a[i][j], m_a[i][j - 1]);
        for (usize i = 1 ; i <= m_H ; i++)
            for (usize j = 0 ; j < m_W ; j++)
                m_a[i][j] = G::operation(m_a[i][j], m_a[i - 1][j]);
    }
};

} // namespace internal

template <concepts::Group G>
class Imos2D {
public:
    
    using T = typename G::Element;

    Imos2D(usize H, usize W) : m_H{H}, m_W{W}, m_imos(H + 1, std::vector<T>(W + 1, G::identity())) {}

    inline usize height() const {
        return m_H;
    }

    inline usize width() const {
        return m_W;
    }

    // [l, r) x [d, u)
    void operation(usize l, usize d, usize r, usize u, T v) {
        assert((l <= r and r <= height()) and "invalid i range: Imos2D::add");
        assert((d <= u and u <= width()) and "invalid j range: Imos2D::add");
        assert(m_moved == false and "data is already builded: Imos2D::add");
        T inv = G::inverse(v);
        m_imos[l][d] = G::operation(m_imos[l][d], v);
        m_imos[l][u] = G::operation(m_imos[l][u], inv);
        m_imos[r][d] = G::operation(m_imos[r][d], inv);
        m_imos[r][u] = G::operation(m_imos[r][u], v);
    }

    const std::vector<T>& operator[](const usize i) const {
        assert(m_moved == false and "data is already builded: Imos2D::operator[]");
        assert(i < height() and "invalid range: Imos2D::operator[]");
        return m_imos[i];
    }

    internal::StaticRectAddSolver<G> build() const {
        assert(m_moved == false and "data is already builded: Imos2D::build");
        return internal::StaticRectAddSolver<G>{m_imos};
    }

    internal::StaticRectAddSolver<G> inplaceBuild() {
        assert(m_moved == false and "data is already builded: Imos2D::build");
        m_moved = true;
        return internal::StaticRectAddSolver<G>{std::move(m_imos)};
    }

private:

    usize m_H = 0, m_W = 0;

    std::vector<std::vector<T>> m_imos;

    bool m_moved = false;
};

} // namespace zawa
