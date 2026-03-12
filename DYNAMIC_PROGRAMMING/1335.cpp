/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int minDifficulty(vector<int> &jobDifficulty, int d)
{
    int n = jobDifficulty.size();
    if (n < d)
    {
        return -1;
    }

    vector<vector<int>> dp(d + 1, vector<int>(n + 1, 1e9));

    int maxi = 0;

    // base day 1
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, jobDifficulty[i - 1]);
        dp[1][i] = maxi;
    }

    for (int i = 2; i <= d; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int mx = 0;

            for (int k = j - 1; k >= i - 1; k--)
            {
                mx = max(mx, jobDifficulty[k]);
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + mx);
            }
        }
    }

    return dp[d][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
    }

    return 0;
}