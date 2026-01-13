#pragma once

#include "../../Template/TypeAlias.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <utility>
#include <vector>
#include <functional>

namespace zawa {

template <class T, class Comp = std::less<T>>
requires std::strict_weak_order<Comp, const T&, const T&>
class BinaryHeap {
private:

    Comp m_comp;

    std::vector<T> m_dat;

public:

    inline usize size() const {
        return m_dat.size() - 1;
    }

    inline bool empty() const {
        return m_dat.size() == 1;
    }

    using const_iterator = typename decltype(m_dat)::const_iterator;

    const_iterator begin() const {
        return m_dat.begin() + 1;
    }

    const_iterator end() const {
        return m_dat.end();
    }

    BinaryHeap(Comp comp = {}) 
        : m_comp{comp}, m_dat(1) {}

    template <std::forward_iterator It>
    requires std::same_as<std::iter_value_t<It>, T>
    BinaryHeap(It first, It last, Comp comp = {}) 
        : m_comp{comp}, m_dat(1) {
        m_dat.insert(m_dat.end(), first, last);
        build();
    }

    BinaryHeap(std::vector<T>&& a, Comp comp = {}) 
        : m_comp{comp}, m_dat(a.size() + 1) {
        std::ranges::copy(std::make_move_iterator(a.begin()), std::make_move_iterator(a.end()), m_dat.begin() + 1);
        build();
    }

    BinaryHeap(const std::vector<T>& a, Comp comp = {}) 
        : m_comp{comp}, m_dat(a.size() + 1) {
        std::ranges::copy(a.begin(), a.end(), m_dat.begin() + 1);
        build();
    }

    const T& top() const {
        assert(size() and "HeapUnderFlow");
        return m_dat[1];
    }

    void push(T&& v) {
        m_dat.push_back(std::move(v));
        upHeap(size());
    }

    void push(const T& v) {
        m_dat.push_back(v);
        upHeap(size());
    }

    void pop() {
        assert(size() and "HeapUnderFlow");
        if (size() > 1)
            std::swap(m_dat[1], m_dat.back());
        m_dat.pop_back();
        if (size() > 1)
            downHeap(1, size());
    }

private:

    void build() {
        const usize n = size();
        for (usize i = (n >> 1) ; i ; i--) 
            downHeap(i, n);
    }

    void upHeap(usize i) {
        while (i >> 1 and m_comp(m_dat[i], m_dat[i >> 1])) {
            std::swap(m_dat[i], m_dat[i >> 1]);
            i >>= 1;
        }
    }

    void downHeap(usize i, usize n) {
        while ((i << 1) <= n) {
            usize j = i << 1;
            if (j + 1 <= n and m_comp(m_dat[j + 1], m_dat[j]))
                j++;
            if (!m_comp(m_dat[j], m_dat[i]))
                break;
            std::swap(m_dat[i], m_dat[j]);
            i = j;
        }
    }
};

} // namespace zawa
