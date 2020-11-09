#ifndef EX4_3_RANGE_H
#define EX4_3_RANGE_H

#include "range_iter.h"

class range {
private:
    const int low;
    const int high;

public:
    range(int l, int h) : low(l), high(h) {}

    range_iter begin() const {
        return range_iter(low);
    }

    range_iter end() const {
        return range_iter(high);
    }
};

#endif //EX4_3_RANGE_H
