#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://yukicoder.me/problems/no/649"

/*
 * yukicoder No.649 ここでちょっとQK！
 * https://yukicoder.me/submissions/1065591
 */

#include "../../Src/DataStructure/Other/PriorityProductSet.hpp"

struct G {
    using Element = long long;
    static Element identity() { return 0; }
    static Element operation(Element,Element) { return 0; }
    static Element inverse(Element) { return 0; }
};

#include <iostream>
int Q, K;
void solve() {
    std::cin >> Q >> K;
    zawa::PriorityProductSet<G> set(K);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            long long v;
            std::cin >> v;
            set.insert(v);
        }
        else if (t == 2) {
            if (set.size() < (int)K) {
                std::cout << -1 << '\n';
            }
            else {
                std::cout << set.popK() << '\n';
            }
        }
        else {
            assert(false);
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
