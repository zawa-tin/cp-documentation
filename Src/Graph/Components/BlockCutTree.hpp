#pragma once

#include <cassert>
#include <concepts>
#include <vector>
#include <optional>

#include "../../Template/TypeAlias.hpp"

namespace zawa {

template <std::integral T>
class BlockCutTree {
public:

    BlockCutTree() = default;

    explicit BlockCutTree(const std::vector<std::vector<T>>& g) : inv_(g.size()) {
        const usize n = g.size();
        std::vector<usize> low(n), ord(n), vs;
        usize time = 1;
        const T INVALID = static_cast<T>(-1);
        auto dfs = [&](auto dfs, T v, T p) -> void {
            low[v] = ord[v] = time++;
            if (g[v].empty()) {
                blocks_.push_back({T{v}});
                return;
            }
            usize deg = 0;
            bool cut = false;
            for (T x : g[v]) {
                if (ord[x]) {
                    low[v] = std::min(low[v], ord[x]);
                }
                else {
                    deg++;
                    dfs(dfs, x, v);
                    low[v] = std::min(low[v], low[x]);
                    if (low[x] >= ord[v]) {
                        std::vector<T> cur{v};
                        cut |= p != INVALID;
                        while (vs.size() and ord[vs.back()] >= ord[x]) {
                            cur.push_back(vs.back());
                            vs.pop_back();
                        }
                        blocks_.push_back(std::move(cur));
                    }
                }
            }
            cut |= p == INVALID and deg >= 2;
            if (cut) cuts_.push_back(v);
            vs.push_back(v);
        };
        for (T i = 0 ; i < static_cast<T>(n) ; i++) if (!ord[i]) 
            dfs(dfs, i, INVALID);
        const usize m = blocks_.size(), k = cuts_.size();
        for (usize i = 0 ; i < k ; i++) inv_[cuts_[i]] = m + i;
        g_.resize(m + k);
        for (usize i = 0 ; i < m ; i++) {
            for (T v : blocks_[i]) if (inv_[v] >= m) {
                g_[i].push_back(inv_[v]);
                g_[inv_[v]].push_back(i);
            }
        }
    }

    inline usize size() const noexcept {
        return g_.size();
    }

    const std::vector<T>& operator[](usize i) const {
        assert(i < size());
        return g_[i];
    }

    enum class Type {
        BLOCK,
        CUT
    };

    Type type(usize i) const {
        assert(i < size());
        return i < blocks_.size() ? Type::BLOCK : Type::CUT;
    }

    const std::vector<std::vector<T>>& blocks() const {
        return blocks_;
    }

    const std::vector<T>& block(usize i) const {
        assert(i < size() and type(i) == Type::BLOCK);
        return blocks_[i];
    }

    const std::vector<T>& cuts() const {
        return cuts_;
    }

    const T cut(usize i) const {
        assert(i < size() and type(i) == Type::CUT);
        return cuts_[i - blocks_.size()];
    }

    std::vector<T> vertices(usize i) const {
        assert(i < size());
        return i < blocks_.size() ? 
            blocks_[i] : std::vector<T>{cuts_[i - blocks_.size()]};
    }

    bool isCut(T v) const {
        assert(v < static_cast<T>(inv_.size()));
        return inv_[v] >= blocks_.size();
    }

    std::optional<usize> cutId(usize i) const {
        assert(i < size());
        return isCut(i) ? std::optional<usize>{inv_[i]} : std::nullopt;
    }

private:

    std::vector<std::vector<T>> blocks_;

    std::vector<T> cuts_;

    std::vector<std::vector<T>> g_;

    std::vector<usize> inv_;
};

} // namespace zawa
