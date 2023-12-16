#pragma once

#include "../Template/TypeAlias.hpp"

#include <functional>
#include <iostream>

namespace zawa {

class U32Pair {
private:
    static constexpr u32 SHIFT{32};
    static constexpr u32 MASK{static_cast<u32>((1LL << SHIFT) - 1)};
    u64 value_{};
public:
    constexpr U32Pair() {}
    constexpr U32Pair(u32 first, u32 second) {
        value_ = (static_cast<u64>(first) << SHIFT) | second;
    }
    constexpr u32 first() const noexcept {
        return static_cast<u32>(value_ >> SHIFT);
    }
    constexpr u32 second() const noexcept {
        return static_cast<u32>(value_ & MASK);
    }
    constexpr u64 combined() const noexcept {
        return value_;
    }
    constexpr U32Pair& operator=(const U32Pair& rhs) {
        value_ = rhs.value_;
        return *this;
    }
    friend constexpr bool operator==(const U32Pair& lhs, const U32Pair& rhs) {
        return lhs.value_ == rhs.value_;
    }
    friend constexpr bool operator!=(const U32Pair& lhs, const U32Pair& rhs) {
        return lhs.value_ != rhs.value_;
    }
    friend constexpr bool operator<(const U32Pair& lhs, const U32Pair& rhs) {
        return lhs.value_ < rhs.value_;
    }
    friend constexpr bool operator<=(const U32Pair& lhs, const U32Pair& rhs) {
        return lhs.value_ <= rhs.value_;
    }
    friend constexpr bool operator>(const U32Pair& lhs, const U32Pair& rhs) {
        return lhs.value_ > rhs.value_;
    }
    friend constexpr bool operator>=(const U32Pair& lhs, const U32Pair& rhs) {
        return lhs.value_ >= rhs.value_;
    }
    friend std::ostream& operator<<(std::ostream& os, const U32Pair& pair) {
        os << '(' << pair.first() << ',' << pair.second() << ')';
        return os;
    }
};

struct U32PairHash {
    usize operator()(const U32Pair& pair) const noexcept {
        return std::hash<u64>{}(pair.combined());
    }
};

} // namespace zawa
