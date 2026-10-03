#pragma once

#include "../Template/TypeAlias.hpp"

#include <iterator>
#include <vector>

namespace zawa {

template <class T>
std::vector<T> FindLinearRecurrence(const std::vector<T>& A) {
    const i32 N=std::ssize(A);
    std::vector<T> Q{1};
    i32 L=0;
    std::vector<T> B{1};
    i32 n0=-1;
    T b=1;
    for (i32 n = 0 ; n < N ; n++) {
        T delta=0;
        for (i32 i = 0 ; i < std::ssize(Q) ; i++) 
            delta+=Q[i]*A[n-i];
        if (delta==0)
            continue;
        i32 Lnew=(2*L<=n?n+1-L:L);
        std::vector<T> Qnew=Q;
        Qnew.resize(Lnew+1);
        T c=delta/b;
        for (i32 i = 0 ; i < std::ssize(B) ; i++)
            Qnew[n-n0+i]-=c*B[i];
        if (2*L<=n) {
            std::swap(B,Q);
            n0=n;
            b=delta;
        }
        L=Lnew;
        Q=std::move(Qnew);
    }
    std::vector<T> res(std::ssize(Q)-1);
    for (u32 i = 1 ; i < Q.size() ; i++)
        res[i-1]=-Q[i];
    return res;
}

} // namespace zawa
