#include <iostream>
#include "pvector.h"
#include "pset.h"
#include "../ex1_2/fraction.h"


void pvector_int() {

    pvector<int> vi("integers.txt");

    for (const int &i : vi) {
        cout << i << endl;
    }

    int i;
    cout << "add integer to vector: ";
    cin >> i;
    vi.push_back(i);
}

void pvector_string() {

    pvector<string> vs("string.txt");

    for (const string &s : vs) {
        cout << s << endl;
    }

    string s;
    cout << "add string to vector: ";
    getline(cin, s); // to ignore \n
    getline(cin, s);
    vs.push_back(s);
}

void pset_int() {

    pset<int> pi("pset.txt");

    for (const int &i : pi) {
        cout << i << endl;
    }

    int i;
    cout << "add integer to set: ";
    cin >> i;
    pi.insert(i);
}

int main() {

    pvector_int();

    pvector_string();

    pset_int();
}
