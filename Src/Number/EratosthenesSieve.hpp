#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>

namespace zawa {

class EratosthenesSieve {
private:
    usize size;
    std::vector<bool> table;

public:
    EratosthenesSieve() = default;

    EratosthenesSieve(usize size) : size{ size + 1 }, table(size + 1, true) {
        assert(size > 0);
        table[0] = table[1] = false;
        for (usize i = 2 ; i < size ; i++) {
            if (!table[i]) continue;
            for (usize j = i + i ; j < size ; j += i ) {
                table[j] = false;
            }
        }
    }

    inline bool operator[](const u32 i) const {
        return table[i];
    }

    inline bool isPrime(const u32 i) const {
        return table[i];
    }

    std::vector<u32> enumeratePrimes(u32 N) const {
        assert(N + 1 < size);
        std::vector<u32> primes{};
        for (u32 i = 2 ; i <= N ; i++) {
            if (table[i]) {
                primes.emplace_back(i);
            }
        }
        return primes;
    }
};

} // namespace zawa
