#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Semigroup/SemigroupConcept.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <cassert>
#include <vector>

namespace zawa {

template <concepts::Semigroup S>
class FoldableDeque {
public:

    using V = typename S::Element;

    FoldableDeque() = default;

    inline usize size() const {
        return m_front.size() + m_back.size();
    }

    inline bool empty() const {
        return m_front.empty() and m_back.empty();
    }

    void pushBack(const V& v) {
        m_back.push_back({
                m_back.empty() ? v : S::operation(m_back.back().first, v),
                v
                });
    }

    void pushFront(const V& v) {
        m_front.push_back({
                m_front.empty() ? v : S::operation(v, m_front.back().first),
                v
                });
    }

    V product() const {
        if (empty()) {
            if constexpr (Concept::Monoid<S>) {
                return S::identity();
            }
            else {
                assert(!"try to calculate product on empty deque! You must need identity for S");
            }
        }
        else {
            if (m_front.empty()) return m_back.back().first;
            if (m_back.empty()) return m_front.back().first;
            return S::operation(m_front.back().first, m_back.back().first);
        }
    }

    V popFront() {
        assert(size());
        if (m_front.empty()) moveBtoF();
        V res = std::move(m_front.back().second);
        m_front.pop_back();
        return res;
    }

    V popBack() {
        assert(size());
        if (m_back.empty()) moveFtoB();
        V res = std::move(m_back.back().second);
        m_back.pop_back();
        return res;
    }

private:

    std::vector<std::pair<V, V>> m_front, m_back;

    void moveFtoB() {
        usize sz = m_front.size() / 2;
        std::vector<V> tmp(sz); 
        for (usize i = 0 ; i < sz ; i++) {
            tmp[i] = m_front.back().second;
            m_front.pop_back();
        }
        while (m_front.size()) {
            pushBack(m_front.back().second);
            m_front.pop_back();
        }
        for (usize i = tmp.size() ; i-- ; ) {
            pushFront(tmp[i]);
        }
    }

    void moveBtoF() {
        usize sz = m_back.size() / 2;
        std::vector<V> tmp(sz); 
        for (usize i = 0 ; i < sz ; i++) {
            tmp[i] = m_back.back().second;
            m_back.pop_back();
        }
        while (m_back.size()) {
            pushFront(m_back.back().second);
            m_back.pop_back();
        }
        for (usize i = tmp.size() ; i-- ; ) {
            pushBack(tmp[i]);
        }
    }
};

} // namespace zawa
