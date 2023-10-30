#pragma once

#include "../../Template/TypeAlias.hpp"

#include <vector>
#include <cassert>
#include <ostream>

namespace zawa {

template <class Structure>
class SparseTable {
private:
    using Value = typename Structure::Element;
    std::vector<u32> L;
    std::vector<std::vector<Value>> dat;
public:

    SparseTable(const std::vector<Value>& a) : L(a.size() + 1) {
        for (u32 i{1} ; i < L.size() ; i++) {
            L[i] = L[i - 1] + (i >> (L[i - 1] + 1));
        }
        dat.resize(L.back() + 1);
        dat[0] = a;
        for (u32 i{1}, len{2} ; i < dat.size() ; i++, len <<= 1) {
            dat[i] = dat[i - 1];
            for (u32 j{} ; j + len - 1 < dat[i].size() ; j++) {
                dat[i][j] = Structure::operation(dat[i - 1][j], dat[i - 1][j + (len >> 1)]);
            }
        }
    }

    Value product(u32 l, u32 r) const {
        assert(l <= r);
        assert(l < dat[0].size());
        assert(r <= dat[0].size());
        u32 now{L[r - l]};
        return Structure::operation(dat[now][l], dat[now][r - (1 << now)]);
    }

    friend std::ostream& operator<<(std::ostream& os, const SparseTable<Structure>& spt) {
        for (u32 i{}, len{1} ; i < spt.dat.size() ; i++, len <<= 1) {
            os << "length = " << len << '\n';
            for (u32 j{} ; j + len - 1 < spt.dat[i].size() ; j++) {
                os << spt.dat[i][j] << (j + len == spt.dat[i].size() ? '\n' : ' ');
            }
        }
        return os;
    }
};

} // namespace zawa
