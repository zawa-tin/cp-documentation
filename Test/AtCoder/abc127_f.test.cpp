#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"

#include "../../Src/Template/IOSetting.hpp"
#include "../../Src/Utility/SlopeTrick.hpp"

#include <cassert>
#include <iostream>

using namespace zawa;

int main() {
    SetFastIO();
    SlopeTrick<int, long long> st;
    int Q;
    std::cin >> Q;
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int a, b;
            std::cin >> a >> b;
            st.addAbsoluteXA(a);
            st.addConstant(b);
        }  
        else if (t == 2) {
            auto [l, r]{st.argmin()};
            long long min{st.min()};
            assert(l.has_value());
            std::cout << l.value() << ' ' << min << '\n';
        }
    }
}
