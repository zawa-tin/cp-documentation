#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * CF902-B Effects of Anti Pimples
 * https://codeforces.com/contest/1876/submission/227473226
 */

#include "../../Src/Number/ModInt.hpp"
#include "../../Src/Number/LinearSieve.hpp"

using mint = zawa::StaticModInt<unsigned, 998244353>;

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

const int N{ 100100 };

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i{} ; i < n ; i++) {
        std::cin >> a[i];
    }
    std::vector<std::pair<int, int>> max(n);
    for (int i{} ; i < n ; i++) {
        for (int j{i} ; j < n ; j += (i + 1)) {
            max[i].first = std::max(max[i].first, a[j]);
        }
        max[i].second = i + 1;
    }
    std::sort(max.begin(), max.end());
    std::reverse(max.begin(), max.end());

    std::vector<mint> p2(n + 1, mint{1});
    for (int i{} ; i < n ; i++) p2[i + 1] = p2[i] * mint{2};

    zawa::LinearSieve siv(N);

    std::set<int> ng;
    mint ans{};
    for (int i{} ; i < n ; i++) {
        auto [val, idx]{ max[i] };
        auto div{ siv.divisor(idx) };
        int must{ (int)div.size() };
        for (auto d : div) if (ng.find(d) != ng.end()) must--;
        int t{ n - (int)ng.size() };
        ans += (p2[t] - p2[t - must]) * mint{val};
        for (auto d : div) ng.emplace(d);
    }
    std::cout << ans << std::endl;
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World" << std::endl;
#endif
}
