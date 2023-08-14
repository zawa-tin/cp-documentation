#define PROBLEM "https://atcoder.jp/contests/agc047/tasks/agc047_a"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Utility/FloatingMarkerShift.hpp"

using namespace zawa;

#include <iostream>
#include <vector>
#include <string>

int main() {
    usize N; std::cin >> N;

    constexpr usize lg2{45}, lg5{20};
    std::vector pos(lg2, std::vector<u32>(lg5));
    
    u64 ans{};
    for (u32 _{} ; _ < N ; _++) {
        std::string s; std::cin >> s;
        i64 value{FloatingMarkerShift(s, 9)};
        u32 d2{}, d5{};
        while (value % 2 == 0) {
            d2++;
            value /= 2;
        }
        while (value % 5 == 0) {
            d5++;
            value /= 5;
        }

        for (u32 i{} ; i < lg2 ; i++) for (u32 j{} ; j < lg5 ; j++) {
            if (d2 + i >= 18 and d5 + j >= 18) {
                ans += pos[i][j];
            }
        }

        pos[d2][d5]++;
    }

    std::cout << ans << std::endl;

}
