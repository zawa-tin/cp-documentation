#pragma once

#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../SparseTable/DisjointSparseTable.hpp"

#include <cassert>
#include <vector>

namespace zawa {

template <concepts::Monoid M>
class StaticRMQ {
private:

    static constexpr usize B = 16;

    static constexpr usize LOG = 4;

    static constexpr usize MASK = 15;

    using T = typename M::Element;

public:

    StaticRMQ() = default;

    StaticRMQ(std::vector<T> A) : m_n{A.size()}, m_inner{(m_n+B-1)>>LOG}, m_pref(m_n), m_suf(m_n), m_a(std::move(A)), m_spt() {
        std::vector<T> buc;
        buc.reserve(innerSize());
        for (usize i = 0 ; i < size() ; ) {
            m_pref[i] = m_a[i];
            while (i < size() and (++i) & MASK)
                m_pref[i] = M::operation(m_pref[i-1],m_a[i]);
            buc.push_back(m_pref[i-1]);
        }
        for (usize i = size() ; i ; ) {
            i--;
            m_suf[i] = m_a[i];
            for ( ; i & MASK ; i--)
                m_suf[i-1] = M::operation(m_a[i],m_suf[i]);
        }
        m_spt = DisjointSparseTable<M>(std::move(buc));
    }

    inline usize size() const noexcept {
        return m_n;
    }

    T product(usize L,usize R) const {
        assert(L <= R and R <= size());
        const usize l = L >> LOG, r = R >> LOG;
        if (l == r) {
            T res = M::identity();
            while (L < R)
                res = M::operation(res,m_a[L++]);
            return res;
        }
        else
            return M::operation(M::operation(m_suf[L],m_spt.product(l+1,r)),m_pref[R]);
    }

    const T& operator[](usize i) const {
        assert(i < size());
        return m_a[i];
    }

private:

    usize m_n, m_inner;

    std::vector<T> m_pref,m_suf,m_a;

    DisjointSparseTable<M> m_spt;

    inline usize innerSize() const noexcept {
        return m_inner;
    }
};

} // namespace zawa
