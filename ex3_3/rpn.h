#ifndef EX3_3_RPN_H
#define EX3_3_RPN_H

#include <iostream>
#include "minmax_traits.h"
#include "../ex2_1/pvector.h"

template<typename T, typename C=minmax_traits<T>>
class RPN {
    pvector<T> stack;

public:

    RPN() : stack("stack.txt") {}

    void push(T el) {
        stack.push_back(el);
    }

    T pop() {
        T el = stack.back();
        stack.pop_back();
        return el;
    }

    void print() {
        if (stack.size() == 0) cout << "1:\t--" << endl;
        for (int i = 0; i < stack.size(); i++) {
            cout << i+1 << ":\t" << stack.at(i) << " " << endl;
        }
    }

    void add() {
        if (stack.size() < 2) return;
        push(pop() + pop());
    }
    void subtract() {
        if (stack.size() < 2) return;
        push(pop() - pop());
    }
    void multiply() {
        if (stack.size() < 2) return;
        push(pop() * pop());
    }
    void divide() {
        if (stack.size() < 2) return;
        push(pop() / pop());
    }
    void min() {
        if (stack.size() < 2) return;
        push(C::min(pop(), pop()));
    }
    void max() {
        if (stack.size() < 2) return;
        push(C::max(pop(), pop()));
    }
};


#endif //EX3_3_RPN_H
