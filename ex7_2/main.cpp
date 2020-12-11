#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "between.h"

using namespace std;

template<typename Iter>
int get_index(Iter fst, Iter cur) {
    return std::distance(fst, cur);
}

template<typename Iter>
void check_between(Iter begin, Iter fst, Iter lst, Iter i) {
    bool isBetween = between(fst, lst, i);
    cout << "Index " << get_index(begin, i) << " is " << (isBetween ? "" : "not ") << "between Index " <<
         get_index(begin, fst) << " and " << get_index(begin, lst) << endl;
}

int main() {

    list<int> l = {1, 2, 3, 4, 5, 6, 7, 8};

    auto l_fst = l.begin();
    auto l_lst = next(l_fst, 4);
    auto l_i = next(l_fst, 2);

    cout << "List test (positive) ";
    check_between(l.begin(), l_fst, l_lst, l_i);

    cout << "---------" << endl;

    advance(l_i, 3);

    cout << "List test (negative) ";
    check_between(l.begin(), l_fst, l_lst, l_i);

    cout << "---------" << endl;

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    auto v_fst = v.begin();
    auto v_lst = next(v_fst, 4);
    auto v_i = next(v_fst, 2);

    cout << "Vector test (positive) ";
    check_between(v.begin(), v_fst, v_lst, v_i);

    cout << "---------" << endl;

    advance(v_i, 3);

    cout << "Vector test (negative) ";
    check_between(v.begin(), v_fst, v_lst, v_i);

    cout << "---------" << endl;

    set<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    auto s_fst = s.begin();
    auto s_lst = next(s_fst, 4);
    auto s_i = next(s_fst, 2);

    cout << "Set test (positive) ";
    check_between(s.begin(), s_fst, s_lst, s_i);

    cout << "---------" << endl;

    advance(s_i, 3);

    cout << "Set test (negative) ";
    check_between(s.begin(), s_fst, s_lst, s_i);
}