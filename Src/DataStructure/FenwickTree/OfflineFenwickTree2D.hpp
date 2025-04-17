#pragma once

#include "../../Template/TypeAlias.hpp"
#include "../../Algebra/Group/GroupConcept.hpp"
#include "./FenwickTree.hpp"
#include "../../Sequence/CompressedSequence.hpp"

#include <cassert>
#include <utility>
#include <vector>
#include <tuple>

namespace zawa {

namespace internal {

template <class T, concepts::Group G>
class FenwickTree2D {
public:

    using V = G::Element;

    FenwickTree2D() = default;

    FenwickTree2D(const std::vector<T>& px, const std::vector<T>& py) 
        : xs_{px}, ys_(xs_.size() + 1), fen_(xs_.size() + 1) {
        assert(px.size());
        assert(px.size() == py.size());
        std::vector<std::vector<T>> appy(xs_.size() + 1);
        for (usize i = 0 ; i < px.size() ; i++) {
            auto x = xs_[px[i]];
            for (x++ ; x < appy.size() ; x += lsb(x)) {
                appy[x].push_back(py[i]);
            }
        }
        for (usize i = 1 ; i < fen_.size() ; i++) {
            ys_[i] = CompressedSequence{appy[i]};
            fen_[i] = FenwickTree<G>{ys_[i].size()};
        }
    }

    void operation(const T& x, const T& y, const V& v) {
        auto i = xs_.find(x);
        assert(i != CompressedSequence<T>::NotFound);
        for ( i++ ; i < fen_.size() ; i += lsb(i)) {
            auto j = ys_[i].find(y);
            assert(j != CompressedSequence<T>::NotFound);
            fen_[i].operation(j, v);
        }
    }

    [[nodiscard]] V prefixProduct(const T& x, const T& y) const {
        V res = G::identity();
        for (u32 i = xs_[x] ; i ; i &= i - 1) {
            res = G::operation(res, fen_[i].prefixProduct(ys_[i][y])); 
        }
        return res;
    }

    [[nodiscard]] V product(const T& lx, const T& ly, const T& rx, const T& ry) const {
        assert(lx <= rx);
        assert(ly <= ry);
        V add = G::operation(prefixProduct(rx, ry), prefixProduct(lx, ly));
        V sub = G::operation(prefixProduct(rx, ly), prefixProduct(lx, ry));
        return G::operation(add, G::inverse(sub));
    }

private:

    CompressedSequence<T> xs_;

    std::vector<CompressedSequence<T>> ys_;

    std::vector<FenwickTree<G>> fen_;

    static constexpr i32 lsb(i32 v) {
        return v & -v;
    }
};

} // namespace internal

template <class T, concepts::Group G>
class OfflineFenwickTree2D {
public:

    OfflineFenwickTree2D(usize q = 0) {
        xs_.reserve(q);
        ys_.reserve(q);
    }

    void operation(const T& x, const T& y) {
        xs_.push_back(x);
        ys_.push_back(y);
    }

    void operation(T&& x, T&& y) {
        xs_.push_back(std::move(x));
        ys_.push_back(std::move(y));
    }

    [[nodiscard]] internal::FenwickTree2D<T, G> build() const {
        return internal::FenwickTree2D<T, G>{xs_, ys_};
    }

private:

    std::vector<T> xs_{}, ys_{};
};

} // namespace zawa
