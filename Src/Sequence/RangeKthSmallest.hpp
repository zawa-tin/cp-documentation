#pragma once

#include "./CompressedSequence.hpp"
#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <bit>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class T, class U>
std::vector<T> RangeKthSmallest(const std::vector<T>& A, const std::vector<U>& Q) {
    assert(A.size());
    CompressedSequence comp{A};
    std::vector<std::vector<std::pair<usize, bool>>> event(A.size() + 1);
    for (usize i{} ; i < Q.size() ; i++) {
        const U& q{Q[i]};
        assert(q.l < q.r and q.r <= A.size());
        assert(q.k < q.r - q.l);
        event[q.l].emplace_back(i, true);
        event[q.r].emplace_back(i, false);
    }
    std::vector<usize> x(Q.size()), cnt(Q.size());
    const usize LOG{(usize)(std::bit_width(comp.size()) -
            (std::has_single_bit(comp.size()) ? 1 : 0))};
    for (usize i{LOG} ; i-- ; ) {
        std::vector<i32> seg(1 << (LOG - i));
        std::vector<i32> add(Q.size());
        for (usize j{1} ; j <= A.size() ; j++) {
            seg[comp.map(j - 1) >> i]++;
            for (auto [k, s] : event[j]) {
                add[k] += seg[(x[k] >> i)] * (s ? -1 : 1);
            }
        }
        for (u32 j{} ; j < Q.size() ; j++) {
            if (cnt[j] + add[j] <= Q[j].k) {
                x[j] += 1 << i;
                cnt[j] += add[j];
            }
        }
    } 
    std::vector<T> res(Q.size());
    for (usize i{} ; i < Q.size() ; i++) {
        res[i] = comp.inverse(x[i]);
    }
    return res;
}

} // namespace zawa
