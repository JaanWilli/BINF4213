#ifndef EX3_2_PVECTOR_H
#define EX3_2_PVECTOR_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "persistence_traits.h"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pvector : public vector<T> {
    string f;

    void read() {
        ifstream ifs(f);
        for(;;) {
            T el;
            P::read(ifs, el);
            if (!ifs.good()) break;
            vector<T>::push_back(el);
        }
    }

    void write() {
        ofstream ofs(f);
        for (const T& t : *this) {
            P::write(ofs, t);
        }
    }


public:
    pvector(string file) : f(file) {
        read();
    }
    ~pvector() {
        write();
    }
};

#endif //EX3_2_PVECTOR_H
