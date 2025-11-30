#pragma once

#include "../../Algebra/Group/AdditiveGroup.hpp"
#include "./PrefixSum1D.hpp"

namespace zawa {

    template <class T>
    using StaticRangeSumSolver = PrefixSum1D<AdditiveGroup<T>>;

    template <class T>
    using Ruisekiwa = PrefixSum1D<AdditiveGroup<T>>;

};
