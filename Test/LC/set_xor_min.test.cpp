#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../Src/DataStructure/Trie/BinaryTrie.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int Q;
    cin >> Q;
    BinaryTrie<30> trie;
    while (Q--) {
        int T, X;
        cin >> T >> X;
        if (T == 0)
            trie.insert(X);
        else if (T == 1) 
            trie.erase(X,trie.count(X));
        else if (T == 2)
            cout << trie.setmin(X) << '\n';
        else
            assert(0);
    }
}
