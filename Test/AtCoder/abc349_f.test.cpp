#define PROBLEM "https://atcoder.jp/contests/abc349/tasks/abc349_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Number/PrimeFactorize.hpp"
#include "atcoder/modint"

#include <iostream>
#include <map>

using namespace zawa;
using mint = atcoder::modint998244353;

int main() {
    SetFastIO(); 

    int N;
    long long M;
    std::cin >> N >> M;
    std::map<long long, int> map;
    int NN{};
    for (int i{} ; i < N ; i++) {
        long long A;
        std::cin >> A;
        if (M % A == 0) {
            map[A]++;
        }
        else {
            NN++;
        }
    }
    N -= NN;
    if (M == 1) {
        std::cout << mint{mint::raw(2).pow(N) - 1}.val() << '\n';
        return 0;
    }
    std::vector A(map.begin(), map.end());
    auto F{PrimeFactorize((unsigned long long)M)};
    std::vector<int> B(A.size());
    for (int i{} ; i < (int)F.size() ; i++) {
        long long mult{1};
        for (int j{} ; j < (int)F[i].exponent() ; j++) {
            mult *= F[i].factor();
        }
        for (int j{} ; j < (int)A.size() ; j++) {
            if (A[j].first % mult == 0) {
                B[j] |= (1 << i);
            }
        }
    }
    std::vector<mint> P2(N + 1, mint::raw(1));
    for (int i{} ; i < N ; i++) {
        P2[i + 1] = P2[i] * mint::raw(2);
    }
    mint ans{P2[N] - 1};
    for (int bit{1} ; bit < (1 << (int)F.size()) ; bit++) {
        int num{};
        for (int i{} ; i < (int)A.size() ; i++) {
            if (B[i] & bit) {
                continue;
            }
            num += A[i].second;
        }
        ans -= (__builtin_popcount(bit) % 2 ? +1 : -1) * (P2[num] - 1);
    }
    std::cout << ans.val() << '\n';
}
