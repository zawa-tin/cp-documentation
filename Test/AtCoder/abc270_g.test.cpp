// #define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc270_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 270 G - Sequence in mod P
 * https://atcoder.jp/contests/abc270/submissions/68673492
 */

#include "../../Src/Algebra/Monoid/MonoidDiscreteLogarithm.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
#include "atcoder/modint"

#include <iostream>
#include <utility>
using namespace std;
using namespace zawa;
using mint = atcoder::modint;
struct X : public AffineMonoid<mint> {
    using super = AffineMonoid<mint>;
    static mint action(super::Element f, mint x) {
        return f(x);
    }
};
struct Hasher {
    size_t operator()(const mint& v) const {
        return v.val();
    }
};
long long P, A, B, S, G;
long long solve() {
    mint::set_mod(P);
    auto ans = MonoidDiscreteLogarithm<X, mint, Hasher>(Affine<mint>{A, B}, mint{S}, mint{G}, P);
    if (ans)
        return ans.value();
    else
        return -1;
}
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> P >> A >> B >> S >> G;
        cout << solve() << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
