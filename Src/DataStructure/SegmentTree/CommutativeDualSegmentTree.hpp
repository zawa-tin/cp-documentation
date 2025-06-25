#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <bit>
#include <cassert>
#include <vector>
#include <iterator>
#include <ostream>

namespace zawa {

template <concepts::Monoid Monoid>
class CommutativeDualSegmentTree {
public:

    using OM = Monoid;

    using O = typename OM::Element;

    using VM = Monoid;

    using V = typename VM::Element;

    CommutativeDualSegmentTree() = default;

    explicit CommutativeDualSegmentTree(usize n) 
        : m_n{ n }, m_dat((n << 1), VM::identity()) {}

    explicit CommutativeDualSegmentTree(const std::vector<O>& dat) 
        : m_n{ dat.size() }, m_dat((m_n << 1), VM::identity()) {
        initDat(dat.begin(), dat.end());
    }

    template <class InputIterator>
    CommutativeDualSegmentTree(InputIterator first, InputIterator last)
        : m_n{ static_cast<usize>(std::distance(first, last)) }, m_dat((m_n << 1), OM::identity()) {
        initDat(first, last);
    }

    [[nodiscard]] inline usize size() const noexcept {
        return m_n;
    }

    virtual void operation(usize l, usize r, const O& v) {
        assert(l <= r and r <= size());
        for (l += size(), r += size() ; l < r ; l = parent(l), r = parent(r)) {
            if (l & 1) {
                m_dat[l] = OM::operation(m_dat[l], v);
                l++;
            }
            if (r & 1) {
                r--;
                m_dat[r] = OM::operation(m_dat[r], v);
            }
        }
    }

    // 未verify
    virtual void operation(usize i, const O& o) {
        assert(i < size());
        m_dat[i + size()] = OM::operation(m_dat[i + size()], o);
    }

    void assign(usize i, const V& v) {
        assert(i < size());
        push(i);
        m_dat[i + size()] = v;
    }

    [[nodiscard]] virtual V operator[](usize i) {
        assert(i < size());
        V res{ VM::identity() };
        for (i += size() ; i ; i = parent(i)) {
            res = VM::operation(res, m_dat[i]);
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const CommutativeDualSegmentTree seg) {
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
            m_dat[left(v)] = OM::operation(m_dat[left(v)], m_dat[v]);
            m_dat[right(v)] = OM::operation(m_dat[right(v)], m_dat[v]);
            m_dat[v] = OM::identity();
        }
    }

};

} // namespace zawa
