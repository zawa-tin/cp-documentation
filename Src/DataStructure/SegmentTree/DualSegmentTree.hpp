#pragma once

#include "./CommutativeDualSegmentTree.hpp"

namespace zawa {

template <Concept::Monoid Monoid>
class DualSegmentTree : public CommutativeDualSegmentTree<Monoid> {
private:
    using Base = CommutativeDualSegmentTree<Monoid>;
public:
    using Operator = typename Base::Operator;
    DualSegmentTree() : Base() {}
    DualSegmentTree(u32 n) : Base(n) {}
    DualSegmentTree(const std::vector<Operator>& dat) : Base(dat) {}
    template <class InputIterator>
    DualSegmentTree(InputIterator first, InputIterator last) : Base(first, last) {}
    
    void operation(u32 l, u32 r, const Operator& v) override {
        Base::push(l);
        if (l < r) Base::push(r - 1);
        Base::operation(l, r, v);
    } 

    Operator operator[](u32 i) override {
        Base::push(i);
        return Base::operator[](i);
    }
};

} // namespace zawa
