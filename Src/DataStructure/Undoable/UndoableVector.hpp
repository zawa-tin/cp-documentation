#pragma once

#include "../../Template/TypeAlias.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class T>
class UndoableVector {
public:
    using Iterator = typename std::vector<T>::const_iterator;

    UndoableVector() = default;

    UndoableVector(usize n) : vec_(n) {}

    UndoableVector(usize n, const T& v) : vec_(n, v) {}

    UndoableVector(const std::vector<T>& vec) : vec_{vec} {}

    UndoableVector(std::vector<T>&& vec) : vec_{std::move(vec)} {}
    
    inline usize size() const {
        return vec_.size();
    }

    Iterator begin() const {
        return vec_.begin();
    }

    Iterator end() const {
        return vec_.end();
    }

    void assign(usize i, const T& v) {
        assert(i < size());
        save(i);
        vec_[i] = v;
    }

    T operator[](usize i) const {
        assert(i < size());
        return vec_[i];
    }

    void undo() {
        assert(history_.size());
        auto [i, v]{history_.back()};
        vec_[i] = v;
        history_.pop_back();
    }

private:
    std::vector<T> vec_; 
    std::vector<std::pair<usize, T>> history_;

    void save(usize i) {
        history_.emplace_back(i, vec_[i]);
    }
};

} // namespace zawa
