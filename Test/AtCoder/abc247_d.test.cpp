#define PROBLEM "https://atcoder.jp/contests/abc247/tasks/abc247_d"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Sequence/RunLengthEncoding.hpp"

#include <iostream>

using namespace zawa;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    RunLengthEncoding<u32, u64> rle;
   
    usize Q; std::cin >> Q;
    for (u32 _{} ; _ < Q ; _++) {
        u32 t; std::cin >> t;
        if (t == 1) {
            u32 x, c; std::cin >> x >> c;
            rle.pushBack(x, c);
        }
        else if (t == 2) {
            u32 c; std::cin >> c;
            u64 ans{};
            for (const auto& data : rle.popFront(c)) {
                ans += (u64)data.value() * data.number();
            }
            std::cout << ans << std::endl;
        }
        else {
            assert(!"input failed");
        }
    }
}
