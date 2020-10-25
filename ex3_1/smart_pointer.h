#ifndef EX3_1_SMART_POINTER_H
#define EX3_1_SMART_POINTER_H

#include <iostream>

template<typename T>
class smart_pointer {

    T *t;
    int *c;

    inline void acquire()
    {
        ++(*c);
    }

    inline void release()
    {
        if (--(*c) <= 0) {
            delete t;
            delete c;
        }
    }

    friend std::ostream& operator <<(std::ostream& os, smart_pointer<T>& p)
    {
        os << '(' << "address: " << (void*)p.t << ", " << "count: " << *p.c << ')';
        return os;
    }

public:

    smart_pointer(T *t) : t(t) {
        c = new int(1);
    }

    smart_pointer(const smart_pointer<T>& p) : t(p.t), c(p.c)
    {
        acquire();
    }

    ~smart_pointer()
    {
        release();
    }

    T& operator*() {
        return *t;
    }

    T* operator->() {
        return t;
    }
};

#endif //EX3_1_SMART_POINTER_H
