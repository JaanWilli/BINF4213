#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include <iostream>

using namespace std;

template<typename F>
struct remy_player {
    char player_id;
    bool id_assigned = false;
    int last_row;
    int last_column = 0;

    // returns the column where the player decides to insert his
    // stone
    // F is the playfield which may be any playfield implementing
    // the stoneat method, if you expect a different class because
    // you need methods to verify whether the opponent can win,
    // copy the field into the class that you expect.
    int play(const F &field) {
        if (!id_assigned) {
            find_player_id(field);
            last_row = field.height - 1;
        }
        if (play_winning(field) != -1) {
            return play_winning(field);
        } else {
            return play_stupid(field);
        }
    }

    void find_player_id(const F &field) {
        player_id = field.player1;
        for (int i = 0; i < field.width; i++) {
            if (field.rep[i][field.height - 1] != 0) {
                player_id = field.player2;
                id_assigned = true;
                break;
            }
        }
    }

    int play_stupid(const F &field) {
        if (position_playable(field, last_column + 1, last_row)) {
            last_column = last_column + 1;
        } else {
            last_column = 0;
            last_row -= 1;
        }
        return last_column;
    }

    int play_winning(const F &field) {
        int height = field.height;
        int width = field.width;

        //vertical case
        int counter = 0;
        for (int x = 0; x < width; x++) {
            for (int y = height - 1; y > 0; y--) {
                if (field.rep[x][y] == player_id) {
                    counter++;
                } else {
                    counter = 0;
                }
                if (counter == 3 && field.rep[x][y - 1] == field.none) {
                    return x;
                }
            }
        }
        return -1;

        //horizontal case - left to right
        counter = 0;
        for (int y = height - 1; y >= 0; y--) {
            for (int x = 0; x < width; x++) {
                if (field.rep[x][y] == player_id) {
                    counter++;
                } else {
                    counter = 0;
                }
                if (counter == 3) {
                    if (position_playable(field, x + 1, y)) {
                        return x + 1;
                    }
                }
            }
        }

        //horizontal case - right to left
        counter = 0;
        for (int y = height - 1; y >= 0; y--) {
            for (int x = width - 1; x >= 0; x--) {
                if (field.rep[x][y] == player_id) {
                    counter++;
                } else {
                    counter = 0;
                }
                if (counter == 3) {
                    if (position_playable(field, x - 1, y)) {
                        return x - 1;
                    }
                }
            }
        }

        //diagonal bottom left to top right case
        counter = 0;
        int step;
        for (int x = 0; x <= width - 1 - 3; x++) {
            for (int y = height - 1; y >= 3; y--) {
                step = 0;
                while (y - step >= 0 && x + step <= width - 1) {
                    if (field.rep[x + step][y - step] == player_id) {
                        counter++;
                    } else {
                        counter = 0;
                    }
                    if (counter == 3) {
                        if (position_playable(field, x + step + 1, y - step - 1)) {
                            return x + step + 1;
                        }
                    }
                    step++;
                }
            }
        }

        //diagonal bottom right to top left case
        counter = 0;
        for (int x = width - 1; x >= 0; x--) {
            for (int y = height - 1; y >= 3; y--) {
                step = 0;
                while (y - step >= 0 && x - step >= 0) {
                    if (field.rep[x - step][y - step] == player_id) {
                        counter++;
                    } else {
                        counter = 0;
                    }
                    if (counter == 3) {
                        if (position_playable(field, x - step - 1, y - step - 1)) {
                            return x - step - 1;
                        }
                    }
                    step++;
                }
            }
        }
        return -1;
    }

    bool position_playable(const F &field, int x, int y) {
        if (x < 0 || x >= field.width || y < 0 || y >= field.height) {
            return false;
        }

        if (field.rep[x][y] == field.none) {
            if (y == (field.width - 1)) {
                return true;
            } else if (field.rep[x][y + 1] == field.none) {
                return true;
            }
        }
        return false;
    }
};

#endif /* COMPUTERPLAYER_H */
