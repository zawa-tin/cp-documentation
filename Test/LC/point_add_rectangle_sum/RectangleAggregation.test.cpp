#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../../../Src/DataStructure/Wavelet/RectangleAggregation.hpp"
#include "../../../Src/Algebra/Group/AdditiveGroup.hpp"
#include "../../../Src/DataStructure/FenwickTree/FenwickTree.hpp"
using namespace zawa;
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<pair<int,int>> P(N);
    vector<int> W(N);
    for (int i = 0 ; i < N ; i++)
        cin >> P[i].first >> P[i].second >> W[i];
    vector<int> T(Q),A(Q),B(Q),C(Q),D(Q);
    for (int i = 0 ; i < Q ; i++) {
        cin >> T[i];
        if (T[i] == 0) {
            cin >> A[i] >> B[i] >> C[i];
            P.push_back({A[i],B[i]});
        }
        else if (T[i] == 1) 
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        else
            assert(0);
    }
    RectangleAggregation RA{P};
    vector<FenwickTree<AdditiveGroup<long long>>> fen(RA.height());
    for (int i = 0 ; i < (int)RA.height() ; i++)
        fen[i] = FenwickTree<AdditiveGroup<long long>>(RA.width());
    for (int i = 0 ; i < N ; i++)
        for (auto [x,y] : RA.point(i))
            fen[x].operation(y,W[i]);
    for (int i = 0 ; i < Q ; i++) {
        if (T[i] == 0) 
            for (auto [x,y] : RA.point({A[i],B[i]}))
                fen[x].operation(y,C[i]);
        else if (T[i] == 1) {
            long long ans = 0;
            for (auto [h,l,r] : RA.rectangle(A[i],B[i],C[i],D[i]))
                ans += fen[h].product(l,r);
            cout << ans << '\n';
        }
        else
            assert(0);
    }
}
