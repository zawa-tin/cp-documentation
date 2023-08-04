#pragma once

namespace zawa {

template <class T1, class T2>
bool Chmax(T1& fr, const T2& bk) {
    return fr < bk and (fr = bk, true);
}

} // namespace zawa
