#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <ostream>
#include <functional>
#include <type_traits>

namespace zawa {

template <class Group>
class FenwickTree {
private:
    using Value = typename Group::Element;

    usize n_;
    u32 bitWidth_;
    std::vector<Value> a_, dat_;

    constexpr i32 lsb(i32 x) const noexcept {
        return x & -x;
    }
    
    // a[i] <- a[i] + v
    void addDat(i32 i, const Value& v) {
        assert(0 <= i and i < static_cast<i32>(n_));
        for ( i++ ; i < static_cast<i32>(dat_.size()) ; i += lsb(i)) {
            dat_[i] = Group::operation(dat_[i], v);
        }
    }

    // return a[0] + a[1] + .. + a[i - 1]
    Value product(i32 i) const {
        assert(0 <= i and i <= static_cast<i32>(n_));
        Value res{ Group::identity() };
        for ( ; i > 0 ; i -= lsb(i)) {
            res = Group::operation(res, dat_[i]);
        }
        return res;
    }

public:
    FenwickTree() : n_{}, bitWidth_{}, a_{}, dat_{} {}

    FenwickTree(usize n) : n_{ n }, bitWidth_{ std::__lg(static_cast<u32>(n)) + 1 }, a_(n), dat_(n + 1, Group::identity()) {
        dat_.shrink_to_fit();
    }

    FenwickTree(const std::vector<Value>& a) : n_{ a.size() }, bitWidth_{ std::__lg(static_cast<u32>(a.size())) + 1 }, a_(a), dat_(a.size() + 1, Group::identity()) {
        dat_.shrink_to_fit();  
        for (i32 i{} ; i < static_cast<i32>(n_) ; i++) {
            addDat(i, a[i]);
        }
    }

    // return a[i]
    const Value& get(usize i) const noexcept {
        assert(i < n_);
        return a_[i];
    }

    // return a[i]
    const Value& operator[](usize i) const noexcept {
        assert(i < n_);
        return a_[i];
    }

    usize size() const noexcept {
        return n_;
    }

    // a[i] <- a[i] + v
    void operation(usize i, const Value& v) {
        assert(i < n_);
        addDat(i, v);
        a_[i] = Group::operation(a_[i], v);
    }

    // a[i] <- v
    void set(usize i, const Value& v) {
        assert(i < n_);
        addDat(i, Group::operation(Group::inverse(a_[i]), v));
        a_[i] = v;
    }

    // return a[0] + a[1] + ... + a[r - 1]
    Value prefixProduct(usize r) const {
        assert(r <= n_);
        return product(r);
    }

    // return a[l] + a[l + 1] ... + a[r - 1]
    Value product(usize l, usize r) const {
        assert(l <= r and r <= n_);
        return Group::operation(Group::inverse(product(l)), product(r));
    }

    template <class Function>
    u32 maxRight(usize l, const Function& f) const {
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>, "maxRight's argument f must be function bool(T)");
        assert(l < n_);
        Value sum{ Group::inverse(product(l)) }; 
        u32 r{};
        for (u32 bit{ bitWidth_ } ; bit ; ) {
            bit--;
            u32 nxt{ r | (1u << bit) };
            if (nxt < dat_.size() and f(Group::operation(sum, dat_[nxt]))) {
                sum = Group::operation(sum, dat_[nxt]);
                r = std::move(nxt);
            }
        }
        assert(l <= r);
        return r;
    }

    template <class Function>
    u32 minLeft(usize r, const Function& f) const {
        static_assert(std::is_convertible_v<decltype(f), std::function<bool(Value)>>, "minLeft's argument f must be function bool(T)");
        assert(r <= n_);
        Value sum{ product(r) };
        u32 l{};
        for (u32 bit{ bitWidth_ } ; bit ; ) {
            bit--;
            u32 nxt{ l | (1u << bit) };
            if (nxt <= r and not f(Group::operation(Group::inverse(dat_[nxt]), sum))) {
                sum = Group::operation(Group::inverse(dat_[nxt]), sum);
                l = std::move(nxt);
            }
        }
        assert(l <= r);
        return l;
    }

    // debug print
    friend std::ostream& operator<<(std::ostream& os, const FenwickTree& ft) {
        for (u32 i{} ; i <= ft.size() ; i++) {
            os << ft.prefixProduct(i) << (i == ft.size() ? "" : " ");
        }
        return os;
    }

};


} // namespace zawa
