#pragma once

#include "../Template/TypeAlias.hpp"

#include <cassert>
#include <cmath>
#include <vector>

namespace zawa {

template <class T>
class BinomalCoefficients {
public:
    static constexpr u64 MOD{T::mod()};
private:
    usize n_{};
    std::vector<T> F_{}, inv_{}, invF_{};
    constexpr bool need(usize n) const noexcept {
        return n_ <= n;
    }
    void expand(usize n) {
        F_.reserve(n + 1);
        inv_.reserve(n + 1);
        invF_.reserve(n + 1);
        for (usize i{n_} ; i <= n ; i++) {
            F_.emplace_back(F_.back() * T{i});
            inv_.emplace_back(MOD - inv_[MOD % i] * (MOD / i));
            invF_.emplace_back(invF_.back() * inv_.back());
        }
        n_ = n + 1;
    }
public:
    constexpr usize size() const noexcept {
        return n_;
    }
    BinomalCoefficients() : n_{2u}, F_{T{1}, T{1}}, inv_{T{0}, T{1}}, invF_{T{1}, T{1}} {}
    BinomalCoefficients(usize n) : n_{2u}, F_{T{1}, T{1}}, inv_{T{0}, T{1}}, invF_{T{1}, T{1}} {
        assert(n);
        if (need(n)) expand(n);
    }
    T F(i32 n) {
        if (need(std::abs(n))) expand(static_cast<usize>(std::abs(n)));
        return (n >= 0 ? F_[n] : invF_[-n]);
    }
    T P(i32 p, i32 q) {
        if (q > p) return T{}; 
        return F(p) * F(q - p);
    }
    T C(i32 p, i32 q) {
        if (q > p) return T{};
        return P(p, q) * F(-q);
    }
    T H(i32 p, i32 q) {
        if (p == 0 and q == 0) return T{1};
        return C(p + q - 1, q);
    }
    T B(const std::vector<i32>& b) {
        T res{1};
        i32 sum{};
        for (i32 x : b) {
            res *= F(-x);
            sum += x;
        }
        res *= F(sum);
        return res;
    }
};

} // namespace zawa
