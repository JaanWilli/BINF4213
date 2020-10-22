#ifndef EX3_3_MINMAX_TRAITS_H
#define EX3_3_MINMAX_TRAITS_H

#include <complex>

using namespace std;

template<typename T>
struct minmax_traits {

    static T min(T a, T b) {
        return a < b ? a : b;
    }

    static T max(T a, T b) {
        return a > b ? a : b;
    }
};

template<typename T>
struct minmax_traits<complex<T>> {

    static complex<T> min(complex<T> a, complex<T> b) {
        return norm(a) < norm(b) ? a : b;
    }

    static complex<T> max(complex<T> a, complex<T> b) {
        return norm(a) > norm(b) ? a : b;
    }
};

#endif //EX3_3_MINMAX_TRAITS_H
