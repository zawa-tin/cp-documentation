#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "../../Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp"
#include "atcoder/modint"

#include <iostream>
using mint = atcoder::modint;
using namespace std;
using namespace zawa;

struct M {
    using Element = mint;
    static Element identity() {
        return mint{1};
    }
    static Element operation(Element L, Element R) {
        return L * R;
    }
    static Element action(Element a, Element b) {
        return a * b;
    }
};

struct Hasher {
    size_t operator()(const mint& v) const {
        return v.val();
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y, m;
        cin >> x >> y >> m;
        mint::set_mod(m);
        auto ans = MonoidDiscreteLogarithm<M, mint, Hasher>(mint{x}, mint{1}, mint{y}, m);
        if (ans)
            cout << ans.value() << '\n';
        else
            cout << -1 << '\n';
    }
}
