#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Sequence/CompressedSequence.hpp"
#include "../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
#include "../../Src/Algebra/Group/AdditiveGroup.hpp"

#include <cassert>
#include <iostream>
#include <vector>

/*
 * ABC287-G Balance Update Query
 * https://atcoder.jp/contests/abc287/submissions/62949373
 */

void solve() {
    using namespace zawa;
    SetFastIO();
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i{} ; i < n ; i++) {
        std::cin >> a[i] >> b[i];
    }
    int q; std::cin >> q;
    std::vector<int> t(q), x(q), y(q);
    for (int i{} ; i < q ; i++) {
        std::cin >> t[i] >> x[i];
        if (t[i] == 1 or t[i] == 2) {
            x[i]--;
            std::cin >> y[i];
        }
    }
    std::vector<int> app;
    app.reserve(n + q);
    for (int i{} ; i < n ; i++) app.push_back(a[i]);
    for (int i{} ; i < q ; i++) if (t[i] == 1) app.push_back(y[i]);

    CompressedSequence<int> comp{ app.begin(), app.end() };
    usize m{comp.size()};
    FenwickTree<AdditiveGroup<int>> ft1(m);
    FenwickTree<AdditiveGroup<long long>> ft2(m);

    for (int i{} ; i < n ; i++) {
        ft1.operation(comp[a[i]], b[i]);
        ft2.operation(comp[a[i]], (long long)a[i] * (long long)b[i]);
    }

    auto calcByMaxRight{[&](int query) -> long long {
        if (query > ft1.prefixProduct(m)) return -1LL;
        query = ft1.prefixProduct(m) - query;
        long long res{ft2.prefixProduct(m)};
        auto it{ft1.maxRight(0, [&](int v) -> bool { return v <= query; })};
        query -= ft1.prefixProduct(it);
        res -= ft2.prefixProduct(it);
        if (it < m) {
            res -= (long long)comp.inverse(it) * query;
        }
        return res;
    }};

    auto calcByMinLeft{[&](int query) -> long long {
        if (query > ft1.prefixProduct(m)) return -1LL;
        auto it{ft1.minLeft(m, [&](int v) -> bool { return v <= query; })};
        query -= (it + 1 == m ? 0 : ft1.product(it + 1, m));
        long long res{it + 1 == m ? 0LL : ft2.product(it + 1, m)};
        res += (long long)comp.inverse(it) * query;
        return res;
    }};

    for (int i{} ; i < q ; i++) {
        if (t[i] == 1) {
            int v{x[i]};
            ft1.operation(comp.at(a[v]), -b[v]);
            ft2.operation(comp[a[v]], (long long)-a[v] * (long long)b[v]);
            a[v] = y[i];
            ft1.operation(comp[a[v]], b[v]);
            ft2.operation(comp[a[v]], (long long)a[v] * (long long)b[v]);
        }
        else if (t[i] == 2) {
            int v{x[i]};
            ft1.operation(comp[a[v]], -b[v]);
            ft2.operation(comp[a[v]], (long long)-a[v] * (long long)b[v]);
            b[v] = y[i];
            ft1.operation(comp[a[v]], b[v]);
            ft2.operation(comp[a[v]], (long long)a[v] * (long long)b[v]);
        }
        else if (t[i] == 3) {
            long long l{calcByMinLeft(x[i])}, r{calcByMaxRight(x[i])};
            assert(l == r);
            std::cout << r << std::endl;
        }
        else {
            assert(false);
        }
    }
}

int main() {
#ifdef ATCODER
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
