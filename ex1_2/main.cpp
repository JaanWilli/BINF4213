#include "fraction.h"
#include <iostream>

using namespace std;

void static_test() {
    fraction f(1, 3);
    fraction g(3, 4);

    cout << "Performing some sample tests..." << endl;
    cout << f << " + " << g << " = " << f + g << endl;
    cout << f << " - " << g << " = " << f - g << endl;
    cout << f << " * " << g << " = " << f * g << endl;
    cout << f << " / " << g << " = " << f / g << endl;

    cout << f << " * " << 6 << " = " << f * 6 << endl;
    cout << f << " / " << 3 << " = " << f / 3 << endl;
}

[[noreturn]] void dynamic_test() {

    cout << "input example: (1/3) + (3/4)" << endl;
    for (;;) {
        fraction f,g;
        string o;

        cout << "--> ";
        if (!(cin >> f >> o >> g)) {
            cout << "Wrong format" << endl;
            cin.clear();
            continue;
        }

        if (o == "+")
            cout << f + g << endl;
        else if (o == "-")
            cout << f - g << endl;
        else if (o == "*")
            cout << f * g << endl;
        else if (o == "/")
            cout << f / g << endl;
        else
            cout << "Wrong operator";
    }
}


int main(int argc, char* argv[]) {

    if (argc <= 1) {
        cout << "available arguments: [-s] or [-i]" << endl;
    }
    else if (argc > 2) {
        cout << "Too many arguments" << endl;
    }
    else {
        string arg = argv[1];
        if (arg == "-s") static_test();
        else if (arg == "-i") dynamic_test();
    }
}
