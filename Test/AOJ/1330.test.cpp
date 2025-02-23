#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1330"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/PotentializedDisjointSetUnion.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

using namespace zawa;

#include <cassert>
#include <iostream>
int N, Q;
bool solve() {
    std::cin >> N >> Q;
    if (N == 0 and Q == 0) return false;
    PotentializedDisjointSetUnion<AdditiveGroup<int>> dsu(N);
    while (Q--) {
        char t;
        int a, b;
        std::cin >> t >> a >> b;
        a--; b--;
        if (t == '!') {
            int w;
            std::cin >> w;
            dsu.merge(a, b, w);
        }
        else if (t == '?') {
            if (dsu.isDefined(a, b)) std::cout << dsu.distance(a, b) << '\n';
            else std::cout << "UNKNOWN\n";
        }
        else assert(false);
    }
    return true;
}
int main() {
    SetFastIO(); 
    while (solve()) ;
}
