#include "game.h"

Game::Game() : board(6, std::vector<Cell>(7, EMPTY)), currentPlayer(1), gameStatus(ONGOING) {}

void Game::play(int column) {
    if (column < 0 || column >= 7 || gameStatus != ONGOING) return;

    for (int row = 5; row >= 0; --row) {
        if (board[row][column] == EMPTY) {
            board[row][column] = currentPlayer == 1 ? PLAYER1 : PLAYER2;

            if (checkWin(row, column)) {
                gameStatus = currentPlayer == 1 ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
            else {
                bool isFull = true;
                for (int c = 0; c < 7 && isFull; ++c) {
                    if (board[0][c] == EMPTY) isFull = false;
                }
                if (isFull) gameStatus = DRAW;
            }

            currentPlayer = 3 - currentPlayer; // Switch player (1 -> 2, 2 -> 1)
            break;
        }
    }
}

Status Game::status() const {
    return gameStatus;
}

bool Game::checkWin(int row, int col) {
    return checkDirection(row, col, 0, 1) ||  // Horizontal
        checkDirection(row, col, 1, 0) ||  // Vertical
        checkDirection(row, col, 1, 1) ||  // Diagonal /
        checkDirection(row, col, 1, -1);   // Diagonal \
    }

    bool Game::checkDirection(int r, int c, int dr, int dc) {
        Cell target = board[r][c];
        int count = 1;

        for (int step = 1; step < 4; ++step) {
            int nr = r + dr * step;
            int nc = c + dc * step;
            if (nr < 0 || nr >= 6 || nc < 0 || nc >= 7 || board[nr][nc] != target) break;
            count++;
        }

        for (int step = 1; step < 4; ++step) {
            int nr = r - dr * step;
            int nc = c - dc * step;
            if (nr < 0 || nr >= 6 || nc < 0 || nc >= 7 || board[nr][nc] != target) break;
            count++;
        }

        return count >= 4;
    }

    std::ostream& operator<<(std::ostream & os, const Game & game) {
        for (const auto& row : game.board) {
            for (Cell cell : row) {
                char symbol = (cell == EMPTY ? '.' : (cell == PLAYER1 ? 'X' : 'O'));
                os << symbol << ' ';
            }
            os << '\n';
        }
        return os;
    }
