#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2957"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Number/EnumerateQuotients.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

const usize sz{200010};

int main() {
    usize N, M; std::cin >> N >> M;
    u64 ans{};

    std::vector<i64> imos(sz);
    for (u32 i{} ; i < N ; i++) {
        u32 A; std::cin >> A;
        ans += (u64)M * A;

        EnumerateQuotients eq(A);
        for (u32 j{} ; j < eq.size() ; j++) {
            imos[eq.l(j)] += eq.quotient(j);
            imos[eq.r(j)] -= eq.quotient(j);
        }
    } 

    for (u32 i{} ; i + 1 < sz ; i++) {
        imos[i + 1] += imos[i];
    }

    for (u32 i{} ; i < M ; i++) {
        u32 B; std::cin >> B;
        ans -= imos[B] * B;
    }

    std::cout << ans << std::endl;
}
