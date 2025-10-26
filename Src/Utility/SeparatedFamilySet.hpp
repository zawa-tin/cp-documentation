#pragma once

#include <algorithm>
#include <vector>
#include <concepts>
#include <ranges>

#include "../Template/TypeAlias.hpp"

namespace zawa {

// https://noshi91.hatenablog.com/entry/2024/05/31/012055
// each (i, j) satisfy there are k such that res[k][i]=1,res[k][j]=0
std::vector<std::vector<bool>> SeparatedFamilySet(usize U) {
    const usize d = [&]() {
        for (usize i = 1 ; ; i++) {
            usize max = 1;
            for (usize j = 0 ; j < (i / 2) ; j++) {
                max *= i - j;
                max /= j + 1;
            }
            if (max >= U) return i;
        }
        return U;
    }();
    std::vector res(d, std::vector<bool>(U));
    std::vector<u8> in(d);
    std::fill(in.rbegin(), in.rbegin() + d / 2, true);
    for (usize idx = 0 ; idx < U ; idx++) {
        for (usize i = 0 ; i < d ; i++) if (in[i]) {
            res[i][idx] = true;
        }
        std::ranges::next_permutation(in);
    }
    return res;
}

} // namespace zawa
