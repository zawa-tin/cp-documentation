#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <limits>
#include <vector>
#include <map>

namespace zawa {

class SubtreesHasher {
public:

    SubtreesHasher() = default;

    template <class G>
    std::vector<usize> operator()(const G& g, usize r = 0u) {
        std::vector<usize> res(g.size());
        auto dfs = [&](auto dfs, usize v, usize p) -> usize {
            std::vector<usize> ch;
            ch.reserve(g[v].size());
            for (usize x : g[v]) if (x != p) {
                ch.push_back(dfs(dfs, x, v));
            }
            std::sort(ch.begin(), ch.end());
            return res[v] = mapping(std::move(ch));
        };
        dfs(dfs, r, std::numeric_limits<u32>::max());
        return res;
    }

private:

    std::map<std::vector<usize>, usize> map;

    usize mapping(std::vector<usize>&& A) {
        usize cur = map.size();
        return map.try_emplace(std::move(A), cur).first->second;
    }
};

} // namespace zawa
