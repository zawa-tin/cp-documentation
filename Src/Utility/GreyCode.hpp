#pragma once

#include "../Template/TypeAlias.hpp"
#include "../Algebra/Action/SetOperator.hpp"

#include <bit>
#include <utility>
#include <vector>

namespace zawa {

enum class GreyCodeOp {
    Add,
    Remove,
    Access
};

std::vector<std::pair<GreyCodeOp, usize>> GreyCode(usize n) {
    std::vector<std::pair<GreyCodeOp, usize>> res;
    res.reserve(1 << (n + 1));
    usize cur = 0;
    res.emplace_back(GreyCodeOp::Access, cur);
    for (usize i = 1 ; i < (1u << n) ; i++) {
        usize nxt = i ^ (i >> 1);
        usize k = std::countr_zero<unsigned>(cur ^ nxt);
        if (cur & (1 << k))
            res.emplace_back(GreyCodeOp::Remove, k);
        else
            res.emplace_back(GreyCodeOp::Add, k);
        res.emplace_back(GreyCodeOp::Access, nxt);
        cur = nxt;
    }
    return res;
}

template <class S, class T>
requires concepts::SetOperator<S, T>
std::vector<typename S::Element> EnumerateSubsetProduct(const std::vector<T>& A) {
    std::vector<typename S::Element> res(1 << A.size());
    typename S::Element cur = S::identity();
    for (auto [type, idx] : GreyCode(A.size())) {
        switch (type) {
        case GreyCodeOp::Add:
            S::add(cur, A[idx]);
            break;
        case GreyCodeOp::Remove:
            S::remove(cur, A[idx]);
            break;
        case GreyCodeOp::Access:
            res[idx] = cur;
            break;
        }
    }
    return res;
}

} // namespace zawa
