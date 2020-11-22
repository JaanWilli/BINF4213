#ifndef EX5_3_PLAYER_FACTORY_H
#define EX5_3_PLAYER_FACTORY_H

#include "player.h"
#include "human_player.h"
#include "jan_player.h"


class player_factory {

public:
    player_factory();

    static player *getPlayer(const std::string &type, const int &id);
};


#endif //EX5_3_PLAYER_FACTORY_H
