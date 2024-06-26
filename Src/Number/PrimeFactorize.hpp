#pragma once

#include "../Template/TypeAlias.hpp"

#include <type_traits>
#include <utility>
#include <vector>

namespace zawa {

template <class T>
class Factor {
    static_assert(std::is_unsigned_v<T>, "T must be unsigned integer");
private:
    T factor_{};
    u32 exp_{};
public:
    Factor() = default;
    Factor(T factor, u32 exp) : factor_{factor}, exp_{exp} {}
    const T& factor() const {
        return factor_;
    }
    const u32& exp() const {
        return exp_;
    }
    friend bool operator<(const Factor<T>& lhs, const Factor<T>& rhs) {
        return lhs.factor() < rhs.factor();
    }
    friend bool operator<=(const Factor<T>& lhs, const Factor<T>& rhs) {
        return lhs.factor() <= rhs.factor();
    }
    friend bool operator>(const Factor<T>& lhs, const Factor<T>& rhs) {
        return lhs.factor() > rhs.factor();
    }
    friend bool operator>=(const Factor<T>& lhs, const Factor<T>& rhs) {
        return lhs.factor() >= rhs.factor();
    }
    explicit operator std::pair<T, u32>() const {
        return std::pair<T, u32>{ factor_, exp_ };
    }
};

template <class T>
std::vector<Factor<T>> PrimeFactorize(T x) {
    static_assert(std::is_unsigned_v<T>, "T must be unsigned integer");
    std::vector<Factor<T>> res;
    for (T f{2} ; u64{f} * f <= x ; f++) {
        u32 exp{};
        while (x % f == 0) {
            exp++;
            x /= f;
        }
        if (exp) {
            res.emplace_back(f, exp);
        }
    }
    if (x > T{1}) {
        res.emplace_back(x, u32{1});
    }
    return res;
}


} // namespace zawa
