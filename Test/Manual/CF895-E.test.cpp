#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * CF895 (Div.3) - E Data Structures Fan
 * https://codeforces.com/contest/1872/submission/226679638
 */

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <iostream>

struct vDat {
    int one{};
    int zero{};
    vDat() {}
    vDat(int o, int z) : one{o}, zero{z} {}
    vDat flip() const { return vDat{ zero, one }; }
};

struct vM {
    using Element = vDat;
    static vDat identity() {
        return vDat{};
    }
    static vDat operation(const vDat& a, const vDat& b) {
        return vDat{ 
            a.one ^ b.one, a.zero ^ b.zero
        };
    }
};

struct oM {
    using Element = bool;
    static bool identity() {
        return false;
    }
    static bool operation(bool a, bool b) {
        return a ^ b;
    }
};

struct Structure {
    using ValueMonoid = vM;
    using OperatorMonoid = oM;
    static vDat mapping(const vDat& a, bool b) {
        return (b ? a.flip() : a);
    }
};

#include <vector>
#include <cassert>

void testCase() {
    using namespace zawa;
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<vDat> init(n);
    for (int i{} ; i < n ; i++) {
        char c; std::cin >> c;
        if (c == '0') {
            init[i].zero = a[i];
        }
        else if (c == '1') {
            init[i].one = a[i];
        }
        else {
            assert(false);
        }
    }
    LazySegmentTree<Structure> seg(init);
    std::vector<int> anses;
    int q; std::cin >> q;
    for (int _{} ; _ < q ; _++) {
        int t; std::cin >> t;
        if (t == 1) {
            int l, r; std::cin >> l >> r;
            l--;
            seg.operation(l, r, true);
        }
        else if (t == 2) {
            int v; std::cin >> v;
            vDat ans{ seg.product(0, n) };
            anses.emplace_back((v ? ans.one : ans.zero));
        }
    }
    int s{ (int)anses.size() };
    for (int i{} ; i < s ; i++) {
        std::cout << anses[i] << (i + 1 == s ? '\n' : ' ');
    }
}

void solve() {
    using namespace zawa;
    SetFastIO();
    int t; std::cin >> t;
    for (int _{} ; _ < t ; _++) {
        testCase();
    }
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World" << std::endl;
#endif
}
