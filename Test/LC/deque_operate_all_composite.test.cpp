#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "../../Src/DataStructure/SWAG/FoldableDeque.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"
using namespace zawa;
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int Q;
    std::cin >> Q;
    FoldableDeque<AffineMonoid<mint>> deq;
    using V = AffineMonoid<mint>::Element;
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int a, b;
            std::cin >> a >> b;
            deq.pushFront(V{mint::raw(a), mint::raw(b)});
        }
        else if (t == 1) {
            int a, b;
            std::cin >> a >> b;
            deq.pushBack(V{mint::raw(a), mint::raw(b)});
        }
        else if (t == 2) {
            deq.popFront();
        }
        else if (t == 3) {
            deq.popBack();
        }
        else {
            int x;
            std::cin >> x;
            std::cout << deq.product()(mint::raw(x)).val() << '\n';
        }
    }
}
