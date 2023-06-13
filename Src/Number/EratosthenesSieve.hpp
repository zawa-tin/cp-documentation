#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <algorithm>

namespace zawa {

class EratosthenesSieve {
private:
    usize tableSize_;
    std::vector<bool> table_;

public:
    EratosthenesSieve() = default;

    EratosthenesSieve(usize tableSize) : tableSize_{ tableSize + 1 }, table_(tableSize + 1, true) {
        table_.shrink_to_fit();
        assert(tableSize_ > 0);
        table_[0] = table_[1] = false;
        for (u64 i = 2 ; i * i < tableSize_ ; i++) {
            if (!table_[i]) continue;
            for (u64 j = i * i ; j < tableSize_ ; j += i ) {
                table_[j] = false;
            }
        }
    }

    inline bool operator[](u32 i) const {
        assert(i < tableSize_);
        return table_[i];
    }

    inline bool isPrime(u32 i) const {
        assert(i < tableSize_);
        return table_[i];
    }

    inline usize size() const {
        return tableSize_ - 1;
    }

    std::vector<u32> enumeratePrimes(u32 N) const {
        assert(N < tableSize_);
        std::vector<u32> primes{};
        primes.reserve(std::count(table_.begin(), table_.begin() + N + 1, true));
        for (u32 i = 2 ; i <= N ; i++) {
            if (table_[i]) {
                primes.emplace_back(i);
            }
        }
        return primes;
    }
};

} // namespace zawa
