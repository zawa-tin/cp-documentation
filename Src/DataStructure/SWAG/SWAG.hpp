#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <vector>

namespace zawa {

template <class S>
class SlidingWindowAggregation {
public:
    using V = typename S::Element;

    SlidingWindowAggregation() = default;

    usize size() const noexcept {
        return front_.size() + back_.size();
    }

    bool empty() const noexcept {
        return size() == 0u;
    }

    void push(const V& v) {
        raw_.push_back(v);
        back_.push_back(back_.size() ? S::operation(back_.back(), v) : v);
    }

    void pop() {
        assert(size());
        move();
        front_.pop_back();
    }

    V product() {
        assert(size());
        if (front_.empty()) return back_.back();
        if (back_.empty()) return front_.back();
        return S::operation(front_.back(), back_.back());
    }
    
private:
    std::vector<V> front_{}, back_{};
    std::vector<V> raw_{};

    void move() {
        if (front_.empty()) {
            while (back_.size()) {
                back_.pop_back();
                V v{raw_.back()};
                raw_.pop_back();
                front_.push_back(front_.size() ? S::operation(v, front_.back()) : v);
            }
        }
    }
};

} // namespace zawa
