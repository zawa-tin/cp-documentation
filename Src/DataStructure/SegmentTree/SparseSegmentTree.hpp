#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <cassert>
#include <limits>
#include <optional>
#include <vector>

namespace zawa {

template <concepts::Monoid M>
class SparseSegmentTree {
public:

    using V = typename M::Element;

    SparseSegmentTree() = default;

    explicit SparseSegmentTree(usize n, usize poolSize = 0u) : m_n{n}, m_pool(1) {
        m_pool.reserve(poolSize);
    }

    void set(usize p, V v) {
        assert(p < size());
        set(0, p, v, 0, size());
    }

    V get(usize p) const {
        return get(0, p, 0, size());
    }

    V product(usize l, usize r) const {
        assert(l <= r and r <= size());
        return product(0, l, r, 0, size());
    }

    inline usize size() const {
        return m_n;
    }

private:

    struct node {
        static constexpr usize INVALID = std::numeric_limits<usize>::max();
        usize lch{INVALID}, rch{INVALID};
        V v{M::identity()};
    };

    static constexpr usize mid(usize l, usize r) {
        return (l & r) + ((l ^ r) >> 1);
    }
    
    void set(usize i, usize p, const V& v, usize l, usize r) {
        if (l + 1 == r) {
            m_pool[i].v = v;
            return;
        }
        const usize m = mid(l, r);
        if (p < m) {
            if (m_pool[i].lch == node::INVALID) m_pool[i].lch = makeNode();
            set(m_pool[i].lch, p, v, l, m);
        }
        else {
            if (m_pool[i].rch == node::INVALID) m_pool[i].rch = makeNode();
            set(m_pool[i].rch, p, v, m, r);
        }
        m_pool[i].v = M::operation(
                m_pool[i].lch == node::INVALID ? M::identity() : m_pool[m_pool[i].lch].v,
                m_pool[i].rch == node::INVALID ? M::identity() : m_pool[m_pool[i].rch].v
                );
    }

    V get(usize i, usize p, usize l, usize r) const {
        if (i == node::INVALID) return M::identity();
        if (l + 1 == r) return m_pool[i].v;
        const usize m = mid(l, r);
        if (p < m) return get(m_pool[i].lch, p, l, m);
        else return get(m_pool[i].rch, p, m, r);
    }

    V product(usize i, usize l, usize r, usize curL, usize curR) const {
        if (i == node::INVALID) return M::identity();
        if (r <= curL or curR <= l) return M::identity();
        if (l <= curL and curR <= r) return m_pool[i].v;
        else {
            const usize m = mid(curL, curR);
            return M::operation(
                        product(m_pool[i].lch, l, r, curL, m),
                        product(m_pool[i].rch, l, r, m, curR)
                    );
        }
    }

    usize makeNode() {
        usize res = m_pool.size();
        m_pool.emplace_back();
        return res;
    }

    usize m_n{};

    std::vector<node> m_pool{};
};

} // namespace zawa
