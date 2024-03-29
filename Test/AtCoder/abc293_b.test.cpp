#define PROBLEM "https://atcoder.jp/contests/abc293/tasks/abc293_b"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/Input.hpp"
#include "../../Src/Template/Output.hpp"

using namespace zawa;

int main() {
    u32 N; input(N);
    std::vector<bool> A(N);
    for (u32 i{} ; i < N ; i++) {
        u32 a; input(a);
        if (not A[i]) A[a - 1] = true;
    }
    std::vector<u32> ans;
    for (u32 i{} ; i < N ; i++) {
        if (not A[i]) {
            ans.push_back(i + 1);
        }
    }
    out(ans.size());
    out(ans);
}
