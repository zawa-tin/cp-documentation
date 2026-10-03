#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "../../Src/Sequence/FindLinearRecurrence.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<mint> A(N);
    for (int i = 0 ; i < N ; i++) {
        int a;
        cin >> a;
        A[i]=mint::raw(a);
    }
    auto ans=zawa::FindLinearRecurrence(A);
    cout << ans.size() << '\n';
    for (int i = 0 ; i < ssize(ans) ; i++)
        cout << ans[i].val() << (i+1==ssize(ans)?'\n':' ');
}
