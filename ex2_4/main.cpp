#include <iostream>
#include "playfield.h"

using namespace std;

int next_player(int current) {
    return current % 2 + 1;
}

bool has_won(playfield p, int pl) {
    for (int i = 0; i < playfield::height; ++i) {
        for (int j = 0; j < playfield::width; ++j) {
            if (p.stoneat(j,i) == pl && p.stoneat(j,i+1) == pl && p.stoneat(j,i+2) == pl && p.stoneat(j,i+3) == pl) {
                return true;
            }
            if (p.stoneat(j,i) == pl && p.stoneat(j+1,i+1) == pl && p.stoneat(j+2,i+2) == pl && p.stoneat(j+3,i+3) == pl) {
                return true;
            }
            if (p.stoneat(j,i) == pl && p.stoneat(j+1,i) == pl && p.stoneat(j+2,i) == pl && p.stoneat(j+3,i) == pl) {
                return true;
            }
            if (p.stoneat(j,i) == pl && p.stoneat(j-1,i-1) == pl && p.stoneat(j-2,i-2) == pl && p.stoneat(j-3,i-3) == pl) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    playfield p;
    int player = 1;

    int in;
    for (;;) {
        cout << "It it player " << player << "'s turn: ";
        cin >> in;
        cout << endl;
        p.insert(in, player);
        p.print();

        if(has_won(p, player)) {
            cout << "Player " << player << " won!" << endl;
            return 0;
        }
        else {
            player = next_player(player);
        }
    }
}
