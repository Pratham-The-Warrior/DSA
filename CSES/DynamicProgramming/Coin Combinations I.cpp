/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    ll n, x;
    cin >> n >> x;
    vector<int> dice(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dice[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (ll j = 1; j <= x; j++)
    {
        for (ll i = 0; i < n; i++)
        {
            if (j - dice[i] >= 0)
            {
                dp[j] = (dp[j] + dp[j - dice[i]]) % mod;
            }
        }
    }

    cout << dp[x] << endl;
}
