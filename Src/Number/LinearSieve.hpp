#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <utility>
#include <cassert>

namespace zawa {

class LinearSieve {
private:
    std::vector<u32> primes_;
    std::vector<u32> lpf_;
public:
    LinearSieve(u32 n) : primes_{}, lpf_(n + 1) {
        for (u32 i{2} ; i <= n ; i++) {
            if (!lpf_[i]) {
                lpf_[i] = i;
                primes_.emplace_back(i);
            }
            for (u32 p : primes_) {
                if (static_cast<u64>(p) * i > n) break;
                lpf_[p * i] = p;
            }
        }
    }

    usize size() const noexcept {
        return lpf_.size() - 1;
    }

    bool isPrime(u32 x) const noexcept {
        assert(x < lpf_.size());
        return lpf_[x] == x;
    }

    bool operator[](u32 x) const noexcept {
        assert(x < lpf_.size());
        return lpf_[x] == x;
    }

    std::vector<u32> primes() const {
        return primes_;
    }

    // @note: response array is not sorted.
    std::vector<u32> divisor(u32 x) const {
        assert(0u < x and x < lpf_.size());
        std::vector<u32> res(1, 1u);
        while (x > 1) {
            u32 factor{lpf_[x]}, exponent{};
            while (lpf_[x] == factor) {
                exponent++;
                x /= lpf_[x];
            }
            usize line{res.size()};
            u32 now{1};
            for (u32 i{} ; i < exponent ; i++) {
                now *= factor;
                for (u32 j{} ; j < line ; j++) {
                    res.emplace_back(res[j] * now);
                }
            }
        }
        return res;
    }

    class PrimeFactor {
    private:
        u32 factor_{}, exponent_{};
    public: 
        PrimeFactor() = default;
        PrimeFactor(u32 factor, u32 exponent) : factor_{factor}, exponent_{exponent} {}
        u32 factor() const noexcept {
            return factor_;
        }
        u32 exponent() const noexcept {
            return exponent_;
        }
    };

    std::vector<PrimeFactor> factorize(u32 x) const {
        assert(0u < x and x < lpf_.size());
        std::vector<PrimeFactor> res;
        while (x > 1) {
            u32 factor{lpf_[x]}, exponent{};
            while (lpf_[x] == factor) {
                exponent++;
                x /= lpf_[x];
            }
            res.emplace_back(factor, exponent);
        }
        return res;
    }
};

} // namespace zawa
