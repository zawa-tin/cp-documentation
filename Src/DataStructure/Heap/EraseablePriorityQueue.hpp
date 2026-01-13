#pragma once

#include "BinaryHeap.hpp"

namespace zawa {

template <class T, class Comp = std::less<T>>
requires std::strict_weak_order<Comp, const T&, const T&>
class EraseablePriorityQueue {
private:

    BinaryHeap<T, Comp> m_que, m_rm;

    usize m_cnt = 0;

public:

    inline usize size() const {
        return m_cnt;
    }

    EraseablePriorityQueue(Comp comp = {}) 
        : m_que{comp}, m_rm{comp}, m_cnt{0} {}

    template <std::forward_iterator It>
    requires std::same_as<std::iter_value_t<It>, T>
    EraseablePriorityQueue(It first, It last, Comp comp = {})
        : m_que{first, last, comp}, m_rm{comp}, m_cnt{m_que.size()} {}

    EraseablePriorityQueue(std::vector<T> a, Comp comp = {}) 
        : m_que{a, comp}, m_rm{comp}, m_cnt{m_que.size()} {}

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void push(U&& v) {
        m_que.push(std::forward<U>(v));
        m_cnt++;
    }

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void erase(U&& v) {
        assert(size() and "HeapUnderFlow");
        m_rm.push(std::forward<U>(v));
        m_cnt--;
    }

    const T& top() {
        assert(size() and "HeapUnderFlow");
        normalize();
        return m_que.top();
    }

    T pop() {
        assert(size() and "HeapUnderFlow");
        normalize();
        T res = m_que.top();
        m_que.pop();
        return res;
    }

private:

    void normalize() {
        while (m_rm.size() and m_que.size() and m_que.top() == m_rm.top())
            m_que.pop(), m_rm.pop();
    }
};

} // namespace zawa
