#pragma once

#include "../Template/TypeAlias.hpp"
#include "./Point.hpp"
#include "./Relation.hpp"

#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>

namespace zawa {

namespace geometryZ2 {

class Polygon {
private:
    std::vector<Point> data_;
public:
    usize size() const {
        return data_.size(); 
    }

    /* constructor */
    Polygon() = default;
    Polygon(const Polygon& polygon) : data_{polygon.data_} {}
    Polygon(const std::vector<Point>& data) : data_{data} {}
    Polygon(usize n) : data_{n} {
        assert(n >= static_cast<usize>(3));
    }

    /* operator */
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
    void headMinimize() {
        auto index{std::distance(data_.begin(), std::min_element(data_.begin(), data_.end()))};
        orderRotate(index);
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
    Zahlen areaTwice() const {
        assert(size() >= static_cast<usize>(3));
        Zahlen res{};
        for (usize i{1} ; i < size() ; i++) {
            res += Cross(data_[i] - data_[0], data_[i+1==size()?0:i+1] - data_[0]);
        }
        return res;
    }
};

}

} // namespace zawa
