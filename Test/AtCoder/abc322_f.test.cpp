// #define PROBLEM "https://atcoder.jp/contests/abc322/tasks/abc322_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * https://atcoder.jp/contests/abc322/submissions/67058865
 * AtCoder Beginner Contest 322 F - Vacation Query
 */

#include "../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp"
#include "../../Src/Template/IOSetting.hpp"

#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using pii = std::pair<int, int>;

void chmax(int& a, int b) {
    a = std::max(a, b);
}

struct vD {
    int max[2]{ 0, 0 };
    pii left{}, right{};
    bool allSame{true};

    vD() = default;

    vD flip() const {
        vD res{};
        res.max[0] = max[1];
        res.max[1] = max[0];
        res.left = pii{left.first ^ 1, left.second};
        res.right = pii{right.first ^ 1, right.second};
        res.allSame = allSame;
        return res;
    }
};

struct vM {
    using Element = vD;
    static vD identity() {
        return vD{};
    }
    static vD operation(const vD& L, const vD& R) {
        vD res{};

        res.max[0] = std::max(L.max[0], R.max[0]);
        res.max[1] = std::max(L.max[1], R.max[1]);

        res.left.first = L.left.first;
        res.left.second = L.left.second;
        if (L.allSame and L.left.first == R.left.first) res.left.second += R.left.second;

        res.right.first = R.right.first;
        res.right.second = R.right.second;
        if (R.allSame and R.right.first == L.right.first) res.right.second += L.right.second;

        res.allSame = L.allSame and R.allSame and L.left.first == R.right.first;

        if (L.right.first == R.left.first) chmax(res.max[L.right.first], L.right.second + R.left.second);
        chmax(res.max[res.left.first], res.left.second);
        chmax(res.max[res.right.first], res.right.second);

        return res;
    }
};

struct oM {
    using Element = bool;
    static bool identity() {
        return false;
    }
    static bool operation(bool l, bool r) {
        return l ^ r;
    }
};

struct Structure {
    using ValueMonoid = vM;
    using OperatorMonoid = oM;
    static vD mapping(const vD& a, bool b) {
        return (b ? a.flip() : a);
    }
};

int main() {
#ifdef ATCODER
    using namespace zawa;
    SetFastIO();

    int n, q; std::cin >> n >> q;
    std::vector<vD> init(n);
    for (int i{} ; i < n ; i++) {
        char c; std::cin >> c;
        if (c == '0') {
            init[i].left = pii{0, 1};
            init[i].right = pii{0, 1};
            init[i].max[0] = 1;
            init[i].max[1] = 0;
            init[i].allSame = true;
        }
        else if (c == '1') {
            init[i].left = pii{1, 1};
            init[i].right = pii{1, 1};
            init[i].max[0] = 0;
            init[i].max[1] = 1;
            init[i].allSame = true;
        }
        else {
            assert(false);
        }
    }

    LazySegmentTree<Structure> seg(init);
    for (int _{} ; _ < q ; _++) {
        int c, l, r; std::cin >> c >> l >> r;
        l--;
        if (c == 1) {
            seg.operation(l, r, true);
        }
        else if (c == 2) {
            auto prod{seg.product(l, r)};
            int ans{prod.max[1]};
            std::cout << ans << '\n';
        }
        else {
            assert(false);
        }
    }
#else
    std::cout << "Hello World\n";
#endif
}
