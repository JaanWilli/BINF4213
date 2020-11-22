#ifndef EX5_2_PLAYFIELD_H
#define EX5_2_PLAYFIELD_H

class playfield {
public:
    const static int width = 7;
    const static int height = 6;

    const static int none = 0;
    const static int player1 = 1;
    const static int player2 = 2;

    virtual int stoneat(int x, int y) const = 0;

    virtual ~playfield() {}
};


#endif //EX5_2_PLAYFIELD_H
