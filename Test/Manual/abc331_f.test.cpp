#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/SegmentTree.hpp"
#include "../../Src/Algebra/Monoid/RollingHashMonoid.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using Value = RollingHashMonoidData::Value;

Value RollingHashMonoidData::base{
    RollingHashMonoidData::randomValue(26)
};

void solve() {
    SetFastIO();
    int n, q; std::cin >> n >> q;
    std::string s; std::cin >> s;

    std::vector<RollingHashMonoidData> init(n), tini(n); 
    for (int i{} ; i < n ; i++) {
        init[i] = RollingHashMonoidData::generate((Value)s[i]);
        tini[n - i - 1] = RollingHashMonoidData::generate((Value)s[i]);
    }

    SegmentTree<RollingHashMonoid> seg(init), ges(tini);
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 1) {
            int x; std::cin >> x;
            x--;
            char c; std::cin >> c;
            seg.set(x, RollingHashMonoidData::generate((Value)c));
            ges.set(n - x - 1, RollingHashMonoidData::generate((Value)c));
        }
        else if (t == 2) {
            int l, r; std::cin >> l >> r;
            l--;
            bool ans{seg.product(l, r) == ges.product(n - r, n - l)};
            std::cout << (ans ? "Yes" : "No") << '\n';
        }
        else {
            assert(!"input fail");
        }
    }
 }

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World!" << '\n';
#endif
}
