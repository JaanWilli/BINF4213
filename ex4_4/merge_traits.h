#ifndef EX4_4_MERGE_TRAITS_H
#define EX4_4_MERGE_TRAITS_H

#include <list>
#include <vector>

using namespace std;

template<typename C, typename T>
struct merge_traits {
    static void merge(C &c, const T t) {
        c.insert(t);
    }
};

template<typename T>
struct merge_traits<vector<T>, T> {
    static void merge(vector<T> &v, const T t) {
        v.push_back(t);
    }
};

template<typename T>
struct merge_traits<list<T>, T> {
    static void merge(list<T> &l, const T t) {
        l.push_back(t);
    }
};

#endif //EX4_4_MERGE_TRAITS_H
