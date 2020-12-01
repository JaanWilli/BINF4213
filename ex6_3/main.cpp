#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

struct aspolar {

    enum Flag {
        RAD,
        DEG
    };
    const complex<double> c;
    Flag f = Flag::RAD;

    explicit aspolar(const complex<double> c) : c(c) {}
    explicit aspolar(const complex<double> c, Flag flag) : c(c), f(flag) {}
};

inline ostream &operator<<(ostream &os, aspolar a) {

    double rad = atan((a.c.imag() / a.c.real())) + ((a.c.real() < 0) ? M_PI : 0);

    if (a.f == a.DEG)
        os << "Degrees: " << (rad * 180 / M_PI);
    else
        os << "Radians: " << rad;
}

int main() {
    complex<double> c(3,4);
    cout << "Complex: " << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "i" << endl;
    cout << aspolar(c, aspolar::DEG) << endl;
    cout << aspolar(c) << endl;
}
