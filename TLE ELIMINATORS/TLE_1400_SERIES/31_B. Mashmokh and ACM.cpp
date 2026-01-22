/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // as we can see testcases are just 2000 so o(n2)  can also work
    // and seeing the testcase value we get a intuition of using dp to solve it

    vector<vector<int>> factors(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                factors[i].push_back(j);
                if (i / j != j)
                {
                    factors[i].push_back(i / j);
                }
            }
        }
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1; // base case intilization
    }

    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 0;
            for (auto x : factors[j])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][x]) % mod;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[k][i]) % mod;
    }

    cout << ans % mod << endl;

    return 0;
}