// #define PROBLEM "https://atcoder.jp/contests/abc389/tasks/abc389_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/DualFenwickTree.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"

/*
 * AtCoder Beginner Contest 389 - F Rated Range
 * https://atcoder.jp/contests/abc389/submissions/63396294
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace zawa;
int N, L[200020], R[200020], Q, X[300030];
int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) {
        std::cin >> L[i] >> R[i];
        R[i]++;
    }
    std::cin >> Q;
    for (int i = 0 ; i < Q ; i++) std::cin >> X[i];
    CompressedSequence<int> comp(X, X + Q);    
    auto init = comp.comped();
    DualFenwickTree<AdditiveGroup<int>> fen{init.begin(), init.end()};
    auto idx = [&](int v) -> int {
        auto it = fen.maxRight(0, [&](int x) -> bool { return x < v; });
        return it ? it.value() : (int)comp.size();    
    };
    for (int i = 0 ; i < N ; i++) {
        int l = idx(L[i]), r = idx(R[i]);
        fen.operation(l, r, 1);
    }
    for (int i = 0 ; i < Q ; i++) {
        std::cout << fen[comp.at(X[i])] << '\n';
    }
#else
    std::cout << "Hello World\n";
#endif
}
