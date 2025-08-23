#pragma once

#include "../Template/TypeAlias.hpp"

#include <algorithm>
#include <concepts>
#include <optional>
#include <utility>
#include <vector>
#include <tuple>

namespace zawa {

namespace SternBrocotTree {

namespace sbt_internal {

template <class T>
concept Integer = std::integral<T> or std::same_as<T, __int128_t> or std::same_as<T, __uint128_t>;

} // namespace sbt_internal

enum Direction {
    Left,
    Right
};

template <sbt_internal::Integer T>
using Path = std::vector<std::pair<Direction, T>>;

template <sbt_internal::Integer T>
using Node = std::pair<T, T>;

template <sbt_internal::Integer T>
Path<T> Encode(Node<T> node) {
    auto [a, b] = node;
    u32 d = [&]() {
        if (a < b) {
            std::swap(a, b);
            return 0;
        }
        else {
            return 1;
        }
    }();
    std::vector<T> quos;
    while (b) {
        quos.push_back(a / b);
        T r = a % b;
        a = b;
        b = r;
    }
    if (quos.size()) {
        quos.back()--;
        if (quos.back() == 0)
            quos.pop_back();
    }
    Path<T> res;
    for (T q : quos) {
        res.push_back({static_cast<Direction>(d), q});
        d ^= 1;
    }
    return res;
}

namespace sbt_internal {

template <Integer T>
std::tuple<Node<T>, Node<T>, Node<T>> Decode(const Path<T>& path) {
    T a = 0, b = 1, c = 1, d = 1, e = 1, f = 0;
    for (auto [direction, step] : path) {
        if (direction == Left) {
            e = c + (step - 1) * a;
            f = d + (step - 1) * b;
            c += step * a;
            d += step * b;
        }
        else if (direction == Right) {
            a = c + (step - 1) * e;
            b = d + (step - 1) * f;
            c += step * e;
            d += step * f;
        } 
    }
    return {Node<T>{a, b}, Node<T>{c, d}, Node<T>{e, f}};
}

} // namespace sbt_internal

template <sbt_internal::Integer T>
Node<T> Decode(const Path<T>& path) {
    return std::get<1>(sbt_internal::Decode(path));
}

template <sbt_internal::Integer T>
Node<T> LCA(Node<T> p, Node<T> q) {
    auto a = Encode(p), b = Encode(q);
    Path<T> path;
    for (usize i = 0 ; i < std::min(a.size(), b.size()) ; i++) {
        if (a[i].first != b[i].first)
            break;
        path.push_back({a[i].first, std::min(a[i].second, b[i].second)});
        if (a[i].second != b[i].second)
            break;
    }
    return Decode(path);
}

// depth is 0-indexed
template <sbt_internal::Integer T>
std::optional<Node<T>> Ancestor(u64 dep, Node<T> n) {
    Path<T> path;
    for (auto [direction, step] : Encode(n)) {
        if (dep == 0)
           break;
        u64 s = std::min<u64>(dep, step);
        path.push_back({direction, s});
        dep -= s;
    }
    if (dep)
        return std::nullopt;
    else
        return Decode(path);
}

template <sbt_internal::Integer T>
std::pair<Node<T>, Node<T>> Range(Node<T> n) {
    Node<T> l, r;
    std::tie(l, std::ignore, r) = sbt_internal::Decode(Encode(n));
    return {l, r};
}

} // namespace SternBrocotTree


} // namespace zawa
