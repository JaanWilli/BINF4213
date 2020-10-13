#ifndef EX2_1_PVECTOR_H
#define EX2_1_PVECTOR_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class pvector {
    string f;
    vector<T> v;

    void read() {
        ifstream ifs(f);
        for(;;) {
            T el;
            ifs >> el;
            if (!ifs.good()) break;
            v.push_back(el);
        }
    }

    void write() {
        ofstream ofs(f);
        for (const T &el : v) {
            ofs << el << endl;
        }
    }


public:
    pvector(string file) : f(file) {
        read();
    }
    ~pvector() {
        write();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }
    void pop_back() {
        v.pop_back();
    }

    T back() {
        return v.back();
    }

    T at(int i) {
        return v.at(i);
    }

    int size() {
        return v.size();
    }
};

#endif //EX2_1_PVECTOR_H
