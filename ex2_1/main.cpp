#include "pvector.h"
#include "fraction.h"
#include <iostream>

int main() {

    pvector<fraction> vf("fractions.txt");
    pvector<int> vi("integers.txt");

    cout << "current list: ";
    for (int i = 0; i < vf.size(); i++) {
        cout << vf.at(i) << " ";
    }
    cout << endl;

    fraction f;
    cout << "add another fraction to list: ";
    cin >> f;
    vf.push_back(f);

    cout << "new list: ";
    for (int i = 0; i < vf.size(); i++) {
        cout << vf.at(i) << " ";
    }
    cout << endl;

    //--------------------------

    cout << "current list: ";
    for (int j = 0; j < vi.size(); j++) {
        cout << vi.at(j) << " ";
    }
    cout << endl;

    int i;
    cout << "add integer to list: ";
    cin >> i;
    vi.push_back(i);

    cout << "new list: ";
    for (int j = 0; j < vi.size(); j++) {
        cout << vi.at(j) << " ";
    }
    cout << endl;

    return 0;
}
