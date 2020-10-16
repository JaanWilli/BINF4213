#ifndef EX2_3_RPN_H
#define EX2_3_RPN_H

#include <iostream>
#include "../ex2_1/pvector.h"

template<typename T>
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
        T a = stack.back(); pop(); T b = stack.back(); pop();
        push(a < b ? a : b);
    }
    void max() {
        if (stack.size() < 2) return;
        T a = stack.back(); pop(); T b = stack.back(); pop();
        push(a > b ? a : b);
    }
};


#endif //EX2_3_RPN_H
