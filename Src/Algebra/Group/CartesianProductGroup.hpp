#pragma once

#include "./GroupConcept.hpp"
#include "../PowerableConcept.hpp"

#include <utility>

namespace zawa {

template <concepts::Group G1, concepts::Group G2 = G1>
class CartesianProductGroup {
public:

    using Element = std::pair<typename G1::Element,typename G2::Element>;

    static Element identity() {
        return {G1::identity(),G2::identity()};
    }

    static Element operation(const Element& l,const Element& r) {
        return {G1::operation(l.first,r.first),G2::operation(l.second,r.second)};
    }

    static Element inverse(const Element& v) {
        return {G1::inverse(v.first),G2::inverse(v.second)};
    }

    template <class U>
    static Element power(const Element& v,U exp) requires (concepts::Powerable<G1,U> and concepts::Powerable<G2,U>) {
        return {G1::power(v.first,exp),G2::power(v.second,exp)};
    }
};

} // namespace zawa
