#pragma once

#include "./CommutativeDualSegmentTree.hpp"

namespace zawa {

template <concepts::Monoid Monoid>
class DualSegmentTree : public CommutativeDualSegmentTree<Monoid> {
private:

    using Base = CommutativeDualSegmentTree<Monoid>;
    
public:

    using OM = Monoid;

    using O = typename OM::Element;

    using VM = Monoid;

    using V = typename VM::Element;

    DualSegmentTree() : Base() {}

    explicit DualSegmentTree(usize n) : Base{n} {}

    explicit DualSegmentTree(const std::vector<O>& dat) : Base{dat} {}

    template <class InputIterator>
    DualSegmentTree(InputIterator first, InputIterator last) : Base(first, last) {}
    
    void operation(usize l, usize r, const O& o) override {
        Base::push(l);
        if (l < r) Base::push(r - 1);
        Base::operation(l, r, o);
    } 

    void operation(usize i, const O& o) override {
        Base::push(i);
        Base::operation(i, o);
    }

    V operator[](usize i) override {
        Base::push(i);
        return Base::operator[](i);
    }
};

} // namespace zawa
