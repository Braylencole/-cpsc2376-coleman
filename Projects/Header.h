// game.h

#ifndef GAME_H
#define GAME_H

#include <vector>

// Game state enumeration
enum class GameState {
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

// Player tokens
enum class Player {
    NONE,
    PLAYER_1,
    PLAYER_2
};

// Board size (modifiable for different grid sizes)
const int BOARD_SIZE = 3;

// Function prototypes
void printRules();
void makeBoard(std::vector<std::vector<Player>>& board);
void printBoard(const std::vector<std::vector<Player>>& board);
GameState gameStatus(const std::vector<std::vector<Player>>& board);
void play(std::vector<std::vector<Player>>& board, Player currentPlayer);
bool isMoveValid(const std::vector<std::vector<Player>>& board, int row, int col);

#endif

