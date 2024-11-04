#pragma once

#include <limits>
#include <utility>

namespace zawa {

template <class T, class U>
struct MinCountMonoid {
    // min, countの順
    using Element = std::pair<T, U>;

    static Element identity() noexcept {
        return { std::numeric_limits<T>::max(), U{} };
    }

    static Element operation(const Element& L, const Element& R) {
        if (L.first < R.first) return L;
        else if (L.first > R.first) return R;
        else return Element{ L.first, L.second + R.second };
    }

};

} // namespace 
