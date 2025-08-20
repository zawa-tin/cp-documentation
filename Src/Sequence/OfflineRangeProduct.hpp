#pragma once

#include "../Template/TypeAlias.hpp"
#include "../Algebra/Monoid/MonoidConcept.hpp"
#include "../Algebra/Action/ActionConcept.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <numeric>
#include <vector>

namespace zawa {

namespace offline_range_product_internal {

template <class R>
concept Range = requires (R lr) {
    { lr.l } -> std::convertible_to<usize>;
    { lr.r } -> std::convertible_to<usize>;
};

template <class M, class S, class R>
concept condition = concepts::Monoid<M> and Range<R> and (std::same_as<typename M::Element, S> or concepts::Acted<M, S>);

} // namespace offline_range_product_internal

template <class M, class S, class Range>
requires offline_range_product_internal::condition<M, S, Range>
std::vector<typename M::Element> OfflineRangeProduct(const std::vector<S>& as, const std::vector<Range>& qs) {
    std::vector<typename M::Element> sum(as.size() + 1), res(qs.size(), M::identity());
    auto f = [&](usize m, const std::vector<usize>& idx) -> void {
        sum[m] = M::identity();
        usize L = m, R = m;
        for (usize i : idx) {
            L = std::min<usize>(L, qs[i].l);
            R = std::max<usize>(R, qs[i].r);
        }
        for (usize i = m ; i-- > L ; ) {
            if constexpr (std::same_as<typename M::Element, S>)
                sum[i] = M::operation(as[i], sum[i + 1]);
            else
                sum[i] = M::acted(sum[i + 1], as[i]);
        }
        for (usize i = m ; i < R ; i++) {
            if constexpr (std::same_as<typename M::Element, S>)
                sum[i + 1] = M::operation(sum[i], as[i]);
            else
                sum[i + 1] = M::acted(sum[i], as[i]);
        }
        for (usize i : idx)
            res[i] = M::operation(sum[qs[i].l], sum[qs[i].r]);
    };
    auto rec = [&](auto rec, usize L, usize R, std::vector<usize> idx) -> void {
        if (L >= R)
            return;
        if (L + 1 == R) {
            f(L, idx);
            return;
        }
        const usize mid = (L + R) / 2;
        std::vector<usize> toL, toR, cur;
        for (auto&& i : idx) {
            assert(qs[i].l <= qs[i].r and static_cast<usize>(qs[i].r) <= as.size());
            if (static_cast<usize>(qs[i].r) <= mid)
                toL.push_back(std::move(i));
            else if (mid <= static_cast<usize>(qs[i].l))
                toR.push_back(std::move(i));
            else
                cur.push_back(std::move(i));
        }
        if (cur.size())
            f(mid, cur);
        if (toL.size())
            rec(rec, L, mid, toL);
        if (toR.size())
            rec(rec, mid, R, toR);
    };
    std::vector<usize> idx(qs.size());
    std::iota(idx.begin(), idx.end(), 0);
    rec(rec, 0, as.size(), idx);
    return res;
}

} // namespace zawa
