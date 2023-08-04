#define PROBLEM "https://atcoder.jp/contests/abc295/tasks/abc295_a"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/Input.hpp"
#include "../../Src/Template/YesNo.hpp"

using namespace zawa;

#include <set>
#include <string>

int main() {
    SetAtCoderYesNo();
    u32 N; In(N);
    std::set<std::string> st{ "and", "not", "that", "the", "you" };
    bool ans{};
    for (u32 _{} ; _ < N ; _++) {
        std::string w; In(w);
        ans |= st.count(w);
    }
    YesNo(ans);
}
