#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc292_d"

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

    bool ans{ true };
    for (u32 i{} ; i < cc.size() ; i++) {
        ans &= cc.n(i) == cc.m(i);
    }

    std::cout << (ans ? "Yes" : "No") << std::endl;
}
