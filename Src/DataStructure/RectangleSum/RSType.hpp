#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <type_traits>

namespace zawa {

template <class P, class W>
struct RSPoint {
    static_assert(std::is_integral_v<P>, "RSPoint P must be integer");
    P x, y;
    W w;
    RSPoint() = default;
    RSPoint(P x_, P y_) 
        : x{x_}, y{y_}, w{static_cast<W>(1)} {}
    RSPoint(P x_, P y_, W w_)
        : x{x_}, y{y_}, w{w_} {}
};

// 求値で使う
// 半開区間
template <class P>
struct RSQuery {
    static_assert(std::is_integral_v<P>, "RSPoint P must be integer");
    P l, d, r, u;
    RSQuery() = default;
    RSQuery(P l_, P d_, P r_, P u_)
        : l{l_}, d{d_}, r{r_}, u{u_} {
        assert(l < r);
        assert(d < u);
    }
};

} // namespace zawa
