#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/CartesianTree.hpp"

#include <functional>
#include <iostream>

using namespace zawa;

int main() {
    SetFastIO(); 
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& a : A) std::cin >> a;
    CartesianTree<int> T{A, std::less{}};
    for (int i{} ; i < N ; i++) {
       usize p{T.parent(i)}; 
       std::cout << (p == decltype(T)::Invalid ? (usize)i : p) << (i + 1 == N ? '\n' : ' ');
    }
}
