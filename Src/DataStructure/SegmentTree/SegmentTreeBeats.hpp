#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./SegmentTreeConcept.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <ranges>
#include <vector>

namespace zawa {

// ref: https://codeforces.com/blog/entry/57319
template <concepts::MonoidWithAction S>
class SegmentTreeBeats {
public:

    using VM = typename S::ValueMonoid;

    using OM = typename S::OperatorMonoid;

    using V = typename VM::Element;

    using O = typename OM::Element;

    SegmentTreeBeats() = default;

    explicit SegmentTreeBeats(usize n) 
        : m_n{n}, m_sz{1u << std::bit_width(n)}, m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {}

    explicit SegmentTreeBeats(const std::vector<V>& a) 
        : m_n{a.size()}, m_sz{1u << std::bit_width(a.size())}, m_dat(m_sz << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {
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

    template <class BREAK_CONDITION, class TAG_CONDITION>
    requires (std::predicate<BREAK_CONDITION, V, O> and std::predicate<TAG_CONDITION, V, O>)
    void operation(usize l, usize r, const O& o, BREAK_CONDITION break_condition, TAG_CONDITION tag_condition) {
        assert(l <= r and r <= size());
        operation(l, r, o, 1, 0, inner_size(), break_condition, tag_condition);
    }

    void assign(usize i, const V& v) {
        assert(i < size());
        assign(i, v, 1, 0, inner_size());
    }

    template <class BREAK_CONDITION, class TAG_CONDITION>
    requires (std::predicate<BREAK_CONDITION, V, O> and std::predicate<TAG_CONDITION, V, O>)
    void operation(usize i, const O& o, BREAK_CONDITION break_condition, TAG_CONDITION tag_condition) {
        assert(i < size());
        operation(i, o, 1, 0, inner_size(), break_condition, tag_condition);
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

    std::vector<V> m_dat{};

    std::vector<O> m_lazy{};

    inline usize inner_size() const noexcept {
        return m_sz;
    }

    void recalc(usize v) {
        m_dat[v] = VM::operation(m_dat[v << 1 | 0], m_dat[v << 1 | 1]);
    }

    void propagate(usize v) {
        if (v < inner_size()) {
            const usize lch = v << 1 | 0, rch = v << 1 | 1;
            m_dat[lch] = S::mapping(m_dat[lch], m_lazy[v]);
            m_lazy[lch] = OM::operation(m_lazy[lch], m_lazy[v]);
            m_dat[rch] = S::mapping(m_dat[rch], m_lazy[v]);
            m_lazy[rch] = OM::operation(m_lazy[rch], m_lazy[v]);
            m_lazy[v] = OM::identity();
        }
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

    template <class BREAK_CONDITION, class TAG_CONDITION>
    requires (std::predicate<BREAK_CONDITION, V, O> and std::predicate<TAG_CONDITION, V, O>)
    void operation(usize ql, usize qr, const O& o, usize nd, usize nl, usize nr, BREAK_CONDITION break_condition, TAG_CONDITION tag_condition) {
        assert(nd < m_dat.size() or !"failed to operation to node such that length is 1. break_condition or/and tag_condition is something wrong");
        if (qr <= nl or nr <= ql or break_condition(m_dat[nd], o)) return;
        if (ql <= nl and nr <= qr and tag_condition(m_dat[nd], o)) {
            m_dat[nd] = S::mapping(m_dat[nd], o);
            m_lazy[nd] = OM::operation(m_lazy[nd], o);
            return;
        }
        propagate(nd);
        const usize m = (nl + nr) >> 1;
        operation(ql, qr, o, nd << 1 | 0, nl, m, break_condition, tag_condition);
        operation(ql, qr, o, nd << 1 | 1, m, nr, break_condition, tag_condition);
        recalc(nd);
    }

    template <class BREAK_CONDITION, class TAG_CONDITION>
    requires (std::predicate<BREAK_CONDITION, V, O> and std::predicate<TAG_CONDITION, V, O>)
    void operation(usize i, const O& o, usize nd, usize nl, usize nr, BREAK_CONDITION break_condition, TAG_CONDITION tag_condition) {
        if (break_condition(m_dat[nd], o)) return;
        if (nd >= inner_size()) {
            assert(tag_condition(m_dat[nd], o) or !"failed to operation to node such that length is 1. break_condition or/and tag_condition is something wrong");
            m_dat[nd] = S::mapping(m_dat[nd], o);
            // 葉頂点なので、lazyへのopは不要
            return;
        }
        propagate(nd); 
        const usize m = (nl + nr) >> 1;
        i < m ? operation(i, o, nd << 1 | 0, nl, m, break_condition, tag_condition) : operation(i, o, nd << 1 | 1, m, nr, break_condition, tag_condition);
        recalc(nd);
    }

    void assign(usize i, const V& v, usize nd, usize nl, usize nr) {
        if (nd >= inner_size()) {
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
