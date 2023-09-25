#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <functional>
#include <type_traits>
#include <iostream>

namespace zawa {

template <class Monoid>
class SegmentTree {
public:
    using Value = typename Monoid::Element;
private:
    constexpr u32 left(u32 v) const {
        return v << 1;
    }
    constexpr u32 right(u32 v) const {
        return v << 1 | 1;
    }
    constexpr u32 parent(u32 v) const {
        return v >> 1;
    }

    usize n_;
    std::vector<Value> dat_;

public:
    SegmentTree() = default;
    SegmentTree(u32 n) : n_{ n }, dat_(n << 1, Monoid::identity()) {
        assert(n_);
    }
    SegmentTree(const std::vector<Value>& dat) : n_{ dat.size() }, dat_(dat.size() << 1, Monoid::identity()) {
        assert(n_);
        for (u32 i{} ; i < n_ ; i++) {
            dat_[i + n_] = dat[i];
        }
        for (u32 i{static_cast<u32>(n_) - 1} ; i ; i--) {
            dat_[i] = Monoid::operation(dat_[left(i)], dat_[right(i)]);
        }
    }

    Value get(u32 i) const {
        assert(i < n_);
        return dat_[i + n_];
    }

    void set(u32 i, const Value& value) {
        assert(i < n_);
        i += n_;
        dat_[i] = value;
        while (i = parent(i), i) {
            dat_[i] = Monoid::operation(dat_[left(i)], dat_[right(i)]);
        }
    }

    Value product(u32 l, u32 r) const {
        assert(l < n_);
        assert(l <= r and r <= n_);
        Value leftValue{ Monoid::identity() }, rightValue{ Monoid::identity() };
        for (l += n_, r += n_ ; l < r ; l = parent(l), r = parent(r)) {
            if (l & 1) {
                leftValue = Monoid::operation(leftValue, dat_[l++]);
            }
            if (r & 1) {
                rightValue = Monoid::operation(dat_[--r], rightValue);
            }
        }
        return Monoid::operation(leftValue, rightValue);
    }

    template <class Function>
    u32 maxRight(u32 l, const Function& f) {
        assert(l < n_);
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>, "maxRight's argument f must be function bool(T)");
        assert(f(Monoid::identity()));
        u32 res{l}, width{1};
        Value prod{ Monoid::identity() };
        // 現在の見ている頂点の幅をwidthで持つ
        // 境界がある頂点を含む部分木の根を探す
        // (折り返す時は必要以上の幅を持つ根になるが、widthを持っているのでオーバーしない)
        for (l += n_ ; res + width <= n_ ; l = parent(l), width <<= 1) if (l & 1) {
            if (not f(Monoid::operation(prod, dat_[l]))) break; 
            res += width;
            prod = Monoid::operation(prod, dat_[l++]);
        }
        // 根から下って、境界を発見する
        while (l = left(l), width >>= 1) {
            if (res + width <= n_ and f(Monoid::operation(prod, dat_[l]))) {
                res += width;
                prod = Monoid::operation(prod, dat_[l++]);
            } 
        }
        return res;
    }

    template <class Function>
    u32 minLeft(u32 r, const Function& f) const {
        assert(r <= n_);
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>, "minLeft's argument f must be function bool(T)");
        assert(f(Monoid::identity()));
        u32 res{r}, width{1};
        Value prod{ Monoid::identity() };
        for (r += n_ ; res >= width ; r = parent(r), width <<= 1) if (r & 1) {
            if (not f(Monoid::operation(dat_[r - 1], prod))) break;
            res -= width;
            prod = Monoid::operation(prod, dat_[--r]);
        }
        while (r = left(r), width >>= 1) {
            if (res >= width and f(Monoid::operation(dat_[r - 1], prod))) {
                res -= width;
                prod = Monoid::operation(dat_[--r], prod);
            }
        }
        return res;
    }

    void debug() {
        for (auto d : dat_) std::cout << d << ' ';
        std::cout << std::endl;
    }
};

} // namespace zawa
