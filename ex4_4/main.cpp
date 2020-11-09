#include <iostream>

#include <list>
#include <string>
#include <vector>
#include <set>

#include "merge.h"

template<typename T>
void print(const T &t) {
    for (auto el : t) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 3, 2};

    merge<int>(v1, v2);
    print(v1);

    set<int> s1 = {1, 2, 3};
    set<int> s2 = {4, 3, 2};

    merge<int>(s1, s2);
    print(s1);

    list<int> l1 = {1, 2, 3};
    list<int> l2 = {4, 3, 2};

    merge<int>(l1, l2);
    print(l1);
}
