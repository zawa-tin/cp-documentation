// #define PROBLEM "https://atcoder.jp/contests/abc448/tasks/abc448_f"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

/*
 * AtCoder Beginner Contest 448 - F Authentic Traveling Salesman Problem
 * https://atcoder.jp/contests/abc448/submissions/74165490
 */

#include "../../Src/Utility/Mo.hpp"
#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <ranges>
#include <utility>
using namespace std;
int main() {
#ifdef ATCODER
    int N;
    cin >> N;
    vector<pair<int,int>> P(N);
    for (auto& [x,y] : P)
        cin >> x >> y;
    auto ans = zawa::Mo(P);
    ranges::rotate(ans,ranges::find(ans,0));
    long long cost = 0;
    for (int i = 0 ; i < ssize(ans) ; i++) {
        int j = ans[i], k = ans[(i+1)%N];
        cost += abs(P[j].first-P[k].first);
        cost += abs(P[j].second-P[k].second);
    }
    assert(cost <= (long long)7.5e9);
    for (int i = 0 ; i < ssize(ans) ; i++)
        cout << ++ans[i] << (i + 1 == ssize(ans) ? '\n' : ' ');
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
