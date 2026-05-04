#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../Src/DataStructure/FenwickTree/LazyFenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
using namespace zawa;

#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    LazyFenwickTree<AdditiveGroup<long long>> fen(N);
    while (Q--) {
        int type,l,r;
        cin >> type >> l >> r;
        l--;
        if (type == 0) {
            int x;
            cin >> x;
            fen.operation(l,r,x);
        }
        else if (type == 1)
            cout << fen.product(l,r) << '\n';
    }
}
