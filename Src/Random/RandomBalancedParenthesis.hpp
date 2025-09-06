#pragma once

#include "./RandomDistinctArray.hpp"

#include <algorithm>
#include <cassert>
#include <vector>
#include <random>
#include <string>

namespace zawa {

namespace Random {

// https://codeforces.com/blog/entry/103245
std::string BalancedParenthesis(usize n, bool verify = true) {
    if (n == 0)
        return "";
    auto left = DistinctArray<usize>(n, 0, 2 * n, verify);
    std::string gen(2 * n + 1, ')');
    for (usize i : left)
        gen[i] = '(';
    std::vector<i32> pref(gen.size());
    pref[0] = gen[0] == '(' ? +1 : -1;
    for (usize i = 1 ; i < pref.size() ; i++)
        pref[i] = pref[i - 1] + (gen[i] == '(' ? +1 : -1);
    auto sp = std::ranges::min_element(pref) - pref.begin();
    std::string res(2 * n, '(');
    for (usize i = 0 ; i < 2 * n ; i++)
        res[i] = gen[(sp + 1 + i) % gen.size()];
    if (verify) {
        i32 bal = 0;
        for (u8 c : res) {
            assert(c == '(' or c == ')');
            bal += c == '(' ? +1 : -1;
            assert(bal >= 0);
        }
        assert(bal == 0);
    }
    return res;
}

} // namespace Random

} // namespace zawa
