// game.cpp

#include <iostream>
#include "game.h"

using namespace std;

// Print game rules
void printRules() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Players take turns to place their tokens (X or O) on the grid." << endl;
    cout << "The first player to align three tokens horizontally, vertically, or diagonally wins." << endl;
    cout << "Enter row and column numbers (0, 1, or 2) to place your token." << endl;
    cout << "Let's play!" << endl;
}

// Initialize the game board
void makeBoard(vector<vector<Player>>& board) {
    board.resize(BOARD_SIZE, vector<Player>(BOARD_SIZE, Player::NONE));
}

// Display the current board
void printBoard(const vector<vector<Player>>& board) {
    cout << "Current Board:" << endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char symbol = ' ';
            if (board[i][j] == Player::PLAYER_1) symbol = 'X';
            else if (board[i][j] == Player::PLAYER_2) symbol = 'O';
            cout << "[" << symbol << "] ";
        }
        cout << endl;
    }
}

// Check if a move is valid
bool isMoveValid(const vector<vector<Player>>& board, int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == Player::NONE;
}

// Handle player's turn
void play(vector<vector<Player>>& board, Player currentPlayer) {
    int row, col;
    bool validMove = false;

    do {
        cout << "Enter row and column (0-" << BOARD_SIZE - 1 << ") separated by a space: ";
        cin >> row >> col;

        if (cin.fail() || !isMoveValid(board, row, col)) {
            cout << "Invalid move. Try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            board[row][col] = currentPlayer;
            validMove = true;
        }
    } while (!validMove);
}

// Check game status
GameState gameStatus(const vector<vector<Player>>& board) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != Player::NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
        }
        if (board[0][i] != Player::NONE && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
        }
    }

    // Check diagonals
    if (board[0][0] != Player::NONE && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
    }
    if (board[0][2] != Player::NONE && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
    }

    // Check for draw or ongoing
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == Player::NONE) {
                return GameState::ONGOING;
            }
        }
    }
    return GameState::DRAW;
}
