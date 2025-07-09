#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../Src/Sequence/Manacher.hpp"

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::string S;
    std::cin >> S;
    auto ans = zawa::Manacher(S);
    for (int i = 0 ; i < std::ssize(ans) ; i++) std::cout << ans[i] << (i + 1 == std::ssize(ans) ? '\n' : ' ');
}
