#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c)
                return false;
            if (board[row][i] == c)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

class Solution
{
public:
    bool isValid(vector<vector<char>> &sudokuBoard, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (sudokuBoard[row][i] == c)
                return false;
            if (sudokuBoard[i][col] == c)
                return false;
            if (sudokuBoard[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>> &sudokuBoard)
    {

        for (int i = 0; i < sudokuBoard.size(); i++)
        {
            for (int j = 0; j < sudokuBoard[0].size(); j++)
            {
                if (sudokuBoard[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(sudokuBoard, i, j, c))
                        {
                            sudokuBoard[i][j] = c;
                            if (solveSudoku(sudokuBoard))
                                return true;
                            else
                                sudokuBoard[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solvePuzzle(vector<vector<char>> &sudokuBoard)
    {
        solveSudoku(sudokuBoard);
    }
};