// #define PROBLEM "https://atcoder.jp/contests/abc419/tasks/abc419_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 419 F - All Included
 * https://atcoder.jp/contests/abc419/submissions/68657508
 */

#include "../../Src/Sequence/AhoCorasick.hpp"
#include "../../Src/Algebra/Monoid/MonoidAction.hpp"
#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace zawa;
using namespace std;
struct Monoid {
    using Element = int;
    static Element identity() {
        return 0;
    }
    static Element operation(Element a, Element b) {
        return a | b;
    }
};
using M = AddSelfAction<Monoid>;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, L;
    cin >> N >> L;
    AhoCorasick<string> aho;
    vector<int> idx(N);
    for (int i = 0 ; i < N ; i++) {
        string s;
        cin >> s;
        aho.insert(s);
        idx[i] = 1 << i;
    }
    auto [trie, msk] = aho.build<M>(idx);
    vector dp(1 << N, vector<mint>(trie.size()));
    dp[0][decltype(trie)::Root()] = 1;
    while (L--) {
        vector nxt(1 << N, vector<mint>(trie.size())); 
        for (int b = 0 ; b < (1 << N) ; b++)
            for (int i = 0 ; i < ssize(trie) ; i++)
                if (dp[b][i] != mint{}) 
                    for (char c = 'a' ; c <= 'z' ; c++) {
                        int nd = trie.trace(i, c);
                        nxt[b | msk[nd]][nd] += dp[b][i];
                    }
        dp = move(nxt);
    }
    mint ans = accumulate(dp[(1 << N) - 1].begin(), dp[(1 << N) - 1].end(), mint{});
    cout << ans.val() << '\n';
#else
    cout << "Hello World\n";
#endif
}
