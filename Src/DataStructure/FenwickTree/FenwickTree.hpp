#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <vector>
#include <cassert>
#include <ostream>
#include <functional>
#include <type_traits>

namespace zawa {

template <concepts::Monoid Monoid>
class FenwickTree {
public:

    using VM = Monoid;
    
    using V = typename VM::Element;

    FenwickTree() = default;

    explicit FenwickTree(usize n) : m_n{ n }, m_bitwidth{ std::__lg(n) + 1 }, m_a(n, VM::identity()), m_dat(n + 1, VM::identity()) {
        m_dat.shrink_to_fit();
        m_a.shrink_to_fit();
    }

    explicit FenwickTree(const std::vector<V>& a) : m_n{ a.size() }, m_bitwidth{ std::__lg(a.size()) + 1 }, m_a(a), m_dat(a.size() + 1, VM::identity()) {
        m_dat.shrink_to_fit();  
        m_a.shrink_to_fit();
        for (i32 i{} ; i < static_cast<i32>(m_n) ; i++) {
            addDat(i, a[i]);
        }
    }

    inline usize size() const noexcept {
        return m_n;
    }

    // return a[i]
    const V& get(usize i) const noexcept {
        assert(i < size());
        return m_a[i];
    }

    // return a[i]
    const V& operator[](usize i) const noexcept {
        assert(i < size());
        return m_a[i];
    }

    // a[i] <- a[i] + v
    void operation(usize i, const V& v) {
        assert(i < size());
        addDat(i, v);
        m_a[i] = VM::operation(m_a[i], v);
    }

    // a[i] <- v
    void assign(usize i, const V& v) requires concepts::Inversible<Monoid> {
        assert(i < size());
        addDat(i, VM::operation(VM::inverse(m_a[i]), v));
        m_a[i] = v;
    }

    // return a[0] + a[1] + ... + a[r - 1]
    V prefixProduct(usize r) const {
        assert(r <= size());
        return product(r);
    }

    // return a[l] + a[l + 1] ... + a[r - 1]
    V product(usize l, usize r) const requires concepts::Inversible<Monoid> {
        assert(l <= r and r <= size());
        return VM::operation(VM::inverse(product(l)), product(r));
    }

    template <class Function>
    usize maxRight(usize l, const Function& f) const requires concepts::Inversible<Monoid> {
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, "maxRight's argument f must be function bool(T)");
        assert(l <= size());
        assert(f(VM::identity()));
        V sum{ VM::inverse(product(l)) }; 
        usize r{};
        for (usize bit{ m_bitwidth } ; bit ; ) {
            bit--;
            usize nxt{ r | (1u << bit) };
            if (nxt < m_dat.size() and (nxt <= l or f(VM::operation(sum, m_dat[nxt])))) {
                sum = VM::operation(sum, m_dat[nxt]);
                r = std::move(nxt);
            }
        }
        assert(l <= r);
        return r;
    }

    template <class Function>
    usize minLeft(usize r, const Function& f) const requires concepts::Inversible<Monoid> {
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(V)>>, "minLeft's argument f must be function bool(T)");
        assert(r <= size());
        assert(f(VM::identity()));
        V sum{ product(r) };
        usize l{};
        for (usize bit{ m_bitwidth } ; bit ; ) {
            bit--;
            usize nxt{ l | (1u << bit) };
            if (nxt <= r and not f(VM::operation(VM::inverse(m_dat[nxt]), sum))) {
                sum = VM::operation(VM::inverse(m_dat[nxt]), sum);
                l = std::move(nxt);
            }
        }
        assert(l <= r);
        return l;
    }

    // debug print
    friend std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {
        for (usize i{} ; i <= ft.size() ; i++) {
            os << ft.prefixProduct(i) << (i == ft.size() ? "" : " ");
        }
        return os;
    }

private:

    usize m_n{};

    usize m_bitwidth{};

    std::vector<V> m_a, m_dat;

    constexpr i32 lsb(i32 x) const noexcept {
        return x & -x;
    }
    
    // a[i] <- a[i] + v
    void addDat(i32 i, const V& v) {
        assert(0 <= i and i < static_cast<i32>(m_n));
        for ( i++ ; i < static_cast<i32>(m_dat.size()) ; i += lsb(i)) {
            m_dat[i] = VM::operation(m_dat[i], v);
        }
    }

    // return a[0] + a[1] + .. + a[i - 1]
    V product(i32 i) const {
        assert(0 <= i and i <= static_cast<i32>(m_n));
        V res{ VM::identity() };
        for ( ; i > 0 ; i -= lsb(i)) {
            res = VM::operation(res, m_dat[i]);
        }
        return res;
    }

};

} // namespace zawa
