#pragma once

#include <ostream>

namespace zawa {

template <class T>
class Affine {
private:
    T a_{1}, b_{};
public:
    constexpr Affine() {}
    constexpr Affine(const T& a, const T& b) : a_{a}, b_{b} {}
    T a() const noexcept {
        return a_;
    }
    T b() const noexcept {
        return b_;
    }
    constexpr T mapping(const T& x) const {
        return a_ * x + b_;
    }
    constexpr T operator()(const T& x) const {
        return a_ * x + b_;
    }
    friend std::ostream& operator<<(std::ostream& os, const Affine& affine) {
        os << '(' << affine.a_ << ',' << affine.b_ << ')';
        return os;
    }
    friend bool operator==(const Affine& lhs, const Affine& rhs) {
        return lhs.a_ == rhs.a_ and lhs.b_ == rhs.b_;
    }
};

template <class T>
struct AffineMonoid {
    using Element = Affine<T>;
    static constexpr Element identity() noexcept {
        return Element{};
    }
    // f_r(f_l(x)): a_r(a_lx+b_l)+b_r
    static constexpr Element operation(const Element& l, const Element& r) noexcept {
        return Element{ l.a() * r.a(), l.b() * r.a() + r.b() };
    }
};

} // namespace zawa
