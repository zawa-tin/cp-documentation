#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../Src/DataStructure/RMQ/StaticRMQ.hpp"
#include <iostream>
#include <vector>
using namespace std;
struct M {
    using Element = int;
    static Element identity() {
        return (int)1e9;
    }
    static Element operation(Element l, Element r) {
        return std::min(l, r);
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& x : A)
        cin >> x;
    zawa::StaticRMQ<M> rmq{std::move(A)};    
    while (Q--) {
        int l,r;
        cin >> l >> r;
        cout << rmq.product(l,r) << '\n';
    }
}
