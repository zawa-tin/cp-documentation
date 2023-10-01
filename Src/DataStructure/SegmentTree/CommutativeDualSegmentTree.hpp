#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <iterator>
#include <ostream>
#include <cassert>

namespace zawa {

template <class Monoid>
class CommutativeDualSegmentTree {
public:
    using Operator = typename Monoid::Element;
private:

    static constexpr u32 parent(u32 v) noexcept {
        return v >> 1;
    }
    static constexpr u32 left(u32 v) noexcept {
        return v << 1;
    }
    static constexpr u32 right(u32 v) noexcept {
        return v << 1 | 1;
    }

    usize n_;
    std::vector<Operator> dat_;

    template <class InputIterator>
    inline void initDat(InputIterator first, InputIterator last) {
        for (u32 i{} ; i < n_ ; i++) {
            dat_[i + n_] = *std::next(first, i);
        }
    }

    void push(u32 i) {
        i += n_;
        u32 height{ 32u - __builtin_clz(i) };
        for (u32 h{ height } ; --h ; ) {
            u32 v{ i >> h };
            dat_[left(v)] = Monoid::operation(dat_[left(v)], dat_[v]);
            dat_[right(v)] = Monoid::operation(dat_[right(v)], dat_[v]);
            dat_[v] = Monoid::identity();
        }
    }

public:
    CommutativeDualSegmentTree() = default;
    CommutativeDualSegmentTree(usize n) 
        : n_{ n }, dat_((n << 1), Monoid::identity()) {}
    CommutativeDualSegmentTree(const std::vector<Operator>& dat) 
        : n_{ dat.size() }, dat_((n_ << 1), Monoid::identity()) {
        build(dat.begin(), dat.end());
    }
    template <class InputIterator>
    CommutativeDualSegmentTree(InputIterator first, InputIterator last)
        : n_{ std::distance(first, last) }, dat_((n_ << 1), Monoid::identity()) {
        build(first, last);
    }

    void update(u32 l, u32 r, const Operator& v) {
        assert(l < n_);
        assert(l <= r and r <= n_);
        for (l += n_, r += n_ ; l < r ; l = parent(l), r = parent(r)) {
            if (l & 1) {
                dat_[l] = Monoid::operation(dat_[l], v);
                l++;
            }
            if (r & 1) {
                r--;
                dat_[r] = Monoid::operation(dat_[r], v);
            }
        }
    }

    void set(u32 i, const Operator& v) {
        assert(i < n_);
        push(i);
        dat_[i + n_] = v;
    }

    Operator operator[](u32 i) const {
        assert(i < n_);
        Operator res{ Monoid::identity() };
        for (i += n_ ; i ; i = parent(i)) {
            res = Monoid::operation(res, dat_[i]);
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const CommutativeDualSegmentTree seg) {
        usize size{ seg.dat_.size() };
        for (u32 i{1} ; i < size ; i++) {
            os << seg.dat_[i] << (i + 1 == size ? "" : " ");
        }
        return os;
    }
};

} // namespace zawa
