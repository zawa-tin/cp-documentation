#pragma once

#include "./SWAGable.hpp"
#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Semigroup/SemigroupConcept.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"

#include <cassert>
#include <optional>
#include <vector>

namespace zawa {

template <concepts::SWAGable S>
class FoldableDeque {
public:

    using V = typename S::Element;
    using Fold = typename S::Fold;
    using F = typename Fold::Element;

    FoldableDeque() = default;

    inline usize size() const {
        return m_front.size() + m_back.size();
    }

    inline bool empty() const {
        return m_front.empty() and m_back.empty();
    }

    void pushBack(const V& v) {
        m_back.push_back({
                m_back.empty() ? S::convert(v) : S::pushBack(m_back.back().first, v),
                v
                });
    }

    void pushFront(const V& v) {
        m_front.push_back({
                m_front.empty() ? S::convert(v) : S::pushFront(m_front.back().first, v),
                v
                });
    }

    std::pair<F, F> get() const requires concepts::Identitiable<typename S::Fold> {
        return {
            m_front.empty() ? Fold::identity() : m_front.back().first,
            m_back.empty() ? Fold::identity() : m_back.back().first
        };
    }

    std::pair<std::optional<F>, std::optional<F>> get() const {
        return {
            m_front.empty() ? std::nullopt : std::optional<F>{m_front.back().first},
            m_back.empty() ? std::nullopt : std::optional<F>{m_back.back().first}
        };
    }

    F product() const requires concepts::Monoid<typename S::Fold> {
        auto [f, b] = get();
        return Fold::operation(f, b);
    }

    F product() const requires concepts::Semigroup<typename S::Fold> {
        assert(m_front.size() or m_back.size());
        if (m_front.empty()) return m_back.back().first;
        if (m_back.empty()) return m_front.back().first;
        return S::Fold::operation(m_front.back().first, m_back.back().first);
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

    std::vector<std::pair<F, V>> m_front, m_back;

    void moveFtoB() {
        const usize sz = m_front.size() >> 1;
        std::vector<V> tmp(sz); 
        for (usize i = 0 ; i < sz ; i++) {
            tmp[i] = m_front.back().second;
            m_front.pop_back();
        }
        while (m_front.size()) {
            pushBack(m_front.back().second);
            m_front.pop_back();
        }
        for (usize i = sz ; i-- ; ) {
            pushFront(tmp[i]);
        }
    }

    void moveBtoF() {
        const usize sz = m_back.size() >> 1;
        std::vector<V> tmp(sz); 
        for (usize i = 0 ; i < sz ; i++) {
            tmp[i] = m_back.back().second;
            m_back.pop_back();
        }
        while (m_back.size()) {
            pushFront(m_back.back().second);
            m_back.pop_back();
        }
        for (usize i = sz ; i-- ; ) {
            pushBack(tmp[i]);
        }
    }
};

} // namespace zawa
