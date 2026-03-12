#include <bits/stdc++.h>

using namespace std;

int countFactors(int n, int p)
{
    if (n <= 0)
        return 0;
    int ct = 0;

    while (n % p == 0)
    {
        ct++;
        n /= p;
    }
    return ct;
}

vector<vector<int>> solveDP(int n, vector<vector<int>> &grid, int p)
{
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int cost = (grid[i][j] == 0 ? 1 : countFactors(grid[i][j], p));

            if (i == 0 && j == 0)
            {
                dp[i][j] = cost;
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + cost;
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + cost;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + cost;
            }
        }
    }
    return dp;
}

string reconstructPath(int n, vector<vector<int>> &dp)
{
    string path = "";
    int x = n - 1, y = n - 1;

    while (x > 0 || y > 0)
    {

        if (x == 0)
        {
            path += 'R';
            y--;
        }
        else if (y == 0)
        {
            path += 'D';
            x--;
        }
        else
        {
            if (dp[x - 1][y] < dp[x][y - 1])
            {
                path += 'D';
                x--;
            }
            else
            {
                path += 'R';
                y--;
            }
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    int zeroR = -1, zeroC = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 0)
            {
                zeroR = i;
                zeroC = j;
            }
        }
    }
    vector<vector<int>> dp2 = solveDP(n, grid, 2);
    vector<vector<int>> dp5 = solveDP(n, grid, 5);

    int val2 = dp2[n - 1][n - 1];
    int val5 = dp5[n - 1][n - 1];

    int bestVal = min(val2, val5);
    string bestPath = (val2 < val5) ? reconstructPath(n, dp2) : reconstructPath(n, dp5);

    if (zeroR != -1 && bestVal > 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < zeroR; i++)
            cout << 'D';
        for (int j = 0; j < zeroC; j++)
            cout << 'R';
        for (int i = zeroR; i < n - 1; i++)
            cout << 'D';
        for (int j = zeroC; j < n - 1; j++)
            cout << 'R';
        cout << endl;
    }
    else
    {
        cout << bestVal << endl;
        cout << bestPath << endl;
    }

    return 0;
}