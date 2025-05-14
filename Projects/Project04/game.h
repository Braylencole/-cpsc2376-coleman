#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>

enum Cell { EMPTY, RED, YELLOW };
enum Status { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

class Game {
public:
    Game();
    void play(int col);
    Status status() const;
    void reset();
    void draw(SDL_Renderer* renderer) const;

private:
    std::vector<std::vector<Cell>> board;
    int currentPlayer;
    Status gameStatus;

    bool checkWin(int row, int col);
    bool checkDirection(int r, int c, int dr, int dc);
    bool isBoardFull();
};

#endif

