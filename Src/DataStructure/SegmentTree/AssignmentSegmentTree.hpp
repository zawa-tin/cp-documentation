#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "./SegmentTree.hpp"

#include <cassert>
#include <vector>
#include <set>

namespace zawa {

namespace concepts {

template <class T, class U>
concept Powerable = requires {
    typename T::Element;
    { T::power(std::declval<typename T::Element>(), std::declval<U>()) }
        -> std::same_as<typename T::Element>;
};

template <class T>
concept EqualCompare = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
};

template <class T>
concept FastPowerableMonoid = Monoid<T> and Powerable<T, u64>;

} // namespace concepts

template <concepts::Monoid Monoid>
class AssignmentSegmentTree {
public:

    using VM = Monoid;

    using V = typename VM::Element;

    AssignmentSegmentTree() = default;

    explicit AssignmentSegmentTree(usize n) : m_seg{n}, m_dat(n, VM::identity()), m_ls{} {
        m_dat.shrink_to_fit();
        assert(n);
        m_ls.insert(0u);
        m_ls.insert(n);
    }

    explicit AssignmentSegmentTree(std::vector<V> dat) : m_seg{}, m_dat{dat}, m_ls{} {
        // dat: 区間の左端lにa_{l}^{r-l}, それ以外のiはidentity()にする -> セグ木にこれをのせる
        // m_dat: 区間の左端lにa_{l}, それ以外のiはidentity()にする
        m_dat.shrink_to_fit();
        if constexpr (concepts::EqualCompare<V>) {
            for (usize i{}, j{} ; i < m_dat.size() ; ) {
                while (j < dat.size() and dat[i] == dat[j]) j++;
                m_ls.insert(i);
                dat[i] = power(m_dat[i], j - i);
                for ( ; ++i < j ; dat[i] = m_dat[i] = VM::identity()) ;
            }
        }
        else {
            for (usize i{} ; i < m_dat.size() ; i++) m_ls.insert(i);
        }
        m_ls.insert(dat.size());
        m_seg = decltype(m_seg){dat};
    }

    [[nodiscard]] inline usize size() const noexcept {
        return m_dat.size();
    }

    [[nodiscard]] V product(usize l, usize r) const {
        assert(l <= r and r <= size());
        if (l == r) return VM::identity();
        const auto second_l = m_ls.upper_bound(l);
        const auto first_l = std::prev(second_l);
        if (second_l != m_ls.end() and r <= *second_l) { // 一つの区間に含まれている
            return power(m_dat[*first_l], r - l);
        }
        const auto last_l = std::prev(m_ls.upper_bound(r));
        V res = VM::operation(
                power(m_dat[*first_l], *second_l - l),
                m_seg.product(*second_l, *last_l)
                );
        if (r == *last_l) return res;
        return VM::operation(res, power(m_dat[*last_l], r - *last_l));
    }

    void assign(usize l, usize r, V v) {
        assert(l <= r and r <= m_dat.size());
        if (l == r) return;
        // assert(*it_l < n);
        auto it_l = std::prev(m_ls.upper_bound(l)), it_r = std::prev(m_ls.upper_bound(r)); 
        if (*it_l < l) m_seg.assign(*it_l, power(m_dat[*it_l], l - *it_l));
        m_seg.assign(l, power(v, r - l));
        if (*it_r < r and r < m_dat.size()) {
            m_dat[r] = m_dat[*it_r];
            m_seg.assign(r, power(m_dat[r], *std::next(it_r) - r));
            m_ls.insert(r);
        }
        m_dat[l] = v;
        for (it_l++ ; *it_l < r ; it_l = m_ls.erase(it_l)) {
            m_seg.assign(*it_l, VM::identity());
            m_dat[*it_l] = VM::identity();
        }
        m_ls.insert(l);
    }

private:

    SegmentTree<VM> m_seg;

    std::vector<V> m_dat;

    std::set<usize> m_ls; 

    static V power(V v, u32 p) requires concepts::FastPowerableMonoid<VM> {
        return VM::power(v, p);
    }

    static V power(V v, u32 p) {
        V res{VM::identity()};
        while (p) {
            if (p & 1) res = VM::operation(res, v);
            v = VM::operation(v, v);
            p >>= 1; 
        }
        return res;
    }
};

} // namespace zawa
