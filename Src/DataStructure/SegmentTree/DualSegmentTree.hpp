#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../../Algebra/Action/ActionConcept.hpp"

#include <bit>
#include <cassert>
#include <vector>
#include <iterator>
#include <ostream>

namespace zawa {

template <concepts::Monoid Monoid>
class DualSegmentTree {
public:

    using VM = Monoid;

    using V = typename VM::Element;

    DualSegmentTree() = default;

    explicit DualSegmentTree(usize n) 
        : m_n{ n }, m_dat((n << 1), VM::identity()) {}

    explicit DualSegmentTree(const std::vector<V>& dat) 
        : m_n{ dat.size() }, m_dat((m_n << 1), VM::identity()) {
        initDat(dat.begin(), dat.end());
    }

    template <class InputIterator>
    DualSegmentTree(InputIterator first, InputIterator last)
        : m_n{ static_cast<usize>(std::distance(first, last)) }, m_dat((m_n << 1), VM::identity()) {
        initDat(first, last);
    }

    [[nodiscard]] inline usize size() const noexcept {
        return m_n;
    }

    template <class O>
    requires concepts::Acted<Monoid, O>
    void operation(usize l, usize r, const O& v) {
        assert(l <= r and r <= size());
        push(l);
        if (l < r)
            push(r - 1);
        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r)) {
            if (l & 1) {
                m_dat[l] = VM::acted(m_dat[l], v);
                l++;
            }
            if (r & 1) {
                r--;
                m_dat[r] = VM::acted(m_dat[r], v);
            }
        }
    }

    template <class O>
    requires concepts::Acted<Monoid, O>
    void operation(usize i, const O& o) {
        assert(i < size());
        push(i);
        m_dat[i + size()] = VM::acted(m_dat[i + size()], o);
    }

    void assign(usize i, const V& v) {
        assert(i < size());
        push(i);
        m_dat[i + size()] = v;
    }

    [[nodiscard]] V operator[](usize i) {
        assert(i < size());
        push(i);
        V res{ VM::identity() };
        for (i += size() ; i ; i = parent(i))
            res = VM::operation(res, m_dat[i]);
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const DualSegmentTree seg) {
        usize size{ seg.m_dat.size() };
        for (usize i{1} ; i < size ; i++) {
            os << seg.m_dat[i] << (i + 1 == size ? "" : " ");
        }
        return os;
    }

protected:

    static constexpr usize parent(usize v) noexcept {
        return v >> 1;
    }

    static constexpr usize left(usize v) noexcept {
        return v << 1;
    }

    static constexpr usize right(usize v) noexcept {
        return v << 1 | 1;
    }

    usize m_n;

    std::vector<V> m_dat;

    template <class InputIterator>
    inline void initDat(InputIterator first, InputIterator last) {
        for (auto it{ first } ; it != last ; it++) {
            m_dat[size() + std::distance(first, it)] = *it;
        }
    }

    void push(usize i) {
        assert(i < size());
        i += size();
        usize height{ 64u - std::countl_zero(i) };
        for (usize h{ height } ; --h ; ) {
            usize v{ i >> h };
            m_dat[left(v)] = VM::operation(m_dat[left(v)], m_dat[v]);
            m_dat[right(v)] = VM::operation(m_dat[right(v)], m_dat[v]);
            m_dat[v] = VM::identity();
        }
    }

};

} // namespace zawa
