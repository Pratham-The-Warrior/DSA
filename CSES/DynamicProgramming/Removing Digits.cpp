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

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    int n;
    cin >> n;

    //*dp[x] = minimum steps to reduce x → 0

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            int dig = temp % 10;
            temp /= 10;
            dp[i] = min(dp[i], 1 + dp[i - dig]);
        }
    }

    cout << dp[n];

    return 0;
}