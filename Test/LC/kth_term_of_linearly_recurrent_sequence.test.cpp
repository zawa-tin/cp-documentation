#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../Src/FPS/KthTerm.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "./atcoder/convolution"

using mint = atcoder::modint998244353;

using namespace zawa;

int main() {
    SetFastIO(); 
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d), c(d);
    for (auto& v : a) {
        int i;
        std::cin >> i;
        v = i;
    }
    for (auto& v : c) {
        int i;
        std::cin >> i;
        v = i;
    }
    std::cout << KthTerm(k, a, c, [](const auto& L, const auto& R) { return atcoder::convolution(L, R); }).val();
}
