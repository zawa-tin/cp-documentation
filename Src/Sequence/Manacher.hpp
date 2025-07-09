#pragma once

#include <concepts>
#include <optional>
#include <vector>
#include <string>

#include "../Template/TypeAlias.hpp"

namespace zawa {

namespace concepts {

template <class C, class T>
concept Container = requires (C c, usize idx) {
    { c[idx] } -> std::convertible_to<T>;
};

} // namespace concepts

namespace internal {

// ref: https://snuke.hatenablog.com/entry/2014/12/02/235837
template <std::equality_comparable T, std::integral RES>
std::vector<RES> Manacher(const std::vector<std::optional<T>>& a) {
    std::vector<RES> res(a.size());
    for (usize i = 0, j = 0 ; i < a.size() ; ) {
        // i + jはここでしか増加せず、i + jは高々|a|しか増えない
        // -> このループは高々|a|
        while (i >= j and i + j < a.size() and a[i - j] == a[i + j]) j++;
        res[i] = j;
        usize k = 1;
        // iは高々|a|までしか増えない->kを増やしているこのループは丁度|a|
        for ( ; i >= k and k + res[i - k] < j ; k++) res[i + k] = res[i - k];
        i += k;
        j -= k;
    } 
    for (usize i = 0 ; i < res.size() ; i++) {
        if (i & 1) {
            res[i] = res[i] & (res[i] ^ 1);
        }
        else {
            res[i] = (res[i] & 1 ? res[i] : res[i] - 1);
        }
    }
    return res;
}

} // namespace internal

template <std::integral RES = usize, std::equality_comparable T = char, class C = std::string>
requires concepts::Container<C, T>
std::vector<RES> Manacher(C a) {
    if (a.empty()) return {};
    std::vector<std::optional<T>> seq(2 * a.size() - 1);
    for (usize i = 0 ; i < a.size() ; i++) {
        seq[2 * i] = std::optional{std::move(a[i])};
    }
    return internal::Manacher<T, RES>(seq);
}

} // namespace zawa
