#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>

namespace zawa {

template <class S>
class DualSparseTable {
public:
    using Value = typename S::Element;

    DualSparseTable() = default;
    
    DualSparseTable(const std::vector<Value>& A)
        : n_{A.size()}, L_(A.size() + 1), dat_{} {
        
        assert(A.size());
        for (u32 i{1} ; i < L_.size() ; i++) {
            L_[i] = L_[i - 1] + (i >> (L_[i - 1] + 1));
        }
        dat_ = std::vector(L_.back() + 1, A);
    }

    void operation(u32 L, u32 R, const Value& v) {
        assert(L <= R and R <= size());
        if (L == R) {
            return;
        }
        else if (L + 1 == R) {
            dat_[0][L] = S::operation(dat_[0][L], v);
        }
        else {
            u32 now{L_[R - L]};
            dat_[now][L] = S::operation(dat_[now][L], v);
            dat_[now][R - (1 << now)] = S::operation(dat_[now][R - (1 << now)], v);
        }
    }

    constexpr usize size() const {
        return n_;
    }

    std::vector<Value> build() {
        assert(dat_.size() >= 2u);
        for (u32 i{static_cast<u32>(dat_.size()) - 2u} ; i + 1 < dat_.size() ; i--) {
            for (u32 j{} ; j + (1 << i) < size() ; j++) {
                dat_[i][j] = S::operation(dat_[i][j], dat_[i + 1][j]);
                dat_[i][j + (1 << i)] = S::operation(dat_[i][j + (1 << i)], dat_[i + 1][j]);
            }
        }
        return dat_[0];
    }

private:
    
    usize n_{};
    std::vector<u32> L_;
    std::vector<std::vector<Value>> dat_{};
};

} // namespace zawa
