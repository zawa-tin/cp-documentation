#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Template/Input.hpp"
#include "../../Src/Template/Output.hpp"

using namespace zawa;

int main() {
    SetFastIO();
    SetPrecision(15);
    u32 T; In(T);
    for (u32 _{} ; _ < T ; _++) {
        u64 A, B; In(A, B);
        Cout(A + B, '\n');
    }
}
