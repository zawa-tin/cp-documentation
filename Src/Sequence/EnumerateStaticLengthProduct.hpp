#pragma once

#include "../Template/TypeAlias.hpp"
#include "../Algebra/Semigroup/SemigroupConcept.hpp"
#include "../DataStructure/SWAG/FoldableQueue.hpp"

#include <cassert>
#include <iterator>
#include <type_traits>
#include <vector>

namespace zawa {

template <concepts::Semigroup S>
std::vector<typename S::Element> EnumerateStaticLengthProduct(const std::vector<typename S::Element>& A, usize K) {
    assert(K > 0);
    if (A.size() < K) return {};
    std::vector<typename S::Element> res(A.size() - K + 1);
    FoldableQueue<SemigroupSWAGable<S>> que{};
    for (usize i{} ; i < K ; i++) {
        que.push(A[i]);
    }
    for (usize i{} ; i < A.size() - K ; i++) {
        res[i] = que.product();
        que.pop();
        que.push(A[i + K]);
    }
    res[A.size() - K] = que.product();
    return res;
}

} // namespace zawa
