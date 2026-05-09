#define PROBLEM "https://atcoder.jp/contests/abc457/tasks/abc457_f"

/*
 * AtCoder Beginner Contest 457 F - Second Gap
 * https://atcoder.jp/contests/abc457/submissions/75681374
 */

#include "../../Src/DataStructure/SegmentTree/DualSegmentTree.hpp"
using namespace zawa;

#include "atcoder/modint"
using mint = atcoder::modint998244353;

#include <iostream>
#include <vector>
#include <optional>
using namespace std;
struct M {
    using Element = pair<optional<mint>,mint>;
    static Element identity() {
        return {nullopt,1};
    }
    static Element operation(Element L, Element R) {
        if (R.first)
            return R;
        L.second *= R.second;
        return L;
    }
    static mint action(Element o,mint x) {
        if (o.first)
            return o.first.value() * o.second;
        else
            return x * o.second;
    }
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> D(N-1);
    for (auto& x : D)
        cin >> x;
    DualSegmentTree<M,mint> dp(N);
    dp.assign(N-2,mint::raw(1));
    dp.assign(N-1,mint::raw(1));
    int cnt = 2;
    int pr = D[N-2];
    for (int i = N - 3 ; i >= 0 ; i--) {
        mint val = dp[i+D[i]];
        if (pr == D[i])
            dp.operation(i+1,N,{nullopt,cnt-1});
        else
            dp.operation(i+1,N,{0,1});
        dp.assign(i,val);
        mint x = val + dp[i+D[i]];
        dp.assign(i+D[i],x);
        pr = D[i];
        cnt++;
    }
    mint ans = 0;
    for (auto i : dp.container())
        ans += i;
    cout << ans.val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
