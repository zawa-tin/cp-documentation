#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Number/Mersenne61ModInt.hpp"

#include <random>
#include <type_traits>

namespace zawa {

struct RollingHashMonoidData {
    using Value = Mersenne61ModInt::Value;
    using Size = usize;
    static Value base;
    Value hash{}, pow{base};
    usize len{};

    constexpr RollingHashMonoidData() = default;
    constexpr RollingHashMonoidData(Value h, Value p, usize l) : hash{h}, pow{p}, len{l} {}
    
    // 単一要素vからなるハッシュを返す
    template <class T>
    static constexpr RollingHashMonoidData generate(const T& v) {
        static_assert(std::is_convertible_v<T, Value>, "v must be convertible unsigned interger value");
        return RollingHashMonoidData{v, base, 1};
    }

    static Value randomValue(const Value& sigma) {
        return std::mt19937{std::random_device{}()}() % (Mersenne61ModInt::Mod() - sigma) + sigma + 1;
    }

    friend constexpr bool operator==(const RollingHashMonoidData& lhs, const RollingHashMonoidData& rhs) {
        return lhs.hash == rhs.hash and lhs.len == rhs.len;
    }
    friend constexpr bool operator!=(const RollingHashMonoidData& lhs, const RollingHashMonoidData& rhs) {
        return lhs.hash != rhs.hash or lhs.len != rhs.len;
    }
};

struct RollingHashMonoid {
    using Modulo = Mersenne61ModInt;
    using Element = RollingHashMonoidData;
    static constexpr Element identity() noexcept {
        return Element{};
    }
    static constexpr Element operation(const Element& lhs, const Element& rhs) noexcept {
        return Element{
            Modulo::Modulo(Modulo::UnsafeMul(lhs.hash, rhs.pow) + rhs.hash),
            Modulo::Mul(lhs.pow, rhs.pow),
            lhs.len + rhs.len
        };
    }
};

} // namespace zawa
