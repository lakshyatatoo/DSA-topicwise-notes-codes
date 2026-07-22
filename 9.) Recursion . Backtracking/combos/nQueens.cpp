#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int dupRow = row;
        int dupCol = col;
        while (dupRow >= 0 && dupCol >= 0)
        {
            if (board[dupRow][dupCol] == 'Q')
                return false;
            dupRow--;
            dupCol--;
        }
        dupRow = row;
        dupCol = col;
        while (dupCol >= 0)
        {
            if (board[dupRow][dupCol] == 'Q')
                return false;
            dupCol--;
        }
        dupRow = row;
        dupCol = col;
        while (dupRow < n && dupCol >= 0)
        {
            if (board[dupRow][dupCol] == 'Q')
                return false;
            dupRow++;
            dupCol--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};

// efficient

class Solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};