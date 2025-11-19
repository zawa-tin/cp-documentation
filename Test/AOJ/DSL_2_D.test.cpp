#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"

#include <cassert>
#include <iostream>
#include <vector>

using namespace zawa;
using namespace std;

struct M {
    using Element = int;
    static int identity() {
        return -1;
    }
    static int operation(int a, int b) {
        return (b == identity() ? a : b);
    }
};
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    AssignmentSegmentTree<M> seg(vector<int>(n, (1LL << 31) - 1));
    while (q--) {
        int t; 
        cin >> t;
        if (t == 0) {
            int l, r, x; 
            cin >> l >> r >> x;
            seg.assign(l, r + 1, x);
        }
        else if (t == 1) {
            int i; 
            cin >> i;
            cout << seg[i] << '\n';
        }
        else
            assert(false);
    }
}
