#define PROBLEM "https://atcoder.jp/contests/abc311/tasks/abc311_b"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Sequence/RunLengthEncoding.hpp"
#include "../../Src/Template/Chmax.hpp"

#include <iostream>
#include <string>

using namespace zawa;

int main() {
    usize N; std::cin >> N;
    u32 D; std::cin >> D;
    std::vector<bool> A(D, true);
    for (u32 _{} ; _ < N ; _++) {
        std::string s; std::cin >> s;
        for (u32 i{} ; i < D ; i++) {
            A[i] = (A[i] and s[i] == 'o');
        }
    }
    RunLengthEncoding rle(A);
    u32 ans{};
    for (auto r : rle) if (r.value()) Chmax(ans, r.number());
    std::cout << ans << std::endl;
}
