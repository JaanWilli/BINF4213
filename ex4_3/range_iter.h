#ifndef EX4_3_RANGE_ITER_H
#define EX4_3_RANGE_ITER_H

class range_iter {
private:
    int cur;

public:
    explicit range_iter(int cur) : cur(cur) {}

    int operator*() const {
        return cur;
    }

    bool operator==(const range_iter &i) const {
        return cur == i.cur;
    }

    bool operator!=(const range_iter &i) const {
        return cur != i.cur;
    }

    range_iter& operator++()
    {
        ++cur;
        return *this;
    }
};

#endif //EX4_3_RANGE_ITER_H
