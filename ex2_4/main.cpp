#include <iostream>
#include "playfield.h"

int main() {

    playfield p;

    int in;
    for (;;) {
        std::cin >> in;
        p.insert(in, 1);
        p.print();
    }
    p.print();
}
