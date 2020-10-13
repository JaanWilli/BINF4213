#include <iostream>
#include <stack>
#include <sstream>
#include "rpn.h"
#include "../ex1_2/fraction.h"

using namespace std;

int main() {

    RPN<int> rpn_int;
    int in_int;

    while(true) {

        cout << "Command: ";
        string line;
        getline(cin, line);
        istringstream is(line);

        while(is) {
            string c;
            is >> c;

            if (c == "n") {
                is >> in_int;
                rpn_int.push(in_int);
            }
            else if (c == "+") {
                rpn_int.add();
            }
            else if (c == "-") {
                rpn_int.subtract();
            }
            else if (c == "*") {
                rpn_int.multiply();
            }
            else if (c == "/") {
                rpn_int.divide();
            }
            else if (c == "min") {
                rpn_int.min();
            }
            else if (c == "max") {
                rpn_int.max();
            }
            else if (c == "d") {
                rpn_int.pop();
            }
            else if (c == "q") {
                return 0;
            }
        }
        rpn_int.print();
    }
}
