#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/agc005/tasks/agc005_b"

#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/MinMonoid.hpp"

int main() {
    using namespace zawa;
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    SegmentTree<MinMonoid<int>> seg(a);
    long long ans{};
    for (int i{} ; i < n ; i++) {
        auto f{[&](int v) -> bool {
            return v >= a[i];
        }};
        unsigned left{ seg.minLeft(i, f) }, right{ seg.maxRight(i, f) };
        ans += (long long)(right - i) * (long long)(i - left + 1) * (long long)a[i];
    }
    std::cout << ans << std::endl;
}
