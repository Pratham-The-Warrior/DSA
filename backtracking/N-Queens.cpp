/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{

    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.')); // initialize n x n board with '.'
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    if (solutions.empty())
    {

        return 0;
    }

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (int i = 0; i < solutions.size(); i++)
    {

        for (auto &row : solutions[i])
            cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
