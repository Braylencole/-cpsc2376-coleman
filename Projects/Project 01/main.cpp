#include <iostream>
#include <vector>
#include <limits>

using namespace std;

enum class GameState {
    ONGOING,
    PLAYER_1_WINS,
    PLAYER_2_WINS,
    DRAW
};

enum class Player {
    NONE,
    PLAYER_1,
    PLAYER_2
};

const int BOARD_SIZE = 3;

// Print rules
void printRules() {
    cout << "=== Tic-Tac-Toe Rules ===\n";
    cout << "1. Two players take turns placing their symbols (X for Player 1, O for Player 2).\n";
    cout << "2. Enter row and column (0 to 2) to place your move.\n";
    cout << "3. First to align 3 symbols wins.\n";
    cout << "4. If board is full with no winner, it's a draw.\n\n";
}

// Initialize empty board
void makeBoard(vector<vector<Player>>& board) {
    board = vector<vector<Player>>(BOARD_SIZE, vector<Player>(BOARD_SIZE, Player::NONE));
}

// Print current board
void printBoard(const vector<vector<Player>>& board) {
    cout << "Board:\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            char c = ' ';
            if (board[i][j] == Player::PLAYER_1) c = 'X';
            else if (board[i][j] == Player::PLAYER_2) c = 'O';
            cout << "[" << c << "]";
        }
        cout << "\n";
    }
}

// Validate move
bool isMoveValid(const vector<vector<Player>>& board, int row, int col) {
    return row >= 0 && row < BOARD_SIZE &&
        col >= 0 && col < BOARD_SIZE &&
        board[row][col] == Player::NONE;
}

// Get game state
GameState gameStatus(const vector<vector<Player>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != Player::NONE &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return (board[i][0] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

        if (board[0][i] != Player::NONE &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return (board[0][i] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
    }

    if (board[0][0] != Player::NONE &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return (board[0][0] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

    if (board[0][2] != Player::NONE &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return (board[0][2] == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

    for (const auto& row : board)
        for (auto cell : row)
            if (cell == Player::NONE)
                return GameState::ONGOING;

    return GameState::DRAW;
}

// Handle turn
void playTurn(vector<vector<Player>>& board, Player currentPlayer) {
    int row, col;
    bool valid = false;

    do {
        cout << "Enter row and column (0-2): ";
        cin >> row >> col;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter numbers.\n";
            continue;
        }

        if (!isMoveValid(board, row, col)) {
            cout << "Invalid move. Try again.\n";
        }
        else {
            board[row][col] = currentPlayer;
            valid = true;
        }
    } while (!valid);
}

// Main game loop
int main() {
    bool playAgain = true;
    while (playAgain) {
        vector<vector<Player>> board;
        Player currentPlayer = Player::PLAYER_1;
        GameState state = GameState::ONGOING;

        printRules();
        makeBoard(board);

        while (state == GameState::ONGOING) {
            printBoard(board);
            cout << "Player " << ((currentPlayer == Player::PLAYER_1) ? "1 (X)" : "2 (O)") << "'s turn.\n";
            playTurn(board, currentPlayer);

            state = gameStatus(board);
            if (state == GameState::ONGOING) {
                currentPlayer = (currentPlayer == Player::PLAYER_1) ? Player::PLAYER_2 : Player::PLAYER_1;
            }
        }

        printBoard(board);

        if (state == GameState::PLAYER_1_WINS)
            cout << "Player 1 (X) wins!\n";
        else if (state == GameState::PLAYER_2_WINS)
            cout << "Player 2 (O) wins!\n";
        else
            cout << "It's a draw!\n";

        char again;
        cout << "Play again? (y/n): ";
        cin >> again;
        playAgain = (again == 'y' || again == 'Y');
    }

    cout << "Thanks for playing!\n";
    return 0;
}
