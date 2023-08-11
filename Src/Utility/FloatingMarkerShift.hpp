#pragma once

#include "../Template/TypeAlias.hpp"

#include <string>
#include <cassert>
#include <limits>

namespace zawa {

i64 FloatingMarkerShift(const std::string& S, u32 shift) {
    static i64 lim10{std::numeric_limits<i64>::max() / 10};
    assert(not S.empty());
    i64 res{};
    u32 moved{};
    bool start{};
    bool minus{S[0] == '-'};
    for (u32 i{(u32)minus} ; i < S.size() ; i++) {
        if (S[i] == '.') {
            start = true;
        }
        else {
            if (start) moved++;
            assert(res < lim10);
            res = res * 10;
            assert(res < std::numeric_limits<i64>::max() - (S[i] - '0'));
            res += S[i] - '0';
        }
    }
    assert(moved <= shift);
    while (moved < shift) {
        moved++;
        assert(res < lim10);
        res = res * 10;
    }
    if (minus) res *= -1;
    return res;
}

}// namespace zawa
