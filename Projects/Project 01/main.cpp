#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Player { NONE, PLAYER_1, PLAYER_2 };

class ConnectFour {
private:
    vector<vector<Player>> board;
    Player currentPlayer;

public:
    ConnectFour() { resetBoard(); }

    void resetBoard() {
        board = vector<vector<Player>>(ROWS, vector<Player>(COLS, Player::NONE));
        currentPlayer = Player::PLAYER_1;
    }

    void printRules() {
        cout << "Welcome to Connect Four!" << endl;
        cout << "The first player to connect four in a row, column, or diagonal wins!" << endl;
        cout << "Enter a column number (1-7) to drop your token." << endl;
    }

    void displayBoard() {
        
        cout << "\n 1 2 3 4 5 6 7\n";
        cout << "---------------\n";
        for (const auto& row : board) {
            for (const auto& cell : row) {
                char symbol = '.';
                if (cell == Player::PLAYER_1) symbol = 'x';
                else if (cell == Player::PLAYER_2) symbol = 'O';
                cout << " " << symbol;
            }
            cout << "\n";
        }
        cout << "---------------\n";
    }

	// Returns true if the token was successfully dropped, false otherwise
    bool dropToken(int col) {
        if (col < 1 || col > COLS || board[0][col - 1] != Player::NONE) {
            cout << "Invalid move. Try again." << endl;
            return false;
        }

        
        for (int row = ROWS - 1; row >= 0; --row) {
            if (board[row][col - 1] == Player::NONE) {
                board[row][col - 1] = currentPlayer;
                return true;
            }
        }
        return false;
    }

    GameState checkGameState() {
        // Check horizontal, vertical, and diagonal win conditions
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                Player token = board[row][col];
                if (token == Player::NONE) continue;

                if (col <= COLS - 4 && token == board[row][col + 1] && token == board[row][col + 2] && token == board[row][col + 3])
                    return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

                if (row <= ROWS - 4 && token == board[row + 1][col] && token == board[row + 2][col] && token == board[row + 3][col])
                    return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

                if (row <= ROWS - 4 && col <= COLS - 4 && token == board[row + 1][col + 1] && token == board[row + 2][col + 2] && token == board[row + 3][col + 3])
                    return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

                if (row >= 3 && col <= COLS - 4 && token == board[row - 1][col + 1] && token == board[row - 2][col + 2] && token == board[row - 3][col + 3])
                    return (token == Player::PLAYER_1) ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
            }
        }
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == Player::NONE) return GameState::ONGOING;
            }
        }
        return GameState::DRAW;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == Player::PLAYER_1) ? Player::PLAYER_2 : Player::PLAYER_1;
    }

    void playGame() {
        printRules();
        while (true) {
            resetBoard();
            GameState state = GameState::ONGOING;
            while (state == GameState::ONGOING) {
                displayBoard();
                int col;
                cout << "Player " << ((currentPlayer == Player::PLAYER_1) ? "1 (X)" : "2 (O)") << ", enter column (1-7): ";
                while (!(cin >> col) || !dropToken(col)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input. Enter column (1-7): ";
                }
                state = checkGameState();
                if (state == GameState::ONGOING) switchPlayer();
            }

            displayBoard();
            if (state == GameState::PLAYER_1_WINS) cout << "Player 1 (X) wins!\n";
            else if (state == GameState::PLAYER_2_WINS) cout << "Player 2 (O) wins!\n";
            else cout << "It's a draw!\n";

            cout << "Play again? (y/n): ";
            char choice;
            cin >> choice;
            if (choice != 'y' && choice != 'Y') break;
        }
    }
};

int main() {
    ConnectFour game;
    game.playGame();
    return 0;
}
