#pragma once

#include "../Template/TypeAlias.hpp"

#include <deque>
#include <vector>
#include <cassert>

namespace zawa {

template <class Value, class Number = u64>
class RunLengthEncoding {
public:
    class Data {
    private:
        Value value_;
        Number number_;
    public:
        Data() = default;
        Data(const Value& value, Number number) : value_{ value }, number_{ number } {}

        const Value& value() const noexcept {
            return value_;
        }

        Number number() const noexcept {
            return number_;
        }

        friend RunLengthEncoding;
    };

private:
    std::deque<Data> seq_;
    u64 sum_{};

    template <class InputIterator>
    inline void build(InputIterator first, InputIterator last) {
        for (auto it{ first } ; it != last ; it++) {
            if (seq_.empty() or seq_.back().value() != *it) {
                seq_.emplace_back(*it, Number{1});
            }
            else {
                seq_.back().number_++;
            }
            sum_++;
        }
    }

public:
    RunLengthEncoding() = default;

    template <class InputIterator>
    RunLengthEncoding(InputIterator first, InputIterator last) {
        build(first, last);
    }

    RunLengthEncoding(const std::vector<Value>& a) {
        build(a.begin(), a.end());
    }

    constexpr usize size() const noexcept {
        return seq_.size();
    }

    constexpr u64 sum() const noexcept {
        return sum_;
    }

    const Data& operator[](u32 i) const noexcept {
        assert(i < size());
        return seq_[i];
    }

    const Value& value(u32 i) const noexcept {
        assert(i < size());
        return seq_[i].value();
    }

    const Number number(u32 i) const noexcept {
        assert(i < size());
        return seq_[i].number();
    }

    typename decltype(seq_)::const_iterator begin() const noexcept {
        return seq_.begin();
    }

    typename decltype(seq_)::const_iterator end() const noexcept {
        return seq_.end();
    }

    const Data& front() const noexcept {
        assert(size());
        return seq_.front();
    }

    const Data& back() const noexcept {
        assert(size());
        return seq_.back();
    }

    void pushBack(const Value& value, const Number number = Number{1}) {
        sum_ += number;
        if (seq_.empty() or seq_.back().value() != value) {
            seq_.emplace_back(value, number);
        }
        else {
            seq_.back().number_ += number;
        }
    }

    void pushFront(const Value& value, const Number number = Number{1}) {
        sum_ += number;
        if (seq_.empty() or seq_.front().value() != value) {
            seq_.emplace_front(value, number);
        }
        else {
            seq_.front().number_ += number;
        }
    }

    void popBack() {
        assert(size());
        sum_ -= seq_.back().number();
        seq_.pop_back();
    }

    void popFront() {
        assert(size());
        sum_ -= seq_.front().number();
        seq_.pop_front();
    }

    std::vector<Data> popBack(u64 number) {
        assert(number <= sum());
        sum_ -= number;
        std::vector<Data> res;
        while (number and number >= seq_.back().number()) {
            res.push_back(seq_.back());
            number -= seq_.back().number();
            seq_.pop_back();
        }
        if (number) {
            res.emplace_back(seq_.back().value(), number);
            seq_.back().number_ -= number;
        }
        return res;
    }

    std::vector<Data> popFront(u64 number) {
        assert(number <= sum());
        sum_ -= number;
        std::vector<Data> res;
        while (number and number >= seq_.front().number()) {
            res.push_back(seq_.front());
            number -= seq_.front().number();
            seq_.pop_front();
        }
        if (number) {
            res.emplace_back(seq_.front().value(), number);
            seq_.front().number_ -= number;
        }
        return res;
    }
};

} // namespace zawa
