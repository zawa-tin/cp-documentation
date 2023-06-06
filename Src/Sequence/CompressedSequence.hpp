#pragma once

#include "../Template/TypeAlias.hpp"

#include <vector>
#include <algorithm>
#include <cassert>

namespace zawa {

template <class T>
class CompressedSequence {
private:
    std::vector<T> comped;
    std::vector<u32> f;
    
public:
    CompressedSequence() = default;
    CompressedSequence(const std::vector<T>& A) : comped(A), f(A.size()) {
        std::sort(comped.begin(), comped.end());
        comped.erase(std::unique(comped.begin(), comped.end()), comped.end());
        comped.shrink_to_fit();
        f.shrink_to_fit();
        for (u32 i = 0 ; i < A.size() ; i++) {
            f[i] = std::lower_bound(comped.begin(), comped.end(), A[i]) - comped.begin();
        }
    }     

    inline usize size() const {
        return comped.size();
    }

    u32 operator[](const T& v) const {
        return std::lower_bound(comped.begin(), comped.end(), v) - comped.begin();
    }

    inline u32 map(u32 i) const {
        assert(i < f.size());
        return f[i];
    }
};

} // namespace zawa
