#pragma once

#include "./SWAGable.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "../../Algebra/Semigroup/SemigroupConcept.hpp"
#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <optional>
#include <vector>

namespace zawa {

template <concepts::SWAGable S>
class FoldableQueue {
public:

    using V = typename S::Element;
    using Fold = typename S::Fold;
    using F = typename Fold::Element;

    FoldableQueue() = default;

    usize size() const noexcept {
        return m_front.size() + m_back.size();
    }

    bool empty() const noexcept {
        return size() == 0u;
    }

    void push(const V& v) {
        m_raw.push_back(v);
        m_back.push_back(m_back.size() ? S::pushBack(m_back.back(), v) : S::convert(v));
    }

    void pop() {
        assert(size());
        move();
        m_front.pop_back();
    }

    std::pair<F, F> get() const requires concepts::Identitiable<typename S::Fold> {
        return {
            m_front.empty() ? Fold::identity() : m_front.back(),
            m_back.empty() ? Fold::identity() : m_back.back()
        };
    }

    std::pair<std::optional<F>, std::optional<F>> get() const {
        return {
            m_front.empty() ? std::nullopt : std::optional<F>{m_front.back()},
            m_back.empty() ? std::nullopt : std::optional<F>{m_back.back()}
        };
    }

    F product() const requires concepts::Monoid<typename S::Fold> {
        auto [f, b] = get();
        return Fold::operation(f, b);
    }

    F product() const requires concepts::Semigroup<typename S::Fold> {
        assert(m_front.size() or m_back.size());
        if (m_front.empty()) return m_back.back();
        if (m_back.empty()) return m_front.back();
        return S::Fold::operation(m_front.back(), m_back.back());
    }
    
private:
    std::vector<F> m_front{}, m_back{};
    std::vector<V> m_raw{};

    void move() {
        if (m_front.size()) return;
        while (m_back.size()) {
            m_back.pop_back();
            V v{m_raw.back()};
            m_raw.pop_back();
            m_front.push_back(m_front.size() ? S::pushFront(m_front.back(), v) : S::convert(v));
        }
    }
};

} // namespace zawa
