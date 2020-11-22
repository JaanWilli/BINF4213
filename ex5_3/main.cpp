#include "jan_playfield.h"
#include "player_factory.h"


using namespace std;

typedef playfield_traits<playfield> PT;

void play(jan_playfield &field, player *p1, player *p2) {

    int current = 1;

    while (PT::is_not_full(field)) {
        field.print();
        std::cout << "It is player " << current << "'s turn: ";

        if (current == playfield::player1) {
            int column = p1->play(field);
            field.insert(column, playfield::player1);
        }
        else if (current == playfield::player2) {
            int column = p2->play(field);
            field.insert(column, playfield::player2);
        }

        std::cout << std::endl;

        if (PT::has_won(field, current)) {
            field.print();
            std::cout << "Player " << current << " won!" << std::endl;
            return;
        }

        current = PT::next_player(current);
    }
    std::cout << "It's a draw..." << std::endl;
}

int main() {

    int c = 0;
    auto p1 = player_factory::getPlayer("human", ++c);
    auto p2 = player_factory::getPlayer("jan", ++c);

    auto field = jan_playfield();
    play(field, p1, p2);
    return 0;
}