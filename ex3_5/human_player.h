#ifndef EX2_4_HUMAN_PLAYER_H
#define EX2_4_HUMAN_PLAYER_H

#include <iostream>
#include "playfield_traits.h"

template<typename F>
struct human_player {
    int id;

public:
    explicit human_player(int id) : id(id) {}

    int play(const F &field) {
        int column;
        for (;;) {
            std::cin >> column;
            if (playfield_traits<F>::is_playable(field, column)) {
                return column;
            }
            else {
                std::cout << "Wrong input. Try again: ";
            }
        }
    }
};

#endif //EX2_4_HUMAN_PLAYER_H
