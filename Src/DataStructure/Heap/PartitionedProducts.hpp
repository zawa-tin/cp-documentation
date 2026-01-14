#pragma once

#include "EraseablePriorityQueue.hpp"
#include "../../Algebra/Action/SetOperator.hpp"

#include <utility>

namespace zawa {

namespace internal {

template <class Comp>
struct ReverseComp {

    [[no_unique_address]] Comp comp;

    ReverseComp() = default;

    explicit ReverseComp(Comp c) : comp(std::move(c)) {}

    template <class T, class U>
    bool operator()(T&& a, U&& b) const noexcept(noexcept(std::invoke(comp, std::forward<U>(b), std::forward<T>(a)))) {
        return std::invoke(comp, std::forward<U>(b), std::forward<T>(a));
    }
};

} // namespace internal

template <class S, class T, class Comp = std::less<T>>
requires concepts::SetOperator<S, T> and std::strict_weak_order<Comp, const T&, const T&>
class PartitionedProducts {
public:

    PartitionedProducts(Comp comp = {}) 
        : m_sm{internal::ReverseComp{comp}}, m_bg{comp}, m_comp{comp} {}

    PartitionedProducts(std::vector<T> a, Comp comp = {}) 
        : m_sm{}, m_bg{comp}, m_comp{comp} {
        for (const T& x : a)
            S::add(m_prodS, x);
        m_sm = EraseablePriorityQueue{std::move(a), internal::ReverseComp{comp}};
    }

    inline usize size() const {
        return m_sm.size() + m_bg.size();
    }

    inline usize smallSize() const {
        return m_sm.size();
    }

    inline usize bigSize() const {
        return m_bg.size();
    }

    inline bool empty() const {
        return m_sm.empty() and m_bg.empty();
    }

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void insert(U&& v) {
        if (m_sm.empty())
            addBig(std::forward<U>(v));
        else if (m_bg.empty() or m_comp(v, m_bg.top()))
            addSmall(std::forward<U>(v));
        else
            addBig(std::forward<U>(v));
    }

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void erase(U&& v) {
        if (m_sm.empty())
            eraseBig(std::forward<U>(v));
        else if (m_bg.empty() or m_comp(v, m_bg.top()))
            eraseSmall(std::forward<U>(v));
        else
            eraseBig(std::forward<U>(v));
    }

    bool adjustSmall(usize K) {
        if (size() < K)
            return false;
        adjust(K);
        return true;
    }

    bool adjustBig(usize K) {
        if (size() < K)
            return false;
        adjust(size() - K);
        return true;
    }

    const T& smallTop() {
        assert(smallSize() and "HeapUnderFlow: small");
        return m_sm.top();
    }

    const S::Element& smallProd() const {
        return m_prodS;
    }

    const T& bigTop() {
        assert(bigSize() and "HeapUnderFlow: big");
        return m_bg.top();
    }

    const S::Element& bigProd() const {
        return m_prodB;
    }

    std::pair<std::vector<T>, std::vector<T>> container() const {
        return {m_sm.container(), m_bg.container()};
    }

private:

    EraseablePriorityQueue<T, internal::ReverseComp<Comp>> m_sm;

    EraseablePriorityQueue<T, Comp> m_bg;

    Comp m_comp;

    S::Element m_prodS = S::identity(), m_prodB = S::identity();

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void addSmall(U&& v) {
        S::add(m_prodS, v);
        m_sm.push(std::forward<U>(v));
    }

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void addBig(U&& v) {
        S::add(m_prodB, v);
        m_bg.push(std::forward<U>(v));
    }

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void eraseSmall(U&& v) {
        S::remove(m_prodS, v);
        m_sm.erase(std::forward<U>(v));
    }

    template <class U>
    requires std::same_as<std::remove_cvref_t<U>, T>
    void eraseBig(U&& v) {
        S::remove(m_prodB, v);
        m_bg.erase(std::forward<U>(v));
    }

    void adjust(usize K) {
        while (smallSize() > K) {
            addBig(m_sm.top());
            S::remove(m_prodS, m_sm.top());
            m_sm.pop();
        }
        while (smallSize() < K) {
            addSmall(m_bg.top());
            S::remove(m_prodB, m_bg.top());
            m_bg.pop();
        }
    }
};

} // namespace zawa
