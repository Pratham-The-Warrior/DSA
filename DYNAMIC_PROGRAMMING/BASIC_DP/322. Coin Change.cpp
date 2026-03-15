/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

// recusive approach-1
int coinChange1(vector<int> &coins, int amount)
{
    if (amount < 0)
        return -1;
    if (amount == 0)
        return 0;

    int min_ct = INT_MAX;

    for (auto c : coins)
    {
        int res = coinChange1(coins, amount - c);

        if (res >= 0 && res < min_ct)
        {
            min_ct = 1 + res;
        }
    }
    return (min_ct == INT_MAX) ? -1 : min_ct;
}

// dp approach
int coinChange2(vector<int> &coins, int amount)
{

    if (amount < 1)
    {
        return 0;
    }

    vector<int> dp(amount + 1);

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;

        for (int c : coins)
        {
            if (c <= i && dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

// dp approach more optimized

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