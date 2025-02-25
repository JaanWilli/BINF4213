#ifndef EX2_4_UTIL_H
#define EX2_4_UTIL_H


template<typename F>
struct playfield_traits {

    static bool is_playable(const F &field, int column) {
        return column >= 0 && column < F::width && field.stoneat(column, 0) == F::none;
    }

    static bool is_not_full(const F &field) {
        for (int i = 0; i < F::width; ++i) {
            if (field.stoneat(i, 0) == F::none) {
                return true;
            }
        }
        return false;
    }

    static bool has_won(const F &field, int pl) {
        for (int i = 0; i < F::width; ++i) {
            for (int j = 0; j < F::height; ++j) {
                if (field.stoneat(i, j) == pl && field.stoneat(i + 1, j) == pl && field.stoneat(i + 2, j) == pl &&
                    field.stoneat(i + 3, j) == pl) {
                    return true;
                }
                if (field.stoneat(i, j) == pl && field.stoneat(i + 1, j + 1) == pl &&
                    field.stoneat(i + 2, j + 2) == pl && field.stoneat(i + 3, j + 3) == pl) {
                    return true;
                }
                if (field.stoneat(i, j) == pl && field.stoneat(i, j + 1) == pl && field.stoneat(i, j + 2) == pl &&
                    field.stoneat(i, j + 3) == pl) {
                    return true;
                }
                if (field.stoneat(i, j) == pl && field.stoneat(i - 1, j - 1) == pl &&
                    field.stoneat(i - 2, j - 2) == pl && field.stoneat(i - 3, j - 3) == pl) {
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
