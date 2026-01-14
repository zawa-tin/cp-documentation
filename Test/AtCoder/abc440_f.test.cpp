// #define PROBLEM "https://atcoder.jp/contests/abc440/tasks/abc440_f"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

/*
 * AtCoder Beginner Contest 440 F - Egoism
 * https://atcoder.jp/contests/abc440/submissions/72451553
 */

#include "../../Src/DataStructure/Heap/PartitionedProducts.hpp"
using namespace zawa;

#include <iostream>
using namespace std;
struct OP {
    using Element = pair<long long, int>;
    static Element identity() {
        return {0, 0};
    }
    static void add(Element& e, const Element& v) {
        e.first += v.first;
        e.second += v.second == -1;
    }
    static void remove(Element& e, const Element& v) {
        e.first -= v.first;
        e.second -= v.second == -1;
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N);
    long long sum = 0;
    int cnt = 0;
    for (int i = 0 ; i < N ; i++) {
        cin >> A[i] >> B[i];
        sum += A[i];
        cnt += B[i] == 2;
    }
    auto make = [&](int i) -> pair<int, int> {
        assert(0 <= i and i < N);
        return {A[i], B[i] == 2 ? -1 : i};
    };
    PartitionedProducts<OP, pair<int, int>> que{[&]() {
            vector<pair<int, int>> res(N);
            for (int i = 0 ; i < N ; i++)
                res[i] = make(i);
            return res;
        }()};
    auto eval = [&]() -> long long {
        que.adjustBig(cnt);
        if (cnt == 0)
            return sum;
        auto [a, b] = que.bigProd();
        long long res = sum + a;
        if (b == cnt) {
            res -= que.bigTop().first;
            if (cnt < N)
                res += que.smallTop().first;
        }
        return res;
    };
    while (Q--) {
        int idx, X, Y;
        cin >> idx >> X >> Y;
        idx--;
        que.erase(make(idx));
        sum -= A[idx];
        cnt -= B[idx] == 2;
        A[idx] = X;
        B[idx] = Y;
        sum += A[idx];
        cnt += B[idx] == 2;
        que.insert(make(idx));
        cout << eval() << '\n';
    }
}
