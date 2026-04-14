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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
     *As we have to minimize the skip operations
     *this is a minimization problem
     *So we will have to use DP here
     *dp[i][j] => which boss we are currently on and which friend is it
     *0=>friend , 1=>you
     *dp[0][0]=0;
     *
     */
    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX));

        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp[i][0] != INT_MAX)
            {
                if (i + 1 <= n)
                {
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i]);
                }
                if (i + 2 <= n)
                {
                    dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + a[i] + a[i + 1]);
                }
            }
            if (dp[i][1] != INT_MAX)
            {
                if (i + 1 <= n)
                {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
                }

                if (i + 2 <= n)
                {
                    dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
                }
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }

    return 0;
}