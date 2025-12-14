#pragma once

#include "../Template/TypeAlias.hpp"

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

namespace concepts {

template <class T>
concept SubsetProd = requires {
    typename T::Element;
    { T::identity() } -> std::same_as<typename T::Element>;
    { T::add(std::declval<typename T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;
    { T::remove(std::declval<typename T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename T::Element>;
};


} // namespace concepts

template <concepts::SubsetProd T>
std::vector<typename T::Element> EnumerateSubsetProduct(std::vector<typename T::Element> A) {
    std::vector<typename T::Element> res(1 << A.size());
    typename T::Element cur = T::identity();
    for (auto [type, idx] : GreyCode(A.size())) {
        switch (type) {
        case GreyCodeOp::Add:
            cur = T::add(cur, A[idx]);
            break;
        case GreyCodeOp::Remove:
            cur = T::remove(cur, A[idx]);
            break;
        case GreyCodeOp::Access:
            res[idx] = cur;
            break;
        }
    }
    return res;
}

} // namespace zawa
