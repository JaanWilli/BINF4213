#ifndef EX4_5_BETWEEN_H
#define EX4_5_BETWEEN_H

#include <iostream>

using namespace std;

template<typename Iter>
bool betweenImpl(Iter fst, Iter lst, Iter i, std::random_access_iterator_tag) {
    cout << "(RA):" << endl;
    return fst <= i && i <= lst;
}

template<typename Iter>
bool betweenImpl(Iter fst, Iter lst, Iter i, std::forward_iterator_tag) {
    cout << "(F)" << endl;
    while (fst != i) {
        if (fst == lst) {
            return false;
        }
        ++fst;
    }
    return true;
}

template<typename Iter>
bool between(Iter fst, Iter lst, Iter i) {
    typedef typename std::iterator_traits<Iter>::iterator_category category;
    return betweenImpl(fst, lst, i, category());
}


#endif //EX4_5_BETWEEN_H
