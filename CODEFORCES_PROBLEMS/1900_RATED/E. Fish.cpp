/* ************************************************
 * *
 * P     R     A     T     H     A     M    *
 * *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/**
 * Problem: Fish Survival Probability
 * Logic: Bitmask DP
 * dp[mask] = Probability that the fish represented by the set bits in 'mask' are alive.
 * Complexity: O(2^n * n^2)
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<double> dp(1 << n, 0.0);
    dp[(1 << n) - 1] = 1.0; // all fish alive
    for (int mask = (1 << n) - 1; mask >= 0; mask--)
    {
        int alive = __builtin_popcount(mask);
        if (alive <= 1)
            continue;
        double possible = alive * (alive - 1) / 2.0; // ways to choose 2 fish from alive fish
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j && (mask & (1 << j)))
                    { // jth fish fucked
                        double probabality = a[i][j] / possible;

                        dp[mask ^ (1 << j)] += dp[mask] * probabality; // Law of Total Probability
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(6) << dp[1 << i] << " ";
    }

    return 0;
}