#pragma once

#include "../Template/TypeAlias.hpp"

#include <concepts>
#include <iterator>

namespace zawa {

enum class GameWinner {
    First,
    Second,
};

template <std::input_iterator It>
GameWinner MisereNim(It first, It last) {
    u64 grundy = 0;
    usize size = 0;
    bool over2 = false;
    for (auto it = first ; it != last ; it++, size++) {
        u64 val = static_cast<u64>(*it);
        over2 |= val >= 2;
        grundy ^= val;
    }
    if (over2) return grundy ? GameWinner::First : GameWinner::Second;
    else return size & 1 ? GameWinner::Second : GameWinner::First;
}

} // namespace zawa
