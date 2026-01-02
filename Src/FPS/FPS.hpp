#pragma once

#include "../Template/TypeAlias.hpp"

#include <concepts>

namespace zawa {

namespace concepts {

template <class FPS>
concept IndexedFPS = requires(FPS f, usize i) {
    typename FPS::value_type;
    { f.size() } -> std::convertible_to<usize>;
    { f[i] } -> std::convertible_to<typename FPS::value_type>;
    f.reserve(0);
    f.push_back(f[i]);
};

} // namespace concepts

struct FPSMult {
    template <class FPS>
    requires requires(const FPS& a, const FPS& b) {
        { a * b } -> std::same_as<FPS>;
    }
    FPS operator()(const FPS& a, const FPS& b) const {
        return a * b;
    }
};

struct NaiveConvolution {
    template <class FPS>
    FPS operator()(const FPS& a, const FPS& b) const {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        FPS res(a.size() + b.size() - 1);
        for (usize i = 0 ; i < a.size() ; i++)
            for (usize j = 0 ; j < b.size() ; j++)
                res[i + j] += a[i] * b[j];
        return res;
    }
};

} // namespace zawa
