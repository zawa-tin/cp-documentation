#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <algorithm>

namespace zawa {

template <class T>
class CompressedSequence {
private:
    std::vector<T> arr;
    std::vector<T> comped;
    std::vector<u32> f;
    
public:
    CompressedSequence() = default;
    CompressedSequence(const std::vector<T>& arr_) : arr(arr_), comped(arr_), f(arr_.size()) {
        std::sort(comped.begin(), comped.end());
        comped.erase(std::unique(comped.begin(), comped.end()), comped.end());
        for (u32 i = 0 ; i < arr.size() ; i++) {
            f[i] = std::lower_bound(comped.begin(), comped.end(), arr[i]) - comped.begin();
        }
    }     

    inline usize size() const {
        return comped.size();
    }

    u32 operator[](const T& v) const {
        return std::lower_bound(comped.begin(), comped.end(), v) - comped.begin();
    }

    inline u32 map(u32 i) const {
        return f[i];
    }
};

} // namespace zawa
