#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./SegmentTreeConcept.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <ranges>
#include <tuple>
#include <vector>

namespace zawa {

template <concepts::MonoidWithAction S>
class LazySegmentTree {
public:

    using VM = S::ValueMonoid;

    using V = typename VM::Element;

    using OM = S::OperatorMonoid;

    using O = typename OM::Element;

    LazySegmentTree() = default;

    explicit LazySegmentTree(usize n) 
        : m_n{n}, m_sz{1u << (std::bit_width(n))}, m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {}

    explicit LazySegmentTree(const std::vector<V>& a)
        : m_n{a.size()}, m_sz{1u << (std::bit_width(a.size()))}, m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {
        std::ranges::copy(a, m_dat.begin() + inner_size());
        for (usize i = inner_size() ; --i ; ) recalc(i);
    }

    [[nodiscard]] inline usize size() const noexcept {
        return m_n;
    }

    [[nodiscard]] V operator[](usize i) {
        assert(i < size());
        return get(i, 1, 0, inner_size());
    }

    [[nodiscard]] V get(usize i) {
        return (*this)[i];
    }

    [[nodiscard]] V product(usize l, usize r) {
        assert(l <= r and r <= size());
        return product(l, r, 1, 0, inner_size());
    }

    void operation(usize l, usize r, const O& o) {
        assert(l <= r and r <= size());
        return operation(l, r, o, 1, 0, inner_size());
    }

    void assign(usize i, const V& v) {
        assert(i < size());
        assign(i, v, 1, 0, inner_size());
    }

    void operation(usize i, const O& o) {
        assert(i < size());
        operation(i, o, 1, 0, inner_size());
    }

private:

    using NodeInfo = std::tuple<usize, usize, usize>;

public:

    template <class F>
    requires std::predicate<F, V>
    usize maxRight(usize l, F f) {
        assert(l <= size());
        if (!f(VM::identity())) return l;
        if (l == size()) return size();
        std::vector<NodeInfo> ranges;
        partition_range(l, size(), ranges, 1, 0, inner_size());
        V prod = VM::identity();
        for (auto [nd, nl, nr] : ranges) {
            if (!f(VM::operation(prod, m_dat[nd]))) {
                return maxRight(f, prod, nd, nl, nr);
            }
            else {
                prod = VM::operation(prod, m_dat[nd]);
            }
        }
        return size();
    }

    template <class F>
    requires std::predicate<F, V>
    usize minLeft(usize r, F f) {
        assert(r <= size());
        if (!f(VM::identity())) return r;
        if (!r) return 0;
        std::vector<NodeInfo> ranges;
        partition_range(0, r, ranges, 1, 0, inner_size());
        V prod = VM::identity();
        for (auto [nd, nl, nr] : ranges | std::views::reverse) {
            if (!f(VM::operation(m_dat[nd], prod))) {
                return minLeft(f, prod, nd, nl, nr);
            }
            else {
                prod = VM::operation(prod, m_dat[nd]);
            }
        }
        return 0;
    }

private:

    usize m_n{}, m_sz{};

    std::vector<V> m_dat;

    std::vector<O> m_lazy;

    inline usize inner_size() const noexcept {
        return m_sz;
    }
    
    void recalc(usize nd) {
        // assert(nd < inner_size());
        m_dat[nd] = VM::operation(m_dat[nd << 1 | 0], m_dat[nd << 1 | 1]);
    }

    void propagate(usize nd) {
        // assert(nd < inner_size());
        for (usize ch : {nd << 1 | 0, nd << 1 | 1}) {
            m_dat[ch] = S::mapping(m_dat[ch], m_lazy[nd]);
            m_lazy[ch] = OM::operation(m_lazy[ch], m_lazy[nd]);
        }
        m_lazy[nd] = OM::identity();
    }

    V product(usize ql, usize qr, usize nd, usize nl, usize nr) {
        if (qr <= nl or nr <= ql) return VM::identity();
        if (ql <= nl and nr <= qr) return m_dat[nd];
        propagate(nd);
        const usize m = (nl + nr) >> 1;
        return VM::operation(
                product(ql, qr, nd << 1 | 0, nl, m),
                product(ql, qr, nd << 1 | 1, m, nr)
                );
    }

    V get(usize i, usize nd, usize nl, usize nr) {
        if (nd >= inner_size()) return m_dat[nd];
        propagate(nd);
        const usize m = (nl + nr) >> 1;
        return i < m ? get(i, nd << 1 | 0, nl, m) : get(i, nd << 1 | 1, m, nr);
    }

    void operation(usize ql, usize qr, const O& o, usize nd, usize nl, usize nr) {
        if (qr <= nl or nr <= ql) return;
        if (ql <= nl and nr <= qr) {
            m_dat[nd] = S::mapping(m_dat[nd], o);
            m_lazy[nd] = OM::operation(m_lazy[nd], o);
            return;
        }
        propagate(nd);
        const usize m = (nl + nr) >> 1;
        operation(ql, qr, o, nd << 1 | 0, nl, m);
        operation(ql, qr, o, nd << 1 | 1, m, nr);
        recalc(nd);
    }

    void operation(usize i, const O& o, usize nd, usize nl, usize nr) {
        if (nl == i and i + 1 == nr) {
            m_dat[nd] = S::mapping(m_dat[nd], o);
            // 葉頂点なので、lazyへのopは不要
            return;
        }
        propagate(nd); 
        const usize m = (nl + nr) >> 1;
        i < m ? operation(i, o, nd << 1 | 0, nl, m) : operation(i, o, nd << 1 | 1, m, nr);
        recalc(nd);
    }

    void assign(usize i, const V& v, usize nd, usize nl, usize nr) {
        if (nl == i and i + 1 == nr) {
            m_dat[nd] = v;
            return;
        }
        propagate(nd); 
        const usize m = (nl + nr) >> 1;
        i < m ? assign(i, v, nd << 1 | 0, nl, m) : assign(i, v, nd << 1 | 1, m, nr);
        recalc(nd);
    }

    void partition_range(usize ql, usize qr, std::vector<NodeInfo>& res, usize nd, usize nl, usize nr) {
        if (qr <= nl or nr <= ql) return;
        if (ql <= nl and nr <= qr) {
            res.emplace_back(nd, nl, nr);
            return;
        }
        propagate(nd);
        const usize m = (nl + nr) >> 1;
        partition_range(ql, qr, res, nd << 1 | 0, nl, m);
        partition_range(ql, qr, res, nd << 1 | 1, m, nr);
    }

    template <class F>
    requires std::predicate<F, V>
    usize maxRight(F f, const V& prod, usize nd, usize nl, usize nr) {
        if (nd >= inner_size()) return nl;
        propagate(nd);
        const usize m = (nl + nr) >> 1, lch = nd << 1 | 0, rch = nd << 1 | 1;
        return f(VM::operation(prod, m_dat[lch])) ? 
            maxRight(f, VM::operation(prod, m_dat[lch]), rch, m, nr) : maxRight(f, prod, lch, nl, m);
    }

    template <class F>
    requires std::predicate<F, V>
    usize minLeft(F f, const V& prod, usize nd, usize nl, usize nr) {
        if (nd >= inner_size()) return nr;
        propagate(nd);
        const usize m = (nl + nr) >> 1, lch = nd << 1 | 0, rch = nd << 1 | 1;
        return f(VM::operation(m_dat[rch], prod)) ? 
            minLeft(f, VM::operation(m_dat[rch], prod), lch, nl, m) : minLeft(f, prod, rch, m, nr);
    }
};

} // namespace zawa
