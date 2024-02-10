#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Tree/Sack.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"

#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace zawa;

int main() {
    SetFastIO();

    int n, q; std::cin >> n >> q;
    std::vector dat(n, std::vector<std::pair<int, long long>>{});
    for (int i{} ; i < n ; i++) {
        long long a; std::cin >> a;
        dat[i].emplace_back(0, a);
    }
    Sack sack(n);
    for (int i{1} ; i < n ; i++) {
        int p; std::cin >> p;
        sack.addEdge(p, i);
    }
    std::vector<long long> ans;
    ans.reserve(q);
    int id{};
    std::vector query(n, std::vector<std::pair<int, int>>{});
    query.reserve(q);
    for (int i{1} ; i <= q ; i++) {
        int t, v; std::cin >> t >> v;
        if (t == 0) {
            long long x; std::cin >> x;
            dat[v].emplace_back(i, x);
        }
        else if (t == 1) {
            ans.emplace_back(-1LL);
            query[v].emplace_back(i, id++);
        }
        else {
            assert(false);
        }
    }
    FenwickTree<AdditiveGroup<long long>> fen(q + 1);
    auto add{[&](int v) -> void {
        for (auto [time, x] : dat[v]) {
            fen.operation(time, x);
        }
    }};
    auto del{[&](int v) -> void {
        for (auto [time, x] : dat[v]) {
            fen.operation(time, -x);
        }
    }};
    auto answer{[&](int v) -> void {
        for (auto [time, i] : query[v]) {
            ans[i] = fen.prefixProduct(time + 1);
        }
    }};
    auto reset{[](){}};
    sack.execute(0, add, del, answer, reset);
    for (auto v : ans) {
        std::cout << v << '\n';
    }
}
