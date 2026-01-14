#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
// #define PROBLEM "https://atcoder.jp/contests/arc196/tasks/arc196_a"

/*
 * AtCoder Regular Contest 196 (Div. 1) A - Adjacent Delete
 * http://atcoder.jp/contests/arc196/submissions/72451838
 */

#include "../../Src/DataStructure/Heap/PartitionedProducts.hpp"
using namespace zawa;

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct OP {
    using Element = long long;
    static Element identity() {
        return 0;
    }
    static void add(Element& L, int R) {
        L += R;
    }
    static void remove(Element& L, int R) {
        L -= R;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& a : A)
        cin >> a;
    auto eval = [&](auto& que) -> long long {
        assert(que.size() % 2 == 0);
        if (que.empty())
            return 0;
        else {
            que.adjustSmall(que.size() / 2);
            return que.bigProd() - que.smallProd();
        }
    };
    PartitionedProducts<OP, int> queL, queR{A};
    if (N % 2 == 0) 
        cout << eval(queR) << '\n'; 
    else {
        queR.erase(A[0]); 
        long long ans = 0;
        for (int i = 0 ; i < N ; i += 2) {
            ans = max(ans, eval(queL) + eval(queR));
            if (i + 2 < N) {
                queL.insert(A[i]);
                queL.insert(A[i + 1]);
                queR.erase(A[i + 1]);
                queR.erase(A[i + 2]);
            }
        }
        cout << ans << '\n';
    }
#else
    cout << "Hello World\n";
#endif
}
