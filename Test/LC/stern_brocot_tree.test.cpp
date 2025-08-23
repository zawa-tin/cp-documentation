#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include "../../Src/Number/SternBrocotTree.hpp"

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace zawa;
using Node = SternBrocotTree::Node<int>;
using Path = SternBrocotTree::Path<int>;
char from(SternBrocotTree::Direction d) {
    return d == SternBrocotTree::Left ? 'L' : 'R';
}
SternBrocotTree::Direction to(char c) {
    assert(c == 'L' or c == 'R');
    return c == 'L' ? SternBrocotTree::Left : SternBrocotTree::Right;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int Q;
    cin >> Q;
    while (Q--) {
        string T;
        cin >> T;
        if (T == "ENCODE_PATH") {
            int a, b;
            cin >> a >> b;
            Path ans = SternBrocotTree::Encode(Node{a, b});
            cout << ssize(ans);
            for (auto [d, s] : ans)
                cout << ' ' << from(d) << ' ' << s;
            cout << '\n';
        }
        else if (T == "DECODE_PATH") {
            int k;
            cin >> k;
            Path path(k);
            for (int i = 0 ; i < k ; i++) {
                char c;
                int s;
                cin >> c >> s;
                path[i] = {to(c), s};
            }
            auto [a, b] = SternBrocotTree::Decode(path);
            cout << a << ' ' << b << '\n';
        }
        else if (T == "LCA") {
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            auto [p, q] = SternBrocotTree::LCA(Node{a, b}, Node{c, d});
            cout << p << ' ' << q << '\n';
        }
        else if (T == "ANCESTOR") {
            int k, a, b;
            cin >> k >> a >> b;
            auto ans = SternBrocotTree::Ancestor(k, Node{a, b});
            if (ans.has_value())
                cout << ans->first << ' ' << ans->second << '\n';
            else
                cout << -1 << '\n';
        }
        else if (T == "RANGE") {
            int a, b;
            cin >> a >> b;
            auto [l, r] = SternBrocotTree::Range(Node{a, b});
            cout << l.first << ' ' << l.second << ' ' << r.first << ' ' << r.second << '\n';
        }
        else
            assert(0);
    }
}
