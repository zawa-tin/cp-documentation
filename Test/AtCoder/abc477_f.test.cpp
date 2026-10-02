// #define PROBLEM "https://atcoder.jp/contests/abc477/tasks/abc477_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * AtCoder Beginner Contest 477 F - Count Cells in a Window
 * https://atcoder.jp/contests/abc477/submissions/79673231
 */
#include "../../Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp"
#include <iostream>
#include <vector>
using namespace std;
struct RectAdd {
    using P=int;
    using W=long long;
    P l,d,r,u;
    W w;
};
struct Rect {
    using P=int;
    P l,d,r,u;
};
int main() {
#ifdef ATCODER
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<RectAdd> rs(N);
    for (int i = 0 ; i < N ; i++) {
        int l,r;
        cin >> l >> r;
        l--;
        rs[i]={i,l,i+1,r,1};
    }
    vector<Rect> qs(Q);
    for (auto& q : qs) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; c--;
        q={a,c,b,d};
    }
    for (auto ans : zawa::RectangleSumOfRectangles(rs,qs))
        cout << ans << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
