#pragma once

#include <cassert>
#include <concepts>
#include <utility>
#include <vector>

namespace zawa {

template <std::integral T, class F>
std::vector<T> ParallelBinarySearch(std::vector<T> oks, std::vector<T> ngs, F f) {
    assert(oks.size() == ngs.size());
    while (true) {
        std::vector<std::pair<T, usize>> remains; 
        std::vector<usize> inv(oks.size(), static_cast<usize>(-1));
        for (usize i = 0 ; i < oks.size() ; i++) if ((oks[i] >= ngs[i] ? oks[i] - ngs[i] : ngs[i] - oks[i]) > T{1}) {
            T mid = (oks[i]&ngs[i]) + ((oks[i]^ngs[i])>>1);
            inv[i] = remains.size();
            remains.push_back({mid, i});
        }
        if (remains.empty()) break;
        auto res = f(remains);
        assert(res.size() == remains.size());
        for (usize i = 0 ; i < res.size() ; i++) {
            T mid = remains[inv[res[i].second]].first;
            if (res[i].first) oks[res[i].second] = mid;
            else ngs[res[i].second] = mid;
            i++;
        }
    } 
    return oks;
}

} // namespace zawa
