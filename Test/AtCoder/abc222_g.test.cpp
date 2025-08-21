// #define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc222_g"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 222 G - 222
 * https://atcoder.jp/contests/abc222/submissions/68673469
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
long long P;
long long solve() {
    mint::set_mod(P);
    auto ans = MonoidDiscreteLogarithm<X, mint, Hasher>(Affine<mint>{10, 2}, mint{2}, mint{0}, P);
    if (ans)
        return ans.value() + 1;
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
        cin >> P;
        cout << solve() << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
