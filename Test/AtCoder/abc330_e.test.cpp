// #define PROBLEM "https://atcoder.jp/contests/abc330/tasks/abc330_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/DataStructure/Other/MexManager.hpp"

#include <iostream>

using namespace std;
int N, Q, A[200020];
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    zawa::MexManager<int> mex;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> A[i];
        mex.insert(A[i]);
    }
    while (Q--) {
        int i, x;
        cin >> i >> x;
        i--;
        mex.erase(A[i]);
        mex.insert(x);
        A[i] = x;
        cout << mex() << '\n';
    }
#else
    cout << "Hello World\n"; 
#endif
}
