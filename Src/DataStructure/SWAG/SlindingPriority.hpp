#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <concepts>
#include <functional>
#include <vector>

namespace zawa {

template <class T,class F = std::less<T>>
requires std::predicate<F,T,T>
class SlidingPriority {
public:

    SlidingPriority() : m_comp{F{}} {}

    explicit SlidingPriority(F comp) : m_comp{std::move(comp)} {}

    inline usize size() const {
        return m_container.size() - m_fr;
    }

    inline bool empty() const {
        return m_fr == m_container.size();
    }

    void push(T x) {
        while (size() and m_comp(x,m_container.back()))
            m_container.pop_back();
        m_container.push_back(std::move(x));
    }

    void pop() {
        assert(!empty());
        m_fr++;
    }

    const T& top() const {
        assert(!empty());
        return m_container[m_fr];
    }

    const T& operator()() const {
        assert(!empty());
        return m_container[m_fr];
    }

private:

    F m_comp;

    std::vector<T> m_container;

    usize m_fr = 0;

};

template <class T,class F>
requires std::predicate<F,T,T>
std::vector<T> StaticLengthPriority(const std::vector<T>& A,usize K,F comp) {
    assert(0u < K and K <= A.size());
    using Item = std::pair<T,usize>;
    auto f = [&](const Item& i,const Item& j) {
        return comp(i.first,j.first);
    };
    SlidingPriority<Item,decltype(f)> deq{f};
    std::vector<T> res(A.size()-K+1);
    for (usize i = 0 ; i < K ; i++)
        deq.push({A[i],i});
    for (usize i = K ; i <= A.size() ; i++) {
        const auto& [v,idx] = deq.top();
        res[i-K] = v;
        if (idx == i-K)
            deq.pop();
        if (i < A.size())
            deq.push({A[i],i});
    }
    return res;
}

template <class T>
requires std::totally_ordered<T>
std::vector<T> StaticLengthPriority(const std::vector<T>& A,usize K) {
    return StaticLengthPriority(A,K,std::less<T>{});
}

} // namespace zawa
