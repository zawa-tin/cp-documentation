#pragma once

#include "../Template/TypeAlias.hpp"
#include "atcoder/modint"
#include "atcoder/convolution"

#include <vector>

namespace zawa {

template <usize MOD = 998244353>
std::vector<atcoder::static_modint<MOD>> StirlingNumberSecondKindFixedN(usize n) {
    using mint = atcoder::static_modint<MOD>;
    std::vector<mint> ifac(n+1);
    mint fac=1;
    for (usize i=2 ; i<=n ; i++)
        fac*=mint::raw(i);
    ifac[n]=fac.inv();
    for (usize i=n ; i>=1 ; i--)
        ifac[i-1]=ifac[i]*mint::raw(i);
    std::vector<mint> a(n+1),b(n+1);
    for (usize i=0 ; i<=n ; i++) {
        a[i]=mint::raw(i).pow(n)*ifac[i];
        b[i]=(i&1?mint{-1}:mint{1})*ifac[i];
    }
    auto pd=atcoder::convolution(a,b);
    pd.resize(n+1);
    return pd;
}

} // namespace zawa
