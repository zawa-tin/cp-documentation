// #define PROBLEM "https://atcoder.jp/contests/abc477/tasks/abc477_g"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/Bucket/BucketRangeProduct.hpp"
#include "../../Src/Graph/Tree/MoonTree.hpp"
#include <iostream>
using namespace std;
using namespace zawa;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<int> X(N);
    for (auto& x : X) {
        cin >> x;
        x--;
    }
    vector<vector<int>> G(N);
    for (int i = 0 ; i < N - 1 ; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<pair<int,int>> UV(Q);
    vector<int> A(Q),B(Q);
    for (int i = 0 ; i < Q ; i++) {
        int u,v;
        cin >> u >> v >> A[i] >> B[i];
        UV[i] = {--u,--v};
    }
    BucketRangeQuery<AdditiveGroup<int>> seg(N+1);
    vector<int> cnt(N);
    seg.operation(0,N);
    auto add = [&](int v) -> void {
        v = X[v];
        seg.operation(cnt[v],-1);
        cnt[v]++;
        seg.operation(cnt[v],+1);
    };
    auto del = [&](int v) -> void {
        v = X[v];
        seg.operation(cnt[v],-1);
        cnt[v]--;
        seg.operation(cnt[v],+1);
    };
    auto eval = [&](int i) -> int {
        return seg.product(A[i],B[i]+1);
    };
    for (int ans : MoonTree(G,UV,add,del,eval))
        cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
