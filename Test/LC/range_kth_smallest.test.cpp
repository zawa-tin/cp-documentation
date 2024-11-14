#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/RangeKthSmallest.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

struct query {
    usize k, l, r;
};

int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    std::vector<query> q(Q);
    for (int i{} ; i < Q ; i++) {
        usize l, r, k;
        std::cin >> l >> r >> k;
        q[i] = { k, l, r };
    }
    for (auto ans : RangeKthSmallest(A, q)) {
        std::cout << ans << '\n';
    }
}
