#pragma once

#include "./TypeAlias.hpp"

namespace zawa {

i32 supi{ (1 << 30) - 1 };
i64 supl{ (1LL << 62) - 1 };
i32 infi{ -supi };
i64 infl{ -supl };

void SetSupi(i32 value) {
    supi = value;
}

void SetSupl(i64 value) {
    supl = value;
}

void SetInfi(i32 value) {
    infi = value;
}

void SetInfl(i64 value) {
    infl = value;
}

} // namespace zawa
