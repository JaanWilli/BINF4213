#include <iostream>
#include "jan_playfield.h"
#include "game.h"
#include "human_player.h"
#include "jan_player.h"

using namespace std;

typedef playfield_traits<playfield> PT;

template<typename P1, typename P2>
void play(jan_playfield &field, P1 p1, P2 p2) {
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
            return;
        }

        current = PT::next_player(current);
    }
    std::cout << "It's a draw..." << std::endl;
}

int main() {

    auto field = jan_playfield();
    play(field, human_player(1), jan_player(2));
}
