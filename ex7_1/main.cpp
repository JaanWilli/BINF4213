#include <iostream>

#include "gcd.h"
#include "fib.h"

using namespace std;

int main() {

    cout << "gcd(60, 24) = " << t_gcd<60, 24>::res << endl;
    cout << "gcd(8, 18) = " << t_gcd<8, 18>::res << endl;

    cout << "-----" << endl;

    cout << "gcd(60, 24) = " << c_gcd(60, 24) << endl;
    cout << "gcd(8, 18) = " << c_gcd(8, 18) << endl;

    cout << "-----" << endl;

    cout << "fib(1) = " << t_fib<1>::res << endl;
    cout << "fib(7) = " << t_fib<7>::res << endl;

    cout << "-----" << endl;

    cout << "fib(1) = " << c_fib(1) << endl;
    cout << "fib(7) = " << c_fib(7) << endl;
    return 0;
}
