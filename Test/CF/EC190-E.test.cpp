#include "../../Src/DataStructure/Wavelet/RectangleAggregation.hpp"
#include "../../Src/DataStructure/RMQ/StaticRMQ.hpp"
/*
 * Educational Codeforces Round 190 E - Minimum Influence
 * https://codeforces.com/contest/2230/submission/375904806
 */
namespace zawa {}
using namespace zawa;
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0 ; i < ssize(v) ; i++)
        os << v[i] << (i + 1 == ssize(v) ? "" : " ");
    return os;
}
const int INF = (int)1e7;
struct MIN {
    using Element = int;
    static Element identity() {
        return INF;
    }
    static Element operation(Element l,Element r) {
        return min(l,r);
    }
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    const int MAX = 2000100;
    int N;
    cin >> N;
    vector<int> P(N),C(N);
    for (auto& x : P)
        cin >> x;
    for (auto& x : C)
        cin >> x;
    int M;
    cin >> M;
    vector<int> TP(M),TC(M),D(M);
    for (auto& x : TP)
        cin >> x;
    for (auto& x : TC)
        cin >> x;
    for (auto& x : D)
        cin >> x;
    vector<int> CPREF(MAX+1,INF),CSUF(MAX+1,INF),PPREF(MAX+1,INF),PSUF(MAX+1,INF);
    for (int i = 0 ; i < N ; i++) {
        CPREF[P[i]+1] = min(CPREF[P[i]+1],C[i]);
        PPREF[C[i]+1] = min(PPREF[C[i]+1],P[i]);
        CSUF[P[i]] = min(CSUF[P[i]],C[i]);
        PSUF[C[i]] = min(PSUF[C[i]],P[i]);
    }
    for (int i = 0 ; i < MAX ; i++) {
        CPREF[i+1] = min(CPREF[i+1],CPREF[i]);
        PPREF[i+1] = min(PPREF[i+1],PPREF[i]);
    }
    for (int i = MAX - 1 ; i >= 0 ; i--) {
        PSUF[i] = min(PSUF[i+1],PSUF[i]);
        CSUF[i] = min(CSUF[i+1],CSUF[i]);
    }
    vector<pair<int,int>> point(N);
    for (int i = 0 ; i < N ; i++)
        point[i] = {P[i],C[i]};
    RectangleAggregation RA{point};
    vector init(RA.height(),vector<int>(RA.width(),INF));
    for (int i = 0 ; i < N ; i++)
        for (auto [x,y] : RA.point(i))
            init[x][y] = min(init[x][y],P[i]+C[i]);
    vector<StaticRMQ<MIN>> seg(RA.height());
    for (int i = 0 ; i < (int)RA.height() ; i++)
        seg[i] = StaticRMQ<MIN>(move(init[i]));
    vector<int> anses(M,INF);
    for (int i = 0 ; i < M ; i++) {
        auto evalC = [&](int c) {
            if (c >= INF)
                return INF;
            if (c < TC[i])
                return 0;
            if (c < TC[i]+D[i])
                return c;
            return TC[i]+D[i];
        };
        auto evalP = [&](int p) {
            if (p >= INF)
                return INF;
            if (p < TP[i])
                return 0;
            if (p < TP[i]+D[i])
                return p;
            return TP[i]+D[i];
        };
        int& ans = anses[i];
        ans = min(ans,evalC(CPREF[TP[i]]));
        ans = min(ans,evalP(PPREF[TC[i]]));
        ans = min(ans,TP[i]+D[i]+evalC(CSUF[TP[i]+D[i]]));
        ans = min(ans,TC[i]+D[i]+evalP(PSUF[TC[i]+D[i]]));
        for (auto [h,l,r] : RA.rectangle(TP[i],TC[i],TP[i]+D[i],TC[i]+D[i]))
            ans = min(ans,seg[h].product(l,r));
    }
    for (int ans : anses)
        cout << ans << '\n';
}
