#ifndef EX4_4_MERGE_H
#define EX4_4_MERGE_H

#include "merge_traits.h"

using namespace std;

template<typename T, typename C1, typename C2, typename M=merge_traits<C1, T>>
C1 merge(C1 &a, C2 &b) {
    C1 res;
    for (T t : a) {
        M::merge(res, t);
    }
    for (T t : b) {
        M::merge(res, t);
    }
    return res;
}


#endif //EX4_4_MERGE_H
