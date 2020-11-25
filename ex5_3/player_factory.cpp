#include "player_factory.h"

player_factory::player_factory() {}

player *player_factory::getPlayer(const std::string &type, const int &id) {
    if (type == "human") return new human_player(id);
    else if (type == "jan") return new jan_player(id);
}
