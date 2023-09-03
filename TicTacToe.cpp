#include <iostream>
using namespace std;

class BoardDisplay {
    char board[3][3] = {
       { '1', '2', '3'},
       { '4' , '5' , '6'},
       { '7' , '8' , '9' }
    };
    char choice1, choice2, again;
    int row, column, check = 0;

public:
    void menu() {
        cout << endl << endl << "\033[33m***********************************************************************************************************************\033[0m" << endl;
        cout << "\t\t\t\t    \033[47m\033[30m**  Welcome to the Excitting Tic Tac Toe Game!  **\033[0m\033[0m" << endl;
        cout << "\033[33m***********************************************************************************************************************\033[0m" << endl << endl;
        cout << "\t\t\t\t\t      \033[35m Are You Ready to Play?\033[0m" << endl << endl << endl;
    }

    void PrintingGrid() {
        for (row = 0; row < 3; row++) {
            for (column = 0; column < 3; column++) {
                cout << " " << board[row][column] << " ";
                if (column < 2) {
                    cout << "\033[36m|\033[0m"; // Vertical grid lines
                }
            }
            cout << endl;
            if (row < 2) {
                cout << "\033[36m---+---+---\033[0m" << endl; // Horizontal grid lines
            }
        }
    }

    void Play() {
        for (int i = 0; i < 9; i++) {
            if (i % 2 == 0) {
            label1:
                cout << endl << "Player 1 Turn : ";
                cout << "\033[35m";
                cin >> choice1;
                cout << "\033[0m";
            }
            else {
            label2:
                cout << endl << "Player 2 Turn : ";
                cout << "\033[32m";
                cin >> choice2;
                cout << "\033[0m";
            }

            bool validMove = false; // Flag to check if the move is valid

            for (row = 0; row < 3; row++) {
                for (column = 0; column < 3; column++) {
                    if ((i % 2 == 0 && board[row][column] == choice1) || (i % 2 != 0 && board[row][column] == choice2)) {
                        if (board[row][column] != 'O' && board[row][column] != 'X') {
                            board[row][column] = (i % 2 == 0) ? 'O' : 'X'; // Assign 'O' or 'X' to the chosen cell
                            validMove = true; // Move is valid
                            break;
                        }
                    }
                }
                if (validMove) break; // If move is valid, exit the loop
            }

            if (!validMove) {
                cout << endl << "\033[31mInvalid Move. Cell Already Filled . Please Choose an Empty Cell\033[0m" << endl;
                if (i % 2 == 0) {
                    goto label1;
                }
                else {
                    goto label2;
                }
            }

            cout << endl;
            PrintingGrid(); // Print the updated grid

            // Check for a win
            if (i >= 4) { // Start checking for a win after 4 moves
                if (CheckWin()) {
                    return;
                }
            }

            // Check for a draw
            if (i == 8) { // If all cells are filled and no winner
                cout << endl << "\033[32m\tWith No Clear Winner, this match ends in a Draw. Thank You for Playing!\033[0m" << endl << endl;
                AskToPlayAgain();
                return;
            }
        }
    }

    bool CheckWin() {
        for (int i = 0; i < 3; i++) {
            // Check rows and columns
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                cout << endl;
                PrintWinner(board[i][i]);
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            cout << endl;
            PrintWinner(board[1][1]);
            return true;
        }

        return false; // No winner yet
    }

    void PrintWinner(char winner) {
        if (winner == 'O') {
            cout << "\033[33m\tWith an Impressive Performance, Player 1 emerges as the Winner! Congratulataions! Thank You for Playing!\033[0m" << endl << endl;
        }
        else if (winner == 'X') {
            cout << "\033[33m\tWith an Impressive Performance, Player 2 emerges as the Winner! Congratulataions! Thank You for Playing!\033[0m" << endl << endl;
        }

        AskToPlayAgain();
    }

    void AskToPlayAgain() {
        cout << endl << "\033[36mDo You Want to Play Again ? Press Any Key for Continue Otherwise Press 'q' / 'Q' for Quit\033[0m" << endl << endl;
        cout << "Enter : ";
        cout << "\033[36m";
        cin >> again;
        cout << "\033[0m";

        if (again == 'q' || again == 'Q') {
            exit(0);
        }
        else {
            check = 0;
            // Reset the board
            for (row = 0; row < 3; row++) {
                for (column = 0; column < 3; column++) {
                    board[row][column] = (char)(check + 49); // Reset to '1', '2', '3', ...
                    check++;
                }
            }
        menu();
            PrintingGrid();
            Play();
        }

    }
};

int main() {
    BoardDisplay b;
    b.menu();
    b.PrintingGrid();
    b.Play();
    return 0;
}
