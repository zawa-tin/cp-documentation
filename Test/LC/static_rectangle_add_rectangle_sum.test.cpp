#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "../../Src/DataStructure/RectangleSum/RectangleSumOfRectangles.hpp"
#include "atcoder/modint"
using mint=atcoder::modint998244353;
#include <iostream>
using namespace std;
struct RectAdd {
    using P=int;
    using W=mint;
    int l,d,r,u;
    mint w;
};
struct Rect {
    using P=int;
    int l,d,r,u;
};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int N,Q;
    cin >> N >> Q;
    vector<RectAdd> rs(N);
    for (auto& r : rs) {
        int w;
        cin >> r.l >> r.d >> r.r >> r.u >> w;
        r.w=mint::raw(w);
    }
    vector<Rect> qs(Q);
    for (auto& r : qs) 
        cin >> r.l >> r.d >> r.r >> r.u;
    for (mint ans : zawa::RectangleSumOfRectangles(rs,qs))
        cout << ans.val() << '\n';
}
