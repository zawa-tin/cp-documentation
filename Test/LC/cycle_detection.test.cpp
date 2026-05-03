#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

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
    }
    auto ret = zawa::CycleDetection(G);
    if (ret) {
        auto es = std::move(ret->second);
        cout << es.size() << '\n';
        for (int i : es)
            cout << i << '\n';
    }
    else
        cout << -1 << '\n';
}
