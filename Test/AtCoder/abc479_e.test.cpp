// #define PROBLEM "https://atcoder.jp/contests/abc479/tasks/abc479_e"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 479 E - Cut and Add
 * https://atcoder.jp/contests/abc479/submissions/80076471
 */
#include "../../Src/Graph/Tree/HeavyLightDecomposition.hpp"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace zawa;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<pair<int,int>> E(N-1);
    for (int i = 0 ; i < N - 1 ; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        E[i]={a,b};
    }
    HeavyLightDecomposition hld{G}; 
    vector<long long> imos(N+1);
    auto operation=[&](int l,int r,int x) {
        imos[l]+=x;
        imos[r]-=x;
    };
    for (int i = 0 ; i < N - 1 ; i++) {
        auto [a,b] = E[i];
        if (hld.isAncestor(a,b))
            swap(a,b);
        // isAncestor(b,a) .. aがbの祖先
        auto [l,r]=hld.subtreeQuery(b);
        if (hld.size(b) > N-hld.size(b))
            operation(l,r,i+1);
        else {
            operation(0,l,i+1);
            operation(r,N,i+1);
        }
    }
    for (int i = 0 ; i < N ; i++)
        imos[i+1]+=imos[i];
    vector<long long> res(N);
    for (int i = 0 ; i < N ; i++)
        res[i]=imos[hld[i]];
    for (int i = 0 ; i < N ; i++)
        cout << res[i] << (i+1==N?'\n': ' ');
#else
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
