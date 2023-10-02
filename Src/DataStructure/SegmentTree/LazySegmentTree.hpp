#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <iterator>
#include <cassert>
#include <ostream>

#include <iostream>

namespace zawa {

template <class Structure>
class LazySegmentTree {
public:
    using VM = typename Structure::ValueMonoid;
    using OM = typename Structure::OperatorMonoid;
    using Value = typename VM::Element;
    using Operator = typename OM::Element;

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
    static constexpr u32 depth(u32 v) noexcept {
        return 31u - __builtin_clz(v);
    }
    static constexpr u32 trailingZeros(u32 v) noexcept {
        return __builtin_ctz(v);
    }

    struct Node {
        Value v_{ VM::identity() };
        Operator o_{ OM::identity() };
        Node() = default;
        Node(const Value& v, const Operator& o) : v_{v}, o_{o} {}
    };

    usize n_{};
    std::vector<Node> dat_;

    static Value action(const Node& node) {
        return Structure::mapping(node.v_, node.o_);
    }

    // ノードvの子に作用を伝播させる
    void propagate(u32 v) {
        dat_[left(v)].o_ = OM::operation(dat_[left(v)].o_, dat_[v].o_);
        dat_[right(v)].o_ = OM::operation(dat_[right(v)].o_, dat_[v].o_);
        dat_[v].o_ = OM::identity();
    }

    // ノードvの祖先のノードの作用素を全て適用する
    void propagateAncestor(u32 v) {
        u32 dep{depth(v)};
        u32 zeros{trailingZeros(v)};
        for (u32 d{dep} ; d != zeros ; d--) {
            propagate(v >> d);
        }
    }

    // ノードvの値を再計算する
    void recalc(u32 v) {
        dat_[v].v_ = VM::operation(action(dat_[left(v)]), action(dat_[right(v)]));
    }

    // 要素vを持つノードの祖先を再計算する
    void recalcAncestor(u32 v) {
        v >>= trailingZeros(v);
        for (v = parent(v) ; v ; v = parent(v)) {
            recalc(v);
        }
    }

    template <class InputIterator>
    void datInit(InputIterator first) {
        auto it{first};
        for (u32 i{} ; i < n_ ; i++) {
            dat_[i + n_].v_ = *it;
            it++;
        }
        for (u32 i{static_cast<u32>(n_)} ; --i ; ) {
            dat_[i].v_ = VM::operation(dat_[left(i)].v_, dat_[right(i)].v_);
        }
    }

public:
    
    LazySegmentTree() = default;
    LazySegmentTree(usize n) : n_{n}, dat_((n << 1)) {
        assert(n_);
    }
    LazySegmentTree(const std::vector<Value>& a) : n_{a.size()}, dat_((a.size() << 1)) {
        assert(!a.empty());
        datInit(a.begin());
    }
    template <class InputIterator>
    LazySegmentTree(InputIterator first, InputIterator last) 
        : n_{static_cast<usize>(std::distance(first, last))}, dat_(std::distance(first, last) << 1) {
        assert(n_);
        datInit(first);
    }

    usize size() const noexcept {
        return n_;
    }

    void operation(u32 i, const Operator& o) {
        assert(i < n_);
        i += size();
        propagateAncestor(i);
        dat_[i].o_ = OM::operation(dat_[i].o_, o);
        recalcAncestor(i);
    }

    void operation(u32 L, u32 R, const Operator& o) {
        assert(L < n_);
        assert(L <= R and R <= n_);
        L += size();
        R += size();
        propagateAncestor(L);
        propagateAncestor(R);
        for (u32 l = L, r = R ; l < r ; l = parent(l), r = parent(r)) {
            if (l & 1) {
                dat_[l].o_ = OM::operation(dat_[l].o_, o);
                l++;
            }
            if (r & 1) {
                r--;
                dat_[r].o_ = OM::operation(dat_[r].o_, o);
            }
        }
        recalcAncestor(L);
        recalcAncestor(R);
    }

    void set(u32 i, const Value& v) {
        assert(i < n_);
        i += size();
        for (u32 d{depth(i)} ; d ; d--) {
            propagate(i >> d);
        }
        dat_[i] = Node{ v, OM::identity() };
        for (i = parent(i) ; i ; i = parent(i)) {
            recalc(i);
        }
    }

    const Value& operator[](u32 i) {
        assert(i < n_);
        i += size();
        for (u32 d{depth(i)} ; d ; d--) {
            propagate(i >> d);
        }
        propagateAncestor(i);
        return action(dat_[i]);
    }

    Value product(u32 L, u32 R) {
        assert(L < n_);
        assert(L <= R and R <= n_);
        L += size();
        R += size();
        propagateAncestor(L);
        propagateAncestor(R);
        recalcAncestor(L);
        recalcAncestor(R);
        Value l{VM::identity()}, r{VM::identity()};
        for ( ; L < R ; L = parent(L), R = parent(R)) {
            if (L & 1) {
                l = VM::operation(l, action(dat_[L]));
                L++;
            }
            if (R & 1) {
                R--;
                r = VM::operation(action(dat_[R]), r);
            }
        }
        return VM::operation(l, r);
    }

    friend std::ostream& operator<<(std::ostream& os, const LazySegmentTree& seg) {
        usize size{seg.dat_.size()};
        os << "Value :\n";
        for (u32 i{1} ; i < size ; i++) {
            os << seg.dat_[i].v_ << (i + 1 == size ? "\n" : " ");
        }
        os << "Operator :\n";
        for (u32 i{1} ; i < size ; i++) {
            os << seg.dat_[i].o_ << (i + 1 == size ? "\n" : " ");
        }
        os << "Action :\n";
        for (u32 i{1} ; i < size ; i++) {
            os << action(seg.dat_[i]) << (i + 1 == size ? "\n" : " ");
        }
        return os;
    }

/*
    template <class F>
    u32 maxRight(u32 l, const F& f) {

    }

    template <class F>
    u32 minLeft(u32 r, const F& f) {

    }
*/
};

} // namespace zawa
