#define PROBLEM "https://atcoder.jp/contests/abc230/tasks/abc230_e"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Number/EnumerateQuotients.hpp"

#include <iostream>

using namespace zawa;

int main() {
    u64 N; std::cin >> N;
    EnumerateQuotients eq(N);
    u64 ans{};
    for (const auto& q : eq) {
        ans += q.len() * q.quotient();
    }
    std::cout << ans << std::endl;
}
