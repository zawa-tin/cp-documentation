// #define PROBLEM "https://atcoder.jp/contests/abc451/tasks/abc451_g"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Beginner Contest 451 G - Minimum XOR Walk
 * https://atcoder.jp/contests/abc451/submissions/74601108
 */

#include "../../Src/DataStructure/Trie/BinaryTrie.hpp"
#include "../../Src/DataStructure/DisjointSetUnion/DisjointSetUnion.hpp"
using namespace zawa;

#include <array>
#include <bit>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using item = array<int,30>;
long long solve() {
    int N,M,K;
    cin >> N >> M >> K;
    vector<vector<pair<int,int>>> G(N);
    DisjointSetUnion dsu(N);
    vector<tuple<int,int,int>> remain;
    for (int i = 0 ; i < M ; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        if (!dsu.same(u,v)) {
            G[u].push_back({v,w});
            G[v].push_back({u,w});
            dsu.merge(u,v);
        }
        else
            remain.push_back({u,v,w});
    }
    vector<int> A(N);
    auto dfs = [&](auto dfs,int v,int p,int k) -> void {
        A[v] = k;
        for (auto [x,w] : G[v])
            if (x != p)
                dfs(dfs,x,v,k^w);
    };
    dfs(dfs,0,-1,0);
    item base;
    base.fill(0);
    auto reduce = [&](int& v) {
        for (int i = 29 ; i >= 0 ; i--)
            if (v & (1 << i))
                v ^= base[i];
    };
    for (auto [u,v,w] : remain) {
        int val = A[u] ^ A[v] ^ w;
        reduce(val);
        if (val)
            base[bit_width<unsigned>(val)-1] = val;
    } 
    vector<int> P(N);
    BinaryTrie<30> trie;
    for (int i = 0 ; i < N ; i++) {
        P[i] = A[i];
        reduce(P[i]);
        trie.insert(P[i]);
    }
    long long ans = 0;
    const int top = bit_width<unsigned>(K)-1;
    for (int i = 0 ; i < N ; i++) {
        trie.erase(P[i]);
        int nd = 1;
        for (int j = 29 ; nd > 0 and j >= 0 ; j--) {
            const int b = (P[i] >> j) & 1;
            if (j > top)
                nd = trie[nd].ch[b];
            else if ((K >> j) & 1) {
                ans += trie[trie[nd].ch[b]].cnt;
                nd = trie[nd].ch[b^1];
            }
            else
                nd = trie[nd].ch[b];
        }
        ans += trie[nd].cnt;
        trie.insert(P[i]);
    }
    ans /= 2;
    return ans;
}
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
        cout << solve() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
