#pragma once

#include <utility>

namespace zawa {

template <class T>
std::pair<T, T> ExtendGCD(T a, T b) {
    if (a == 0) return { T{0}, 1 };
    if (b == 0) return { T{1}, 0 };
    T px{1}, py{0}, x{0}, y{1};
    while (a % b) {
        T d{a / b}, r{a % b};
        T nx{px - d*x}, ny{py - d*y};
        px = x;
        py = y;
        x = nx;
        y = ny;
        a = b;
        b = r;
    }
    return {x, y};
}

} // namespace zawa
