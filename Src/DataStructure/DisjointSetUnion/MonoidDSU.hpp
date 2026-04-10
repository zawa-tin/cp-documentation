#pragma once

#include "./DisjointSetUnion.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <vector>

namespace zawa {

// 可換じゃないとダメだよ
template <concepts::Monoid M>
class MonoidDSU {
public:

    MonoidDSU() = default;

    MonoidDSU(usize n) : m_dsu{n}, m_prod(n,M::identity()) {}

    MonoidDSU(std::vector<typename M::Element> A) : m_dsu{A.size()}, m_prod{std::move(A)} {}

    u32 leader(usize v) {
        return m_dsu.leader(v);
    }

    bool same(usize u,usize v) {
        return m_dsu.same(u,v);
    }

    bool merge(usize u,usize v) {
        u = leader(u);
        v = leader(v);
        if (u == v)
            return false;
        m_dsu.merge(u,v);
        m_prod[leader(u)] = M::operation(m_prod[u],m_prod[v]);
        return true;
    }

    inline usize size() const noexcept {
        return m_dsu.size();
    }

    inline usize components() const noexcept {
        return m_dsu.components();
    }

    template <class T>
    std::vector<std::vector<T>> enumerate() requires std::convertible_to<usize,T> {
        return m_dsu.enumerate();
    }

    const M::Element& operator[](usize i) {
        assert(i < size());
        return m_prod[leader(i)];
    }

private:

    DisjointSetUnion m_dsu;

    std::vector<typename M::Element> m_prod;

};

} // namespace zawa
