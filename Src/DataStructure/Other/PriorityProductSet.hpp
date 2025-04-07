#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"

#include <cassert>
#include <optional>
#include <utility>
#include <queue>

namespace zawa {

// 1-indexed
template <Concept::Group G>
class PriorityProductSet {
public:

    using V = G::Element;

    PriorityProductSet() = default;

    PriorityProductSet(usize K) : m_K{K} {}

    void insert(V&& v) {
        pushSmall(std::move(v));
        adjust();
    }

    void insert(const V& v) {
        insert(V{v});
    }

    usize size() const {
        return m_small.size() + m_big.size();
    }

    inline usize K() const {
        return m_K;
    }

    void setK(usize K) {
        m_K = K;
        adjust();
    }

    std::optional<V> product() const {
        return m_small.size() == m_K ? std::optional<V>{m_sv} : std::nullopt;
    }

    std::optional<V> productRemain() const {
        return m_small.size() == m_K ? std::optional<V>{m_bv} : std::nullopt;
    }

    V productAll() const {
        return G::operation(m_sv, m_bv);
    }

    V popK() {
        assert(m_K >= 1u and size() >= m_K);
        V res = popSmall(); 
        adjust();
        return res;
    }

private:

    std::priority_queue<V> m_small;

    std::priority_queue<V, std::vector<V>, std::greater<V>> m_big;

    V m_sv = G::identity(), m_bv = G::identity();

    usize m_K = 0;

    void pushSmall(V&& v) {
        m_sv = G::operation(m_sv, v);
        m_small.push(std::move(v));
    }

    V popSmall() {
        assert(m_small.size());
        V res = m_small.top();
        m_small.pop();
        m_sv = G::operation(m_sv, G::inverse(res));
        return res;
    }

    void pushBig(V&& v) {
        m_bv = G::operation(m_bv, v);
        m_big.push(std::move(v));
    }

    V popBig() {
        assert(m_big.size());
        V res = m_big.top();
        m_big.pop();
        m_bv = G::operation(m_bv, G::inverse(res));
        return res;
    }

    void adjust() {
        while (m_small.size() > m_K) pushBig(popSmall());
        while (m_small.size() < m_K and m_big.size()) pushSmall(popBig());
    }
};

} // namespace zawa
