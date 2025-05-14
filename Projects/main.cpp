// main.cpp

#include <iostream>
#include "game.h"

using namespace std;

int main() {
    bool playAgain = true;
    while (playAgain) {
        printRules();

        vector<vector<Player>> board;
        makeBoard(board);

        GameState state = GameState::ONGOING;
        Player currentPlayer = Player::PLAYER_1;

        while (state == GameState::ONGOING) {
            printBoard(board);
            cout << "Player " << (currentPlayer == Player::PLAYER_1 ? "1 (X)" : "2 (O)") << "'s turn." << endl;
            play(board, currentPlayer);

            state = gameStatus(board);
            if (state == GameState::ONGOING) {
                currentPlayer = (currentPlayer == Player::PLAYER_1) ? Player::PLAYER_2 : Player::PLAYER_1;
            }
        }

        printBoard(board);

        if (state == GameState::PLAYER_1_WINS) {
            cout << "Player 1 (X) wins!" << endl;
        }
        else if (state == GameState::PLAYER_2_WINS) {
            cout << "Player 2 (O) wins!" << endl;
        }
        else if (state == GameState::DRAW) {
            cout << "It's a draw!" << endl;
        }

        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
