#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>

enum Cell { EMPTY, PLAYER1, PLAYER2 };
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Game {
private:
    std::vector<std::vector<Cell>> board;
    int currentPlayer;
    Status gameStatus;

    bool checkWin(int row, int col);
    bool checkDirection(int r, int c, int dr, int dc);

public:
    Game();
    void play(int column);
    Status status() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

#endif

