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

ostream &operator<<(ostream &os, aspolar a) {

    double radius = abs(a.c);
    double theta = atan((a.c.imag() / a.c.real()));

    if (a.c.real() < 0) theta += M_PI;
    if (theta < 0) theta = 2 * M_PI + theta;

    if (a.f == a.DEG)
        os << "Radius = " << radius << ", Theta = " << (theta * 180 / M_PI) << " degrees";
    else
        os << "Radius = " << radius << ", Theta = " << theta << " radians";
}

int main() {
    complex<double> c(3,4);
    cout << "Complex: " << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "i" << endl;

    cout << aspolar(c, aspolar::DEG) << endl;
    cout << aspolar(c) << endl;
}
