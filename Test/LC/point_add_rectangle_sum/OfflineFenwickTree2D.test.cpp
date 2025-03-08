#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../Src/Template/IOSetting.hpp"
#include "../../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../../Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp"

using namespace zawa;
int N, Q, X[100010], Y[100010], W[100010], T[100010], A[100010], B[100010], C[100010], D[100010];
int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    for (int i = 0 ; i < N ; i++) std::cin >> X[i] >> Y[i] >> W[i];
    for (int i = 0 ; i < Q ; i++) {
        std::cin >> T[i];
        if (T[i] == 0) std::cin >> A[i] >> B[i] >> C[i];
        else if (T[i] == 1) std::cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    OfflineFenwickTree2D<int, AdditiveGroup<long long>> fen{};
    for (int i = 0 ; i < N ; i++) fen.operation(X[i], Y[i]);
    for (int i = 0 ; i < Q ; i++) if (T[i] == 0) fen.operation(A[i], B[i]);
    auto exe = fen.build();
    for (int i = 0 ; i < N ; i++) exe.operation(X[i], Y[i], W[i]);
    for (int i = 0 ; i < Q ; i++) {
        if (T[i] == 0) exe.operation(A[i], B[i], C[i]);
        else std::cout << exe.product(A[i], B[i], C[i], D[i]) << '\n';
    }
}
