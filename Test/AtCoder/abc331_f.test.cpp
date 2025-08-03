#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/abc331/tasks/abc331_f"

/*
 * AtCoder Beginner Contest 331 F - Palindrome Query
 * https://atcoder.jp/contests/abc331/submissions/68181997
 */

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

int main() {
#ifdef ATCODER
    SetFastIO();
    int N, Q; 
    std::cin >> N >> Q;
    std::string S; 
    std::cin >> S;

    std::vector<RollingHashMonoidData> init(N), tini(N); 
    for (int i{} ; i < N ; i++) {
        init[i] = RollingHashMonoidData{S[i]};
        tini[N - i - 1] = RollingHashMonoidData{S[i]};
    }
    SegmentTree<RollingHashMonoid> seg{init}, ges{tini};
    while(Q--) {
        int t; 
        std::cin >> t;
        if (t == 1) {
            int x; 
            std::cin >> x;
            x--;
            char c; 
            std::cin >> c;
            seg.assign(x, RollingHashMonoidData{c});
            ges.assign(N - x - 1, RollingHashMonoidData{c});
        }
        else if (t == 2) {
            int l, r; std::cin >> l >> r;
            l--;
            bool ans{seg.product(l, r) == ges.product(N - r, N - l)};
            std::cout << (ans ? "Yes" : "No") << '\n';
        }
        else {
            assert(!"input fail");
        }
    }
#else
    std::cout << "Hello World\n";
#endif
}
