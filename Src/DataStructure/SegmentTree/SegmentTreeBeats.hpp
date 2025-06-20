#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <cassert>
#include <vector>

namespace zawa {

// ref: https://codeforces.com/blog/entry/57319
template <class S>
class SegmentTreeBeats {
public:

    using VM = typename S::ValueMonoid;

    using OM = typename S::OperatorMonoid;

    using V = typename VM::Element;

    using O = typename OM::Element;

    static usize treeSize(usize n) {
        usize res = 1;
        while (res < n) res <<= 1;
        return res;
    }

    SegmentTreeBeats() = default;

    explicit SegmentTreeBeats(usize n) 
        : m_n{n}, m_treeSize{treeSize(n)}, m_tree(m_treeSize << 1, VM::identity()), m_lazy(m_treeSize << 1, OM::identity()) {}

    explicit SegmentTreeBeats(const std::vector<V>& a) 
        : m_n{a.size()}, m_treeSize{treeSize(a.size())}, m_tree(m_treeSize << 1, VM::identity()), m_lazy(m_treeSize << 1, OM::identity()) {
        for (usize i = 0 ; i < m_n ; i++) m_tree[m_treeSize + i] = a[i];
        for (usize i = m_treeSize ; --i >= 1 ; ) m_tree[i] = VM::operation(m_tree[i << 1 | 0], m_tree[i << 1 | 1]);
    }

    inline usize size() const noexcept {
        return m_n;
    }

    V product(usize l, usize r) {
        assert(l <= r and r <= size());
        return product(1, 0, m_treeSize, l, r);
    }

    V operator[](usize i) {
        assert(i < size());
        return product(1, 0, m_treeSize, i, i + 1);
    }

    template <class BREAK_CONDITION, class TAG_CONDITION>
    void operation(usize l, usize r, const O& act, BREAK_CONDITION breakCondition, TAG_CONDITION tagCondition) {
        assert(l <= r and r <= size());
        operation(act, 1, 0, m_treeSize, l, r, breakCondition, tagCondition);
    }

private:

    void pushDown(usize v) {
        if (v < m_treeSize) {
            const usize lch = v << 1 | 0, rch = v << 1 | 1;
            m_tree[lch] = S::mapping(m_tree[lch], m_lazy[v]);
            m_lazy[lch] = OM::operation(m_lazy[lch], m_lazy[v]);
            m_tree[rch] = S::mapping(m_tree[rch], m_lazy[v]);
            m_lazy[rch] = OM::operation(m_lazy[rch], m_lazy[v]);
            m_lazy[v] = OM::identity();
        }
    }

    void recalc(usize v) {
        m_tree[v] = VM::operation(m_tree[v << 1 | 0], m_tree[v << 1 | 1]);
    }

    V product(usize v, usize vl, usize vr, usize ql, usize qr) {
        if (vr <= ql or qr <= vl) return VM::identity();
        if (ql <= vl and vr <= qr) return m_tree[v];
        const usize m = (vl + vr) >> 1;
        pushDown(v);
        return VM::operation(
                product(v << 1 | 0, vl, m, ql, qr),
                product(v << 1 | 1, m, vr, ql, qr)
                );
    }

    template <class BREAK_CONDITION, class TAG_CONDITION>
    void operation(const O& act, usize v, usize vl, usize vr, usize ql, usize qr, BREAK_CONDITION breakCondition, TAG_CONDITION tagCondition) {
        if (vr <= ql or qr <= vl) return;
        assert(v < m_tree.size() or !"failed to operation to node such that length is 1. break_condition or/and tag_condition is something wrong");
        if (breakCondition(m_tree[v], act)) return;
        pushDown(v);
        if (ql <= vl and vr <= qr and tagCondition(m_tree[v], act)) {
            m_tree[v] = S::mapping(m_tree[v], act);
            m_lazy[v] = act; 
            return;
        }
        const usize m = (vl + vr) >> 1;
        operation(act, v << 1 | 0, vl, m, ql, qr, breakCondition, tagCondition);
        operation(act, v << 1 | 1, m, vr, ql, qr, breakCondition, tagCondition);
        recalc(v);
    }

    usize m_n{}, m_treeSize{};

    std::vector<V> m_tree{};

    std::vector<O> m_lazy{};
};

} // namespace zawa
