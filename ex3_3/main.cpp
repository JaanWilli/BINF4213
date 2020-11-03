#include <iostream>
#include <stack>
#include <sstream>
#include <complex>
#include "rpn.h"
#include "../ex1_2/fraction.h"

using namespace std;

template<typename T>
int run_rpn(RPN<T> &rpn) {
    T in;

    while(true) {

        cout << "Command: ";
        string line;
        getline(cin, line);
        istringstream is(line);

        while(is) {
            string c;
            is >> c;

            if (c == "n") {
                is >> in;
                rpn.push(in);
            }
            else if (c == "+") {
                rpn.add();
            }
            else if (c == "-") {
                rpn.subtract();
            }
            else if (c == "*") {
                rpn.multiply();
            }
            else if (c == "/") {
                rpn.divide();
            }
            else if (c == "min") {
                rpn.min();
            }
            else if (c == "max") {
                rpn.max();
            }
            else if (c == "d") {
                rpn.pop();
            }
            else if (c == "q") {
                return 0;
            }
        }
        rpn.print();
    }
}

int main(int argc, char *argv[]) {

    if (argc == 2) {
        string arg1(argv[1]);

        if (arg1 == "int") {
            RPN<int> rpn;
            run_rpn(rpn);
        }
        else if (arg1 == "fraction") {
            RPN<fraction> rpn;
            run_rpn(rpn);
        }
        else if (arg1 == "double") {
            RPN<double> rpn;
            run_rpn(rpn);
        }
        else if (arg1 == "complex") {
            RPN<complex<int>> rpn;
            run_rpn(rpn);
        }
    }
}
