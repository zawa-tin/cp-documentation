#pragma once

#include "../Template/TypeAlias.hpp"

#include <cassert>
#include <cmath>
#include <vector>
#include <atcoder/internal_math>
#include <atcoder/modint>

namespace zawa {

template <u32 MOD>
class BinomalCoefficients {
public:
    using Value = atcoder::static_modint<MOD>;
    static_assert(atcoder::internal::is_prime_constexpr(MOD));
private:
    usize n_{};
    std::vector<Value> F_{}, inv_{}, invF_{};
    constexpr bool need(usize n) const noexcept {
        return n_ <= n;
    }
    void expand(usize n) {
        F_.reserve(n + 1);
        inv_.reserve(n + 1);
        invF_.reserve(n + 1);
        for (usize i{n_} ; i <= n ; i++) {
            F_.emplace_back(F_.back() * Value{i});
            inv_.emplace_back(MOD - inv_[MOD % i] * (MOD / i));
            invF_.emplace_back(invF_.back() * inv_.back());
        }
        n_ = n + 1;
    }
public:
    constexpr usize size() const noexcept {
        return n_;
    }
    BinomalCoefficients() 
        : n_{2u}, F_{Value::raw(1), Value::raw(1)}, inv_{Value{}, Value::raw(1)}, 
        invF_{Value::raw(1), Value::raw(1)} {}
    BinomalCoefficients(usize n) 
        : n_{2u}, F_{Value::raw(1), Value::raw(1)}, inv_{Value{}, Value::raw(1)}, 
        invF_{Value::raw(1), Value::raw(1)} {
        assert(n);
        if (need(n)) expand(n);
    }
    Value F(i32 n) {
        if (need(std::abs(n))) expand(static_cast<usize>(std::abs(n)));
        return (n >= 0 ? F_[n] : invF_[-n]);
    }
    Value P(i32 p, i32 q) {
        if (q > p) return Value{}; 
        return F(p) * F(q - p);
    }
    Value C(i32 p, i32 q) {
        if (q > p) return Value{};
        return P(p, q) * F(-q);
    }
    Value H(i32 p, i32 q) {
        if (p == 0 and q == 0) return Value::raw(1);
        return C(p + q - 1, q);
    }
    Value B(const std::vector<i32>& b) {
        Value res{1};
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
