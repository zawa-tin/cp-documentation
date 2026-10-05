#pragma once

#include "./FenwickTree.hpp"
#include "../../Algebra/Monoid/MonoidPower.hpp"
#include "../../Algebra/Group/CartesianProductGroup.hpp"

#include <vector>

namespace zawa {

template <concepts::Group G>
class LazyFenwickTree {
public:

    using T = typename G::Element;

    explicit LazyFenwickTree(usize n) : m_n{n}, m_fen{n} {}

    explicit LazyFenwickTree(const std::vector<T>& a) : m_n{a.size()}, m_fen{a.size()} {
        for (usize i = 0 ; i < size() ; i++)
            operation(i,a[i]);
    }

    inline usize size() const {
        return m_n;
    }

    void operation(usize l,usize r,T v) {
        assert(l <= r and r <= size());
        if (l < r) {
            m_fen.operation(l,{G::inverse(power(v,l)),v});
            if (r < size())
                m_fen.operation(r,{power(v,r),G::inverse(v)});
        }
    }

    T prefixProduct(usize r) const {
        assert(r <= size());
        auto [a,b] = m_fen.prefixProduct(r);
        return G::operation(a,power(b,r));
    }

    T product(usize l,usize r) const {
        assert(l <= r and r <= size());
        return G::operation(G::inverse(prefixProduct(l)),prefixProduct(r));
    }
    
    void operation(usize i,T v) {
        assert(i < size());
        operation(i,i+1,v);
    }

    T get(usize i) const {
        assert(i < size());
        return product(i,i+1);
    }

    T operator[](usize i) const {
        return get(i);
    }

    void assign(usize i,T v) {
        assert(i < size());
        operation(i,G::operation(G::inverse(get(i)),v));
    }

    std::vector<T> container() const {
        std::vector<T> res(size());
        for (usize i = 0 ; i < size() ; i++)
            res[i] = get(i);
        return res;
    }

private:

    usize m_n;

    FenwickTree<CartesianProductGroup<G>> m_fen;

    static inline T power(const T& v,u32 exp) {
        return MonoidPower<G,u32>(v,exp);
    }
};

} // namespace zawa
