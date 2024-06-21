#pragma once

#include "../Real.hpp"
#include "../Point.hpp"
#include "../Line.hpp"
#include "../Circle.hpp"
#include "../Distance/PointAndPoint.hpp"

#include <vector>

namespace zawa {

namespace geometryR2 {

    std::vector<Line> CommonTangentBetweenCircles(const Circle& c0, const Circle& c1) {
        std::vector<Line> res;
        if (c0.center() == c1.center()) {
            return res; 
        }
        res.reserve(4);
        Real g{Distance(c0.center(), c1.center())};
        Vector u{Vector{c1.center() - c0.center()}.normalized()};
        Vector v{u.rotated(PI / Real{2})};
        for (i32 s : { -1, 1 }) {
            Real h{(c0.radius() + c1.radius() * s) / g};
            if (Equal(Square(h), Real{1})) {
                res.emplace_back(c0.center() + (Positive(h) ? u : -u) * c0.radius(),
                        c0.center() + (Positive(h) ? u : -u) * c0.radius() + v);
                                    
            }
            else if (Smaller(Square(h), Real{1})) {
                Point U{u * h}, V{v * Sqrt(Real{1} - Square(h))};
                res.emplace_back(c0.center() + (U + V) * c0.radius(),
                        c1.center() - (U + V) * (c1.radius() * s));
                res.emplace_back(c0.center() + (U - V) * c0.radius(),
                        c1.center() - (U - V) * (c1.radius() * s));
            }
        }
        return res;
    }

} // namespace geometryR2

} // namespace zawa
