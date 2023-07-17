#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc293_d"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Graph/Components/ConnectedComponents.hpp"

#include <iostream>

using namespace zawa;

int main() {
    u32 N, M;
    std::cin >> N >> M;

    ConnectedComponents cc(N);
    for (u32 _{} ; _ < M ; _++) {
        u32 A, C;
        u8 B, D;
        std::cin >> A >> B >> C >> D;
        cc.addEdge(A - 1, C - 1);
    }

    cc.build();

    u32 X{}, Y{};
    for (u32 i{} ; i < cc.size() ; i++) {
        if (cc.hasCycle(i)) {
            X++;
        }
        else {
            Y++;
        }
    }

    std::cout << X << ' ' << Y << std::endl;
}
