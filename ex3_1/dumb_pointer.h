#ifndef EX3_1_DUMB_POINTER_H
#define EX3_1_DUMB_POINTER_H

#include <iostream>

template<typename T>
class dumb_pointer {

    T *t;

    friend std::ostream& operator <<(std::ostream& os, dumb_pointer<T>& p)
    {
        os << '(' << "address: " << (void*)p.t << ')';
        return os;
    }

public:

    dumb_pointer(T *t) : t(t) {}

    ~dumb_pointer() {
        delete t;
    }

    T& operator*() {
        return *t;
    }

    T* operator->() {
        return t;
    }
};

#endif //EX3_1_DUMB_POINTER_H
