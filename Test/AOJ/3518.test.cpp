#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3518"
#include "../../Src/DataStructure/Wavelet/RectangleAggregation.hpp"
#include "../../Src/DataStructure/SparseTable/SparseTable.hpp"
using namespace zawa;
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int INF = (int)2e9;
struct MIN {
   using Element = int;
   static Element identity() {
       return INF;
   }
   static Element operation(Element L, Element R) {
       return min(L,R);
   }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> P(M);
    vector<int> A(M);
    for (int i = 0 ; i < M ; i++)
        cin >> P[i].first >> P[i].second >> A[i];
    RectangleAggregation RA{P};
    vector init(RA.height(),vector<int>(RA.size(),MIN::identity()));
    for (int i = 0 ; i < M ; i++)
        for (auto [x,y] : RA.point(P[i]))
            init[x][y] = A[i];
    vector<SparseTable<MIN>> spt(RA.height());
    for (int i = 0 ; i < (int)RA.height() ; i++)
        spt[i] = SparseTable<MIN>(move(init[i]));
    int Q;
    cin >> Q;
    while (Q--) {
        int l,r,d,u;
        cin >> l >> r >> d >> u;
        int ans = MIN::identity();
        for (auto [h,L,R] : RA.rectangle(l,d,r+1,u+1))
            ans = min(ans,spt[h].product(L,R));
        int cnt = RA.count(l,d,r+1,u+1);
        long long area = (long long)(r-l+1)*(u-d+1);
        // cout << area << "," << cnt << endl;
        assert(area >= cnt);
        if (area > cnt)
            ans = min(ans,0);
        cout << ans << '\n';
    }
}
