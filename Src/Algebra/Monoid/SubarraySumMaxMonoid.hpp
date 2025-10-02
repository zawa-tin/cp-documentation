#pragma once

#include <algorithm>
#include <concepts>
#include <optional>

namespace zawa {

template <std::totally_ordered T>
class SubarraySumMax {
public:

    SubarraySumMax() = default;

    explicit SubarraySumMax(T v) : m_ans{v}, m_sum{v}, m_pref{v}, m_suf{v} {}

    SubarraySumMax(T ans, T sum, T pref, T suf) : m_ans{ans}, m_sum{sum}, m_pref{pref}, m_suf{suf} {}

    inline T ans() const {
        return m_ans;
    }

    inline T sum() const {
        return m_sum;
    }

    inline T pref() const {
        return m_pref;
    }

    inline T suf() const {
        return m_suf;
    }

    static SubarraySumMax<T> merge(const SubarraySumMax<T>& lhs, const SubarraySumMax<T>& rhs) {
        T sum = lhs.sum() + rhs.sum();
        T pref = std::max(lhs.pref(), lhs.sum() + rhs.pref());
        T suf = std::max(rhs.suf(), lhs.suf() + rhs.sum());
        T ans = std::max({lhs.ans(), rhs.ans(), lhs.suf() + rhs.pref()});
        return {ans, sum, pref, suf};
    }

private:

    T m_ans{}, m_sum{}, m_pref{}, m_suf{};

};

template <std::totally_ordered T>
struct SubarraySumMaxMonoid {

    using Element = std::optional<SubarraySumMax<T>>;

    static Element identity() {
        return std::nullopt;
    }

    static Element operation(const Element& L, const Element& R) {
        if (!L) return R;
        if (!R) return L;
        return Element::value_type::merge(L.value(), R.value());
    }

    static Element convert(T v) {
        return Element{v};
    }
};

} // namespace zawa
