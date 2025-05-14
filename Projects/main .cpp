#include <iostream>
#include "game.h"

int main() {
    Game game;
    int move;

    while (game.status() == ONGOING) {
        std::cout << game;
        std::cout << "Enter your move (0-8): ";
        std::cin >> move;
        game.play(move);
    }

    std::cout << game;

    switch (game.status()) {
    case PLAYER1_WINS: std::cout << "Player 1 (X) wins!\n"; break;
    case PLAYER2_WINS: std::cout << "Player 2 (O) wins!\n"; break;
    case DRAW: std::cout << "It's a draw!\n"; break;
    default: break;
    }

    return 0;
}
