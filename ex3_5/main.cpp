#include <iostream>
#include "playfield.h"
#include "game.h"
#include "human_player.h"
#include "jan_player.h"
#include "dominique_player.h"
#include "vincent_player.h"
#include "remy_player.h"

using namespace std;

template<typename P1, typename P2>
void start_game(P1 p1, P2 p2) {
    game<playfield, P1, P2> g(p1, p2);
    g.play();
}

int main() {
    jan_player<playfield> jan = {1};

    human_player<playfield> human = {2};

    dominique_player<playfield> dominique = {2};
    vincent_player<playfield> vincent = {2};
    remy_player<playfield> remy = {2};
    start_game(jan, dominique);
}
