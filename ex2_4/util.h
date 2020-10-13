#ifndef EX2_4_UTIL_H
#define EX2_4_UTIL_H


template<typename F>
struct util {

    static bool is_playable(const F &field, int column) {
        return column >= 0 && column < playfield::width && field.stoneat(column, 0) == playfield::none;
    }

    static bool is_not_full(const F &field) {
        for (int i = 0; i < playfield::width; ++i) {
            if (field.stoneat(i, 0) == playfield::none) {
                return true;
            }
        }
        return false;
    }

    static bool has_won(const F &field, int pl) {
        for (int i = 0; i < playfield::height; ++i) {
            for (int j = 0; j < playfield::width; ++j) {
                if (field.stoneat(j, i) == pl && field.stoneat(j, i + 1) == pl && field.stoneat(j, i + 2) == pl &&
                    field.stoneat(j, i + 3) == pl) {
                    return true;
                }
                if (field.stoneat(j, i) == pl && field.stoneat(j + 1, i + 1) == pl &&
                    field.stoneat(j + 2, i + 2) == pl && field.stoneat(j + 3, i + 3) == pl) {
                    return true;
                }
                if (field.stoneat(j, i) == pl && field.stoneat(j + 1, i) == pl && field.stoneat(j + 2, i) == pl &&
                    field.stoneat(j + 3, i) == pl) {
                    return true;
                }
                if (field.stoneat(j, i) == pl && field.stoneat(j - 1, i - 1) == pl &&
                    field.stoneat(j - 2, i - 2) == pl && field.stoneat(j - 3, i - 3) == pl) {
                    return true;
                }
            }
        }
        return false;
    }

    static int next_player(int current) {
        return current % 2 + 1;
    }

};

#endif //EX2_4_UTIL_H
