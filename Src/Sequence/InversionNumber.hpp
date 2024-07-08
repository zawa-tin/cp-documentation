#pragma once

#include "../Template/TypeAlias.hpp"

#include <cassert>
#include <iterator>
#include <type_traits>
#include <vector>

namespace zawa {

template <class InputIterator>
u64 InversionNumber(InputIterator first, InputIterator last) {
    assert((usize)std::distance(first, last) >= usize{0});
    std::vector<std::remove_reference_t<decltype(*first)>> A(first, last);
    auto rec{[&](auto rec, usize L, usize R) -> u64 {
        if (R - L <= usize{1}) return 0; 
        usize M{(L + R) >> 1};
        u64 res{rec(rec, L, M) + rec(rec, M, R)};
        std::vector<u64> tmp(R - L);
        usize i{L}, j{M}, k{};
        while (i < M and j < R) {
            if (A[i] <= A[j]) {
                tmp[k++] = A[i++];
            }
            else {
                res += M - i;
                tmp[k++] = A[j++];
            }
        }
        while (i < M) tmp[k++] = A[i++];
        while (j < R) tmp[k++] = A[j++];
        for (usize l{L} ; l < R ; l++) {
            A[l] = tmp[l - L];
        }
        return res;
    }};
    return rec(rec, usize{0}, usize{A.size()});
}

template <class InputIterator>
bool InversionParity(InputIterator first, InputIterator last) {
    assert((usize)std::distance(first, last) >= usize{0});
    std::vector<std::remove_reference_t<decltype(*first)>> A(first, last);
    auto rec{[&](auto rec, usize L, usize R) -> bool {
        if (R - L <= usize{1}) return 0; 
        usize M{(L + R) >> 1};
        bool res{rec(rec, L, M) != rec(rec, M, R)};
        std::vector<u64> tmp(R - L);
        usize i{L}, j{M}, k{};
        while (i < M and j < R) {
            if (A[i] <= A[j]) {
                tmp[k++] = A[i++];
            }
            else {
                res ^= (M - i) & 1;
                tmp[k++] = A[j++];
            }
        }
        while (i < M) tmp[k++] = A[i++];
        while (j < R) tmp[k++] = A[j++];
        for (usize l{L} ; l < R ; l++) {
            A[l] = tmp[l - L];
        }
        return res;
    }};
    return rec(rec, usize{0}, usize{A.size()});
}

} // namespace zawa
