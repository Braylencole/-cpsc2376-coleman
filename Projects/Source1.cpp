#include "game.h"

Game::Game() : board(SIZE, std::vector<Player>(SIZE, EMPTY)), currentPlayer(PLAYER1), gameStatus(ONGOING) {}

void Game::play(int cell) {
    if (cell < 0 || cell >= SIZE * SIZE || gameStatus != ONGOING) return;

    int row = cell / SIZE;
    int col = cell % SIZE;

    if (board[row][col] == EMPTY) {
        board[row][col] = currentPlayer;

        if (isWinningMove(row, col)) {
            gameStatus = (currentPlayer == PLAYER1) ? PLAYER1_WINS : PLAYER2_WINS;
        }
        else if (boardFull()) {
            gameStatus = DRAW;
        }
        else {
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        }
    }
    // If cell is already taken, do nothing
}

Status Game::status() const {
    return gameStatus;
}

bool Game::boardFull() {
    for (const auto& row : board) {
        for (Player cell : row) {
            if (cell == EMPTY) return false;
        }
    }
    return true;
}

bool Game::isWinningMove(int row, int col) {
    Player p = board[row][col];

    // Check row
    if (board[row][0] == p && board[row][1] == p && board[row][2] == p) return true;

    // Check column
    if (board[0][col] == p && board[1][col] == p && board[2][col] == p) return true;

    // Check diagonals
    if (row == col && board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (row + col == 2 && board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;

    return false;
}

void Game::display() const {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    for (int r = 0; r < Game::SIZE; ++r) {
        for (int c = 0; c < Game::SIZE; ++c) {
            char symbol = '.';
            if (game.board[r][c] == PLAYER1) symbol = 'X';
            else if (game.board[r][c] == PLAYER2) symbol = 'O';

            os << symbol;
            if (c < Game::SIZE - 1) os << " | ";
        }
        os << "\n";
        if (r < Game::SIZE - 1) os << "--+---+--\n";
    }
    return os;
}
