#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <algorithm>
#include <cassert>

namespace zawa {

template <class T>
class CompressedSequence {
private:
    std::vector<T> comped_;
    std::vector<u32> f_;
    
public:
    CompressedSequence() = default;
    CompressedSequence(const std::vector<T>& A) : comped_(A), f_(A.size()) {
        std::sort(comped_.begin(), comped_.end());
        comped_.erase(std::unique(comped_.begin(), comped_.end()), comped_.end());
        comped_.shrink_to_fit();
        f_.shrink_to_fit();
        for (u32 i{} ; i < A.size() ; i++) {
            f_[i] = std::lower_bound(comped_.begin(), comped_.end(), A[i]) - comped_.begin();
        }
    }     

    inline usize size() const noexcept {
        return comped_.size();
    }

    u32 operator[](const T& v) const {
        return std::lower_bound(comped_.begin(), comped_.end(), v) - comped_.begin();
    }

    inline u32 map(u32 i) const noexcept {
        assert(i < f_.size());
        return f_[i];
    }

    inline T inverse(u32 i) const noexcept {
        assert(i < size());
        return comped_[i];
    }
};

} // namespace zawa
