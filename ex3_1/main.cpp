#include <iostream>
#include <list>

#include "dumb_pointer.h"
#include "smart_pointer.h"

using namespace std;

template<typename T>
void pass_smart_pointer(smart_pointer<T> p)
{
    cout << ">>> p_pass: " << p << endl << endl;
}

int main() {

    smart_pointer<list<int>> p(new list<int>());
    p->push_back(1);
    p->push_back(2);
    cout << ">>> p:      " << p << endl << endl;

    list<int> l_new = *p;
    cout << ">>> l:      " << p->size() << endl;
    cout << "    l_new:  " << l_new.size() << endl << endl;

    pass_smart_pointer(p);

    cout << ">>> p:      " << p << endl << endl;
}
