#include <iostream>
#include "playfield.h"
#include "playfield_traits.h"
#include "game.h"
#include "human_player.h"
#include "jan_player.h"
#include "complayer.h"

using namespace std;

template<typename P1, typename P2>
void start_game(P1 p1, P2 p2) {
    game<playfield, P1, P2> g(p1, p2);
    g.play();
}

int main() {
    complayer<playfield> opp = {2};
    start_game(jan_player<playfield>(1), opp);
}
