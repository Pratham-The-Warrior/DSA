#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int> &board, int row, int col)
{
    for (int c = 0; c < col; ++c)
    {
        int r = board[c];
        if (r == row || abs(r - row) == abs(c - col))
            return false;
    }
    return true;
}

void solveNQueens(int n, int col, vector<int> &board, vector<vector<string>> &solutions)
{
    if (col == n)
    {
        vector<string> grid(n, string(n, '.'));
        for (int c = 0; c < n; ++c)
            grid[board[c]][c] = 'Q';
        solutions.push_back(grid);
        return;
    }

    for (int row = 0; row < n; ++row)
    {
        if (isSafe(board, row, col))
        {
            board[col] = row;
            solveNQueens(n, col + 1, board, solutions);
            board[col] = -1; // backtrack
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int test = 1; test <= t; ++test)
    {
        int n;
        cin >> n;

        vector<vector<string>> solutions;
        vector<int> board(n, -1);

        solveNQueens(n, 0, board, solutions);

        cout << "Testcase " << test << " \n";
        for (int k = 0; k < (int)solutions.size(); ++k)
        {
            cout << "Arrangement " << k + 1 << ":\n";
            for (auto &row : solutions[k])
                cout << row << "\n";
            // cout << "\n";
        }
    }
    return 0;
}
