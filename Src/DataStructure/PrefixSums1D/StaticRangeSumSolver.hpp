#pragma once

#include "../../Algebra/Group/AdditiveGroup.hpp"
#include "./PrefixSums1D.hpp"

namespace zawa {

    template <class T>
    using StaticRangeSumSolver = PrefixSums1D<AdditiveGroup<T>>;

    template <class T>
    using Ruisekiwa = PrefixSums1D<AdditiveGroup<T>>;

};
