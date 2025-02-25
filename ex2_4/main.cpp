#include <iostream>
#include "playfield.h"
#include "util.h"
#include "game.h"
#include "human_player.h"

using namespace std;

template<typename P1, typename P2>
void start_game(P1 p1, P2 p2) {
    game<playfield, P1, P2> g(p1, p2);
    g.play();
}

int main() {
    start_game(human_player<playfield>(1), human_player<playfield>(2));
}
