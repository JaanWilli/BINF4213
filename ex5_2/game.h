#ifndef EX5_2_GAME_H
#define EX5_2_GAME_H

#include <iostream>
#include <memory>
#include "playfield.h"
#include "playfield_traits.h"
#include "player.h"

typedef playfield_traits<playfield> PT;

struct game {

    std::shared_ptr<jan_playfield> field;
    std::shared_ptr<player> player1;
    std::shared_ptr<player> player2;

    int current;

public:

    game(std::shared_ptr<jan_playfield> f, std::shared_ptr<player> p1, std::shared_ptr<player> p2) {
        field = f;
        player1 = p1;
        player2 = p2;
        current = 1;
    }

    void play() {

        while (PT::is_not_full(*field)) {
            field->print();
            std::cout << "It is player " << current << "'s turn: ";

            if (current == playfield::player1) {
                play_round(player1, playfield::player1);
            }
            else if (current == playfield::player2) {
                play_round(player2, playfield::player2);
            }

            std::cout << std::endl;

            if (PT::has_won(*field, current)) {
                field->print();
                std::cout << "Player " << current << " won!" << std::endl;
                return;
            }

            current = PT::next_player(current);
        }
        std::cout << "It's a draw..." << std::endl;
    }

    void play_round(std::shared_ptr<player> p, int player) {
        int column = p->play(*field);
        field->insert(column, player);
    }
};

#endif //EX5_2_GAME_H
