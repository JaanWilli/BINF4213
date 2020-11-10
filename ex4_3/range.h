#ifndef EX4_3_RANGE_H
#define EX4_3_RANGE_H

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

    range_iter& operator++() {
        ++cur;
        return *this;
    }
};

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
