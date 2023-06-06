#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <algorithm>

namespace zawa {

class EratosthenesSieve {
private:
    usize tableSize;
    std::vector<bool> table;

public:
    EratosthenesSieve() = default;

    EratosthenesSieve(usize tableSize_) : tableSize{ tableSize_ + 1 }, table(tableSize_ + 1, true) {
        table.shrink_to_fit();
        assert(tableSize > 0);
        table[0] = table[1] = false;
        for (u64 i = 2 ; i * i < tableSize ; i++) {
            if (!table[i]) continue;
            for (u64 j = i * i ; j < tableSize ; j += i ) {
                table[j] = false;
            }
        }
    }

    inline bool operator[](u32 i) const {
        assert(i < tableSize);
        return table[i];
    }

    inline bool isPrime(u32 i) const {
        assert(i < tableSize);
        return table[i];
    }

    inline usize size() const {
        return tableSize - 1;
    }

    std::vector<u32> enumeratePrimes(u32 N) const {
        assert(N < tableSize);
        std::vector<u32> primes{};
        primes.reserve(std::count(table.begin(), table.begin() + N + 1, true));
        for (u32 i = 2 ; i <= N ; i++) {
            if (table[i]) {
                primes.emplace_back(i);
            }
        }
        return primes;
    }
};

} // namespace zawa
