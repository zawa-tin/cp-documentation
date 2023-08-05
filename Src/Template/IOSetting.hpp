#pragma once

#include "./TypeAlias.hpp"

#include <iostream>
#include <iomanip>

namespace zawa {

void SetFastIO() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
}

void SetPrecision(u32 dig) {
    std::cout << std::fixed << std::setprecision(dig);
}

} // namespace zawa
