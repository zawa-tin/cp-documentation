#include "../../Src/Template/TypeAlias.hpp"
#include "../../Src/Utility/BinarySearch.hpp"

#include <iostream>

int main() {
    using namespace zawa;
    u32 n, m; std::cin >> n >> m;
    std::vector g(n, std::vector<std::pair<u32, u32>>{});
    for (u32 _{} ; _ < m ; _++) {
        u32 a, b, w; std::cin >> a >> b >> w;
        a--; b--;
        g[a].emplace_back(w, b);
        g[b].emplace_back(w, a);
    }
    for (auto& adj : g) std::sort(adj.begin(), adj.end());

    auto f{[&](u32 X) -> bool {
        std::vector<i32> col(n, -1);
        auto rec{[&](auto rec, u32 v, u32 c) -> bool {
            col[v] = c;
            for (auto [w, x] : g[v]) {
                if (w >= X) break;
                if (col[x] == -1 and !rec(rec, x, c ^ 1)) return false;
                if (col[x] == (i32)c) return false;
            }
            return true;
        }};
        for (u32 i{} ; i < n ; i++) if (col[i] == -1 and !rec(rec, i, 0))
            return false;
        for (u32 i{} ; i < n ; i++) if (g[i].size() > 1) {
            if (g[i][0].first + g[i][1].first < X) return false;
        }
        return true;
    }};

    u32 ans{ BinarySearch(u32{}, (u32)2e9 + 1, f) };
    std::cout << ans << std::endl;
}
