#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../Src/DataStructure/Wavelet/WaveletMatrix.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int& a : A)
        cin >> a;
    WaveletMatrix wav{move(A)};
    while (Q--) {
        int l,r,k;
        cin >> l >> r >> k;
        cout << wav.kthSmallest(l,r,k) << '\n';
    }
}
