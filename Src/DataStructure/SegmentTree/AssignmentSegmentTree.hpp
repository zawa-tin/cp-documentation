#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Monoid/MonoidConcept.hpp"
#include "./SegmentTree.hpp"

#include <cassert>
#include <vector>
#include <set>

namespace zawa {

namespace Concept {

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

} // namespace

template <Concept::Monoid M>
class AssignmentSegmentTree {
public:

    using V = typename M::Element;

    AssignmentSegmentTree() = default;

    AssignmentSegmentTree(usize n) : seg_{(u32)n}, dat_(n, M::identity()), ls_{} {
        dat_.shrink_to_fit();
        assert(n);
        ls_.insert(0u);
        ls_.insert(n);
    }

    AssignmentSegmentTree(std::vector<V> dat) : seg_{}, dat_{dat}, ls_{} {
        // dat: 区間の左端lにa_{l}^{r-l}, それ以外のiはidentity()にする -> セグ木にこれをのせる
        // dat_: 区間の左端lにa_{l}, それ以外のiはidentity()にする
        dat_.shrink_to_fit();
        if constexpr (Concept::EqualCompare<V>) {
            for (usize i{}, j{} ; i < dat_.size() ; ) {
                while (j < dat.size() and dat[i] == dat[j]) j++;
                ls_.insert(i);
                dat[i] = power(dat_[i], j - i);
                for ( ; ++i < j ; dat[i] = dat_[i] = M::identity()) ;
            }
        }
        else {
            for (usize i{} ; i < dat_.size() ; i++) ls_.insert(i);
        }
        ls_.insert(dat.size());
        seg_ = decltype(seg_){dat};
    }

    inline usize size() const noexcept {
        return dat_.size();
    }

    V product(usize l, usize r) const {
        assert(l <= r and r <= dat_.size());
        auto second_l = ls_.upper_bound(l);
        auto first_l = std::prev(second_l);
        if (second_l != ls_.end() and r <= *second_l) { // 一つの区間に含まれている
            return power(dat_[*first_l], r - l);
        }
        auto last_l = std::prev(ls_.upper_bound(r));
        return M::operation(
                M::operation(
                    power(dat_[*first_l], *second_l - l),
                    seg_.product(*second_l, *last_l)
                    ),
                power(dat_[*last_l], r - *last_l)
                );
    }

    void assign(usize l, usize r, V v) {
        assert(l <= r and r <= dat_.size());
        if (l == r) return;
        // assert(*it_l < n);
        auto it_l = std::prev(ls_.upper_bound(l)), it_r = std::prev(ls_.upper_bound(r)); 
        if (*it_l < l) seg_.set(*it_l, power(dat_[*it_l], l - *it_l));
        seg_.set(l, power(v, r - l));
        if (*it_r < r and r < dat_.size()) {
            dat_[r] = dat_[*it_r];
            seg_.set(r, power(dat_[r], *std::next(it_r) - r));
            ls_.insert(r);
        }
        dat_[l] = v;
        for (it_l++ ; *it_l < r ; it_l = ls_.erase(it_l)) {
            seg_.set(*it_l, M::identity());
            dat_[*it_l] = M::identity();
        }
        ls_.insert(l);
    }

private:

    SegmentTree<M> seg_;

    std::vector<V> dat_;

    std::set<usize> ls_; 

    static V power(V v, u32 p) requires Concept::FastPowerableMonoid<M> {
        return M::power(v, p);
    }

    static V power(V v, u32 p) {
        V res{M::identity()};
        while (p) {
            if (p & 1) res = M::operation(res, v);
            v = M::operation(v, v);
            p >>= 1; 
        }
        return res;
    }
};

} // namespace zawa
