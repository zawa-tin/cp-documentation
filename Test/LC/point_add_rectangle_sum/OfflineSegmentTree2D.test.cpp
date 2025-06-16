#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../../Src/DataStructure/SegmentTree/OfflineSegmentTree2D.hpp"


#include <iostream>

using namespace zawa;

int N, Q, X[100010], Y[100010], W[100010], T[100010], A[100010], B[100010], C[100010], D[100010];
int main() {
    std::cin >> N >> Q;
    for (int i = 0 ; i < N ; i++) std::cin >> X[i] >> Y[i] >> W[i];
    for (int i = 0 ; i < Q ; i++) {
        std::cin >> T[i];
        if (T[i] == 0) std::cin >> A[i] >> B[i] >> C[i];
        else if (T[i] == 1) std::cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    OfflineSegmentTree2D<int, AdditiveGroup<long long>> seg{};
    for (int i = 0 ; i < N ; i++) seg.operation(X[i], Y[i]);
    for (int i = 0 ; i < Q ; i++) if (T[i] == 0) seg.operation(A[i], B[i]);
    auto exe = seg.build();
    for (int i = 0 ; i < N ; i++) exe.operation(X[i], Y[i], W[i]);
    for (int i = 0 ; i < Q ; i++) {
        if (T[i] == 0) exe.operation(A[i], B[i], C[i]);
        else std::cout << exe.product(A[i], B[i], C[i], D[i]) << '\n';
    }
}
