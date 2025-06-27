// #define PROBLEM "https://atcoder.jp/contests/abc196/tasks/abc196_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 196 E - Filters
 * https://atcoder.jp/contests/abc196/submissions/67097963
 */

#include "../../Src/Algebra/Monoid/ClampAddMonoid.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    using M = ClampAddMonoid<long long, (long long)1e18>;
    using D = typename M::Element;
    D f = M::identity();
    while (N--) {
        int a, t;
        std::cin >> a >> t;
        if (t == 1) f = M::operation(f, D::add(a));
        else if (t == 2) f = M::operation(f, D::chmax(a));
        else if (t == 3) f = M::operation(f, D::chmin(a));
        else assert(false);
    }
    int Q;
    std::cin >> Q;
    while (Q--) {
        int x;
        std::cin >> x;
        std::cout << f(x) << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
