#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Number/BinomalCoefficients.hpp"

#include <iostream>
#include <tuple>
using namespace zawa;

/*
 * yukicoder No.117 組み合わせの数
 * https://yukicoder.me/submissions/957921
 */

std::tuple<char, int, int> parse() {
    std::string s; std::cin >> s;
    char c{s[0]};
    int i{2};
    int p{};
    for (; s[i] != ',' ; i++) {
        p = (p * 10) + (s[i] - '0');
    }
    int q{};
    for (i++ ; s[i] != ')' ; i++) {
        q = (q * 10) + (s[i] - '0');
    }
    return { c, p, q };
}

void solve() {
    int t; std::cin >> t;
    BinomalCoefficients<1000000007> comb(1000000);
    for (int _{} ; _ < t ; _++) {
        auto [c, p, q]{parse()}; 
        if (c == 'C') std::cout << comb.C(p, q).val() << '\n';
        else if (c == 'P') std::cout << comb.P(p, q).val() << '\n';
        else std::cout << comb.H(p, q).val() << '\n';
    }
}

int main() {
#ifdef ONLINE_JUDGE
    solve();
#else
    std::cout << "Hello World" << '\n';
#endif
}
