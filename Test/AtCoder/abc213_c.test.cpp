#define PROBLEM "https://atcoder.jp/contests/abc213/tasks/abc213_c"

#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/Template/TypeAlias.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

i32 main() {
    usize H, W, N;
    std::cin >> H >> W >> N; 
    std::vector<u32> A(N), B(N);
    for (u32 i = 0 ; i < N ; i++) {
        std::cin >> A[i] >> B[i];
    }

    CompressedSequence compY(A);
    CompressedSequence<u32> compX(B.begin(), B.end());
    for (u32 i = 0 ; i < N ; i++) {
        std::cout << compY.map(i) + 1 << ' ' << compX.map(i) + 1 << std::endl;
    }
}
