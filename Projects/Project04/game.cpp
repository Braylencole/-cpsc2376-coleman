#include "game.h"

Game::Game() : board(6, std::vector<Cell>(7, EMPTY)), currentPlayer(1), gameStatus(ONGOING) {}

void Game::play(int col) {
    if (col < 0 || col >= 7 || gameStatus != ONGOING) return;

    for (int row = 5; row >= 0; --row) {
        if (board[row][col] == EMPTY) {
            board[row][col] = (currentPlayer == 1) ? RED : YELLOW;

            if (checkWin(row, col)) {
                gameStatus = (currentPlayer == 1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            }
            else if (isBoardFull()) {
                gameStatus = DRAW;
            }
            else {
                currentPlayer = 3 - currentPlayer;
            }
            break;
        }
    }
}

Status Game::status() const {
    return gameStatus;
}

void Game::reset() {
    board = std::vector<std::vector<Cell>>(6, std::vector<Cell>(7, EMPTY));
    currentPlayer = 1;
    gameStatus = ONGOING;
}

bool Game::isBoardFull() {
    for (const auto& row : board)
        for (Cell c : row)
            if (c == EMPTY) return false;
    return true;
}

bool Game::checkWin(int row, int col) {
    return checkDirection(row, col, 0, 1) ||  // horizontal
        checkDirection(row, col, 1, 0) ||  // vertical
        checkDirection(row, col, 1, 1) ||  // diagonal /
        checkDirection(row, col, 1, -1);   // diagonal \
    }

    bool Game::checkDirection(int r, int c, int dr, int dc) {
        Cell target = board[r][c];
        int count = 1;

        for (int step = 1; step < 4; ++step) {
            int nr = r + dr * step, nc = c + dc * step;
            if (nr < 0 || nr >= 6 || nc < 0 || nc >= 7 || board[nr][nc] != target) break;
            count++;
        }

        for (int step = 1; step < 4; ++step) {
            int nr = r - dr * step, nc = c - dc * step;
            if (nr < 0 || nr >= 6 || nc < 0 || nc >= 7 || board[nr][nc] != target) break;
            count++;
        }

        return count >= 4;
    }

    void Game::draw(SDL_Renderer * renderer) const {
        int cellSize = 100;

        // Draw board background
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_Rect boardRect = { 0, 0, 7 * cellSize, 6 * cellSize };
        SDL_RenderFillRect(renderer, &boardRect);

        // Draw circles
        for (int r = 0; r < 6; ++r) {
            for (int c = 0; c < 7; ++c) {
                int cx = c * cellSize + cellSize / 2;
                int cy = r * cellSize + cellSize / 2;

                if (board[r][c] == RED) {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                }
                else if (board[r][c] == YELLOW) {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                }
                else {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                }

                for (int radius = 40; radius > 0; --radius) {
                    for (int w = -radius; w <= radius; ++w) {
                        int h = (int)sqrt(radius * radius - w * w);
                        SDL_RenderDrawPoint(renderer, cx + w, cy + h);
                        SDL_RenderDrawPoint(renderer, cx + w, cy - h);
                    }
                }
            }
        }
    }
