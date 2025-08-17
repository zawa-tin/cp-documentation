// #define PROBLEM "https://atcoder.jp/contests/abc268/tasks/abc268_ex"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Sequence/AhoCorasick.hpp"

/*
 * AtCoder Beginner Contest 268 Ex - Taboo
 * https://atcoder.jp/contests/abc268/submissions/68594582
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace zawa;
struct M {
    using Element = bool;
    static Element identity() {
        return false;
    }
    static Element add(Element, int) {
        return true;
    }
    static Element merge(Element l, Element r) {
        return l or r;
    }
};
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
    vector<bool> ban;
    auto trie = aho.build<M>(ban);
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
