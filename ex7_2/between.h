#ifndef EX7_2_BETWEEN_H
#define EX7_2_BETWEEN_H

#include <iostream>

using namespace std;

template<typename Iter>
using IterCategory = typename std::iterator_traits<Iter>::iterator_category;

template<typename Iter>
using hasRA = is_base_of<random_access_iterator_tag, IterCategory<Iter>>;

template<typename Iter>
typename enable_if<hasRA<Iter>::value, bool>::type
between(Iter fst, Iter lst, Iter i) {
    cout << "(RA):" << endl;
    return fst <= i && i <= lst;
}

template<typename Iter>
typename enable_if<!hasRA<Iter>::value, bool>::type
between(Iter fst, Iter lst, Iter i) {
    cout << "(F)" << endl;
    while (fst != i) {
        if (fst == lst) {
            return false;
        }
        ++fst;
    }
    return true;
}


#endif //EX7_2_BETWEEN_H