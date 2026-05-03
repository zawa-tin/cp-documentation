#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include "../../Src/Graph/CycleDetection.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> G(N);
    for (int i = 0 ; i < M ; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back({v,i});
        G[v].push_back({u,i});
    }
    auto ret = zawa::CycleDetection(G);
    if (ret) {
        auto [vs,es] = std::move(*ret);
        cout << ssize(vs) << '\n';
        for (int i = 0 ; i < ssize(vs) ; i++)
            cout << vs[i] << (i + 1 == ssize(vs) ? '\n' : ' ');
        for (int i = 0 ; i < ssize(es) ; i++)
            cout << es[i] << (i + 1 == ssize(es) ? '\n' : ' ');
    }
    else
        cout << -1 << '\n';
}
