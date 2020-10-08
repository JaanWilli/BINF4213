#ifndef EX1_2_FRACTION_H
#define EX1_2_FRACTION_H

#include <iostream>

class fraction {

    int c,d;

    friend std::ostream& operator<<(std::ostream& o, fraction f);
    friend std::istream& operator>>(std::istream& i, fraction& f);

public:

    fraction(int cnt = 0, int dnm = 1) :
            c(cnt), d(dnm)
    { /*void*/ }

    fraction operator+(fraction f);
    fraction operator-(fraction f);
    fraction operator*(fraction f);
    fraction operator/(fraction f);
};

#endif //EX1_2_FRACTION_H
