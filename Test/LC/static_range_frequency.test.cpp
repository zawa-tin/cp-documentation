#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/DataStructure/Mo/Mo.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"

#include <iostream>
#include <vector>

using namespace zawa;

int N, Q, X[500050];
struct query {
    usize l, r;
};
int main() {
    SetFastIO();

    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int& a : A) std::cin >> a;
    CompressedSequence comp{A};
    std::vector<query> q(Q);
    for (int i{} ; auto& [l, r] : q) {
        std::cin >> l >> r >> X[i];
        i++;
    }
    std::vector<int> cnt(comp.size());
    auto add{[&](int i) -> void {
        cnt[comp.map(i)]++;
    }};
    auto del{[&](int i) -> void {
        cnt[comp.map(i)]--;
    }};
    auto eval{[&](int i) -> int {
        auto j{comp[X[i]]};
        if (j == comp.size() or comp.inverse(j) != X[i]) return 0;
        else return cnt[j];
    }};
    for (int ans : Mo(q, add, add, del, del, eval)) std::cout << ans << '\n';
}
