#ifndef EX5_2_HUMAN_PLAYER_H
#define EX5_2_HUMAN_PLAYER_H

#include <iostream>

#include "player.h"
#include "playfield_traits.h"

struct human_player : public player {
    int id;

public:

    human_player(int id);

    virtual ~human_player();

    virtual int play(const playfield &field);
};

#endif //EX5_2_HUMAN_PLAYER_H
