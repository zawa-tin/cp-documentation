// #define PROBLEM "https://atcoder.jp/contests/soundhound2018-summer-final/tasks/soundhound2018_summer_final_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * SoundHound Programming Contest 2018 Masters Tournament 本選 E - Hash Swapping
 * https://atcoder.jp/contests/soundhound2018-summer-final/submissions/75029139
 */

#include "../../Src/DataStructure/SegmentTree/PersistentSegmentTree.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;
const int BASE = 1000000;
const int MOD = 1000000007;
struct VM {
    using Element = pair<long long,long long>;
    static Element identity() {
        return {0,1};
    }
    static Element operation(Element L, Element R) {
        R.first = (R.first * L.second + L.first) % MOD;
        R.second = (L.second * R.second) % MOD;
        return R;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector A(M,vector<VM::Element>(N));
    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < N ; j++) {
            char c;
            cin >> c;
            A[i][j] = {c - 'a' + 1,BASE};
        }
    }
    PersistentSegmentTree<VM> seg(A[0]);
    vector<int> T(M);
    for (int i = 1 ; i < M ; i++)
        T[i] = seg.construct(A[i]);
    int Q;
    cin >> Q;
    while (Q--) {
        int t,X,Y,L,R;
        cin >> t >> X >> Y >> L >> R;
        L--;
        X--; Y--;
        if (t == 1) {
            int tmp = seg.copy(T[X],T[Y],L,R);
            T[X] = seg.copy(T[Y],T[X],L,R);
            T[Y] = tmp;
        }
        else if (t == 2)
            cout << seg.product(T[X],L,R).first << '\n';
        else
            assert(0);
    }
#else
    cout << "Hello World\n";
#endif
}
