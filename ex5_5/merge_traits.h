#ifndef EX4_4_MERGE_TRAITS_H
#define EX4_4_MERGE_TRAITS_H

#include <list>
#include <vector>
#include <forward_list>

using namespace std;

template<typename C, typename T>
struct merge_traits {
    static void merge(C &c, const T t) {
        c.insert(c.end(), t);
    }
};

template<typename T>
struct merge_traits<forward_list<T>, T> {
    static void merge(forward_list<T> &l, const T t) {
        l.push_front(t);
    }
};


#endif //EX4_4_MERGE_TRAITS_H
