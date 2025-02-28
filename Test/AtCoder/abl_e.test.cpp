// #define PROBLEM "https://atcoder.jp/contests/abl/tasks/abl_e"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/SegmentTree/AssignmentSegmentTree.hpp"
#include "atcoder/modint"

#include <iostream>
#include <vector>

/*
 * ACL Beginner Contest - E Replace Digits
 * https://atcoder.jp/contests/abl/submissions/63211812
 */

using namespace zawa;
using mint = atcoder::modint998244353;
int N, Q;
mint p10[2*200020];
mint rep[10][2*200020];

struct M {
    using Element = std::pair<mint, int>;
    static Element identity() {
        return {mint{}, 0};
    }
    static Element operation(const Element& l, const Element& r) {
        return {p10[r.second]*l.first+r.first, l.second+r.second};
    }
    static Element power(Element v, u64 exp) {
        return {rep[v.first.val()][exp], (int)exp};
    }
};
#include <random>
int main() {
    SetFastIO();
    std::cin >> N >> Q; 
    p10[0] = mint::raw(1);
    for (int i = 1 ; i <= N ; i++) p10[i] = p10[i - 1] * mint::raw(10);
    for (int i = 0 ; i < 10 ; i++) {
        // rep[i][0] = mint::raw(i);
        for (int j = 1 ; j <= N ; j++) rep[i][j] = rep[i][j - 1] * mint::raw(10) + mint::raw(i);
    }
    AssignmentSegmentTree<M> seg(N);
    seg.assign(0, N, {mint::raw(1), 1});
    while (Q--) {
        int L, R, D;
        std::cin >> L >> R >> D;
        L--;
        seg.assign(L, R, {mint::raw(D), 1});
        std::cout << seg.product(0, N).first.val() << '\n';
    }
}
