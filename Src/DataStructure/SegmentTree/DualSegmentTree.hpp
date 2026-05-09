#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../../Algebra/Action/ActionConcept.hpp"

#include <bit>
#include <cassert>
#include <concepts>
#include <vector>

namespace zawa {

template <class M,class T,bool Commutative = false>
requires concepts::Monoid<M> and concepts::Action<M,T>
class DualSegmentTree {
public:

    using O = M::Element;

    DualSegmentTree() = default;

    explicit DualSegmentTree(usize n) : m_n{n}, m_a(n), m_seg(n<<1,M::identity()) {}

    explicit DualSegmentTree(usize n,T init) : m_n{n}, m_a(n,init), m_seg(n<<1,M::identity()) {}

    explicit DualSegmentTree(std::vector<T> a) : m_n{a.size()}, m_a{std::move(a)}, m_seg(m_n<<1,M::identity()) {}

    inline usize size() const {
        return m_n;
    }

    void operation(usize l,usize r,O o) {
        assert(l <= r and r <= size());
        if constexpr (!Commutative) {
            push(l);
            if (l < r)
                push(r-1);
        }
        for (l += size(), r += size() ; l < r ; l >>= 1, r >>= 1) {
            if (l & 1) {
                m_seg[l] = M::operation(m_seg[l],o);
                l++;
            }
            if (r & 1) {
                r--;
                m_seg[r] = M::operation(m_seg[r],o);
            }
        }
    }

    void operation(usize i,O o) {
        assert(i < size());
        if constexpr (!Commutative)
            push(i);
        m_seg[i+size()] = std::move(o);
    }

    T get(usize i) const {
        assert(i < size());
        O prod = M::identity();
        for (usize v = i+size() ; v ; v >>= 1)
            prod = M::operation(prod,m_seg[v]);
        return M::action(prod,m_a[i]);
    }

    T operator[](usize i) const {
        assert(i < size());
        return get(i);
    }

    void assignOperator(usize i,O o) {
        assert(i < size());
        push(i);
        m_seg[i+size()] = std::move(o);
    }

    void assign(usize i,T x) {
        assert(i < size());
        assignOperator(i,M::identity());
        m_a[i] = std::move(x);
    }

    std::vector<T> container() const {
        std::vector<T> res(size());
        for (usize i = 0 ; i < size() ; i++)
            res[i] = get(i);
        return res;
    }

private:

    void push(usize i) {
        assert(i < size());
        i += size();
        for (usize j = std::bit_width(i) ; --j ; ) {
            usize v = i >> j;
            m_seg[v<<1|0] = M::operation(m_seg[v<<1|0],m_seg[v]);
            m_seg[v<<1|1] = M::operation(m_seg[v<<1|1],m_seg[v]);
            m_seg[v] = M::identity();
        }
    }

    usize m_n;

    std::vector<T> m_a;

    std::vector<O> m_seg;
};

} // namespace zawa
