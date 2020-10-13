#ifndef EX2_4_PLAYFIELD_H
#define EX2_4_PLAYFIELD_H

struct playfield {

public:
    const static int width=7;
    const static int height=6;

    const static char none=0;
    const static char player1=1;
    const static char player2=2;

protected:
    char rep[playfield::width][playfield::height]{};

public:
    playfield();

    int stoneat(int x, int y)  const;
    std::string stone_repr(int x, int y) const;
    void insert(int x, int player);
    void print() const;
};

#endif //EX2_4_PLAYFIELD_H
