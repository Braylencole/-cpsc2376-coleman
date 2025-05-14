#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

enum Player { EMPTY, PLAYER1, PLAYER2 };
enum Status { ONGOING, PLAYER1_WINS, PLAYER2_WINS, DRAW };

class Game {
private:
    static const int SIZE = 3;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    Status gameStatus;

    bool isWinningMove(int row, int col);
    bool boardFull();

public:
    Game();

    void play(int cell);      // Make a move (0-8)
    Status status() const;    // Get current game status
    void display() const;     // Optional
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif

