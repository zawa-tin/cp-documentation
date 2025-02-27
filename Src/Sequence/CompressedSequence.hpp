#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>

namespace zawa {

template <class T>
class CompressedSequence {
private:
    std::vector<T> comped_;
    std::vector<u32> f_;
    
public:

    static constexpr u32 NotFound = std::numeric_limits<u32>::max();

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

    u32 upper_bound(const T& v) const {
        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(), comped_.end(), v));
    }

    u32 find(const T& v) const {
        u32 i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(), v));
        return i == comped_.size() or comped_[i] != v ? NotFound : i;
    }

    bool contains(const T& v) const {
        u32 i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(), v));
        return i < comped_.size() and comped_[i] == v;
    }

    u32 at(const T& v) const {
        u32 res = find(v);
        assert(res != NotFound);
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
