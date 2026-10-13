// #define PROBLEM "https://atcoder.jp/contests/tenka1-2014-final/tasks/tenka1_2014_final_d"
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
/*
 * 天下一プログラマーコンテスト2014本戦 D - 高橋君
 * https://atcoder.jp/contests/tenka1-2014-final/submissions/80011789
 */
#include "../../Src/Combinatorics/BinomialCoefficientPrefixSums.hpp"
#include "atcoder/modint"
#include <iostream>
#include <utility>
#include <vector>
using mint=atcoder::modint1000000007;
using namespace std;
int main() {
#ifdef ATCODER
    int T;
    cin >> T;
    vector<pair<int,int>> NK(T);
    for (auto& [n,k] : NK)
        cin >> n >> k;
    for (auto ans : zawa::BinomialCoefficientPrefixSums<mint>(NK))
        cout << ans.val() << '\n';
#else
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
#endif
}
