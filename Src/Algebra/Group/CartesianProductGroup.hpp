#pragma once

#include "./GroupConcept.hpp"
#include "../PowerableConcept.hpp"

#include <utility>

namespace zawa {

template <concepts::Group G>
class CartesianProductGroup {
public:

    using Element = std::pair<typename G::Element,typename G::Element>;

    static Element identity() {
        return {G::identity(),G::identity()};
    }

    static Element operation(const Element& l,const Element& r) {
        return {G::operation(l.first,r.first),G::operation(l.second,r.second)};
    }

    static Element inverse(const Element& v) {
        return {G::inverse(v.first),G::inverse(v.second)};
    }

    template <class U>
    static Element power(const Element& v,U exp) requires concepts::Powerable<G,U> {
        return {G::power(v.first,exp),G::power(v.second,exp)};
    }
};

} // namespace zawa
