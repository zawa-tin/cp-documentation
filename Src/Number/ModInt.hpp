#pragma once

#include "../Template/TypeAlias.hpp"

#include <type_traits>
#include <iostream>
#include <utility>
#include <cassert>

namespace zawa {

template <class T, T mod>
class StaticModInt {
private:
    using mint = StaticModInt;

    T v_{};

    static void templateTypeAssert() {
        static_assert(std::is_integral_v<T>, "ModInt template argument must be integral");
        static_assert(mod > 0, "mod must be positive");
    }

    i64 extendGCD(i64 a, i64 b, i64& x, i64& y) const {
       i64 d{a};
       if (b) {
           d = extendGCD(b, a % b, y, x);
           y -= (a / b) * x;
       }
       else {
           x = 1;
           y = 0;
       }
       return d;
    }

public:

    StaticModInt() {
        templateTypeAssert();
    }
    template <class ArgType>
    StaticModInt(ArgType v) : v_{ static_cast<T>(((v % mod) + mod) % mod) } {
        templateTypeAssert();
        static_assert(std::is_integral_v<ArgType>, "ModInt constructor Argument Must Be Integral");
    }

    friend std::istream& operator>>(std::istream& is, mint& value) {
        is >> value.v_;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& value) {
        os << value.v_;
        return os;
    }

    T v() const {
        return v_;
    }

    bool operator==(const mint& rhs) const {
        return v_ == rhs.v_;
    }

    mint operator+() const {
        return *this;
    }
    mint& operator+=(const mint& rhs) {
        v_ = (v_ < mod - rhs.v_ ? v_ + rhs.v_ : v_ + rhs.v_ - mod);
        return *this;
    }
    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint{lhs} += rhs;
    }
    mint& operator++() {
        v_ = (v_ + 1 == mod ? 0 : v_ + 1);
        return *this;
    }
    mint operator++(int) {
        mint res{*this};
        ++*this;
        return res;
    }

    mint operator-() const {
        return mod - v_;
    }
    mint& operator-=(const mint& rhs) {
        v_ = (v_ >= rhs.v_ ? v_ - rhs.v_ : v_ + (mod - rhs.v_));
        return *this;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint{lhs} -= rhs;
    }
    mint& operator--() {
        v_ = (v_ ? v_ - 1 : mod - 1);
        return *this;
    }
    mint operator--(int) {
        mint res{*this};
        --*this;
        return res;
    }

    mint& operator*=(const mint& rhs) {
        u64 mult{ static_cast<u64>(v_) * static_cast<u64>(rhs.v_) };
        v_ = static_cast<T>(mult % mod);
        return *this;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint{lhs} *= rhs;
    }

    mint inverse() const {
        i64 res{}, hoge{};
        assert(extendGCD(static_cast<i64>(v_), static_cast<i64>(mod), res, hoge) == 1);
        return mint{res};
    }
    mint& operator/=(const mint& rhs) {
        return *this *= rhs.inverse();
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint{lhs} /= rhs;
    }

    mint pow(u64 k) const {
        mint res{1}, base{k};
        while (k) {
            if (k & 1) res *= base;
            base *= base; 
            k >>= 1;
        }
        return res;
    }
};

} // namespace zawa
