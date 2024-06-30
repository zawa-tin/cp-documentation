#pragma once

#include "../Template/TypeAlias.hpp"

#include <type_traits>

namespace zawa {

template <class T>
class PrimeFactor {
    static_assert(std::is_unsigned_v<T>, "T must be unsigned integer");
private:
    T factor_{};
    u32 exponent_{};

public: 
    PrimeFactor() = default;

    PrimeFactor(T factor, u32 exponent) : factor_{factor}, exponent_{exponent} {}

    inline T factor() const noexcept {
        return factor_;
    }

    inline u32 exponent() const noexcept {
        return exponent_;
    }

    friend bool operator<(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs) {
        return lhs.factor() != rhs.factor() ?
            lhs.factor() < rhs.factor() :
            lhs.exponent() < rhs.exponent();
    }

    friend bool operator>(const PrimeFactor<T>& lhs, const PrimeFactor<T>& rhs) {
        return lhs.factor() != rhs.factor() ?
            lhs.factor() > rhs.factor() :
            lhs.exponent() > rhs.exponent();
    }
};

} // namespace zawa
