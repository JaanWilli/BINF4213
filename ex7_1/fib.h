#ifndef EX7_1_FIB_H
#define EX7_1_FIB_H

template<int N>
struct t_fib {
    static const int res = t_fib<N-1>::res + t_fib<N-2>::res;
};

template<>
struct t_fib<1> {
    static const int res = 1;
};

template<>
struct t_fib<0> {
    static const int res = 0;
};


constexpr int c_fib(int n) {
    return (n < 2) ? n : c_fib(n-1) + c_fib(n-2);
}

#endif //EX7_1_FIB_H
