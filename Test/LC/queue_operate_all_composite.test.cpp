#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SWAG/FoldableQueue.hpp"
#include "../../Src/Algebra/Monoid/AffineMonoid.hpp"

#include <cassert>
#include <iostream>

#include "atcoder/modint"
using mint = atcoder::modint998244353;

using namespace zawa;

int main() {
    SetFastIO();
    int Q;
    std::cin >> Q;
    FoldableQueue<AffineMonoid<mint>> que{};
    using V = typename AffineMonoid<mint>::Element;
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int a, b;
            std::cin >> a >> b;
            que.push(V{a, b});
        }
        else if (t == 1) {
            que.pop();
        }
        else if (t == 2) {
            int x;
            std::cin >> x;
            std::cout << (que.empty() ? V{} : que.product())(x).val() << '\n';
        }
        else {
            assert(false);
        }
    }
}
