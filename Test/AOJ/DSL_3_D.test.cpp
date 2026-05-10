#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D"

#include "../../Src/DataStructure/SWAG/SlindingPriority.hpp"
using namespace zawa;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,L;
    cin >> N >> L;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    auto ans = StaticLengthPriority(A,L); 
    for (int i = 0 ; i < ssize(ans) ; i++)
        cout << ans[i] << (i + 1 == ssize(ans) ? '\n' : ' ');
}
