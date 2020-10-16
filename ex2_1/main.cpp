#include "pvector.h"
#include "fraction.h"
#include <iostream>

template<typename T>
void print_vector(pvector<T> v) {

    cout << "list elements: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i+1 << ": " << v.at(i) << endl;
    }
}


int main() {

    pvector<fraction> vf("fractions.txt");
    print_vector(vf);

    fraction f;
    cout << "add fraction to list: ";
    cin >> f;
    vf.push_back(f);

    print_vector(vf);

    //--------------------------

    pvector<int> vi("integers.txt");
    print_vector(vi);

    int i;
    cout << "add integer to list: ";
    cin >> i;
    vi.push_back(i);

    print_vector(vi);

    //--------------------------

    pvector<string> vs("string.txt");
    print_vector(vs);

    string s;
    cout << "add string to list: ";
    cin >> s;
    vs.push_back(s);

    print_vector(vs);
}
