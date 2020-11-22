#include <iostream>
#include "jan_playfield.h"
#include "game.h"
#include "player.h"
#include "human_player.h"
#include "jan_player.h"

#include <memory>

using namespace std;

typedef playfield_traits<playfield> PT;

int main() {

    auto p1 = human_player(1);
    auto p2 = jan_player(2);
    auto field = jan_playfield();

    int current = 1;

    while (PT::is_not_full(field)) {
        field.print();
        std::cout << "It is player " << current << "'s turn: ";

        if (current == playfield::player1) {
            int column = p1.play(field);
            field.insert(column, playfield::player1);
        }
        else if (current == playfield::player2) {
            int column = p2.play(field);
            field.insert(column, playfield::player2);
        }

        std::cout << std::endl;

        if (PT::has_won(field, current)) {
            field.print();
            std::cout << "Player " << current << " won!" << std::endl;
            return 0;
        }

        current = PT::next_player(current);
    }
    std::cout << "It's a draw..." << std::endl;
}
