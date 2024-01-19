// Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void drawBoard(const std::vector<std::vector<char>>& board)
{
    for (const auto& row : board)
    {
        for (char cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2]) == player ||
            board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector < std::vector<char>> &board)
{
    for (const auto& row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    while (!gameOver)
    {
        drawBoard(board);
        std::cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        std::cin >> row >> col;

        if (board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            gameOver = checkWin(board, currentPlayer);

            if (gameOver)
            {
                drawBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            }
            else if (checkDraw(board))
            {
                drawBoard(board);
                std::cout << "It's a draw!" << std::endl;
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else
        {
            std::cout << "That spot is already taken. Try again." << std::endl;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
