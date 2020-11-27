#ifndef EX4_4_MERGE_H
#define EX4_4_MERGE_H

#include <algorithm>

using namespace std;

template<typename C1, typename C2, typename R>
void merge(C1 a, C2 b, R &r) {

    std::merge(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
}

template<typename C1, typename C2, typename T>
void merge(C1 a, C2 b, forward_list<T> &r) {

    std::merge(a.begin(), a.end(), b.begin(), b.end(), front_inserter(r));
}

#endif //EX4_4_MERGE_H
