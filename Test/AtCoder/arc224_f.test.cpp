// #define PROBLEM "https://atcoder.jp/contests/arc224/tasks/arc224_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Regular Contest --224 F - AND/OR
 * https://atcoder.jp/contests/arc224/submissions/80011933
 */
#include "../../Src/Combinatorics/BinomialCoefficientPrefixSums.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using namespace zawa;
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N,K;
        cin >> N >> K;
        vector<long long> A(N);
        for (auto& x : A)
            cin >> x;
        ranges::reverse(A);
        long long M=0;
        for (int i = 0 ; i < K ; i++)
            M|=A[i];
        int use=0;
        long long cur=0;
        vector<pair<int,int>> query;
        for (int i = 0 ; i < N ; i++) {
            if (((M^cur)&A[i])==(M^cur))
                query.push_back({N-i-1,K-use-1});
            else {
                cur|=A[i];
                cur&=M;
                use++;
            }
        }
        mint ans=0;
        if (cur==M)
            ans++;
        for (auto val : BinomialCoefficientPrefixSums<mint>(query))
            ans+=val;
        cout << ans.val() << '\n';
    }
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
