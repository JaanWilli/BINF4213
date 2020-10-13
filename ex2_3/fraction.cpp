#include "fraction.h"

int gcf(int a, int b) {
    if (b == 0) return a;
    else return gcf(b, a%b);
}

int lcm(int a, int b) {
    return a*b / gcf(a,b);
}

fraction fraction::operator+(fraction f) {
    int dnm = lcm(d, f.d);
    int cnt = c * dnm / d + f.c * dnm / f.d;
    return fraction(cnt, dnm);
}

fraction fraction::operator-(fraction f) {
    int dnm = lcm(d, f.d);
    int cnt = c * dnm / d - f.c * dnm / f.d;
    return fraction(cnt, dnm);
}

fraction fraction::operator*(fraction a) {
    int f1 = gcf(a.c, d);
    int f2 = gcf(c, a.d);

    return fraction(a.c / f1 * c / f2, a.d / f2 * d / f1);
}

fraction fraction::operator/(fraction f) {
    int f1 = gcf(c, f.c);
    int f2 = gcf(f.d, d);

    return fraction((c / f1) * (f.d / f2), (d / f2 * (f.c / f1)));
}

std::ostream& operator<<(std::ostream& o, fraction f) {
    if (f.d == 1) o << f.c;
    else o << '(' << f.c << '/' << f.d << ')';
    return o;
}

std::istream& operator>>(std::istream& i, fraction& f) {
    int cnt, dnm;
    char c;

    i >> c;
    i >> cnt;
    i >> c;
    i >> dnm;
    i >> c;

    f = fraction(cnt, dnm);

    return i;
}

bool fraction::operator<(fraction f) {
    int denom = lcm(d, f.d);
    return c * denom / d < f.c * denom / f.d;
}

bool fraction::operator>(fraction f) {
    int denom = lcm(d, f.d);
    return c * denom / d > f.c * denom / f.d;
}