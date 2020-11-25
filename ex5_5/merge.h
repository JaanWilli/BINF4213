#ifndef EX4_4_MERGE_H
#define EX4_4_MERGE_H

#include <algorithm>
#include "merge_traits.h"

using namespace std;

template<typename C1, typename C2, typename R>
void merge(C1 &a, C2 &b, R &r) {

    std::merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(r));
}

template<typename C1, typename C2, typename T>
void merge(C1 &a, C2 &b, set<T> &r) {

    std::merge(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
}

template<typename T>
void merge(map<T, T> &a, map<T, T> &b, map<T, T> &r) {

    std::merge(a.begin(), a.end(), b.begin(), b.end(), inserter(r, r.end()));
}

template<typename C1, typename C2, typename T>
void merge(C1 &a, C2 &b, map<T, T> &r) {

    for (auto el : a)
        r.insert(pair(el, el));
    for (auto el : b)
        r.insert(pair(el, el));
}

template<typename T>
void merge(forward_list<T> &a, forward_list<T> &b, forward_list<T> &r) {

    r.merge(a);
    r.merge(b);
}

template<typename C1, typename C2, typename T>
void merge(C1 &a, C2 &b, forward_list<T> &r) {

    for (auto el : a)
        r.push_front(el);
    for (auto el : b)
        r.push_front(el);
}

#endif //EX4_4_MERGE_H
