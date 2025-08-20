#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../../Algebra/Action/ActionConcept.hpp"

#include <bit>
#include <cassert>
#include <concepts>
#include <vector>

namespace zawa {

template <concepts::Monoid M>
class DisjointSparseTable {
public:

    using V = typename M::Element;

    constexpr usize height(usize n) const {
        return std::max(usize{1}, std::bit_width(n) - (usize)std::has_single_bit(n));
    }

    constexpr usize msb(usize n) const {
        assert(n);
        return std::bit_width(n) - 1;
    }

    template <class S>
    requires std::same_as<V, S> or concepts::Acted<V, S>
    DisjointSparseTable(const std::vector<S>& A) : m_table(height(A.size())) {
        assert(A.size());
        for (usize i = 1, w = 2 ; i < m_table.size() ; i++, w <<= 1) {
            m_table[i].resize(A.size());
            for (usize j = 0, idx = 0 ; j < A.size() ; j += w, idx++) {
                V prod = M::identity();
                if (idx & 1) { // ->
                    usize m = std::min(A.size() - j, w);
                    for (usize k = 0 ; k < m ; k++) {
                        if constexpr (std::same_as<V, S>)
                            prod = M::operation(prod, A[j + k]);
                        else
                            prod = M::acted(prod, A[j + k]);
                        m_table[i][j + k] = prod;
                    }
                }
                else { // <-
                    usize m = std::min(A.size(), j + w);
                    for (usize k = m ; k-- > j ; ) {
                        if constexpr (std::same_as<V, S>)
                            prod = M::operation(A[k], prod);
                        else
                            prod = M::acted(prod, A[k]);
                        m_table[i][k] = prod;
                    }
                }
            }
        }
        m_table[0].resize(A.size());
        for (usize i = 0 ; i < A.size() ; i++) {
            if constexpr (std::same_as<V, S>)
                m_table[0][i] = A[i];
            else
                m_table[0][i] = M::acted(M::identity(), A[i]);
        }
    }

    template <std::input_iterator It>
    DisjointSparseTable(It first, It last) : DisjointSparseTable(std::vector(first, last)) {}

    V product(usize l, usize r) const {
        assert(l <= r and r <= m_table[0].size());
        if (l == r) return M::identity();
        if (l + 1 == r) return m_table[0][l];
        usize y = msb(l xor --r);
        return M::operation(m_table[y][l], m_table[y][r]);
    }

private:

    std::vector<std::vector<V>> m_table;
};

} // namespace zawa
