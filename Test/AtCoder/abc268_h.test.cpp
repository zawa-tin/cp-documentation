// #define PROBLEM "https://atcoder.jp/contests/abc268/tasks/abc268_ex"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Sequence/AhoCorasick.hpp"
#include "../../Src/Algebra/Monoid/MonoidAction.hpp"

/*
 * AtCoder Beginner Contest 268 Ex - Taboo
 * https://atcoder.jp/contests/abc268/submissions/68657548
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace zawa;
struct Monoid {
    using Element = bool;
    static Element identity() {
        return false;
    }
    static Element operation(Element l, Element r) {
        return l or r;
    }
};
using M = AddSelfAction<Monoid>;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    string S;
    int N;
    cin >> S >> N;
    AhoCorasick<string> aho;
    for (int i = 0 ; i < N ; i++) {
        string T;
        cin >> T;
        aho.insert(T);
    }
    auto [trie, ban] = aho.build<M>(vector<bool>(N, true));
    int ans = 0, cur = 0;
    for (char c : S) {
        cur = trie.trace(cur, c);
        if (ban[cur]) {
            ans++;
            cur = decltype(trie)::Root();
        }
    }
    cout << ans << '\n';
#else
    cout << "Hello World\n";
#endif
}
