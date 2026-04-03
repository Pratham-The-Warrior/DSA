/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int knapsack(int W, int wt[], int val[], int n)
{
    // Base case
    if (n == 0 || W == 0)
        return 0;

    // If weight of nth item is more than capacity
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Return max of including or excluding the item
    else
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
            knapsack(W, wt, val, n - 1));
}

// DP Memoization(top-down DP)

int knapsackDP(int W, int wt[], int val[], int n)
{
}

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    /*
    Variations :-
    1. Subset Sum
    2. Equal Sum Partition
    3. Count of Subset Sum
    4. Target Sum

    */

    // Recursive//

    return 0;
}