#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc288_c"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Components/ConnectedComponents.hpp"

#include <iostream>

using namespace zawa;

int main() {
    u32 N, M;
    std::cin >> N >> M;

    ConnectedComponents cc(N);
    for (u32 _{} ; _ < M ; _++) {
        u32 A, B;
        std::cin >> A >> B;
        cc.addEdge(A - 1, B - 1);
    }
    
    cc.build();

    u32 ans{};
    for (u32 i{} ; i < cc.size() ; i++) {
        ans += (i32)cc.m(i) - (i32)cc.n(i) + 1;
    }

    std::cout << ans << std::endl;
}
