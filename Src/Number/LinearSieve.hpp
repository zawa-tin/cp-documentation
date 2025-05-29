#pragma once

#include "../Template/TypeAlias.hpp"
#include "./PrimeFactor.hpp"

#include <concepts>
#include <vector>
#include <utility>
#include <cassert>

namespace zawa {

class LinearSieve {
public:

    using V = u32;
    using F = PrimeFactor<V>;

private:

    std::vector<V> primes_;
    std::vector<V> lpf_;

public:

    explicit LinearSieve(V n) : primes_{}, lpf_(n + 1) {
        for (V i{2} ; i <= n ; i++) {
            if (!lpf_[i]) {
                lpf_[i] = i;
                primes_.emplace_back(i);
            }
            for (V p : primes_) {
                if (static_cast<u64>(p) * i > n) break;
                lpf_[p * i] = p;
            }
        }
    }

    V size() const noexcept {
        return static_cast<V>(lpf_.size()) - 1;
    }

    bool isPrime(V x) const noexcept {
        assert(x < lpf_.size());
        return lpf_[x] == x;
    }

    bool operator[](V x) const noexcept {
        assert(x < lpf_.size());
        return lpf_[x] == x;
    }

    std::vector<V> primes() const {
        return primes_;
    }

    // @note: response array is not sorted.
    template <std::integral T = V>
    std::vector<T> divisor(V x) const {
        assert(0u < x and x < lpf_.size());
        std::vector<T> res(1, 1u);
        while (x > 1) {
            V factor{lpf_[x]};
            u32 exponent{};
            while (lpf_[x] == factor) {
                exponent++;
                x /= lpf_[x];
            }
            usize line{res.size()};
            V now{1};
            for (u32 i{} ; i < exponent ; i++) {
                now *= factor;
                for (usize j{} ; j < line ; j++) {
                    res.emplace_back(static_cast<T>(res[j] * now));
                }
            }
        }
        return res;
    }

    std::vector<F> factorize(V x) const {
        assert(0u < x and x < lpf_.size());
        std::vector<F> res;
        while (x > 1) {
            V factor{lpf_[x]};
            u32 exponent{};
            while (lpf_[x] == factor) {
                exponent++;
                x /= lpf_[x];
            }
            res.emplace_back(factor, exponent);
        }
        return res;
    }

    i32 mobius(V x) const {
        assert(0u < x and x < lpf_.size());
        i32 res = 1;
        while (x > 1u) {
            V factor = lpf_[x];
            u32 exp = 0;
            while (lpf_[x] == factor) {
                x /= factor;
                exp++;
            }
            if (exp >= 2u) return 0;
            res *= -1;
        }
        return res;
    }
};

} // namespace zawa
