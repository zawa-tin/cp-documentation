#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <limits>
#include <utility>
#include <vector>

namespace zawa {

template <class T, class RBT, class Add, class Rollback, class Eval>
std::vector<typename std::invoke_result_t<Eval, usize, const RBT&>> RollbackMo(const std::vector<T>& qs, Add addL, Add addR, Rollback rollback, Eval eval) {
    const usize n = [&]() {
        usize mx = 0;
        for (usize i = 0 ; i < qs.size() ; i++) {
            assert(qs[i].l <= qs[i].r);
            mx = std::max<usize>(mx, qs[i].r);
        }
        return mx;
    }();
    const usize SQ = [&]() {
        usize i = 1;
        while (i * i < n)
            i++;
        return i;
    }();
    std::vector<std::vector<std::pair<usize, usize>>> rs((n + SQ - 1) / SQ);
    std::vector<typename std::invoke_result_t<Eval, usize, const RBT&>> res(qs.size());
    std::vector<RBT> history;
    history.emplace_back();
    for (usize i = 0 ; i < qs.size() ; i++) {
        if (qs[i].r - qs[i].l <= SQ) {
            for (usize j = qs[i].l ; j < qs[i].r ; j++)
                history.push_back(addR(j, history.back()));
            res[i] = eval(i, history.back());
            for (usize j = qs[i].l ; j < qs[i].r ; j++) {
                rollback(history.back());
                history.pop_back();
            }
        }
        else
            rs[qs[i].l / SQ].emplace_back(qs[i].r, i);
    }
    for (usize i = 0 ; i < rs.size() ; i++)
        if (rs[i].size()) {
            std::sort(rs[i].begin(), rs[i].end());
            const usize L = (i + 1) * SQ;
            usize R = L;
            for (auto [r, idx] : rs[i]) {
                while (R < r)
                    history.push_back(addR(R++, history.back()));
                for (usize j = L ; j > qs[idx].l ; )
                    history.push_back(addL(--j, history.back()));
                res[idx] = eval(idx, history.back());
                for (usize j = L ; j > qs[idx].l ; j--) {
                    rollback(history.back());
                    history.pop_back();
                }
            }
            for (usize j = L ; j < R ; j++) {
                rollback(history.back());
                history.pop_back();
            }
        }
    return res;
}

} // namespace zawa
