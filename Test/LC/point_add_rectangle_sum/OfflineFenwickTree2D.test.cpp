#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../../Src/Template/IOSetting.hpp"
#include "../../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../../Src/DataStructure/FenwickTree/OfflineFenwickTree2D.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    int N, Q;
    std::cin >> N >> Q;
    OfflineFenwickTree2D<int, AdditiveGroup<long long>> fen{};
    while (N--) {
        int x, y, w;
        std::cin >> x >> y >> w;
        fen.operation(x, y, w);
    }
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x, y, w;
            std::cin >> x >> y >> w;
            fen.operation(x, y, w);
        }
        else {
            int l, d, r, u;
            std::cin >> l >> d >> r >> u;
            fen.product(l, d, r, u);
        }
    }
    for (auto [ans, _] : fen.execute()) {
        std::cout << ans << '\n';
    }
}
