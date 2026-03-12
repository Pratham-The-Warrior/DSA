/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= wt[i]; w--)
        {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int exactKnapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<int> dp(W + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int w = W; w >= wt[i]; w--)
        {
            if (dp[w - wt[i]] != INT_MIN) // only update if previous weight is reachable
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[W] == INT_MIN ? -1 : dp[W]; // -1 if exact weight not possible
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, W;
        cin >> n >> W;
        vector<int> wt(n), val(n);

        for (int i = 0; i < n; i++)
            cin >> wt[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        cout << "Maximum profit from knapsack = " << exactKnapsack(W, wt, val, n) << "\n";
    }

    return 0;
}
