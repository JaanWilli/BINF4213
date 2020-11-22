#ifndef EX5_2_JAN_PLAYFIELD_H
#define EX5_2_JAN_PLAYFIELD_H

#include "playfield.h"
#include "playfield_traits.h"

class jan_playfield : public playfield {
public:
    char rep[playfield::width][playfield::height]{};

    jan_playfield();

    virtual int stoneat(int x, int y)  const;
    virtual std::string stone_repr(int x, int y) const;
    virtual void insert(int x, int player);
    virtual void print() const;
};

#endif //EX2_4_PLAYFIELD_H
