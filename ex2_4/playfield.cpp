#include <iostream>
#include "playfield.h"

using namespace std;

playfield::playfield() {
    std::fill(&rep[0][0], &rep[0][0] + width * height, (int)none);
}

int playfield::stoneat(int x, int y) const {
    return rep[x][y];
}

void playfield::insert(int x, int player) {
    x--;
    int y = height - 1;
    while (rep[x][y] != none) y--;
    rep[x][y] = player;
}

void playfield::print() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << "| " << stoneat(j,i) << " ";
        }
        cout << "|" << endl << "-----------------------------" << endl;
    }
}