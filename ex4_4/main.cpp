#include <iostream>

#include <list>
#include <forward_list>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "merge.h"

template<typename T>
void print(const T &t) {
    for (auto el : t) {
        cout << el << " ";
    }
    cout << endl;
}

template<typename T>
void print(const map<T, T> &t) {
    for (auto el : t) {
        cout << el.first << ":" << el.second << " ";
    }
    cout << endl;
}


int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {3, 4, 5};

    vector<int> v = merge<int>(v1, v2);
    cout << "Vector: ";
    print(v);

    //---------------------------------------

    set<int> s1 = {1, 2, 3};
    set<int> s2 = {3, 4, 5};

    set<int> s = merge<int>(s1, s2);
    cout << "Set: ";
    print(s);

    //---------------------------------------

    forward_list<int> l1 = {1, 2, 3};
    forward_list<int> l2 = {3, 4, 5};

    forward_list<int> l = merge<int>(l1, l2);
    l.reverse();
    cout << "List: ";
    print(l);

    //---------------------------------------

    map<int, int> m1 = {{1,10}, {2,20}, {3,30}};
    map<int, int> m2 = {{3,30}, {4,40}, {5,50}};

    map<int, int> m = merge<pair<int, int>>(m1, m2);
    cout << "Map: ";
    print(m);

    //---------------------------------------

    vector<int> v3 = {1, 2, 3};
    set<int> s3 = {3, 4, 5};
    list<int> l3 = {5, 6, 7};

    vector<int> vs = merge<int>(v3, s3);
    vector<int> vsl = merge<int>(vs, l3);

    cout << "Vector, Set, List: ";
    print(vsl);
}
