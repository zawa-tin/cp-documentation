#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/Mo/Mo.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

/*
 * AtCoder Beginner Contest 384 G - Abs Sum
 * https://atcoder.jp/contests/abc384/submissions/67045346
 */

using namespace zawa;

int N, K, A[100000], B[100000];
struct query {
    usize l, r;
};
query Q[10000];

void solve() {
    CompressedSequence a{std::vector(A, A + N)}, b{std::vector(B, B + N)};
    FenwickTree<AdditiveGroup<int>> ca(a.size()), cb(b.size());
    FenwickTree<AdditiveGroup<long long>> sa(a.size()), sb(b.size());
    long long ans = 0;
    auto addA = [&](int i) -> void {
        // std::cout << "addA " << i << std::endl;
        int sm = cb.prefixProduct(b[A[i]]); 
        ans += (long long)A[i] * sm;
        ans += (long long)-A[i] * (cb.prefixProduct(b.size()) - sm);
        ans += sb.prefixProduct(b.size()) - 2LL * sb.prefixProduct(b[A[i]]);
        sa.operation(a.map(i), A[i]);
        ca.operation(a.map(i), 1);
    };
    auto addB = [&](int i) -> void {
        // std::cout << "addB " << i << std::endl;
        int sm = ca.prefixProduct(a[B[i]]);
        ans += (long long)B[i] * sm;
        ans += (long long)-B[i] * (ca.prefixProduct(a.size()) - sm);
        ans += sa.prefixProduct(a.size()) - 2LL * sa.prefixProduct(a[B[i]]);
        sb.operation(b.map(i), B[i]);
        cb.operation(b.map(i), 1);
    };
    auto delA = [&](int i) -> void {
        // std::cout << "delA " << i << std::endl;
        int sm = cb.prefixProduct(b[A[i]]); 
        ans -= (long long)A[i] * sm;
        ans -= (long long)-A[i] * (cb.prefixProduct(b.size()) - sm);
        ans -= sb.prefixProduct(b.size()) - 2LL * sb.prefixProduct(b[A[i]]);
        sa.operation(a.map(i), -A[i]);
        ca.operation(a.map(i), -1);
    };
    auto delB = [&](int i) -> void {
        // std::cout << "delB " << i << std::endl;
        int sm = ca.prefixProduct(a[B[i]]);
        ans -= (long long)B[i] * sm;
        ans -= (long long)-B[i] * (ca.prefixProduct(a.size()) - sm);
        ans -= sa.prefixProduct(a.size()) - 2LL * sa.prefixProduct(a[B[i]]);
        sb.operation(b.map(i), -B[i]);
        cb.operation(b.map(i), -1);
    };
    auto eval = [&](int) -> long long {
        // std::cout << "eval " << i << std::endl;
        return ans;
    };
    for (long long a : Mo(std::vector<query>(Q, Q + K), addA, addB, delA, delB, eval)) {
        std::cout << -a << '\n';
    }
}

int main() {
#ifdef ATCODER
    SetFastIO();
    std::cin >> N;
    for (int i = 0 ; i < N ; i++) std::cin >> A[i];
    for (int i = 0 ; i < N ; i++) std::cin >> B[i];
    std::cin >> K;
    for (int i = 0 ; i < K ; i++) {
        std::cin >> Q[i].l >> Q[i].r;
    }
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
