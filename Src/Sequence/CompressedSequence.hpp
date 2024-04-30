#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <algorithm>
#include <cassert>
#include <iterator>

namespace zawa {

template <class T>
class CompressedSequence {
private:
    std::vector<T> comped_;
    std::vector<u32> f_;
    
public:
    CompressedSequence() = default;

    template <class InputIterator>
    CompressedSequence(InputIterator first, InputIterator last) : comped_(first, last), f_{} {
        std::sort(comped_.begin(), comped_.end());
        comped_.erase(std::unique(comped_.begin(), comped_.end()), comped_.end());
        comped_.shrink_to_fit();
        f_.reserve(std::distance(first, last));
        for (auto it{first} ; it != last ; it++) {
            f_.emplace_back(std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(), *it)));
        }
    }

    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(), A.end()) {}

    inline usize size() const noexcept {
        return comped_.size();
    }

    u32 operator[](const T& v) const {
        return std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(), v));
    }

    u32 at(const T& v) const {
        u32 res{(*this)[v]};
        assert(res < size() and comped_[res] == v);
        return res;
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
