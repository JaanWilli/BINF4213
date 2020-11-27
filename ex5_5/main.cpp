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
    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {5, 4, 6};
    list<int> l1 = {1, 2, 3};
    list<int> l2 = {3, 4, 5};
    set<int> s1 = {1, 2, 3};
    set<int> s2 = {3, 4, 5};
    map<int, int> m1 = {{1,10}, {2,20}, {3,30}};
    map<int, int> m2 = {{3,30}, {4,40}, {2,20}};
    forward_list<int> fl1 = {1, 2, 3};
    forward_list<int> fl2 = {5, 4, 6};

    vector<int> v;
    merge(v1, v2, v);
    print(v);

    list<int> l;
    merge(l1, l2, l);
    print(v);

    set<int> s;
    merge(s1, s2, s);
    print(s);

    map<int, int> m;
    merge(m1, m2, m);
    print(m);

    forward_list<int> fl;
    merge(fl1, fl2, fl);
    print(fl);
}
