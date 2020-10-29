#include <iostream>
#include <list>

#include "dumb_pointer.h"
#include "smart_pointer.h"

using namespace std;

class C {
public: int x;
    explicit C(int x) : x(x) {}
    void add() {++x;}
};

void print(smart_pointer<C> p) {
    cout << p.counter() << ": " <<  p << endl;
}

void dumb_test() {
    cout << "Dumb Pointer Test:" << endl;

    C *c = new C(1);
    dumb_pointer<C> p = c;

    cout << p << endl;
    cout << p -> x << endl;
}

void smart_test() {
    cout << "Smart Pointer Test:" << endl;

    C *c1 = new C(1);
    C *c2 = new C(2);

    smart_pointer<C> p(c1);
    cout << p.counter() << endl;

    smart_pointer<C> q(p);
    cout << p.counter() << endl;
    cout << q.counter() << endl;

    smart_pointer<C> r(c2);
    cout << r.counter() << endl;

    cout << "---" << endl;

    q = r;
    cout << p.counter() << endl;
    cout << q.counter() << endl;
    cout << r.counter() << endl;

    cout << "---" << endl;

    print(p);
    print(q);
    print(r);

    p->add();
    cout << p->x << endl;
    q->add();
    cout << q->x << endl;
    r->add();
    cout << r->x << endl;
}

int main() {
    dumb_test();

    cout << "----------------------------------" << endl << endl;

    smart_test();
}
