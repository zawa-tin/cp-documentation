#pragma once

#include "../Template/TypeAlias.hpp"
#include "./Real.hpp"
#include "./Point.hpp"
#include "./Relation.hpp"

#include <algorithm>
#include <cassert>
#include <concepts>
#include <vector>

namespace zawa {

namespace geometryR2 {

class Polygon {
private:
    std::vector<Point> data_;
public:
    /* member */
    usize size() const {
        return data_.size();
    }

    /* constructor */
    Polygon() = default;
    explicit Polygon(const std::vector<Point>& data) : data_{data} {}
    explicit Polygon(usize n) : data_(n) {}

    /* operator[] */
    Point& operator[](usize i) {
        assert(i < size());
        return data_[i];
    }
    const Point& operator[](usize i) const {
        assert(i < size());
        return data_[i];
    }
    friend std::istream& operator>>(std::istream& is, Polygon& polygon) {
        for (size_t i{} ; i < polygon.size() ; i++) {
            is >> polygon[i];
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon) {
        for (usize i{} ; i < polygon.size() ; i++) {
            std::cout << polygon[i] << (i + 1 == polygon.size() ? "" : " ");
        }
        return os;
    }

    /* member function */
    void orderRotate(usize i) {
        assert(i < size());
        std::rotate(data_.begin(), data_.begin() + i, data_.end());
    }
    void normalForm() {
        auto index{std::distance(data_.begin(), std::min_element(data_.begin(), data_.end()))};
        orderRotate(index);
    }
    Polygon normalFormed() const {
        Polygon res{*this};
        res.normalForm();
        return res;
    }
    bool isConvex() const {
        assert(size() >= static_cast<usize>(3));
        for (usize i{} ; i < size() ; i++) {
            if (Relation(data_[i], data_[i+1==size()?0:i+1], data_[i+2>=size()?i+2-size():i+2])
                    == CLOCKWISE) {
                return false;
            }
        }
        return true;
    }
    Real area() const {
        if (std::ssize(data_) <= 2) return 0;
        Real res{};
        for (usize i{1} ; i < size() ; i++) {
            res += Cross(data_[i] - data_[0], data_[i+1==size()?0:i+1] - data_[0]);
        }
        return res / static_cast<Real>(2);
    }
    void pushBack(const Point& p) {
        data_.push_back(p);
    }
    void emplaceBack(Real x, Real y) {
        data_.emplace_back(x, y);
    }
    void reserve(usize n) {
        data_.reserve(n);
    }
    template <std::input_iterator RandomAccessIterator>
    void insert(usize n, RandomAccessIterator first, RandomAccessIterator last) {
        assert(n <= size());
        data_.insert(std::next(data_.begin(), n), first, last);
    }
};

} // namespace geometryR2

} // namespace zawa

