#include <iostream>
#include <vector>


void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell != 'X' && cell != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));

    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        std::cout << "Current board:\n";
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        gameWon = checkWin(board, currentPlayer);
        gameDraw = checkDraw(board);

        if (gameWon) {
            std::cout << "Player " << currentPlayer << " wins!\n";
        } else if (gameDraw) {
            std::cout << "It's a draw!\n";
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
