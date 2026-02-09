// #define PROBLEM "https://atcoder.jp/contests/awc0001/tasks/awc0001_e"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Weekday Contest 0001 Beta E
 * https://atcoder.jp/contests/awc0001/submissions/73160986
 */

#include "../../Src/Sequence/EnumerateStaticLengthProduct.hpp"
using namespace zawa;
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct M {
   using Element = pair<int,int>;
   static Element operation(Element l, Element r) {
       return {max(l.first,r.first),min(l.second,r.second)};
   }
};
int main() {
#ifdef ATCODER
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> A(N);
    for (auto& x : A) {
        cin >> x.first;
        x.second = x.first;
    }
    int ans = 0;
    for (auto [a, b] : EnumerateStaticLengthProduct<M>(A, K))
        ans = max(ans, a - b);
    cout << ans << '\n';
#else
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
#endif
}
