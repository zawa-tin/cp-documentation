#pragma once

#include <cassert>
#include <utility>
#include <vector>

namespace zawa {

template <class T>
class UndoableValue {
public:

    UndoableValue() = default;

    UndoableValue(const T& v) : v_{v} {}

    UndoableValue(T&& v) : v_{std::move(v)} {}

    void assign(const T& v) {
        save();
        v_ = v;
    }

    void assign(T&& v) {
        save();
        v_ = std::move(v);
    }

    const T& value() const {
        return v_;
    }

    void undo() {
        assert(history_.size());
        v_ = history_.back();
        history_.pop_back();
    }

private:
    T v_{};
    std::vector<T> history_;

    inline void save() {
        history_.emplace_back(v_);
    }
};

} // namespace zawa
