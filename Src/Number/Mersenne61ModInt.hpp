#pragma once

#include "../Template/TypeAlias.hpp"

namespace zawa {

// @reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
class Mersenne61ModInt {
public:
    using Value = u64;
private:
    static constexpr Value MOD{(1ull << 61) - 1}; // == MASK61
    static constexpr Value MASK30{(1ull << 30) - 1};
    static constexpr Value MASK31{(1ull << 31) - 1};
    Value v_{};
public:
    constexpr Mersenne61ModInt() {}

    static constexpr Value Mod() noexcept {
        return MOD;
    }
    static constexpr Value Modulo(const Value& v) noexcept {
        Value res{(v >> 61) + (v & MOD)};
        res = (res >= MOD ? res - MOD : res);
        return res;
    }
    static constexpr Value UnsafeMul(const Value& a, const Value& b) noexcept {
        Value fa{a >> 31}, fb{b >> 31};
        Value ba{a & MASK31}, bb{b & MASK31};
        Value mid{fa * bb + fb * ba};
        return Value{2}*fa*fb + (mid >> 30) + ((mid & MASK30) << 31) + ba*bb;
    }
    static constexpr Value Mul(const Value& a, const Value& b) noexcept {
        return Modulo(UnsafeMul(a, b));
    }
};

};
