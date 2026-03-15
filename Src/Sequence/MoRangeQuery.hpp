#pragma once

#include <algorithm>
#include <ranges>

#include "../Utility/Mo.hpp"

namespace zawa {

template <class T, class AddL, class AddR, class DelL, class DelR, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize>> Mo(std::vector<std::pair<T,T>> qs, AddL addL, AddR addR, DelL delL, DelR delR, Eval eval, bool reset = false) {
    auto ord = Mo(qs);
    std::vector<typename std::invoke_result_t<Eval, usize>> res(qs.size());
    T L = 0, R = 0;
    for (usize i : ord) {
        const auto [l, r] = qs[i];
        while (R < r) 
            addR(R++);
        while (L > l) 
            addL(--L);
        while (R > r) 
            delR(--R);
        while (L < l) 
            delL(L++);
        res[i] = eval(i);
    }
    if (reset) 
        while (R > L) 
            delR(--R);
    return res;
}

} // namespace zawa
