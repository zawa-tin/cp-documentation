#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

namespace internal {

template <concepts::Group G>
class StaticRectSumSolver {
public:
    
    using T = typename G::Element;

    using const_iterator = typename std::vector<std::vector<T>>::const_iterator;

    explicit StaticRectSumSolver(const std::vector<std::vector<T>>& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_sum(m_H + 1, std::vector<T>(m_W + 1, G::identity())) {
        for (usize i = 0 ; i < m_H ; i++)
            for (usize j = 0 ; j < m_W ; j++)
                m_sum[i + 1][j + 1] = G::operation(
                        G::operation(m_sum[i + 1][j], m_sum[i][j + 1]), 
                        G::operation(G::inverse(m_sum[i][j]), a[i][j])
                        );
    }

    explicit StaticRectSumSolver(std::vector<std::vector<T>>&& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_sum{std::move(a)} {
        for (usize i = 0 ; i < m_H ; i++)
            m_sum[i].push_back(G::identity());
        m_sum.push_back(std::vector<T>(m_W + 1, G::identity()));
        for (usize i = 0 ; i <= m_H ; i++)
            for (usize j = m_W ; j-- ; )
                m_sum[i][j] = G::operation(m_sum[i][j], m_sum[i][j + 1]);
        for (usize i = m_H ; i-- ; )
            for (usize j = 0 ; j <= m_W ; j++)
                m_sum[i][j] = G::operation(m_sum[i][j], m_sum[i + 1][j]);
    }

    inline usize height() const {
        return m_H;
    }

    inline usize width() const {
        return m_W;
    }

    // [l, r) x [d, u)
    T product(usize l, usize d, usize r, usize u) const {
        assert((l <= r and r <= height()) and "invalid i range: StaticRectSumSolver::product");
        assert((d <= u and u <= width()) and "invalid j range: StaticRectSumSolver::product");
        return G::operation(
                G::operation(m_sum[r][u], m_sum[l][d]),
                G::inverse(G::operation(m_sum[r][d], m_sum[l][u]))
                );
    }

    const std::vector<T>& operator[](usize i) const {
        assert(i <= height() and "invalid access m_sum[i]: StaticRectSumSolver::operator[]");
        return m_sum[i];
    }

    const_iterator begin() const {
        return m_sum.begin();
    }
    
    const_iterator end() const {
        return m_sum.end();
    }

private:

    usize m_H, m_W;

    std::vector<std::vector<T>> m_sum;
};

} // namespace internal

template <concepts::Group G>
class Ruisekiwa2D {
public:
    
    using T = typename G::Element;

    Ruisekiwa2D(usize H, usize W) : m_H{H}, m_W{W}, m_a(H, std::vector<T>(W, G::identity())) {}

    explicit Ruisekiwa2D(std::vector<std::vector<T>>&& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_a{std::move(a)} {}

    explicit Ruisekiwa2D(const std::vector<std::vector<T>>& a) : m_H{a.size()}, m_W{a.empty() ? 0u : a[0].size()}, m_a{a} {}

    inline usize height() const {
        return m_H;
    }

    inline usize width() const {
        return m_W;
    }

    void operation(usize i, usize j, T v) {
        assert((i < height() and j < width()) and "invalid range: Ruisekiwa2D::operation");
        assert(m_moved == false and "already destructed: Ruisekiwa2D::operation");
        m_a[i][j] = G::operation(m_a[i][j], v);
    }

    const std::vector<T>& operator[](const usize i) const {
        assert(i < height() and "invalid range: Ruisekiwa2D::operator[]");
        assert(m_moved == false and "already destructed: Ruisekiwa2D::operator[]");
        return m_a[i];
    }

    internal::StaticRectSumSolver<G> build() const {
        assert(m_moved == false and "already destructed: Ruisekiwa2D::build");
        return internal::StaticRectSumSolver<G>{m_a};
    }

    internal::StaticRectSumSolver<G> inplaceBuild() {
        assert(m_moved == false and "already destructed: Ruisekiwa2D::build");
        m_moved = true;
        return internal::StaticRectSumSolver<G>{std::move(m_a)};
    }

private:

    usize m_H = 0, m_W = 0;

    std::vector<std::vector<T>> m_a;

    bool m_moved = false;
};

} // namespace zawa
