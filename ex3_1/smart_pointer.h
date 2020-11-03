#ifndef EX3_1_SMART_POINTER_H
#define EX3_1_SMART_POINTER_H

#include <iostream>

template<typename T>
class smart_pointer {

    T *t;
    int *c;

    inline void add_one() {
        ++(*c);
    }

    inline void remove_one() {
        --(*c);
        if ((*c) <= 0) {
            delete t;
            delete c;
        }
    }

public:

    explicit smart_pointer(T *t) : t(t) {
        c = new int(1);
    }

    smart_pointer(const smart_pointer<T>& p) : t(p.t), c(p.c) {
        add_one();
    }

    ~smart_pointer() {
        remove_one();
    }

    int counter() {
        return *c;
    }

    T& operator*() {
        return *t;
    }

    T* operator->() {
        return t;
    }

    smart_pointer<T>& operator=(const smart_pointer<T> &p) {
        if (this == &p)
            return *this;
        remove_one();
        t = p.t;
        c = p.c;
        add_one();
        return *this;
    }
};

#endif //EX3_1_SMART_POINTER_H
