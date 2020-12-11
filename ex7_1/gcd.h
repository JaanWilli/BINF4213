#ifndef EX7_1_GCD_H
#define EX7_1_GCD_H

/*
while b != 0
    b = a mod b
    a = old_b
*/

template<int A, int B>
struct t_gcd {
    static const int res = t_gcd<B, A % B>::res;
};

template<int A>
struct t_gcd<A, 0> {
    static const int res = A;
};


constexpr int c_gcd(int a, int b) {
    return (b == 0) ? a : c_gcd(b, a % b);
}

#endif //EX7_1_GCD_H
