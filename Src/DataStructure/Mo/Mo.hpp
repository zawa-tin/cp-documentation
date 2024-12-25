#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <vector>
#include <type_traits>

namespace zawa {

namespace internal {

// reference: https://codeforces.com/blog/entry/61203?#comment-1064868
u64 hilbertOrder(u64 x, u64 y, usize dim) {
    const u64 max{(1ull << dim) - 1};
    assert(x <= max);
    assert(y <= max);
    u64 res{};
    for (u64 s{1ull << (dim - 1)} ; s ; s >>= 1) {
        bool rx{static_cast<bool>(x & s)}, ry{static_cast<bool>(y & s)};
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= max, y ^= max;
            std::swap(x, y);
        }
    }
    return res;
}

} // namespace internal

template <class T, class AddL, class AddR, class DelL, class DelR, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize>> Mo(std::vector<T> qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval) {
    usize log{};
    for (const T& lr : qs) {
        assert(lr.l <= lr.r);
        log = std::max<usize>(log, std::bit_width(lr.r));
    }
    std::vector<std::pair<T, usize>> ord(qs.size());
    std::vector<u64> h(qs.size());
    for (usize i{} ; i < qs.size() ; i++) {
        ord[i] = {qs[i], i};
        h[i] = internal::hilbertOrder(qs[i].l, qs[i].r, log);
    }
    std::sort(ord.begin(), ord.end(), [&](const auto& L, const auto& R) -> bool {
            return h[L.second] < h[R.second];
            });
    std::vector<typename std::invoke_result_t<Eval, usize>> res(qs.size());
    usize L{}, R{};
    for (const auto& [lr, id] : ord) {
        while (R < lr.r) addR(R++);
        while (L > lr.l) addL(--L);
        while (R > lr.r) delR(--R);
        while (L < lr.l) delL(L++);
        res[id] = eval(id);
    }
    return res;
}

} // namespace zawa
