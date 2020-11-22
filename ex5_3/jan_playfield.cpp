#include <iostream>
#include "jan_playfield.h"

using namespace std;

jan_playfield::jan_playfield() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            rep[i][j] = none;
        }
    }
}

int jan_playfield::stoneat(int x, int y) const {
    if (x >= 0 && x < jan_playfield::width && y >= 0 && y < jan_playfield::height)
        return rep[x][y];
    else
        return none;
}

std::string jan_playfield::stone_repr(int x, int y) const {
    int stone = rep[x][y];
    if (stone == 0)
        return " ";
    else if (stone == 1)
        return "\e[91mx\e[0m";
    else if (stone == 2)
        return "\e[30mx\e[0m";
}

void jan_playfield::insert(int x, int player) {
    if (playfield_traits<jan_playfield>::is_playable(*this, x)) {
        int y = height - 1;
        while (rep[x][y] != none) y--;
        rep[x][y] = player;
    }
}

void jan_playfield::print() const {
    cout << "  1   2   3   4   5   6   7" << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << "| " << stone_repr(j,i) << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}