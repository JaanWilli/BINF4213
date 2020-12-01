#ifndef EX6_2_PERSISTENCE_TRAITS_H
#define EX6_2_PERSISTENCE_TRAITS_H

#include <iostream>

using namespace std;

template<typename T>
struct persistence_traits {

    static void read(ifstream &ifs, T &el) {
        ifs >> el;
    }

    static void write(ofstream &ofs, const T &el) {
        ofs << el << endl;
    }
};

template<>
struct persistence_traits<string> {

    static void read(ifstream &ifs, string &s) {
        getline(ifs, s);
    }

    static void write(ofstream &ofs, const string &s) {
        ofs << s << endl;
    }
};

#endif //EX6_2_PERSISTENCE_TRAITS_H
