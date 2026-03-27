/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    BRUTE FORCE would not be feasible
    I think DP MAY be used


    */

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<ll> dp(n + 1, 0);
        dp[n] = 0;
        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            int p = 1 + dp[i + 1];
            int q = INT_MAX;

            if (i + a[i] < n)
            {
                q = dp[i + a[i] + 1];
            }
            dp[i] = min(p, q);
        }

        cout << dp[0] << endl;
    }

    return 0;
}