/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

/*
    TRIANGLE MINIMUM PATH SUM
    --------------------------
    Given a triangle array, find the minimum path sum
    from top to bottom. At each step, move to adjacent
    numbers on the next row.
*/

// ---------------------------------------------------------
//  Naive 2D DP (top-down, with bug if not handled)
// ---------------------------------------------------------
int minPathSumNaive(vector<vector<int>> triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(triangle.begin(), triangle.end());

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= i; k++)
        {
            if (k == 0)
                dp[i][k] += dp[i - 1][k];
            else if (k == i)
                dp[i][k] += dp[i - 1][k - 1];
            else
                dp[i][k] += min(dp[i - 1][k - 1], dp[i - 1][k]);
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

// ---------------------------------------------------------
//
