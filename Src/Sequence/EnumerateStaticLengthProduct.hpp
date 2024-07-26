#pragma once

#include "../Template/TypeAlias.hpp"
#include "../DataStructure/SWAG/SWAG.hpp"

#include <cassert>
#include <iterator>
#include <type_traits>
#include <vector>

namespace zawa {

template <class S>
std::vector<typename S::Element> EnumerateStaticLengthProduct(const std::vector<typename S::Element>& A, usize K) {
    assert(K > 0);
    if (A.size() < K) return {};
    std::vector<typename S::Element> res(A.size() - K + 1);
    SlidingWindowAggregation<S> swag{};
    for (usize i{} ; i < K ; i++) {
        swag.push(A[i]);
    }
    for (usize i{} ; i < A.size() - K ; i++) {
        res[i] = swag.product();
        swag.pop();
        swag.push(A[i + K]);
    }
    res[A.size() - K] = swag.product();
    return res;
}

} // namespace zawa
