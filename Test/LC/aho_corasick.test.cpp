#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"

#include "../../Src/Sequence/AhoCorasick.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    zawa::AhoCorasick<string> aho;
    for (int i = 0 ; i < N ; i++) {
        string s;
        cin >> s;
        aho.insert(s);
    }
    auto trie = aho.build();
    const auto& nodes = trie.nodes(); 
    cout << trie.size() << '\n';
    for (int i = 1 ; i < ssize(nodes) ; i++)
        cout << nodes[i].par.first << ' ' << nodes[i].fail << '\n';
    for (int i = 0 ; i < N ; i++)
        cout << trie.match(i) << (i + 1 == N ? '\n' : ' ');
}
