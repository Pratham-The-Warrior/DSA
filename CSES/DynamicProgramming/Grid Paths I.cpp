/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*=================================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
      ================================================= */

    // 2D dp

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[0][0] == '.')
        dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j > 0)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}

/***********************Variations*************************/

/*
*2️ Weighted Cells
*Rules: Each cell has a weight, and the goal is to find the maximum/minimum sum path instead of counting paths.
*dp[i][j]=max/min(dp[i−1][j],dp[i][j−1])+weight[i][j]



*/