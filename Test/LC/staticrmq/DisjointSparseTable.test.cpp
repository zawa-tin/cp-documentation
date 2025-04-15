#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../Src/DataStructure/SparseTable/DisjointSparseTable.hpp"

#include <iostream>
#include <vector>
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
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int& a : A) std::cin >> a;
    zawa::DisjointSparseTable<M> dst{A};
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << dst.product(l, r) << '\n';
    }
}
