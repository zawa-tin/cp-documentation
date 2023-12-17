#define PROBLEM "https://atcoder.jp/contests/abc205/tasks/abc205_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Graph/Flow/Dinic.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    SetFastIO();
    int h, w, n; std::cin >> h >> w >> n;
    Dinic<int> mf(h + n + n + w + 2);
    int s{h + n + n + w}, t{s + 1};
    for (int i{} ; i < h ; i++) {
        mf.addEdge(s, i, 1);
    }
    for (int i{} ; i < n ; i++) {
        mf.addEdge(h + i, h + n + i, 1);
    }
    for (int i{} ; i < w ; i++) {
        mf.addEdge(h + n + n + i, t, 1);
    }
    for (int i{} ; i < n ; i++) {
        int a, b, c, d; std::cin >> a >> b >> c >> d;
        a--; b--;
        for (int j{a} ; j < c ; j++) {
            mf.addEdge(j, h + i, 1);
        }
        for (int j{b} ; j < d ; j++) {
            mf.addEdge(h + n + i, h + n + n + j, 1);
        }
    }
    int ans{mf.flow(s, t)};
    std::cout << ans << '\n';
}
