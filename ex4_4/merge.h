#ifndef EX4_4_MERGE_H
#define EX4_4_MERGE_H

#include "merge_traits.h"

using namespace std;

template<typename T, typename C1, typename C2, typename M=merge_traits<C1, T>>
void merge(C1 &a, C2 &b) {
    for (T t : b) {
        M::merge(a,t);
    }
}



#endif //EX4_4_MERGE_H
