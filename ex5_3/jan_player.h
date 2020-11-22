#ifndef EX5_2_JAN_PLAYER_H
#define EX5_2_JAN_PLAYER_H

#include <set>
#include <vector>

#include "player.h"
#include "playfield.h"
#include "playfield_traits.h"

class jan_player : public player {
    int id;

    struct copy_playfield;

    typedef playfield_traits<copy_playfield> T;

public:

    jan_player(int id);

    virtual ~jan_player();

    virtual int play(const playfield &field);
};

#endif //EX5_2_JAN_PLAYER_H
