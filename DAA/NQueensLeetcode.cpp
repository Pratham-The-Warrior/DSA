/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isSafe(int n, vector<string> &nQueens, int row, int col)
    {
        // Check same column
        for (int i = 0; i < row; i++)
        {
            if (nQueens[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (nQueens[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (nQueens[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int n, vector<vector<string>> &ans, vector<string> &nQueens, int row)
    {
        // Base case: all rows filled
        if (row == n)
        {
            ans.push_back(nQueens);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(n, nQueens, row, col))
            {
                nQueens[row][col] = 'Q';
                solve(n, ans, nQueens, row + 1);
                nQueens[row][col] = '.'; // backtrack
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> nQueens(n, string(n, '.'));
        solve(n, ans, nQueens, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<vector<string>> ans = s.solveNQueens(n);

    // Print all solutions
    for (auto &board : ans)
    {
        for (auto &row : board)
            cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
