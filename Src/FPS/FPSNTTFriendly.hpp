#pragma once

#include "../Template/TypeAlias.hpp"

#include "atcoder/modint"
#include "atcoder/convolution"

#include <iostream>
#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <usize MOD = 998244353>
struct FPSNTTFriendly : public std::vector<atcoder::static_modint<MOD>> {

    using std::vector<atcoder::static_modint<MOD>>::vector;

    using V = atcoder::static_modint<MOD>;

    FPSNTTFriendly(const std::vector<V>& f) {
        this->reserve(f.size());
        for (V v : f) this->push_back(std::move(v));
    }

    FPSNTTFriendly<MOD> resized(usize n) const {
        auto cp = *this;
        cp.resize(n);
        return cp;
    }

    FPSNTTFriendly<MOD> inv(usize n) const {
        assert(this->size() and (*this)[0] != V{0});
        FPSNTTFriendly<MOD> g{this->front().inv()};
        while (g.size() < n) {
            auto fgg = [&]() {
                auto res = g;
                FPSNTTFriendly<MOD> f(resized(g.size() << 1));
                const usize m = res.size(), k = f.size(), s = (m + m - 1) + k - 1;
                const usize z = atcoder::internal::bit_ceil(s);
                res.resize(z);
                f.resize(z);
                atcoder::internal::butterfly(res);
                atcoder::internal::butterfly(f);
                for (usize i = 0 ; i < z ; i++) res[i] *= res[i] * f[i];
                atcoder::internal::butterfly_inv(res);
                res.resize(k);
                res *= V{z}.inv();
                return res;
            }();
            // auto gg = atcoder::convolution(g, g);
            // std::vector<T> f(g.size() << 1);
            // for (usize i = 0 ; i < std::min(f.size(), F.size()) ; i++) f[i] = F[i];
            // auto fgg = atcoder::convolution(f, gg);
            g = V{2} * g - fgg;
        }
        g.resize(n);
        return g;
    }

    FPSNTTFriendly<MOD> differential() const {
        if (this->empty()) return FPSNTTFriendly{};
        FPSNTTFriendly res(this->size() - 1);
        for (usize i = 1 ; i < this->size() ; i++) {
            res[i - 1] = (*this)[i] * V{i};
        }
        return res;
    }

    // C = 0
    FPSNTTFriendly<MOD> integral() const {
        FPSNTTFriendly<MOD> res(this->size() + 1);
        for (usize i = 0 ; i < this->size() ; i++) {
            res[i + 1] = (*this)[i] / V{i + 1};
        }
        return res;
    }

    FPSNTTFriendly<MOD> inv() const {
        return inv(this->size());
    }

    FPSNTTFriendly<MOD> log(usize n) const {
        assert(this->size() and (*this)[0] == V{1});
        return FPSNTTFriendly<MOD>{differential() / (*this)}.resized(n - 1).integral();
    }

    FPSNTTFriendly<MOD> log() const {
        return log(this->size()); 
    }

    FPSNTTFriendly<MOD> operator+() const {
        return *this;
    }

    FPSNTTFriendly<MOD> operator-() const {
        for (usize i = 0 ; i < this->size() ; i++) (*this)[i] *= V::raw(MOD - 1);
    }

    FPSNTTFriendly<MOD>& operator+=(const FPSNTTFriendly<MOD>& f) {
        if (this->size() < f.size()) this->resize(f.size());
        for (usize i = 0 ; i < f.size() ; i++) (*this)[i] += f[i];
        return *this;
    }

    FPSNTTFriendly<MOD>& operator-=(const FPSNTTFriendly<MOD>& f) {
        if (this->size() < f.size()) this->resize(f.size());
        for (usize i = 0 ; i < f.size() ; i++) (*this)[i] -= f[i];
        return *this;
    }

    FPSNTTFriendly<MOD>& operator*=(const V& v) {
        for (usize i = 0 ; i < this->size() ; i++) (*this)[i] *= v;
        return *this;
    }

    friend FPSNTTFriendly<MOD> operator*(const FPSNTTFriendly<MOD>& l, const atcoder::static_modint<MOD>& r) {
        return FPSNTTFriendly<MOD>{l} *= r;
    }

    friend FPSNTTFriendly<MOD> operator*(const atcoder::static_modint<MOD>& l, const FPSNTTFriendly<MOD>& r) {
        return FPSNTTFriendly<MOD>{r} *= l;
    }

    FPSNTTFriendly<MOD>& operator*=(FPSNTTFriendly<MOD> f) {
        auto l = *this; 
        auto r = std::move(f);
        auto conved = atcoder::convolution(l, r);
        return *this = std::move(conved);
    }

    FPSNTTFriendly<MOD>& operator/=(const V& v) {
        return (*this) *= v.inv();
    }

    friend FPSNTTFriendly<MOD> operator/(const FPSNTTFriendly<MOD>& l, const atcoder::static_modint<MOD>& r) {
        return FPSNTTFriendly<MOD>{l} /= r;
    }

    FPSNTTFriendly<MOD>& operator/=(FPSNTTFriendly<MOD> f) {
        return (*this) *= f.inv();
    }
};

template <usize MOD = 998244353>
FPSNTTFriendly<MOD> operator+(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>& r) {
    return FPSNTTFriendly<MOD>{l} += r;
}

template <usize MOD = 998244353>
FPSNTTFriendly<MOD> operator-(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>& r) {
    return FPSNTTFriendly<MOD>{l} -= r;
}

template <usize MOD = 998244353>
FPSNTTFriendly<MOD> operator*(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>& r) {
    return atcoder::convolution(l, r);
}

template <usize MOD = 998244353>
FPSNTTFriendly<MOD> operator/(const FPSNTTFriendly<MOD>& l, const FPSNTTFriendly<MOD>& r) {
    return FPSNTTFriendly<MOD>{atcoder::convolution(l, r.inv())};
}

template <usize MOD = 998244353>
std::ostream& operator<<(std::ostream& os, const FPSNTTFriendly<MOD>& f) {
    for (usize i = 0 ; i < f.size() ; i++) os << f[i].val() << (i + 1 == f.size() ? "" : " ");
    return os;
}

template <usize MOD = 998244353>
std::istream& operator>>(std::istream& is, FPSNTTFriendly<MOD>& f) {
    for (auto& v : f) {
        i64 x;
        is >> x;
        v = atcoder::static_modint<MOD>{x};
    }
    return is;
}

template <usize MOD = 998244353>
using FPS = FPSNTTFriendly<MOD>;

} // namespace zawa
