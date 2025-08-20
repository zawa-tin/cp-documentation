// #define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_h"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 223 H - Xor Query
 * https://atcoder.jp/contests/abc223/submissions/68663949
 */

#include "../../Src/Sequence/OfflineRangeProduct.hpp"

#include <iostream>
#include <array>
#include <bit>
#include <vector>
using namespace zawa;
using namespace std;
struct M {
    using Element = array<unsigned long long, 60>;
    static unsigned long long reduce(const Element& B, unsigned long long v) {
        for (int i = 59 ; i >= 0 and v ; i--)
            if (v & (1ull << i))
                v ^= B[i];
        return v;
    }
    static bool insert(Element& B, unsigned long long v) {
        v = reduce(B, v);
        if (v) {
            B[bit_width(v) - 1] = v;
            return true;
        }
        return false;
    }
    static Element identity() {
        Element res;
        res.fill(0);
        return res;
    }
    static Element operation(Element l, Element r) {
        for (unsigned long long v : r)
            if (v)
                insert(l, v);
        return l;
    }
    static Element acted(Element l, unsigned long long v) {
        insert(l, v);
        return l;
    }
};
struct query {
    int l, r;
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<unsigned long long> A(N), X(Q);
    for (int i = 0 ; i < N ; i++)
       cin >> A[i];
    vector<query> lr(Q);
    for (int i = 0 ; i < Q ; i++) {
        int l, r;
        cin >> l >> r >> X[i];
        l--;
        lr[i] = {l, r};
    }
    auto ans = OfflineRangeProduct<M>(A, lr);
    for (int i = 0 ; i < Q ; i++)
        cout << (M::reduce(ans[i], X[i]) == 0 ? "Yes\n" : "No\n");
#else
    cout << "Hello World\n";
#endif
}
