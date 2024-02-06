#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <optional>
#include <type_traits>

namespace zawa {

template <class T, class InputIterator>
std::optional<T> MajorityVote(InputIterator first, InputIterator last) {
    static_assert(std::is_convertible_v<decltype(*first), T>, "InputIterator must be convertible T");
    assert(first != last);
    std::optional<T> remain{}; 
    usize number{};
    for (auto it{first} ; it != last ; it++) {
        if (number) {
            if (remain.value() == *it) {
                number++;
            }
            else {
                number--;
            }
        }
        else {
            remain = *it;
            number++;
        }
    }
    if (number and 2u * std::count(first, last, remain.value()) > std::distance(first, last)) {
        return remain;
    }
    else {
        return std::nullopt;
    }
}

} // namespace zawa
