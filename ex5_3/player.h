#ifndef EX5_2_PLAYER_H
#define EX5_2_PLAYER_H

#include <iostream>
#include "playfield.h"
#include "jan_playfield.h"

class player {
public:
    virtual int play(const playfield &field) = 0;
    virtual ~player() {}
};

#endif //EX5_2_PLAYER_H
