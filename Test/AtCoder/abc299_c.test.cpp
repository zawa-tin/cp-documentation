#define PROBLEM "https://atcoder.jp/contests/abc299/tasks/abc299_c"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Sequence/RunLengthEncoding.hpp"

#include <iostream>
#include <string>
#include <algorithm>

using namespace zawa;

i32 solve(const std::string& S) {
    RunLengthEncoding<u8> rle(S.begin(), S.end());
    i32 res{-1};
    for (u32 i{1} ; i < rle.size() ; i++) {
        if (rle[i].value() == 'o') {
            res = std::max<i32>(res, rle[i].number());
        }
    }
    return res;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u32 N; std::cin >> N;
    std::string S; std::cin >> S;

    i32 ans{-1};
    ans = std::max(ans, solve(S));
    std::reverse(S.begin(), S.end());
    ans = std::max(ans, solve(S));

    std::cout << ans << std::endl;
    
}
