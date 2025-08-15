#pragma once

#include "./FenwickSet.hpp"
#include "../../Sequence/CompressedSequence.hpp"

#include <concepts>
#include <vector>

namespace zawa {

template <std::totally_ordered T>
class OfflineOrderedSet {
private:
    class OfflineOrderedSetExecuter {
    public:

        explicit OfflineOrderedSetExecuter(std::vector<T>&& app)
            : m_comp(std::move(app)), m_set(m_comp.size()) {}

        usize size() const {
            return m_set.size();
        }

        void insert(T x) {
            m_set.insert(m_comp.at(x));
        }

        void erase(T x) {
            auto it = m_comp.find(x);
            if (it == decltype(m_comp)::NotFound)
                return;
            m_set.erase(it);
        }

        bool contains(T x) const {
            auto it = m_comp.find(x);
            return it != decltype(m_comp)::NotFound and m_set.contains(it);
        }

        // 1-indexed
        std::optional<T> kth(i32 k) const {
            auto res = m_set.kth(k);
            return res ? std::optional{m_comp.inverse(res.value())} : std::nullopt;
        }

        usize countLessEqual(T x) const {
            return m_set.countLessEqual(static_cast<i32>(m_comp.upper_bound(x)) - 1);
        }

        std::optional<T> prevEqual(T x) const {
            auto res = m_set.prevEqual(static_cast<i32>(m_comp.upper_bound(x)) - 1);
            return res ? std::optional{m_comp.inverse(res.value())} : std::nullopt;
        }

        std::optional<T> nextEqual(T x) const {
            auto res = m_set.nextEqual(m_comp[x]);
            return res ? std::optional{m_comp.inverse(res.value())} : std::nullopt;
        }

    private:

        CompressedSequence<T> m_comp;

        FenwickSet m_set;
    };

public:

    OfflineOrderedSet() = default;

    void reserveInsert(T v) {
        m_app.push_back(v);
    }

    OfflineOrderedSetExecuter build() {
        return OfflineOrderedSetExecuter{std::move(m_app)};
    }

private:

    std::vector<T> m_app; 

};

}
