#include "game.h"
#include <iostream>

int main() {
    Game game;
    int move;

    while (game.status() == ONGOING) {
        std::cout << game;
        std::cout << "Enter column (0–6): ";
        std::cin >> move;
        game.play(move);
    }

    std::cout << game;
    switch (game.status()) {
    case PLAYER_1_WINS: std::cout << "Player 1 wins!\n"; break;
    case PLAYER_2_WINS: std::cout << "Player 2 wins!\n"; break;
    case DRAW: std::cout << "Game is a draw.\n"; break;
    default: break;
    }

    return 0;
}
