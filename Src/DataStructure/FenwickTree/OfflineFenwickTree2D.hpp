#pragma once

#include "../../Template/TypeAlias.hpp"
#include "./FenwickTree.hpp"
#include "../../Sequence/CompressedSequence.hpp"

#include <utility>
#include <vector>
#include <tuple>

namespace zawa {

template <class T, class G>
class OfflineFenwickTree2D {
public:
    using V = typename G::Element;

    OfflineFenwickTree2D() = default;

    u32 operation(T x, T y, const V& v) {
        u32 res{(u32)idx_.size()};
        idx_.emplace_back(false, op_.size());
        op_.emplace_back(x, y, v);
        return res;
    }

    u32 product(T lx, T ly, T rx, T ry) {
        u32 res{(u32)idx_.size()};
        idx_.emplace_back(true, prod_.size());
        prod_.emplace_back(lx, ly, rx, ry);
        return res;
    }

    inline usize size() const noexcept {
        return idx_.size();
    }

    std::vector<std::pair<V, u32>> execute() const {
        std::vector<T> appX;
        appX.reserve(op_.size());
        for (u32 i{} ; i < op_.size() ; i++) {
            appX.push_back(std::get<0>(op_[i]));
        }
        CompressedSequence<T> compX{appX};
        std::vector<std::vector<T>> appY(compX.size() + 1);
        for (u32 i{} ; i < op_.size() ; i++) {
            T x{std::get<0>(op_[i])}, y{std::get<1>(op_[i])};
            for (u32 j{compX[x] + 1} ; j < appY.size() ; j += lsb(j)) {
                appY[j].push_back(y);
            }
        }
        std::vector<CompressedSequence<T>> compY(compX.size() + 1);
        for (u32 i{1} ; i < compY.size() ; i++) {
            compY[i] = CompressedSequence{appY[i]};
        }
        std::vector<FenwickTree<G>> fen(compX.size() + 1); 
        for (u32 i{1} ; i < fen.size() ; i++) {
            fen[i] = FenwickTree<G>(compY[i].size() + 1);
        }
        std::vector<std::pair<V, u32>> res(prod_.size());

        auto prefix{[&](T x, T y) -> V {
            V res{G::identity()};
            for (u32 i{compX[x]} ; i ; i -= lsb(i)) {
                res = G::operation(res, fen[i].prefixProduct(compY[i][y]));
            }
            return res;
        }};

        for (u32 i{} ; i < size() ; i++) {
            if (idx_[i].first) { // product
                auto [lx, ly, rx, ry]{prod_[idx_[i].second]};
                V prod{G::identity()}; 
                prod = G::operation(prod, prefix(rx, ry));
                prod = G::operation(prod, G::inverse(prefix(lx, ry)));
                prod = G::operation(prod, G::inverse(prefix(rx, ly)));
                prod = G::operation(prod, prefix(lx, ly));
                res[idx_[i].second] = std::pair{ prod, i }; 
            }
            else { // operation
                auto [x, y, v]{op_[idx_[i].second]};
                for (u32 j{compX[x] + 1} ; j < fen.size() ; j += lsb(j)) {
                    fen[j].operation(compY[j][y], v);
                }
            }
        }
        return res;
    }

private:
    std::vector<std::tuple<T, T, T>> op_;
    std::vector<std::tuple<T, T, T, T>> prod_;
    std::vector<std::pair<bool, u32>> idx_;

    constexpr i32 lsb(i32 v) const noexcept {
        return v & -v;
    }
};

} // namespace zawa
