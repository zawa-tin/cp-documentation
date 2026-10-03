#pragma once

#include "../Template/TypeAlias.hpp"
#include "./FindLinearRecurrence.hpp"
#include "../FPS/KthTerm.hpp"

namespace zawa {

template <class T>
T BMBM(std::vector<T> A,u64 N) {
    auto C=FindLinearRecurrence(A);
    C.insert(C.begin(),T{0});
    return KthTerm(N,A,C,NaiveConvolution{});
}


} // namespace zawa
