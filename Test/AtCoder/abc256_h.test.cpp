// #define PROBLEM "https://atcoder.jp/contests/abc256/tasks/abc256_h"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 256 Ex - I like Query Problem
 * https://atcoder.jp/contests/abc256/submissions/67095836
 */

#include "../../Src/DataStructure/SegmentTree/SegmentTreeBeats.hpp"
using namespace zawa;

#include <cassert>
#include <iostream>
#include <vector>

struct VD {
    long long sum = 0;
    int val = 0, cnt = 0;
    bool same = true;
};
struct VM {
    using Element = VD;
    static VD identity() {
        return VD{};
    }
    static VD operation(const VD& L, const VD& R) {
        if (L.cnt == 0) return R;
        if (R.cnt == 0) return L;
        long long sum = L.sum + R.sum;
        int val = L.val, cnt = L.cnt + R.cnt;
        bool same = L.same and R.same and L.val == R.val;
        return {sum,val,cnt,same};
    }
};
using OD = std::pair<int, long long>;
std::ostream& operator<<(std::ostream& os, const VD& v) {
    os << '[' << v.sum << ',' << v.cnt << ',' << v.val << ',' << v.same << ']';
    return os;
}
std::ostream& operator<<(std::ostream& os, const OD& v) {
    os << '(' << v.first << ',' << v.second << ')';
    return os;
}
struct OM {
    using Element = OD;
    static Element identity() {
        return {-1, -1};
    }
    // division -> 0, set -> 1
    static Element operation(const Element L, const Element R) {
        if (L.first == -1) return R;
        else if (R.first == -1) return L;
        else if (R.first == 1) return R; // Rが代入
        else if (L.first == 0) return {0,L.second*R.second};
        else return {1,L.second / R.second};
    }
};
struct ACT {
    using ValueMonoid = VM;
    using OperatorMonoid = OM;
    static VM::Element mapping(VM::Element v, OM::Element o) {
        if (o.first == 0) {
            v.val /= o.second;
            v.sum = (long long)v.val * v.cnt;
        }
        if (o.first == 1) {
            v.val = o.second;
            v.sum = (long long)v.val * v.cnt;
        }
        return v;
    }
};
bool division_break_condition(const VD& v, const OD&) {
    return v.same and v.val == 0;
}
bool set_break_condition(const VD&, const OD&) {
    return false;
}
bool tag_condition(const VD& v, const OD&) {
    return v.same;
}

void solve() {
    int N, Q;
    std::cin >> N >> Q; 
    std::vector<VD> init(N);
    for (int i = 0 ; i < N ; i++) {
        int A;
        std::cin >> A;
        init[i] = {A,A,1,true};
    }
    SegmentTreeBeats<ACT> seg{init};
    while (Q--) {
        int T;
        std::cin >> T;
        if (T == 1) {
            int L, R, x;
            std::cin >> L >> R >> x;
            L--;
            seg.operation(L, R, {0,x}, division_break_condition, tag_condition);
        }
        else if (T == 2) {
            int L, R, x;
            std::cin >> L >> R >> x;
            L--;
            seg.operation(L, R, {1,x}, set_break_condition, tag_condition);
        }
        else if (T == 3) {
            int L, R;
            std::cin >> L >> R;
            L--;
            std::cout << seg.product(L, R).sum << '\n';
        }
        else assert(false);
    }
}

int main() {
#ifdef ATCODER
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
#else
    std::cout << "Hello World\n";
#endif
}
