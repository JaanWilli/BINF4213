#ifndef EX3_2_PSET_H
#define EX3_2_PSET_H

#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include "persistence_traits.h"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pset : public set<T> {
    string f;

    void read() {
        ifstream ifs(f);
        for(;;) {
            T el;
            P::read(ifs, el);
            if (!ifs.good()) break;
            set<T>::insert(el);
        }
    }

    void write() {
        ofstream ofs(f);
        for (const T& t : *this) {
            P::write(ofs, t);
        }
    }


public:
    pset(string file) : f(file) {
        read();
    }
    ~pset() {
        write();
    }
};

#endif //EX3_2_PSET_H
